/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Main.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "Simulation.h"

using namespace std;

int main(void)
{

	Simulation Genetics; //instantiate a simulation object
	
	Genetics.initializeSimulation(); //set up the simulation
	Genetics.runSimulation(); //run the simulation

	system("pause");
	return 0;
}