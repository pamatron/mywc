cmake_minimum_required(VERSION 3.0.0)

# set(MYWC_SRC
#     main.cpp)
# add all files in the current directory
file(GLOB MYWC_SRC "*.h" "*.cpp")

add_executable(mywc ${MYWC_SRC})
