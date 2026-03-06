#include <X11/Xlib.h>
#include <unistd.h>

int main(){
    Display *display = XOpenDisplay(NULL);

    int screen = DefaultScreen(display);
    Screen *s = DefaultScreenOfDisplay(display);

    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        10, 10,
        s->width,s->height ,
        0,
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );

    XMapWindow(display, window);
    XFlush(display);

    sleep(10);

    XCloseDisplay(display);
}