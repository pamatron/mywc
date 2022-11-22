cmake_minimum_required(VERSION 3.0.0)

# add all files in the current directory
file(GLOB MYWC_SRC "*.h" "*.cpp")

add_executable(mywc ${MYWC_SRC})

# support for the std::format library 
# currently seemingly only supported by MSVC
# target_compile_features(mywc PRIVATE cxx_std_20)

if(MSVC)
  target_compile_options(mywc PRIVATE /W4)
#   target_compile_options(mywc PRIVATE /WX)
else()
  target_compile_options(mywc PRIVATE -Wall -Wextra -Wpedantic)
#   target_compile_options(mywc PRIVATE -Werror)
endif()