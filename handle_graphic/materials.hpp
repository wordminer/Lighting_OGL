#ifndef MATERIALS_HPP
#define MATERIALS_HPP

#include "shader.hpp"
#include "glm.hpp"

struct Material {
    glm::vec3 specular;
    glm::vec3 defuse;
    glm::vec3 ambient;
    float shininess;
};

void set_material_uniform(ShaderProgram shader, Material info_material);
void set_light_uniform(ShaderProgram shader, Material light_info);

#endif 