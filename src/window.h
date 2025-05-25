// Window public API

#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

// Opaque type
typedef struct _Window Window;

// Constructor
Window* windowNew(uint32_t width, uint32_t height, const char* title);

// Getters
void* windowGetHandle(Window* window);
uint32_t windowGetWidth(Window* window);
uint32_t windowGetHeight(Window* window);
const char* windowGetTitle(Window* window);
uint32_t windowGetPositionX(Window* window);    // Todo: Reimplement when vectors are added
uint32_t windowGetPositionY(Window* window);    // Todo: Reimplement when vectors are added

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