# Find Utility

## About
This program searches through a given list of files and prints each line that contains (or doesn't contain) a pattern string. This program is useful when you are trying to search through a huge text file to find where a given instance of something is!

## How to Build
Type make to build project. This will create the program find.

## How to use
Usage of program is ./find [ARGS] PATTERN file1, file2, ... , fileN. Arguments are optional. The two arguments are -n and -x.
 - -n: prints line numbers in file of applicable found lines
 - -x: prints all lines that DO NOT contain the given search pattern
You can give one or multiple files. The given output will print the file name, all the matching lines then the next file name (if there is one) and applicable matchine lines and so on.

## Credit
This is from exercise 7-7 of The C Programming Language by Dennis Ritchie and Brian Kernigan. This find program is loosely based on the book so credit is given to them and myself John Morgan Wight.
