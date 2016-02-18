#version 420

layout(location = 0) in vec3 vPos;
layout(location = 1) in vec3 vNormal;
layout(location = 2) in vec2 vUVCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 fNormal;
out vec3 fVertex;
out vec2 fUVCoord;
out vec3 eye;

void main() {
    vec4 p = vec4(vPos, 1.0);
    fNormal = vNormal;
    fVertex = (model * p).xyz;
    fUVCoord = vUVCoord;
    eye.x = -view[0][3];
    eye.y = -view[1][3];
    eye.z = -view[2][3];
    gl_Position = projection * view * model * vec4(vPos, 1.0);
}
