#include "window_driver.hpp"
#include "SDL.h"

Window::Window(const std::string &ptr_name_window, int width_window, int hight_window, Uint32 SDL_init_flag, Uint32 window_flag){
    Window::name_window = ptr_name_window;
    
    if (SDL_Init(SDL_init_flag)< 0){std::cout<< "SDL cant be initalizated !!!!!" << std::endl << SDL_GetError();}
    this->Set_attribute();    

    this->window = SDL_CreateWindow(
        this->name_window.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width_window,
        hight_window,
        window_flag
    );
    if (NULL == this->window) {std::cout<< "Error while creating window!!!" <<  std::endl << SDL_GetError();}

    this->gl_context = SDL_GL_CreateContext(this->window);

    if (GLEW_OK != glewInit()) {
        std::cout << "failed to initialized GLEW" << std::endl;
        exit(1);
    }
}

Window::~Window(){
    SDL_GL_DeleteContext(this->gl_context);
    SDL_DestroyWindow(this->window);
}

SDL_Window* Window::get_window_ptr(){return this->window;}

void Window::Set_attribute(){
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
}

void Window::clear_color(const GLclampf r, const GLclampf g, const GLclampf b, const GLclampf a){
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swap_buffer(){
    SDL_GL_SwapWindow(this->window);
}

void Window::swap_mouse(int x, int y) {
    SDL_WarpMouseInWindow(this->window, x, y);
}

