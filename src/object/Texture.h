#pragma once
#include <GL/glew.h>
#include <string>


class Texture {
private:
    GLuint textureId;
public:
    Texture(const std::string fileName);

    void bind();
};
