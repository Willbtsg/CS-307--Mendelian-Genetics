/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SimViewer.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class SimViewer
{
public:
	SimViewer(void); //constructor
	~SimViewer(void); //destructor

	void printMessage(string message); //used to print a string to the screen
	string returnText(); //gets user input for text
	void returnNumber(int *count); //gets user input for numbers
};

