cmake_minimum_required(VERSION 3.30.0)
project(SimpleInventory VERSION 0.1.0 LANGUAGES C CXX)

add_executable(SimpleInventory main.cpp product.cpp inventory.cpp)

include(CTest)
enable_testing()

