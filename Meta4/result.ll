declare i32 @getchar()
declare i32 @putchar(i32)
@a = common global i32 0, align 4
@a1 = global i8 52, align 1
@a2 = common global i8 0, align 1
@a5 = global i16 1, align 2
@a3 = global double 1.1, align 8
define i32 @main() {
	%a = alloca i16, align 2
	store i16 -111, i16* %a, align 2
	%b = alloca i32, align 4
	store i32 -5, i32* %b, align 4
	%c = alloca i8, align 1
	store i8 108, i8* %c, align 1
	%1 = call i32 @putchar(i32 104)
	%2 = call i32 @putchar(i32 101)
	%3 = load i8, i8* %c, align 1
	%4 = sext i8 %3 to i32
	%5 = call i32 @putchar(i32 %4)
	%6 = load i8, i8* %c, align 1
	%7 = sext i8 %6 to i32
	%8 = call i32 @putchar(i32 %7)
	%9 = load i16, i16* %a, align 2
	%10 = sext i16 %9 to i32
	%11 = sub nsw i32 0, %10
	%12 = trunc i32 %11 to i16
	%13 = sext i16 %12 to i32
	%14 = call i32 @putchar(i32 %13)
	
\123

4

-->3

5403
%15 = call i32 @putchar(i32 0)
	ret i32 1
}

define i32 @f7(i32 %l1, i32 %l2, i32 %l3) {
	%g1 = alloca i32, align 4
	%g3 = alloca i32, align 4
	%g2 = alloca i8, align 1
	ret i32 1
}

define i8 @jot(i32 %h0, i8 %h1, double %h2) {
	%b1 = alloca i32, align 4
	%b2 = alloca i32, align 4
	%b5 = alloca i8, align 1
	%b6 = alloca i8, align 1
	%c3 = alloca i16, align 2
	%b3 = alloca double, align 8
	%b4 = alloca double, align 8
	%1 = load i8, i8* %b6, align 1
	%2 = sext i8 %1 to i32
	%3 = sub nsw i32 0, %2
	%4 = trunc i32 %3 to i8
	store i8 %4, i8* %b5, align 1
	%5 = load double, double* %b4, align 8
	%6 = fsub double -0.000000e+00, %5
	store double %6, double* %b3, align 8
	%7 = load i32, i32* %b2, align 4
	%8 = sub nsw i32 0, %7
	store i32 %8, i32* %b1, align 4
	store i16 -1, i16* %c3, align 2
	%9 = load i16, i16* %c3, align 2
	%10 = sext i16 %9 to i32
	%11 = sub nsw i32 0, %10
	%12 = trunc i32 %11 to i16
	store i16 %12, i16* %c3, align 2
	ret i8 103
}

define void @f9(i32 %j1, i8 %j2, double %j3) {
	%c1 = alloca i32, align 4
	%c2 = alloca i32, align 4
	%c3 = alloca double, align 8
	store double 1.2, double* %c3, align 8
	store i32 5, i32* %c1, align 4
	ret void
ret void
}

define i32 @empty() {
	ret i32 0
}

