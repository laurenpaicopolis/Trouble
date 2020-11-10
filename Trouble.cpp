//
// Created by Michelle on 4/13/2020.
//

#include <iostream>
#include "Trouble.h"
#include "Team.h"
#include "Game.h"

using namespace std;

// Constructors
Trouble::Trouble() : winner(false), numOfDie(0), numOfPieces(0) {
}

Trouble::Trouble(int numOfDie, int numOfPieces) {
    setDie(numOfDie);
    setPieces(numOfPieces);
}
// Getters
int Trouble::getPieces() const {
    return numOfPieces;
}

int Trouble::getDie() const {
    return numOfDie;
}

bool Trouble::getWinner() const {
    return winner;
}

int Trouble::getDieRolled() const {
    return numRolled;
}

int Trouble::getOpponentMoved() const {
    return opponentMoved;
}

pieces &Trouble::getCPUPiece() {
    return CPUPiece;
}

int Trouble::getIndexPieceToBeMoved() const {
    return indexPieceToBeMoved;
}

vector<pieces> &Trouble::getTeamOnePieces() {
    return allTeams[0];
}

vector<pieces> &Trouble::getTeamTwoPieces() {
    return allTeams[1];
}

vector<pieces> &Trouble::getTeamThreePieces() {
    return allTeams[2];
}

vector<pieces> &Trouble::getTeamFourPieces() {
    return allTeams[3];
}

vector<vector<pieces>> &Trouble::getAllTeams() {
    return allTeams;
}
int Trouble::getUserTeam() const{
    return userTeam;
}

int Trouble::getOpponentTeam() const {
    return opponentTeam;
}

bool Trouble::getPieceCollided() const {
    return pieceCollided;
}

// Setters
void Trouble::setPieces(int numOfPieces) {
    this->numOfPieces = (numOfPieces < 0) ? 0 : numOfPieces;
}

void Trouble::setDie(int numOfDie) {
    this->numOfDie = (numOfDie < 0) ? 0 : numOfDie;
}

void Trouble::setCPUPiece(pieces CPUpiece) {
    CPUPiece = CPUpiece;
}

void Trouble::setWinner(bool winner) {
    this->winner = winner;
}

void Trouble::setIndexPieceToBeMoved(int indexPieceToBeMoved) {
    if (indexPieceToBeMoved == 0 || indexPieceToBeMoved == 1 || indexPieceToBeMoved == 2 ||
        indexPieceToBeMoved == 3) {
        this->indexPieceToBeMoved = indexPieceToBeMoved;
    }
    else {
        this->indexPieceToBeMoved = 0;
    }
}

// Creates all of the teams for play
void Trouble::createTeams() {
    teamBlue.setTeamNumber(1);
    teamBlue.setNumOfTeamPieces(4);
    teamBlue.setColor(Blue);
    team1Pieces = teamBlue.addPiecesTeamOne();
    // add team 1 to vector of teams
    allTeams.push_back(team1Pieces);

    teamGreen.setTeamNumber(2);
    teamGreen.setNumOfTeamPieces(4);
    teamGreen.setColor(Green);
    team2Pieces = teamGreen.addPiecesTeamTwo();
    // add team 2 to vector of teams
    allTeams.push_back(team2Pieces);

    teamRed.setTeamNumber(3);
    teamRed.setNumOfTeamPieces(4);
    teamRed.setColor(Red);
    team3Pieces = teamRed.addPiecesTeamThree();
    // add team 3 to vector of teams
    allTeams.push_back(team3Pieces);

    teamYellow.setTeamNumber(4);
    teamYellow.setNumOfTeamPieces(4);
    teamYellow.setColor(Yellow);
    team4Pieces = teamYellow.addPiecesTeamFour();
    // add team 4 to vector of teams
    allTeams.push_back(team4Pieces);

}

// Sets the user's team number
void Trouble::setUserTeam(int teamSelected) {
    if (!alreadySelected) {
        alreadySelected = true;
        userTeam = teamSelected;
    }
}

// Moves user selected piece
bool Trouble::pickPiece(int teamNumber, int keyNumber) {
    // Reset bools
    bool answer = false;
    bool letsGo = false;
    finishTime = false;
    // Get the user selected piece to be moved
    pieces &pieceToBeMoved = allTeams.at(teamNumber - 1).at(keyNumber - 1);
    // Save original position of piece
    originalPosition = pieceToBeMoved.positionOnBoard;

    // If the piece is in play, move the piece around the board
    if (!pieceToBeMoved.home) {
        // Move the piece the number rolled by user
        for (int i = 1; i <= numRolled; i++) {
            pieceToBeMoved.positionOnBoard++;
            // If that number exceeds 27 (max index of circle spots on board), reset to 0
            if (pieceToBeMoved.positionOnBoard > 27) {
                pieceToBeMoved.positionOnBoard = 0;
            }
            // If the team number is one, and the user's piece is approaching finish
            // reset position to match finish circle index's on board in graphics
            if (teamNumber == 1) {
                if ((pieceToBeMoved.positionOnBoard == 3 && !pieceToBeMoved.aroundOnce) ||
                    pieceToBeMoved.timeToGoHome) {
                    letsGo = true;
                    pieceToBeMoved.aroundOnce = true;
                    pieceToBeMoved.positionOnBoard = -1;
                    if (i == numRolled) {
                        pieceToBeMoved.positionOnBoard = 3;
                        pieceToBeMoved.timeToGoHome = true;
                    }
                }
            }
            // If the team number is two, and the user's piece is approaching finish
            // reset position to match finish circle index's on board in graphics
            if (teamNumber == 2) {
                if ((pieceToBeMoved.positionOnBoard == 9 && !pieceToBeMoved.aroundOnce) ||
                    pieceToBeMoved.timeToGoHome) {
                    letsGo = true;
                    pieceToBeMoved.aroundOnce = true;
                    pieceToBeMoved.positionOnBoard = -1;
                    if (i == numRolled) {
                        pieceToBeMoved.positionOnBoard = 9;
                        pieceToBeMoved.timeToGoHome = true;
                    }
                }
            }
            // If the team number is three, and the user's piece is approaching finish
            // reset position to match finish circle index's on board in graphics
            if (teamNumber == 3) {
                if (pieceToBeMoved.positionOnBoard == 17 || pieceToBeMoved.timeToGoHome) {
                    letsGo = true;
                    pieceToBeMoved.aroundOnce = true;
                    pieceToBeMoved.positionOnBoard = -1;
                    if (i == numRolled) {
                        pieceToBeMoved.positionOnBoard = 17;
                        pieceToBeMoved.timeToGoHome = true;
                    }
                }
            }
            // If the team number is four, and the user's piece is approaching finish
            // reset position to match finish circle index's on board in graphics
            if (teamNumber == 4) {
                if (pieceToBeMoved.positionOnBoard == 23 || pieceToBeMoved.timeToGoHome) {
                    letsGo = true;
                    pieceToBeMoved.aroundOnce = true;
                    pieceToBeMoved.positionOnBoard = -1;
                    if (i == numRolled) {
                        pieceToBeMoved.positionOnBoard = 23;
                        pieceToBeMoved.timeToGoHome = true;
                    }
                }
            }
        }
        // If the piece is already in the finish and dice rolled to move it is too big
        // for legal move, reset back to original position in finish spots
        if ((pieceToBeMoved.positionOnBoard > 3 && pieceToBeMoved.finish)) {
            pieceToBeMoved.positionOnBoard = originalPosition;
        }

        // If the piece just moved into finish spots and dice rolled to move it is too big
        // for legal move, reset back to original position outside of finish spots
        else if (pieceToBeMoved.positionOnBoard > 3 && letsGo)
            pieceToBeMoved.positionOnBoard = originalPosition;

        // otherwise the piece had a small enough roll to be in finish spots
        else if (pieceToBeMoved.aroundOnce) {
            finishTime = true;
        }
    }

    // get vector of pieces of user's team
    vector<pieces> team = allTeams.at(teamNumber - 1);

    // check if piece selected is a valid move on board
    answer = ruleBreaker(team, pieceToBeMoved, teamNumber);

    // return if piece selected was a valid move on board
    return answer;
}

// Determine if piece can be moved without breaking any rules
bool Trouble::ruleBreaker(vector<pieces> &team, pieces &pieceToBeMoved, int teamNumber) {
    bool success = true;
    int firstToFinish = 0;

    // If the piece just moved into a finish spot or is already in finish, make
    // sure it is not colliding with any of its own pieces
    if (finishTime || pieceToBeMoved.finish) {
        for (int i = 0; i < team.size(); i++) {
            if ((team[i].finish) && (team[i].pieceID != pieceToBeMoved.pieceID)) {
                firstToFinish += 1;
                // If piece not originally in finish, make sure it is not
                // colliding with piece already in finish
                if (!pieceToBeMoved.finish) {
                    if (pieceToBeMoved.positionOnBoard == team[i].positionOnBoard) {
                        // Collided with own team, not valid
                        success = false;
                        // Reset back to original position
                        pieceToBeMoved.positionOnBoard = originalPosition;
                        pieceToBeMoved.finish = false;
                        pieceToBeMoved.aroundOnce = false;
                    }
                }
                // It user piece selected already in finish, make sure it is legal move
                if (pieceToBeMoved.finish) {
                    // Piece is already at top/farthest spot in finish positions on board already
                    // cannot move any further
                    if (pieceToBeMoved.positionOnBoard == 3) {
                        // Not valid
                        success = false;
                    }
                    // If the piece collided with its own team in finish, not valid
                    if (pieceToBeMoved.positionOnBoard == team[i].positionOnBoard) {
                        success = false;
                        // Reset back to original position
                        pieceToBeMoved.positionOnBoard = originalPosition;
                    }
                }
            }
        }
        // If it is the first piece to get to finish, it was a success, set piece finish to true
        if (firstToFinish == 0 && !pieceToBeMoved.finish)
            pieceToBeMoved.finish = true;
        // Otherwise if successful move, set piece finish to true
        if (success)
            pieceToBeMoved.finish = true;
    }

    // If the piece the user wants to select to move is in home and
    // the user does not roll a six, success is false
    if (pieceToBeMoved.home) {
        if (numRolled != 6)
            success = false;
        else {
            // Piece is on board, set home to false
            pieceToBeMoved.home = false;
            // First time piece has been on board for the entire game
            pieceToBeMoved.firstTimeOut = true;
        }
    }
    else
        pieceToBeMoved.firstTimeOut = false;

    // determine if they are landing on another one of their own pieces
    // if piece selected lands on one of their own pieces, select new piece
    if (!pieceToBeMoved.home && !pieceToBeMoved.aroundOnce && !pieceToBeMoved.finish) {
        for (int i = 0; i < team.size(); i++) {
            if (team[i].pieceID != pieceToBeMoved.pieceID) {
                if (!team[i].home && !team[i].finish) {
                    if (team[i].positionOnBoard == pieceToBeMoved.positionOnBoard) {
                        success = false;
                        if (pieceToBeMoved.firstTimeOut) {
                            pieceToBeMoved.home = true;
                        }
                    }
                }
            }
        }

        // If there was a rule broken, reset piece to be moved
        if (!success ) {
            if (!pieceToBeMoved.firstTimeOut) {
                for (int i = 0; i <= (numRolled - 1); i++) {
                    pieceToBeMoved.positionOnBoard--;
                    if (pieceToBeMoved.positionOnBoard < 0){
                        pieceToBeMoved.aroundOnce = false;
                        pieceToBeMoved.positionOnBoard = 27;
                    }
                }
            }
        }
    }

    // If user didn't break any rules, determine if their piece will land on another player's piece
    pieceCollided = false;
    if (success && !pieceToBeMoved.aroundOnce) {
            determineIfPiecesCollide(pieceToBeMoved, teamNumber);
    }
    return success;
}

// Determine if piece moved collided with any other players pieces
void Trouble::determineIfPiecesCollide(pieces &pieceToBeMoved, int teamNumber) {
    pieceCollided = false;
    for (int i = 0; i < allTeams.size(); i++) {
        if (i != (teamNumber - 1)) {
            // Get opponents pieces
            vector<pieces> &opponent = allTeams[i];
            // If the opponent's piece is not in home and not at finish, check to see
            // if piece moved collided with it
            for (int j = 0; j < opponent.size(); j++) {
                if (!opponent[j].home && !opponent[j].finish) {
                    if (opponent[j].positionOnBoard == pieceToBeMoved.positionOnBoard) {
                        // Reset collided pieces bools back to start
                        opponent[j].home = true;
                        opponent[j].timeToGoHome = false;
                        opponent[j].aroundOnce = false;
                        // If collided piece is from team one, reset to home position
                        if (opponent[j].teamNum == 1) {
                            opponent[j].positionOnBoard = 4;
                        }
                        // If collided piece is from team two, reset to home position
                        if (opponent[j].teamNum == 2) {
                            opponent[j].positionOnBoard = 10;
                        }
                        // If collided piece is from team three, reset to home position
                        if (opponent[j].teamNum == 3) {
                            opponent[j].positionOnBoard = 18;
                        }
                        // If collided piece is from team four, reset to home position
                        if (opponent[j].teamNum == 4) {
                            opponent[j].positionOnBoard = 24;
                        }
                        // Save opponent team and piece index collided with
                        opponentMoved = j;
                        pieceCollided = true;
                        opponentTeam = i;
                    }
                }
            }
        }
    }
}

// CPU selects random piece to be moved
bool Trouble::CPUtime(int CPUTeam) {
    // Set booleans to start
    bool answer = false;
    bool finished = false;
    finishTime = false;
    bool letsGo = false;

    // Get CPU team pieces
    vector<pieces> &CPUpieces = allTeams.at(CPUTeam - 1);

    // While all the pieces on the team have not been tested to see if valid, and
    // their has still not been a valid move made
    while (!answer && !finished) {

        // Set to start values
        finishTime = false;
        int ct = 0;

        // move random piece (0-3)
        indexPieceToBeMoved = rand() % 4;
        setIndexPieceToBeMoved(indexPieceToBeMoved);

        // Get piece selected
        pieces &pieceToBeMoved = allTeams.at(CPUTeam - 1).at(indexPieceToBeMoved);
        // Save original position of piece
        originalPosition = pieceToBeMoved.positionOnBoard;
        // loop through each of the team pieces, check if they have all been tried yet
        for (int i = 0; i < CPUpieces.size(); i++) {
            if (CPUpieces[i].tried)
                ct++; // keep track of pieces already tried
        }
        // If all pieces have been tried and none can do a valid move,
        // end CPU's turn
        if (ct == 4) {
            finished = true;
            answer = false;
        }

        // If piece selected is not at home/been tried, and not all pieces have been tried yet
        // Add number rolled on dice and check to see if valid move
        if (!pieceToBeMoved.home && !finished && !pieceToBeMoved.tried) {
            pieceToBeMoved.tried = true;
            // Move the piece the number rolled by user
            for (int i = 1; i <= numRolled; i++) {
                pieceToBeMoved.positionOnBoard++;
                // If that number exceeds 27 (max index of circle spots on board), reset to 0
                if (pieceToBeMoved.positionOnBoard > 27) {
                    pieceToBeMoved.positionOnBoard = 0;
                }
                // If the team number is one, and the CPU's piece is approaching finish
                // reset position to match finish circle index's on board in graphics
                if (CPUTeam == 1) {
                    if ((pieceToBeMoved.positionOnBoard == 3 && !pieceToBeMoved.aroundOnce) ||
                        pieceToBeMoved.timeToGoHome) {
                        letsGo = true;
                        pieceToBeMoved.aroundOnce = true;
                        pieceToBeMoved.positionOnBoard = -1;
                        if (i == numRolled) {
                            pieceToBeMoved.positionOnBoard = 3;
                            pieceToBeMoved.timeToGoHome = true;
                        }
                    }
                }
                // If the team number is two, and the CPU's piece is approaching finish
                // reset position to match finish circle index's on board in graphics
                if (CPUTeam == 2) {
                    if ((pieceToBeMoved.positionOnBoard == 9 && !pieceToBeMoved.aroundOnce) ||
                        pieceToBeMoved.timeToGoHome) {
                        letsGo = true;
                        pieceToBeMoved.aroundOnce = true;
                        pieceToBeMoved.positionOnBoard = -1;
                        if (i == numRolled) {
                            pieceToBeMoved.positionOnBoard = 9;
                            pieceToBeMoved.timeToGoHome = true;
                        }
                    }
                }
                // If the team number is three, and the CPU's piece is approaching finish
                // reset position to match finish circle index's on board in graphics
                if (CPUTeam == 3) {
                    if (pieceToBeMoved.positionOnBoard == 17 || pieceToBeMoved.timeToGoHome) {
                        letsGo = true;
                        pieceToBeMoved.aroundOnce = true;
                        pieceToBeMoved.positionOnBoard = -1;
                        if (i == numRolled) {
                            pieceToBeMoved.positionOnBoard = 17;
                            pieceToBeMoved.timeToGoHome = true;
                        }
                    }
                }
                // If the team number is four, and the CPU's piece is approaching finish
                // reset position to match finish circle index's on board in graphics
                if (CPUTeam == 4) {
                    if (pieceToBeMoved.positionOnBoard == 23 || pieceToBeMoved.timeToGoHome) {
                        letsGo = true;
                        pieceToBeMoved.aroundOnce = true;
                        pieceToBeMoved.positionOnBoard = -1;
                        if (i == numRolled) {
                            pieceToBeMoved.positionOnBoard = 23;
                            pieceToBeMoved.timeToGoHome = true;
                        }
                    }
                }
            }

            // If the piece is already in the finish and dice rolled to move it is too big
            // for legal move, reset back to original position in finish spots
            if ((pieceToBeMoved.positionOnBoard > 3 && pieceToBeMoved.finish)) {
                pieceToBeMoved.positionOnBoard = originalPosition;
            }

            // If the piece just moved into finish spots and dice rolled to move it is too big
            // for legal move, reset back to original position outside of finish spots
            else if (pieceToBeMoved.positionOnBoard > 3 && letsGo) {
                pieceToBeMoved.positionOnBoard = originalPosition;
            }

            // otherwise the piece had a small enough roll to be in finish spots
            else if (pieceToBeMoved.aroundOnce) {
                finishTime = true;
            }
            // check if piece selected is a valid move on board
            answer = ruleBreaker(CPUpieces, pieceToBeMoved, CPUTeam);
        }

        // If the piece selected is leaving a home spot
        // check if piece selected is a valid move on board
        if (pieceToBeMoved.home && !finished && !pieceToBeMoved.tried) {
            pieceToBeMoved.tried = true;
            answer = ruleBreaker(CPUpieces, pieceToBeMoved, CPUTeam);
        }
    }

    // After checking all pieces or finding a valid piece to select
    // reset tried for all CPU pieces for next turn
    for (int i = 0; i < CPUpieces.size(); i++) {
        CPUpieces[i].tried = false;
    }

    // return if piece selected was a valid move on board
    return answer;
}

int Trouble::rollDie() {
    // get a random number between 1-6
    numRolled = rand() % 6 + 1;
    return numRolled;
}

void Trouble::board(int spaces, boardShape shapeOfBoard) {
    // Set spaces on board to 52 (number on trouble board)
    if (spaces!= 52)
        spaces = 52;
    else
        this->spaces = spaces;
    this->shapeOfBoard= shapeOfBoard;
}