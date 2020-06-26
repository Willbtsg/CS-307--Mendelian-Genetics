/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: Chromosome.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma once
#include "Gene.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

class Chromosome
{

private:
	char strands[2][12]; //2d array used to store strands
	vector<Gene> GeneList; //vector of Gene objects corresponding to the strands

public:
	Chromosome(); //constructor
	~Chromosome(); //destructor 
	void copyStrands(char *strand1, char *strand2); //copies strand data to Chromosome
	void addGene(Gene *newGene);
	int getGeneListSize();
	string passGeneName(int geneNum);
	string getAlleleInfo(int geneNum);
	char getAllele(int strandNum, int geneNum, bool *crossCheck); //returns an allele for use in reproduction
};

