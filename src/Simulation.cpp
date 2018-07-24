//
// Created by meszi on 2018.07.24..
//

#include "../include/Simulation.h"

namespace sf {

    Simulation::Simulation(const Window &window, const Renderer &renderer, const Uint32 timeStamp) :
            running(true),
            window(window),
            renderer(renderer),
            timeStep(timeStamp) {}

    Simulation::Simulation(const Uint32 subsystems, const Window &window,
                           const Renderer &renderer, const Uint32 timeStamp) :
            initializer(subsystems),
            running(true),
            window(window),
            renderer(renderer),
            timeStep(timeStamp) {}

    void Simulation::init() {}

    void Simulation::shutdown() {}

    void Simulation::startFrame() {
        timePassed = SDL_GetTicks();
    }

    const bool Simulation::pollEvent() {
        return eventDispatcher.pollEvent(currentEvent);
    }

    void Simulation::waitForNextFrame() {
        while (timePassed + timeStep > SDL_GetTicks()) {
            SDL_Delay(0);
        }
    }
}   // sf
