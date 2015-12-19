#version 420

out vec4 color;

in vec3     fPosition;
in vec3     fNormal;
in vec3     cameraPosition;

vec4 lighting(vec4 diffuse) {
    vec4 spec = vec4(0.0);
    vec3 lDir = normalize(vec3(2.0,2.0,1) - fPosition);

    vec4 ambient = vec4(0.,0.,0.,1);
    vec4 specular = vec4(0.1,0.1,0.1,1);
    float shininess = 0.7;

    float intensity = max(dot(fNormal, lDir), 0.0);

    if (intensity > 0.0) {
        vec3 h = normalize(lDir + cameraPosition);
        float intSpec = max(dot(h,fNormal),0.0);
        spec = specular * pow(intSpec, shininess);
    }
    return max(intensity * diffuse + spec, ambient);
}

void main(void) {
  color = lighting(vec4(1.0));
  color = vec4(1.0, 1.0, 1.0, 1.0);
}
