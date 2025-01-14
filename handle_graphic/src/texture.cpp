#include "texture.hpp"

void load_image(unsigned int &texture,const char *image_path){
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char* data = stbi_load(image_path, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        //std::cout << "success in load texture" << image_path << std::endl;
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

Block_texture::Block_texture(const char* block_images_path[]){
    for (int i = 0; i < 6; i++){
        load_image(face_texture[i], block_images_path[i]);
    }
}

void Block_texture::Bind_texture(){
    for (int i = 0; i < 6; i++){
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, face_texture[i]);
    }
}

void Block_texture::Set_shader_texture(ShaderProgram Shader){
    Shader.uniformInt("texture_1", 0);
    Shader.uniformInt("texture_2", 1);
    Shader.uniformInt("texture_3", 2);
    Shader.uniformInt("texture_4", 3);
    Shader.uniformInt("texture_5", 4);
    Shader.uniformInt("texture_6", 5);
}