// Phong Fragment Shader
#version 150 compatibility


smooth in vec3 p_normalVec;
smooth in vec3 p_lightVec;
smooth in vec3 p_eyeVec;

smooth in vec3 p_lightVec2;

vec4 calculateSimplePointLight(in vec3 lightVec, in vec3 normalVec, in vec3 eyeVec, in int lightSourceIndex) {

	lightVec = normalize(lightVec);
	normalVec = normalize(normalVec);
	eyeVec = normalize(eyeVec);

	float diffuse = max(dot(normalVec,lightVec),0.0);
	vec3 reflectVec = reflect(-lightVec,normalVec); 
	float spec = pow( max(dot(reflectVec, eyeVec),0.0) ,gl_FrontMaterial.shininess);
	
	vec4 c_amb = clamp(gl_LightSource[lightSourceIndex].ambient * gl_FrontMaterial.ambient, 0.0, 1.0);
	vec4 c_diff = clamp(diffuse * gl_LightSource[lightSourceIndex].diffuse * gl_FrontMaterial.diffuse, 0.0, 1.0);
	vec4 c_spec = clamp(spec * gl_LightSource[lightSourceIndex].specular * gl_FrontMaterial.specular, 0.0, 1.0);
	
	return c_amb + c_diff + c_spec;
}

void main() { 	
	gl_FragColor = calculateSimplePointLight(p_lightVec, p_normalVec, p_eyeVec, 0) + calculateSimplePointLight(p_lightVec2, p_normalVec, p_eyeVec, 1);
}
