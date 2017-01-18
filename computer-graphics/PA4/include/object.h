#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object(std::string fileName);
    ~Object();
    void Update(unsigned int dt);
    void Render();

    glm::mat4 GetModel();

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angle;
};

#endif /* OBJECT_H */
