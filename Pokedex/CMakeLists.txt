cmake_minimum_required (VERSION 3.20)
project ("Pokedex")

option(USE_NLOHMANN "Use Nlohmann JSON" ON)

# Add source to this project's executable
add_executable (Pokedex "Pokedex.cpp" "Pokedex.h" "JsonParser.h" "JsonParser.cpp")

## NLOHMANN LIBRARY FECTHING ##

# Fetch nlohmann/json library
include(FetchContent)

FetchContent_Declare(
    nlohmannJson
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
)

## RAPIDJSON LIBRARY FECTHING ##

# Fetch rapidjson library
FetchContent_Declare(
    rapidjson
    GIT_REPOSITORY https://github.com/Tencent/rapidjson.git
    GIT_TAG master
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
)

# Make fecthed content available
FetchContent_MakeAvailable(nlohmannJson rapidjson)

# Set preprocessor definition based on chosen library
if(USE_NLOHMANN)
    # Link nlohmann JSON library
    target_compile_definitions(Pokedex PRIVATE USE_NLOHMANN)
    target_link_libraries(Pokedex PRIVATE nlohmann_json::nlohmann_json)
else()
    # Link rapidjson library
    target_compile_definitions(Pokedex PRIVATE USE_NLOHMANN)
    target_include_directories(Pokedex PRIVATE ${rapidjson_SOURCE_DIR}/include)
endif()