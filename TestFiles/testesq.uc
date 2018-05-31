void teste(double a, double c) {
    a = 'b';
    c = a + c;
}

int main(void) {
    teste(1, 2e2);
}