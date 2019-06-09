#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include "BasicJSON.h"


int main()
{
	BasicJSON json;
	// Parse the JSON file
	if (json.Parse("products.json"))
	{
		// Set the value of "quantity" in line 6 from 261 to 300
		json[0]["quantity"] = 300;
		// Set the value of "_id" in line 3 from "5968dd23fc13ae04d9000001" to "000000000000000000000001"
		json[0]["_id"] = "000000000000000000000001";
		// Delete the pair with name "unit_cost" in line 21
		json[2].Delete("unit_cost");
		// Write out current data to JSON file
		json.Write("output.json");
	}
}