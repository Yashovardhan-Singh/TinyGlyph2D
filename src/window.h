// Window public API

#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

#include "vector.h"
#include "defines.h"

// Opaque type
typedef struct _Window Window;

// Constructor
API Window* windowNew(uint32_t width, uint32_t height, const char* title);

// Getters
API void* windowGetHandle(Window* window);
API uint32_t windowGetWidth(Window* window);
API uint32_t windowGetHeight(Window* window);
API const char* windowGetTitle(Window* window);
API Vec2 windowGetPosition(Window* window);

// Setters
API void windowSetTitle(Window* window, const char* title);
API void windowSetSize(Window* window, uint32_t width, uint32_t height);
API void windowSetPosition(Window* window, uint32_t x, uint32_t y);

// Misc
API uint8_t windowCloseEvent(Window* window);
API void windowRefresh(Window* window);

// Destructor
API void windowDestroy(Window* window);

#endif //WINDOW_H