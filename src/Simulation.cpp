#include "../include/Simulation.h"

namespace sf {
    Simulation::Simulation(const Window &windowInitializer, const Uint32 rendererFlags, const Uint32 timeStep) :
            running(true),
            timeStep(timeStep),
            timePassed(SDL_GetTicks()),
            window(windowInitializer),
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
