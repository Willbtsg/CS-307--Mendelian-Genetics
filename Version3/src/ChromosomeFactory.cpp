/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: ChromosomeFactory.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
/*******************************************************************
*	This program was modified post-submission on 6/26/2020 to
*	fix errors present in the release version of the executable.
*******************************************************************/
#include "stdafx.h"
#include "ChromosomeFactory.h"
#include "GeneFactory.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

ChromosomeFactory* ChromosomeFactory::instance = NULL; //sets instance to NULL until constructor getInstance is called for the first time

//-----------------------------------
// Constructor
//-----------------------------------
ChromosomeFactory::ChromosomeFactory()
{
}

//----------------------------------------
// returns instance of ChromosomeFactory
//----------------------------------------
ChromosomeFactory* ChromosomeFactory::getInstance()
{
	if (instance == NULL)
	{
		instance = new ChromosomeFactory();
	}

	return instance;
}

//-----------------------------------
// Destructor
//-----------------------------------
ChromosomeFactory::~ChromosomeFactory()
{
}

//----------------------------------------------------------------
// returns pointer to new Chromosome object
//
// Arguments:
//
// strand1- pointer to array of characters representing
//		    genetic information
// strand2- pointer to array of characters representing
//		    genetic information
//-----------------------------------------------------------------
Chromosome* ChromosomeFactory::createChromosome(char *strand1, char *strand2)
{
	Chromosome *newChromosome = new Chromosome(); //create new Chromosome object
	GeneFactory *GFactory = GeneFactory::getInstance(); //get instance of GeneFactory
	
	int i = 0;
	char *ch1 = NULL; //used for first allele data
	char *ch2 = NULL; //used for second allele data
	bool done = false; 

	newChromosome->copyStrands(strand1, strand2);
	ch1 = &strand1[i]; //get first character from second strand
	ch2 = &strand2[i]; //get first character from second strand

	while (!done) //until there are no more characters representing genetic data
	{
		newChromosome->addGene(GFactory->createGene(ch1, ch2)); //create a new Gene object using the GeneFactory and add it to the Chromosome

		i += 2;
		ch1 = &strand1[i]; //see if the new indices in the strands point to characters for genetic data (i.e. letters)
		ch2 = &strand2[i];
		if ((int)*ch1 < 65 || (int)*ch2 < 65) //if they don't...
		{
			done = true; //...set done to true and exit at bottom of loop
		}
	}

	return newChromosome;
}