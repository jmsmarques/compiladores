declare i32 @getchar()
declare i32 @putchar(i32)
@a = common global i32 0, align 4
@a1 = global i8 52, align 1
@a2 = common global i8 0, align 1
@a5 = global i16 1, align 2
@a3 = global double 1.1, align 8
define i32 @main() {
	%a = alloca i32, align 4
	store i32 -111, i32* %a, align 4
	%b = alloca double, align 8
	%1 = fadd double 1.0, 12.0
	store double %1, double* %b, align 8
	%c = alloca i32, align 4
	store i32 108, i32* %c, align 4
	%2 = call i32 @putchar(i32 104)
	%3 = call i32 @putchar(i32 101)
	%4 = load i32, i32* %c, align 4
	%5 = call i32 @putchar(i32 %4)
	%6 = load i32, i32* %c, align 4
	%7 = call i32 @putchar(i32 %6)
	%8 = load i32, i32* %a, align 4
	%9 = sub nsw i32 0, %8
	%10 = call i32 @putchar(i32 %9)
	%11 = call i32 @putchar(i32 10)
	%l = alloca i32, align 4
	store i32 97, i32* %l, align 4
	store i32 122, i32* %l, align 4
	%12 = load i32, i32* %l, align 4
	%aux1 = alloca i32
	store i32 1, i32* %aux1
	%13 = load i32, i32* %aux1
	%14 = icmp ne i32 %13, 0
	br i1 %14, label %label1, label %label2

	label1:
	%15 = load i32, i32* %l, align 4
	%16 = call i32 @putchar(i32 %15)
	br label %label2

	label2:
	%f = alloca i32, align 4
	%17 = call i32 @factorial(i32 5)
	store i32 %17, i32* %f, align 4
	ret i32 1
}

define i32 @f7(i32 %l1, i32 %l2, i32 %l3) {
	%g = alloca i32, align 4
	%1 = alloca i32, align 4
	store i32 %l1, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = icmp sgt i32 %2, 1
	%4 = zext i1 %3 to i32
	%5 = icmp ne i32 %4, 0
	br i1 %5, label %label1, label %label2

	label1:
	%6 = alloca i32, align 4
	store i32 %l1, i32* %6, align 4
	%7 = load i32, i32* %6, align 4
	%8 = alloca i32, align 4
	store i32 %l2, i32* %8, align 4
	%9 = load i32, i32* %8, align 4
	%10 = add i32 %7, %9
	store i32 %10, i32* %g, align 4
	br label %label3

	label2:
		%11 = alloca i32, align 4
	store i32 %l1, i32* %11, align 4
	%12 = load i32, i32* %11, align 4
	%13 = alloca i32, align 4
	store i32 %l3, i32* %13, align 4
	%14 = load i32, i32* %13, align 4
	%15 = add i32 %12, %14
ret i32 %15
	label3:
		%16 = load i32, i32* %g, align 4
ret i32 %16
}

define i32 @factorial(i32 %x) {
	%1 = alloca i32, align 4
	store i32 %x, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = icmp eq i32 %2, 1
	%4 = zext i1 %3 to i32
	%5 = icmp ne i32 %4, 0
	br i1 %5, label %label1, label %label2

	label1:
	ret i32 1
	label2:
		%6 = alloca i32, align 4
	store i32 %x, i32* %6, align 4
	%7 = load i32, i32* %6, align 4
	%8 = alloca i32, align 4
	store i32 %x, i32* %8, align 4
	%9 = load i32, i32* %8, align 4
	%10 = sub i32 %9, 1
	%11 = call i32 @factorial(i32 %10)
	%12 = mul i32 %7, %11
ret i32 %12
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
	store i32 3, i32* %c2, align 4
	%c4 = alloca i16, align 2
	store i16 2, i16* %c4, align 2
	%c3 = alloca double, align 8
	store double 1.2, double* %c3, align 8
	%1 = load i32, i32* %c2, align 4
	%2 = icmp ne i32 %1, 0
	%3 = xor i1 %2, true
	%4 = sitofp i1 %3 to double
	%5 = load double, double* %c3, align 8
	%6 = fmul double %4, %5
	%7 = load i32, i32* %c1, align 4
	%8 = sitofp i32 %7 to double
	%9 = fdiv double %6, %8
	%10 = fadd double 5.0, %9
	%11 = fsub double -0.000000e+00, %10
	store double %11, double* %c3, align 8
	%12 = alloca i32, align 4
	store i32 %j1, i32* %12, align 4
	%13 = load i32, i32* %12, align 4
	%14 = call i32 @putchar(i32 %13)
	%15 = call i32 @putchar(i32 10)
	ret void
}

define i32 @empty() {
	ret i32 0
}

