#ifndef EVENT_H
#define EVENT_H

#include "renderer.h"
int poll_events(win *window);

int key_pressed();

int mouse_x();
int mouse_y();

#endif