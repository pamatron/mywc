#include "commandline.h"

#include <fmt/core.h>

#include <getopt.h>
#include <iostream>

int main(int argc, char **argv)
{
    MYWC::CLI obj(argc, argv);
    fmt::print("this is my implementation of wc !\n");
#ifndef NDEBUG
    std::cout << obj << std::endl;
#endif
}
