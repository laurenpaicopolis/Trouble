//
// Created by Michelle on 4/13/2020.
//

#ifndef MW_LP_FINAL_PROJECT_GRAPHICS_TROUBLE_H
#define MW_LP_FINAL_PROJECT_GRAPHICS_TROUBLE_H

#include "Game.h"
#include "Team.h"
#include "Graphics.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Trouble : public Game {
private:
    // Fields
    vector<pieces> team1Pieces;
    vector<pieces> team2Pieces;
    vector<pieces> team3Pieces;
    vector<pieces> team4Pieces;
    vector<vector<pieces>> allTeams;
    Team teamBlue;
    Team teamGreen;
    Team teamRed;
    Team teamYellow;

    bool winner;
    int numOfDie;
    int numOfPieces;
    int numRolled;
    int userTeam;
    bool alreadySelected = false;
    int opponentMoved;
    int opponentTeam;
    bool pieceCollided = false;
    bool finishTime = false;
    int originalPosition;
    pieces CPUPiece;
    int indexPieceToBeMoved;

public:
    // Constructors
    // Requires: Nothing
    // Modifies: winner, numOfDie, numOfPieces
    // Effects: Sets fields to default values
    Trouble();

    // Requires: numOfDie, numOfPieces
    // Modifies: numOfDie, numOfPieces
    // Effects: Sets fields to default values
    Trouble(int numOfDie, int numOfPieces);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    bool getWinner() const;
    int getDie() const;
    int getPieces() const;
    int getDieRolled() const;
    int getUserTeam() const;
    int getOpponentMoved() const;
    int getOpponentTeam() const;
    bool getPieceCollided() const;
    int getIndexPieceToBeMoved() const;
    vector<pieces> &getTeamOnePieces();
    vector<pieces> &getTeamTwoPieces();
    vector<pieces> &getTeamThreePieces();
    vector<pieces> &getTeamFourPieces();
    vector<vector<pieces>> &getAllTeams();
    pieces &getCPUPiece();

    // Setters
    // Requires: Non-negative input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setWinner(bool winner);
    void setDie(int numOfDie);
    void setPieces(int numOfPieces);
    void setCPUPiece(pieces CPUpiece);
    void setIndexPieceToBeMoved(int indexPieceToBeMoved);
    void setUserTeam(int teamSelected);

    // Functions
    // Requires: Nothing
    // Modifies: numRolled
    // Effects: Returns the number rolled
    int rollDie();

    // Requires: Nothing
    // Modifies: gets vector of pieces for each team
    // Effects: Nothing
    void createTeams();

    // Requires: teamNumber, keyNumber
    // Modifies: Nothing
    // Effects: which piece is selected
    bool pickPiece(int teamNumber, int keyNumber);

    // Requires: Team object
    // Modifies: Nothing
    // Effects: CPU plays against player, rolls dice and randomly selects piece to be moved of opponent
    bool CPUtime(int CPUTeam);

    // Requires: vector of the team, piece to be moved
    // Modifies: Nothing
    // Effects: determines if piece selected to be moved is a legal move
    bool ruleBreaker(vector<pieces> &team, pieces &pieceToBeMoved, int teamNumber);

    // Requires: pieceToBeMoved and teamNumber
    // Modifies: pieceCollided
    // Effects: determines if piece collided with another piece
    void determineIfPiecesCollide(pieces &pieceToBeMoved, int teamNumber);

    // Virtual method board
    // Requires: spaces and shapeOfBoard
    // Modifies: spaces and shapeOfBoard
    // Effects: Assigns the input value to the field
    virtual void board(int spaces, boardShape shapeOfBoard) override;
};

#endif //MW_LP_FINAL_PROJECT_GRAPHICS_TROUBLE_H
