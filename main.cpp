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

//    using namespace std::this_thread;
//    using namespace std::chrono;

    return 0;
}