#pragma once

#include <string>

namespace MYWC
{
    class CLI
    {
    public:
        bool print_bytes;
        bool print_lines;
        bool print_words;
        char const *file_name;

        explicit CLI(int argc, char **argv);
#ifndef NDEBUG
        explicit operator std::string();
#endif
    };
}
