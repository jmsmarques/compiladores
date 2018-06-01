lex uccompiler.l
yacc -d -v uccompiler.y
clang -Wall -Wno-unused-function -o uccompiler annotTree.c ast.c codeGen.c errors.c symtable.c y.tab.c lex.yy.c