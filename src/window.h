// Window public API

#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

#include "vector.h"
#include "defines.h"

/**
 * @brief   Opaque type to Window struct
 */
typedef struct _Window Window;

/**
 * @brief   Create a new window
 * @param   width: uint32_t, width of the window
 * @param   height: uint32_t, height of the window
 * @returns Pointer to a new Window
 * @see     Window
 */
TGAPI Window* windowNew(uint32_t width, uint32_t height, const char* title);

/**
 * @brief   Get raw pointer to the window
 * @param   window: Pointer to the window
 * @returns Raw pointer to GLFW as void*
 * @see     Window
 */
TGAPI INLINE void* windowGetHandle(Window* window);

/**
 * @brief   Get width of current window
 * @param   window: Pointer to the window
 * @returns Width of the window
 * @see     Window
 */
TGAPI INLINE uint32_t windowGetWidth(Window* window);

/**
 * @brief   Get height of current window
 * @param   window: Pointer to the window
 * @returns Height of the window
 * @see     Window
 */
TGAPI INLINE uint32_t windowGetHeight(Window* window);

/**
 * @brief   Get title of current window
 * @param   window: Pointer to the window
 * @returns Title of the window
 * @see     Window
 */
TGAPI INLINE const char* windowGetTitle(Window* window);

/**
 * @brief   Get position of current window
 * @param   window: Pointer to the window
 * @returns 2D Vector, with position of the window as components
 * @see     Window, Vec2
 */
TGAPI INLINE Vec2 windowGetPosition(Window* window);

/**
 * @brief   Get size of current window
 * @param   window: Pointer to the window
 * @returns 2D Vector, with size of the window as components
 * @see     Window, Vec2
 */
TGAPI INLINE Vec2 windowGetSize(Window* window);

/**
 * @brief   Set title of current window
 * @param   window: Pointer to the window
 * @param   title: String, new title
 * @returns void
 * @see     Window
 */
TGAPI INLINE void windowSetTitle(Window* window, const char* title);

/**
 * @brief   Set title of current window
 * @param   window: Pointer to the window
 * @param   width: new width
 * @param   height: new height
 * @returns void
 * @see     Window
 */
TGAPI INLINE void windowSetSize(Window* window, uint32_t width, uint32_t height);

/**
 * @brief   Set title of current window
 * @param   window: Pointer to the window
 * @param   size: new size, with width and height as components of Vec2
 * @returns void
 * @see     Window, Vec2
 */
TGAPI INLINE void windowSetSizeVec2(Window* window, Vec2 size);

/**
 * @brief   Set title of current window
 * @param   window: Pointer to the window
 * @param   x: new x position
 * @param   y: new y position
 * @returns void
 * @see     Window
 */
TGAPI INLINE void windowSetPosition(Window* window, uint32_t x, uint32_t y);

/**
 * @brief   Set title of current window
 * @param   window: Pointer to the window
 * @param   position: new position, with x and y as components of Vec2
 * @returns void
 * @see     Window, Vec2
 */
TGAPI INLINE void windowSetPositionVec2(Window* window, Vec2 position);

/**
 * @brief   Check if window the window received a close event
 * @param   window: Pointer to the window
 * @returns 1 if window close event has not been received
 * @see     Window
 */
TGAPI INLINE uint8_t windowCloseEvent(Window* window);

/**
 * @brief   Refresh the window
 * @param   window: Pointer to the window
 * @returns void
 * @see     Window
 */
TGAPI INLINE void windowRefresh(Window* window);

/**
 * @brief   De initialise the window
 * @param   window: Pointer to the window
 * @returns void
 * @see     Window
 */
TGAPI INLINE void windowDestroy(Window* window);

#endif //WINDOW_H