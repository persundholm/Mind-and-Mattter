/*
 * GameSession.h
 *
 *  Created on: Sep 10, 2018
 *      Author: per
 */

#include "Player.h"

#ifndef GAMESESSION_H_
#define GAMESESSION_H_

class Game_Session {
public:
	Game_Session();
	virtual ~Game_Session();

	void runGame();

	Player getPlayer1()
	{
		return player1;
	}
	Player getPlayer2()
	{
		return player2;
	}


	bool getIsGameActive()
	{
		return isGameActive;
	}
	void gameOver()
	{
		isGameActive=false;
	}

private:
	int distance{10};
	Player player1;
	Player player2;
	bool isGameActive{true};
};

#endif /* GAMESESSION_H_ */
