#include "../../include/event/Event.h"

namespace sf {
    SDL_Event & Event::getEvent() {
        return event;
    }

    Uint32 Event::getType() const {
        return event.type;
    }
}
