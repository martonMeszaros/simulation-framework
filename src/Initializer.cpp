#include "../include/Initializer.h"

namespace sf {
    Initializer::Initializer(const Uint32 subsystems) {
        SDL_Init(subsystems);
    }

    Initializer::~Initializer() {
        SDL_Quit();
    }

    void Initializer::initSubSystem(const Uint32 subsystem) {
        SDL_InitSubSystem(subsystem);
    }

    void Initializer::quitSubSystem(const Uint32 subsystem) {
        SDL_QuitSubSystem(subsystem);
    }
}   // sf
