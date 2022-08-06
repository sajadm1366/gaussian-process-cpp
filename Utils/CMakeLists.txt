add_library(Utils utils.h utils.cpp)

target_include_directories(Utils PUBLIC .)

target_link_libraries(Utils PUBLIC Maths)
