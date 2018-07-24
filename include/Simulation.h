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
        explicit Simulation(const std::string &windowTitle, const int windowWidth, const int windowHeight,
                                    const Uint32 rendererFlags, const Uint32 timeStep);
        virtual ~Simulation() = default;

        virtual void init();
        virtual void loop() = 0;
        virtual void shutdown();

    private:
        const Uint32 timeStep;
        Uint32 timePassed;
        Initializer initializer;

    protected:
        bool running;
        Window window;
        Renderer renderer;
        EventDispatcher eventDispatcher;
        Event currentEvent;

        void startFrame();
        const bool pollEvent();
        virtual void handleEvents() = 0;
        virtual void process() = 0;
        virtual void render() = 0;
        void waitForNextFrame();
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_SIMULATION_H
