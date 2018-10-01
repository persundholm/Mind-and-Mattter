/*
 * GameSession.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: per
 */

#include "GameSession.h"
#include <stdio.h>
#include <iostream>
#include "Turn.h"

Game_Session::Game_Session()
{

}

Game_Session::~Game_Session() {
	// TODO Auto-generated destructor stub
}

void Game_Session::setGameStatus()
{
	if(player1.getIsAlive() & player2.getIsAlive())
		isGameActive=true;
	else
		isGameActive=false;

}

Player* Game_Session::getActivePlayer()
{
	if(activePlayer==playersTurn::PLAYER_ONE)
		return &player1;
	else
		return &player2;
}

Player* Game_Session::getUnActivePlayer()
{
	if(activePlayer==playersTurn::PLAYER_ONE)
		return &player2;
	else
		return &player1;
}


void Game_Session::refreshAcitvePlayer()
{
	if(activePlayer==playersTurn::PLAYER_ONE)
	{
		activePlayer=playersTurn::PLAYER_TWO;
		unActivePlayer=playersTurn::PLAYER_ONE;
	}

	else
	{
		activePlayer=playersTurn::PLAYER_ONE;
		unActivePlayer=playersTurn::PLAYER_TWO;
	}
};


void Game_Session::runGame()
{
	using namespace std;
	cout << "Welcome to the Mind and Matter alpha!" << endl << "##############################" << endl << endl;

	do
	{
		//Get active player
		Player *player=getActivePlayer();
		Player *opponent=getUnActivePlayer();

		//Print status
		if(activePlayer==playersTurn::PLAYER_ONE)
			cout << "Player one's turn" << endl;
		else
			cout << "Player two's turn" << endl;

		cout << "Your health is " << player->getHealth() << endl;
		cout << "Your attack is " << player->getAttack() << endl;
		cout << "Your opponent's health is " << opponent->getHealth() << endl;
		cout << "Your opponent's attack is " << opponent->getAttack() << endl;
		cout << "Distance to opponent is " << Turn::getDistance() << endl;
		//Make turn
		Turn playersTurn=Turn(player,opponent);
		playersTurn.makeTurn();
		refreshAcitvePlayer();
		setGameStatus();
	}
	while(getIsGameActive());

}
