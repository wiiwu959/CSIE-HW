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
		// Delete "unit_cost" in each record
		for (int i = 0; i < 252; i++)
		{
			json[i].Delete("unit_cost");
		}
		// Update the value of "_id" in records after the 169th
		std::ostringstream stream;
		for (int i = 169; i < 252; i++)
		{
			stream.str(std::string());
			stream.clear();
			stream << "5968dd23fc13ae04d9" << std::setfill('0') << std::setw(6) << (i + 1);
			json[i]["_id"] = stream.str();
		}
		// Write out current data to JSON file
		json.Write("output.json");
	}

	return 0;
}