#include "handle_data.hpp"
#include "camera.hpp"
#include "texture.hpp"
#include "block.hpp"
#include "const.hpp"


#include "stb_image.h"


void load_cube(){
    
}

int main(int argc, char* argv[]) {
    Window screen("hello", WIDTH_WIN, HIGHT_WIN, SDL_INIT_VIDEO, SDL_WINDOW_OPENGL);
    ShaderProgram Shader_rec(vshader_path, 
                             fshader_path);

    
    Shader_rec.activate();
    
    glEnable(GL_DEPTH_TEST);

    bool running = true;
    SDL_Event event;

    glm::vec3 Rotate_axis[] = { glm::vec3(1.0f, 0.0f, 0.0f),
                               glm::vec3(0.0f, 1.0f, 0.0f),
                               glm::vec3(0.0f, 0.0f, 1.0f) };
    glm::vec3 Camera_pos = { 0.0f, 0.0f, 10.0f };
    Camera Main_view(Camera_pos, 45, 0.05, 0.1, 0.1f, 100.0f);
    Main_view.set_viewrange(Shader_rec, WIDTH_WIN, HIGHT_WIN);

    const char* Block_tex[] = {
    "resources/image/test_block/Block_front.jpg",
    "resources/image/test_block/Block_back.jpg",
    "resources/image/test_block/Block_right.jpg",
    "resources/image/test_block/Block_left.jpg",
    "resources/image/test_block/Block_up.jpg",
    "resources/image/test_block/Block_down.jpg"
    };

    Block test(glm::vec3(0,0,0), 1, 1, 1);
    test.Create_block(false, Block_tex, face_create_key, glm::vec3(0.5, 1, 0.3), normal_face_vector);

    screen.swap_mouse(WIDTH_WIN / 2, HIGHT_WIN / 2);
    
    while (running) {
        //SDL_GetMouseState(&mouse_current_x, &mouse_current_y);
        Main_view.control_mouse(screen, WIDTH_WIN, HIGHT_WIN);

        screen.clear_color(0.2f, 0.3f, 0.3f, 1.0f);
        Shader_rec.activate();
        // Shader_rec.uniformVec3("vertexColor", 1.0f, 0.5f, 0.3f);
        Shader_rec.uniformVec3("light_color", glm::vec3(1, 1, 1));
        Shader_rec.uniformVec3("light_pos", glm::vec3(5, 10, 15));
        
        test.data.Bind_vertex_array();
        Main_view.set_position(Shader_rec, glm::vec3(0,0,0), 0, 0);
        Main_view.set_camera_pos(Shader_rec);

        glDrawArrays(GL_TRIANGLES, 0, 36);


        while (SDL_PollEvent(&event)) {
            if (SDL_QUIT == event.type) {
                running = false;
                SDL_Quit();
            }
            if (SDL_KEYDOWN == event.type) {
                if (SDL_SCANCODE_TAB == event.key.keysym.scancode) {
                    if (SDL_GetRelativeMouseMode()) {
                        SDL_SetRelativeMouseMode(SDL_FALSE);
                    }
                    else {
                        screen.swap_mouse(WIDTH_WIN / 2, HIGHT_WIN / 2);
                        SDL_SetRelativeMouseMode(SDL_TRUE);
                    }
                }
            }
        }
        
        Main_view.control_moving();
        
        screen.swap_buffer();
        
    }

    Shader_rec.purge();
    return 0;
}
