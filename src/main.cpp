#include <iostream>
#include <getopt.h>

#include "commandline.h"

int main(int argc, char **argv)
{
    std::cout << "This is my custom word count tool" << std::endl;
    MYWC::CLI obj(argc, argv);
#ifndef NDEBUG
    std::cout << obj << std::endl;
#endif
}
