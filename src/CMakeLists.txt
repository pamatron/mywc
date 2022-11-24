cmake_minimum_required(VERSION 3.9)

# add all files in the current directory
file(GLOB MYWC_SRC "*.h" "*.cpp")

add_executable(mywc ${MYWC_SRC})

# support for the std::format library 
# currently seemingly only supported by MSVC
# target_compile_features(mywc PRIVATE cxx_std_20)
# therefore temporarily use https://github.com/fmtlib/fmt.git

if(MSVC)
  target_compile_options(mywc PRIVATE /W4)
else()
  target_compile_options(mywc PRIVATE -Wall -Wextra -Wpedantic)
  # during development treat warnings as errors
  target_compile_options(mywc PRIVATE -Werror)
endif()

target_link_libraries(mywc fmt)