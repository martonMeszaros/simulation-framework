#ifndef SIMULATION_FRAMEWORK_RENDERERFLAGS_H
#define SIMULATION_FRAMEWORK_RENDERERFLAGS_H

#include <SDL_render.h>

namespace sf {
    enum RendererFlags {
        SOFTWARE        = SDL_RENDERER_SOFTWARE,
        ACCELERATED     = SDL_RENDERER_ACCELERATED,
        // Presenting the renderer is synchronized with refresh rate.
        PRESENTVSYNC    = SDL_RENDERER_PRESENTVSYNC,
        // Can render to texture.
        TARGETTEXTURE   = SDL_RENDERER_TARGETTEXTURE
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_RENDERERFLAGS_H
