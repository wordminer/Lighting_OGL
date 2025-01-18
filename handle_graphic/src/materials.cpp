#include "materials.hpp"

Material::Material(const char* specular_path,const char* defuse_path, glm::vec3 ob_ambient, float shiny){
    this->ambient = ob_ambient;
    this->shininess = shiny;
    load_image(this->defuse, defuse_path);
    load_image(this->specular, specular_path);
}

void set_material_uniform(ShaderProgram shader, Material info_material){
    shader.uniformVec3("material.ambient", info_material.ambient);
    shader.uniformFloat("material.shininess", info_material.shininess);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, info_material.defuse);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, info_material.specular);
}

void set_light_uniform(ShaderProgram shader, Light light_info){
    shader.uniformVec3("light.specular", light_info.specular);
    shader.uniformVec3("light.defuse", light_info.defuse);
    shader.uniformVec3("light.ambient", light_info.ambient);
}