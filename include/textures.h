
#pragma once

#include <string>
#include "tileset/tileset.h"

namespace opengl {

    void add(const std::string& id, const assets::tileset& tileset);
    void* get_texture(const std::string& tileset, const std::string& id, int& width, int& height);

}
