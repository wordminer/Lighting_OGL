#include "materials.hpp"



void set_material_uniform(ShaderProgram shader, Material info_material){
    shader.uniformVec3("material.specular", info_material.specular);
    shader.uniformVec3("material.defuse", info_material.defuse);
    shader.uniformVec3("material.ambient", info_material.ambient);
    shader.uniformFloat("material.shininess", info_material.shininess);
}

void set_light_uniform(ShaderProgram shader, Material light_info){
    shader.uniformVec3("light.specular", light_info.specular);
    shader.uniformVec3("light.defuse", light_info.defuse);
    shader.uniformVec3("light.ambient", light_info.ambient);
}