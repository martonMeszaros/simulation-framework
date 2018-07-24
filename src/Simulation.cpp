//
// Created by meszi on 2018.07.24..
//

#include "../include/Simulation.h"

namespace sf {

    Simulation::Simulation(const std::string &windowTitle, const int windowWidth, const int windowHeight,
                               const Uint32 rendererFlags, const Uint32 timeStamp) :
            timeStep(timeStamp),
            timePassed(0),
            running(true),
            // Forces the window to start shown, with no providable flags.
            window(windowTitle, windowWidth, windowHeight, false),
            renderer(window, rendererFlags) {}

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
