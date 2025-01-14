#include "vertex.hpp"

size_t getOffsetOfPos() {
    return offsetof(Vertex, m_pos);
}

size_t getOffsetOfColor() {
    return offsetof(Vertex, obcolor);
}

size_t getOffsetOfNormal() {
    return offsetof(Vertex, normal_face_vec);
}