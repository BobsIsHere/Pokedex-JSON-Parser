#include <string>
#include "Pokedex.h"
#include "JsonParser.h"

int main()
{
	JsonParser parser;
	parser.ParseJsonFile("pokedex.json");

	return 0;
}