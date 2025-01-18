#version 330 core
out vec4 FragColor;
 
in vec3 ob_color;
in vec3 face_normal;
in vec3 light_vec;
in vec3 camera_vec;

in vec2 Face;
in vec2 TexCoord;

struct Material{
    sampler2D specular;
    sampler2D defuse;
    vec3 ambient;
    float shininess;
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
    vec3 ambient = texture(material.defuse, TexCoord).rgb * light.ambient;

    vec3 norm = normalize(face_normal);
    float defuse_streght =  max(dot(light_vec, norm), 0);
    vec3 difuse = defuse_streght * texture(material.defuse, TexCoord).rgb * light.defuse;

    vec3 reflect_vec = normalize(reflect(-light_vec, norm));
    float reflect_check = dot(reflect_vec, norm);
    float negative_check = max(reflect_check, 0) / reflect_check;
    float specular = pow(max(dot(reflect_vec, normalize(camera_vec)) * negative_check, 0), material.shininess);
    vec3 specular_vec = specular * texture(material.specular, TexCoord).rgb * light.specular;

    vec3 ourColor = (ambient + difuse + specular_vec) ;

    FragColor = vec4(ourColor, 1.0);
}