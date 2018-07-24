//
// Created by meszi on 2018.07.23..
//

#ifndef SIMULATION_FRAMEWORK_RECT_H
#define SIMULATION_FRAMEWORK_RECT_H

#include <SDL_rect.h>

namespace sf {
    /** Represents a rectangle that has position and size. */
    class Rect {
    public:
        int x;
        int y;
        int width;
        int height;

        Rect();
        Rect(const int x, const int y, const int width, const int height);
        ~Rect() = default;

        /** Return an SDL_Rect version of this Rect */
        const SDL_Rect &getRect();

    private:
        SDL_Rect rect;
    };
}   // sf

#endif //SIMULATION_FRAMEWORK_RECT_H
