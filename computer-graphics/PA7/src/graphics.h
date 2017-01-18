#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "object.h"

class Graphics
{
  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void Update(unsigned int dt, char keyboardInput, bool initialized);
    void Render();

  private:
    std::string ErrorString(GLenum error);

    Camera *m_camera;
    Shader *m_shader;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;

    Object *sun;
		Object *mercury;
		Object *venus;
		Object *earth;
		Object *mars;
		Object *jupiter;
		Object *saturn;
		Object *saturnsring;
		Object *uranus;
		Object *neptune;
		Object *pluto;
		Object *stars;

};

#endif /* GRAPHICS_H */
