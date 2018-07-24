//
// Created by meszi on 2018.07.24..
//

#include "../../include/event/Event.h"

namespace sf {
    SDL_Event & Event::getEvent() {
        return event;
    }

    Uint32 Event::getType() const {
        return event.type;
    }
}
