#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct Edge
{
	char from;
	char to;
} edge;

typedef struct Note
{
	int find;
	int leave;
} note;


void DFS1(vector<edge> graph, vector<note>& nodeList, int node, vector<int>& finish, int& time)
{
	nodeList[node].find = time;
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i].from == char(node + 'a'))
		{
			if (nodeList[graph[i].to - 'a'].find == 0)
			{
				time++;
				DFS1(graph, nodeList, graph[i].to - 'a', finish, time);
			}
		}
	}
	if (nodeList[node].leave == 0)
	{
		time++;
		finish.push_back(node);
		nodeList[node].leave = time;
	}
}

void DFS2(vector<edge>& graph, vector<note>& transList, int node, int& time, vector<int>& scc, int sccpos)
{
	transList[node].find = time;
	scc[node] = sccpos;
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i].from == char(node + 'a'))
		{
			if (transList[graph[i].to - 'a'].find == 0)
			{
				time++;
				DFS2(graph, transList, graph[i].to - 'a', time, scc, sccpos);
			}
		}
	}
	if (transList[node].leave == 0)
	{
		time++;
		transList[node].leave = time;
	}
}

int main()
{
	int nodeNumber;
	int time = 1;
	vector<edge> graph;
	// save strongly connected component
	vector<int> scc;

	// save the order of leaving the node.
	vector<int> finish;
	// save each node's find and leave order(at first time)
	vector<note> nodeList;
	// save each node's find and leave order(at second time)(using tranpose graph)
	vector<note> transList;

	string temp;
	edge tempEdge;
	
	// read data and initialize.
	getline(cin, temp, ';');
	nodeNumber = stoi(temp);
	for (int i = 0; i < nodeNumber; i++)
	{
		nodeList.push_back({ 0,0 });
		transList.push_back({0,0});
		scc.push_back(0);
	}

	getline(cin, temp);
	for (int i = 0; i < temp.size(); i++)
	{
		tempEdge.from = temp[i];
		i += 2;
		tempEdge.to = temp[i];
		i++;

		graph.push_back(tempEdge);
	}
	

	// do first DFS.
	for (int i = 0; i < nodeNumber; i++)
	{
		if (nodeList[i].find == 0)
		{
			DFS1(graph, nodeList, i, finish, time);
		}
	}

	// comstruct transpose graph.
	for (int i = 0; i < graph.size(); i++)
	{
		int swap = graph[i].from;
		graph[i].from = graph[i].to;
		graph[i].to = swap;
	}

	int sccpos = 0; 
	time = 1;
	for (int i = finish.size() - 1; i >= 0; i--)
	{
		if (transList[finish[i]].find == 0)
		{
			sccpos++;
			DFS2(graph, transList, finish[i], time, scc, sccpos);
		}
	}


	bool open = true;
	int count = 0, count2;
	for (int i = 0; i < nodeNumber; i++)
	{
		if (scc[i] != 0)
		{
			int tem = scc[i];
			count2 = 0;
			for (int j = 0; j < nodeNumber; j++)
			{
				
				if (tem == scc[j])
				{
					if (count2 != 0)
					{
						cout << ",";
					}
					cout << char(j + 'a');
					scc[j] = 0;
					count++;
					count2++;
				}
			}
			if (count != nodeNumber) 
			{
				cout << ";";
			}
		}
	}
}