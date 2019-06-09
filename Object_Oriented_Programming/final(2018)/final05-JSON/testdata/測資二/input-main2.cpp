#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <iomanip>
#include "BasicJSON.h"


int main()
{
	BasicJSON json;
	// Parse the JSON file
	if (json.Parse("products.json"))
	{
		// Copy the 3rd record to the records ranged from 5th to 51st
		for (int i = 4; i < 50; i++)
		{
			json[i]["product_name"] = "Dextromathorphan HBr";
			json[i]["supplier"] = "Schmitt-Weissnat";
			json[i]["quantity"] = 211;
			json[i]["unit_cost"] = "$20.53";
		}
		// Delete "supplier" in each record after 50th
		for (int i = 50; i < 253; i++)
		{
			json[i].Delete("supplier");
		}
		// Write out current data to JSON file
		json.Write("output.json");
	}

	return 0;
}