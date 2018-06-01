int putchar(int);
int assignment(void);
int unary_minus(void);
int printing(void);

int arithmetic_ops_types(void) {
	double a;
	int l = 1;
	short m = 2;
	double u = 3;
	a = l + m * u + l; putchar(a + '0');
	putchar('\n');
	a = l + l;	putchar(a + '0');
	a = l + m;	putchar(a + '0');
	a = l + u;	putchar(a + '0');
	a = m + l;	putchar(a + '0');
	a = m + m;	putchar(a + '0');
	a = m + u;	putchar(a + '0');
	a = u + l;	putchar(a + '0');
	a = u + m;	putchar(a + '0');
	a = u + u;	putchar(a + '0');
	putchar('\n');

	a = l - l;	putchar(a + '0');
	a = l - m;	putchar(a + '0');
	a = l - u;	putchar(a + '0');
	a = m - l;	putchar(a + '0');
	a = m - m;	putchar(a + '0');
	a = m - u;	putchar(a + '0');
	a = u - l;	putchar(a + '0');
	a = u - m;	putchar(a + '0');
	a = u - u;	putchar(a + '0');
	putchar('\n');

	a = l * l;	putchar(a + '0');
	a = l * m;	putchar(a + '0');
	a = l * u;	putchar(a + '0');
	a = m * l;	putchar(a + '0');
	a = m * m;	putchar(a + '0');
	a = m * u;	putchar(a + '0');
	a = u * l;	putchar(a + '0');
	a = u * m;	putchar(a + '0');
	a = u * u;	putchar(a + '0');
	putchar('\n');

	a = l / l;	putchar(a + '0');
	a = l / m;	putchar(a + '0');
	a = l / u;	putchar(a + '0');
	a = m / l;	putchar(a + '0');
	a = m / m;	putchar(a + '0');
	a = m / u;	putchar(a + '0');
	a = u / l;	putchar(a + '0');
	a = u / m;	putchar(a + '0');
	a = u / u;	putchar(a + '0');
	putchar('\n');

	a = 1 + 1;	putchar(a + '0');
	a = 1 + 2;	putchar(a + '0');
	a = 1 + 3;	putchar(a + '0');
	a = 2 + 1;	putchar(a + '0');
	a = 2 + 2;	putchar(a + '0');
	a = 2 + 3;	putchar(a + '0');
	a = 3 + 1;	putchar(a + '0');
	a = 3 + 2;	putchar(a + '0');
	a = 3 + 3;	putchar(a + '0');
	putchar('\n');

	a = 1 - 1;	putchar(a + '0');
	a = 1 - 2;	putchar(a + '0');
	a = 1 - 3;	putchar(a + '0');
	a = 2 - 1;	putchar(a + '0');
	a = 2 - 2;	putchar(a + '0');
	a = 2 - 3;	putchar(a + '0');
	a = 3 - 1;	putchar(a + '0');
	a = 3 - 2;	putchar(a + '0');
	a = 3 - 3;	putchar(a + '0');
	putchar('\n');

	a = 1 * 1;	putchar(a + '0');
	a = 1 * 2;	putchar(a + '0');
	a = 1 * 3;	putchar(a + '0');
	a = 2 * 1;	putchar(a + '0');
	a = 2 * 2;	putchar(a + '0');
	a = 2 * 3;	putchar(a + '0');
	a = 3 * 1;	putchar(a + '0');
	a = 3 * 2;	putchar(a + '0');
	a = 3 * 3;	putchar(a + '0');
	putchar('\n');

	a = 1 / 1;	putchar(a + '0');
	a = 1 / 2;	putchar(a + '0');
	a = 1 / 3;	putchar(a + '0');
	a = 2 / 1;	putchar(a + '0');
	a = 2 / 2;	putchar(a + '0');
	a = 2 / 3;	putchar(a + '0');
	a = 3 / 1;	putchar(a + '0');
	a = 3 / 2;	putchar(a + '0');
	a = 3 / 3;	putchar(a + '0');
	putchar('\n');
    
	a = 1 | 1;	putchar(a + '0');
	a = 1 | 2;	putchar(a + '0');
	a = 1 | 3;	putchar(a + '0');
	a = 2 | 1;	putchar(a + '0');
	a = 2 | 2;	putchar(a + '0');
	a = 2 | 3;	putchar(a + '0');
	a = 3 | 1;	putchar(a + '0');
	a = 3 | 2;	putchar(a + '0');
	a = 3 | 3;	putchar(a + '0');
	putchar('\n');
    
	a = 1 & 1;	putchar(a + '0');
	a = 1 & 2;	putchar(a + '0');
	a = 1 & 3;	putchar(a + '0');
	a = 2 & 1;	putchar(a + '0');
	a = 2 & 2;	putchar(a + '0');
	a = 2 & 3;	putchar(a + '0');
	a = 3 & 1;	putchar(a + '0');
	a = 3 & 2;	putchar(a + '0');
	a = 3 & 3;	putchar(a + '0');
	putchar('\n');

	a = 1 ^ 1;	putchar(a + '0');
	a = 1 ^ 2;	putchar(a + '0');
	a = 1 ^ 3;	putchar(a + '0');
	a = 2 ^ 1;	putchar(a + '0');
	a = 2 ^ 2;	putchar(a + '0');
	a = 2 ^ 3;	putchar(a + '0');
	a = 3 ^ 1;	putchar(a + '0');
	a = 3 ^ 2;	putchar(a + '0');
	a = 3 ^ 3;	putchar(a + '0');
	putchar('\n');
    
	a = 1.0 + 1;	putchar(a + '0');
	a = 1.0 + 2;	putchar(a + '0');
	a = 1.0 + 3;	putchar(a + '0');
	a = 2.0 + 1;	putchar(a + '0');
	a = 2.0 + 2;	putchar(a + '0');
	a = 2.0 + 3;	putchar(a + '0');
	a = 3.0 + 1;	putchar(a + '0');
	a = 3.0 + 2;	putchar(a + '0');
	a = 3.0 + 3;	putchar(a + '0');
	a = 1   + 1.0;	putchar(a + '0');
	a = 1   + 2.0;	putchar(a + '0');
	a = 1   + 3.0;	putchar(a + '0');
	a = 2   + 1.0;	putchar(a + '0');
	a = 2   + 2.0;	putchar(a + '0');
	a = 2   + 3.0;	putchar(a + '0');
	a = 3   + 1.0;	putchar(a + '0');
	a = 3   + 2.0;	putchar(a + '0');
	a = 3   + 3.0;	putchar(a + '0');
	a = 1.0 + 1.0;	putchar(a + '0');
	a = 1.0 + 2.0;	putchar(a + '0');
	a = 1.0 + 3.0;	putchar(a + '0');
	a = 2.0 + 1.0;	putchar(a + '0');
	a = 2.0 + 2.0;	putchar(a + '0');
	a = 2.0 + 3.0;	putchar(a + '0');
	a = 3.0 + 1.0;	putchar(a + '0');
	a = 3.0 + 2.0;	putchar(a + '0');
	a = 3.0 + 3.0;	putchar(a + '0');
	putchar('\n');
    
	a = 1.0 - 1;	putchar(a + '0');
	a = 1.0 - 2;	putchar(a + '0');
	a = 1.0 - 3;	putchar(a + '0');
	a = 2.0 - 1;	putchar(a + '0');
	a = 2.0 - 2;	putchar(a + '0');
	a = 2.0 - 3;	putchar(a + '0');
	a = 3.0 - 1;	putchar(a + '0');
	a = 3.0 - 2;	putchar(a + '0');
	a = 3.0 - 3;	putchar(a + '0');
	a = 1   - 1.0;	putchar(a + '0');
	a = 1   - 2.0;	putchar(a + '0');
	a = 1   - 3.0;	putchar(a + '0');
	a = 2   - 1.0;	putchar(a + '0');
	a = 2   - 2.0;	putchar(a + '0');
	a = 2   - 3.0;	putchar(a + '0');
	a = 3   - 1.0;	putchar(a + '0');
	a = 3   - 2.0;	putchar(a + '0');
	a = 3   - 3.0;	putchar(a + '0');
	a = 1.0 - 1.0;	putchar(a + '0');
	a = 1.0 - 2.0;	putchar(a + '0');
	a = 1.0 - 3.0;	putchar(a + '0');
	a = 2.0 - 1.0;	putchar(a + '0');
	a = 2.0 - 2.0;	putchar(a + '0');
	a = 2.0 - 3.0;	putchar(a + '0');
	a = 3.0 - 1.0;	putchar(a + '0');
	a = 3.0 - 2.0;	putchar(a + '0');
	a = 3.0 - 3.0;	putchar(a + '0');
	putchar('\n');
    
	a = 1.0 * 1;	putchar(a + '0');
	a = 1.0 * 2;	putchar(a + '0');
	a = 1.0 * 3;	putchar(a + '0');
	a = 2.0 * 1;	putchar(a + '0');
	a = 2.0 * 2;	putchar(a + '0');
	a = 2.0 * 3;	putchar(a + '0');
	a = 3.0 * 1;	putchar(a + '0');
	a = 3.0 * 2;	putchar(a + '0');
	a = 3.0 * 3;	putchar(a + '0');
	a = 1   * 1.0;	putchar(a + '0');
	a = 1   * 2.0;	putchar(a + '0');
	a = 1   * 3.0;	putchar(a + '0');
	a = 2   * 1.0;	putchar(a + '0');
	a = 2   * 2.0;	putchar(a + '0');
	a = 2   * 3.0;	putchar(a + '0');
	a = 3   * 1.0;	putchar(a + '0');
	a = 3   * 2.0;	putchar(a + '0');
	a = 3   * 3.0;	putchar(a + '0');
	a = 1.0 * 1.0;	putchar(a + '0');
	a = 1.0 * 2.0;	putchar(a + '0');
	a = 1.0 * 3.0;	putchar(a + '0');
	a = 2.0 * 1.0;	putchar(a + '0');
	a = 2.0 * 2.0;	putchar(a + '0');
	a = 2.0 * 3.0;	putchar(a + '0');
	a = 3.0 * 1.0;	putchar(a + '0');
	a = 3.0 * 2.0;	putchar(a + '0');
	a = 3.0 * 3.0;	putchar(a + '0');
	putchar('\n');
    
	a = 1.0 / 1;	putchar(a + '0');
	a = 1.0 / 2;	putchar(a + '0');
	a = 1.0 / 3;	putchar(a + '0');
	a = 2.0 / 1;	putchar(a + '0');
	a = 2.0 / 2;	putchar(a + '0');
	a = 2.0 / 3;	putchar(a + '0');
	a = 3.0 / 1;	putchar(a + '0');
	a = 3.0 / 2;	putchar(a + '0');
	a = 3.0 / 3;	putchar(a + '0');
	a = 1   / 1.0;	putchar(a + '0');
	a = 1   / 2.0;	putchar(a + '0');
	a = 1   / 3.0;	putchar(a + '0');
	a = 2   / 1.0;	putchar(a + '0');
	a = 2   / 2.0;	putchar(a + '0');
	a = 2   / 3.0;	putchar(a + '0');
	a = 3   / 1.0;	putchar(a + '0');
	a = 3   / 2.0;	putchar(a + '0');
	a = 3   / 3.0;	putchar(a + '0');
	a = 1.0 / 1.0;	putchar(a + '0');
	a = 1.0 / 2.0;	putchar(a + '0');
	a = 1.0 / 3.0;	putchar(a + '0');
	a = 2.0 / 1.0;	putchar(a + '0');
	a = 2.0 / 2.0;	putchar(a + '0');
	a = 2.0 / 3.0;	putchar(a + '0');
	a = 3.0 / 1.0;	putchar(a + '0');
	a = 3.0 / 2.0;	putchar(a + '0');
	a = 3.0 / 3.0;	putchar(a + '0');
	putchar('\n');
	return 0;
}

int arithmetic_ops(void) {
	int a, l = 1, m = 2, u = 3;

	a = l + l;	putchar(a + '0');
	a = l + m;	putchar(a + '0');
	a = l + u;	putchar(a + '0');
	a = m + l;	putchar(a + '0');
	a = m + m;	putchar(a + '0');
	a = m + u;	putchar(a + '0');
	a = u + l;	putchar(a + '0');
	a = u + m;	putchar(a + '0');
	a = u + u;	putchar(a + '0');
	putchar('\n');

	a = l - l;	putchar(a + '0');
	a = l - m;	putchar(a + '0');
	a = l - u;	putchar(a + '0');
	a = m - l;	putchar(a + '0');
	a = m - m;	putchar(a + '0');
	a = m - u;	putchar(a + '0');
	a = u - l;	putchar(a + '0');
	a = u - m;	putchar(a + '0');
	a = u - u;	putchar(a + '0');
	putchar('\n');

	a = l * l;	putchar(a + '0');
	a = l * m;	putchar(a + '0');
	a = l * u;	putchar(a + '0');
	a = m * l;	putchar(a + '0');
	a = m * m;	putchar(a + '0');
	a = m * u;	putchar(a + '0');
	a = u * l;	putchar(a + '0');
	a = u * m;	putchar(a + '0');
	a = u * u;	putchar(a + '0');
	putchar('\n');

	a = l / l;	putchar(a + '0');
	a = l / m;	putchar(a + '0');
	a = l / u;	putchar(a + '0');
	a = m / l;	putchar(a + '0');
	a = m / m;	putchar(a + '0');
	a = m / u;	putchar(a + '0');
	a = u / l;	putchar(a + '0');
	a = u / m;	putchar(a + '0');
	a = u / u;	putchar(a + '0');
	putchar('\n');

	a = l % l;	putchar(a + '0');
	a = l % m;	putchar(a + '0');
	a = l % u;	putchar(a + '0');
	a = m % l;	putchar(a + '0');
	a = m % m;	putchar(a + '0');
	a = m % u;	putchar(a + '0');
	a = u % l;	putchar(a + '0');
	a = u % m;	putchar(a + '0');
	a = u % u;	putchar(a + '0');
	putchar('\n');

	a = l & l;	putchar(a + '0');
	a = l & m;	putchar(a + '0');
	a = l & u;	putchar(a + '0');
	a = m & l;	putchar(a + '0');
	a = m & m;	putchar(a + '0');
	a = m & u;	putchar(a + '0');
	a = u & l;	putchar(a + '0');
	a = u & m;	putchar(a + '0');
	a = u & u;	putchar(a + '0');
	putchar('\n');

	a = l | l;	putchar(a + '0');
	a = l | m;	putchar(a + '0');
	a = l | u;	putchar(a + '0');
	a = m | l;	putchar(a + '0');
	a = m | m;	putchar(a + '0');
	a = m | u;	putchar(a + '0');
	a = u | l;	putchar(a + '0');
	a = u | m;	putchar(a + '0');
	a = u | u;	putchar(a + '0');
	putchar('\n');

	a = l ^ l;	putchar(a + '0');
	a = l ^ m;	putchar(a + '0');
	a = l ^ u;	putchar(a + '0');
	a = m ^ l;	putchar(a + '0');
	a = m ^ m;	putchar(a + '0');
	a = m ^ u;	putchar(a + '0');
	a = u ^ l;	putchar(a + '0');
	a = u ^ m;	putchar(a + '0');
	a = u ^ u;	putchar(a + '0');
	putchar('\n');

	a = 1 + 1;	putchar(a + '0');
	a = 1 + 2;	putchar(a + '0');
	a = 1 + 3;	putchar(a + '0');
	a = 2 + 1;	putchar(a + '0');
	a = 2 + 2;	putchar(a + '0');
	a = 2 + 3;	putchar(a + '0');
	a = 3 + 1;	putchar(a + '0');
	a = 3 + 2;	putchar(a + '0');
	a = 3 + 3;	putchar(a + '0');
	putchar('\n');

	a = 1 - 1;	putchar(a + '0');
	a = 1 - 2;	putchar(a + '0');
	a = 1 - 3;	putchar(a + '0');
	a = 2 - 1;	putchar(a + '0');
	a = 2 - 2;	putchar(a + '0');
	a = 2 - 3;	putchar(a + '0');
	a = 3 - 1;	putchar(a + '0');
	a = 3 - 2;	putchar(a + '0');
	a = 3 - 3;	putchar(a + '0');
	putchar('\n');

	a = 1 * 1;	putchar(a + '0');
	a = 1 * 2;	putchar(a + '0');
	a = 1 * 3;	putchar(a + '0');
	a = 2 * 1;	putchar(a + '0');
	a = 2 * 2;	putchar(a + '0');
	a = 2 * 3;	putchar(a + '0');
	a = 3 * 1;	putchar(a + '0');
	a = 3 * 2;	putchar(a + '0');
	a = 3 * 3;	putchar(a + '0');
	putchar('\n');

	a = 1 / 1;	putchar(a + '0');
	a = 1 / 2;	putchar(a + '0');
	a = 1 / 3;	putchar(a + '0');
	a = 2 / 1;	putchar(a + '0');
	a = 2 / 2;	putchar(a + '0');
	a = 2 / 3;	putchar(a + '0');
	a = 3 / 1;	putchar(a + '0');
	a = 3 / 2;	putchar(a + '0');
	a = 3 / 3;	putchar(a + '0');
	putchar('\n');

	a = 1 % 1;	putchar(a + '0');
	a = 1 % 2;	putchar(a + '0');
	a = 1 % 3;	putchar(a + '0');
	a = 2 % 1;	putchar(a + '0');
	a = 2 % 2;	putchar(a + '0');
	a = 2 % 3;	putchar(a + '0');
	a = 3 % 1;	putchar(a + '0');
	a = 3 % 2;	putchar(a + '0');
	a = 3 % 3;	putchar(a + '0');
	putchar('\n');

	a = 1 & 1;	putchar(a + '0');
	a = 1 & 2;	putchar(a + '0');
	a = 1 & 3;	putchar(a + '0');
	a = 2 & 1;	putchar(a + '0');
	a = 2 & 2;	putchar(a + '0');
	a = 2 & 3;	putchar(a + '0');
	a = 3 & 1;	putchar(a + '0');
	a = 3 & 2;	putchar(a + '0');
	a = 3 & 3;	putchar(a + '0');
	putchar('\n');

	a = 1 | 1;	putchar(a + '0');
	a = 1 | 2;	putchar(a + '0');
	a = 1 | 3;	putchar(a + '0');
	a = 2 | 1;	putchar(a + '0');
	a = 2 | 2;	putchar(a + '0');
	a = 2 | 3;	putchar(a + '0');
	a = 3 | 1;	putchar(a + '0');
	a = 3 | 2;	putchar(a + '0');
	a = 3 | 3;	putchar(a + '0');
	putchar('\n');

	a = 1 ^ 1;	putchar(a + '0');
	a = 1 ^ 2;	putchar(a + '0');
	a = 1 ^ 3;	putchar(a + '0');
	a = 2 ^ 1;	putchar(a + '0');
	a = 2 ^ 2;	putchar(a + '0');
	a = 2 ^ 3;	putchar(a + '0');
	a = 3 ^ 1;	putchar(a + '0');
	a = 3 ^ 2;	putchar(a + '0');
	a = 3 ^ 3;	putchar(a + '0');
	putchar('\n');
	return 0;
}

int relational_ops(void) {
	int l = 0, m = 1, u = 2;
	int a;

	a = l == l;	putchar(a + '0');
	a = l == m;	putchar(a + '0');
	a = l == u;	putchar(a + '0');
	a = m == l;	putchar(a + '0');
	a = m == m;	putchar(a + '0');
	a = m == u;	putchar(a + '0');
	a = u == l;	putchar(a + '0');
	a = u == m;	putchar(a + '0');
	a = u == u;	putchar(a + '0');
	putchar('\n');

	a = l != l;	putchar(a + '0');
	a = l != m;	putchar(a + '0');
	a = l != u;	putchar(a + '0');
	a = m != l;	putchar(a + '0');
	a = m != m;	putchar(a + '0');
	a = m != u;	putchar(a + '0');
	a = u != l;	putchar(a + '0');
	a = u != m;	putchar(a + '0');
	a = u != u;	putchar(a + '0');
	putchar('\n');

	a = l < l;	putchar(a + '0');
	a = l < m;	putchar(a + '0');
	a = l < u;	putchar(a + '0');
	a = m < l;	putchar(a + '0');
	a = m < m;	putchar(a + '0');
	a = m < u;	putchar(a + '0');
	a = u < l;	putchar(a + '0');
	a = u < m;	putchar(a + '0');
	a = u < u;	putchar(a + '0');
	putchar('\n');

	a = l <= l;	putchar(a + '0');
	a = l <= m;	putchar(a + '0');
	a = l <= u;	putchar(a + '0');
	a = m <= l;	putchar(a + '0');
	a = m <= m;	putchar(a + '0');
	a = m <= u;	putchar(a + '0');
	a = u <= l;	putchar(a + '0');
	a = u <= m;	putchar(a + '0');
	a = u <= u;	putchar(a + '0');
	putchar('\n');

	a = l > l;	putchar(a + '0');
	a = l > m;	putchar(a + '0');
	a = l > u;	putchar(a + '0');
	a = m > l;	putchar(a + '0');
	a = m > m;	putchar(a + '0');
	a = m > u;	putchar(a + '0');
	a = u > l;	putchar(a + '0');
	a = u > m;	putchar(a + '0');
	a = u > u;	putchar(a + '0');
	putchar('\n');

	a = l >= l;	putchar(a + '0');
	a = l >= m;	putchar(a + '0');
	a = l >= u;	putchar(a + '0');
	a = m >= l;	putchar(a + '0');
	a = m >= m;	putchar(a + '0');
	a = m >= u;	putchar(a + '0');
	a = u >= l;	putchar(a + '0');
	a = u >= m;	putchar(a + '0');
	a = u >= u;	putchar(a + '0');
	putchar('\n');

	a = 0 == 0;	putchar(a + '0');
	a = 0 == 1;	putchar(a + '0');
	a = 0 == 2;	putchar(a + '0');
	a = 1 == 0;	putchar(a + '0');
	a = 1 == 1;	putchar(a + '0');
	a = 1 == 2;	putchar(a + '0');
	a = 2 == 0;	putchar(a + '0');
	a = 2 == 1;	putchar(a + '0');
	a = 2 == 2;	putchar(a + '0');
	putchar('\n');

	a = 0 != 0;	putchar(a + '0');
	a = 0 != 1;	putchar(a + '0');
	a = 0 != 2;	putchar(a + '0');
	a = 1 != 0;	putchar(a + '0');
	a = 1 != 1;	putchar(a + '0');
	a = 1 != 2;	putchar(a + '0');
	a = 2 != 0;	putchar(a + '0');
	a = 2 != 1;	putchar(a + '0');
	a = 2 != 2;	putchar(a + '0');
	putchar('\n');

	a = 0 < 0;	putchar(a + '0');
	a = 0 < 1;	putchar(a + '0');
	a = 0 < 2;	putchar(a + '0');
	a = 1 < 0;	putchar(a + '0');
	a = 1 < 1;	putchar(a + '0');
	a = 1 < 2;	putchar(a + '0');
	a = 2 < 0;	putchar(a + '0');
	a = 2 < 1;	putchar(a + '0');
	a = 2 < 2;	putchar(a + '0');
	putchar('\n');

	a = 0 <= 0;	putchar(a + '0');
	a = 0 <= 1;	putchar(a + '0');
	a = 0 <= 2;	putchar(a + '0');
	a = 1 <= 0;	putchar(a + '0');
	a = 1 <= 1;	putchar(a + '0');
	a = 1 <= 2;	putchar(a + '0');
	a = 2 <= 0;	putchar(a + '0');
	a = 2 <= 1;	putchar(a + '0');
	a = 2 <= 2;	putchar(a + '0');
	putchar('\n');

	a = 0 > 0;	putchar(a + '0');
	a = 0 > 1;	putchar(a + '0');
	a = 0 > 2;	putchar(a + '0');
	a = 1 > 0;	putchar(a + '0');
	a = 1 > 1;	putchar(a + '0');
	a = 1 > 2;	putchar(a + '0');
	a = 2 > 0;	putchar(a + '0');
	a = 2 > 1;	putchar(a + '0');
	a = 2 > 2;	putchar(a + '0');
	putchar('\n');

	a = 0 >= 0;	putchar(a + '0');
	a = 0 >= 1;	putchar(a + '0');
	a = 0 >= 2;	putchar(a + '0');
	a = 1 >= 0;	putchar(a + '0');
	a = 1 >= 1;	putchar(a + '0');
	a = 1 >= 2;	putchar(a + '0');
	a = 2 >= 0;	putchar(a + '0');
	a = 2 >= 1;	putchar(a + '0');
	a = 2 >= 2;	putchar(a + '0');
	putchar('\n');
	return 0;
}

int logical_ops_variables(void) {
	char V = 1, F = 0;
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;

	int test = V && V; putchar(test + '0');
	test = V && F; putchar(test + '0');
	test = F && V; putchar(test + '0');
	test = F && F; putchar(test + '0');
	putchar('\n'); // line expected: 1000

	a = V && V && V && V; putchar(a + '0'); // 1 true
	b = V && V && V && F; putchar(b + '0'); // 0 false
	c = V && V && F && V; putchar(c + '0'); // 0 false
	d = V && V && F && F; putchar(d + '0'); // 0 false
	e = V && F && V && V; putchar(e + '0'); // 0 false
	f = V && F && V && F; putchar(f + '0'); // 0 false
	g = V && F && F && V; putchar(g + '0'); // 0 false
	h = V && F && F && F; putchar(h + '0'); // 0 false
	i = F && V && V && V; putchar(i + '0'); // 0 false
	j = F && V && V && F; putchar(j + '0'); // 0 false
	k = F && V && F && V; putchar(k + '0'); // 0 false
	l = F && V && F && F; putchar(l + '0'); // 0 false
	m = F && F && V && V; putchar(m + '0'); // 0 false
	n = F && F && V && F; putchar(n + '0'); // 0 false
	o = F && F && F && V; putchar(o + '0'); // 0 false
	p = F && F && F && F; putchar(p + '0'); // 0 false
	putchar('\n'); // line expected: 1000000000000000

	a = V || V || V || V; putchar(a + '0'); // 1 true
	b = V || V || V || F; putchar(b + '0'); // 1 true
	c = V || V || F || V; putchar(c + '0'); // 1 true
	d = V || V || F || F; putchar(d + '0'); // 1 true
	e = V || F || V || V; putchar(e + '0'); // 1 true
	f = V || F || V || F; putchar(f + '0'); // 1 true
	g = V || F || F || V; putchar(g + '0'); // 1 true
	h = V || F || F || F; putchar(h + '0'); // 1 true
	i = F || V || V || V; putchar(i + '0'); // 1 true
	j = F || V || V || F; putchar(j + '0'); // 1 true
	k = F || V || F || V; putchar(k + '0'); // 1 true
	l = F || V || F || F; putchar(l + '0'); // 1 true
	m = F || F || V || V; putchar(m + '0'); // 1 true
	n = F || F || V || F; putchar(n + '0'); // 1 true
	o = F || F || F || V; putchar(o + '0'); // 1 true
	p = F || F || F || F; putchar(p + '0'); // 0 false
	putchar('\n'); // line expected: 1111111111111110

	a = V && (V || V) || V; putchar(a + '0'); // 1 true
	b = V && (V || V) || F; putchar(b + '0'); // 1 true
	c = V && (V || F) || V; putchar(c + '0'); // 1 true
	d = V && (V || F) || F; putchar(d + '0'); // 1 true
	e = V && (F || V) || V; putchar(e + '0'); // 1 true
	f = V && (F || V) || F; putchar(f + '0'); // 1 true
	g = V && (F || F) || V; putchar(g + '0'); // 1 true
	h = V && (F || F) || F; putchar(h + '0'); // 0 false
	i = F && (V || V) || V; putchar(i + '0'); // 1 true
	j = F && (V || V) || F; putchar(j + '0'); // 0 false
	k = F && (V || F) || V; putchar(k + '0'); // 1 true
	l = F && (V || F) || F; putchar(l + '0'); // 0 false
	m = F && (F || V) || V; putchar(m + '0'); // 1 true
	n = F && (F || V) || F; putchar(n + '0'); // 0 false
	o = F && (F || F) || V; putchar(o + '0'); // 1 true
	p = F && (F || F) || F; putchar(p + '0'); // 0 false
	putchar('\n'); // line expected: 1111111010101010

	a = V && ((V || V) || V); putchar(a + '0'); // 1 true
	b = V && ((V || V) || F); putchar(b + '0'); // 1 true
	c = V && ((V || F) || V); putchar(c + '0'); // 1 true
	d = V && ((V || F) || F); putchar(d + '0'); // 1 true
	e = V && ((F || V) || V); putchar(e + '0'); // 1 true
	f = V && ((F || V) || F); putchar(f + '0'); // 1 true
	g = V && ((F || F) || V); putchar(g + '0'); // 1 true
	h = V && ((F || F) || F); putchar(h + '0'); // 0 false
	i = F && ((V || V) || V); putchar(i + '0'); // 0 false
	j = F && ((V || V) || F); putchar(j + '0'); // 0 false
	k = F && ((V || F) || V); putchar(k + '0'); // 0 false
	l = F && ((V || F) || F); putchar(l + '0'); // 0 false
	m = F && ((F || V) || V); putchar(m + '0'); // 0 false
	n = F && ((F || V) || F); putchar(n + '0'); // 0 false
	o = F && ((F || F) || V); putchar(o + '0'); // 0 false
	p = F && ((F || F) || F); putchar(p + '0'); // 0 false
	putchar('\n'); // line expected: 1111111000000000

	return 0;
}

int logical_ops_literals(void) {
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;

	int test = 1 && 1; putchar(test + '0');
	test = 1 && 0; putchar(test + '0');
	test = 0 && 1; putchar(test + '0');
	test = 0 && 0; putchar(test + '0');
	putchar('\n'); // line expected: 1000

	a = 1 && 1 && 1 && 1; putchar(a + '0'); // 1 true
	b = 1 && 1 && 1 && 0; putchar(b + '0'); // 0 false
	c = 1 && 1 && 0 && 1; putchar(c + '0'); // 0 false
	d = 1 && 1 && 0 && 0; putchar(d + '0'); // 0 false
	e = 1 && 0 && 1 && 1; putchar(e + '0'); // 0 false
	f = 1 && 0 && 1 && 0; putchar(f + '0'); // 0 false
	g = 1 && 0 && 0 && 1; putchar(g + '0'); // 0 false
	h = 1 && 0 && 0 && 0; putchar(h + '0'); // 0 false
	i = 0 && 1 && 1 && 1; putchar(i + '0'); // 0 false
	j = 0 && 1 && 1 && 0; putchar(j + '0'); // 0 false
	k = 0 && 1 && 0 && 1; putchar(k + '0'); // 0 false
	l = 0 && 1 && 0 && 0; putchar(l + '0'); // 0 false
	m = 0 && 0 && 1 && 1; putchar(m + '0'); // 0 false
	n = 0 && 0 && 1 && 0; putchar(n + '0'); // 0 false
	o = 0 && 0 && 0 && 1; putchar(o + '0'); // 0 false
	p = 0 && 0 && 0 && 0; putchar(p + '0'); // 0 false
	putchar('\n'); // line expected: 1000000000000000

	a = 1 || 1 || 1 || 1; putchar(a + '0'); // 1 true
	b = 1 || 1 || 1 || 0; putchar(b + '0'); // 1 true
	c = 1 || 1 || 0 || 1; putchar(c + '0'); // 1 true
	d = 1 || 1 || 0 || 0; putchar(d + '0'); // 1 true
	e = 1 || 0 || 1 || 1; putchar(e + '0'); // 1 true
	f = 1 || 0 || 1 || 0; putchar(f + '0'); // 1 true
	g = 1 || 0 || 0 || 1; putchar(g + '0'); // 1 true
	h = 1 || 0 || 0 || 0; putchar(h + '0'); // 1 true
	i = 0 || 1 || 1 || 1; putchar(i + '0'); // 1 true
	j = 0 || 1 || 1 || 0; putchar(j + '0'); // 1 true
	k = 0 || 1 || 0 || 1; putchar(k + '0'); // 1 true
	l = 0 || 1 || 0 || 0; putchar(l + '0'); // 1 true
	m = 0 || 0 || 1 || 1; putchar(m + '0'); // 1 true
	n = 0 || 0 || 1 || 0; putchar(n + '0'); // 1 true
	o = 0 || 0 || 0 || 1; putchar(o + '0'); // 1 true
	p = 0 || 0 || 0 || 0; putchar(p + '0'); // 0 false
	putchar('\n'); // line expected: 1111111111111110

	a = 1 && (1 || 1) || 1; putchar(a + '0'); // 1 true
	b = 1 && (1 || 1) || 0; putchar(b + '0'); // 1 true
	c = 1 && (1 || 0) || 1; putchar(c + '0'); // 1 true
	d = 1 && (1 || 0) || 0; putchar(d + '0'); // 1 true
	e = 1 && (0 || 1) || 1; putchar(e + '0'); // 1 true
	f = 1 && (0 || 1) || 0; putchar(f + '0'); // 1 true
	g = 1 && (0 || 0) || 1; putchar(g + '0'); // 1 true
	h = 1 && (0 || 0) || 0; putchar(h + '0'); // 0 false
	i = 0 && (1 || 1) || 1; putchar(i + '0'); // 1 true
	j = 0 && (1 || 1) || 0; putchar(j + '0'); // 0 false
	k = 0 && (1 || 0) || 1; putchar(k + '0'); // 1 true
	l = 0 && (1 || 0) || 0; putchar(l + '0'); // 0 false
	m = 0 && (0 || 1) || 1; putchar(m + '0'); // 1 true
	n = 0 && (0 || 1) || 0; putchar(n + '0'); // 0 false
	o = 0 && (0 || 0) || 1; putchar(o + '0'); // 1 true
	p = 0 && (0 || 0) || 0; putchar(p + '0'); // 0 false
	putchar('\n'); // line expected: 1111111010101010

	a = 1 && ((1 || 1) || 1); putchar(a + '0'); // 1 true
	b = 1 && ((1 || 1) || 0); putchar(b + '0'); // 1 true
	c = 1 && ((1 || 0) || 1); putchar(c + '0'); // 1 true
	d = 1 && ((1 || 0) || 0); putchar(d + '0'); // 1 true
	e = 1 && ((0 || 1) || 1); putchar(e + '0'); // 1 true
	f = 1 && ((0 || 1) || 0); putchar(f + '0'); // 1 true
	g = 1 && ((0 || 0) || 1); putchar(g + '0'); // 1 true
	h = 1 && ((0 || 0) || 0); putchar(h + '0'); // 0 false
	i = 0 && ((1 || 1) || 1); putchar(i + '0'); // 0 false
	j = 0 && ((1 || 1) || 0); putchar(j + '0'); // 0 false
	k = 0 && ((1 || 0) || 1); putchar(k + '0'); // 0 false
	l = 0 && ((1 || 0) || 0); putchar(l + '0'); // 0 false
	m = 0 && ((0 || 1) || 1); putchar(m + '0'); // 0 false
	n = 0 && ((0 || 1) || 0); putchar(n + '0'); // 0 false
	o = 0 && ((0 || 0) || 1); putchar(o + '0'); // 0 false
	p = 0 && ((0 || 0) || 0); putchar(p + '0'); // 0 false
	putchar('\n'); // line expected: 1111111000000000

	return 0;
}

// 60 pontos
int assignment(void){
	int a, b, c;
	int d;
	a = b;
	char aa, bb;
	aa = bb;
	short aaa, bbb;
	aaa = bbb;
	double aaaa, bbbb;
	aaaa = bbbb;
	a = 1;
	b = 1;
	c = 1;
	d = 1;
	aa = 'A';
	bb = 'z';
	aaa = 1;
	bbb = 1;
	aaaa = 1.0;
	bbbb = 1.0;
	return d;
}

// 60 pontos
int unary_minus(void){
	int c = -1;
	int d = -c;
	int a = 1;
	int b;
	b = -a;
	b = -2;
	return 0;
}

// 60 - 100 pontos
int printing(void){
	// 60 pontos
	putchar('a');
	char _11 = 'A';
	int _12 = 65;
	short _13 = 65;
	double _14 = 65.0;
	
	putchar(97);
	//putchar(65.0);
	putchar(_11);
	putchar(_12);
	putchar(_13);
	//putchar(_14);
	putchar('\n');
	putchar('\t');
	putchar('\n');
	putchar('\'');
	putchar('\n');
	putchar('\"');
	putchar('\n');
	putchar('\\');
	putchar('\123');
	// 100 pontos
	putchar(78);
	putchar('\116');
	putchar('\10');
	putchar('\65');
    return 0;
}

// 20 pontos
int main(void){
	arithmetic_ops_types();
	putchar('\n');
	arithmetic_ops();
	putchar('\n');
	relational_ops();
	putchar('\n');
	logical_ops_variables();
	putchar('\n');
	logical_ops_literals();
	putchar('\n');
	assignment();
	putchar('\n');
	unary_minus();
	putchar('\n');
	printing();
	putchar('\n');
	int var1 = 2;
	short var2 = 3;
	char var3 = 4;
	double var4 = 3;

	double a;// = var1 == var2 == (var3 == var4); putchar(a + '0');

	a =   var1 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var2 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var3 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var1  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var2  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var3  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var4 ==   var4  ==  var1  == var1;	putchar(a + '0');
	a =   var1 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var2 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var3 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var1  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var2  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var3  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var4 ==   var4  == (var1  == var1);	putchar(a + '0');
	a =   var1 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var1 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var2 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var3 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var1  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var2  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var3  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =   var4 ==  (var4  ==  var1) == var1; 	putchar(a + '0');
	a =  (var1 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var2 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var3 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var1) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var2) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var3) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var4 ==   var4) ==  var1  == var1; 	putchar(a + '0');
	a =  (var1 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var1 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var2 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var3 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var1) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var2) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var3) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a =  (var4 ==   var4) == (var1  == var1); 	putchar(a + '0');
	a = ((var1 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var1 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var2 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var3 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var1) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var2) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var3) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a = ((var4 ==   var4) ==  var1) == var1; 	putchar(a + '0');
	a =   var1 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var2 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var3 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var1  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var2  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var3  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var4 == ((var4  ==  var1) == var1); 	putchar(a + '0');
	a =   var1 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var1 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var2 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var3 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var1  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var2  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var3  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	a =   var4 ==  (var4  == (var1  == var1)); 	putchar(a + '0');
	putchar('\n');

	a =   2 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   3 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   4 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   2  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   3  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   4  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   3.0 ==   3.0  ==  2  == 2;	putchar(a + '0');
	a =   2 ==   2  == (2  == 2);	putchar(a + '0');
	a =   2 ==   2  == (2  == 2);	putchar(a + '0');
	a =   2 ==   2  == (2  == 2);	putchar(a + '0');
	a =   2 ==   2  == (2  == 2);	putchar(a + '0');
	a =   2 ==   3  == (2  == 2);	putchar(a + '0');
	a =   2 ==   3  == (2  == 2);	putchar(a + '0');
	a =   2 ==   3  == (2  == 2);	putchar(a + '0');
	a =   2 ==   3  == (2  == 2);	putchar(a + '0');
	a =   2 ==   4  == (2  == 2);	putchar(a + '0');
	a =   2 ==   4  == (2  == 2);	putchar(a + '0');
	a =   2 ==   4  == (2  == 2);	putchar(a + '0');
	a =   2 ==   4  == (2  == 2);	putchar(a + '0');
	a =   2 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   2 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   2 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   2 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   3 ==   2  == (2  == 2);	putchar(a + '0');
	a =   3 ==   2  == (2  == 2);	putchar(a + '0');
	a =   3 ==   2  == (2  == 2);	putchar(a + '0');
	a =   3 ==   2  == (2  == 2);	putchar(a + '0');
	a =   3 ==   3  == (2  == 2);	putchar(a + '0');
	a =   3 ==   3  == (2  == 2);	putchar(a + '0');
	a =   3 ==   3  == (2  == 2);	putchar(a + '0');
	a =   3 ==   3  == (2  == 2);	putchar(a + '0');
	a =   3 ==   4  == (2  == 2);	putchar(a + '0');
	a =   3 ==   4  == (2  == 2);	putchar(a + '0');
	a =   3 ==   4  == (2  == 2);	putchar(a + '0');
	a =   3 ==   4  == (2  == 2);	putchar(a + '0');
	a =   3 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   3 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   3 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   3 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   4 ==   2  == (2  == 2);	putchar(a + '0');
	a =   4 ==   2  == (2  == 2);	putchar(a + '0');
	a =   4 ==   2  == (2  == 2);	putchar(a + '0');
	a =   4 ==   2  == (2  == 2);	putchar(a + '0');
	a =   4 ==   3  == (2  == 2);	putchar(a + '0');
	a =   4 ==   3  == (2  == 2);	putchar(a + '0');
	a =   4 ==   3  == (2  == 2);	putchar(a + '0');
	a =   4 ==   3  == (2  == 2);	putchar(a + '0');
	a =   4 ==   4  == (2  == 2);	putchar(a + '0');
	a =   4 ==   4  == (2  == 2);	putchar(a + '0');
	a =   4 ==   4  == (2  == 2);	putchar(a + '0');
	a =   4 ==   4  == (2  == 2);	putchar(a + '0');
	a =   4 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   4 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   4 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   4 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   2  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   2  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   2  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   2  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   3  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   3  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   3  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   3  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   4  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   4  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   4  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   4  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   3.0 ==   3.0  == (2  == 2);	putchar(a + '0');
	a =   2 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   2 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   3 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   4 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (2  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (3  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (4  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =   3.0 ==  (3.0  ==  2) == 2; 	putchar(a + '0');
	a =  (2 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (3 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (4 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   2) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   3) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   4) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (3.0 ==   3.0) ==  2  == 2; 	putchar(a + '0');
	a =  (2 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (2 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (3 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (4 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   2) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   3) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   4) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a =  (3.0 ==   3.0) == (2  == 2); 	putchar(a + '0');
	a = ((2 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((2 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((3 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((4 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   2) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   3) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   4) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a = ((3.0 ==   3.0) ==  2) == 2; 	putchar(a + '0');
	a =   2 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   2 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   3 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   4 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((2  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((3  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((4  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   3.0 == ((3.0  ==  2) == 2); 	putchar(a + '0');
	a =   2 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   2 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   3 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   4 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (2  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (3  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (4  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	a =   3.0 ==  (3.0  == (2  == 2)); 	putchar(a + '0');
	putchar('\n');	

	return 0;
}

