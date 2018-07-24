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
        explicit Simulation(const Window &window, const Renderer &renderer);
        explicit Simulation(const Uint32 subsystems, const Window &window, const Renderer &renderer);
        ~Simulation() = default;

        virtual void init();
        virtual void loop() = 0;
        virtual void shutdown();

    private:
        Initializer initializer;

    protected:
        bool running;
        Window window;
        Renderer renderer;
        EventDispatcher eventDispatcher;
        Event currentEvent;

        virtual void process() = 0;
        virtual void render() = 0;
        const bool pollEvent();
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_SIMULATION_H
