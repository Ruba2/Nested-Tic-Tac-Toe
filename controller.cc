#include"controller.h"
#include"board.h"
#include<string>
#include<iostream>
using namespace std;
// Ctor
Controller::Controller() {
	this->board = new Board;
}


// Dtor
Controller::~Controller() {
	delete board;
}



// Main Gameplay loop.

void Controller::play() {
	cout << "Welcome to Nested Tic Tac Tow" << endl;
	cout << "Player one is X and Plauer two is O" << endl;
	cout << "navigate using the following:" << endl;
	cout << "ul to play in the upper left cell" << endl;
	cout << "um to play in the upper middle cell" << endl;
	cout << "ur to play in the upper right cell" << endl;
	cout << "ml to play in the middle left cell" << endl;
	cout << "mm to play in the middle cell" << endl;
	cout << "mr to play in the middle right cell" << endl;
	cout << "ll to play in the lower left cell" << endl;
	cout << "lm to play in the lower middle cell" << endl;
	cout << "lr to play in the lower right cell\n" << endl;
	string input;

	delete board; // if board exists, delete it
	this->board = new Board;
	// print action here
	this->board->reset();
	this->board->setup();
	this->board->print();
	while(getline(cin, input)) {
		if (input == "q") {
			cout << "Quitting Game..." << endl;
			return;
			/* to do Mohammed */
			// Add save game in a file option
		} else {
			cout << endl;
			this->board->recive_action(input);
		}
		if(this->board->has_ended()) {break;}
	}
	if(this->board->has_ended())
		cout << "You have won the game." <<endl;	
}			
