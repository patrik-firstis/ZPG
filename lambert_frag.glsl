#version 330 core
in vec3 fragNormal;
in vec3 fragPosition;

out vec4 fragColor;

void main() {
    vec3 lightPosition = vec3(0.0, 0.0, 0.0);
    vec3 lightVector = normalize(lightPosition - fragPosition);
    float diffuse = max(dot(fragNormal, lightVector), 0.0); // intensity of light <1.0,0.0>
    vec4 diffuseColor = diffuse * vec4(0.385, 0.647, 0.812, 1.0); // intensity * color
    fragColor = vec4(0.1, 0.1, 0.1, 1.0) + diffuseColor; // ambient light + diffuse color
}