#include "Stock.h"
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

Stock::Stock()
{
	srand(time(NULL));
	string namePool[5] = { "Gougle","ICM","CheekBook","Somsung","Tree" };
	struct stockData temp;
	for (int i = 0; i < 5; i++)
	{
		temp.name = namePool[i];
		temp.value = rand() % 2000;
		stockList.push_back(temp);
	}
}

Stock::~Stock()
{
}


vector<struct stockData> Stock::getStockList()
{
	return stockList;
}

void Stock::valueChange()
{
	srand(time(NULL));
	for (int i = 0; i < stockList.size(); i++)
	{
		int change = 0;
		change = rand() % (stockList[i].value / 2);
		if (rand() % 2 == 0)
		{
			change *= -1;
		}
		stockList[i].value += change;
	}
}
