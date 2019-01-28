#pragma once
#include "Specimen.h"
#include <vector>

using namespace std;

class Population
{
	int size;
	vector <Specimen> population;
	int **matrix;
	int matrixSize;
public:
	Population(int, int **,int);
	~Population();
	void sortPopulation();
	void mutateRandomSpecimen();
	void crossover();
	void randomCrossover();
	void selection();
	void displayBest();
};

