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

    float Contant;
    float linear;
    float quadratic;
};

struct Light {
    vec3 specular;
    vec3 defuse;
    vec3 ambient;

    float spotlight_angle;
    vec3 Look_vec;
};

uniform Material material;
uniform Light light;
uniform vec3 light_color;

void main()
{
    float spotlight_check = dot(normalize(-light_vec), normalize(light.Look_vec));
    if (light.spotlight_angle < spotlight_check) spotlight_check = 1;
    
    else spotlight_check = 0;

    float light_distance = length(light_vec);
    float attenuation = 1/(material.Contant + material.linear*light_distance + material.quadratic*(light_distance * light_distance));

    vec3 ambient = texture(material.defuse, TexCoord).rgb * light.ambient * attenuation;

    vec3 norm = normalize(face_normal);
    float defuse_streght =  max(dot(normalize(light_vec), norm), 0);
    vec3 difuse = defuse_streght * texture(material.defuse, TexCoord).rgb * light.defuse * attenuation;

    vec3 reflect_vec = normalize(reflect(-normalize(light_vec), norm));
    float reflect_check = dot(reflect_vec, norm);
    float negative_check = max(reflect_check, 0) / reflect_check;
    float specular = pow(max(dot(reflect_vec, normalize(camera_vec)) * negative_check, 0), material.shininess);
    vec3 specular_vec = specular * texture(material.specular, TexCoord).rgb * light.specular * attenuation;

    

    vec3 ourColor = (ambient + (difuse + specular_vec)*spotlight_check);

    FragColor = vec4(ourColor, 1.0);
}