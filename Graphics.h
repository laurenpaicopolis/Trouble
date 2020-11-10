//
// Created by Michelle on 4/17/2020.
//

#ifndef MW_LP_FINAL_PROJECT_GRAPHICS_GRAPHICS_H
#define MW_LP_FINAL_PROJECT_GRAPHICS_GRAPHICS_H

#include "Circle.h"
#include "Shape.h"
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void drawCircles();

void timeToPlay(int teamNum);
void teamTurn(int teamNum);

// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init();

// Initialize OpenGL Graphics
void InitGL();

// Callback functions for GLUT

// Draw the window - this is where all the GL actions are
void display();

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int dummy);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);

// Move selected piece on the board
void movePieces();


#endif //MW_LP_FINAL_PROJECT_GRAPHICS_GRAPHICS_H
