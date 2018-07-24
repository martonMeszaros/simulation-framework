//
// Created by meszi on 2018.07.24..
//

#include "../../include/event/Event.h"

namespace sf {
    Event::Event() : type(EventType::NONE), event(nullptr) {}

    Event::~Event() {
        delete event;
    }

    void Event::setEvent(SDL_Event *e) {
        type = static_cast<EventType>(e->type);
        event = e;
    }

    EventType Event::getType() const {
        return type;
    }

    SDL_Event *const Event::getEvent() const {
        return event;
    }
}
