//
// Created by meszi on 2018.07.23..
//

#include "../include/Renderer.h"
#include "../include/Rect.h"

namespace sf {

    Renderer::Renderer(const Window &window) : Renderer(window, 0) {}

    Renderer::Renderer(const Window &window, const Uint32 flags) : renderer(nullptr) {
        // The -1 initializes the first rendering driver that supports the requested flags.
        renderer = SDL_CreateRenderer(window.getWindow(), -1, flags);
        setDrawColor({0, 0, 0});
    }

    Renderer::~Renderer() {
        SDL_DestroyRenderer(renderer);
    }

    void Renderer::clear() {
        SDL_RenderClear(renderer);
    }

    void Renderer::fill() {
        SDL_RenderFillRect(renderer, NULL);
    }

    void Renderer::fillRect(Rect &rect) {
        SDL_RenderFillRect(renderer, &rect.getRect());
    }

    void Renderer::present() {
        SDL_RenderPresent(renderer);
    }

    SDL_Renderer *const Renderer::getRenderer() const {
        return renderer;
    }

    void Renderer::setDrawColor(const RGBA &color) {
        SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
    }
}   // sf
