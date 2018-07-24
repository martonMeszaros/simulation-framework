#include <chrono>
#include <iostream>
#include <thread>

#include "include/sf.h"

int main() {
    using namespace sf;
    Initializer initializer;
    Window window("Hello World!", 480, 480, false);
    Renderer renderer(window, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    const RGBA WHITE(255, 255, 255);
    const RGBA PURPLE(128, 0, 255);
    Rect rect(0, 0, 240, 240);
    EventDispatcher dispatcher;
    Event event;

    bool running = true;
    while (running) {
        // Event handling
        while (dispatcher.pollEvent(event)) {
            if (event.getType() == EventType::QUIT) {
                running = false;
            } else if (event.getType() == EventType::KEYUP) {
                rect.x = (0 == rect.x) ? 240 : 0;
            } else if (event.getType() == EventType::MOUSEBUTTONUP) {
                rect.y = (0 == rect.y) ? 240 : 0;
            }
        }
        // Drawing
        renderer.setDrawColor(WHITE);
        renderer.clear();
        renderer.setDrawColor(PURPLE);
        renderer.fillRect(rect);
        renderer.present();
    }


    return 0;
}