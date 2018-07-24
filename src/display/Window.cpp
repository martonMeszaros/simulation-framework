//
// Created by meszi on 2018.07.23..
//

#include "../../include/display/Window.h"

namespace sf {
    Window::Window(const std::string &title, const int width, const int height, const bool hidden) :
            title(title),
            defaultWidth(width),
            defaultHeight(height),
            hidden(hidden),
            window(nullptr) {
        // Flag(s) are decided based on whether the window was created as hidden.
        Uint32 flags = hidden ? SDL_WINDOW_HIDDEN : 0;
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                width, height, flags);
    }

    Window::Window(const std::string &title, const int width, const int height,
                   const bool hidden, const Uint32 flags) :
            title(title),
            defaultWidth(width),
            defaultHeight(height),
            hidden(hidden),
            window(nullptr) {
        // If the window was created hidden, OR's the appropriate flag into the others provided.
        // You could also specify the window as shown by default,
        // but provide the hidden flag separately.
        if (hidden) {
            window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                    width, height, flags | SDL_WINDOW_HIDDEN);
        } else {
            window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                    width, height, flags);
        }
    }

    Window::~Window() {
        SDL_DestroyWindow(window);
    }

    void Window::show() {
        hidden = false;
        SDL_ShowWindow(window);
    }

    void Window::hide() {
        hidden = true;
        SDL_HideWindow(window);
    }

    void Window::maximize() {
        SDL_MaximizeWindow(window);
    }

    void Window::minimize() {
        SDL_MinimizeWindow(window);
    }

    void Window::restore() {
        SDL_RestoreWindow(window);
    }

    void Window::restoreSize(const bool centerWindow) {
        SDL_SetWindowSize(window, defaultWidth, defaultHeight);
        if (centerWindow) {
            SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        }
    }

    const std::string &Window::getTitle() const {
        return title;
    }

    int Window::getDefaultWidth() const {
        return defaultWidth;
    }

    int Window::getDefaultHeight() const {
        return defaultHeight;
    }

    bool Window::isHidden() const {
        return hidden;
    }

    SDL_Window *const Window::getWindow() const {
        return window;
    }
}   // sf
