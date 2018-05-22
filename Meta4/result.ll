declare i32 @getchar()
declare i32 @putchar(i32)
@a = common global i32 0, align 4
@a1 = global i8 52, align 1
@a2 = common global i8 0, align 1
@a3 = global double 1.1, align 8
declare i8 @jot(i32, i8, double)

declare i32 @f7(i32, i32, i32)

declare void @f9(i32, i8, double)

define i32 @main() {
	ret i32 %a
}

define i32 @f7(i32 %l1, i32 %l2, i32 %l3) {
	ret i32 1
}

define i8 @jot(i32 %h0, i8 %h1, double %h2) {
	ret i32 103
}

define void @f9(i32 %j1, i8 %j2, double %j3) {
ret void
}

define i32 @empty() {
	ret i32 0
}

declare double @factorial(i32)

define double @factorial(i32 %x) {
	ret double (null)
}

