project(assignment1)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)

# find_package(Armadillo REQUIRED)
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

include_directories(include)


add_executable(assign1 src/main.cpp)
target_link_libraries(assign1 ${ARMADILLO_LIBRARIES})