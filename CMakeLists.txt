cmake_minimum_required(VERSION 3.10)

# set the project name
project(gp_cpp)

# add the executable
add_subdirectory(Utils)
add_subdirectory(Maths)
add_subdirectory(Gp)

add_executable(main  main.cpp)

target_link_libraries(main PUBLIC Maths Utils GP_Model)



enable_testing()
add_subdirectory(test)

