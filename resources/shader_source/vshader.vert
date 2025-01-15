#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec3 aNormal;

out vec3 ob_color;
out vec3 face_normal;
out vec3 light_vec;
out vec3 camera_vec;

uniform vec3 light_pos;
uniform vec3 camera_pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    camera_vec = (camera_pos - aPos);
    light_vec = normalize(light_pos - aPos);
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
    ob_color = aColor;
    face_normal = mat3(transpose(inverse(model))) * aNormal;
}