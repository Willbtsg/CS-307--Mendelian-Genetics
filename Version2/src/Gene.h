/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Gene.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
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
#include <stdlib.h>
#include "MasterGene.h"

using namespace std;

class Gene
{
private:
	char alleles[2];
	MasterGene *source; //pointer to MasterGene containing information about trait this Gene controls

public:
	Gene(void); //constructor
	~Gene(void); //destructor

	void setMG(MasterGene *master);
	void setAlleles(char pass1, char pass2);
	char getAllele(char allele, bool *crossCheck); //returns an allele for use in reproduction
	string getAlleleInfo();
	string passName(); //returns name of trait from source
};

