project(assignment1)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Armadillo
find_package(Armadillo PATHS ${Armadillo_DIR} REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

# Boost
find_package(Boost COMPONENTS iostreams system filesystem  PATHS ${Boost_DIR} REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
# for gnuplot.
include_directories(../include)


include_directories(include)
add_library(ODE src/ODE.cc include/ODE.h)


add_executable(assign1 src/main.cc)
target_link_libraries(assign1 ${Boost_LIBRARIES} ${Armadillo_LIBRARIES}  ODE)