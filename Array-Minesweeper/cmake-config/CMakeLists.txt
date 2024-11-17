cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_TESTS OFF CACHE BOOL "" FORCE)



# Add the include directories where your header files are 
#sma- now I included all header files so in .cpp no need to decalre header paths from header directory
#include_directories(${CMAKE_SOURCE_DIR}/../header)
include_directories(${CMAKE_SOURCE_DIR}/../header)

# Collect all source files in the source directory
#sma - it will collect all cpp files from source folder so no need to add each file manually
#update - the problem with this only when you added new folder or cpp file it is not auto detecting
#you need to make some changes to this text file and recompile, like add space or empty line
file(GLOB_RECURSE SOURCE_FILES
    ../source/*.cpp  # Adjust the glob pattern to match your source file paths
)

add_executable(main ../main.cpp ${SOURCE_FILES} )



target_link_libraries(main PRIVATE sfml-graphics sfml-audio sfml-window sfml-system)
target_compile_features(main PRIVATE cxx_std_17)

#std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
#sma - added this to set the path to root of project , not inside the cmake folder
#you can always check the path using above cpp line then adjust below path accordingly
#if path is in subfolders then we need to adjust the all the declared configs paths
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/..")



# Windows-specific settings
if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
