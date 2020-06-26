/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Parent.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma once
#include "Chromosome.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Parent
{

private:

	char scientificName[32]; //holds genus and species in one array
	char commonName[32]; //holds common name of organism

	vector<Chromosome> ChromosomeList; //vector of Gene objects based on Parent's genotype

public:
	Parent(void); //constructor
	~Parent(void); //destructor

	void setScientificName(char *sciName);
	void setCommonName(char *comName);
	string getScientificName();
	string getCommonName();
	void addChromosome(Chromosome *newChromosome);
	char passGene(int chromosomeNum, int strandNum, int geneNum, bool *crossCheck); //gets allele from Chromosome for reproduction
	int getChromosomeListSize();
	string getGeneName(int chromosomeNum, int geneNum); //gets name of trait that a Gene controls
	int getGeneListSize(int chromosomeNum);
	string getAlleleInfo(int chromosomeNum, int geneNum);
};

