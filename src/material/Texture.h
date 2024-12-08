#pragma once
#include <GL/glew.h>
#include <string>


class Texture {
private:
    GLuint textureId;
    std::string fileName;

public:
    Texture(const std::string fileName);

    void bind();
    std::string getFileName();
};
