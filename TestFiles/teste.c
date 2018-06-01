int readint (void) {
    int read = 0 ,sign = 1;
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
void printint (int n) {
    if(n < 0) {
        putchar('-');
        n = -n;
    }
    if(n / 10) {
        printint (n / 10);
    }
    putchar (n % 10 + '0');
}
int sum1(int a, int b) {
    return a + b;
}

int sum(int a, int b) {
    return a + b;
}
int main (void) {
    int i = 1;
    //double l;
    while (i != 0) {
        i = readint();
        //l = i;
        printint(i);
        printint(sum(sum1(i,1), !sum(!4, !sum1(2, !3 + 4))));
        putchar('\n');
    }
    sum(!sum(i,1), !sum1(!i, 0));
}