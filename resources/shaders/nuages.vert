#version 420

layout(location = 0) in vec3 positions;
layout(location = 1) in vec3 normals;

uniform mat4    model;
uniform mat4    view;
uniform mat4    projection;

out vec3 pos;

void main() {
    pos = positions;
    gl_Position = projection * view * model * vec4(positions, 1.0);
}
