#include "GlidingRectangles.h"

int main() {
    Uint32 rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    GlidingRectangles glidingRectangles("Gliding Rectangle", 480, 480, rendererFlags, 16);
    glidingRectangles.loop();
    return 0;
}