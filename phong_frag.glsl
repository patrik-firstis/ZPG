#version 450
#define MAX_LIGHTS 10

in vec3 fragNormal;
in vec3 fragPosition;

uniform vec3 viewPosition;
uniform vec3 viewDirection;
uniform vec3 objectColor;

struct Light {
  int type; // 0 = directional, 1 = point, 2 = spot
	vec3 position;     
  vec3 direction;
  vec3 color;      
	vec3 ambient;
	float intensity;
  float constantAttenuation; 
  float linearAttenuation;   
  float quadraticAttenuation; 
  float innerConeAngle;   
  float outerConeAngle;  
};

uniform Light lights[MAX_LIGHTS];

out vec4 fragColor;

vec3 diffuseColor(Light light);
vec3 specularColor(Light light);
float attenuation(Light light);

void main() {
	vec3 ambient = vec3(0.0, 0.0, 0.0);
  vec3 diffuse = vec3(0.0, 0.0, 0.0);
  vec3 specular = vec3(0.0, 0.0, 0.0);

  for (int i = 0; i < MAX_LIGHTS; i++) {
		Light light = lights[i];
		ambient += light.ambient;
		diffuse += diffuseColor(light) * attenuation(light) * light.intensity;
		specular += specularColor(light) * attenuation(light) * light.intensity;
	}
  
  fragColor = vec4((ambient * objectColor) + (diffuse * objectColor) + specular, 0.0);
}

vec3 diffuseColor(Light light) {
	vec3 lightVector = vec3(0.0, 0.0, 0.0);
	if (light.type == 0) {
		lightVector = normalize(-light.direction);
	} 
	else if (light.type == 1) {
		lightVector = normalize(light.position - fragPosition);
	}
	else if (light.type == 2) {
		lightVector = normalize(viewPosition - fragPosition);
	}

	float diffuse = max(dot(normalize(fragNormal), lightVector), 0.0);
  return diffuse * light.color;
}

vec3 specularColor(Light light) {
	vec3 lightVector = vec3(0.0, 0.0, 0.0);
	if (light.type == 0) {
		lightVector = normalize(-light.direction);
	} 
	else if (light.type == 1) {
		lightVector = normalize(light.position - fragPosition);
	}
	else if (light.type == 2) {
		return vec3(0.0, 0.0, 0.0);
	}

	vec3 viewVector = normalize(viewPosition - fragPosition);
	vec3 reflectVector = reflect(-lightVector, normalize(fragNormal));
	float specular = pow(max(dot(viewVector, reflectVector), 0.0), 32.0);
	return specular * light.color;
}

float attenuation(Light light) {
	if (light.type == 0) {
		return 1.0;
	} else if (light.type == 1) {
		vec3 lightVector = normalize(light.position - fragPosition);
		float distance = length(light.position - fragPosition);
		return 1.0 / (light.constantAttenuation + light.linearAttenuation * distance + light.quadraticAttenuation * distance * distance);
	} else if (light.type == 2){
		vec3 spotVector = normalize(-viewDirection);
		vec3 lightVector = normalize(viewPosition - fragPosition);
		float theta = dot(lightVector, spotVector);
		float intensity = 0.0;

		if (theta > cos(light.innerConeAngle)) {
			intensity = 1.0;
		} else if (theta > cos(light.outerConeAngle)) {
			intensity = (theta - cos(light.outerConeAngle)) / (cos(light.innerConeAngle) - cos(light.outerConeAngle));
		}

		float distance = length(viewPosition - fragPosition);
		float attenuation = 1.0 / (light.constantAttenuation + light.linearAttenuation * distance + light.quadraticAttenuation * distance * distance);
		
		return attenuation * intensity;
	}
	return 1.0;
}
