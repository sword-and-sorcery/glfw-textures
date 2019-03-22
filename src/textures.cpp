
#include "textures.h"
#include <iostream>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace opengl {
    namespace {
        std::map<std::string, const assets::tileset*> tilesets; // TODO: !!!
        std::map<std::pair<std::string, std::string>, std::tuple<int, int, void*>> images;
    }

    void add(const std::string& id, const assets::tileset& tileset) {
        tilesets.emplace(std::make_pair(id, &tileset));
    }

    void* get_texture(const std::string& tileset, const std::string& id, int& width, int& height) {
        auto it_images = images.find(std::make_pair(tileset, id));
        if (it_images != images.end()) {
            width = std::get<0>(it_images->second);
            height = std::get<1>(it_images->second);
            return std::get<2>(it_images->second);
        }

        auto it = tilesets.find(tileset);
        if (it != tilesets.end()) {
            auto tile = it->second->get(id);

            unsigned char* image_data = stbi_load(tile.filename.c_str(), &width, &height, NULL, 4);

            GLuint my_opengl_texture;
            glGenTextures(1, &my_opengl_texture);
            glBindTexture(GL_TEXTURE_2D, my_opengl_texture);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);

            void* ret = (void*)(intptr_t)my_opengl_texture;
            images[std::make_pair(tileset, id)] = std::make_tuple(width, height, ret);
            return ret;
        }
        throw std::runtime_error("Tileset (or tile not found)");
    }
}
