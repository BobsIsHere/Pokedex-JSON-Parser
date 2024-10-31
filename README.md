# Pokedex-JSON-Parser

For this parser project I chose the [Nlohmann/json] library and the [Tencent/RapidJson] library.

## Setup Instructions

### 1. Unzip the Folder
To set up this parser project, you need to first unzip the folder. 

### 2. Open the Project in Visual Studio
Next you need to open this project using Visual Studios. You can do this by right-clicking inside the folder 
and select 'Show more options'. In that list, you have the option to select 'Open with Visual Studios'.

### 3. Configure and Build the Project
After opening the project and waiting for CMake to configure, you will need to build to project so it can retrieve all libraries.

### 4. Run the Project
To actually run the project, you press 'F5' or just the start button in Visual Studio. This will print out the json file using the Nlohmann parsing code. 

### 5. Switch to RapidJson Parser
When you want to switch to the RapidJson parsing code, you will need to open the CMakeSettings.json file which you can find in VS folder view.
Scroll all the way down until you find CMake variables and cache. In this list you also need to scroll all the way down until you find the variable 'USE_NLOHMANN'.
You can set this variable true or false by checking or unchecking the box. You always need to save the file so the changes can be made in code.
Now run the project again and it should print out the same list using the RapidJson parser.

## External Libraries

During the build process, the external libraries are retrieved using the 'FetchContent_Declare()' function. This function records the options to populate specified
content, such as to download and manage external dependencies directly from a URL or repository. This makes it easier to include a third-party library
in a CMake project.