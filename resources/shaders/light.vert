#version 440

layout(location = 0) in vec3 positions;
layout(location = 1) in vec3 normals;
layout(location = 2) in vec3 color;

uniform mat4    model;
uniform mat4    view;
uniform mat4    projection;

flat out vec3    fragNormal;
flat out vec3    fragVert;
flat out vec3    fragColor;

void main()
{
    fragColor = color;
    fragVert = positions;
    fragNormal = normals;
    gl_Position = projection * view * model * vec4(positions, 1.0);
}
