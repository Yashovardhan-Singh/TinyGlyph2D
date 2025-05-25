#include "../src/window.h"

int main() {
    Window* win = windowNew(1280, 720, "Example");
    while (!windowCloseEvent(win)) {
        windowRefresh(win);
    }
    windowDestroy(win);
}