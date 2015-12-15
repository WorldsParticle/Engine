#version 420

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

uniform mat4    model;
uniform mat4    view;
uniform mat4    projection;

out vec3    fNormal;
out vec3    cameraPosition;

void main() {
    fNormal = normal;
    cameraPosition.x = -view[0][3];
    cameraPosition.y = -view[1][3];
    cameraPosition.z = -view[2][3];
    gl_Position = projection * view * model * vec4(position, 1.0);
}
