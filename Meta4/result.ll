declare i32 @getchar()
declare i32 @putchar(i32)
@a = global double 1.0, align 8
define i8 @teste(double %a, double %c, i8 signext %d) {
	%1 = alloca double, align 8
	store double %a, double* %1, align 8
	%2 = alloca double, align 8
	store double %c, double* %2, align 8
	%3 = alloca i8, align 1
	store i8 %d, i8* %3, align 1
	store double 98.0, double* %1, align 8
	store i8 4, i8* %3, align 1
	%4 = load i8, i8* %3, align 1
	%5 = sitofp i8 %4 to double
	%6 = fadd double 3.0e1, %5
	store double %6, double* %1, align 8
	%7 = load double, double* %1, align 8
	%8 = load double, double* %2, align 8
	%9 = fadd double %7, %8
	store double %9, double* %2, align 8
	%g = alloca i8, align 1
	store i8 48, i8* %g, align 1
	%k = alloca double, align 8
	store double 3.0, double* %k, align 8
	%j = alloca double, align 8
	%10 = load double, double* %k, align 8
	%11 = load double, double* %k, align 8
	%12 = fcmp oeq double %10, %11
	%13 = zext i1 %12 to i32
	%14 = load double, double* %1, align 8
	%15 = load double, double* %1, align 8
	%16 = fsub double -0.000000e+00, %15
	%17 = fcmp one double %14, %16
	%18 = zext i1 %17 to i32
	%19 = add i32 %13, %18
	%20 = sitofp i32 %19 to double
	store double %20, double* %j, align 8
	%21 = call i32 @putchar(i32 102)
	%22 = call i32 @putchar(i32 10)
	%23 = load i8, i8* %3, align 1
	ret i8 %23
}

define i32 @cao(double %a, i32 %b, i16 signext %c, i8 signext %d) {
	%1 = alloca double, align 8
	store double %a, double* %1, align 8
	%2 = alloca i32, align 4
	store i32 %b, i32* %2, align 4
	%3 = alloca i16, align 2
	store i16 %c, i16* %3, align 2
	%4 = alloca i8, align 1
	store i8 %d, i8* %4, align 1
	%5 = load i32, i32* %2, align 4
	%6 = trunc i32 %5 to i8
	store i8 %6, i8* %4, align 1
	%7 = load i8, i8* %4, align 1
	%8 = sext i8 %7 to i32
	%9 = add i32 %8, 48
	%10 = call i32 @putchar(i32 %9)
	%11 = load i16, i16* %3, align 2
	%12 = sitofp i16 %11 to double
	store double %12, double* %1, align 8
	%13 = load i8, i8* %4, align 1
	%14 = sext i8 %13 to i16
	store i16 %14, i16* %3, align 2
	%15 = load i16, i16* %3, align 2
	%16 = sext i16 %15 to i32
	%17 = add i32 %16, 48
	%18 = call i32 @putchar(i32 %17)
	%19 = load i16, i16* %3, align 2
	%20 = load i8, i8* %4, align 1
	%21 = sext i8 %20 to i16
	%22 = mul i16 %19, %21
	%23 = sext i16 %22 to i32
	%24 = srem i32 %23, 2
	store i32 %24, i32* %2, align 4
	%25 = load i32, i32* %2, align 4
	ret i32 %25
}

define i16 @fl() {
	ret i16 48
}

define void @troll(i32 %a) {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = add i32 %2, 48
	%4 = call i32 @putchar(i32 %3)
	ret void
}

define i8 @volta(double %a, i32 %b) {
	%1 = alloca double, align 8
	store double %a, double* %1, align 8
	%2 = alloca i32, align 4
	store i32 %b, i32* %2, align 4
	%f = alloca i16, align 2
	store i16 2, i16* %f, align 2
	%l = alloca i8, align 1
	%3 = load i32, i32* %2, align 4
	%4 = trunc i32 %3 to i8
	store i8 %4, i8* %l, align 1
	%5 = load i16, i16* %f, align 2
	%6 = sitofp i16 %5 to double
	store double %6, double* %1, align 8
	%7 = call i16 @fl()
	%8 = load i32, i32* %2, align 4
	%9 = trunc i32 %8 to i8
	store i8 %9, i8* %l, align 1
	%10 = load i8, i8* %l, align 1
	%jorge11 = alloca double
	store double 2., double* %jorge11
	%11 = load double, double* %jorge11
	%12 = call i16 @fl()
	%13 = trunc i16 %12 to i8
	%14 = call i8 @teste(double 2.0,double %11,i8 signext %13)
	%15 = sext i8 %14 to i16
	%16 = add i16 %7, %15
	%17 = sext i16 %16 to i32
	store i32 %17, i32* %2, align 4
	%18 = load i32, i32* %2, align 4
	%19 = call i32 @putchar(i32 %18)
	%20 = call i16 @fl()
	%21 = load i32, i32* %2, align 4
	%22 = trunc i32 %21 to i8
	store i8 %22, i8* %l, align 1
	%23 = load i8, i8* %l, align 1
	%jorge24 = alloca double
	store double 2., double* %jorge24
	%24 = load double, double* %jorge24
	%25 = call i16 @fl()
	%26 = trunc i16 %25 to i8
	%27 = call i8 @teste(double 2.0,double %24,i8 signext %26)
	%28 = sext i8 %27 to i16
	%29 = add i16 %20, %28
	%30 = sext i16 %29 to i32
	store i32 %30, i32* %2, align 4
	%31 = load i32, i32* %2, align 4
	%32 = trunc i32 %31 to i8
	ret i8 %32
}

define i32 @volta3(i32 %a) {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = add i32 %2, 3
	store i32 %3, i32* %1, align 4
	%4 = load i32, i32* %1, align 4
	ret i32 %4
}

define i32 @volta2(i32 %a) {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = add i32 %2, 2
	store i32 %3, i32* %1, align 4
	%f = alloca i32, align 4
	%4 = load i32, i32* %1, align 4
	%5 = call i32 @volta3(i32 %4)
	store i32 %5, i32* %f, align 4
	%6 = load i32, i32* %f, align 4
	ret i32 %6
}

define i32 @volta1(i32 %a) {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%b = alloca i32, align 4
	store i32 2, i32* %b, align 4
	%2 = load i32, i32* %1, align 4
	%3 = add i32 %2, 1
	store i32 %3, i32* %1, align 4
	%4 = load i32, i32* %1, align 4
	%5 = call i32 @volta2(i32 %4)
	ret i32 %5
}

define i32 @func(i32 %a, i16 signext %b, i8 signext %c, double %d) {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%2 = alloca i16, align 2
	store i16 %b, i16* %2, align 2
	%3 = alloca i8, align 1
	store i8 %c, i8* %3, align 1
	%4 = alloca double, align 8
	store double %d, double* %4, align 8
	%5 = load i32, i32* %1, align 4
	%6 = add i32 %5, 48
	%7 = call i32 @putchar(i32 %6)
	%8 = load i16, i16* %2, align 2
	%9 = sext i16 %8 to i32
	%10 = add i32 %9, 48
	%11 = call i32 @putchar(i32 %10)
	%12 = load i8, i8* %3, align 1
	%13 = sext i8 %12 to i32
	%14 = add i32 %13, 48
	%15 = call i32 @putchar(i32 %14)
	%16 = load double, double* %4, align 8
	%17 = fcmp oeq double %16, 100.0
	%18 = zext i1 %17 to i32
	%19 = add i32 %18, 48
	%20 = call i32 @putchar(i32 %19)
	ret i32 0
}

define i32 @main() {
	%p = alloca i32, align 4
	store i32 0, i32* %p, align 4
	%1 = load i32, i32* %p, align 4
	%2 = icmp ne i32 %1, 0
	%3 = xor i1 %2, true
	%4 = zext i1 %3 to i32
	%5 = load i32, i32* %p, align 4
	%6 = icmp ne i32 %5, 0
	%7 = xor i1 %6, true
	%8 = zext i1 %7 to i32
	%9 = add i32 %4, %8
	%10 = add i32 %9, 48
	%11 = call i32 @putchar(i32 %10)
	%12 = call i32 @volta1(i32 1)
	%13 = add i32 %12, 48
	%14 = call i32 @putchar(i32 %13)
	%g = alloca i32, align 4
	store i32 5, i32* %g, align 4
	%15 = load i32, i32* %g, align 4
	%16 = load i32, i32* %g, align 4
	%17 = icmp eq i32 %15, %16
	%18 = zext i1 %17 to i32
	%19 = load i32, i32* %g, align 4
	%20 = load i32, i32* %g, align 4
	%21 = icmp ne i32 %19, %20
	%22 = zext i1 %21 to i32
	%23 = add i32 %22, 48
	%24 = add i32 %18, %23
	%25 = call i32 @putchar(i32 %24)
	%26 = call i32 @cao(double 1.0,i32 2,i16 signext 3,i8 signext 4)
	%27 = call i32 @putchar(i32 %26)
	%a = alloca i32, align 4
	store i32 97, i32* %a, align 4
	%b = alloca i16, align 2
	store i16 98, i16* %b, align 2
	%c = alloca i8, align 1
	store i8 99, i8* %c, align 1
	%d = alloca double, align 8
	store double 100.0, double* %d, align 8
	%28 = call i32 @func(i32 1,i16 signext 1,i8 signext 1,double 1.0)
	call void @troll(i32 0)
	%29 = load i32, i32* %a, align 4
	%30 = load i32, i32* %a, align 4
	%31 = trunc i32 %30 to i16
	%32 = load i32, i32* %a, align 4
	%33 = trunc i32 %32 to i8
	%34 = load i32, i32* %a, align 4
	%35 = sitofp i32 %34 to double
	%36 = call i32 @func(i32 %29,i16 signext %31,i8 signext %33,double %35)
	%37 = load i32, i32* %a, align 4
	call void @troll(i32 %37)
	%38 = load i16, i16* %b, align 2
	%39 = sext i16 %38 to i32
	%40 = load i16, i16* %b, align 2
	%41 = load i16, i16* %b, align 2
	%42 = trunc i16 %41 to i8
	%43 = load i16, i16* %b, align 2
	%44 = sitofp i16 %43 to double
	%45 = call i32 @func(i32 %39,i16 signext %40,i8 signext %42,double %44)
	%46 = load i16, i16* %b, align 2
	%47 = sext i16 %46 to i32
	call void @troll(i32 %47)
	%48 = load i8, i8* %c, align 1
	%49 = sext i8 %48 to i32
	call void @troll(i32 %49)
	%50 = load i8, i8* %c, align 1
	%51 = sext i8 %50 to i32
	%52 = load i8, i8* %c, align 1
	%53 = sext i8 %52 to i16
	%54 = load i8, i8* %c, align 1
	%55 = load i8, i8* %c, align 1
	%56 = sitofp i8 %55 to double
	%57 = call i32 @func(i32 %51,i16 signext %53,i8 signext %54,double %56)
	%58 = load i32, i32* %a, align 4
	%59 = load i16, i16* %b, align 2
	%60 = load i8, i8* %c, align 1
	%61 = load double, double* %d, align 8
	%62 = call i32 @func(i32 %58,i16 signext %59,i8 signext %60,double %61)
	%63 = alloca i32, align 4
	%64 = load i32, i32* %63, align 4
	ret i32 %64
}

