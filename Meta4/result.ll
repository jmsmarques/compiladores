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
	%3 = icmp ne i16 %2, 0
	br label %label2

	label2:
	%4 = phi i1 [ false, %0 ], [ %3, %label1 ]
	%5 = zext i1 %4 to i8
	store i8 %5, i8* %k, align 1
	%6 = load i8, i8* %k, align 1
	%7 = sext i8 %6 to i32
	%8 = icmp sgt i32 %7, 0
	%9 = zext i1 %8 to i32
	%10 = icmp eq i32 %9, 0
	%11 = zext i1 %10 to i32
	%12 = sub i32 2, 3
	store i32 %12, i32* %a, align 4
	%13 = load i32, i32* %a, align 4
	%14 = icmp sge i32 1, %13
	%15 = zext i1 %14 to i32
	%16 = and i32 %11, %15
	%17 = icmp ne i32 %16, 0
	%18 = xor i1 %17, true
	%19 = zext i1 %18 to i32
	%20 = icmp ne i32 %19, 0
	br i1 %20, label %label3, label %label4

	label3:
	%21 = icmp eq i32 -2, 2
	%22 = zext i1 %21 to i32
	%23 = or i32 %22, 5
	%24 = icmp ne i32 %23, 0
	br label %label4

	label4:
	%25 = phi i1 [ false, %label2 ], [ %24, %label3 ]
	%26 = zext i1 %25 to i32
	%27 = icmp ne i32 %26, 0
	br i1 %27, label %label5, label %label6

	label5:
	%28 = xor i32 -4, 5
	%29 = icmp ne i32 %28, 0
	br label %label6

	label6:
	%30 = phi i1 [ false, %label4 ], [ %29, %label5 ]
	%31 = zext i1 %30 to i16
	store i16 %31, i16* %b, align 2
	%32 = load i16, i16* %b, align 2
	%33 = sext i16 %32 to i32
	%34 = add i32 %33, 48
	%35 = call i32 @putchar(i32 %34)
	%36 = load i32, i32* %a, align 4
	%37 = add i32 %36, 48
	%38 = call i32 @putchar(i32 %37)
	%39 = load i8, i8* %k, align 1
	%40 = sext i8 %39 to i32
	%41 = add i32 %40, 48
	%42 = call i32 @putchar(i32 %41)
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

