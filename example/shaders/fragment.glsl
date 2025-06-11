#version 330 core

in vec2 FragPos;
out vec4 FragColor;

void main() {
   FragColor = vec4(FragPos.xy*5.0, 1.0, 1.0);
}
