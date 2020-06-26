/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Offspring.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "Offspring.h"

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Offspring::Offspring()
{

}

//-----------------------------------
// Destructor
//-----------------------------------
Offspring::~Offspring()
{

}

//----------------------------------------------------------------------
// add character array to children vector
//
// Argument:
//
// newChild- character array containing genotype to be added to vector
//
//----------------------------------------------------------------------
void Offspring::addChild(char newChild[12])
{
	children.push_back(newChild);

	return;
}