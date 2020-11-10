//
// Created by Michelle on 4/13/2020.
//
#include "Game.h"
#include <iomanip>

// Constructors
Game::Game() : gameName("Game"), players(0), score(0), shapeOfBoard(square) {
}

Game:: Game(int players, string name) {
    setName(name);
    this->players = (players < 0) ? 0 : players;
}

// Getters
string Game::getName() const {
    return gameName;
}

int Game::getPlayers() const {
    return players;
}

int Game::getScore() const{
    return score;
}

int Game::getSpaces() const {
    return spaces;
}

boardShape Game::getBoardShape() const {
    return shapeOfBoard;
}

// Setters
void Game::setName(string name) {
    if (name == "")
        gameName = "Game";
    else
        gameName = name;
}

void Game::setBoardShape(boardShape shapeOfBoard) {
    this->shapeOfBoard = shapeOfBoard;
}

void Game::setPlayers(int players) {
    this->players = (players < 0) ? 0 : players;
}

void Game::setScore(int score) {
    this->score = (score < 0) ? 0 : score;
}

void Game::setSpaces(int spaces) {
    this->spaces = (spaces < 0) ? 0 : spaces;
}