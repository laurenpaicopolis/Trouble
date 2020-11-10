//
// Created by Michelle on 4/20/2020.
//
#include "Graphics.h"
#include "Square.h"

// Constructors
Square::Square() : red(1.0), green(1.0), blue(1.0), alpha(1.0), xCoord(0.0), yCoord(0.0), dimensions() {
}

Square::Square(double red, double green, double blue, double alpha, double x, double y, vector<int> dimensions) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
    setXCoord(x);
    setYCoord(y);
    setDimensions(dimensions);
}

Square::Square(double red, double green, double blue, double alpha, double x, double y, vector<int> dimensions, int numOnDice) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
    setXCoord(x);
    setYCoord(y);
    setDimensions(dimensions);
    setNumOnDice(numOnDice);
}

// Getters
vector<int> Square::getDimensions() const {
    return dimensions;
}

double Square::getXCoord() const {
    return xCoord;
}

double Square::getYCoord() const {
    return yCoord;
}

int Square::getNumOnDice() const {
    return numOnDice;
}

// Setters
void Square::setDimensions(vector<int> dimensions) {
    this->dimensions = dimensions;
}

void Square::setXCoord(double x) {
    xCoord = x;
}

void Square::setYCoord(double y) {
    yCoord = y;
}

void Square::setNumOnDice(int numOnDice) {
    this->numOnDice = numOnDice;
}

void Square::setColor(double red, double green, double blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

// Overrided draw method from parent class shape.cpp
void Square::draw() const {
    glColor3f(red, green, blue);

    double x = dimensions.at(0);
    double y = dimensions.at(1);
    double xDimension = x / 2.0;
    double yDimension = y / 2.0;

    // Draw square
    glBegin(GL_POLYGON);
    // upper left corner
    glVertex2i(xCoord - xDimension,yCoord - yDimension);
    // upper right corner
    glVertex2i(xCoord + xDimension,yCoord - yDimension);
    // lower right corner
    glVertex2i(xCoord + xDimension, yCoord + yDimension);
    // lower left corner
    glVertex2i(xCoord - xDimension,yCoord + yDimension);

    // End Square
    glEnd();
}
