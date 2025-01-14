#ifndef CONST
#define CONST

#include "glm.hpp"

extern float WIDTH_WIN = 800;
extern float HIGHT_WIN = 500;

extern const char* vshader_path = "resources/shader_source/vshader.vert";
extern const char* fshader_path = "resources/shader_source/fshader.frag";

extern const char* tnt_img_path = "resources/image/minecraftTnt.jpg";

extern const int face_create_key[] = {
    6, 7, 5,    6, 5, 4,
    2, 3, 1,    2, 1, 0,
    7, 3, 1,    7, 1, 5,
    2, 6, 4,    2, 4, 0,
    2, 3, 7,    2, 7, 6,
    0, 1, 5,    0, 5, 4
};
glm::fvec3 normal_face_vector[6] = {
    glm::fvec3( 0,  0,  1),
    glm::fvec3( 0,  0, -1),
    glm::fvec3( 1,  0,  0),
    glm::fvec3(-1,  0,  0),
    glm::fvec3( 0,  1,  0),
    glm::fvec3( 0, -1,  0)
};

#endif