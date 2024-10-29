#include <string>
#include <vector>
#include "Pokedex.h"
#include "JsonParser.h"

int main()
{
	JsonParser parser;
	std::vector<PokemonData> pokemonList = parser.ParsePokemonList("Content/pokedex.json");
	parser.PrintPokemonList(pokemonList); 

	return 0;
}