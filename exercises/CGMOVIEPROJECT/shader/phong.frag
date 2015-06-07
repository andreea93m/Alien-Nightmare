// Phong Fragment Shader
#version 150 compatibility

smooth in vec3 p_normalVec;
smooth in vec3 p_eyeVec;

smooth in vec3 p_lightVec;
smooth in vec3 p_lightVec2;

flat in int p_lightIndex;
flat in int p_lightIndex2;

smooth in float p_dist;
smooth in float p_dist2;

uniform vec4 mycolor;
uniform bool useTexturing;
uniform sampler2D mytexture;
in vec2 mytextureCoordinates;

vec4 calculateSimplePointLight(in vec3 lightVec, in vec3 normalVec, in vec3 eyeVec,
								in int lightSourceIndex, in float dist) {

	lightVec = normalize(lightVec);
	normalVec = normalize(normalVec);
	eyeVec = normalize(eyeVec);

	vec3 spotVec = normalize(gl_LightSource[lightSourceIndex].spotDirection);
	float angle = dot(-lightVec, spotVec);

	if(angle > gl_LightSource[lightSourceIndex].spotCosCutoff) {
		float diffuse = max(dot(normalVec,lightVec),0.0);
		vec3 reflectVec = reflect(-lightVec,normalVec);
		float spec = pow( max(dot(reflectVec, eyeVec),0.0) ,gl_FrontMaterial.shininess);

		vec4 c_amb = clamp(gl_LightSource[lightSourceIndex].ambient * gl_FrontMaterial.ambient, 0.0, 1.0);
		vec4 c_diff = clamp(diffuse * gl_LightSource[lightSourceIndex].diffuse * gl_FrontMaterial.diffuse, 0.0, 1.0);
		vec4 c_spec = clamp(spec * gl_LightSource[lightSourceIndex].specular * gl_FrontMaterial.specular, 0.0, 1.0);

		float att = 1.0 / (gl_LightSource[lightSourceIndex].constantAttenuation +
	                    gl_LightSource[lightSourceIndex].linearAttenuation * dist +
	                    gl_LightSource[lightSourceIndex].quadraticAttenuation * dist * dist);

		vec4 finalColor = att * (c_amb + c_diff + c_spec);

		return useTexturing ? finalColor * texture(mytexture, mytextureCoordinates) : finalColor;
	}

	return gl_LightSource[lightSourceIndex].ambient;
}

void main() {
	gl_FragColor = calculateSimplePointLight(p_lightVec, p_normalVec, p_eyeVec, p_lightIndex, p_dist) +
					calculateSimplePointLight(p_lightVec2, p_normalVec, p_eyeVec, p_lightIndex2, p_dist2);
}
