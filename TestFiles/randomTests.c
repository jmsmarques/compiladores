double a = 1;

short fl(void);

int teste(double a, double c, char d) {
    a = 'b';
    a = 3.0e1 + (d = 4);
    c = a + c;
    char g = 48;
    double k = 3;
    double j = (k == k) + (a != -a);

    if(1) {
        putchar('f');
        putchar(10);
    }
    return d;
}

int cao(double a, int b, short c, char d) {
    d = b;
    putchar(d + '0');
    a = c;
    c = d;
    putchar(c + '0');
    b = c * d % 2;
    return b;
}

short fl(void) {
    return 48;
}

double troll(int a) {
    putchar(a + '0');
}

char volta(double a, int b) {
    short f = 2;
    char l = b;
    a = f;
    putchar(b = fl() + !teste(!2, (l = !b,2.), !fl()));
    return !(fl() + teste(!2, (l = b,2.), fl()) % 2 * l / b);
}

int volta3(int a) {
    a = a + 3;
    return a;
}

int volta2(int a) {
    a = a + 2;
    char f = volta3(a);
    short k = 2;
    return f + k;
}

int volta1(int a) {
    int b = 2;
    a = a + 1;
    return volta2(a);
}


int func(int a, short b, char c, double d) {
	putchar(a + '0');
	putchar(b + '0');
	putchar(c + '0');
	putchar((d == 'd') + '0');
	return 0;
}

int main(void) {
    short s = 9;
    int p = volta(2., s);
    putchar(!p +!p + '0');
    
    putchar(volta1(1) + 48);
    int g = 5;
    putchar((g == g) + ((g != g) + '0'));
    putchar(cao(1,2,3,4));

	int a = 'a';
	short b = 'b';
	char c = 'c';
	double d = 'd';
    
	func(1, 1, 1, 1);
    troll(0);
	func(a, a, a, a);
    troll(a);
	func(b, b, b, b);
    troll(b);troll(c);
	func(c, c, c, c);
	func(a, b, c, d);
}