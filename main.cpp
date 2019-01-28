#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	/*
	int selected = static_cast<int>(13 * 0.75);
	for (int i = 0; i < 50; i++)
	{
		selected = static_cast<int>(13 * 0.75);
		cout << selected << "\n";
	}*/

	Graph graph;

	bool exit = false;
	int choice;

	while (!exit)
	{

		system("cls");

		cout << "1. Wprowadz graf z pliku tekstowego.\n";
		cout << "2. Wyswietl graf.\n";
		cout << "3. Znajdz minimalny cykl Hamiltona algorytmem genetycznym.\n";
		cout << "4. Wyjdz z programu.\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			graph.enterGraph();
			break;
		case 2:
			graph.showGraph();
			break;
		case 3:
			graph.geneticAlgorithmTSP(1000, 100, (float)0.75, (float)0.05);
			break;
		case 4:
			exit = true;
			break;
		default:
			cout << "Nie ma takiej opcji w menu.\n";
			break;
		}
	}
	return 0;
}