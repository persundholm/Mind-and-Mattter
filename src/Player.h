/*
 * Player.h
 *
 *  Created on: Sep 10, 2018
 *      Author: per
 */
#include "Deck.h"


#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
public:
	Player();
	virtual ~Player();

	int getHealth()
	{
		return health;
	}
	int getAttack()
	{
		return attack;
	}
	int getMovement()
	{
		return movement;
	}
	void subtractHealth(int damage)
	{
		health=health-damage;
	}


private:
	Deck deck;
	int health{20};
	int attack{2};
	int movement{1};
};

#endif /* PLAYER_H_ */
