#include "../../include/display/Rect.h"

namespace sf {
    Rect::Rect() : Rect(0, 0, 0, 0) {}

    Rect::Rect(const int x, const int y, const int width, const int height) :
            x(x),
            y(y),
            width(width),
            height(height) {}

    const SDL_Rect &Rect::getRect() {
        rect.x = x;
        rect.y = y;
        rect.w = width;
        rect.h = height;
        return rect;
    }
}   // sf
