#version 330

layout (location = 0) in vec2 aPos;
out vec2 FragPos;

void main() {
   FragPos = aPos.xy;
   gl_Position = vec4(aPos, 0.0, 1.0);
}
