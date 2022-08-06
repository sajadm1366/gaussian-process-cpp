add_library(Maths
	   linalg.cpp
	   linalg.h
            alglibinternal.cpp
             alglibinternal.h
	     alglibmisc.cpp
	     alglibmisc.h
	     specialfunctions.cpp
	     specialfunctions.h
	     statistics.cpp
	     statistics.h
	     ap.cpp
	      ap.h
	       grad_decent.h
		grad_decent.cpp)

target_include_directories(Maths PUBLIC .)
