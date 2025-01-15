#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <iostream>
#include <vector>
#include "glm.hpp"
#include "vertex.hpp"



class Block{
public:
    std::vector<glm::vec3> Block_coord;
    std::vector<Vertex> Block_vertices;
    glm::fvec3 Position;
    glm::fvec3 lengh_side; 

    Block(glm::fvec3 mPosition, float x_side, float y_side, float z_side);
    void Create_block(bool is_texture, const char* block_images_path[], const int face_key[], glm::vec3 Color,glm::fvec3 face_vector[]);
   
};

#endif 