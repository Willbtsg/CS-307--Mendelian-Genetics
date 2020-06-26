/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: ChromosomeFactory.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma once
#include "Chromosome.h"

class ChromosomeFactory
{
private:
	static ChromosomeFactory* instance; //keep track of instance for Singleton
	ChromosomeFactory(); //consturctor
	
public:
	static ChromosomeFactory* getInstance(); //returns instance of Singleton object
	~ChromosomeFactory(); //destructor
	Chromosome* ChromosomeFactory::createChromosome(char *strand1, char *strand2); //creates new Chromosome object
};

