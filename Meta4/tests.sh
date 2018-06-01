valgrind ./uccompiler < ../../../testes/funcs_web.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/vazio.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/vazio1.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/testeSimples.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/OR.c > result.ll > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/MinusDouble.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/Logic_erro.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/funcs.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/first.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/E_func_enun.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/E.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/define.c > result.ll
lli result.ll
valgrind ./uccompiler < ../../../testes/brute.c > result.ll
lli result.ll

valgrind ./uccompiler < ../TestFiles/bigmod.c > result.ll
lli result.ll
valgrind ./uccompiler < ../TestFiles/fibonacci.c > result.ll
lli result.ll
valgrind ./uccompiler < ../TestFiles/funcs.c > result.ll
lli result.ll
valgrind ./uccompiler < ../TestFiles/teste.c > result.ll
lli result.ll
valgrind ./uccompiler < ../TestFiles/randomTests.c > result.ll
lli result.ll
valgrind ./uccompiler < ../TestFiles/validProgram.c > result.ll
lli result.ll
valgrind ./uccompiler < ../TestFiles/bigtest1.c > result.ll
lli result.ll
valgrind ./uccompiler < ../TestFiles/bigtest2.c > result.ll
lli result.ll