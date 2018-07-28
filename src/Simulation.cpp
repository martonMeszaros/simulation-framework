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

    const bool Simulation::isRunning() {
        timePassed = SDL_GetTicks();
        return running;
    }

    void Simulation::setRunning(const bool running) {
        this->running = running;
    }

    const bool Simulation::pollEvent() {
        return eventDispatcher.pollEvent(currentEvent);
    }

    void Simulation::waitForNextFrame() {
        while (timePassed + timeStep > SDL_GetTicks()) {
            // Ideally, we would wait exactly the difference between
            // the evaluations sides, but delays under 10ms are inconsistent.
            SDL_Delay(0);
        }
    }
}   // sf
