#!/bin/sh

flex uccompiler.l
clang-3.8 -o uccompiler lex.yy.c
