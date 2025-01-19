#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in vec2 aTexCoord;
layout (location = 4) in vec2 aFace;

out vec3 ob_color;
out vec3 face_normal;
out vec3 light_vec;
out vec3 camera_vec;

out vec2 TexCoord;
out vec2 Face;
    
uniform vec3 light_pos;
uniform vec3 camera_pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vec3 Pos_convert = vec3(model * vec4(aPos, 1.0));
    camera_vec = (camera_pos - Pos_convert);
    light_vec = (light_pos - Pos_convert);
    ob_color = aColor;
    
    face_normal = mat3(transpose(inverse(model))) * aNormal;
    TexCoord = aTexCoord;
    Face = aFace;

    gl_Position = projection * view * model * vec4(aPos, 1.0f);
}