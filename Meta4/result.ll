declare i32 @getchar()
declare i32 @putchar(i32)
@a = common global i32 0, align 4
@a1 = global i8 52, align 1
@a2 = common global i8 0, align 1
@a5 = global i16 1, align 2
@a3 = global double 1.1, align 8
define i32 @main() {
	%a = alloca i32, align 4
	%b = alloca i32, align 4
	%c = alloca i8, align 1
	%1 = load i32, i32* %a, align 4
ret i32 %1
}

define i32 @f7(i32 %l1, i32 %l2, i32 %l3) {
	%g1 = alloca i32, align 4
	%g3 = alloca i32, align 4
	%g2 = alloca i8, align 1
	store i8 98, i8* %g2, align 1
	ret i32 2
	store i32 2, i32* %g1, align 4
	ret i32 1
}

define i8 @jot(i32 %h0, i8 %h1, double %h2) {
	%b1 = alloca i32, align 4
	%b2 = alloca i32, align 4
	%b3 = alloca double, align 8
	%1 = load i32, i32* %b2, align 4
	store i32 %1, i32* %b1, align 4
	ret i8 103
}

define void @f9(i32 %j1, i8 %j2, double %j3) {
	%c1 = alloca i32, align 4
	%c2 = alloca i32, align 4
	%c3 = alloca double, align 8
	ret void
ret void
}

define i32 @empty() {
	ret i32 0
}

define double @factorial(i32 %x) {
	ret double (null)
}

