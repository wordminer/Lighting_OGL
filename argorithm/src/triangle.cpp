#include "triangle.hpp"


void moving_triangle(float* triangle_coord, float* Move_pos, int size_list, int stride, int start_point)
{
	for (int pos = 0; pos < size_list; pos++) {
		int key = pos * stride + start_point;
		for (int i = 0; i < 2; i++) {
			triangle_coord[key + i] += Move_pos[i];
		}
	}
}
