//
// Created by meszi on 2018.07.24..
//

#include <iostream>
#include "../../include/event/EventDispatcher.h"

namespace sf {
    bool EventDispatcher::pollEvent(Event &event) {
        return static_cast<bool>(SDL_PollEvent(&event.getEvent()));
    }
}
