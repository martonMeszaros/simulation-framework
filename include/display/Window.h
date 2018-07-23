//
// Created by meszi on 2018.07.23..
//

#ifndef SIMULATION_FRAMEWORK_WINDOW_H
#define SIMULATION_FRAMEWORK_WINDOW_H

#include <string>
#include <SDL.h>

namespace sf {
    /** Create a window. */
    class Window {
    public:
        explicit Window(const std::string &title, const int width, const int height, const bool hidden);
        /** Initialize a Window with provided flags.
         *
         * @param flags The different window flags OR'd together.
         */
        explicit Window(const std::string &title, const int width, const int height,
               const bool hidden, const Uint32 flags);
        ~Window();

        void show();
        void hide();
        void maximize();
        void minimize();
        /** Restore the window after it has been minimized or maximized. */
        void restore();
        /** Restore the window's size to it's original value.
         *
         * @param centerWindow Whether to position the resized window in the center.
         */
        void restoreSize(const bool centerWindow);

        const std::string &getTitle() const;
        int getDefaultWidth() const;
        int getDefaultHeight() const;
        bool isHidden() const;
        /** Get the underlying SDL_Window pointer. */
        SDL_Window *const getWindow() const;

    private:
        std::string title;
        int defaultWidth;
        int defaultHeight;
        bool hidden;
        SDL_Window *window;

    };
}   // sf

#endif //SIMULATION_FRAMEWORK_WINDOW_H
