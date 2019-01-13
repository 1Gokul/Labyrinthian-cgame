#include "stdafx.h"

#include "game.h"

#include<iostream>
#include<conio.h>
#include<Windows.h>

game::game() :
	_currentLevel(1)
{
}


game::~game()
{
}

void game::menu()		
{
	cls();
	
		std::cout << "\t\t\t\tLABYRITHIAN\n\n\t\t\t\tBy: Gokul Viswanath (https://github.com/1Gokul)\n"<<std::endl;
		std::cout << "\n\n\t\t\t\tG to start\n\t\t\t\tS for controls";

	char ch = _getch(); //Using _getch() as i feel pressing enter each time is a bit tedious.

		if (ch == 'G' || ch == 'g')startLevel();	//Set up the game and start

		else if (ch == 'S' || ch == 's') {		//show controls (Basic WASD)

			cls();

			std::cout << "\n\n\t\t\t    |W|\n\t\t\t|A| |S| |D|\n\n"
				"W to move up\nA to move left\nS to move down\nD to move right\n\n";

			std::cout << "\n\n\n  <-- Back to Main Menu  (Tap any key)";
			_getch();
		
			menu();
		}

		else menu();

	
}


void game::startLevel()
{
	loadingAnimation();	

	if (_currentLevel == 1) {

		L_obj.loadLevel("Levels/level1.txt");
	}
	else if (_currentLevel == 2) {

		L_obj.loadLevel("Levels/level2.txt");
	}
	else if(_currentLevel == 3) {

		L_obj.loadLevel("Levels/level3.txt");
	}
	else if (_currentLevel == 4) {

		L_obj.loadLevel("Levels/level4.txt");
	}
	else if (_currentLevel == 5) {

		L_obj.loadLevel("Levels/level5.txt");
	}

	gameLoop();
}



void game::gameLoop()
{
	
	bool passedLevel = false;
	
	for (;;) {
		cls();

		L_obj.printLevel();

		std::cout << "\nPress 'C' for controls or 'Z' to exit.\n\nEnter your move. ";
		move = _getch();

		tolower(move);		//Lowers case of input character.
		

		if (move == 'w' || move == 's' || move == 'a' || move == 'd') {

			passedLevel = L_obj.updatePlayer(move);
			if (passedLevel == true) {		//If level was completed.

				cls();
				std::cout << "\n\n\n\t\t\tYou completed level " << _currentLevel;
				std::cout<< "! On to level " << _currentLevel++ << "!" << std::endl;
				system("pause");
				
				startLevel();

			}
		}

		else if(move == 'z'){	// Just in case the player hasn't pressed Z by mistake.
		
			std::cout << "\nAre you sure you want to exit? Press Y for yes or N for no.\n\n";
			char ch = _getch();
			tolower(ch);

			if (ch == 'y')ending();
			else if (ch == 'n')continue;
		}
		else {
			std::cout << "WRONG MOVE!!" << std::endl;
			system("pause");
			gameLoop();
		 }

	}

	
}

void game::ending()
{
	cls();

	std::cout << "\n\n\n\t\tThank you for playing Labyrinthian!" << std::endl << "\t\t";
	system("pause");
	exit(1);

}

void game::loadingAnimation()
{
	cls();

	std::cout << "\n\n\n\n\n\n\t\t\t\tLOADING.";
	Sleep(1000);
	std::cout << ".";
	Sleep(1000);
	std::cout << ".";
}
