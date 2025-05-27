#include "window.h"

#include <stdlib.h>

#include "../vendor/glad/gl.h"
#include <GLFW/glfw3.h>

struct _Window {
    uint32_t width, height;
    const char* title;
    GLFWwindow* windowHandle;
};

void internal_windowResizeCallback(GLFWwindow* window, int width, int height) {
    Window* win = glfwGetWindowUserPointer(window);
    win->width = width;
    win->height = height;
    glViewport(0, 0, width, height);
}

Window* windowNew(uint32_t width, uint32_t height, const char* title) {
    glfwInit();

    Window* window = malloc(sizeof(Window));
    window->windowHandle = glfwCreateWindow(width, height, title, NULL, NULL);
    window->width = width;
    window->height = height;
    window->title = title;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwMakeContextCurrent(window->windowHandle);
    glfwSetWindowUserPointer(window->windowHandle, window);
    glfwSetWindowSizeCallback(window->windowHandle, internal_windowResizeCallback);

    gladLoadGL(glfwGetProcAddress);

    int32_t fbWidth, fbHeight;
    glfwGetFramebufferSize(window->windowHandle, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);

    return window;
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

void windowSetPosition(Window* window, uint32_t x, uint32_t y) {
    glfwSetWindowPos(window->windowHandle, x, y);
}

Vec2 windowGetPosition(Window* window) {
    int x, y;
    glfwGetWindowPos(window->windowHandle, &x, &y);
    return (Vec2) { (float) x, (float) y };
}

uint8_t windowCloseEvent(Window* window) {
    return glfwWindowShouldClose(window->windowHandle);
}

void windowRefresh(Window* window) {
    glfwSwapBuffers(window->windowHandle);
    glfwPollEvents();
}

void windowDestroy(Window* window) {
    free(window);
}