#ifndef SIMULATION_FRAMEWORK_RENDERER_H
#define SIMULATION_FRAMEWORK_RENDERER_H

#include "Window.h"
#include "RGBA.h"
#include "Rect.h"

namespace sf {
    /** Create a Renderer to draw to a window. */
    class Renderer {
    public:
        Renderer(const Window &window);
        /** Initialize a Renderer with provided flags.
         * @param flags The different renderer flags OR'd together.
         */
        Renderer(const Window &window, const Uint32 flags);
        ~Renderer();

        /** Clear the renderer with the current draw color. */
        void clear();
        /** Fill the specified area with the current draw color. */
        void fillRect(Rect &rect);
        /** Update screen with any new draw calls. */
        void present();

        /** Get the underlying SDL_Renderer pointer. */
        SDL_Renderer *const getRenderer() const;
        void setDrawColor(const RGBA &color);

    private:
        SDL_Renderer *renderer;
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_RENDERER_H
