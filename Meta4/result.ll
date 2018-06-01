declare i32 @getchar()
declare i32 @putchar(i32)
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

define void @print(i32 %x) {
	%1 = alloca i32, align 4
	store i32 %x, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	call void @printint(i32 %2)
	%3 = call i32 @putchar(i32 10)
	ret void
}

define i32 @main() {
	%p = alloca i32, align 4
	%q = alloca i8, align 1
	store i32 5, i32* %p, align 4
	store i8 1, i8* %q, align 1
	%1 = load i8, i8* %q, align 1
	call void @main2(i8 signext %1)
	ret i32 0
}

define void @main2(i8 signext %p) {
	%1 = alloca i8, align 1
	store i8 %p, i8* %1, align 1
	%2 = call i8 @q()
	%3 = sext i8 %2 to i32
	call void @print(i32 %3)
	%4 = call i8 @q()
	%5 = sext i8 %4 to i32
	call void @print(i32 %5)
	%6 = call i8 @q()
	%7 = sext i8 %6 to i32
	call void @print(i32 %7)
	%8 = call i8 @q()
	%9 = sext i8 %8 to i32
	call void @print(i32 %9)
	ret void
}

define i8 @q(i8 signext %p, i8 signext %q) {
	%1 = alloca i8, align 1
	store i8 %p, i8* %1, align 1
	%2 = alloca i8, align 1
	store i8 %q, i8* %2, align 1
	%3 = load i8, i8* %1, align 1
	%4 = icmp ne i8 %3, 0
	br i1 %4, label %label1, label %label2

	label1:
	%5 = load i8, i8* %2, align 1
	%6 = icmp ne i8 %5, 0
	%7 = xor i1 %6, true
	%8 = zext i1 %7 to i32
	%9 = icmp ne i32 %8, 0
	br label %label2

	label2:
	%10 = phi i1 [ false, %0 ], [ %9, %label1 ]
	%11 = zext i1 %10 to i8
	ret i8 %11
}

