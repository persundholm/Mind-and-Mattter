/*
 * Turn.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: per
 */

#include "Turn.h"
#include <iostream>


int Turn::distance=10;	//initial distance


Turn::Turn(Player* p, Player* o)
	: activePlayer(p), opponent(o)
{

}

Turn::~Turn() {
	// TODO Auto-generated destructor stub
}


Turn::movePhaseActions Turn::interpretUserInputBeginningPhase(char userInput)
{
	switch(userInput)
	{
	case 'b':
		return movePhaseActions::MOVE_BACK;
	case 'f':
		return movePhaseActions::MOVE_FORWARD;
	case 's':
		return movePhaseActions::STAY;
	default:
		return movePhaseActions::NO_ACTION;
	}
}


Turn::attackPhaseActions Turn::interpretUserInputAttackPhase(char userInput)
{
	switch(userInput)
	{
	case 'y':
		return attackPhaseActions::ATTACK;
	case 'n':
		return attackPhaseActions::DONT_ATTACK;
	default:
		return attackPhaseActions::NO_ACTION;
	}
}


void Turn::subtractDistance(int subtraction)
{
	distance=distance-subtraction;

	//Do not allow for negative distance
	if(distance<0)
		distance=0;
}


void Turn::beginningPhase()
{
	//TODO dra kort funktionalitet
}

void Turn::mainPhase()
{
	//TODO Play cards
}


void Turn::movePhase()
{




	bool badUserInput{false};
	do
	{

		//Receive user command
		std::cout << "Do you wish to move forward(f), back(b) or stay(s)?" << std::endl;
		char movementInput;
		std::cin >> movementInput;
		movePhaseActions command = interpretUserInputBeginningPhase(movementInput);

		//execute user command
			switch(command)
			{
			case movePhaseActions::MOVE_BACK:
				distance=distance+activePlayer->getMovement();
				badUserInput=false;
				break;
			case movePhaseActions::MOVE_FORWARD:
				subtractDistance(activePlayer->getMovement());
				badUserInput=false;
				break;
			case movePhaseActions::STAY:
				badUserInput=false;
				break;
			default:
				std::cout << "Not a valid input; please try again" << std::endl;
				badUserInput=true;
				break;
			}
	}while(badUserInput);


	//Reduce distance default during movement phase
	subtractDistance(1);
	std::cout << "Distance to opponent is now " << distance << std::endl;

}


void Turn::attackPhase()
{


if(distance<1)
{



	bool badUserInput{false};
	do
	{

		//Receive user command
		std::cout << "Do you wish to attack? (y/n)" << std::endl;
		char attackInput;
		std::cin >> attackInput;
		attackPhaseActions command = interpretUserInputAttackPhase(attackInput);

		//execute user command
			switch(command)
			{
			case attackPhaseActions::ATTACK:
				opponent->subtractHealth(activePlayer->getAttack());
				badUserInput=false;
				break;
			case attackPhaseActions::DONT_ATTACK:
				badUserInput=false;
				break;
			default:
				std::cout << "Not a valid input; please try again" << std::endl;
				badUserInput=true;
				break;
			}
	}while(badUserInput);


	std::cout << "Opponent's health is now " << opponent->getHealth() << std::endl;


}

		/*std::cout << "Do you wish to attack? (a)" << std::endl;
		char movementInput;
		std::cin >> movementInput;
		attackPhaseActions command = interpretUserInputAttackPhase(movementInput);

		switch(command)
		{
		case attackPhaseActions::ATTACK:
			std::cout << "Aj!";
			break;
		case attackPhaseActions::NO_ACTION:
		}*/



}

void Turn::endPhase()
{

}


void Turn::makeTurn()
{
	beginningPhase();
	mainPhase();
	movePhase();
	attackPhase();
	endPhase();
}



