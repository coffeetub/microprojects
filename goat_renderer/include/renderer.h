#ifndef RENDERER_H
#define RENDERER_H

#include <stdint.h>
#include <X11/Xlib.h>
#include <unistd.h>
typedef struct win{
    int width;
    int height;
    uint32_t bgcolor;
    Window window;
    Display* display;
    int screen;
    GC gc;
    XImage* image;
}win;

win* init_display(uint32_t bgcolor);
void render_frame(win* display_window);
void draw_line(int x0 , int y0 , int x1 , int y1 , uint32_t color);
void draw_rect(int x , int y , int w ,int h , uint32_t color);
void fill_rect(int x , int y , int w , int h , uint32_t color);
void set_pixel(int x , int y , uint32_t colour);
#endif