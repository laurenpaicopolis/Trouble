//
// Created by Michelle on 4/21/2020.
//

#ifndef MW_LP_FINAL_PROJECT_GRAPHICS_OCTAGON_H
#define MW_LP_FINAL_PROJECT_GRAPHICS_OCTAGON_H

#include "Shape.h"
#include <vector>
using namespace std;

class Octagon : public Shape {
private:
    vector<int> dimensions;
    double xCoord;
    double yCoord;
    double red;
    double green;
    double blue;
    double alpha;
public:
    // Constructors
    // Requires: Nothing
    // Modifies: all fields
    // Effects: Sets fields to default values
    Octagon();

    // Requires: red, green, blue, alpha, x, y, dimensions
    // Modifies: red, green, blue, alpha, x, y, dimensions
    // Effects: Sets fields to default values
    Octagon(double red, double green, double blue, double alpha, double x, double y, vector<int> dimensions);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    vector<int> getDimensions() const;
    double getXCoord() const;
    double getYCoord() const;

    // Setters
    // Requires: input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setDimensions(vector<int> dimensions);
    void setXCoord(double x);
    void setYCoord(double y);

    // Draw octagon
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: draws octagon
    void draw() const override;

};

#endif //MW_LP_FINAL_PROJECT_GRAPHICS_OCTAGON_H
