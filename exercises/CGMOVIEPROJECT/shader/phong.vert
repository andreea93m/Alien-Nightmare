// Phong Vertex Shader
#version 150 compatibility


//output of this shader
smooth out vec3 p_normalVec;
smooth out vec3 p_lightVec;
smooth out vec3 p_eyeVec;

smooth out vec3 p_lightVec2;

void main() {
	vec3 ecPosition = (gl_ModelViewMatrix * gl_Vertex).xyz;
    
    p_normalVec = (gl_NormalMatrix * gl_Normal).xyz;
    p_eyeVec = -ecPosition;
	p_lightVec = (gl_LightSource[0].position.xyz - ecPosition); //light position was already transformed to eye space by OpenGL

	p_lightVec2 = (gl_LightSource[1].position.xyz - ecPosition);
	
	//compute the vertex position based on projection and modelview matrix
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; //gl_ModelViewProjectionMatrix = gl_ProjectionMatrix * gl_ModelViewMatrix
}
