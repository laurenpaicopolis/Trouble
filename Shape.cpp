//
// Created by Lauren Paicopolis on 4/20/20.
//

#include "Shape.h"
#include "Graphics.h"
// Constructors
Shape::Shape() {
    xValue = 0;
    xValue = 0;
}

Shape::Shape(double x, double y) {
    xValue = x;
    yValue = y;
}

// Getters
double Shape::getXValue() const {
    return xValue;
}

double Shape::getYValue() const {
    return yValue;
}

// Setters
void Shape::setXValue(double x) {
    xValue = x;
}

void Shape::setYValue(double y) {
    yValue = y;
}


