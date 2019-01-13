#pragma once

#include<vector>
#include<string>


const char PLAYER_CHAR = 'G';		///< the player is labeled as 'G' in the game.
const char EMPTY_CHAR = ' ';	   ///< char for an empty space.
const char DESTINATION_CHAR = 'O';

class Level
{
public:
	Level();
	~Level();

	void loadLevel(std::string fileName);		///< Loads the level from the text file.

	void printLevel();							///< Prints out the level. Used in the gameLoop() function of class game

	bool updatePlayer(char imove);				///< Updates position of the player depending on the input.

	void findPlayer();							///< Finds the player's position and updates the x and y coordinates to playerX and playerY.

	char getTile(int x, int y);					///< Gets the character at the position (x,y).

	void movePlayer(int x, int y);				///< Sets the new position of the player while removing their previous position.
	
	

private:

	
	int playerX;			///< X coordinate of the player.
	int playerY;			///< Y coordinate of the player.

	std::vector<std::string> _levelData;		///< Vector of strings holding all the data from the current level's text file.
};

