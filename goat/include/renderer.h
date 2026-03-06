#ifndef RENDERER_H
#define RENDERER_H

#include <stdint.h>
#include <X11/Xlib.h>
#include <unistd.h>
typedef struct win{
    int width;
    int height;
    uint32_t bgcolor;
    int fps;
    Window window;
    Display* display;
    int screen;
}win;

void display(uint32_t bgcolor);

#endif