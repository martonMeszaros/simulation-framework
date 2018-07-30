#ifndef SIMULATION_FRAMEWORK_SUBSYSTEMS_H
#define SIMULATION_FRAMEWORK_SUBSYSTEMS_H

#include <SDL.h>

namespace sf {
    enum SubSystems {
        TIMER           = SDL_INIT_TIMER,
        AUDIO           = SDL_INIT_AUDIO,
        VIDEO           = SDL_INIT_VIDEO,
        JOYSTICK        = SDL_INIT_JOYSTICK,
        HAPSTICK        = SDL_INIT_HAPTIC,
        GAMECONTROLLER  = SDL_INIT_GAMECONTROLLER,
        EVENTS          = SDL_INIT_EVENTS,
        EVERYTHING      = SDL_INIT_EVERYTHING
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_SUBSYSTEMS_H
