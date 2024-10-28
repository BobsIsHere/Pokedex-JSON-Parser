#include "JsonParser.h"

#ifdef USE_NLOHMANN
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

	void ParseJsonFile(const std::string& filePath);

private:

};

// ---- NLOHMANN JSON IMPLEMENTATION ----
JsonParser::NlohmannImpl::NlohmannImpl()
{
}

JsonParser::NlohmannImpl::~NlohmannImpl()
{
}

void JsonParser::NlohmannImpl::ParseJsonFile(const std::string& filePath)
{

}
#else
#include <rapidjson/document.h>
class JsonParser::RapidJsonImpl
{
public:
	RapidJsonImpl();
	~RapidJsonImpl();

	RapidJsonImpl(const RapidJsonImpl& other) = delete;
	RapidJsonImpl(RapidJsonImpl&& other) = delete;
	RapidJsonImpl& operator=(const RapidJsonImpl& other) = delete;
	RapidJsonImpl& operator=(RapidJsonImpl&& other) = delete;

	void ParseJsonFile(const std::string& filePath);

private:

};

// ---- RAPIDJSON IMPLEMENTATION ----
JsonParser::RapidJsonImpl::RapidJsonImpl()
{
}

JsonParser::RapidJsonImpl::~RapidJsonImpl()
{
}

void JsonParser::RapidJsonImpl::ParseJsonFile(const std::string& filePath)
{

}
#endif

// ---- JSON PARSER CLASS IMPLEMENTATION ----
JsonParser::JsonParser()
{
#ifdef USE_NLOHMANN
	m_pNlohmannImpl = std::make_unique<NlohmannImpl>();
#else
	m_pRapidJsonImpl = std::make_unique<RapidJsonImpl>();
#endif
}

JsonParser::~JsonParser()
{
}

void JsonParser::ParseJsonFile(const std::string& filePath)
{
#ifdef USE_NLOHMANN
	m_pNlohmannImpl->ParseJsonFile(filePath);
#else
	m_pRapidJsonImpl->ParseJsonFile(filePath);
#endif
}

std::unique_ptr<JsonParser> JsonParser::CreateParser()
{
	return std::unique_ptr<JsonParser>();
}