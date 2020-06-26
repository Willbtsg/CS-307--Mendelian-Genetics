/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: SimViewer.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
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

