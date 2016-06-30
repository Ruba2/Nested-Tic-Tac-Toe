#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"board.h"


class Controller {
	Board *board;			// pointer to the main board
	public:
	Controller();			// ctor
	~Controller();			// dtor
//	void notify_board(int, int);	// Handles navigation and control.
	void play();			// Main Game loop.
};
#endif
