import ctypes
import time

renderer = ctypes.CDLL("./librenderer.so")

renderer.init_display.argtypes = [ctypes.c_uint32]
renderer.init_display.restype = ctypes.c_void_p

renderer.set_pixel.argtypes = [
    ctypes.c_int,
    ctypes.c_int,
    ctypes.c_uint32,
    ctypes.c_void_p
]

renderer.render_frame.argtypes = [ctypes.c_void_p]

window = renderer.init_display(0x000000)

for i in range(400):
    renderer.set_pixel(i, i, 0xff0000, window)

renderer.render_frame(window)

time.sleep(5)