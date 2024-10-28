#include <nlohmann/json.hpp>
#include <string>
#include "Pokedex.h"

void NlohmannParser();
void RapidJsonParser();

int main()
{
	// Parse the JSON file using Nlohmann JSON
	NlohmannParser();

	return 0;
}

void NlohmannParser()
{
	std::string jsonString = R"({"testKey": "testValue"})";

	nlohmann::json parsedJson{ nlohmann::json::parse(jsonString) };

	std::cout << "testKey: " << parsedJson["testKey"] << std::endl;
}

void RapidJsonParser()
{

}