#include "framebuffer.h"
#include <stdlib.h>
#include <stdint.h>

static uint32_t *framebuffer = NULL;
static int width = 0;
static int height = 0;
static uint32_t bg_colour = 0x000000;

void init_frame(int w , int h , uint32_t bg){
    width = w;
    height = h;
    bg_colour = bg;
    framebuffer = (uint32_t*)malloc(sizeof(uint32_t) * w * h);
}

void clear_frame(){
    for(int i = 0 ; i<width*height ; i++){
        framebuffer[i] = bg_colour;
    }
}

void framebuffer_set_pixel(int x , int y , uint32_t colour){
    if(y>0 && y<=height && x > 0 && x <= width){
        framebuffer[y*width + x] = colour;
    }
}

uint32_t* framebuffer_get(){
    return framebuffer;
}

int get_width(){
    return width;
}

int get_height(){
    return height;
}

void set_width(int w){
    width = w;
}

void set_height(int h){
    height = h;
}

void set_bgcolor(uint32_t colour){
    bg_colour = colour;
}

