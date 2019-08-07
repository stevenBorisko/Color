project(Color)
add_library(Color
	./src/ColorHSV.cpp
	./src/ColorHSL.cpp
	./src/ColorRGB.cpp
	./src/ColorRGBc.cpp
)
target_include_directories(Color PUBLIC ./include)
