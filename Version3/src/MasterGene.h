/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: MasterGene.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class MasterGene
{

private:
	char name[32]; //trait name
	char domDesc[32]; //dominant trait appearance
	char domSym; //dominant trait symbol
	char recDesc[32]; //recessive trait appearance
	char recSym; //recessive trait symbol
	double crossOver; //likelihood that a crossover will occur for this gene

public:
	MasterGene(void); //constructor
	~MasterGene(void); //destructor

	void setTrait(char *trait);
	void setDomDesc(char *description);
	void setDomSym(char symbol);
	void setRecDesc(char *description);
	void setRecSym(char symbol);
	void setCross (double cross);
	string getTrait();
	string getDomDesc();
	char getDomSym();
	string getRecDesc();
	char getRecSym();
	double getCross();

};

