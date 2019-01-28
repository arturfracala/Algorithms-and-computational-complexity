#include "Graph.h"
#include "Population.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;


Graph::Graph()
{
	size = 1;
	matrix = new int*[1];
	matrix[0] = new int[1];
	matrix[0][0] = 0;
}


Graph::~Graph()
{
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void Graph::enterGraph()
{
	fstream file;
	string fileName;

	std::cout << "Podaj nazwe pliku tekstowego:\n";
	cin >> fileName;

	file.open(fileName.c_str(), fstream::in | fstream::out | fstream::app);

	int variable;

	if (file.is_open())
	{
		for (int i = 0; i < size; i++)
			delete[] matrix[i];
		delete[] matrix;

		file >> size;

		if (file.fail())
			std::cout << "Blad odczytu rozmiaru tablicy reprezentujacej graf.\n";
		else
		{
			matrix = new int*[size];

			for (int i = 0; i < size; i++)
				matrix[i] = new int[size];

			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
				{
					file >> variable;

					if (file.fail())
					{
						std::cout << "Blad odczytu danych\n";
						break;
					}
					else
						matrix[i][j] = variable;
				}
		}
		file.close();
	}
}

void Graph::showGraph()
{
	std::cout << "\n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << "\n";
	}

	std::cin.ignore();
	std::cin.get();
}

void Graph::geneticAlgorithmTSP(int numberOfGeneration, int population, float crossoverRate, float mutationRate)
{
	srand(time(NULL));

	Population *myPopulation = new Population(10, matrix, size);

	myPopulation->sortPopulation();
	myPopulation->displayBest();

	float randomVar = (float)rand() / RAND_MAX;

	for(int i =0;i<numberOfGeneration;i++){
	
		randomVar = (float)rand() / RAND_MAX;

		if (randomVar < crossoverRate)
		{
			myPopulation->crossover();
			myPopulation->sortPopulation();
			myPopulation->randomCrossover();
			myPopulation->sortPopulation();
		}

		randomVar = (float)rand() / RAND_MAX;

		if (randomVar < mutationRate)
		{
			myPopulation->mutateRandomSpecimen();
			myPopulation->sortPopulation();
		}
	
		myPopulation->selection();
		myPopulation->sortPopulation();
		cout << "Iteracja numer: " << i + 1<<"\n";
		myPopulation->displayBest();
	}
	
	std::cin.ignore();
	std::cin.get();

	delete myPopulation;
}
