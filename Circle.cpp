//
// Created by Lauren Paicopolis on 4/17/20.
//

#include "Circle.h"
#include "Graphics.h"
#include <string>
using namespace std;

Circle::Circle() : red(1.0), green(1.0), blue(1.0), alpha(1.0), xCoord(0.0), yCoord(0.0), radius(1.0) {
}

Circle::Circle(double red, double green, double blue, double alpha, double x, double y, double radius) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
    setRadius(radius);
    setXCoord(x);
    setYCoord(y);
}

Circle::Circle(double red, double green, double blue, double alpha, double x, double y, double radius, int numOnPiece) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
    setRadius(radius);
    setXCoord(x);
    setYCoord(y);
    this->numOnPiece = numOnPiece;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getXCoord() const{
    return xCoord;
}

double Circle::getYCoord() const{
    return yCoord;
}

void Circle::setRadius(double r) {
    if (r < 0) {
        r = 0;
    }
    radius = r;
}

void Circle::setXCoord(double x) {
    xCoord = x;
}

void Circle::setYCoord(double y) {
    yCoord = y;
}

void Circle::moveYCoord(double y) {
    yCoord += y;
}

void Circle::moveXCoord(double x) {
    xCoord += x;
}

void Circle::draw() const {
    glColor3f(red, green, blue);
    // Draw circle as Triangle Fan
    glBegin(GL_TRIANGLE_FAN);
    // Draw center point
    glVertex2i(xCoord, yCoord);
    // Draw points on edge of circle
    for (double i = 0; i < 2.0*PI+0.05; i += (2.0*PI)/360.0) {
        glVertex2i(xCoord + (radius * cos(i)),
                   yCoord + (radius * sin(i)));
    }

    // End Triangle Fan
    glEnd();

    // add numbers to pieces
    if(numOnPiece == 1 || numOnPiece == 2 || numOnPiece == 3 || numOnPiece == 4) {
        glColor3f(0, 0, 0);
        string num = to_string(numOnPiece);
        char pieceMove[1];
        pieceMove[0] = num[0];
        glRasterPos2i(xCoord - 5, yCoord + 5);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, pieceMove[0]);
    }
}

