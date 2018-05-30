declare i32 @getchar()
declare i32 @putchar(i32)
define i32 @readint() {
	%read = alloca i32, align 4
	store i32 0, i32* %read, align 4
	%sign = alloca i32, align 4
	store i32 1, i32* %sign, align 4
	%c = alloca i8, align 1
	%1 = call i32 @getchar()
	%2 = trunc i32 %1 to i8
	store i8 %2, i8* %c, align 1
	%3 = load i8, i8* %c, align 1
	%4 = sext i8 %3 to i32
	%5 = icmp eq i32 %4, 45
	%6 = zext i1 %5 to i32
	%7 = icmp ne i32 %6, 0
	br i1 %7, label %label1, label %label2

	label1:
	store i32 -1, i32* %sign, align 4
	br label %label2

	label2:
	br label %label3

	label3:
	%8 = load i8, i8* %c, align 1
	%9 = sext i8 %8 to i32
	%10 = icmp ne i32 %9, 10
	%11 = zext i1 %10 to i32
	%12 = icmp ne i32 %11, 0
	br i1 %12, label %label4, label %label5

	label4:
	%13 = load i8, i8* %c, align 1
	%14 = sext i8 %13 to i32
	%15 = icmp ne i32 %14, 45
	%16 = zext i1 %15 to i32
	%17 = icmp ne i32 %16, 0
	br i1 %17, label %label6, label %label7

	label6:
	%18 = load i32, i32* %read, align 4
	%19 = mul i32 %18, 10
	%20 = load i8, i8* %c, align 1
	%21 = sext i8 %20 to i32
	%22 = add i32 %19, %21
	%23 = sub i32 %22, 48
	store i32 %23, i32* %read, align 4
	br label %label7

	label7:
	%24 = call i32 @getchar()
	%25 = trunc i32 %24 to i8
	store i8 %25, i8* %c, align 1
	br label %label3

	label5:
	%26 = load i32, i32* %sign, align 4
	%27 = load i32, i32* %read, align 4
	%28 = mul i32 %26, %27
	ret i32 %28
}

define double @printint(double %n, i32 %f, i16 %g) {
	%1 = alloca double, align 8
	store double %n, double* %1, align 8
	%2 = alloca i32, align 4
	store i32 %f, i32* %2, align 4
	%3 = alloca i16, align 2
	store i16 %g, i16* %3, align 2
	%4 = load i32, i32* %2, align 4
	%5 = load i16, i16* %3, align 2
	%6 = sext i16 %5 to i32
	%7 = add i32 %4, %6
	%8 = sitofp i32 %7 to double
	store double %8, double* %1, align 8
	%9 = load i16, i16* %3, align 2
	%10 = sext i16 %9 to i32
	store i32 %10, i32* %2, align 4
	%11 = mul i32 2, 4
	%12 = sdiv i32 %11, 2
	store i32 %12, i32* %2, align 4
	%13 = load i32, i32* %2, align 4
	%14 = add i32 %13, 48
	%15 = call i32 @putchar(i32 %14)
	%16 = load i32, i32* %2, align 4
	%17 = trunc i32 %16 to i16
	store i16 %17, i16* %3, align 2
	%18 = load i32, i32* %2, align 4
	%19 = sdiv i32 %18, 2
	store i32 %19, i32* %2, align 4
	%20 = load i16, i16* %3, align 2
	%21 = sext i16 %20 to i32
	%22 = add i32 %21, 48
	%23 = call i32 @putchar(i32 %22)
	%24 = load i32, i32* %2, align 4
	%25 = add i32 %24, 48
	%26 = call i32 @putchar(i32 %25)
	%27 = load double, double* %1, align 8
	ret double %27
}

define i32 @main() {
	%c = alloca double, align 8
	%1 = call double @printint(double 10.0,i32 4,i16 2)
	store double %1, double* %c, align 8
	%2 = load double, double* %c, align 8
	%3 = fcmp ogt double %2, 5.0
	%4 = zext i1 %3 to i32
	%5 = icmp ne i32 %4, 0
	br i1 %5, label %label1, label %label2

	label1:
	%6 = load double, double* %c, align 8
	%7 = fcmp olt double %6, 7.0
	%8 = zext i1 %7 to i32
	%9 = icmp ne i32 %8, 0
	br label %label2

	label2:
	%10 = phi i1 [ false, %0 ], [ %9, %label1 ]
	%11 = zext i1 %10 to i32
	%12 = icmp ne i32 %11, 0
	br i1 %12, label %label3, label %label4

	label3:
	%13 = call i32 @putchar(i32 10)
	br label %label4

	label4:
	ret i32 1
}

