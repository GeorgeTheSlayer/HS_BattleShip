#include "Ships.h"
#include <cstdlib>
#include <iostream>
using namespace std;

static const int MAX_X = 16;
static const int MAX_Y = 16;
static const int NUM_SHIPS = 10;

int gameBoard[MAX_X][MAX_Y] = {0}; 

void testPrint(){
	for (int x = 0; x < MAX_X; x++){
		for (int y = 0; y < MAX_Y; y++){
			cout << gameBoard[y][x];
			cout << " ";
		}
		cout << "\n";
	}
}

void initBoard(){
	srand(time(0));
	for (int i = 0; i < NUM_SHIPS; i++){
		bool repeatStep = true;
		while (repeatStep){
			int indexValX = rand() % MAX_X;
			int indexValY = rand() % MAX_Y;
			
			if (gameBoard[indexValX][indexValY] == 0){
				gameBoard[indexValX][indexValY] = 1;
				repeatStep = false;
			}

		}
	}
}

int fire(const int loc_x, const int loc_y){
	if (gameBoard[loc_x - 1][loc_y - 1] == 1){
		gameBoard[loc_x - 1][loc_y - 1] = 0;
		return 1;
	}

	if (check(loc_x - 1, loc_y - 1) == 1)
		return 2;
	
	return 0;
}

int check(const int loc_x, const int loc_y){
	int cordX[3][3];
	int cordY[3][3];

	for (int x = 0; x < 3; x++){
		for (int y = 0; y < 3; y++){
			cordX[x][y] = loc_x + (x - 1);
			cordY[x][y] = loc_y + (y - 1);

			if (cordX[x][y] > MAX_X - 1 || cordY[x][y] < 0)
				cordX[x][y] = loc_x;

			if (cordY[x][y] > MAX_Y - 1 || cordY[x][y] < 0)
				cordY[x][y] = loc_y;
		}
	}

	for (int x = 0; x < 3; x++){
		for (int y = 0; y < 3; y++){
			int x_cord = cordX[x][y];
			int y_cord = cordY[x][y];

			if (gameBoard[x_cord][y_cord] == 1)
				return 1;
		}
	}

	return 0;
}

int scan(){
	int counter = 1;
	for (int x = 0; x < MAX_X - 1; x++){
		for (int y = 0; y < MAX_Y - 1; y++){
			if (gameBoard[x][y] == 1){
				counter++;
			}
		}
	}

	return counter;
}

