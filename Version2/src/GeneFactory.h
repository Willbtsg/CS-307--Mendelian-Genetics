/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: GeneFactory.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
/*******************************************************************
*	This program was modified post-submission on 6/26/2020 to
*	fix errors present in the release version of the executable.
*******************************************************************/
#pragma once

#include "MasterGene.h"
#include "Gene.h"

class GeneFactory
{

private:
	static GeneFactory *instance; //instance for singleton implementation
	GeneFactory(); //private constructor

public:
	static GeneFactory* getInstance(); //returns instance of Singleton object
	~GeneFactory(); //destructor

	MasterGene* createMasterGene(); //creates new MasterGene object
	Gene* createGene(char *allele1, char *allele2); //creates new Gene object
};

