#include <iostream>
#include <getopt.h>

#include "commandline.h"

int main(int argc, char **argv)
{
    MYWC::CLI obj(argc, argv);
#ifndef NDEBUG
    std::cout << obj << std::endl;
#endif
}
