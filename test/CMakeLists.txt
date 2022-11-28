
add_test(NAME no_args 
            COMMAND mywc)
set_property(TEST no_args
            PROPERTY PASS_REGULAR_EXPRESSION "^ *0 +0 +0")

# pwd == ./build/test
add_test(NAME one_line 
            COMMAND bash -c "echo hello | ../src/mywc")
set_property(TEST one_line
            PROPERTY PASS_REGULAR_EXPRESSION "^ *1 +1 +6")
            
add_test(NAME multi_line 
            COMMAND bash -c "echo 'hello\nmy dear\nfriend' | ../src/mywc")
set_property(TEST multi_line
            PROPERTY PASS_REGULAR_EXPRESSION "^ *3 +4 +21")

add_test(NAME no_trailing_newline 
            COMMAND bash -c "echo -n 'hello\nmy\nfriend' | ../src/mywc")
set_property(TEST no_trailing_newline
            PROPERTY PASS_REGULAR_EXPRESSION "^ *2 +3 +15")

add_test(NAME only_bytes 
            COMMAND bash -c "echo -n 'hello\nmy\nfriend' | ../src/mywc --bytes")
set_property(TEST only_bytes
            PROPERTY PASS_REGULAR_EXPRESSION "^ *15")

add_test(NAME only_words 
            COMMAND bash -c "echo -n 'hello\nmy\nfriend' | ../src/mywc --words")
set_property(TEST only_words
            PROPERTY PASS_REGULAR_EXPRESSION "^ *3")

add_test(NAME only_lines 
            COMMAND bash -c "echo -n 'hello\nmy\nfriend' | ../src/mywc --lines")
set_property(TEST only_lines
            PROPERTY PASS_REGULAR_EXPRESSION "^ *2")
