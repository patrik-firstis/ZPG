#version 330

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    vec3 color;
};

uniform Material material;

out vec4 fragmentColor;

void main () {
     fragmentColor = vec4 (material.color, 1.0);
};