#ifndef SIMULATION_FRAMEWORK_SIMULATION_H
#define SIMULATION_FRAMEWORK_SIMULATION_H

#include "display/Renderer.h"
#include "event/EventDispatcher.h"

namespace sf {
    /** Represents an abstract simulation and provides structure for it. */
    class Simulation {
    public:
        explicit Simulation(const Window &windowInitializer, const Uint32 rendererFlags, const Uint32 timeStep);
        virtual ~Simulation() = default;

        /** Use this method to implement the main behaviour of your simulation. */
        virtual void run() = 0;

    private:
        bool running;
        /** Represents the minimum amount of milliseconds that should elapse between frames.
         * For a 60fps application, set it to 16.
         */
        const Uint32 timeStep;
        /** Used for correctly calculating the time between each frame. */
        Uint32 timePassed;

    protected:
        Window window;
        Renderer renderer;
        EventDispatcher eventDispatcher;
        Event currentEvent;

        /** Call this method as the simulation's main loop's condition.
         * This is also used to set Simulation::timePassed at the beginning of each frame.
         */
        const bool startFrame();
        void setRunning(const bool running);
        /** This is a propagation from EventDispatches::pollEvent(Event&).
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
         * This doesn't handle what happens, if the frame took longer to process, than timeStep,
         * it only makes sure at least timeStep milliseconds pass.
         */
        void waitForNextFrame();
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_SIMULATION_H
