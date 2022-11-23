#include "commandline.h"

#include <fmt/core.h>
#include <fmt/ostream.h>

#include <getopt.h>
#include <iostream>
#include <fstream>

namespace MYWC
{
    void process_input(std::istream &in)
    {
        std::string line;
        while (std::getline(in, line))
        {
            fmt::print("line: {}\n", line);
        }
    }
}

int main(int argc, char **argv)
{
    MYWC::CLI cli_args(argc, argv);
#ifndef NDEBUG
    fmt::print("CLI args:\n{}\n", std::string(cli_args));
#endif
    if (std::string("-") == cli_args.file_name)
    {
        MYWC::process_input(std::cin);
    }
    else
    {
        std::ifstream input_file(cli_args.file_name);
        if (input_file)
        {
            MYWC::process_input(input_file);
        }
        else
        {
            fmt::print(std::cerr, "could not open file \"{}\"\n",
                       cli_args.file_name);
        }
    }
}
