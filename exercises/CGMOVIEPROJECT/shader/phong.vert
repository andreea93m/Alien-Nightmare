// Phong Vertex Shader
#version 150 compatibility

uniform bool useTexturing;
uniform int lightIndex;
uniform int lightIndex2;

//output of this shader
smooth out vec3 p_normalVec;
smooth out vec3 p_eyeVec;

smooth out vec3 p_lightVec;
smooth out vec3 p_lightVec2;

flat out int p_lightIndex;
flat out int p_lightIndex2;

smooth out float p_dist;
smooth out float p_dist2;

out vec2 mytextureCoordinates; // From simpleshader

void main() {
	vec3 ecPosition = (gl_ModelViewMatrix * gl_Vertex).xyz;
    
    p_normalVec = (gl_NormalMatrix * gl_Normal).xyz;
    p_eyeVec = -ecPosition;

	p_lightVec = (gl_LightSource[lightIndex].position.xyz - ecPosition); //light position was already transformed to eye space by OpenGL
	p_lightVec2 = (gl_LightSource[lightIndex2].position.xyz - ecPosition); //light position was already transformed to eye space by OpenGL

	p_lightIndex = lightIndex;
	p_lightIndex2 = lightIndex2;

	p_dist = length(p_lightVec);
	p_dist2 = length(p_lightVec2);

	// From simpleshader
	if(useTexturing == true) {
		mytextureCoordinates = gl_MultiTexCoord0.st;
    }

    //compute the vertex position based on projection and modelview matrix
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; //gl_ModelViewProjectionMatrix = gl_ProjectionMatrix * gl_ModelViewMatrix
}
