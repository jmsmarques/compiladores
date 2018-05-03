lex uccompiler.l
yacc -d -v uccompiler.y
clang -Wall -Wno-unused-function -o uccompiler *.c