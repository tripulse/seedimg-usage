# this is a very minimal example of using seedimg
# from an external project, as a dependency.
cmake_minimum_required(VERSION 3.13)

project(seedimg-usage)

# we may not but the underlying library does require to use
# the C++17 standard (eg. for <optional> and <functional>)
set(CMAKE_CXX_STANDARD 17)

add_executable(seedimg-usage src/main.cpp)
file(COPY src/khionu.png DESTINATION "${CMAKE_BINARY_DIR}")

# include seedimg as a depndency.
#   - add provided headers to include path.
#   - build the dependency.
include_directories(libs/seedimg/include)
add_subdirectory(libs/seedimg)

# seedimg - the core library, defines primitives for operations.
# seedimg-autodetect - for loading/saving images easily.
target_link_libraries(seedimg-usage PRIVATE seedimg seedimg-autodetect)
