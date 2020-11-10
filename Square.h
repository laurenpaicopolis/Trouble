//
// Created by Michelle on 4/20/2020.
//

#ifndef MW_LP_FINAL_PROJECT_GRAPHICS_SQUARE_H
#define MW_LP_FINAL_PROJECT_GRAPHICS_SQUARE_H

#include "Shape.h"
#include <vector>
#include <string>
using namespace std;

class Square : public Shape {
private:
    vector<int> dimensions;
    double xCoord;
    double yCoord;
    double red;
    double green;
    double blue;
    double alpha;
    int numOnDice;
public:
    // Constructors
    // Requires: Nothing
    // Modifies: all fields
    // Effects: Sets fields to default values
    Square();

    // Requires: red, green, blue, alpha, x, y, dimensions
    // Modifies: red, green, blue, alpha, x, y, dimensions
    // Effects: Sets fields to default values
    Square(double red, double green, double blue, double alpha, double x, double y, vector<int> dimensions);

    // Requires: red, green, blue, alpha, x, y, dimensions, numOnDice
    // Modifies: red, green, blue, alpha, x, y, dimensions, numOnDice
    // Effects: Sets fields to default values
    Square(double red, double green, double blue, double alpha, double x, double y, vector<int> dimensions, int numOnDice);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    vector<int> getDimensions() const;
    double getXCoord() const;
    double getYCoord() const;
    int getNumOnDice() const;

    // Setters
    // Requires: input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setDimensions(vector<int> dimensions);
    void setXCoord(double x);
    void setYCoord(double y);
    void setNumOnDice(int numOnDice);
    void setColor(double red, double green, double blue);

    // Draw square
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: draws square
    void draw() const override;

};


#endif //MW_LP_FINAL_PROJECT_GRAPHICS_SQUARE_H
