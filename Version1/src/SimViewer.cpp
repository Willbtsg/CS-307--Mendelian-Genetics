/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: SimViewer.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "SimViewer.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
SimViewer::SimViewer()
{

}

//-----------------------------------
// Destructor
//-----------------------------------
SimViewer::~SimViewer()
{

}

//----------------------------------------------------
// prints message to user
// 
// Argument:
//
// message- contains message to be output to screen
//
//----------------------------------------------------
void SimViewer::printMessage(string message)
{

	cout << message << endl;

	return;
}

//----------------------------------------
// returns user text input to the program
//----------------------------------------
string SimViewer::returnText()
{
	string input;

	cin >> input;

	return input;
}

//------------------------------------------
// returns user number input to the program
//
// Argument:
//
// *count- pointer to an integer variable
//  that will hold user input
//------------------------------------------
void SimViewer::returnNumber(int *count)
{
	cout << "==>";
	cin >> *count;

	return;
}