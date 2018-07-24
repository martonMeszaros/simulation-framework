//
// Created by meszi on 2018.07.23..
//

#ifndef SIMULATION_FRAMEWORK_RGBA_H
#define SIMULATION_FRAMEWORK_RGBA_H

#include <SDL_quit.h>

namespace sf {
    /** Structure representing RGBA color. */
    struct RGBA {
        Uint8 red;
        Uint8 green;
        Uint8 blue;
        Uint8 alpha;

        /** Create a fully opaque color (alpha = 255). */
        RGBA(const Uint8 red, const Uint8 green, const Uint8 blue);
        RGBA(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha);
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_RGBA_H
