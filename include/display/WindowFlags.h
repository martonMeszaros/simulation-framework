#ifndef SIMULATION_FRAMEWORK_WINDOWFLAGS_H
#define SIMULATION_FRAMEWORK_WINDOWFLAGS_H

#include <SDL_video.h>

namespace sf {
    enum WindowFlags {
        FULLSCREEN          = SDL_WINDOW_FULLSCREEN,
        // Create a fullscreen window at the resolution of the desktop.
        FULLSCREEN_DESKTOP  = SDL_WINDOW_FULLSCREEN_DESKTOP,
        OPENGL              = SDL_WINDOW_OPENGL,
        HIDDEN              = SDL_WINDOW_HIDDEN,
        BORDERLESS          = SDL_WINDOW_BORDERLESS,
        RESIZABLE           = SDL_WINDOW_RESIZABLE,
        MINIMIZED           = SDL_WINDOW_MINIMIZED,
        MAXIMIZED           = SDL_WINDOW_MAXIMIZED,
        INPUT_GRABBED       = SDL_WINDOW_INPUT_GRABBED,
        ALLOW_HIGHDPI       = SDL_WINDOW_ALLOW_HIGHDPI
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_WINDOWFLAGS_H
