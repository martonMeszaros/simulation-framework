#ifndef SIMULATION_FRAMEWORK_EVENT_H
#define SIMULATION_FRAMEWORK_EVENT_H

#include <SDL_events.h>

namespace sf {
    /** Contains an event registered by SDL. */
    class Event {
    public:
        Event() = default;
        ~Event() = default;

        /** Get the underlying SDL_Event object. */
        SDL_Event & getEvent();
        /** Get the event's type. Can be checked against SDL_EventType or sf::EventType. */
        Uint32 getType() const;

    private:
        SDL_Event event;
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_EVENT_H
