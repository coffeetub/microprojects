#include "renderer.h"
#include "framebuffer.h"
#include <X11/Xlib.h>
#include <unistd.h>

win* display_window;
Scre
screen *s = DefaultScreenOfDisplay(display);
display_window->width = s->width;
display_window->height = s->height;
display_window->display = XOpenDisplay(NULL);
display_window->screen = DefaultScreen(display);

Window* display(uint32_t background_color){
    display_window.bgcolor = background_color;
    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display , screen);
        0,0,
        display_window.width , display_window.height,
        0,
        BlackPixel(display , screen);
        background_color;
    );
}
