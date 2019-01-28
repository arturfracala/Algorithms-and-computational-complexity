#include "Population.h"
#include <algorithm>
#include <iostream>

using namespace std;


Population::Population(int newSize, int **newMatrix, int newMatrixSize)
{
	size = newSize;
	matrix = newMatrix;
	matrixSize = newMatrixSize;

	Specimen *current;
	for (int i = 0; i < size; i++)
	{
		current = new Specimen(matrixSize, matrix);
		current->shuffle_chromosome();
		population.push_back(*current);
		delete current;
	}
}


Population::~Population()
{
}

void Population::sortPopulation()
{
	for (int i = 0; i < size; i++)
		for (int j = 1; j < size - i; j++) //pêtla wewnêtrzna
			if (population[j - 1].getWeight() > population[j].getWeight())
				//zamiana miejscami
				swap(population[j - 1], population[j]);
}

void Population::mutateRandomSpecimen()
{
	int mutated;
	mutated = rand() % size;
	population[mutated].mutate();
}

void Population::crossover()
{

	int father = 0, mother = 1;

	vector<int> child;
	
	int halfSize = static_cast<int>(matrixSize / 2);

	for (int i = 0; i < halfSize; i++)
	{
		child.push_back(population[father].getGeneAt(i));
	}

	int newCity;

	for (int i = 0; i < matrixSize; i++)
	{

		newCity = population[mother].getGeneAt(i);

		if (!(find(child.begin(), child.end(), newCity) != child.end()))
		{
			child.push_back(newCity);
		}
	}

	Specimen *newS = new Specimen(matrixSize, matrix, child);
	population[size - 1] = *newS;
	delete newS; 
}

void Population::randomCrossover()
{
	
	int father = rand()%size, mother = rand() % size;

	while (father == mother)
		mother = rand() % size;

	vector<int> child;

	int halfSize = static_cast<int>(matrixSize / 2);

	for (int i = 0; i < halfSize; i++)
	{
		child.push_back(population[father].getGeneAt(i));
	}

	int newCity;

	for (int i = 0; i < matrixSize; i++)
	{

		newCity = population[mother].getGeneAt(i);

		if (!(find(child.begin(), child.end(), newCity) != child.end()))
		{
			child.push_back(newCity);
		}
	}

	Specimen *newS2 = new Specimen(matrixSize, matrix, child);
	population[size - 1] = *newS2;
	delete newS2;

	////////////////////////////////////////////////////////////////////////
	///////////////////////////SECOND CROSSOVER/////////////////////////////
	////////////////////////////////////////////////////////////////////////

	father = rand() % size, mother = rand() % size;

	while (father == mother)
		mother = rand() % size;

	vector<int> child2;

	for (int i = 0; i < halfSize; i++)
	{
		child2.push_back(population[father].getGeneAt(i));
	}

	for (int i = 0; i < matrixSize; i++)
	{

		newCity = population[mother].getGeneAt(i);

		if (!(find(child2.begin(), child2.end(), newCity) != child2.end()))
		{
			child2.push_back(newCity);
		}
	}

	Specimen *newS3 = new Specimen(matrixSize, matrix, child2);
	population[size - 2] = *newS3;
	delete newS3;
}

void Population::selection()
{
	int selected = static_cast<int>(size * 0.75);

	while(selected<size){
		population[selected].shuffle_chromosome();
		selected++;
	}
}

void Population::displayBest()
{
	population[0].display();
}
