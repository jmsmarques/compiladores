double a = 1;

char teste(double a, double c, char d) {
    a = 'b';
    a = 3.0e1 + (d = 4);
    c = a + c;
    char g = 48;
    return d;
}

double cao(void) {
    return 2.1;
}

short fl(void) {
    return 48;
}

char volta(double a, int b) {
    short f = 2;
    char l = b;
    a = f;
    putchar(b = fl() + teste(2, (l = b,2.), fl()));
    return b = fl() + teste(2, (l = b,2.), fl());
}

int volta3(int a) {
    a = a + 3;
    return a;
}

int volta2(int a) {
    a = a + 2;
    int f = volta3(a);
    return f;
}

int volta1(int a) {
    int b = 2;
    a = a + 1;
    return volta2(a);
}

int main(void) {
    putchar(volta1(1) + 48);
    
    return 1;
}