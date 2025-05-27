// Window public API

#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>
#include "vector.h"

// Opaque type
typedef struct _Window Window;

// Constructor
Window* windowNew(uint32_t width, uint32_t height, const char* title);

// Getters
void* windowGetHandle(Window* window);
uint32_t windowGetWidth(Window* window);
uint32_t windowGetHeight(Window* window);
const char* windowGetTitle(Window* window);
Vec2 windowGetPosition(Window* window);

// Setters
void windowSetTitle(Window* window, const char* title);
void windowSetSize(Window* window, uint32_t width, uint32_t height);
void windowSetPosition(Window* window, uint32_t x, uint32_t y);

// Misc
uint8_t windowCloseEvent(Window* window);
void windowRefresh(Window* window);

// Destructor
void windowDestroy(Window* window);

#endif //WINDOW_H