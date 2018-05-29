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
	%13 = icmp slt i32 %12, 1000
	%14 = zext i1 %13 to i32
	%15 = icmp ne i32 %14, 0
	br i1 %15, label %label2, label %label3

	label2:
		%16 = call i32 @putchar(i32 111)
		%17 = load i32, i32* %l, align 4
		%18 = add i32 %17, 1
		store i32 %18, i32* %l, align 4
		%19 = load i32, i32* %l, align 4
		%20 = icmp sgt i32 %19, 500
		%21 = zext i1 %20 to i32
		%22 = icmp ne i32 %21, 0
		br i1 %22, label %label4, label %label5

		label4:
		%23 = call i32 @putchar(i32 105)
		br label %label5

		label5:
	br label %label1
	label3:
	ret i32 1
}

