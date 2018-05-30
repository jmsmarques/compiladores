double printint (double n) {
    n = n + 1;
    while(n < 10) {
        n = printint(n);
    }
    return n;
}
int main (void) {
    double g = printint(1);
    return 1;
}