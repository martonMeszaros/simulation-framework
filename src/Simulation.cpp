#include "../include/Simulation.h"

namespace sf {
    Simulation::Simulation(const Window &window, const Uint32 rendererFlags, const Uint32 timeStep) :
            running(true),
            timeStep(timeStep),
            timePassed(SDL_GetTicks()),
            window(window),
            renderer(window, rendererFlags) {}

    const bool Simulation::startFrame() {
        timePassed = SDL_GetTicks();
        return running;
    }

    const bool Simulation::pollEvent() {
        return eventDispatcher.pollEvent(currentEvent);
    }

    void Simulation::waitForNextFrame() {
        // Ideally, we would wait exactly the amount of time needed
        // to still pass until the next frame, however, delays below 10ms are inconsistent.
        // For this reason, a loop is used to not rely on delay timers.
        // An empty loop would increase power draw for handheld devices significantly,
        // so a function call is still used, to slow down the loop.
        while (timePassed + timeStep > SDL_GetTicks()) {
            delay(0);
        }
    }

    void Simulation::delay(const Uint32 milliseconds) {
        SDL_Delay(milliseconds);
    }

    const bool Simulation::isRunning() const {
        return running;
    }

    void Simulation::setRunning(const bool running) {
        this->running = running;
    }
}   // sf
