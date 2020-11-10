//
// Created by Michelle on 4/21/2020.
//

#include "Graphics.h"
#include "Octagon.h"

// Constructors
Octagon::Octagon() : red(1.0), green(1.0), blue(1.0), alpha(1.0), xCoord(0.0), yCoord(0.0), dimensions() {
}

Octagon::Octagon(double red, double green, double blue, double alpha, double x, double y, vector<int> dimensions) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
    setXCoord(x);
    setYCoord(y);
    setDimensions(dimensions);
}

// Getters
vector<int> Octagon::getDimensions() const {
    return dimensions;
}

double Octagon::getXCoord() const{
    return xCoord;
}

double Octagon::getYCoord() const{
    return yCoord;
}

// Setters
void Octagon::setDimensions(vector<int> dimensions) {
    this->dimensions = dimensions;
}

void Octagon::setXCoord(double x) {
    xCoord = x;
}

void Octagon::setYCoord(double y) {
    yCoord = y;
}

// Overrided draw method from parent class shape.cpp
void Octagon::draw() const {
    glColor3f(red, green, blue);

    // get the x dimension
    double x = dimensions.at(0);
    // get the y dimension
    double y = dimensions.at(1);
    double xDimension = x / 2.0;
    double yDimension = y / 2.0;
    // create two variables that will scale the x and y values
    double xScale = (1.0/4)*(x);
    double yScale = (1.0/4)*(y);

    // Draw octagon
    glBegin(GL_POLYGON);
    // upper left corner point 1
    glVertex2i(xCoord - xDimension,(yCoord - yDimension) + yScale);
    // upper left corner point 2
    glVertex2i((xCoord - xDimension) + xScale,yCoord - yDimension);

    // upper right corner point 1
    glVertex2i((xCoord + xDimension) - xScale,yCoord - yDimension);
    // upper right corner point 2
    glVertex2i(xCoord + xDimension,(yCoord - yDimension) + yScale);

    // lower right corner point 1
    glVertex2i(xCoord + xDimension, (yCoord + yDimension) - yScale);
    // lower right corner point 2
    glVertex2i((xCoord + xDimension) - xScale, yCoord + yDimension);

    // lower left corner point 1
    glVertex2i((xCoord - xDimension) + xScale ,yCoord + yDimension);
    // lower left corner point 2
    glVertex2i(xCoord - xDimension,(yCoord + yDimension) - yScale);

    // End Octagon
    glEnd();
}
