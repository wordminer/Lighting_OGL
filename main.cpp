#include "handle_data.hpp"
#include "camera.hpp"
#include "texture.hpp"
#include "block.hpp"
#include "const.hpp"
#include "handle_data.hpp"
#include "materials.hpp"


#include "stb_image.h"

void buffer_data(Block block_class, Graphic_data& GP){
    GP.Buffer_array_data(block_class.Block_vertices.data(), (GLsizeiptr)(block_class.Block_vertices.size() * sizeof(Vertex)), GL_STATIC_DRAW);
    // std::cout<< block_class.Block_vertices[0].m_pos.x << std::endl;
    // std::cout<< block_class.Block_vertices[0].m_pos.y << std::endl;
    // std::cout<< block_class.Block_vertices[0].m_pos.z << std::endl;
    GP.AttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (void *)getOffsetOfPos());
    GP.AttribPointer(1, 3, GL_FLOAT, false, sizeof(Vertex), (void *)getOffsetOfColor());
    GP.AttribPointer(2, 3, GL_FLOAT, false, sizeof(Vertex), (void *)getOffsetOfNormal());
    GP.AttribPointer(3, 2, GL_FLOAT, false, sizeof(Vertex), (void *)getOffsetOfTexCoord());
    GP.AttribPointer(4, 2, GL_FLOAT, false, sizeof(Vertex), (void *)getOffsetOfFaceID());
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

    const char* iron_tex[] = {
        "resources/image/iron/iron.jpg",
        "resources/image/iron/iron.jpg",
        "resources/image/iron/iron.jpg",
        "resources/image/iron/iron.jpg",
        "resources/image/iron/iron.jpg",
        "resources/image/iron/iron.jpg"
    }; 

    Block_texture block_test(iron_tex);
    block_test.Set_shader_texture(Shader_rec);

    glm::vec3 light_coord = glm::vec3(5, 10, 5);

    Block test(glm::vec3(0,0,0), 3, 3, 3);
    test.Create_block(false, Block_tex, face_create_key, glm::vec3(0.5, 1, 0.3), normal_face_vector, Texture_coord_face);
    // Block sunlight(light_coord, 0.5, 0.5, 0.5);
    // sunlight.Create_block(false, Block_tex, face_create_key, glm::vec3(1, 1, 1), normal_face_vector);

    Graphic_data data;
   
    Material iron{
        glm::vec3(0.508273, 0.508273, 0.508273),
        glm::vec3(0.50754, 0.50754, 0.50754),
        glm::vec3(0.19225, 0.19225,	0.19225),
        4
    }; 

    Material light{
        glm::vec3(1, 1, 1),
        glm::vec3(1, 1, 1),
        glm::vec3(1, 1, 1)
    };    

    screen.swap_mouse(WIDTH_WIN / 2, HIGHT_WIN / 2);
    
    while (running) {
        //SDL_GetMouseState(&mouse_current_x, &mouse_current_y);
        Main_view.control_mouse(screen, WIDTH_WIN, HIGHT_WIN);

        screen.clear_color(0.2f, 0.3f, 0.3f, 1.0f);
        Shader_rec.activate();
        // Shader_rec.uniformVec3("vertexColor", 1.0f, 0.5f, 0.3f);
        Shader_rec.uniformVec3("light_pos", light_coord);
        Shader_rec.uniformVec3("camera_pos", Main_view.Camera_pos);
        set_material_uniform(Shader_rec, iron);
        set_light_uniform(Shader_rec, light);
        block_test.Bind_texture();
        
            // std::cout << Main_view.Camera_pos.x << Main_view.Camera_pos.y << Main_view.Camera_pos.z;
        buffer_data(test, data);
        data.Bind_vertex_array();
        Main_view.set_position(Shader_rec, test.Position, 0, 0);
        Main_view.set_camera_pos(Shader_rec);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        //draw sun

        // buffer_data(sunlight, data);
        // data.Bind_vertex_array();
        // Main_view.set_position(Shader_rec, sunlight.Position, 0, 0);
        // Main_view.set_camera_pos(Shader_rec);
        // Shader_rec.uniformVec3("light_color", glm::vec3(10, 10, 10));
        // Shader_rec.uniformVec3("light_pos", glm::vec3(0,0,0));

        // glDrawArrays(GL_TRIANGLES, 0, 36);


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

