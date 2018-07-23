#include <chrono>
#include <thread>

#include "include/sf.h"

int main() {
    using namespace sf;
    Initializer initializer;
    Window window("Hello World!", 480, 480, false);
    Renderer renderer(window, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    const RGBA PURPLE(255, 0, 255);
    const RGBA WHITE(255, 255, 255);
    const Rect rect(0, 0, 100, 215);
    renderer.fill();
    renderer.present();

    using namespace std::this_thread;
    using namespace std::chrono;
    sleep_for(seconds(1));
    renderer.setDrawColor(WHITE);
    renderer.fill();
    renderer.present();
    sleep_for(seconds(1));
    return 0;
}