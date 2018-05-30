#include <stdio.h>
int readint (void) {
    int read = 0 ,sign = 1;
    //read = 1, sign = 0, read = 1;
    char c = getchar();
    if(c == '-')
        sign = -1;
    while(c != '\n') {
        if(c != '-')
            read = read * 10 + c - '0';
        c = getchar();
    }
    return sign * read;
}
double printint (double n, int f, short g) {
    f = g;
    n = n + 1;
    while(n < 10) {
        n = printint(n, g, g);
        putchar(getchar() + 1);
    }
    return n;
}
int main2(int a);
int main3(int a);
int main (void) {
    int a = main2(0);
    putchar(a + 48);
    return 1;
}

int main2(int a){
    if(a != 10) {
        return main2(a+1);
    }
    else {
        return main3(a - 1);
    }
    return 0;
}

int main3(int){
    return 1;
}