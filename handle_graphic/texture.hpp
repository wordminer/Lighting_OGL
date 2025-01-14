#ifndef TEXTURE
#define TEXTURE 

#include "stb_image.h"
#include <iostream>
#include "vertex.hpp"
#include "shader.hpp"

void load_image(unsigned int &texture,const char *image_path);

class Block_texture{
    public:
        //define x axis is nourth and south, z for west and east.
        unsigned int face_texture[6];
        Block_texture(const char* block_images_path[]);
        void Bind_texture();
        void Set_shader_texture(ShaderProgram Shader);
};

#endif 
