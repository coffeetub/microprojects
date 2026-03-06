#include "event.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>

static int running = 1;
static int last_key = 0;
static int mousex = 0;
static int mousey = 0;

int poll_events(win *w)
{
    XEvent event;

    while (XPending(w->display))
    {
        XNextEvent(w->display, &event);

        switch (event.type)
        {
            case DestroyNotify:
                running = 0;
                break;

            case KeyPress:
                last_key = XLookupKeysym(&event.xkey, 0);
                break;

            case MotionNotify:
                mousex = event.xmotion.x;
                mousey = event.xmotion.y;
                break;

            case ConfigureNotify:
                w->width  = event.xconfigure.width;
                w->height = event.xconfigure.height;
                break;
        }
    }

    return running;
}

int key_pressed()
{
    return last_key;
}

int mouse_x()
{
    return mousex;
}

int mouse_y()
{
    return mousey;
}