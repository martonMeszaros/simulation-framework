//
// Created by meszi on 2018.07.24..
//

#ifndef SIMULATION_FRAMEWORK_EVENTDISPACHER_H
#define SIMULATION_FRAMEWORK_EVENTDISPACHER_H

#include "Event.h"

namespace sf {
    /** Create a dispatches that is responsible for managing events. */
    class EventDispatcher {
    public:
        EventDispatcher() = default;
        ~EventDispatcher() = default;

        /** Poll the next event in the event queue.
         *
         * @param event The object in which to store the event's data.
         * @return true, if an event was polled, false if there is no event in the queue.
         */
        bool pollEvent(Event &event);
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_EVENTDISPACHER_H
