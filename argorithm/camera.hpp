#ifndef CAMERA_HPP
#define CAMERA_HPP 

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <iostream>
#include <GL/glew.h>
#include <SDL.h>

#include "shader.hpp"
#include "window_driver.hpp"

class Camera {
public:
	Camera(glm::vec3 pos, float FAV, float speed_move, float speed_rotate, float near_dis, float far_dis);
	
	void set_viewrange(ShaderProgram Shader, float Width_camera, float Hight_camera);
	void set_position(ShaderProgram Shader, glm::vec3 Position, float* Angle_rotate, glm::vec3* Vector_rotate);
	void set_camera_pos(ShaderProgram Shader);

	void moving(float* Move);
	void rotate(int Rotate[], bool fixed_target);

	void control_mouse(Window& game_win, int win_width,int win_hight);
	void control_moving();

private:
	glm::vec3 Camera_pos;
	glm::vec3 Target_point;
	glm::vec3 Camera_up = glm::vec3(0, 1, 0);
	glm::vec3 Side_vector, Forward_vector;

	float FAV_game;
	float near, far;
	float speed_m, speed_r;
	float Angle_rotated[3] = { 0,-90,0 };
	int mouse_current_x, mouse_current_y;
};


#endif 