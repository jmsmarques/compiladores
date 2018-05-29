declare i32 @getchar()
declare i32 @putchar(i32)
@a = common global i32 0, align 4
@a1 = global i8 52, align 1
@a2 = common global i8 0, align 1
@a5 = global i16 1, align 2
@a3 = global double 1.1, align 8
define i32 @main() {
	%a = alloca i32, align 4
	store i32 0, i32* %a, align 4
	%b = alloca i16, align 2
	store i16 1, i16* %b, align 2
	%k = alloca i8, align 1
	%1 = icmp ne i32 1, 0
	br i1 %1, label %label1, label %label2

	label1:
	%2 = load i16, i16* %b, align 2
	%3 = sext i16 %2 to i32
	%4 = call i32 @putchar(i32 97)
	%5 = add i32 %3, %4
	%6 = icmp ne i32 %5, 0
	br label %label2

	label2:
	%7 = phi i1 [ false, %0 ], [ %6, %label1 ]
	%8 = zext i1 %7 to i8
	store i8 %8, i8* %k, align 1
	%9 = load i8, i8* %k, align 1
	%10 = sext i8 %9 to i32
	%11 = icmp sgt i32 %10, 0
	%12 = zext i1 %11 to i32
	%13 = icmp eq i32 %12, 0
	%14 = zext i1 %13 to i32
	%15 = sub i32 2, 3
	store i32 %15, i32* %a, align 4
	%16 = load i32, i32* %a, align 4
	%17 = icmp sge i32 1, %16
	%18 = zext i1 %17 to i32
	%19 = and i32 %14, %18
	%20 = icmp ne i32 %19, 0
	%21 = xor i1 %20, true
	%22 = zext i1 %21 to i32
	%23 = icmp ne i32 %22, 0
	br i1 %23, label %label3, label %label4

	label3:
	%24 = icmp eq i32 -2, 2
	%25 = zext i1 %24 to i32
	%26 = or i32 %25, 5
	%27 = icmp ne i32 %26, 0
	br label %label4

	label4:
	%28 = phi i1 [ false, %label2 ], [ %27, %label3 ]
	%29 = zext i1 %28 to i32
	%30 = icmp ne i32 %29, 0
	br i1 %30, label %label5, label %label6

	label5:
	%31 = xor i32 -4, 5
	%32 = icmp ne i32 %31, 0
	br label %label6

	label6:
	%33 = phi i1 [ false, %label4 ], [ %32, %label5 ]
	%34 = zext i1 %33 to i16
	store i16 %34, i16* %b, align 2
	%35 = load i16, i16* %b, align 2
	%36 = sext i16 %35 to i32
	%37 = add i32 %36, 48
	%38 = call i32 @putchar(i32 %37)
	%39 = load i32, i32* %a, align 4
	%40 = add i32 %39, 48
	%41 = call i32 @putchar(i32 %40)
	%42 = load i8, i8* %k, align 1
	%43 = sext i8 %42 to i32
	%44 = add i32 %43, 48
	%45 = call i32 @putchar(i32 %44)
	ret i32 1
}

define i32 @f7(i32 %l1, i32 %l2, i32 %l3) {
	%g1 = alloca i32, align 4
	%g3 = alloca i32, align 4
	%g2 = alloca i8, align 1
	%1 = load i32, i32* %g1, align 4
	%2 = icmp slt i32 %1, 1
	br i1 %2, label %label1, label %label2

	label1:
	store i8 98, i8* %g2, align 1
	br label %label3

	label2:
	ret i32 2
	label3:
	%3 = load i32, i32* %g3, align 4
	%4 = load i32, i32* %g1, align 4
	%5 = icmp ne i32 %3, %4
	br i1 %5, label %label4, label %label5

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

