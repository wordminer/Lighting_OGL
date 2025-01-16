#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <GL/glew.h>
#include <glm.hpp>

struct Vertex {
    glm::fvec3 m_pos;
    glm::fvec3 obcolor;
    // glm::vec2 Texcoord;
    glm::fvec3 normal_face_vec;
    glm::fvec2 Tex_coord;
    glm::fvec2 face_id;
    //int tex_id;

    Vertex() {}

    //for color only
    Vertex(glm::fvec3 Pos, glm::fvec3 color_face, GLint face, glm::fvec3 face_normal, glm::fvec2 Texcoord)
        : m_pos(Pos), obcolor(color_face), normal_face_vec(face_normal), Tex_coord(Texcoord), face_id(glm::fvec2(face, 0)) {}

    // Vertex(glm::vec3 Pos, glm::vec3 color_face, GLint face, glm::vec2 Tex_coord, int texid)
    //     : m_pos(Pos), obcolor(color_face), face_id(face), Texcoord(Tex_coord), tex_id(texid) {}

};

size_t getOffsetOfPos();
size_t getOffsetOfColor();
size_t getOffsetOfNormal();
size_t getOffsetOfTexCoord();
size_t getOffsetOfFaceID();

#endif