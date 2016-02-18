#version 420

in vec3 fNormal;
in vec3 fVertex;
in vec2 fUVCoord;
in vec3 eye;

out vec4 outColor;

uniform sampler2D tex;

vec4 lighting(vec4 diffuse) {
    vec4 spec = vec4(0.0);
    vec3 lDir = normalize(vec3(2.0,2.0,1) - fVertex);

    vec4 ambient = vec4(0.,0.,0.,1);
    vec4 specular = vec4(0.1,0.1,0.1,1);
    float shininess = 0.7;

    float intensity = max(dot(fNormal, lDir), 0.0);

    if (intensity > 0.0) {
	vec3 h = normalize(lDir + eye);
	float intSpec = max(dot(h,fNormal),0.0);
	spec = specular * pow(intSpec, shininess);
    }
    return max(intensity * diffuse + spec, ambient);
}

void main() {
    vec4 diffuse = vec4(1);

    diffuse = texture(tex, fUVCoord);
    //outColor = lighting(diffuse);
    outColor = diffuse;
}
