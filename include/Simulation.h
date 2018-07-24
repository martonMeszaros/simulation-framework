//
// Created by meszi on 2018.07.24..
//

#ifndef SIMULATION_FRAMEWORK_SIMULATION_H
#define SIMULATION_FRAMEWORK_SIMULATION_H

#include "Initializer.h"
#include "display/Renderer.h"
#include "event/EventDispatcher.h"

namespace sf {
    class Simulation {
    public:
        explicit Simulation(const Window &window, const Renderer &renderer, const Uint32 timeStep);
        explicit Simulation(const Uint32 subsystems, const Window &window, const Renderer &renderer,
                            const Uint32 timeStep);
        ~Simulation() = default;

        virtual void init();
        virtual void loop() = 0;
        virtual void shutdown();

    private:
        Uint32 timePassed;
        const Uint32 timeStep;
        Initializer initializer;

    protected:
        bool running;
        Window window;
        Renderer renderer;
        EventDispatcher eventDispatcher;
        Event currentEvent;

        void startFrame();
        const bool pollEvent();
        virtual void handleEvent() = 0;
        virtual void process() = 0;
        virtual void render() = 0;
        void waitForNextFrame();
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_SIMULATION_H
