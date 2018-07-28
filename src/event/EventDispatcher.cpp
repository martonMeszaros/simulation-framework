#include <iostream>
#include "../../include/event/EventDispatcher.h"

namespace sf {
    bool EventDispatcher::pollEvent(Event &event) {
        // SDL_PollEvent() return an int, that's either 0 (no event), or 1.
        return static_cast<bool>(SDL_PollEvent(&event.getEvent()));
    }
}
