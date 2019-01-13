#pragma once

#include "Level.h"

#include <iostream>
#include<string>
#include<stdlib.h>


class game
{
public:
	game();
	~game();

	void menu();	///< Main menu of the game.
	
	void startLevel();	///< Sets up level and starts the game.
	
	void gameLoop();	///< The main function, in which the gameloop exists.

	void ending();		///< Executres when the Player wins or chooses to exit the game.

	void cls()		///< To make calling easier. Still havent found an alternative, though
	{
		system("cls");
	}

	void loadingAnimation(); ///<The LOADING sign with dots appearing, just to make it look nice.


private:

	Level L_obj;		///< Object of class level.
						/*To the person reading this, can you tell me whether I should use a pointer to an object?
						How would it help?             */
	

	int _currentLevel;	///< current level of the player.

	


	char move;		///< Move entered by the player.
};

