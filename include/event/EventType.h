//
// Created by meszi on 2018.07.24..
//

#ifndef SIMULATION_FRAMEWORK_EVENTTYPE_H
#define SIMULATION_FRAMEWORK_EVENTTYPE_H

#include <SDL_events.h>

namespace sf {
    enum EventType {
        QUIT = SDL_QUIT,
        KEYDOWN = SDL_KEYDOWN,
        KEYUP = SDL_KEYUP,
        MOUSEMOTION = SDL_MOUSEMOTION,
        MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN,
        MOUSEBUTTONUP = SDL_MOUSEBUTTONUP
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_EVENTTYPE_H
