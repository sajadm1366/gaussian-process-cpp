add_executable(test_funcs test_funcs.cpp)

message(STATUS "I am here in the test!")


#cmake_print_variables(CMAKE_SOURCE_DIR)

target_link_libraries(test_funcs PUBLIC Maths Utils GP_Model)


add_test(test_funcs test_funcs)
