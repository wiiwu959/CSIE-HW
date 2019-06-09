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
		// Delete the pair with name "unit_cost" in the 250th record
		json[249].Delete("unit_cost");
		// Update the value of the pair with name "supplier" from "Schmitt-Weissnat" to "Schmitt-Bogisich" in the 251st record
		json[250]["supplier"] = "Schmitt-Bogisich";
		// Update the value of the pair with name "quantity" from 211 to 200 in the 252nd record
		json[251]["quantity"] = 200;
		// Update the value of the pair with name "unit_cost" from "$20.53" to "$29.99" in the 253rd record
		json[252]["unit_cost"] = "$29.99";
		// Write out current data to JSON file
		json.Write("output.json");
	}

	return 0;
}