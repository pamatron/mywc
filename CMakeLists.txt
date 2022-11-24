cmake_minimum_required(VERSION 3.9)
project(mywc VERSION 0.1.0)

include(CheckIPOSupported)
check_ipo_supported(RESULT result)
if(result)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
    message("IPO not supported")
endif()

# include(CTest)
# enable_testing()

include_directories(extern/fmt/include)
add_subdirectory(extern/fmt)

include_directories(include)
add_subdirectory(src)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
