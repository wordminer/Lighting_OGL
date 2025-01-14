#version 330 core
out vec4 FragColor;
 
in vec3 ob_color;
in vec3 face_normal;
in vec3 light_vec;

uniform vec3 light_color;

void main()
{
    float light_streght =  max(face_normal.x * light_vec.x, 0);
    float ambient_strength = light_streght ;
    vec3 ambient = ambient_strength * light_color;
    vec3 ourColor = ambient * ob_color;

    FragColor = vec4(ourColor, 1.0);
}