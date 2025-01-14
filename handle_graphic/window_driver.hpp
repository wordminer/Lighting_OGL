#ifndef WINDOW_DRIVER_HPP
#define WINDOW_DRIVER_HPP

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <SDL.h>

class Window {
    public:
        Window(const std::string &ptr_name_window, int width_window, int hight_window, Uint32 SDL_init_flag, Uint32 window_flag);
        ~Window();

        SDL_Window* get_window_ptr();

        void Set_attribute();
        void swap_buffer();
        void clear_color(const GLclampf r, const GLclampf g, const GLclampf b, const GLclampf a);
        void swap_mouse(int x, int y);
        void apply_defaut_setting();

    private:
        std::string name_window;
        SDL_Window *window = nullptr;
        SDL_GLContext gl_context;
};

#endif