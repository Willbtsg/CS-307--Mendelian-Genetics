/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Offspring.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
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
// add string to children vector
//
// Argument:
//
// newChild- string containing genotype to be added to vector
//
//----------------------------------------------------------------------
void Offspring::addChild(string newChild)
{
	children.push_back(newChild);

	return;
}