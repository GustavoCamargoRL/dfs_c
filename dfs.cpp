// Resolution of the third question of Fundamentals of Algorithms for Optimization
// Example depth search algorithm for graphs
// Autor: Gustavo Lima
// Prof: Raphael Kramer


#include <vector> 
#include <iostream>

//initialization of global variables
std::vector<std::string> cor = {};   //initializing color vector
std::vector<std::pair<int, int>> pai_temp = {};   //initializing parent vector and time
std::vector<std::vector<int>> grafo = { {1,2},{4,6},{4},{},{3,5,7},{0},{3,2},{6} };  //initialization of the graph and its arcs
int pai = 0;				  //initialization of parent of origin
int tempo = 0;				  //iteration counter initialization
std::vector<int> sequenciaVisitada = {pai};

//start DFS algorithm
void dfs(int pai)
{
	for (int i = 0; i < grafo[pai].size(); i++)
	{
		
		if (cor[grafo[pai][i]][0] == 'w')	//check if the vertex has not been visited by checking if its color is white
		{
			sequenciaVisitada.push_back(grafo[pai][i]);
			cor[grafo[pai][i]] = "blue";					//changes the vertex color to blue to indicate that it has already been visited
			pai_temp[grafo[pai][i]].first = pai;			//updates the parent value of the explored vertex
			dfs(grafo[pai][i]);								//recursively calls the search for the next vertex
		}
		tempo += 1;
		std::cout << "End of iteration" << tempo << ": colour = [";
		for (int i = 0; i < cor.size(); i++)
		{
			for (int j = 0; j < cor[i].size(); j++)
			{
				std::cout << cor[i][j];
			}
			if (i < cor.size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "], (Father,Time) = [No 1 - Father: nil Time:" << pai_temp[0].second << ", ";
		for (int i = 1; i < pai_temp.size(); i++)
		{
			std::cout << "Node " << i + 1 << " - ";
			std::cout << "Father: ";
			std::cout << pai_temp[i].first + 1 << " Time: " << pai_temp[i].second;
			if (i < pai_temp.size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout<<std::endl;
	}
	cor[pai] = "purple";
	pai_temp[pai].second = tempo;

}
int main(int argc, char *argv[])
{

	std::cout << "Beginning of the search for depth in a graph:" << std::endl;

	for (int i = 0; i < grafo.size(); i++)
	{
		cor.push_back("white");
		pai_temp.push_back({ NULL,NULL });
	}
	std::cout << "Initial values: color = [";
	for (int i = 0; i < cor.size(); i++)
	{
		for (int j = 0; j < cor[i].size(); j++)
		{
			std::cout << cor[i][j];
		}
		if (i < cor.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "], (Father, Time) = [No 1 - Father: nil time: nil";
	for (int i = 1; i < pai_temp.size(); i++)
	{
		std::cout << "Node " << i + 1 << " - ";
		std::cout << "Father: nil Time: nil";
		if (i < pai_temp.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;
	cor[pai] = "blue";
	//call of the breadth search execution
	dfs(pai);

	std::cout << "Final result:" << std::endl;
	std::cout << "iterations " << tempo << ": colour = [";
	for (int i = 0; i < cor.size(); i++)
	{
		for (int j = 0; j < cor[i].size(); j++)
		{
			std::cout << cor[i][j];
		}
		if (i < cor.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "], (Father,Time) = [No 1 - Father: nil Time: " << pai_temp[0].second << ", ";
	for (int i = 1; i < pai_temp.size(); i++)
	{
		std::cout << "Node " << i + 1 << " - ";
		std::cout << "Father: ";
		std::cout << pai_temp[i].first + 1 << " Time: " << pai_temp[i].second;
		if (i < pai_temp.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl << "sequence visited:";
	for (int i = 0; i < sequenciaVisitada.size(); i++)
	{
		std::cout << sequenciaVisitada[i];
		if (i < cor.size() - 1)
		{
			std::cout << ", ";
		}
	}

	return 0;
}
