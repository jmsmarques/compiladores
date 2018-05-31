declare i32 @getchar()
declare i32 @putchar(i32)
define void @teste(double %a, double %c) {
	%1 = alloca double, align 8
	store double %a, double* %1, align 8
	%2 = alloca double, align 8
	store double %c, double* %2, align 8
	store double 98.0, double* %1, align 8
	%3 = load double, double* %1, align 8
	%4 = load double, double* %2, align 8
	%5 = fadd double %3, %4
	store double %5, double* %2, align 8
	ret void
}

define i32 @main() {
	call void @teste(double 1.0,double 2.e2)
	%1 = alloca i32, align 4
	%2 = load i32, i32* %1, align 4
	ret i32 %2
}

