# Lexer-Parser

### :busts_in_silhouette: The Team
* Varun Naryanan
* Anish Sai Mitta
* Himnish Kapoor
* Anurag Sidharth Aribandi

### 🔎 About
* The project consists of a lexer and a parser, both compatible with each other.
* The language syntax is similar to that of C and C++ syntax, instead of semicolons to end statements, colons are used.
* The language supports any variable or function name other those with special characters like '@'.
* Before every function name and after its return type the keyword 'fun' must be specified and the last statement of the function must be followed by the keyword 'endfun'.
* The language similarly supports loops and if statements.
* The language supports in built print and scan functions.
* See the sample test codes in the "Test_Codes" folder to get a better idea.
* The parser is an LL Parser. The parsing table is provided in the "Parser" folder.
* The CFG is provided in the pdf and the parsing table is provided in the Parser folder.
* Synch, Skip and Terminal errors are handled by the parser and the line number that causes the error is specified.

## Lexer

### :key: Run the Project
* Ensure that the header file, driver,lexer and code txt input files are in the same folder.
* Compile the code with the command "g++ lexer.cpp driver.cpp -o main".
* Run the code with the command "./main test_case1.txt output.txt", the first file name is the code txt file, the second is the output file name that will be generated

### :star: Output
* The output a file that contains the lexemes and their corresponding token pairs.
* The line number of hte lexeme is also specified
* The "Lex_Output" folder contains outputs corresponding to the code test cases (output1 corresponds to the test_case1 txt file)

## Parser

### :key: Run the Project
* Ensure that the parser.cpp and parsing table csv files are in the same folder.
* Compile the code with the command "g++ -o parser.exe parser.cpp".
* Run the code with the command "./parser.exe output2.txt", the file name is the input to the parser, in this case the output of the lexer which took in a code txt file. 

### :star: Output
* The code outputs two txt files and will say "PARSED" on the terminal if the code has no errors. Else, it will specify the type of error encountered and the line at which the error occurs in the original code txt file
* One is the stack output of the LL parser, which details the production rules used from the CFG grammar, the contents of the stack before and after using the production rule, and the input pointer.
* Whenever a token from the input (The token list outputted by the lexer) is matched with the top of the stack, it will denote so. 
* The other output file is the tree output, a parsing tree is constructed and the output is the DFS traversal of said tree, specifying each parent and it's children.       
* The "Parser_Output" folder contains outputs corresponding to the code test cases and the lexer outputs (stack_output1 corresponds to the stack output of the test_case1 code txt file and the output1 txt file from the lexeme output).
