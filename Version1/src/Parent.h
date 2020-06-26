/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Parent.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
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

using namespace std;

class Parent
{

private:

	vector<Gene> GeneList; //vector of Gene objects based on Parent's genotype

	char scientificName[32]; //holds genus and species in one array
	char commonName[32]; //holds common name of organism
	char genotype[12]; //holds organism genotype

public:
	Parent(void); //constructor
	~Parent(void); //destructor

	void setScientificName(char *sciName);
	void setCommonName(char *comName);
	void setGenotype(char *newGeno);
	string getScientificName();
	string getCommonName();
	void addGene(Gene newGene);
	char passGene(int geneNum); //gets allele from Gene for cross-pollination
	string getAlleles(int i); //outputs allele pair for Gene at index i
	int getGeneListSize();
	string getGeneName(int i); //gets name of trait that a Gene controls
};

