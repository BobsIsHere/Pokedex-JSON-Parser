#include <nlohmann/json.hpp>
#include <rapidjson/document.h>

#include <string>
#include "Pokedex.h"

void NlohmannParser();
void RapidJsonParser();

int main()
{
	// Parse the JSON file using Nlohmann JSON
	NlohmannParser();

	// Parse the JSON file using RapidJSON
	RapidJsonParser();

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
	const char* jsonString = R"({"testKey": "testValue"})";

	rapidjson::Document document;
	document.Parse(jsonString);

	if (document.HasParseError())
	{
		std::cerr << "Parse error: " << document.GetParseError() << std::endl;
	}
	else if (document.HasMember("testKey") && document["testKey"].IsString())
	{
		std::cout << "testKey: " << document["testKey"].GetString() << std::endl;
	}
	else
	{
		std::cerr << "'testKey' not found or is not a string." << std::endl;
	}
}