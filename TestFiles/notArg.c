void printint(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
    {
        printint(n / 10);
    }
    putchar(n % 10 + '0');
}

void print(int x)
{
    printint(x);
    putchar('\n');
}
void main2(char q);

int main(void) {
    int p;
    char q;
    p = 5;
    q = 1;
    main2(q);
    return 0;
}

char q(char, char);

void main2(char p){
    print(q(p,p));
    print(q(p,!p));
    print(q(!p,p));
    print(q(!p,!p));
}


char q(char p, char q) {
    return p && !q;
}