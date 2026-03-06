#include "renderer.h"
#include "framebuffer.h"
#include "event.h"
#include <X11/Xlib.h>
#include <unistd.h>
#include <stdlib.h>


win* init_display(uint32_t background_color)
{
    win* display_window = malloc(sizeof(win));

    display_window->display = XOpenDisplay(NULL);
    display_window->screen = DefaultScreen(display_window->display);

    Screen *s = DefaultScreenOfDisplay(display_window->display);

    display_window->width  = s->width;
    display_window->height = s->height;

    display_window->bgcolor = background_color;

    display_window->window = XCreateSimpleWindow(
        display_window->display,
        RootWindow(display_window->display, display_window->screen),
        0, 0,
        display_window->width,
        display_window->height,
        0,
        BlackPixel(display_window->display, display_window->screen),
        display_window->bgcolor
    );
    display_window->gc = XCreateGC(
    display_window->display,
    display_window->window,
    0,
    NULL
    );
    
    XSelectInput(
    display_window->display,
    display_window->window,
    ExposureMask |
    KeyPressMask |
    PointerMotionMask |
    StructureNotifyMask
    );

    init_frame(display_window->width,display_window->height,display_window->bgcolor);

    clear_frame();

    display_window->image = XCreateImage(
    display_window->display,
    DefaultVisual(display_window->display, display_window->screen),
    24,
    ZPixmap,
    0,
    (char*)framebuffer_get(),
    get_width(),
    get_height(),
    32,
    0
    );


    XMapWindow(display_window->display, display_window->window);
    XFlush(display_window->display);

    return display_window;
}

void render_frame(win* display_window){
    XPutImage(
    display_window->display,
    display_window->window,
    display_window->gc,
    display_window->image,
    0,0,
    0,0,
    get_width(),
    get_height()
    );
    XFlush(display_window->display);
}

void draw_line(int x0,int y0,int x1,int y1,uint32_t color)
{
    int dx = abs(x1-x0);
    int dy = abs(y1-y0);

    int sx = x0<x1 ? 1 : -1;
    int sy = y0<y1 ? 1 : -1;

    int err = dx - dy;

    while(1)
    {
        framebuffer_set_pixel(x0,y0,color);

        if(x0==x1 && y0==y1) break;

        int e2 = 2*err;

        if(e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if(e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_rect(int x,int y,int w,int h,uint32_t color)
{
    draw_line(x, y, x+w, y, color);
    draw_line(x, y, x, y+h, color);
    draw_line(x+w, y, x+w, y+h, color);
    draw_line(x, y+h, x+w, y+h, color);
}

void fill_rect(int x,int y,int w,int h,uint32_t color)
{
    for(int i=y;i<y+h;i++)
    {
        for(int j=x;j<x+w;j++)
        {
            framebuffer_set_pixel(j,i,color);
        }
    }
}

void set_pixel(int x , int y , uint32_t colour){
    framebuffer_set_pixel(x,y,colour);
}


