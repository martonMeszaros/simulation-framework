//
// Created by meszi on 2018.07.23..
//

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
        Renderer(const Window &window, const Uint32 flags);
        ~Renderer();

        void clear();
        void fill();
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
