/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Offspring.h
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
#include <vector>

using namespace std;

class Offspring
{
private:
	vector<char*> children; //vector of character arrays indicating genotype

public:
	Offspring(void); //constructor
	~Offspring(void); //destructor

	void addChild(char newChild[12]);
};

