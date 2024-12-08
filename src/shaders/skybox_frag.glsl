#version 330

in vec3 fragPosition;

uniform samplerCube textureUnitID;

out vec4 fragColor;

void main () {
    fragColor = texture(textureUnitID, fragPosition);// * vec4(0.4, 0.4, 0.4, 1.0);
}