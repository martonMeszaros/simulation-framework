//
// Created by meszi on 2018.07.23..
//

#ifndef SIMULATION_FRAMEWORK_SIMULATIONINITIALIZER_H
#define SIMULATION_FRAMEWORK_SIMULATIONINITIALIZER_H

#include <SDL.h>

namespace sf {
    /** Initialize SDL at construction and shutdown at destruction. */
    class Initializer {
    public:
        /** Initialize SDL's provided subsystems.
         *
         * @param subsystems The different subsystems OR'd together.
         */
        explicit Initializer(const Uint32 subsystems = DEFAULT_SUBSYSTEMS);
        ~Initializer();

        void initSubSystem(const Uint32 subsystem);
        void quitSubSystem(const Uint32 subsystem);

    private:
        static const Uint32 DEFAULT_SUBSYSTEMS = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_SIMULATIONINITIALIZER_H
