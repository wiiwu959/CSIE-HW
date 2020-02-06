#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

typedef struct Edge
{
	char from;
	char to;
	int weight;
} edge;

void printNode(map<char, int>& destination, int num)
{
	int count = 0;
	for (char i = 'a'; i <= 'z'; i++)
	{
		if (destination.find(i) != destination.end())
		{
			if (destination[i] >= 9999000)
			{
				cout << "inf";
			}
			else
			{
				cout << destination[i];
			}
			count++;
			if (count == num)
			{
				cout << endl;
			}
			else
			{
				cout << ";";
			}
		}
	}
}

void relax(vector<edge> graph ,edge X, map<char, int>& destination)
{
	if (destination[X.to] > destination[X.from] + X.weight)
	{
		destination[X.to] = destination[X.from] + X.weight;
	}
}


int main()
{
	int nodeNumber;
	char startNode;
	vector<edge> graph;
	map<char, int> destination;

	// read data.
	string input;
	getline(cin, input, ';');
	nodeNumber = stoi(input);
	getline(cin, input, ';');
	startNode = input[0];
	destination[startNode] = 0;

	stringstream inputStream;
	getline(cin, input);
	inputStream.str(input);

	edge tempEdge;
	while(getline(inputStream, input,','))
	{
		tempEdge.from = input[0];
		getline(inputStream, input, ',');
		tempEdge.to = input[0];
		getline(inputStream, input, ';');
		tempEdge.weight = stoi(input);

		graph.push_back(tempEdge);

		if (destination.find(tempEdge.from) == destination.end())
		{
			destination[tempEdge.from] = 9999999;
		}

		if (destination.find(tempEdge.to) == destination.end())
		{
			destination[tempEdge.to] = 9999999;
		}
	}

	int count = 0;
	for (char i = 'a'; i <= 'z'; i++)
	{
		if (destination.find(i) != destination.end())
		{
			cout << i;
			count++;
			if (count == nodeNumber)
			{
				cout << endl;
			}
			else
			{
				cout << ";";
			}
		}
	}

	// do Bellman-Ford Algorithm
	for (int i = 0; i < nodeNumber - 1; i++)
	{
		for (int j = 0; j < graph.size(); j++)
		{
			relax(graph, graph[j], destination);
		}
		printNode(destination, nodeNumber);
	}

	// if after (vertex - 1) times of relaxation, there is still shortest path
	// there exist negative cycle.
	for (int j = 0; j < graph.size(); j++)
	{
		if (destination[graph[j].to] > destination[graph[j].from] + graph[j].weight)
		{
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}