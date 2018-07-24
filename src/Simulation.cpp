//
// Created by meszi on 2018.07.24..
//

#include "../include/Simulation.h"

namespace sf {

    Simulation::Simulation(const Window &window, const Renderer &renderer) :
            running(true),
            window(window),
            renderer(renderer) {}

    Simulation::Simulation(const Uint32 subsystems, const Window &window, const Renderer &renderer) :
            initializer(subsystems),
            running(true),
            window(window),
            renderer(renderer) {}

    void Simulation::init() {}

    void Simulation::shutdown() {}

    const bool Simulation::pollEvent() {
        return eventDispatcher.pollEvent(currentEvent);
    }
}   // sf
