#include <chrono>
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

    using namespace std::this_thread;
    using namespace std::chrono;
    for (int i = 0; i < 2; ++i) {
        for (int y = 0; y < 2; ++y) {
            for (int x = 0; x < 2; ++x) {
                rect.x = x * 240;
                rect.y = y * 240;
                renderer.setDrawColor(WHITE);
                renderer.clear();
                renderer.setDrawColor(PURPLE);
                renderer.fillRect(rect);
                renderer.present();
                sleep_for(milliseconds(500));
            }
        }
    }
    return 0;
}