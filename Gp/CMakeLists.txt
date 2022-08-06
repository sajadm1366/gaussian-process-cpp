add_library(GP_Model
	   GP_Model.h
      	   GP_Model.cpp
	    kernel.h
	    kernel.cpp)

target_include_directories(GP_Model PUBLIC .)
target_link_libraries(GP_Model PUBLIC Maths Utils)
