#include "commandline.h"

#include <fmt/core.h>
#include <fmt/ostream.h>

#include <iostream>
#include <fstream>
#include <vector>

#include <getopt.h>
#include <ctype.h>

namespace MYWC
{
    void process_input(std::istream &in, const CLI &cli_args)
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
        words += inword;

        std::vector<uint64_t> output_counts;

        if (cli_args.print_lines)
        {
            output_counts.push_back(lines);
        }
        if (cli_args.print_words)
        {
            output_counts.push_back(words);
        }
        if (cli_args.print_bytes)
        {
            output_counts.push_back(bytes);
        }
        fmt::print("{:7}\n", fmt::join(output_counts, " "));
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
        MYWC::process_input(std::cin, cli_args);
    }
    else
    {
        std::ifstream input_file(cli_args.file_name);
        if (input_file)
        {
            MYWC::process_input(input_file, cli_args);
        }
        else
        {
            fmt::print(std::cerr, "could not open file \"{}\"\n",
                       cli_args.file_name);
        }
    }
}
