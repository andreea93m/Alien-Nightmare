// Phong Vertex Shader
#version 150 compatibility

uniform bool useTexturing;

uniform int lightIndex[8];

//output of this shader
smooth out vec3 p_normalVec;
smooth out vec3 p_eyeVec;
smooth out vec3 p_lightVec[8];
flat out int p_lightIndex[8];
smooth out float p_dist[8];

out vec2 mytextureCoordinates; // From simpleshader

void main() {
	vec3 ecPosition = (gl_ModelViewMatrix * gl_Vertex).xyz;
    
    p_normalVec = (gl_NormalMatrix * gl_Normal).xyz;
    p_eyeVec = -ecPosition;
    
    for(int i = 0; i < 8; ++i) {
    	if(lightIndex[i] != -1) {
    			p_lightVec[i] = (gl_LightSource[lightIndex[i]].position.xyz - ecPosition); //light position was already transformed to eye space by OpenGL
    			p_lightIndex[i] = lightIndex[i];
    			p_dist[i] = length(p_lightVec[i]);
    	} else {
    		p_lightIndex[i] = -1;
    	}
    }

	// From simpleshader
	if(useTexturing == true) {
		mytextureCoordinates = gl_MultiTexCoord0.st;
    }

    //compute the vertex position based on projection and modelview matrix
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; //gl_ModelViewProjectionMatrix = gl_ProjectionMatrix * gl_ModelViewMatrix
}
