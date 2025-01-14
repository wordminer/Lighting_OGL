#ifndef HANDLE_DATA
#define HANDLE_DATA

#include "GL/glew.h"
#include <iostream>

class Graphic_data {
public:
	unsigned int VBO, VAO, EBO, Texture;

	Graphic_data();
	~Graphic_data();

	void Bind_vertex_array();

	void Buffer_array_data(const void* array_buffer, GLsizeiptr size_array, GLenum Type_usage);

	void Element_buffer_data(int* element_array_buffer, GLsizeiptr size_array, GLenum Type_usage);

	void AttribPointer(GLuint index_ptr, GLint size, GLenum type_ptr, GLboolean Is_normalized, GLsizei stride_distance, const void* start_point);
};
#endif