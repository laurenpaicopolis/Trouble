//
// Created by Lauren Paicopolis on 4/20/20.
//

#ifndef MW_LP_FINAL_PROJECT_GRAPHICS_SHAPE_H
#define MW_LP_FINAL_PROJECT_GRAPHICS_SHAPE_H


class Shape {
private:
    double xValue;
    double yValue;
public:
    // Constructors
    // Requires: Nothing
    // Modifies: all fields
    // Effects: Sets fields to default values
    Shape();

    // Requires: x, y
    // Modifies: x, y
    // Effects: Sets fields to default values
    Shape(double x, double y);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    double getXValue() const;
    double getYValue() const;

    // Setters
    // Requires: double input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setYValue(double y);
    void setXValue(double x);

    // Requires: Nothing
    // Modifies: Nothing
    // Effects: draws shape
    virtual void draw() const = 0;
};


#endif //MW_LP_FINAL_PROJECT_GRAPHICS_SHAPE_H
