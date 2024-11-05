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

set(RAPIDJSON_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_THIRDPARTY_GTEST OFF CACHE BOOL "" FORCE)

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
    target_link_libraries(Pokedex PRIVATE nlohmann_json::nlohmann_json)
else()
    # Link rapidjson library
    target_include_directories(Pokedex PRIVATE ${rapidjson_SOURCE_DIR}/include)
endif()

target_compile_definitions(Pokedex PRIVATE USE_NLOHMANN_LIB=$<BOOL:${USE_NLOHMANN}>)