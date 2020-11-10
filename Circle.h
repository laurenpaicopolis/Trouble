//
// Created by Lauren Paicopolis on 4/17/20.
//

#ifndef MW_LP_FINAL_PROJECT_GRAPHICS_CIRCLE_H
#define MW_LP_FINAL_PROJECT_GRAPHICS_CIRCLE_H
#include <math.h> // This allows you to use sqrt and pow functions
#include <string>
#include "Shape.h"

const double PI = 3.14159265358979323846;

class Circle : public Shape {
private:
    double radius;
    double xCoord;
    double yCoord;
    double red;
    double green;
    double blue;
    double alpha;
    int numOnPiece;

public:
    // Constructors
    // Requires: Nothing
    // Modifies: all fields
    // Effects: Sets fields to default values
    Circle();

    // Requires: red, green, blue, alpha, x, y, radius
    // Modifies: red, green, blue, alpha, x, y, radius
    // Effects: Sets fields to default values
    Circle(double red, double green, double blue, double alpha, double x, double y, double radius);

    // Requires: red, green, blue, alpha, x, y, radius, numOnPiece
    // Modifies: red, green, blue, alpha, x, y, radius, numOnPiece
    // Effects: Sets fields to default values
    Circle(double red, double green, double blue, double alpha, double x, double y, double radius, int numOnPiece);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    double getRadius() const;
    double getXCoord() const;
    double getYCoord() const;

    // Setters
    // Requires: double input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setRadius(double r);
    void setXCoord(double x);
    void setYCoord(double y);

    // Requires: double input
    // Modifies: xCoord and yCoord
    // Effects: x and y position
    void moveYCoord(double y);
    void moveXCoord(double x);

    // Requires: Nothing
    // Modifies: Nothing
    // Effects: draws circle
    void draw() const override;

};


#endif //MW_LP_FINAL_PROJECT_GRAPHICS_CIRCLE_H
