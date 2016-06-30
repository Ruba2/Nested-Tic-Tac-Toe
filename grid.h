#ifndef GRID_H
#define GRID_H
#include<string>
class Grid{
        char cells[3][3];
	bool current;
        public:
        Grid();
        ~Grid();
        void print();
        void reset();
	char get_char_print(int, int);
	void play_turn(char, std::string);
	void set_current();
	void rem_current(); 
};

#endif
