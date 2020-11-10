//
// Created by Michelle on 4/13/2020.
//

#ifndef MW_LP_FINAL_PROJECT_GRAPHICS_GAME_H
#define MW_LP_FINAL_PROJECT_GRAPHICS_GAME_H

using namespace std;
#include <iomanip>
#include "Graphics.h"

enum boardShape {circle, square, rectangle};

class Game {
private:
    // Fields
    string gameName;
    int players;
    int score;

protected:
    int spaces;
    boardShape shapeOfBoard;

public:
    // Default Constructor
    // Requires: Nothing
    // Modifies: players, gameName, and score
    // Effects: Sets fields to default values
    Game();

    // Default Constructor
    // Requires: int players and string name
    // Modifies: players, gameName, and score
    // Effects: Assigns the input value to the field, sets score to 0
    Game(int players, string name);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    int getScore() const;
    int getPlayers() const;
    string getName() const;
    int getSpaces() const;
    boardShape getBoardShape() const;

    // Setters
    // Requires: Non-negative input or string
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setScore(int score);
    void setPlayers(int players);
    void setName(string name);
    void setSpaces(int spaces);
    void setBoardShape(boardShape shapeOfBoard);

    // Virtual method board
    // Requires: Non-negative input and boardShape enum
    // Modifies: spaces and shape
    // Effects: Assigns the input value to the field
    virtual void board(int spaces, boardShape shapeOfBoard) = 0;

};
#endif //MW_LP_FINAL_PROJECT_GRAPHICS_GAME_H
