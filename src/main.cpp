#include <iostream>
#include <getopt.h>

void parse_commandline(int argc, char **argv)
{
    option longopts[] = {
        {"file", required_argument, NULL, 'f'},
        {0}};
    while (1)
    {
        const int opt = getopt_long(argc, argv, "f:", longopts, 0);
        if (opt == -1)
        {
            break;
        }
        std::cout << optind << std::endl;

        switch (opt)
        {
        case 'f':
            std::cout << "you activated the f switch" << std::endl;
            std::cout << "your filename is " << optarg << std::endl;
            break;
        }
    }
    for (; optind < argc; optind++)
    {
        std::cout << "extra arguments: " << argv[optind] << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::cout << "This is my custom word count tool" << std::endl;
    parse_commandline(argc, argv);
}
