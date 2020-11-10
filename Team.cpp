//
// Created by Michelle on 4/13/2020.
//

#include <iostream>
#include "Team.h"

using namespace std;

// Constructors
Team::Team() : teamNumber(1), numOfTeamPieces(4), color(Blue) {
}

Team::Team(int teamNumber, int numOfTeamPieces, colors color) {
    this->teamNumber = (teamNumber < 0) ? 0 : teamNumber;
    this->numOfTeamPieces = (numOfTeamPieces < 0) ? 0 : numOfTeamPieces;
    this->color = color;
}

// Getters
int Team::getTeamNumber() const {
    return teamNumber;
}

int Team::getNumOfTeamPieces() const {
    return numOfTeamPieces;
}

colors Team::getColor() const {
    return color;
}

vector<pieces> Team::getTeamPieces() const {
    return piecesOfTheGame;
}

// Setters
void Team::setTeamNumber(int teamNumber) {
    this->teamNumber = (teamNumber < 0) ? 0 : teamNumber;
}

void Team::setNumOfTeamPieces(int numOfTeamPieces) {
    this->numOfTeamPieces = (numOfTeamPieces < 0) ? 0 : numOfTeamPieces;
}

void Team::setColor(colors color) {
    this->color = color;
}

/***** Create Different Team Pieces ******/
vector<pieces> Team::addPiecesTeamOne() {
    for (int i = 0; i < numOfTeamPieces; ++i) {
        // Set team one's home spots, color, etc
        pieces piece;
        piece.positionOnBoard = 4;
        piece.teamNum = teamNumber;
        piece.pieceID = i + 1;
        piece.colorOfPiece = Red;
        piece.home = true;
        piece.finish = false;
        piece.tried = false;
        piece.firstTimeOut = false;
        piece.aroundOnce = false;
        piece.timeToGoHome = false;

        // add piece to team one vector
        piecesOfTheGame.push_back(piece);
    }
    return piecesOfTheGame;
}

vector<pieces> Team::addPiecesTeamTwo() {
    for (int i = 0; i < numOfTeamPieces; ++i) {
        // Set team two's home spots, color, etc
        pieces piece;
        piece.positionOnBoard = 10;
        piece.teamNum = teamNumber;
        piece.pieceID = i + 1;
        piece.colorOfPiece = Green;
        piece.home = true;
        piece.finish = false;
        piece.tried = false;
        piece.firstTimeOut = false;
        piece.aroundOnce = false;
        piece.timeToGoHome = false;

        // add piece to team two vector
        piecesOfTheGame.push_back(piece);
    }
    return piecesOfTheGame;
}

vector<pieces> Team::addPiecesTeamThree() {
    for (int i = 0; i < numOfTeamPieces; ++i) {
        // Set team three's home spots, color, etc
        pieces piece;
        piece.positionOnBoard = 18;
        piece.teamNum = teamNumber;
        piece.pieceID = i + 1;
        piece.colorOfPiece = Yellow;
        piece.home = true;
        piece.finish = false;
        piece.tried = false;
        piece.firstTimeOut = false;
        piece.aroundOnce = false;
        piece.timeToGoHome = false;

        // add piece to team three vector
        piecesOfTheGame.push_back(piece);
    }
    return piecesOfTheGame;
}

vector<pieces> Team::addPiecesTeamFour() {
    for (int i = 0; i < numOfTeamPieces; ++i) {
        // Set team four's home spots, color, etc
        pieces piece;
        piece.positionOnBoard = 24;
        piece.teamNum = teamNumber;
        piece.pieceID = i + 1;
        piece.colorOfPiece = Blue;
        piece.home = true;
        piece.finish = false;
        piece.tried = false;
        piece.firstTimeOut = false;
        piece.aroundOnce = false;
        piece.timeToGoHome = false;

        // add piece to team four vector
        piecesOfTheGame.push_back(piece);
    }
    return piecesOfTheGame;
}