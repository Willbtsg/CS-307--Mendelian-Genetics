/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Offspring.h
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
#include <vector>

using namespace std;

class Offspring
{
private:
	vector<string> children; //vector of strings indicating genotype

public:
	Offspring(void); //constructor
	~Offspring(void); //destructor

	void addChild(string newChild);
};

