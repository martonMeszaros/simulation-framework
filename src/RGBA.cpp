//
// Created by meszi on 2018.07.23..
//

#include "../include/RGBA.h"

namespace sf {
    RGBA::RGBA(const Uint8 red, const Uint8 green, const Uint8 blue) :
            RGBA(red, green, blue, 255) {}

    RGBA::RGBA(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha) :
            red(red),
            green(green),
            blue(blue),
            alpha(alpha) {}
}   // sf
