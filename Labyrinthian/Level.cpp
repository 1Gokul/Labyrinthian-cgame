#include "stdafx.h"
#include "Level.h"

#include <fstream>
#include<string>

const std::string levelLink = "http://www.delorie.com/game-room/mazes/";
								/*Still learning on how to generate mazes on my own, but temporarily I have taken 
								mazes from this website. Is this the proper way to give credit or should i do it another way?
								*/
Level::Level()
{
}


Level::~Level()
{
}

void Level::loadLevel(std::string fileName)
{
	_levelData.clear();		// Clears the content of the previous level, if any


	std::ifstream file;

	file.open(fileName);

	if (file.fail()) {			//If the level file cannot open.

		perror(fileName.c_str());
		system("pause");
		exit(1);
	}

	std::string line;


	while (std::getline(file, line)) {

		_levelData.push_back(line);			// Puts content of text file to _levelData.
	}

	file.close();


								
	findPlayer();					//Find player's initial position

}

void Level::printLevel()
{

	for (int i = 0; i < _levelData.size(); i++) {

		printf("%s\n", _levelData[i].c_str());

	}

	printf("\nMaze taken from- %s\n", levelLink.c_str());	//Credit to DJ Delorie, from whose website I got the mazes.

}

bool Level::updatePlayer(char imove)
{
	findPlayer();

	int prevPlayerX = playerX;
	int prevPlayerY = playerY;

	if		(imove == 'w')playerY--;
	else if (imove == 's')playerY++;
	else if (imove == 'a')playerX--;
	else if (imove == 'd')playerX++;


	if (getTile(playerX, playerY) != '-'		//Checking if next position coincides with a wall.
		&& getTile(playerX, playerY) != '+'
		&& getTile(playerX , playerY) != '|') {

		if (getTile(playerX, playerY) == DESTINATION_CHAR)return true;	//If the player passes the level.

	else {
		movePlayer(prevPlayerX, prevPlayerY); //actually sending the previous coordinates so that the previous
											//position of the player will become an empty tile.
	}

	}
	
	
	return false;
}

void Level::findPlayer()
{

	for (int i = 0; i < _levelData.size(); i++)for (int j = 0; j < _levelData[i].size(); j++) {

		if (getTile(j, i) == PLAYER_CHAR) {

			playerX = j;
			playerY = i;
		}
	}

	

}

char Level::getTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::movePlayer(int x, int y)
{
	_levelData[playerY][playerX] = PLAYER_CHAR;
	_levelData[y][x] = EMPTY_CHAR;	//Remove previous position of player.
}






