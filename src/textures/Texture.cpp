#include "Texture.h"
#include "SOIL.h"
#include <iostream>

Texture::Texture(const std::string fileName) {
    id = SOIL_load_OGL_texture(fileName.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if (id == 0) {
		fprintf(stderr, "SOIL texture loading error: '%s'\n", SOIL_last_result()); 
        exit(EXIT_FAILURE);
    }

    printf("Texture %s loaded\n", fileName.c_str());
}

void Texture::bind() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, id);
}