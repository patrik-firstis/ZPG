# version 330

layout(location = 0) in vec3 vp;

out vec3 fragPosition;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
  mat4 skyboxViewMatrix = mat4(mat3(viewMatrix)); 
  fragPosition = vp;
	gl_Position = projectionMatrix * skyboxViewMatrix * vec4(vp, 1.0);
}