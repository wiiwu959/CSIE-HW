#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>
using namespace std;

struct stockData
{
	string name;
	unsigned int value;
};

class Stock
{
private:
	vector<struct stockData> stockList;

public:
	Stock();
	~Stock();

	vector<struct stockData> getStockList();
	void valueChange();
};

#endif