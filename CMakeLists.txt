cmake_minimum_required(VERSION 3.20)
project(Pokedex)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USE_NLOHMANN "Use Nlohmann JSON" ON)

# Add source to this project's executable
add_executable(Pokedex "Source/Pokedex.cpp" "Source/Pokedex.h" "Source/JsonParser.h" "Source/JsonParser.cpp")

add_subdirectory(Source)

## COPY CONTENT FOLDER ##
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Content)

add_custom_command(
    TARGET Pokedex POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/Content/pokedex.json" "${CMAKE_CURRENT_BINARY_DIR}/Content"
)