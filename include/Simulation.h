//
// Created by meszi on 2018.07.24..
//

#ifndef SIMULATION_FRAMEWORK_SIMULATION_H
#define SIMULATION_FRAMEWORK_SIMULATION_H

#include "Initializer.h"
#include "display/Renderer.h"
#include "event/EventDispatcher.h"

namespace sf {
    /** Represents an abstract simulation and provides structure for it. */
    class Simulation {
    public:
        explicit Simulation(const std::string &windowTitle, const int windowWidth, const int windowHeight,
                                    const Uint32 rendererFlags, const Uint32 timeStep);
        virtual ~Simulation() = default;

        /** Should be called before Simulation::loop(), if you need some setup,
         * that cannot be done in the constructor.
         */
        virtual void init();
        /** Use this method to implement the main behaviour of your simulation. */
        virtual void loop() = 0;
        /** Should be called after Simulation::loop(), if you need some breakdown,
         * that cannot be done in the destructor.
         */
        virtual void shutdown();

    private:
        /** Represents the minimum amount of milliseconds that should elapse between frames.
         *
         * For a 60fps application, set it to 16.
         */
        const Uint32 timeStep;
        /** Used for correctly calculating the time between each frame. */
        Uint32 timePassed;
        Initializer initializer;

    protected:
        /** Represents whether the application is running, or should be terminated.
         *
         * Should not be confused with any kind of paused state.
         */
        bool running;
        Window window;
        Renderer renderer;
        EventDispatcher eventDispatcher;
        Event currentEvent;

        /** Call at the beginning of each frame to correctly handle frame rate. */
        void startFrame();
        /** This is a propagation from EventDispatches::pollEvent(Event&).
         *
         * Does the same, but only on the provided Simulation::currentEvent object.
         */
        const bool pollEvent();
        /** Use this method to handle events that occur while running the application. */
        virtual void handleEvents() = 0;
        /** Use this method to execute changes to the simulation's state. */
        virtual void process() = 0;
        /** Use this method to organize your render calls in the application. */
        virtual void render() = 0;
        /** Call at the end of each frame to lock the frame rate specified by Simulation::timeStep.
         *
         * This doesn't handle what happens, if the frame took longer to process, than timeStep,
         * it only makes sure at least timeStep milliseconds pass.
         */
        void waitForNextFrame();
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_SIMULATION_H
