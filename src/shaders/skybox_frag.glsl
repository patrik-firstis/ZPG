#version 330

in vec3 fragPosition;

uniform samplerCube textureUnitID;

out vec4 fragColor;

void main () {
    fragColor = texture(textureUnitID, fragPosition) * vec4(0.7, 0.7, 0.7, 1.0);
}