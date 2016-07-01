#include"board.h"
#include"grid.h"
#include<iostream>
#include<string>
using namespace std;



// ctor
Board::Board(){

}

// dtor
Board::~Board(){
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			delete grids[i][j];
		}
	}
}



//rest
void Board::reset() {
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++) {
			grids[i][j] = new Grid;
			grids[i][j]->reset();
		}
	}
	current_grid_x = 1;
	current_grid_y = 1;
	grids[1][1]->set_current();
	turn = 'X'; 
}
void Board::setup() {
	for (int i = 0; i < 17; ++i) {
		for(int j = 0; j < 29; ++j) {
			if (i % 2 == 0) { // if i is even
				int ones = j % 10;
				int tens = j / 10;
				if ( tens == 0 ) {
					if (ones == 0 || ones == 4 || ones == 8) {
						if( i == 0 || i == 2 || i == 4) {
							textDisplay[i][j] = grids[0][0]->get_char_print(i, ones);
						} else if ( i == 6 || i == 8 || i == 10) {
							textDisplay[i][j] = grids[1][0]->get_char_print(i, ones);
						} else if ( i == 12 || i == 14 || i == 16) {
							textDisplay[i][j] = grids[2][0]->get_char_print(i, ones);
						} else {
							textDisplay[i][j] = ' ';
						}
					} else { 
						if (j == 9 || j == 19) {
							textDisplay[i][j] = '	';
						} else { textDisplay[i][j] = ' ';}
					}

				} else if ( tens == 1 ) {
					if (ones == 0 || ones == 4 || ones == 8) {
						if( i == 0 || i == 2 || i == 4) {
							textDisplay[i][j] = grids[0][1]->get_char_print(i, ones);
						} else if ( i == 6 || i == 8 || i == 10) {
							textDisplay[i][j] = grids[1][1]->get_char_print(i, ones);
						} else if ( i == 12 || i == 14 || i == 16) {
							textDisplay[i][j] = grids[2][1]->get_char_print(i, ones);
						} else {
							textDisplay[i][j] = ' ';
						} 
					} else {if (j == 9 || j == 19) {
						textDisplay[i][j] ='	';
					} else { textDisplay[i][j] = ' ';}
					} 
				} else if ( tens == 2 ) {
					if (ones == 0 || ones == 4 || ones == 8) {
						if( i == 0 || i == 2 || i == 4) {
							textDisplay[i][j] = grids[0][2]->get_char_print(i, ones);
						} else if ( i == 6 || i == 8 || i == 10) {
							textDisplay[i][j] = grids[1][2]->get_char_print(i, ones);
						} else if ( i == 12 || i == 14 || i == 16) {
							textDisplay[i][j] = grids[2][2]->get_char_print(i, ones);
							//	int m = 5;
						} else {
							textDisplay[i][j] = ' ';
						}
					} else {if(j == 9 || j == 19) {
						textDisplay[i][j]='	';
					} else { textDisplay[i][j] = ' '; }

					}
				}
			} else { 
				if (j == 9 || j == 19) {
					textDisplay[i][j] = '	';
				} else if ( i == 5 || i == 11) {
					textDisplay[i][j] = '-';
				} else { textDisplay[i][j] = ' ';}
			}
		}	
	}
	//grids[2][2].print();
}


void Board::print() {
	for (int i = 0; i < 17; ++i) {
		for(int j = 0; j < 29; ++j) {
			cout << textDisplay[i][j];
		}
		cout << endl;
	}
}


bool Board::check_win_game() {

	// check rows 
	switch(current_grid_x)  {
		case 0 :
			if(results[0][0]== this->turn && results[0][1]==this->turn && results[0][2] == this->turn)
				return true;
			break;
		case 1 :
			if(results[1][0]==this->turn&&results[1][1]== this->turn && results[1][2]==this->turn)
				return true;
			break;
		case 2 :
			if(results[2][0]==this->turn&&results[2][1]== this->turn && results[2][2]==this->turn)
				return true;
			break;
	}
        // check columns 
	switch(current_grid_y)  {
		case 0 :
			if(results[0][0] == this->turn && results[1][0]== this->turn && results[2][0]==this->turn)
				return true;
			break;
		case 1 :
			if(results[0][1]== this->turn && results[1][1]== this->turn && results[2][1]==this->turn)
				return true;
			break;
		case 2 :
      if(results[0][2] == this->turn && results[1][2]== this->turn && results[2][2]==this->turn)
				return true;
			break;
	}
        // check diagonals 
	if(current_grid_x==current_grid_y)  {
		if(results[0][0]==this->turn && results[1][1]== this->turn && results[2][2]==this->turn)
				return true;
			
	}
	if((current_grid_x + current_grid_y)==2)  {
		if(results[0][2]==this->turn && results[1][1]== this->turn && results[2][0]==this->turn)
				return true;
	}
	return false;
}

bool Board::has_ended()  {
	return this->ended;
}

void Board::recive_action(string action) {
	this->grids[current_grid_y][current_grid_x]->play_turn(this->turn, action);
  cout << this->results[current_grid_y][current_grid_x]<<endl;
        if(!this->results[current_grid_y][current_grid_x])  {
		this->results[current_grid_y][current_grid_x] = this->grids[current_grid_y][current_grid_x]->check_win_grid(this->turn, action);
        	if(this->results[current_grid_y][current_grid_x])  {
	        	this->ended = this->check_win_game();
		}
	}
   
	this->grids[current_grid_y][current_grid_x]->rem_current();
	change_turn(this->turn);
	if (action[0] == 'u') { current_grid_y = 0;}
	if (action[0] == 'm') { current_grid_y = 1;}
	if (action[0] == 'l') { current_grid_y = 2;}
	if (action[1] == 'l') { current_grid_x = 0;}
	if (action[1] == 'm') { current_grid_x = 1;}
	if (action[1] == 'r') { current_grid_x = 2;}
	this->grids[current_grid_y][current_grid_x]->set_current();	
	setup();
	print();
}







void Board::change_turn(char turn) {
	if (turn == 'X') { this->turn = 'O';}
	else { this->turn = 'X';}
}
