cmake_minimum_required(VERSION 2.8.12)
project(example)

add_subdirectory(pybind)
pybind11_add_module(example example.cpp example.h utilities.cpp utilities.h)
