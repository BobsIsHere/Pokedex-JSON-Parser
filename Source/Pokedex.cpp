#include <string>
#include <vector>
#include <windows.h>
#include "Pokedex.h"
#include "JsonParser.h"

int main()
{
	// Set console output to UTF-8 so we can print Unicode characters
	SetConsoleOutputCP(CP_UTF8); 

	JsonParser parser;
	std::vector<PokemonData> pokemonList = parser.ParsePokemonList("Content/pokedex.json");
	parser.PrintPokemonList(pokemonList); 

	return 0;
}