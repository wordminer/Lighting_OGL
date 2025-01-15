#version 330 core
out vec4 FragColor;
 
in vec3 ob_color;
in vec3 face_normal;
in vec3 light_vec;
in vec3 camera_vec;

struct Material{
    vec3 specular;
    vec3 defuse;
    vec3 ambient;
};

struct Light {
    vec3 specular;
    vec3 defuse;
    vec3 ambient;
};

uniform Material material;
uniform Light light;

uniform vec3 light_color;

void main()
{
    vec3 ambient = material.ambient * light.ambient;

    vec3 norm = normalize(face_normal);
    float defuse_streght =  max(dot(light_vec, norm), 0);
    vec3 difuse = defuse_streght * material.defuse * light.defuse;

    vec3 reflect_vec = normalize(reflect(-light_vec, norm));
    float specular = pow(max(dot(reflect_vec, normalize(camera_vec)), 0), 16);
    vec3 specular_vec = specular * material.specular * light.specular;

    vec3 ourColor = (ambient + difuse + specular_vec) ;

    FragColor = vec4(ourColor, 1.0);
}