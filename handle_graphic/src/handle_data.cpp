#include "handle_data.hpp"

Graphic_data::Graphic_data()
{
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

Graphic_data::~Graphic_data()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Graphic_data::Bind_vertex_array() 
{
	glBindVertexArray(VAO);
}

void Graphic_data::Buffer_array_data(const void* array_buffer, GLsizeiptr size_array, GLenum Type_usage)
{
	glBufferData(GL_ARRAY_BUFFER, size_array, array_buffer, Type_usage);
}

void Graphic_data::Element_buffer_data(int* element_array_buffer, GLsizeiptr size_array, GLenum Type_usage)
{
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_array, element_array_buffer, Type_usage);
}

void Graphic_data::AttribPointer(GLuint index_ptr, GLint size, GLenum type_ptr, GLboolean Is_normalized, GLsizei stride_distance, const void* start_point)
{
	glVertexAttribPointer(index_ptr, size, type_ptr, Is_normalized, stride_distance, start_point);
	glEnableVertexAttribArray(index_ptr);
}