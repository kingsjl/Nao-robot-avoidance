cmake_minimum_required(VERSION 2.8)
project(avoidance)

find_package(qibuild)

# Create a executable named avoidance
# with the source file: main.cpp
qi_create_bin(avoidance "main.cpp")

qi_use_lib(avoidance ALCOMMON ALPROXIES)
