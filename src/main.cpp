#include "commandline.h"

#include <fmt/core.h>
#include <fmt/ostream.h>

#include <iostream>
#include <fstream>

#include <getopt.h>
#include <ctype.h>

namespace MYWC
{
    void process_input(std::istream &in)
    {
        uint64_t bytes = 0;
        uint64_t words = 0;
        uint64_t lines = 0;
        std::string line;
        char c;
        bool inword = false;
        while (in.read(&c, 1))
        {
            bytes++;
            if (c == '\n')
            {
                lines++;
            }
            if (isspace(c))
            {
                words += inword;
                inword = false;
            }
            else
            {
                inword = true;
            }
        }

        fmt::print("bytes, words, lines\n{:5}{:5}{:5}\n",
                   bytes, words, lines);
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
