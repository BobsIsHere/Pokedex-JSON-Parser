#include <iostream>
#include <fstream>
#include "JsonParser.h"

#ifdef USE_NLOHMANN_LIB
#if USE_NLOHMANN_LIB == true
#include <nlohmann/json.hpp>
class JsonParser::NlohmannImpl
{
public:
	NlohmannImpl();
	~NlohmannImpl();

	NlohmannImpl(const NlohmannImpl& other) = delete;
	NlohmannImpl(NlohmannImpl&& other) = delete;
	NlohmannImpl& operator=(const NlohmannImpl& other) = delete;
	NlohmannImpl& operator=(NlohmannImpl&& other) = delete;

	std::vector<PokemonData> ParsePokemonList(const std::string& filePath);
	void PrintPokemonList(const std::vector<PokemonData>& pokemonList);
};

// ---- NLOHMANN JSON IMPLEMENTATION ----
JsonParser::NlohmannImpl::NlohmannImpl()
{
}

JsonParser::NlohmannImpl::~NlohmannImpl()
{
}

std::vector<PokemonData> JsonParser::NlohmannImpl::ParsePokemonList(const std::string& filePath)
{
	std::vector<PokemonData> pokemonList{};

	std::ifstream file{ filePath };
	if (!file.is_open())
	{
		std::cerr << "Failed to open file: " << filePath << std::endl;
		return pokemonList; 
	}

	nlohmann::json jsonData;

	try
	{
		file >> jsonData;

		for (const auto& pokemon : jsonData["pokemon"])
		{
			PokemonData tempPokemon{};

			tempPokemon.id = pokemon["id"];
			tempPokemon.name = pokemon["name"];
			tempPokemon.type = pokemon["type"].get<std::vector<std::string>>();

			pokemonList.push_back(tempPokemon);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Failed to parse JSON file: " << e.what() << std::endl; 
	}

	file.close();
	return pokemonList; 
}

void JsonParser::NlohmannImpl::PrintPokemonList(const std::vector<PokemonData>& pokemonList)
{
	for (const auto& pokemon : pokemonList)
	{
		std::cout << pokemon.id << ". ";
		std::cout << pokemon.name;
		std::cout << " [";

		for (size_t idx = 0; idx < pokemon.type.size(); ++idx) 
		{
			std::cout << pokemon.type[idx];

			if (idx != pokemon.type.size() - 1)
			{
				std::cout << ", ";
			}
		}

		std::cout << "]" << std::endl;
	}
}

#else
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
class JsonParser::RapidJsonImpl
{
public:
	RapidJsonImpl();
	~RapidJsonImpl();

	RapidJsonImpl(const RapidJsonImpl& other) = delete;
	RapidJsonImpl(RapidJsonImpl&& other) = delete;
	RapidJsonImpl& operator=(const RapidJsonImpl& other) = delete;
	RapidJsonImpl& operator=(RapidJsonImpl&& other) = delete;

	std::vector<PokemonData> ParsePokemonList(const std::string& filePath);
	void PrintPokemonList(const std::vector<PokemonData>& pokemonList);
};

// ---- RAPIDJSON IMPLEMENTATION ----
JsonParser::RapidJsonImpl::RapidJsonImpl()
{
}

JsonParser::RapidJsonImpl::~RapidJsonImpl()
{
}

std::vector<PokemonData> JsonParser::RapidJsonImpl::ParsePokemonList(const std::string& filePath)
{
	std::vector<PokemonData> pokemonList{};

	std::ifstream file{ filePath };
	if (!file.is_open())
	{
		std::cerr << "Failed to open file: " << filePath << std::endl;
		return pokemonList;
	}

	rapidjson::IStreamWrapper stream{ file };
	rapidjson::Document jsonData{};
	jsonData.ParseStream(stream);

	if (jsonData.HasParseError())
	{
		std::cerr << "Failed to parse JSON file: " << jsonData.GetParseError() << std::endl;
		return pokemonList; 
	}

	if (!jsonData.IsObject() || !jsonData.HasMember("pokemon") || !jsonData["pokemon"].IsArray())
	{
		std::cerr << "Invalid JSON format" << std::endl;
		return pokemonList; 
	}

	const auto& pokemonArray = jsonData["pokemon"].GetArray();
	for (const auto& pokemon : pokemonArray)
	{
		PokemonData tempPokemon{};
		tempPokemon.id = pokemon["id"].GetInt(); 
		tempPokemon.name = pokemon["name"].GetString();

		for (const auto& type : pokemon["type"].GetArray())
		{
			if (type.IsString())
			{
				tempPokemon.type.push_back(type.GetString());
			}
		}

		pokemonList.push_back(tempPokemon);
	}

	return pokemonList; 
}

void JsonParser::RapidJsonImpl::PrintPokemonList(const std::vector<PokemonData>& pokemonList)
{
	for (const auto& pokemon : pokemonList)
	{
		std::cout << pokemon.id << ". ";
		std::cout << pokemon.name;
		std::cout << " [";

		for (size_t idx = 0; idx < pokemon.type.size(); ++idx)
		{
			std::cout << pokemon.type[idx];

			if (idx != pokemon.type.size() - 1)
			{
				std::cout << ", ";
			}
		}

		std::cout << "]" << std::endl;
	}
}
#endif
#endif

// ---- JSON PARSER CLASS IMPLEMENTATION ----
JsonParser::JsonParser()
{
#ifdef USE_NLOHMANN_LIB
#if USE_NLOHMANN_LIB == true
	m_pNlohmannImpl = std::make_unique<NlohmannImpl>();
#else
	m_pRapidJsonImpl = std::make_unique<RapidJsonImpl>();
#endif
#endif
}

JsonParser::~JsonParser()
{
}

std::vector<PokemonData> JsonParser::ParsePokemonList(const std::string& filePath)
{
#ifdef USE_NLOHMANN_LIB
#if USE_NLOHMANN_LIB == true
	return m_pNlohmannImpl->ParsePokemonList(filePath);
#else
	return m_pRapidJsonImpl->ParsePokemonList(filePath);
#endif
#endif
}

void JsonParser::PrintPokemonList(const std::vector<PokemonData>& pokemon)
{
#ifdef USE_NLOHMANN_LIB
#if USE_NLOHMANN_LIB == true
	 m_pNlohmannImpl->PrintPokemonList(pokemon);
#else
	return m_pRapidJsonImpl->PrintPokemonList(pokemon);
#endif
#endif
}