declare i32 @getchar()
declare i32 @putchar(i32)
@a = common global i32 0, align 4
@a1 = global i8 52, align 1
@a2 = common global i8 0, align 1
@a5 = global i16 1, align 2
@a3 = global double 1.1, align 8
define i32 @main() {
	%a = alloca i32, align 4
	store i32 1, i32* %a, align 4
	%b = alloca i32, align 4
	store i32 1, i32* %b, align 4
	%k = alloca i32, align 4
	%1 = load i32, i32* %a, align 4
	%2 = icmp ne i32 %1, 0
	br i1 %2, label %label1, label %label2

	label1:
	%3 = load i32, i32* %b, align 4
	%4 = icmp ne i32 %3, 0
	br label %label2

	label2:
	%5 = phi i1 [ false, %0 ], [ %4, %label1 ]
	%6 = zext i1 %5 to i32
	store i32 %6, i32* %k, align 4
	%7 = load i32, i32* %k, align 4
	%8 = icmp sgt i32 %7, 0
	%9 = zext i1 %8 to i32
	%10 = icmp eq i32 %9, 0
	%11 = zext i1 %10 to i32
	%12 = icmp ne i32 %11, 0
	br i1 %12, label %label4, label %label3

	label3:
	%13 = sub i32 2, 3
	store i32 %13, i32* %a, align 4
%14 = load i32, i32* %a, align 4
	%15 = icmp sge i32 1, %14
	%16 = zext i1 %15 to i32
	%17 = icmp ne i32 %16, 0
	br label %label4

	label4:
	%18 = phi i1 [ true, %label2 ], [ %17, %label3 ]
	%19 = zext i1 %18 to i32
	%20 = icmp ne i32 %19, 0
	%21 = xor i1 %20, true
	%22 = zext i1 %21 to i32
	%23 = icmp ne i32 %22, 0
	br i1 %23, label %label5, label %label6

	label5:
	%24 = icmp eq i32 2, 2
	%25 = zext i1 %24 to i32
	%26 = icmp ne i32 %25, 0
	br label %label6

	label6:
	%27 = phi i1 [ false, %label4 ], [ %26, %label5 ]
	%28 = zext i1 %27 to i32
	store i32 %28, i32* %b, align 4
		%29 = load i32, i32* %k, align 4
	%30 = icmp sgt i32 %29, 0
	%31 = zext i1 %30 to i32
	%32 = icmp eq i32 %31, 0
	%33 = zext i1 %32 to i32
	%34 = icmp ne i32 %33, 0
	br i1 %34, label %label8, label %label7

	label7:
	%35 = sub i32 2, 3
	store i32 %35, i32* %a, align 4
%36 = load i32, i32* %a, align 4
	%37 = icmp sge i32 1, %36
	%38 = zext i1 %37 to i32
	%39 = icmp ne i32 %38, 0
	br label %label8

	label8:
	%40 = phi i1 [ true, %label6 ], [ %39, %label7 ]
	%41 = zext i1 %40 to i32
	%42 = icmp ne i32 %41, 0
	br i1 %42, label %label9, label %label10

	label9:
	%43 = icmp eq i32 2, 2
	%44 = zext i1 %43 to i32
	%45 = icmp ne i32 %44, 0
	br label %label10

	label10:
	%46 = phi i1 [ false, %label8 ], [ %45, %label9 ]
	%47 = zext i1 %46 to i32
	%48 = icmp ne i32 %47, 0
	%49 = xor i1 %48, true
	%50 = zext i1 %49 to i32
	%51 = icmp ne i32 %50, 0
	%52 = xor i1 %51, true
	%53 = zext i1 %52 to i32
	%54 = sub nsw i32 0, %53
	%55 = add i32 %54, 49
	%56 = call i32 @putchar(i32 %55)
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

