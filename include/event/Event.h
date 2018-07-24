//
// Created by meszi on 2018.07.24..
//

#ifndef SIMULATION_FRAMEWORK_EVENT_H
#define SIMULATION_FRAMEWORK_EVENT_H

#include <SDL_events.h>

namespace sf {
    class Event {
    public:
        Event() = default;
        ~Event() = default;

        SDL_Event & getEvent();
        Uint32 getType() const;

    private:
        SDL_Event event;
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_EVENT_H
