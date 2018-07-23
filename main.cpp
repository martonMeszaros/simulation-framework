#include <chrono>
#include <thread>

#include "include/sf.h"

int main() {
    using namespace sf;
    Initializer initializer;
    Window window("Hello World!", 480, 480, false);
    const RGBA BLACK(0, 0, 0);
    const RGBA WHITE(255, 255, 255);

    using namespace std::this_thread;
    using namespace std::chrono;
    sleep_for(seconds(1));
    sleep_for(seconds(1));
    return 0;
}