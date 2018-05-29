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
	store i32 5, i32* %l, align 4
	br label %label1

	label1:
	%12 = load i32, i32* %l, align 4
	%13 = icmp ne i32 %12, 0
	br i1 %13, label %label2, label %label3

	label2:
	%14 = icmp ne i32 1, 0
	br label %label3

	label3:
	%15 = phi i1 [ false, %label1 ], [ %14, %label2 ]
	%16 = zext i1 %15 to i32
	%17 = icmp ne i32 %16, 0
	br i1 %17, label %label4, label %label5

	label4:
	%18 = call i32 @putchar(i32 97)
	%19 = load i32, i32* %l, align 4
	%20 = sub i32 %19, 1
	store i32 %20, i32* %l, align 4
	br label %label1

	label5:
	%21 = icmp ne i32 1, 0
	br i1 %21, label %label6, label %label7

	label6:
	%22 = icmp ne i32 0, 0
	br label %label7

	label7:
	%23 = phi i1 [ false, %label5 ], [ %22, %label6 ]
	%24 = zext i1 %23 to i32
	%25 = icmp ne i32 %24, 0
	br i1 %25, label %label8, label %label9

	label8:
	%26 = call i32 @putchar(i32 98)
	br label %label10

	label9:
	%27 = call i32 @putchar(i32 110)
	br label %label10

	label10:
	%28 = load double, double* %b, align 8
	%29 = fcmp olt double %28, -4.0
	%30 = zext i1 %29 to i32
	%31 = icmp ne i32 %30, 0
	br i1 %31, label %label11, label %label12

	label11:
	%32 = call i32 @putchar(i32 52)
	br label %label12

	label12:
	ret i32 1
}

define i32 @f7(i32 %l1, i32 %l2, i32 %l3) {
	%g1 = alloca i32, align 4
	%g3 = alloca i32, align 4
	%g2 = alloca i8, align 1
	%1 = load i32, i32* %g1, align 4
	%2 = icmp slt i32 %1, 1
	%3 = zext i1 %2 to i32
	%4 = icmp ne i32 %3, 0
	br i1 %4, label %label1, label %label2

	label1:
	store i8 98, i8* %g2, align 1
	br label %label3

	label2:
	ret i32 2
	label3:
	%5 = load i32, i32* %g3, align 4
	%6 = load i32, i32* %g1, align 4
	%7 = icmp ne i32 %5, %6
	%8 = zext i1 %7 to i32
	%9 = icmp ne i32 %8, 0
	br i1 %9, label %label4, label %label5

	label4:
	store i32 2, i32* %g1, align 4
	br label %label5

	label5:
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
	ret void
}

define i32 @empty() {
	ret i32 0
}

