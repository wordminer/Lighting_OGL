#version 330 core
out vec4 FragColor;
 
in vec3 ob_color;
in vec3 face_normal;
in vec3 light_vec;
in vec3 camera_vec;

in vec2 Face;
in vec2 TexCoord;

struct Material{
    vec3 specular;
    vec3 defuse;
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

uniform sampler2D texture_1;
uniform sampler2D texture_2; 
uniform sampler2D texture_3;
uniform sampler2D texture_4;
uniform sampler2D texture_5;
uniform sampler2D texture_6;

void main()
{
    vec3 ambient = material.ambient * light.ambient;

    vec3 norm = normalize(face_normal);
    float defuse_streght =  max(dot(light_vec, norm), 0);
    vec3 difuse = defuse_streght * material.defuse * light.defuse;

    vec3 reflect_vec = normalize(reflect(-light_vec, norm));
    float reflect_check = dot(reflect_vec, norm);
    float negative_check = max(reflect_check, 0) / reflect_check;
    float specular = pow(max(dot(reflect_vec, normalize(camera_vec)) * negative_check, 0), material.shininess);
    vec3 specular_vec = specular * material.specular * light.specular;

    vec3 ourColor = (ambient + difuse + specular_vec) ;

    if (Face.x == 0){ FragColor = texture(texture_1, TexCoord); }
    else if (Face.x == 1){ FragColor = texture(texture_2, TexCoord); }
    else if (Face.x == 2){ FragColor = texture(texture_3, TexCoord); }
    else if (Face.x == 3){ FragColor = texture(texture_4, TexCoord); }
    else if (Face.x == 4){ FragColor = texture(texture_5, TexCoord); }
    else if (Face.x == 5){ FragColor = texture(texture_6, TexCoord); }

    FragColor *= vec4(ourColor, 1.0);
}