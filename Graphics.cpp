//
// Created by Michelle on 4/17/2020.
//

#include "Game.h"
#include "Trouble.h"
#include "Team.h"
#include "Circle.h"
#include "Graphics.h"
#include "Shape.h"
#include "Square.h"
#include "Octagon.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <memory>
#include <string>

using namespace std;

// vectors holding spots on the board, pieces, and other shapes
vector<unique_ptr<Circle>> spotsOnBoard;
vector<unique_ptr<Circle>> teamOne;
vector<unique_ptr<Circle>> teamTwo;
vector<unique_ptr<Circle>> teamThree;
vector<unique_ptr<Circle>> teamFour;
vector<unique_ptr<Circle>> teamOneHome;
vector<unique_ptr<Circle>> teamTwoHome;
vector<unique_ptr<Circle>> teamThreeHome;
vector<unique_ptr<Circle>> teamFourHome;
vector<unique_ptr<Circle>> teamOneFinish;
vector<unique_ptr<Circle>> teamTwoFinish;
vector<unique_ptr<Circle>> teamThreeFinish;
vector<unique_ptr<Circle>> teamFourFinish;
vector<unique_ptr<Shape>> shapesOnTheBoard;
Trouble trouble(1,16);

// white dice
vector<int> d2 = {40, 40};
Square dice(1.0, 1.0, 1.0, 1.0, 350, 350, d2, trouble.rollDie());

// declared booleans
bool valid = true;
bool teamSelected = false;
bool collided = false;
bool userTime = true;
bool keyPressed = false;
bool start = false;
bool CPU = false;
bool CPUCorrectPiece = false;
bool userTurn = false;
bool CPURollsASix = false;
bool userRollsASix = false;
bool beginGame = true;
bool CPUTurn = false;
bool changeMessage = false;
bool rolledASixAgain = false;
bool diceRolled = false;
bool moved = false;
bool userMovePiece = true;
bool turnDone = false;
bool CPUMoved = false;

// declared variables
int opponentPiece = 0;
int opponentTeam = 0;
int keyNum = 1;
int wd;
int userTeam = 1;
int CPUTeam;

// used to determine which team's turn it is
int teamNumTurn = 1;
vector<int> listOfTeamNums = {1, 2, 3, 4};

void drawCircles() {

    /****** Circles for Board *******/
    // upper left corner of circle
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,100,320,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,115,270,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,135,225,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,165,180,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,210,140,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,260,115,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,320,100,20));

    // upper left finish spots
    teamOneFinish.push_back(make_unique<Circle>(0,0,0,1,213,192,20));
    teamOneFinish.push_back(make_unique<Circle>(0,0,0,1,244,228,20));
    teamOneFinish.push_back(make_unique<Circle>(0,0,0,1,277,262,20));
    teamOneFinish.push_back(make_unique<Circle>(0,0,0,1,307,297,20));

    // upper left home spots
    teamOneHome.push_back(make_unique<Circle>(0,0,0,1,70,70,20));
    teamOneHome.push_back(make_unique<Circle>(0,0,0,1,115,115,20));
    teamOneHome.push_back(make_unique<Circle>(0,0,0,1,170,80,20));
    teamOneHome.push_back(make_unique<Circle>(0,0,0,1,80,170,20));

    // Team One Pieces
    teamOne.push_back(make_unique<Circle>(1,0,0,1,70,70,20, 1));
    teamOne.push_back(make_unique<Circle>(1,0,0,1,115,115,20, 2));
    teamOne.push_back(make_unique<Circle>(1,0,0,1,170,80,20,3));
    teamOne.push_back(make_unique<Circle>(1,0,0,1,80,170,20, 4));

    // upper right corner of circle
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,380,100,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,440,115,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,490,140,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,535,180,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,565,225,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,585,270,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,600,320,20));

    // upper right home spots
    teamTwoHome.push_back(make_unique<Circle>(0,0,0,1,630,70,20));
    teamTwoHome.push_back(make_unique<Circle>(0,0,0,1,585,115,20));
    teamTwoHome.push_back(make_unique<Circle>(0,0,0,1,530,80,20));
    teamTwoHome.push_back(make_unique<Circle>(0,0,0,1,620,170,20));

    // Team Two Pieces
    teamTwo.push_back(make_unique<Circle>(0,1,0,1,630,70,20, 1));
    teamTwo.push_back(make_unique<Circle>(0,1,0,1,585,115,20, 2));
    teamTwo.push_back(make_unique<Circle>(0,1,0,1,530,80,20, 3));
    teamTwo.push_back(make_unique<Circle>(0,1,0,1,620,170,20, 4));

    // upper right finish spots
    teamTwoFinish.push_back(make_unique<Circle>(0,0,0,1,487,193,20));
    teamTwoFinish.push_back(make_unique<Circle>(0,0,0,1,457,228,20));
    teamTwoFinish.push_back(make_unique<Circle>(0,0,0,1,427,263,20));
    teamTwoFinish.push_back(make_unique<Circle>(0,0,0,1,397,298,20));

    // lower right corner of circle
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,600,380,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,585,430,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,565,475,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,535,520,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,490,560,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,440,585,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,380,600,20));

    // lower right finish spots
    teamThreeFinish.push_back(make_unique<Circle>(0,0,0,1,487,507,20));
    teamThreeFinish.push_back(make_unique<Circle>(0,0,0,1,457,472,20));
    teamThreeFinish.push_back(make_unique<Circle>(0,0,0,1,427,437,20));
    teamThreeFinish.push_back(make_unique<Circle>(0,0,0,1,397,402,20));

    // lower right home spots
    teamThreeHome.push_back(make_unique<Circle>(0,0,0,1,630,630,20));
    teamThreeHome.push_back(make_unique<Circle>(0,0,0,1,585,585,20));
    teamThreeHome.push_back(make_unique<Circle>(0,0,0,1,530,620,20));
    teamThreeHome.push_back(make_unique<Circle>(0,0,0,1,620,530,20));

    // Team Three Pieces
    teamThree.push_back(make_unique<Circle>(1, 1, 0,1,630,630,20, 1));
    teamThree.push_back(make_unique<Circle>(1, 1, 0,1,585,585,20, 2));
    teamThree.push_back(make_unique<Circle>(1, 1, 0,1,530,620,20, 3));
    teamThree.push_back(make_unique<Circle>(1, 1, 0,1,620,530,20, 4));

    // lower left corner of circle
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,320,600,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,260,585,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,210,560,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,165,520,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,135,475,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,115,430,20));
    spotsOnBoard.push_back(make_unique<Circle>(0,0,0,1,100,380,20));

    // lower left finish spots
    teamFourFinish.push_back(make_unique<Circle>(0,0,0,1,210,505,20));
    teamFourFinish.push_back(make_unique<Circle>(0,0,0,1,240,470,20));
    teamFourFinish.push_back(make_unique<Circle>(0,0,0,1,270,435,20));
    teamFourFinish.push_back(make_unique<Circle>(0,0,0,1,300,400,20));

    // lower left home spots
    teamFourHome.push_back(make_unique<Circle>(0,0,0,1,70,630,20));
    teamFourHome.push_back(make_unique<Circle>(0,0,0,1,115,585,20));
    teamFourHome.push_back(make_unique<Circle>(0,0,0,1,170,620,20));
    teamFourHome.push_back(make_unique<Circle>(0,0,0,1,80,530,20));

    // Team Four Pieces
    teamFour.push_back(make_unique<Circle>(0, 0, 1,1,70,630,20, 1));
    teamFour.push_back(make_unique<Circle>(0, 0, 1,1,115,585,20, 2));
    teamFour.push_back(make_unique<Circle>(0, 0, 1,1,170,620,20, 3));
    teamFour.push_back(make_unique<Circle>(0, 0, 1,1,80,530,20, 4));


    // Add other shapes to the board
    vector<int> d = {350, 350};
    // red corner
    shapesOnTheBoard.push_back(make_unique<Square>(240.0/250, 156.0/250, 156.0/250, 1.0, 175, 175, d));
    // green corner
    shapesOnTheBoard.push_back(make_unique<Square>(172.0/250,242.0/250,184.0/250, 1.0, 525, 175, d));
    // yellow corner
    shapesOnTheBoard.push_back(make_unique<Square>(246.0/250, 252.0/250, 192.0/250, 1.0, 525, 525, d));
    // blue corner
    shapesOnTheBoard.push_back(make_unique<Square>(172.0/250,214.0/250,242.0/250, 1.0, 175, 525, d));
    // octagon in center
    vector<int> octagonDim = {90, 90};
    shapesOnTheBoard.push_back(make_unique<Octagon>(145.0/250, 149.0/250, 156.0/250, 1.0, 350, 350, octagonDim));
    // center circle where dice is
    shapesOnTheBoard.push_back(make_unique<Circle>(0,0,0,1,350,350,40));
}

void timeToPlay(int teamNum) {
    // team 1 will go first, and then will go through each team's turn

    // Determine if it is the user's turn
    if (listOfTeamNums[teamNum - 1] == teamNumTurn && teamNumTurn == userTeam) {
        cout << "Team turn: " << teamNumTurn << endl;
        teamTurn(teamNumTurn);

        // if the user rolls a 6, then they get to roll again
        if (trouble.getDieRolled() == 6) {
            userTime = true;
            userRollsASix = true;
        }

        // otherwise, it is the CPU's turn
        else if (!rolledASixAgain) {
            userRollsASix = false;
            userTurn = false;
            CPUTurn = true;
        }
    }
    else {
        // CPU's turn
        cout << "Team turn: " << teamNumTurn << endl;
        teamTurn(teamNumTurn);

        // if the die rolled is a 6, repeat turn
        if (trouble.getDieRolled() == 6) {
            CPURollsASix = true;
            CPU = true;
        }
        // otherwise it is the next team's turn
        else {
            CPURollsASix = false;
            CPUTurn = false;
        }
    }

    // if the team number is 4, then reset back to 0
    if (teamNumTurn == 4 && !CPURollsASix && !userRollsASix) {
        teamNumTurn = 0;
    }

    // Go to the next team if the roll is not a 6
    if (trouble.getDieRolled() != 6) {
        ++teamNumTurn;
        CPUTurn = true;
        CPU = true;
        userTime = false;
        userTurn = false;
    }

    // If it is the user's turn, reset all booleans
    if (teamNumTurn == userTeam) {
        userTurn = true;
        userTime = true;
        CPUTurn = false;
        CPU = false;
        keyPressed = false;
    }

}

// Calls to Trouble to determine if piece is valid move
void teamTurn(int teamNumTurn) {
    // determine if it is the user's turn
    if (userTeam == teamNumTurn) {
        // user rolls
        userTime = true;
        CPUTurn = false;
        CPU = false;
    }
    // otherwise it is the CPU's turn
    else {
        CPU = true;
        CPUTurn = true;
        userTime = false;
    }

    // CPU time/turn
    if (CPU && !CPUMoved) {
        CPUCorrectPiece = false;
        CPUTeam = teamNumTurn;
        cout << "CPU team num: " << CPUTeam << endl;
        cout << "CPU Time!" << endl;
        // get the team whose turn it is
        CPUCorrectPiece = trouble.CPUtime(CPUTeam);

        // if the CPU piece moved collided with another piece, get the opponent team/piece collided with
        if (trouble.getPieceCollided()) {
            collided = true;
            opponentPiece = trouble.getOpponentMoved();
            opponentTeam = trouble.getOpponentTeam();
        }
        else
            collided = false;

        // If the CPU made a valid move and piece was moved, move piece on board
        if (CPUCorrectPiece) {
            turnDone = false;
            movePieces();
        }

        // CPU's dice rolled
        cout << "CPU dice: " << trouble.getDieRolled() << endl;
        CPU = false;
        CPUTurn = false;
        CPUMoved = true;
    }

    // Turn is done, redisplay board
    glutPostRedisplay();
}


void init() {
    // Draw the circles/spots on the board
    drawCircles();
    // create teams
    trouble.createTeams();
}

void movePieces() {
    // Move pieces on game board for user if their team is 1
    if (userTeam == 1 && keyPressed && !CPU && diceRolled && !turnDone) {
        turnDone = true;
        // Get team one pieces
        vector<pieces> &teamOnePieces = trouble.getAllTeams().at(0);
        // Get piece moved
        pieces pieceMoved = teamOnePieces[keyNum - 1];
        // If the piece moved is not at its finish spot, move the piece
        if (!pieceMoved.finish && !pieceMoved.aroundOnce) {
            // get piece position
            int position = pieceMoved.positionOnBoard;
            // match piece position to index in circle board spots, get circle and its coordinates
            unique_ptr<Circle> &circle = spotsOnBoard[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            // Get the corresponding piece moved on team, and move on board
            unique_ptr<Circle> &userPiece = teamOne[keyNum - 1];
            // set the new position of the piece to new spot on board
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;

            // if the piece collided with another piece, send the opponent's piece home
            if (collided) {
                // If piece collided with is from team one, send it back home
                if (opponentTeam == 0) {
                    unique_ptr<Circle> &circleSpot = teamOneHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece = teamOne[opponentPiece];
                    double xC = circleSpot->getXCoord();
                    double yC = circleSpot->getYCoord();

                    // set the new position of the piece
                    collidedPiece->setXCoord(xC);
                    collidedPiece->setYCoord(yC);
                }
                // If piece collided with is from team two, send it back home
                if (opponentTeam == 1) {
                    unique_ptr<Circle> &circleSpot2 = teamTwoHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece2 = teamTwo[opponentPiece];
                    double xC2 = circleSpot2->getXCoord();
                    double yC2 = circleSpot2->getYCoord();

                    // set the new position of the piece
                    collidedPiece2->setXCoord(xC2);
                    collidedPiece2->setYCoord(yC2);

                }
                // If piece collided with is from team three, send it back home
                if (opponentTeam == 2) {
                    unique_ptr<Circle> &circleSpot3 = teamThreeHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece3 = teamThree[opponentPiece];
                    double xC3 = circleSpot3->getXCoord();
                    double yC3 = circleSpot3->getYCoord();

                    // set the new position of the piece
                    collidedPiece3->setXCoord(xC3);
                    collidedPiece3->setYCoord(yC3);

                }
                // If piece collided with is from team four, send it back home
                if (opponentTeam == 3) {
                    unique_ptr<Circle> &circleSpot4 = teamFourHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece4 = teamFour[opponentPiece];
                    double xC4 = circleSpot4->getXCoord();
                    double yC4 = circleSpot4->getYCoord();

                    // set the new position of the piece
                    collidedPiece4->setXCoord(xC4);
                    collidedPiece4->setYCoord(yC4);

                }
            }
            // Piece has been moved for user, it's CPU's turn
            diceRolled = false;
            moved = true;
            CPU = true;
        }
        // If piece moved is at finish and needs to move in finish spots, move piece
        else if (pieceMoved.finish && pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = teamOneFinish[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &userPiece = teamOne[keyNum - 1];

            // set the new position of the piece
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;
        }
        // Piece has been moved for user, it's CPU's turn
        diceRolled = false;
        moved = true;
        CPU = true;
    }

    // Move pieces for CPU if its team is 1
    if (CPUTeam == 1 && keyPressed && CPU && !turnDone) {
        turnDone = true;
        // Get team one pieces
        vector<pieces> &teamOnePieces = trouble.getAllTeams().at(0);
        // Get piece moved
        pieces pieceMoved = teamOnePieces[trouble.getIndexPieceToBeMoved()];
        // If the piece moved is not at its finish spot, move the piece
        if (!pieceMoved.finish && !pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = spotsOnBoard[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &CPUPiece = teamOne[trouble.getIndexPieceToBeMoved()];
            // set the new position of the piece
            CPUPiece->setXCoord(x);
            CPUPiece->setYCoord(y);
            keyPressed = false;

            // if the piece collided with another piece, send the opponent's piece home
            if (collided) {
                // If piece collided with is from team one, send it back home
                if (opponentTeam == 0) {
                    unique_ptr<Circle> &circleSpot = teamOneHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece = teamOne[opponentPiece];
                    double xC = circleSpot->getXCoord();
                    double yC = circleSpot->getYCoord();
                    collidedPiece->setXCoord(xC);
                    collidedPiece->setYCoord(yC);

                }
                // If piece collided with is from team two, send it back home
                if (opponentTeam == 1) {
                    unique_ptr<Circle> &circleSpot2 = teamTwoHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece2 = teamTwo[opponentPiece];
                    double xC2 = circleSpot2->getXCoord();
                    double yC2 = circleSpot2->getYCoord();
                    collidedPiece2->setXCoord(xC2);
                    collidedPiece2->setYCoord(yC2);

                }
                // If piece collided with is from team three, send it back home
                if (opponentTeam == 2) {
                    unique_ptr<Circle> &circleSpot3 = teamThreeHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece3 = teamThree[opponentPiece];
                    double xC3 = circleSpot3->getXCoord();
                    double yC3 = circleSpot3->getYCoord();
                    collidedPiece3->setXCoord(xC3);
                    collidedPiece3->setYCoord(yC3);

                }
                // If piece collided with is from team four, send it back home
                if (opponentTeam == 3) {
                    unique_ptr<Circle> &circleSpot4 = teamFourHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece4 = teamFour[opponentPiece];
                    double xC4 = circleSpot4->getXCoord();
                    double yC4 = circleSpot4->getYCoord();
                    collidedPiece4->setXCoord(xC4);
                    collidedPiece4->setYCoord(yC4);

                }
            }
        }
        // If piece moved is at finish and needs to move in finish spots, move piece
        else if (pieceMoved.finish && pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = teamOneFinish[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &CPUPiece = teamOne[trouble.getIndexPieceToBeMoved()];

            // set the new position of the piece
            CPUPiece->setXCoord(x);
            CPUPiece->setYCoord(y);
            keyPressed = false;
        }
    }

    // move pieces for user if their team is 2
    if (userTeam == 2 && keyPressed && !CPU && diceRolled  && !turnDone) {
        turnDone = true;
        // Get team two pieces
        vector<pieces> &teamTwoPieces = trouble.getAllTeams().at(1);
        // Get piece moved
        pieces pieceMoved = teamTwoPieces[keyNum - 1];
        // If the piece moved is not at its finish spot, move the piece
        if (!pieceMoved.finish && !pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = spotsOnBoard[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &userPiece = teamTwo[keyNum - 1];
            // set the new position of the piece
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;

            // if the piece collided with another piece, send the opponent's piece home
            if (collided) {
                if (opponentTeam == 0) {
                    unique_ptr<Circle> &circleSpot = teamOneHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece = teamOne[opponentPiece];
                    double xC = circleSpot->getXCoord();
                    double yC = circleSpot->getYCoord();
                    collidedPiece->setXCoord(xC);
                    collidedPiece->setYCoord(yC);

                }
                if (opponentTeam == 1) {
                    unique_ptr<Circle> &circleSpot2 = teamTwoHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece2 = teamTwo[opponentPiece];
                    double xC2 = circleSpot2->getXCoord();
                    double yC2 = circleSpot2->getYCoord();
                    collidedPiece2->setXCoord(xC2);
                    collidedPiece2->setYCoord(yC2);

                }
                if (opponentTeam == 2) {
                    unique_ptr<Circle> &circleSpot3 = teamThreeHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece3 = teamThree[opponentPiece];
                    double xC3 = circleSpot3->getXCoord();
                    double yC3 = circleSpot3->getYCoord();
                    collidedPiece3->setXCoord(xC3);
                    collidedPiece3->setYCoord(yC3);

                }
                if (opponentTeam == 3) {
                    unique_ptr<Circle> &circleSpot4 = teamFourHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece4 = teamFour[opponentPiece];
                    double xC4 = circleSpot4->getXCoord();
                    double yC4 = circleSpot4->getYCoord();
                    collidedPiece4->setXCoord(xC4);
                    collidedPiece4->setYCoord(yC4);

                }
            }
            // Piece has been moved for user, it's CPU's turn
            diceRolled = false;
            moved = true;
            CPU = true;
        }
        else if (pieceMoved.finish && pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = teamTwoFinish[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &userPiece = teamTwo[keyNum - 1];
            // set the new position of the piece
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;
        }
        // Piece has been moved for user, it's CPU's turn
        diceRolled = false;
        moved = true;
        CPU = true;
    }

    // move pieces for CPU if its team is 2
    if (CPUTeam == 2 && keyPressed && CPU && !turnDone) {
        turnDone = true;
        // Get team two pieces
        vector<pieces> &teamTwoPieces = trouble.getAllTeams().at(1);
        // Get piece moved
        pieces pieceMoved = teamTwoPieces[trouble.getIndexPieceToBeMoved()];
        // If the piece moved is not at its finish spot, move the piece
        if (!pieceMoved.finish && !pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = spotsOnBoard[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &userPiece = teamTwo[trouble.getIndexPieceToBeMoved()];
            // set the new position of the piece
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;

            // if the piece collided with another piece, send the opponent's piece home
            if (collided) {
                if (opponentTeam == 0) {
                    unique_ptr<Circle> &circleSpot = teamOneHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece = teamOne[opponentPiece];
                    double xC = circleSpot->getXCoord();
                    double yC = circleSpot->getYCoord();
                    collidedPiece->setXCoord(xC);
                    collidedPiece->setYCoord(yC);

                }
                if (opponentTeam == 1) {
                    unique_ptr<Circle> &circleSpot2 = teamTwoHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece2 = teamTwo[opponentPiece];
                    double xC2 = circleSpot2->getXCoord();
                    double yC2 = circleSpot2->getYCoord();
                    collidedPiece2->setXCoord(xC2);
                    collidedPiece2->setYCoord(yC2);

                }
                if (opponentTeam == 2) {
                    unique_ptr<Circle> &circleSpot3 = teamThreeHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece3 = teamThree[opponentPiece];
                    double xC3 = circleSpot3->getXCoord();
                    double yC3 = circleSpot3->getYCoord();
                    collidedPiece3->setXCoord(xC3);
                    collidedPiece3->setYCoord(yC3);

                }
                if (opponentTeam == 3) {
                    unique_ptr<Circle> &circleSpot4 = teamFourHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece4 = teamFour[opponentPiece];
                    double xC4 = circleSpot4->getXCoord();
                    double yC4 = circleSpot4->getYCoord();
                    collidedPiece4->setXCoord(xC4);
                    collidedPiece4->setYCoord(yC4);

                }
            }
        }
        // If piece moved is at finish and needs to move in finish spots, move piece
        else if (pieceMoved.finish && pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = teamTwoFinish[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &CPUPiece = teamTwo[trouble.getIndexPieceToBeMoved()];
            // set the new position of the piece
            CPUPiece->setXCoord(x);
            CPUPiece->setYCoord(y);
            keyPressed = false;
        }
    }

    // move pieces for user if their team is 3
    if (userTeam == 3 && keyPressed && !CPU && diceRolled && !turnDone) {
        turnDone = true;
        // Get team three pieces
        vector<pieces> &teamThreePieces = trouble.getAllTeams().at(2);
        // Get piece moved
        pieces pieceMoved = teamThreePieces[keyNum - 1];
        // If the piece moved is not at its finish spot, move the piece
        if (!pieceMoved.finish && !pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = spotsOnBoard[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &userPiece = teamThree[keyNum - 1];
            // set the new position of the piece
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;

            // if the piece collided with another piece, send the opponent's piece home
            if (collided) {
                if (opponentTeam == 0) {
                    unique_ptr<Circle> &circleSpot = teamOneHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece = teamOne[opponentPiece];
                    double xC = circleSpot->getXCoord();
                    double yC = circleSpot->getYCoord();
                    collidedPiece->setXCoord(xC);
                    collidedPiece->setYCoord(yC);

                }
                if (opponentTeam == 1) {
                    unique_ptr<Circle> &circleSpot2 = teamTwoHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece2 = teamTwo[opponentPiece];
                    double xC2 = circleSpot2->getXCoord();
                    double yC2 = circleSpot2->getYCoord();
                    collidedPiece2->setXCoord(xC2);
                    collidedPiece2->setYCoord(yC2);

                }
                if (opponentTeam == 2) {
                    unique_ptr<Circle> &circleSpot3 = teamThreeHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece3 = teamThree[opponentPiece];
                    double xC3 = circleSpot3->getXCoord();
                    double yC3 = circleSpot3->getYCoord();
                    collidedPiece3->setXCoord(xC3);
                    collidedPiece3->setYCoord(yC3);

                }
                if (opponentTeam == 3) {
                    unique_ptr<Circle> &circleSpot4 = teamFourHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece4 = teamFour[opponentPiece];
                    double xC4 = circleSpot4->getXCoord();
                    double yC4 = circleSpot4->getYCoord();
                    collidedPiece4->setXCoord(xC4);
                    collidedPiece4->setYCoord(yC4);

                }
            }
            // Piece has been moved for user, it's CPU's turn
            diceRolled = false;
            moved = true;
            CPU = true;
        }
        // If piece moved is at finish and needs to move in finish spots, move piece
        else if (pieceMoved.finish && pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = teamThreeFinish[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &userPiece = teamThree[keyNum - 1];

            // set the new position of the piece
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;
        }
        // Piece has been moved for user, it's CPU's turn
        diceRolled = false;
        moved = true;
        CPU = true;
    }

    // move pieces for CPU if its team is 3
    if (CPUTeam == 3 && keyPressed && CPU  && !turnDone) {
        turnDone = true;
        // Get team three pieces
        vector<pieces> &teamThreePieces = trouble.getAllTeams().at(2);
        // Get piece moved
        pieces pieceMoved = teamThreePieces[trouble.getIndexPieceToBeMoved()];
        // If the piece moved is not at its finish spot, move the piece
        if (!pieceMoved.finish && !pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = spotsOnBoard[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &userPiece = teamThree[trouble.getIndexPieceToBeMoved()];
            // set the new position of the piece
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;

            // if the piece collided with another piece, send the opponent's piece home
            if (collided) {
                if (opponentTeam == 0) {
                    unique_ptr<Circle> &circleSpot = teamOneHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece = teamOne[opponentPiece];
                    double xC = circleSpot->getXCoord();
                    double yC = circleSpot->getYCoord();
                    collidedPiece->setXCoord(xC);
                    collidedPiece->setYCoord(yC);

                }
                if (opponentTeam == 1) {
                    unique_ptr<Circle> &circleSpot2 = teamTwoHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece2 = teamTwo[opponentPiece];
                    double xC2 = circleSpot2->getXCoord();
                    double yC2 = circleSpot2->getYCoord();
                    collidedPiece2->setXCoord(xC2);
                    collidedPiece2->setYCoord(yC2);

                }
                if (opponentTeam == 2) {
                    unique_ptr<Circle> &circleSpot3 = teamThreeHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece3 = teamThree[opponentPiece];
                    double xC3 = circleSpot3->getXCoord();
                    double yC3 = circleSpot3->getYCoord();
                    collidedPiece3->setXCoord(xC3);
                    collidedPiece3->setYCoord(yC3);

                }
                if (opponentTeam == 3) {
                    unique_ptr<Circle> &circleSpot4 = teamFourHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece4 = teamFour[opponentPiece];
                    double xC4 = circleSpot4->getXCoord();
                    double yC4 = circleSpot4->getYCoord();
                    collidedPiece4->setXCoord(xC4);
                    collidedPiece4->setYCoord(yC4);

                }
            }
        }
        // If piece moved is at finish and needs to move in finish spots, move piece
        else if (pieceMoved.finish && pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = teamThreeFinish[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &CPUPiece = teamThree[trouble.getIndexPieceToBeMoved()];

            // set the new position of the piece
            CPUPiece->setXCoord(x);
            CPUPiece->setYCoord(y);
            keyPressed = false;
        }
    }

    // move pieces for user if their team is 4
    if (userTeam == 4 && keyPressed && !CPU && diceRolled && !turnDone) {
        turnDone = true;
        // Get team four pieces
        vector<pieces> &teamFourPieces = trouble.getAllTeams().at(3);
        // Get piece moved
        pieces pieceMoved = teamFourPieces[keyNum - 1];
        // If the piece moved is not at its finish spot, move the piece
        if (!pieceMoved.finish && !pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = spotsOnBoard[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &userPiece = teamFour[keyNum - 1];
            // set the new position of the piece
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;

            // if the piece collided with another piece, send the opponent's piece home
            if (collided) {
                if (opponentTeam == 0) {
                    unique_ptr<Circle> &circleSpot = teamOneHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece = teamOne[opponentPiece];
                    double xC = circleSpot->getXCoord();
                    double yC = circleSpot->getYCoord();
                    collidedPiece->setXCoord(xC);
                    collidedPiece->setYCoord(yC);

                }
                if (opponentTeam == 1) {
                    unique_ptr<Circle> &circleSpot2 = teamTwoHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece2 = teamTwo[opponentPiece];
                    double xC2 = circleSpot2->getXCoord();
                    double yC2 = circleSpot2->getYCoord();
                    collidedPiece2->setXCoord(xC2);
                    collidedPiece2->setYCoord(yC2);

                }
                if (opponentTeam == 2) {
                    unique_ptr<Circle> &circleSpot3 = teamThreeHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece3 = teamThree[opponentPiece];
                    double xC3 = circleSpot3->getXCoord();
                    double yC3 = circleSpot3->getYCoord();
                    collidedPiece3->setXCoord(xC3);
                    collidedPiece3->setYCoord(yC3);

                }
                if (opponentTeam == 3) {
                    unique_ptr<Circle> &circleSpot4 = teamFourHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece4 = teamFour[opponentPiece];
                    double xC4 = circleSpot4->getXCoord();
                    double yC4 = circleSpot4->getYCoord();
                    collidedPiece4->setXCoord(xC4);
                    collidedPiece4->setYCoord(yC4);

                }
            }
            // Piece has been moved for user, it's CPU's turn
            diceRolled = false;
            moved = true;
            CPU = true;
        }
        // If piece moved is at finish and needs to move in finish spots, move piece
        else if (pieceMoved.finish && pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = teamFourFinish[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &userPiece = teamFour[keyNum - 1];

            // set the new position of the piece
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;
        }
        // Piece has been moved for user, it's CPU's turn
        diceRolled = false;
        moved = true;
        CPU = true;
    }

    // move pieces for CPU if its team is 4
    if (CPUTeam == 4 && keyPressed && CPU && !turnDone) {
        turnDone = true;
        // Get team four pieces
        vector<pieces> &teamFourPieces = trouble.getAllTeams().at(3);
        // Get piece moved
        pieces pieceMoved = teamFourPieces[trouble.getIndexPieceToBeMoved()];
        // If the piece moved is not at its finish spot, move the piece
        if (!pieceMoved.finish && !pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = spotsOnBoard[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &userPiece = teamFour[trouble.getIndexPieceToBeMoved()];
            // set the new position of the piece
            userPiece->setXCoord(x);
            userPiece->setYCoord(y);
            keyPressed = false;

            // if the piece collided with another piece, send the opponent's piece home
            if (collided) {
                if (opponentTeam == 0) {
                    unique_ptr<Circle> &circleSpot = teamOneHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece = teamOne[opponentPiece];
                    double xC = circleSpot->getXCoord();
                    double yC = circleSpot->getYCoord();
                    collidedPiece->setXCoord(xC);
                    collidedPiece->setYCoord(yC);

                }
                if (opponentTeam == 1) {
                    unique_ptr<Circle> &circleSpot2 = teamTwoHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece2 = teamTwo[opponentPiece];
                    double xC2 = circleSpot2->getXCoord();
                    double yC2 = circleSpot2->getYCoord();
                    collidedPiece2->setXCoord(xC2);
                    collidedPiece2->setYCoord(yC2);

                }
                if (opponentTeam == 2) {
                    unique_ptr<Circle> &circleSpot3 = teamThreeHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece3 = teamThree[opponentPiece];
                    double xC3 = circleSpot3->getXCoord();
                    double yC3 = circleSpot3->getYCoord();
                    collidedPiece3->setXCoord(xC3);
                    collidedPiece3->setYCoord(yC3);

                }
                if (opponentTeam == 3) {
                    unique_ptr<Circle> &circleSpot4 = teamFourHome.at(opponentPiece);
                    unique_ptr<Circle> &collidedPiece4 = teamFour[opponentPiece];
                    double xC4 = circleSpot4->getXCoord();
                    double yC4 = circleSpot4->getYCoord();
                    collidedPiece4->setXCoord(xC4);
                    collidedPiece4->setYCoord(yC4);

                }
            }
        }
        // If piece moved is at finish and needs to move in finish spots, move piece
        else if (pieceMoved.finish && pieceMoved.aroundOnce) {
            int position = pieceMoved.positionOnBoard;
            unique_ptr<Circle> &circle = teamFourFinish[position];
            double x = circle->getXCoord();
            double y = circle->getYCoord();
            unique_ptr<Circle> &CPUPiece = teamFour[trouble.getIndexPieceToBeMoved()];

            // set the new position of the piece
            CPUPiece->setXCoord(x);
            CPUPiece->setYCoord(y);
            keyPressed = false;
        }
    }
}

// Initialize OpenGL Graphics
void initGL() {
    // set background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, 700, 700);

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, 700, 700, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

    /****** Drawing the Board *******/
    // Draw background elements
    for (unique_ptr<Shape>&shape : shapesOnTheBoard) {
        shape->draw();
    }

    // Draw dice
    dice.draw();

    // Draw spaces on board
    for (unique_ptr<Circle>&spot : spotsOnBoard) {
        spot->draw();
    }

    // Draw finish spots for each team on board
    for (unique_ptr<Circle>&piece : teamOneFinish){
        piece->draw();
    }

    for (unique_ptr<Circle>&piece : teamTwoFinish){
        piece->draw();
    }

    for (unique_ptr<Circle>&piece : teamThreeFinish){
        piece->draw();
    }

    for (unique_ptr<Circle>&piece : teamFourFinish){
        piece->draw();
    }

    // Draw home spots pieces on board
    for (unique_ptr<Circle>&piece : teamOneHome){
        piece->draw();
    }

    for (unique_ptr<Circle>&piece : teamTwoHome){
        piece->draw();
    }

    for (unique_ptr<Circle>&piece : teamThreeHome){
        piece->draw();
    }

    for (unique_ptr<Circle>&piece : teamFourHome){
        piece->draw();
    }

    // Draw team pieces on board
    for (unique_ptr<Circle>&piece : teamOne){
        piece->draw();
    }

    for (unique_ptr<Circle>&piece : teamTwo){
        piece->draw();
    }

    for (unique_ptr<Circle>&piece : teamThree){
        piece->draw();
    }

    for (unique_ptr<Circle>&piece : teamFour){
        piece->draw();
    }

    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(0,0,0);

    // Add number on dice
    int numOnDice = dice.getNumOnDice();
    string num = to_string(numOnDice);
    char diceRoll[1];
    diceRoll[0] = num[0];
    glRasterPos2i(345,360);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, diceRoll[0]);


    /****** Add team names to board *******/
    char teamOneName[] = "Team One";
    int len;
    glRasterPos2i(120,35);
    len = (int) strlen(teamOneName);
    for (int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, teamOneName[i]);
    }

    char teamTwoName[] = "Team Two";
    int len2;
    glRasterPos2i(500,35);
    len2 = (int) strlen(teamTwoName);
    for (int i = 0; i < len2; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, teamTwoName[i]);
    }

    char teamThreeName[] = "Team Three";
    int len3;
    glRasterPos2i(500,680);
    len3 = (int) strlen(teamThreeName);
    for (int i = 0; i < len3; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, teamThreeName[i]);
    }

    char teamFourName[] = "Team Four";
    int len4;
    glRasterPos2i(120,680);
    len4 = (int) strlen(teamFourName);
    for (int i = 0; i < len4; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, teamFourName[i]);
    }

    // Ask user to select a team number
    if (beginGame) {
        char incorrectMove[] = "Please select 1,2,3, or 4 to be your team number";
        int lenMessage;
        glRasterPos2i(230,50);
        lenMessage = (int) strlen(incorrectMove);
        for (int i = 0; i < lenMessage; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, incorrectMove[i]);
        }
    }

    // Tell the user to press the dice to roll and then select the piece they want to move
    if (userTurn) {
        char incorrectMove[] = "Please press the dice to roll and select the piece you want to move";
        int lenMessage;
        glRasterPos2i(200,50);
        lenMessage = (int) strlen(incorrectMove);
        for (int i = 0; i < lenMessage; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, incorrectMove[i]);
        }
    }

    // Tell the user to press the dice to roll for the CPU
    if (CPUTurn) {
        char incorrectMove[] = "Please press the dice to roll for the CPU and press 5 after";
        int lenMessage;
        glRasterPos2i(200,50);
        lenMessage = (int) strlen(incorrectMove);
        for (int i = 0; i < lenMessage; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, incorrectMove[i]);
        }
    }

    // Get whether or not piece move was valid from team just moved
    vector<vector<pieces>>& allTroubleTeams = trouble.getAllTeams();
    bool homeAnswer = allTroubleTeams.at(userTeam - 1).at(keyNum -1).home;

    // User's choice is invalid
    if (!valid && !homeAnswer) {
        char incorrectMove[] = "Invalid move";
        int len5;
        glRasterPos2i(330,680);
        len5 = (int) strlen(incorrectMove);
        for (int i = 0; i < len5; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, incorrectMove[i]);
        }
    }

    // User can't move piece from home unless it is a 6
    if (!valid && homeAnswer && !changeMessage) {
        char incorrectMove[] = "Can't move piece from home unless you roll a 6";
        int len6;
        glRasterPos2i(230,640);
        len6 = (int) strlen(incorrectMove);
        for (int i = 0; i < len6; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, incorrectMove[i]);
        }
    }
    // Render now
    glFlush();
}


void kbd(unsigned char key, int x, int y) {
    // Booleans
    collided = false;
    keyPressed = false;
    bool pickAgain = true;
    bool firstPick = true;

    // have switch and cases for each 1,2,3,4 keys
    switch (key) {
        // escape
        case 27: {
            glutDestroyWindow(wd);
            exit(0);
            break;
        }
        case '1': {
            // If user has not selected team yet, let user select team and set userTeam
            if (!teamSelected) {
                // set all booleans to begin
                userTurn = true;
                userTime = true;
                start = true;
                firstPick = false;
                trouble.setUserTeam(1);
                userTeam = 1;
                teamSelected = true;
                beginGame = false;
                break;
            }

            /**** Move piece 1 ****/
            // otherwise, user wants to move piece 1, check to see if valid move
            valid = false;

            // determine if piece has already been moved
            if (moved && !diceRolled) {
                userMovePiece = false;
                cout << "This piece was already moved for this turn" << endl;
            }
            // if the piece has not been moved already, determine if it can be moved
            else if (!moved && userTime) {
                userMovePiece = true;
                valid = trouble.pickPiece(userTeam, 1);
            }

            // if valid move, check to see if user piece collided with other pieces
            // if so, get the piece collided with and team number associated w/ it
            // move changed pieces on the board
            if (valid && !keyPressed && diceRolled) {
                keyPressed = true;
                keyNum = 1;
                // If piece selected collided with other team's piece
                if (trouble.getPieceCollided()) {
                    collided = true;
                    opponentPiece = trouble.getOpponentMoved(); // gets piece index
                    opponentTeam = trouble.getOpponentTeam(); // gets team number
                    CPU = false;
                    movePieces();
                }
                else {
                    collided = false;
                    CPU = false;
                    movePieces();
                    if (userRollsASix) {
                        CPU = false;
                    }
                }
                diceRolled = false;
            }

            // get piece that was played
            vector<vector<pieces>> &teamPlayed = trouble.getAllTeams();
            pieces piecePlayed = teamPlayed.at(userTeam - 1).at(0);

            // If piece is at home and it is not valid (can't move because a 6 wasn't rolled),
            // then mark as moved because user's turn is over
            if (piecePlayed.home && !valid) {
                moved = true;
            }

            // If valid and piece is not at home and it is the user's turn or the
            // piece was moved and it is still the user's turn, then pickAgain is false
            if ((valid && !piecePlayed.home && userTurn) || (moved && userTime)) {
                pickAgain = false;
            }
            break;
        }
        case '2': {
            // user selects team 2
            if (!teamSelected) {
                // set all booleans to begin
                start = true;
                firstPick = false;
                userTime = false;
                trouble.setUserTeam(2);
                userTeam = 2;
                teamSelected = true;
                beginGame = false;
                break;
            }
            // Reset valid to false (piece moved has not been validated)
            valid = false;

            /**** Move piece 2 ****/
            // determine if piece has already been moved
            if (moved && !diceRolled) {
                userMovePiece = false;
                cout << "This piece was already moved for this turn" << endl;
            }
            // if the piece has not been moved already, determine if it can be moved
            else if (!moved && userTime) {
                valid = trouble.pickPiece(userTeam, 2);
            }
            // if valid move, check to see if user piece collided with other pieces
            // if so, get the piece collided with and team number associated w/ it
            // move changed pieces on the board
            if (valid && !keyPressed && diceRolled) {
                keyPressed = true;
                keyNum = 2;
                if (trouble.getPieceCollided()) {
                    collided = true;
                    opponentPiece = trouble.getOpponentMoved();
                    opponentTeam = trouble.getOpponentTeam();
                    CPU = false;
                    movePieces();
                }
                else {
                    collided = false;
                    CPU = false;
                    movePieces();
                    if (userRollsASix) {
                        CPU = false;
                    }
                }
                diceRolled = false;
            }

            // get piece that was played
            vector<vector<pieces>> &teamPlayed = trouble.getAllTeams();
            pieces piecePlayed = teamPlayed.at(userTeam - 1).at(1);

            // piece is at home and it is not valid (can't move because a 6 wasn't rolled),
            // then mark as moved because user's turn is over
            if (piecePlayed.home && !valid) {
                moved = true;
            }

            // if valid and piece is not at home and it is the user's turn or the
            // piece was moved and it is still the user's turn, then pickAgain is false
            if ((valid && !piecePlayed.home && userTurn) || (moved && userTime)) {
                pickAgain = false;
            }
            break;
        }
        case '3': {
            // user selects team 3
            if (!teamSelected) {
                // set all booleans to begin
                start = true;
                firstPick = false;
                userTime = false;
                trouble.setUserTeam(3);
                userTeam = 3;
                teamSelected = true;
                beginGame = false;
                break;
            }

            // Reset valid to false (piece moved has not been validated)
            valid = false;

            /**** Move piece 3 ****/
            // determine if piece has already been moved
            if (moved && !diceRolled) {
                userMovePiece = false;
                cout << "This piece was already moved for this turn" << endl;
            }
            // if the piece has not been moved already, determine if it can be moved
            else if (!moved && userTime) {
                valid = trouble.pickPiece(userTeam, 3);
            }
            // if valid move, check to see if user piece collided with other pieces
            // if so, get the piece collided with and team number associated w/ it
            // move changed pieces on the board
            if (valid && !keyPressed && diceRolled) {
                keyPressed = true;
                keyNum = 3;
                if (trouble.getPieceCollided()) {
                    collided = true;
                    opponentPiece = trouble.getOpponentMoved();
                    opponentTeam = trouble.getOpponentTeam();
                    CPU = false;
                    movePieces();
                }
                else {
                    collided = false;
                    CPU = false;
                    movePieces();
                    if (userRollsASix) {
                        CPU = false;
                    }
                }
                diceRolled = false;
            }

            // get piece that was played
            vector<vector<pieces>> &teamPlayed = trouble.getAllTeams();
            pieces piecePlayed = teamPlayed.at(userTeam - 1).at(2);

            // piece is at home and it is not valid (can't move because a 6 wasn't rolled),
            // then mark as moved because user's turn is over
            if (piecePlayed.home && !valid) {
                moved = true;
            }

            // if valid and piece is not at home and it is the user's turn or the
            // piece was moved and it is still the user's turn, then pickAgain is false
            if ((valid && !piecePlayed.home && userTurn) || (moved && userTime)) {
                pickAgain = false;
            }
            break;
        }
        case '4': {
            // user selects team 4
            if (!teamSelected) {
                // set all booleans to begin
                start = true;
                userTime = false;
                firstPick = false;
                trouble.setUserTeam(4);
                userTeam = 4;
                teamSelected = true;
                beginGame = false;
                break;
            }
            // Reset valid to false (piece moved has not been validated)
            valid = false;

            /**** Move piece 4 ****/
            // determine if piece has already been moved
            if (moved && !diceRolled) {
                userMovePiece = false;
                cout << "This piece was already moved for this turn" << endl;
            }
            // if the piece has not been moved already, determine if it can be moved
            else if (!moved && userTime) {
                valid = trouble.pickPiece(userTeam, 4);
            }
            // if valid move, check to see if user piece collided with other pieces
            // if so, get the piece collided with and team number associated w/ it
            // move changed pieces on the board
            if (valid && !keyPressed && diceRolled) {
                keyPressed = true;
                keyNum = 4;
                if (trouble.getPieceCollided()) {
                    collided = true;
                    opponentPiece = trouble.getOpponentMoved();
                    opponentTeam = trouble.getOpponentTeam();
                    CPU = false;
                    movePieces();
                }
                else {
                    collided = false;
                    CPU = false;
                    movePieces();
                    if (userRollsASix) {
                        CPU = false;
                    }
                }
                diceRolled = false;
            }

            // get piece that was played
            vector<vector<pieces>> &teamPlayed = trouble.getAllTeams();
            pieces piecePlayed = teamPlayed.at(userTeam - 1).at(3);

            // piece is at home and it is not valid (can't move because a 6 wasn't rolled),
            // then mark as moved because user's turn is over
            if (piecePlayed.home && !valid) {
                moved = true;
            }

            // if valid and piece is not at home and it is the user's turn or the
            // piece was moved and it is still the user's turn, then pickAgain is false
            if ((valid && !piecePlayed.home && userTurn) || (moved && userTime)) {
                pickAgain = false;
            }
            break;
        }
        // CPU's Turn
        case '5': {
            // Making sure user has selected 1-4 for team
            if (!teamSelected) {
                break;
            }
            // if the user has selected their team and pressed a key, then
            // have the CPU play its turn
            else if (teamSelected && !keyPressed && !CPUMoved) {
                userTurn = false;
                keyPressed = true;
                CPUTurn = true;
                timeToPlay(teamNumTurn);
            }
            break;
        }
    }

    // if pick again is false, then it is the next team's turn
    if (!pickAgain && userMovePiece) {
        timeToPlay(teamNumTurn);
    }
    // At the start of the game, if the user didn't select team 1, then it is the CPU's turn
    if (userTeam != 1 && !firstPick) {
        CPU = true;
        CPUTurn = true;
    }
    // Redisplay board
    glutPostRedisplay();
}

void cursor(int x, int y) {
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    /****** Pressed down on mouse *******/
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && start) {
        dice.setColor(196.0/250,149.0/250,185.0/250);
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && start && !userTime && !CPU) {
        dice.setColor(1,1,1);
    }

    /******* Mouse is up ********/
    // user turn
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && start && !keyPressed && userTime && !CPU && !userRollsASix) {
        changeMessage = false;

        // rolls the dice
        int roll = trouble.rollDie();
        dice.setNumOnDice(roll);
        dice.setColor(1,1,1);
        diceRolled = true;
        moved = false;
        turnDone = false;

        // if the user has rolled a six, then it is still their turn
        if (roll == 6) {
            userTime = true;
            userRollsASix = true;
        }
        // if the user doesn't roll a 6, it is the CPU's turn
        else {
            CPU = true;
        }
    }

    // user turn if they rolled a six
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && start && userRollsASix && userTime && !CPU) {
        cout << trouble.getDieRolled() << endl;

        // if user rolls a 6, roll again
        int roll = trouble.rollDie();
        dice.setNumOnDice(roll);
        dice.setColor(1,1,1);
        diceRolled = true;
        moved = false;
        turnDone = false;

        // if the user rolls a six again, it is still their turn
        if (roll == 6) {
            rolledASixAgain = true;
        }
        // if they don't roll a six again, it is the CPU's turn
        else {
            rolledASixAgain = false;
            keyPressed = true;
            CPU = false;
        }
    }

    // User plays for CPU (Mouse is up)
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && start && CPU && !CPURollsASix) { //!userTime
        changeMessage = true;

        // roll the dice for the CPU
        int roll = trouble.rollDie();
        dice.setNumOnDice(roll);
        dice.setColor(1,1,1);
        userTime = false;
        keyPressed = true;
        diceRolled = true;
        CPUMoved = false;

        // if the CPU rolls a 6, then it is still their turn
        if (roll == 6) {
            userTime = false;
        }
        // if the next team number whose turn it is, is the user's team,
        // then it is the user's turn
        else if (teamNumTurn == userTeam) {
            userTime = true;
        }
        // otherwise, it is the next CPU's turn
        else {
            CPU = true;
        }
    }

    // CPU turn (user rolls for CPU)
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && start && CPU && CPURollsASix) {
        cout << trouble.getDieRolled() << endl;
        // if CPU rolls a 6, roll again
        int roll = trouble.rollDie();
        dice.setNumOnDice(roll);
        dice.setColor(1,1,1);
        diceRolled = true;
        CPUMoved = false;

        // determine if it is the user's turn or CPU's turn
        if (roll != 6 && userTeam != teamNumTurn) {
            userTime = false;
            keyPressed = true;
            CPU = true;
        }
    }

    // Dice should not do anything if it is not the correct turn
    else if ((button == GLUT_LEFT_BUTTON && state == GLUT_UP && start && keyPressed && !userTime) ||
            (button == GLUT_LEFT_BUTTON && state == GLUT_UP && start) ||
            (button == GLUT_LEFT_BUTTON && state == GLUT_UP && start && !userTime)) {
        dice.setColor(1,1,1);
    }
    glutPostRedisplay();
}

void timer(int dummy) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

int main(int argc, char** argv) {
    // set seed for randomization for dice in Trouble
    srand(time(0));
    init();

    // Initialize GLUT
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize(700, 700);

    // Position the window's initial top-left corner
    glutInitWindowPosition(250, 80);

    // create the window and store the title to it
    wd = glutCreateWindow("Trouble");

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // (this is for 1,2,3,4 or escape keys)
    glutKeyboardFunc(kbd);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles the click of the mouse
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();

    return 0;
}
