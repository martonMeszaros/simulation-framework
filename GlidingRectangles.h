//
// Created by meszi on 2018.07.24..
//

#ifndef SIMULATION_FRAMEWORK_GLIDINGRECTANGLES_H
#define SIMULATION_FRAMEWORK_GLIDINGRECTANGLES_H

#include "include/Simulation.h"

using namespace sf;

class GlidingRectangles : public Simulation {
public:
    explicit GlidingRectangles(const std::string &windowTitle, const int windowWidth, const int windowHeight,
                                   const Uint32 rendererFlags, const Uint32 timeStep);
    ~GlidingRectangles() override;
    void loop() override;

protected:
    void process() override;
    void handleEvents() override;
    void render() override;

private:
    const RGBA WHITE;
    const RGBA PURPLE;
    const RGBA BLUE;
    const int RECT_WIDTH;
    const int RECT_HEIGHT;
    Rect purpleRect;
    Rect blueRect;
    int velocity;
};


#endif //SIMULATION_FRAMEWORK_GLIDINGRECTANGLES_H
