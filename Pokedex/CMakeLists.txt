cmake_minimum_required (VERSION 3.20)
project ("Pokedex")

# Add source to this project's executable.
add_executable (Pokedex "Pokedex.cpp" "Pokedex.h")

# Fetch nlohmann/json library
include(FetchContent)

FetchContent_Declare(
    nlohmannJson
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3 # Specify the version of the library you want to use
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
)

# Make fecthed content available
FetchContent_MakeAvailable(nlohmannJson)

# Link nlohmann JSON library
target_link_libraries(Pokedex PRIVATE nlohmann_json::nlohmann_json)