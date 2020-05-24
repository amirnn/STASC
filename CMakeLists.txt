project(STASC)
cmake_minimum_required(VERSION 3.10) # optimistic

# Armadillo
# Set armadillo path for windows
IF (WIN32)
  set(Armadillo_DIR "C:/Program Files/Armadillo/armadillo_9.880.1/")
  MESSAGE( STATUS "On Windows Armadillo Path is set to: " ${Armadillo_DIR} )
ENDIF()

# Boost
# Set boost path for windows
IF (WIN32)
  set(Boost_DIR "C:/Program Files/boost/boost_1_73_0/stage/lib/cmake/Boost-1.73.0")
  MESSAGE( STATUS "On Windows Boost Path is set to: " ${Boost_DIR} )
ENDIF()

add_subdirectory(assign1)