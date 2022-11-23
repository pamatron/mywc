#include "commandline.h"

#include <fmt/core.h>

#include <getopt.h>

int main(int argc, char **argv)
{
    MYWC::CLI obj(argc, argv);
#ifndef NDEBUG
    fmt::print("{}\n",std::string(obj));
#endif
}
