// get function defines
#include "window.h"

// malloc
#include <stdlib.h>

// Glad is always included before glfw
#include "../vendor/glad/gl.h"
#include <GLFW/glfw3.h>

// Internal Struct
struct _Window {
    uint32_t width, height;
    const char* title;
    GLFWwindow* windowHandle;
};

// Callback to window resize event, glfw calls this automatically
// While window parameter is not used, it needs to be here, since the callback function pointer expects it there
// from GLFW3.h: typedef void (* GLFWwindowsizefun)(GLFWwindow* window, int width, int height);
PRIVATE void internal_windowResizeCallback(GLFWwindow* window, int width, int height) {
    Window* win = glfwGetWindowUserPointer(window); // retrieve data attached to window, through pointer we set earlier
    win->width = width; // set the new width internally
    win->height = height; // set the new height internally
    glViewport(0, 0, width, height); // resize the rendering viewport of opengl to fit window
}

// Return a pointer to a fresh new window
Window* windowNew(uint32_t width, uint32_t height, const char* title) {
    glfwInit(); // initialise GLFW

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // set major version of opengl
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // set minor version of opengl
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // set profile of opengl

    // Allocate memory for window and init fields
    Window* window = malloc(sizeof(Window));
    window->windowHandle = glfwCreateWindow(width, height, title, NULL, NULL);  // return pointer to our window
    window->width = width;  // set width
    window->height = height;    // set height
    window->title = title;  // set title

    glfwMakeContextCurrent(window->windowHandle); // attach the window to the thread on which opengl calls are issued
    glfwSetWindowUserPointer(window->windowHandle, window); // attach the window pointer to our custom window struct
    glfwSetWindowSizeCallback(window->windowHandle, internal_windowResizeCallback); // pass resize callback

    gladLoadGL(glfwGetProcAddress); // load gl functions through GLAD, glfwGetProcAddress returns address of process

    int32_t fbWidth, fbHeight;  // framebuffer width and framebuffer height
    glfwGetFramebufferSize(window->windowHandle, &fbWidth, &fbHeight); // get window(framebuffer) width and height
    glViewport(0, 0, fbWidth, fbHeight);    // set opengl rendering viewport

    return window;  // return pointer to our custom window struct
}

// Void pointer here because we don't want to reveal glfw as part of public api
void* windowGetHandle(Window* window) {
    return window->windowHandle;
}

uint32_t windowGetWidth(Window* window) {
    return window->width;
}

uint32_t windowGetHeight(Window* window) {
    return window->height;
}

void windowSetTitle(Window* window, const char* title) {
    glfwSetWindowTitle(window->windowHandle, title);
}

const char* windowGetTitle(Window* window) {
    return window->title;
}

void windowSetSize(Window* window, uint32_t width, uint32_t height) {
    glfwSetWindowSize(window->windowHandle, width, height);
}

void windowSetSizeVec2(Window* window, Vec2 size) {
    glfwSetWindowSize(window->windowHandle, (int32_t) size.x, (int32_t) size.y);
}

void windowSetPosition(Window* window, uint32_t x, uint32_t y) {
    glfwSetWindowPos(window->windowHandle, x, y);
}

void windowSetPositionVec2(Window* window, Vec2 position) {
    glfwSetWindowPos(window->windowHandle, (int32_t) position.x, (int32_t) position.y);
}

Vec2 windowGetPosition(Window* window) {
    uint32_t x, y;
    glfwGetWindowPos(window->windowHandle, &x, &y);
    return (Vec2) { (float) x, (float) y };
}

Vec2 windowGetSize(Window* window) {
    uint32_t fbx, fby;
    glfwGetFramebufferSize(window->windowHandle, &fbx, &fby);
    return (Vec2) { (float) fbx, (float) fby };
}

// Return if window should close
uint8_t windowCloseEvent(Window* window) {
    return glfwWindowShouldClose(window->windowHandle);
}

// Needed for window to not get stale or freeze
void windowRefresh(Window* window) {
    // Swap the front and back buffer
    // this is needed because windows have 2 buffers, front and back.
    // the front buffer is used to display whatever is going on screen
    // the back buffer is used to store whatever we are rendering
    // when we are done rendering, we swap the buffers, so that the completed back buffer
    // is now being displayed, and the front buffer is now being drawn on. This swapping happens every frame.
    glfwSwapBuffers(window->windowHandle);
    glfwPollEvents();   // poll events like window close, window redraw, window rezise, etc.
}

// free the pointer to the allocated window struct
void windowDestroy(Window* window) {
    free(window);
}