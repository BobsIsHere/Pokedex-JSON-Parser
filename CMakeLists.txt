cmake_minimum_required (VERSION 3.20)
project (Pokedex)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USE_NLOHMANN "Use Nlohmann JSON" ON)

# Add source to this project's executable
add_executable (Pokedex "Pokedex/Pokedex.cpp" "Pokedex/Pokedex.h" "Pokedex/JsonParser.h" "Pokedex/JsonParser.cpp")

add_subdirectory(Pokedex)