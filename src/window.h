// Window public API

#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

#include "vector.h"
#include "defines.h"

// Opaque type
typedef struct _Window Window;

// Constructor
TGAPI Window* windowNew(uint32_t width, uint32_t height, const char* title);

// Getters
TGAPI void* windowGetHandle(Window* window);
TGAPI uint32_t windowGetWidth(Window* window);
TGAPI uint32_t windowGetHeight(Window* window);
TGAPI const char* windowGetTitle(Window* window);
TGAPI Vec2 windowGetPosition(Window* window);

// Setters
TGAPI void windowSetTitle(Window* window, const char* title);
TGAPI void windowSetSize(Window* window, uint32_t width, uint32_t height);
TGAPI void windowSetPosition(Window* window, uint32_t x, uint32_t y);

// Misc
TGAPI uint8_t windowCloseEvent(Window* window);
TGAPI void windowRefresh(Window* window);

// Destructor
TGAPI void windowDestroy(Window* window);

#endif //WINDOW_H