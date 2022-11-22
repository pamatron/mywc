cmake_minimum_required(VERSION 3.0.0)
project(mywc VERSION 0.1.0)

# include(CTest)
# enable_testing()

include_directories(extern/fmt/include)
add_subdirectory(extern/fmt)

include_directories(include)
# add_subdirectory(src)

# add all files in the current directory
file(GLOB MYWC_SRC "src/*.h" "src/*.cpp")

# add_subdirectory(../extern/fmt ../extern/fmt)

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

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
