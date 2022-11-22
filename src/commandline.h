#pragma once

#include <iostream>

namespace MYWC
{
    class CLI
    {
    public:
        bool print_chars;
        bool print_lines;
        bool print_words;
        char const *file_name;

        explicit CLI(int argc, char **argv);
    };
    std::ostream &operator<<(std::ostream &out, CLI const &data);
}
