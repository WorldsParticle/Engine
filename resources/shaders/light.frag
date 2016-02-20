#version 440

uniform mat4    model;
uniform mat4    view;

flat in vec3     fragNormal;
flat in vec3     fragVert;
flat in vec3     fragColor;

out vec4    finalColor;

float   phong_shading(vec3 lightPosition)
{
    //calculate normal in world coordinates
    mat3    normalMatrix = transpose(inverse(mat3(model)));
    vec3    normal = normalize(normalMatrix * fragNormal);

    //calculate the location of this fragment (pixel) in world coordinates
    vec3    fragPosition = vec3(model * vec4(fragVert, 1));

    //calculate the vector from this pixels surface to the light source
    vec3    surfaceToLight = lightPosition - fragPosition;

    //calculate the cosine of the angle of incidence
    float   AoI = dot(normal, surfaceToLight);
    float   brightness = AoI / (length(surfaceToLight) * length(normal));
    return clamp(brightness, 0, 1);
}

float   flat_shading(vec3 lightPosition, vec3 lightDir)
{
    //calculate normal in world coordinates
    mat3    normalMatrix = transpose(inverse(mat3(model)));
    vec3    normal = normalize(normalMatrix * fragNormal);

    //calculate the location of this fragment (pixel) in world coordinates
    //vec3    fragPosition = vec3(model * vec4(fragVert, 1));

    //calculate the vector from this pixels surface to the light source
    //vec3    surfaceToLight = lightPosition - fragPosition;

    //calculate the cosine of the angle of incidence
    //float   AoI = dot(normal, lightDir);
    float   brightness = dot(normal, lightDir) / (length(lightDir) * length(lightDir));
    return clamp(brightness, 0, 1);
}


void main() {

    // set the light position to the camera position...

    mat4    viewMatrix = inverse(view);
    vec3    lightPosition = vec3(viewMatrix[3][0], viewMatrix[3][1], viewMatrix[3][2]);
    vec3    lightDir = vec3(viewMatrix[0][2], viewMatrix[1][2], viewMatrix[2][2]);
    vec3    lightColor = vec3(1.0, 1.0, 1.0);

    float   brightness = flat_shading(lightPosition, lightDir);
    brightness = 1.0;
    finalColor = vec4(brightness * lightColor * fragColor, 1.0);
}

