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

	enum class playersTurn
	{
		PLAYER_ONE,
		PLAYER_TWO
	};

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

	Player* getActivePlayer();

	Player* getUnActivePlayer();

	void refreshAcitvePlayer();

	bool getIsGameActive()
	{
		return isGameActive;
	}
	void setGameStatus();





private:
	Player player1;
	Player player2;
	playersTurn activePlayer{playersTurn::PLAYER_ONE};
	playersTurn unActivePlayer{playersTurn::PLAYER_TWO};
	bool isGameActive{true};

};

#endif /* GAMESESSION_H_ */
