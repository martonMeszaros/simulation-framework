//
// Created by meszi on 2018.07.24..
//

#ifndef SIMULATION_FRAMEWORK_EVENT_H
#define SIMULATION_FRAMEWORK_EVENT_H

#include "EventType.h"

namespace sf {
    class Event {
    public:
        Event();
        ~Event();

        void setEvent(SDL_Event *e);
        EventType getType() const;
        SDL_Event *const getEvent() const;

    private:
        EventType type;
        SDL_Event *event;
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_EVENT_H
