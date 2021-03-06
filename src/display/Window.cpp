#include "../../include/display/Window.h"

namespace sf {
    Window::Window(const std::string &title, const int width, const int height) :
            Window(title, width, height, 0) {}

    Window::Window(const std::string &title, const int width, const int height, const Uint32 flags) :
            title(title),
            defaultWidth(width),
            defaultHeight(height),
            window(nullptr) {
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                width, height, flags);
        const Uint32 flagsMask = SDL_GetWindowFlags(window);
        hidden = (SDL_WINDOW_HIDDEN & flagsMask) == flagsMask;
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
