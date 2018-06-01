char maybe(int a, short c) {
    int f;
    if(a > c) {
        return c;
        while(1) {
            putchar('k');
        }
        return a;
    }
    else {
        if(!a > c) {
            return a;
        }
        if(c) {
            if(!a) {
                return 1;
            }
        }
        else {
            return 10;
        }
        f = c;
        while(a < f) {
            putchar('j');
            putchar(10);
            a = a + 1;
        }
        a = a / 2;
    }
    char n;

    n = (a + c) * 2;
    a = c / a * (c && a);
    
    n = n * 2;

    return n;
}

int main(void) {
    short f = maybe(5, 10);
    putchar(f + '0');
    putchar(10);
}