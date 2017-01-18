
#include "engine.h"

Engine::Engine(string name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;
}

Engine::Engine(string name)
{
  m_WINDOW_NAME = name;
  m_WINDOW_HEIGHT = 0;
  m_WINDOW_WIDTH = 0;
  m_FULLSCREEN = true;
}

Engine::~Engine()
{
  delete m_window;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}

bool Engine::Initialize()
{
  // Start a window
  m_window = new Window();
  if(!m_window->Initialize(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT))
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  // Set the time
  m_currentTimeMillis = GetCurrentTimeMillis();

  // No errors
  return true;
}

void Engine::Run()
{
  m_running = true;
	keyboardInput = '\0';
	initialized = false;

  while(m_running)
  {
    // Update the DT
    m_DT = getDT();

    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
      Keyboard();
    }

    // Update and render the graphics
    m_graphics->Update(m_DT, keyboardInput, initialized);
    m_graphics->Render();
    initialized = true;
		

    // Swap to the Window
    m_window->Swap();
  }
}

void Engine::Keyboard()
{
  if(m_event.type == SDL_QUIT)
  {
    m_running = false;
  }
  else if (m_event.type == SDL_KEYDOWN)
  {
    // handle key down events here
    switch (m_event.key.keysym.sym)
    {
      case SDLK_ESCAPE:
        m_running = false;
        break;
			//follow mercurey
      case SDLK_1:
        keyboardInput = '1';
        break;
      //follow venus
      case SDLK_2:
        keyboardInput = '2';
        break;
      //follow earth
      case SDLK_3:
        keyboardInput = '3';
        break;
      //follow mars
      case SDLK_4:
        keyboardInput = '4';
        break;
      //follow jupiter
      case SDLK_5:
        keyboardInput = '5';
        break;
      //follow saturn
      case SDLK_6:
        keyboardInput = '6';
        break;
      //follow uranus
      case SDLK_7:
        keyboardInput = '7';
        break;
      //follow neptune
      case SDLK_8:
        keyboardInput = '8';
        break;
      //follow pluto
      case SDLK_9:
        keyboardInput = '9';
        break;
      //close zoom
      case SDLK_q:
        keyboardInput = 'q';
        break;
      //mid zoom
      case SDLK_w:
        keyboardInput = 'w';
        break;
      //far zoom
      case SDLK_e:
        keyboardInput = 'e';
        break;
      //side view
      case SDLK_r:
        keyboardInput = 'r';
        break;
      //close topdown view
      case SDLK_t:
        keyboardInput = 't';
        break;
      //far topdown view
      case SDLK_y:
        keyboardInput = 'y';
        break;
  	}
  }
}

unsigned int Engine::getDT()
{
  long long TimeNowMillis = GetCurrentTimeMillis();
  assert(TimeNowMillis >= m_currentTimeMillis);
  unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  m_currentTimeMillis = TimeNowMillis;
  return DeltaTimeMillis;
}

long long Engine::GetCurrentTimeMillis()
{
  timeval t;
  gettimeofday(&t, NULL);
  long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  return ret;
}
