/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Chromosome.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "Chromosome.h"

//-----------------------------------
// Constructor
//-----------------------------------
Chromosome::Chromosome()
{

}

//-----------------------------------
// Destructor
//-----------------------------------
Chromosome::~Chromosome()
{
}

//-----------------------------------
// adds new Gene to GeneList
//-----------------------------------
void Chromosome::addGene(Gene *newGene)
{
	GeneList.push_back(*newGene);
}

//----------------------------------------------------
// copies strands into Chromosome object
//
// Arguments:
//
// strand1- character array containing first strand
// strand2- character array containing second strand
//----------------------------------------------------
void Chromosome::copyStrands(char *strand1, char *strand2)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 12; i++)
	{
		strands[0][i] = strand1[j];
		j += 2;
	}

	j = 0;
	for (i = 0; i < 12; i++)
	{
		strands[1][i] = strand2[j];
		j += 2;
	}
	
}

//-----------------------------------
// returns GeneList size
//-----------------------------------
int Chromosome::getGeneListSize()
{
	return GeneList.size();
}

//----------------------------------------------------
// returns name of trait controlled by Gene
//
// Arguments:
//
// geneNum- which index of GeneList to get data from
//----------------------------------------------------
string Chromosome::passGeneName(int geneNum)
{
	return GeneList[geneNum].passName();
}

//-------------------------------------------------------------------
// returns information about alleles from a Gene
//
// Arguments:
//
// geneNum- which index of the GeneList to use
//
//-------------------------------------------------------------------
string Chromosome::getAlleleInfo(int geneNum)
{
	return GeneList[geneNum].getAlleleInfo();
}

//--------------------------------------------------------------------------------
// returns allele from Gene
//
// Argument: 
//
// strandNum- which strand to return an allele from if a crossover doesn't occur
// geneNum- index of GeneList to get an allele from
// crossCheck- pointer to a bool set to true if a crossover occurs
//
//--------------------------------------------------------------------------------
char Chromosome::getAllele(int strandNum, int geneNum, bool *crossCheck)
{
	char allele = strands[strandNum][geneNum];

	return GeneList[geneNum].getAllele(allele, crossCheck);
}