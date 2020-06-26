/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: ParenFactory.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma once

#include "Parent.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

class ParentFactory
{

private:
	static ParentFactory* instance; //instance for Singleton implementation
	ParentFactory(); //private conctructor

public:
	static ParentFactory* getInstance(); //returns instance of Singleton object
	~ParentFactory(); //destructor
	Parent* createParent(int parentNum); //creates new Parent object
};

