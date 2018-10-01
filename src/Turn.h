/*
 * Turn.h
 *
 *  Created on: Sep 11, 2018
 *      Author: per
 */

#include "Player.h"

#ifndef TURN_H_
#define TURN_H_



class Turn {

public:
	Turn(Player* p, Player* o);

	virtual ~Turn();

	enum class phase
		{
			MOVE_PHASE,
			MAIN_PHASE,
			ATTACK_PHASE,
			END_PHASE
		};

	enum class movePhaseActions
	{
		MOVE_BACK,
		STAY,
		MOVE_FORWARD,
		NO_ACTION
	};

	enum class attackPhaseActions
		{
			ATTACK,
			DONT_ATTACK,
			NO_ACTION
		};

	enum class mainPhaseActions
			{
				PLAY_CARD,
				DONE,
				NO_ACTION
			};

	void beginningPhase();
	void mainPhase();
	void movePhase();
	void attackPhase();
	void endPhase();

	int static getDistance()
	{
		return distance;
	}
	movePhaseActions interpretUserInputBeginningPhase(char userInput);
	attackPhaseActions interpretUserInputAttackPhase(char userInput);
	mainPhaseActions interpretUserInputMainPhase(char userInput);

	void makeTurn();

private:

	//Attributes
	Player* activePlayer;
	Player* opponent;
	static int distance;
	bool hasPlayedElementCard{false};



	//Functions
	void subtractDistance(int subtraction);






};


#endif /* TURN_H_ */
