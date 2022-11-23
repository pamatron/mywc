#include "commandline.h"

#include "version.h"

#include <fmt/core.h>

#include <getopt.h>

namespace MYWC
{
    static struct option const longopts[] =
        {
            {"bytes", no_argument, nullptr, 'c'},
            {"lines", no_argument, nullptr, 'l'},
            {"words", no_argument, nullptr, 'w'},
            {"help", no_argument, nullptr, 'h'},
            {"version", no_argument, nullptr, 'V'},
            {nullptr, 0, nullptr, 0}};

    void print_usage(int status)
    {
        fmt::print("\
Usage: mywc [OPTION]... [FILE]\n\
Print newline, word, and byte counts for FILE. \
A word is a non-zero-length sequence of printable \
characters delimited by white space.\n\
\n\
With no FILE, or when FILE is -, read standard input.\n\
\n\
The options below may be used to select which counts are printed, \
always in the following order: newline, word, byte.\n\
  -c, --bytes            print the byte counts\n\
  -l, --lines            print the newline counts\n\
  -w, --words            print the word counts\n\
      --help        display this help and exit\n\
      --version     output version information and exit\n");
        exit(status);
    }

    void print_version()
    {
        fmt::print("{}", VERSION);
        exit(EXIT_SUCCESS);
    }

    CLI::CLI(int argc, char **argv)
    {
        int optc;

        print_bytes = false;
        print_lines = false;
        print_words = false;

        while (true)
        {
            optc = getopt_long(argc, argv, "clw", longopts, 0);
            if (optc == -1)
            {
                break;
            }

            switch (optc)
            {
            case 'c':
                print_bytes = true;
                break;

            case 'l':
                print_lines = true;
                break;

            case 'w':
                print_words = true;
                break;

            case 'h':
                print_usage(EXIT_SUCCESS);
                break;

            case 'V':
                print_version();
                break;

            default:
                print_usage(EXIT_FAILURE);
            }
        }

        if (!print_bytes && !print_words && !print_lines)
        {
            print_bytes = print_words = print_lines = true;
        }

        if (optind < argc)
        {
            file_name = argv[optind];
            optind++;
        }
        else
        {
            file_name = "-";
        }
    }

#ifndef NDEBUG
    CLI::operator std::string()
    {
        return fmt::format("\
print_bytes: {}\n\
print_lines: {}\n\
print_words: {}\n\
file_name:   \"{}\"",
                           print_bytes, print_lines, print_words, file_name);
    }
#endif
}