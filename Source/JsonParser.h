#pragma once
#include <memory>
#include <string>
#include <vector>

struct PokemonData
{
	int id;
	std::string name; 
	std::vector<std::string> type;
};

class JsonParser final
{
public:
	explicit JsonParser();
	~JsonParser();

	JsonParser(const JsonParser& other) = delete;
	JsonParser(JsonParser&& other) = delete;
	JsonParser& operator=(const JsonParser& other) = delete;
	JsonParser& operator=(JsonParser&& other) = delete;

	std::vector<PokemonData> ParsePokemonList(const std::string& filePath);
	void PrintPokemonList(const std::vector<PokemonData>& pokemonList);

private:
#ifdef USE_NLOHMANN_LIB
#if USE_NLOHMANN_LIB == true
	class NlohmannImpl;
	std::unique_ptr<NlohmannImpl> m_pNlohmannImpl;
#else
	class RapidJsonImpl;
	std::unique_ptr<RapidJsonImpl> m_pRapidJsonImpl;
#endif
#endif
};