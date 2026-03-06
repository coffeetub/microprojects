#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdint.h>

void init_frame(int w , int h , uint32_t bg);
void clear_frame();
void framebuffer_set_pixel(int x , int y , uint32_t colour);
uint32_t* framebuffer_get();
int get_width();
int get_height();
void set_width(int w);
void set_height(int h);
//void update_frame();
void set_bgcolor(uint32_t colour);

#endif