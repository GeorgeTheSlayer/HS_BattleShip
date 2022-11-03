#include <stdio.h>
#include <iostream>
#include "Ships.h"

using namespace std;

bool debugMode = true;

int playGame(){
	bool playGame = true;

	while(playGame){
	

	if (debugMode)
		testPrint();

	int x, y;
	
	cout << "Y Location: ";
	cin >> y;
	
	if(cin.fail())
		return 1;

	cout << "X Location: ";
	cin >> x;

	if (cin.fail())
		return 1;

	int ans = fire(x,y);
	
	if (ans == 1){
		cout << "HIT" << endl;
	}

	if (ans == 2)
		cout << "NEAR MISS" << endl;

	else if (ans == 0){
		cout << "MISS" << endl;
	}
	
	cout << "You have this many Ships left: " << scan() << endl;

	if (scan() == 0)
		playGame = false;

	//cout << "Press Enter to Continue: ";
	cin.get();


	do 
	 {
		 cout << '\n' << "Press a key to continue...";
	 } while (cin.get() != '\n');
	system("clear");

	}
	return 0;
}

int main(){
	
	initBoard();
//	testPrint();
	return playGame();
}


