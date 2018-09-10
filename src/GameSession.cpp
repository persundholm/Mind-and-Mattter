/*
 * GameSession.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: per
 */

#include "GameSession.h"
#include <stdio.h>
#include <iostream>

Game_Session::Game_Session() {
	// TODO Auto-generated constructor stub

}

Game_Session::~Game_Session() {
	// TODO Auto-generated destructor stub
}


void Game_Session::runGame()
{
	using namespace std;
	cout << "Welcome to the Mind and Matter alpha!" << endl << "##############################" << endl << endl;

	do
	{
		Player player1=getPlayer1();
		cout << "Your health is " << player1.getHealth();
		gameOver();
	}
	while(getIsGameActive());

}
