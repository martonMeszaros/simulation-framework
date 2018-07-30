#ifndef SIMULATION_FRAMEWORK_SIMULATION_H
#define SIMULATION_FRAMEWORK_SIMULATION_H

#include "display/Renderer.h"
#include "event/EventDispatcher.h"

namespace sf {
    /** Represents an abstract simulation and provides structure for it. */
    class Simulation {
    public:
        /** Creates the main facilities for a simulation.
         * @param window sf::Window object. Since you need to create it beforehand,
         * you'll also need to create an sf::Initializer object before then.
         * @param rendererFlags Flags to use for the renderer OR'd together.
         * @param timeStep Minimum amount of time to pass between frames.
         */
        explicit Simulation(const Window &window, const Uint32 rendererFlags, const Uint32 timeStep);
        virtual ~Simulation() = default;

        /** Use this method to implement the main behaviour of your simulation. */
        virtual void run() = 0;

    private:
        bool running;
        /** Represents the minimum amount of milliseconds that should elapse between frames.
         * For a 60fps application, set it to 16.
         */
        const Uint32 timeStep;
        /** Used for correctly calculate the time between each frame. */
        Uint32 timePassed;

    protected:
        Window window;
        Renderer renderer;
        EventDispatcher eventDispatcher;
        Event currentEvent;

        /** Call this method as the simulation's main loop's condition.
         * The method is responsible for setting Simulation::timePassed at the beginning of each frame.
         * @return The value of Simulation::running.
         */
        const bool startFrame();
        /** This is a propagation of EventDispatcher::pollEvent(Event&).
         * Does the same, and the polled event will be in Simulation::currentEvent.
         */
        const bool pollEvent();
        /** Use this method to handle events that occur while running the application. */
        virtual void handleEvents() = 0;
        /** Use this method to execute changes to the simulation's state. */
        virtual void update() = 0;
        /** Use this method to organize your render calls in the application. */
        virtual void render() = 0;
        /** Call at the end of each frame to lock the frame rate specified by Simulation::timeStep.
         * This doesn't handle what happens, if the frame took longer to process, than timeStep,
         * it only makes sure at least timeStep milliseconds pass.
         */
        void waitForNextFrame();
        /** Delay execution by the specified amount.
         * Delays below 10 milliseconds are inconsistent.
         */
        void delay(const Uint32 milliseconds);

        const bool isRunning() const;
        void setRunning(const bool running);
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_SIMULATION_H
