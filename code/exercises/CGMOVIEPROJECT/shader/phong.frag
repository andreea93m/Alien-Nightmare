// Phong Fragment Shader
#version 150 compatibility

smooth in vec3 p_normalVec;
smooth in vec3 p_eyeVec;

smooth in vec3 p_lightVec[8];
flat in int p_lightIndex[8];
smooth in float p_dist[8];

uniform vec4 mycolor;
uniform bool useTexturing;
uniform sampler2D mytexture;
in vec2 mytextureCoordinates;

vec4 calculateSimplePointLight(in vec3 lightVec, in vec3 normalVec, in vec3 eyeVec,
								in int lightSourceIndex, in float dist) {

	lightVec = normalize(lightVec);
	normalVec = normalize(normalVec);
	eyeVec = normalize(eyeVec);

	gl_LightSourceParameters lightParameters = gl_LightSource[lightSourceIndex];

	vec3 spotVec = normalize(lightParameters.spotDirection);
	vec3 reflectVec = reflect(-lightVec,normalVec);
	float diffuse = max(dot(normalVec,lightVec),0.0);
    float spec = pow(max(dot(reflectVec, eyeVec),0.0) ,gl_FrontMaterial.shininess);

	float att = 1.0 / (lightParameters.constantAttenuation +
    	                    lightParameters.linearAttenuation * dist +
    	                    lightParameters.quadraticAttenuation * dist * dist);

	vec4 finalColor = useTexturing ? texture(mytexture, mytextureCoordinates) : vec4(1.0);

    vec4 c_amb = clamp(lightParameters.ambient * gl_FrontMaterial.ambient, 0.0, 1.0);
    vec4 c_diff = clamp(diffuse * lightParameters.diffuse * gl_FrontMaterial.diffuse, 0.0, 1.0);
    vec4 c_spec = clamp(spec * lightParameters.specular * gl_FrontMaterial.specular, 0.0, 1.0);

    if(lightParameters.spotCutoff <= 90.0) {
        // This is a spot light
        float angle = dot(-lightVec, spotVec);

        if(angle < cos(radians(lightParameters.spotCutoff))) {
            // Outside the cone
            c_diff = c_spec = vec4(0.0);
        }

        // Apply the spot exponent to the attenuation
        att *= pow(angle, lightParameters.spotExponent);
    }

    finalColor *= att * (c_amb + c_diff + c_spec);

	return finalColor;
}

void main() {
	gl_FragColor = vec4(0.0);
		
	for(int i = 0; i < 8; ++i) {
		if(p_lightIndex[i] != -1) {
			gl_FragColor += calculateSimplePointLight(p_lightVec[i], p_normalVec, p_eyeVec, p_lightIndex[i], p_dist[i]);
		}
	}
}
