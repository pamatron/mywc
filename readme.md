# MYWC

A custom word counting tool
written in C++ using `getopt`
and the formatting library [fmt](https://github.com/fmtlib/fmt)

## Usage

```txt
Usage: mywc [OPTION]... [FILE]
Print newline, word, and byte counts for FILE. A word is a non-zero-length sequence of printable characters delimited by white space.

With no FILE, or when FILE is -, read standard input.

The options below may be used to select which counts are printed, always in the following order: newline, word, byte.
  -c, --bytes            print the byte counts
  -l, --lines            print the newline counts
  -w, --words            print the word counts
      --help        display this help and exit
      --version     output version information and exit
```
