#version 450
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

out vec3 fragNormal;
out vec3 fragPosition;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main() {
	
	mat3 norm = transpose(inverse(mat3(modelMatrix)));
	fragNormal = normalize(norm * normal);
	fragPosition = vec3(modelMatrix * vec4(position, 1.0));
  gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);
}	