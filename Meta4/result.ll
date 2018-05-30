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

define void @printint(i32 %n) {
	%1 = alloca i32, align 4
	store i32 %n, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = icmp slt i32 %2, 0
	%4 = zext i1 %3 to i32
	%5 = icmp ne i32 %4, 0
	br i1 %5, label %label1, label %label2

	label1:
	%6 = call i32 @putchar(i32 45)
	%7 = load i32, i32* %1, align 4
	%8 = sub nsw i32 0, %7
	store i32 %8, i32* %1, align 4
	br label %label2

	label2:
	%9 = load i32, i32* %1, align 4
	%10 = sdiv i32 %9, 10
	%11 = icmp ne i32 %10, 0
	br i1 %11, label %label3, label %label4

	label3:
	%12 = load i32, i32* %1, align 4
	%13 = sdiv i32 %12, 10
	call void @printint(i32 %13)
	br label %label4

	label4:
	%14 = load i32, i32* %1, align 4
	%15 = srem i32 %14, 10
	%16 = add i32 %15, 48
	%17 = call i32 @putchar(i32 %16)
	ret void
}

define i32 @main() {
	%i = alloca i32, align 4
	store i32 1, i32* %i, align 4
	br label %label1

	label1:
	%1 = load i32, i32* %i, align 4
	%2 = icmp ne i32 %1, 0
	%3 = zext i1 %2 to i32
	%4 = icmp ne i32 %3, 0
	br i1 %4, label %label2, label %label3

	label2:
	%5 = call i32 @readint()
	store i32 %5, i32* %i, align 4
	%6 = load i32, i32* %i, align 4
	call void @printint(i32 %6)
	%7 = call i32 @putchar(i32 10)
	br label %label1
	label3:
%8 = alloca i32, align 4
%9 = load i32, i32* %8, align 4
ret i32 %9
}

