//
// Created by Michelle on 4/13/2020.
//

#ifndef MW_LP_FINAL_PROJECT_GRAPHICS_TEAM_H
#define MW_LP_FINAL_PROJECT_GRAPHICS_TEAM_H

#include <iostream>
#include <vector>
#include "Graphics.h"
using namespace std;

enum colors {Blue, Green, Red, Yellow};

struct pieces {
    int teamNum;
    int positionOnBoard;
    int pieceID;
    colors colorOfPiece;
    bool home;
    bool finish;
    bool tried;
    bool firstTimeOut;
    bool aroundOnce;
    bool timeToGoHome;
};

class Team {
private:
    // Fields
    int teamNumber;
    int numOfTeamPieces;
    colors color;
    vector<pieces> piecesOfTheGame;

public:
    // Default Constructor
    // Requires: Nothing
    // Modifies: teamNumber, numOfTeamPieces
    // Effects: Sets fields to default values
    Team();

    // Constructor
    // Requires: teamNumber, numOfTeamPieces
    // Modifies: teamNumber, numOfTeamPieces
    // Effects: Sets fields to default values
    Team(int teamNumber, int numOfTeamPieces, colors color);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    int getTeamNumber() const;
    int getNumOfTeamPieces() const;
    vector<pieces> getTeamPieces() const;
    colors getColor() const;

    // Setters
    // Requires: Non-negative input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setTeamNumber(int teamNumber);
    void setNumOfTeamPieces(int numOfTeamPieces);
    void setColor(colors color);

    // Functions
    // Requires: Nothing
    // Modifies: sets fields for each piece
    // Effects: Returns the vector of pieces
    vector<pieces> addPiecesTeamOne();
    vector<pieces> addPiecesTeamTwo();
    vector<pieces> addPiecesTeamThree();
    vector<pieces> addPiecesTeamFour();
};

#endif //MW_LP_FINAL_PROJECT_GRAPHICS_TEAM_H
