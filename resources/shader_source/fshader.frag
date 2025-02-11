#version 330 core
out vec4 FragColor;
 
in vec3 ob_color;
in vec3 face_normal;
in vec3 light_vec;
in vec3 camera_vec;

uniform vec3 light_color;

void main()
{
    vec3 specular_strength = vec3(0.8, 0.8, 0.8);
    vec3 reflect_vec = normalize(reflect(-light_vec, face_normal));
    float specular = pow(max(dot(reflect_vec, normalize(camera_vec)), 0), 8);
    vec3 specular_vec = specular * specular_strength * light_color;

    vec3 difuse_streght = vec3(0.3, 0.3, 0.3);
    float light_streght =  max(dot(light_vec, face_normal), 0);
    vec3 difuse = light_streght * light_vec * difuse_streght;

    float ambient_strength = 0.1;
    vec3 ambient = ambient_strength * light_color;

    vec3 ourColor = (ambient + difuse + specular_vec);

    FragColor = vec4(ourColor, 1.0);
}