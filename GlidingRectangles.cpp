//
// Created by meszi on 2018.07.24..
//

#include "GlidingRectangles.h"
#include "include/event/EventType.h"

GlidingRectangles::GlidingRectangles(const std::string &windowTitle, const int windowWidth, const int windowHeight,
                                     const Uint32 rendererFlags, const Uint32 timeStep) :
        Simulation(windowTitle, windowWidth, windowHeight, rendererFlags, timeStep),
        WHITE(255, 255, 255),
        PURPLE(128, 0, 255),
        BLUE(32, 32, 255),
        RECT_WIDTH(window.getDefaultWidth() / 2),
        RECT_HEIGHT(window.getDefaultHeight() / 2),
        velocity(5),
        blueRect(0, 0, RECT_WIDTH, RECT_HEIGHT),
        purpleRect(window.getDefaultWidth() / 2, 0, RECT_WIDTH, RECT_HEIGHT) {}

GlidingRectangles::~GlidingRectangles() {

}

void GlidingRectangles::loop() {
    while (running) {
        startFrame();
        handleEvents();
        process();
        render();
        waitForNextFrame();
    }
}

void GlidingRectangles::handleEvents() {
    while(pollEvent()) {
        if (currentEvent.getType() == EventType::QUIT) {
            running = false;
        }
        if (currentEvent.getType() == EventType::KEYDOWN) {
            if (SDLK_SPACE == currentEvent.getEvent().key.keysym.sym) {
                velocity += 1;
            } else if (SDLK_BACKSPACE == currentEvent.getEvent().key.keysym.sym) {
                velocity -= 1;
            }
        }
    }
}

void GlidingRectangles::process() {
    blueRect.x += velocity;
    blueRect.y += velocity;
    purpleRect.x -= velocity;
    purpleRect.y += velocity;
    if (blueRect.y > window.getDefaultHeight()) {
        blueRect.y = -blueRect.height;
        blueRect.x = -blueRect.width;
    }
    if (purpleRect.y > window.getDefaultHeight()) {
        purpleRect.y = -blueRect.height;
        purpleRect.x = window.getDefaultWidth();
    }
}

void GlidingRectangles::render() {
    renderer.setDrawColor(WHITE);
    renderer.clear();
    renderer.setDrawColor(BLUE);
    renderer.fillRect(blueRect);
    renderer.setDrawColor(PURPLE);
    renderer.fillRect(purpleRect);
    renderer.present();
}
