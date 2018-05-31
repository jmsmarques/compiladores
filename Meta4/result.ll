declare i32 @getchar()
declare i32 @putchar(i32)
define void @func(i32 %a) {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	store i32 2, i32* %1, align 4
	ret void
}

define void @testa_rel() {
	%a = alloca i32, align 4
	%b = alloca i32, align 4
	%c = alloca i32, align 4
	store i32 1, i32* %a, align 4
	store i32 2, i32* %b, align 4
	store i32 1, i32* %c, align 4
	%1 = load i32, i32* %a, align 4
	%2 = load i32, i32* %b, align 4
	%3 = icmp slt i32 %1, %2
	%4 = zext i1 %3 to i32
	%5 = load i32, i32* %c, align 4
	%6 = icmp slt i32 %4, %5
	%7 = zext i1 %6 to i32
	%8 = icmp ne i32 %7, 0
	br i1 %8, label %label1, label %label2

	label1:
	%9 = call i32 @putchar(i32 115)
	br label %label3

	label2:
	%10 = call i32 @putchar(i32 110)
	br label %label3

	label3:
	store i32 10, i32* %a, align 4
	%11 = load i32, i32* %a, align 4
	%12 = load i32, i32* %b, align 4
	%13 = icmp slt i32 %11, %12
	%14 = zext i1 %13 to i32
	%15 = load i32, i32* %c, align 4
	%16 = icmp slt i32 %14, %15
	%17 = zext i1 %16 to i32
	%18 = icmp ne i32 %17, 0
	br i1 %18, label %label4, label %label5

	label4:
	%19 = call i32 @putchar(i32 115)
	br label %label6

	label5:
	%20 = call i32 @putchar(i32 110)
	br label %label6

	label6:
	store i32 10, i32* %a, align 4
	store i32 10, i32* %b, align 4
	%21 = load i32, i32* %a, align 4
	%22 = load i32, i32* %b, align 4
	%23 = icmp slt i32 %21, %22
	%24 = zext i1 %23 to i32
	%25 = load i32, i32* %b, align 4
	%26 = load i32, i32* %c, align 4
	%27 = icmp slt i32 %25, %26
	%28 = zext i1 %27 to i32
	%29 = icmp eq i32 %24, %28
	%30 = zext i1 %29 to i32
	%31 = icmp ne i32 %30, 0
	br i1 %31, label %label7, label %label8

	label7:
	%32 = call i32 @putchar(i32 115)
	br label %label9

	label8:
	%33 = call i32 @putchar(i32 110)
	br label %label9

	label9:
	ret void
}

define i32 @main() {
	%a = alloca i32, align 4
	store i32 0, i32* %a, align 4
	%1 = load i32, i32* %a, align 4
	%2 = add i32 %1, 48
	%3 = call i32 @putchar(i32 %2)
	%4 = load i32, i32* %a, align 4
	call void @func(i32 %4)
	%5 = load i32, i32* %a, align 4
	%6 = add i32 %5, 48
	%7 = call i32 @putchar(i32 %6)
	%8 = call i32 @putchar(i32 10)
	call void @testa_rel()
	%f = alloca i32, align 4
	%9 = add i32 20, 1
	%10 = icmp eq i32 20, %9
	%11 = zext i1 %10 to i32
	store i32 %11, i32* %f, align 4
	%12 = load i32, i32* %f, align 4
	%13 = add i32 %12, 48
	%14 = call i32 @putchar(i32 %13)
	%b = alloca i16, align 2
	store i16 0, i16* %b, align 2
	%m = alloca double, align 8
	%15 = and i32 97, 97
	%16 = sitofp i32 %15 to double
	store double %16, double* %m, align 8
	%n = alloca double, align 8
	%17 = load i16, i16* %b, align 2
	%18 = sext i16 %17 to i32
	%19 = load i16, i16* %b, align 2
	%20 = sext i16 %19 to i32
	%21 = and i32 %18, %20
	%22 = sitofp i32 %21 to double
	store double %22, double* %n, align 8
	%23 = load double, double* %n, align 8
	%24 = fadd double %23, 1.0
	%25 = load double, double* %m, align 8
	%26 = fsub double %24, %25
	%27 = fcmp olt double %26, 0.00000000001
	%28 = zext i1 %27 to i32
	%29 = icmp ne i32 %28, 0
	br i1 %29, label %label2, label %label1

	label1:
	%30 = load double, double* %m, align 8
	%31 = load double, double* %n, align 8
	%32 = fadd double %31, 1.0
	%33 = fsub double %30, %32
	%34 = fcmp olt double %33, 0.00000000001
	%35 = zext i1 %34 to i32
	%36 = icmp ne i32 %35, 0
	br label %label2

	label2:
	%37 = phi i1 [ true, %0 ], [ %36, %label1 ]
	%38 = zext i1 %37 to i32
	%39 = add i32 %38, 48
	%40 = call i32 @putchar(i32 %39)
	%i = alloca i32, align 4
	%41 = and i32 97, 97
	store i32 %41, i32* %i, align 4
	%h = alloca i32, align 4
	%42 = load i16, i16* %b, align 2
	%43 = sext i16 %42 to i32
	%44 = load i16, i16* %b, align 2
	%45 = sext i16 %44 to i32
	%46 = and i32 %43, %45
	store i32 %46, i32* %h, align 4
	%47 = load i32, i32* %i, align 4
	%48 = load i32, i32* %h, align 4
	%49 = add i32 %48, 1
	%50 = icmp eq i32 %47, %49
	%51 = zext i1 %50 to i32
	%52 = add i32 %51, 48
	%53 = call i32 @putchar(i32 %52)
	%54 = call i32 @putchar(i32 10)
	%o1 = alloca i32, align 4
	%o2 = alloca i32, align 4
	store i32 1, i32* %o2, align 4
	%55 = load i32, i32* %o2, align 4
	store i32 %55, i32* %o1, align 4
	%56 = load i32, i32* %o1, align 4
	%57 = add i32 %56, 48
	%58 = call i32 @putchar(i32 %57)
	%59 = load i32, i32* %o2, align 4
	%60 = add i32 %59, 48
	%61 = call i32 @putchar(i32 %60)
	%62 = call i32 @putchar(i32 10)
	%beta = alloca i32, align 4
	%63 = load i32, i32* %o1, align 4
	%64 = load i32, i32* %o2, align 4
	%65 = and i32 %63, %64
	store i32 %65, i32* %beta, align 4
	%66 = load i32, i32* %beta, align 4
	%67 = add i32 %66, 48
	%68 = call i32 @putchar(i32 %67)
	%69 = call i32 @putchar(i32 10)
	%o3 = alloca i16, align 2
	%o4 = alloca i16, align 2
	store i16 1, i16* %o4, align 2
	%70 = load i16, i16* %o4, align 2
	store i16 %70, i16* %o3, align 2
	%71 = load i16, i16* %o3, align 2
	%72 = sext i16 %71 to i32
	%73 = add i32 %72, 48
	%74 = call i32 @putchar(i32 %73)
	%75 = load i16, i16* %o4, align 2
	%76 = sext i16 %75 to i32
	%77 = add i32 %76, 48
	%78 = call i32 @putchar(i32 %77)
	%79 = call i32 @putchar(i32 10)
	%beta1 = alloca i32, align 4
	%80 = load i16, i16* %o3, align 2
	%81 = sext i16 %80 to i32
	%82 = load i16, i16* %o4, align 2
	%83 = sext i16 %82 to i32
	%84 = and i32 %81, %83
	store i32 %84, i32* %beta1, align 4
	%85 = load i32, i32* %beta1, align 4
	%86 = add i32 %85, 48
	%87 = call i32 @putchar(i32 %86)
	%88 = call i32 @putchar(i32 10)
	%o5 = alloca i8, align 1
	%o6 = alloca i8, align 1
	store i8 1, i8* %o6, align 1
	%89 = load i8, i8* %o6, align 1
	store i8 %89, i8* %o5, align 1
	%90 = load i8, i8* %o5, align 1
	%91 = sext i8 %90 to i32
	%92 = add i32 %91, 48
	%93 = call i32 @putchar(i32 %92)
	%94 = load i8, i8* %o6, align 1
	%95 = sext i8 %94 to i32
	%96 = add i32 %95, 48
	%97 = call i32 @putchar(i32 %96)
	%98 = call i32 @putchar(i32 10)
	%beta2 = alloca i32, align 4
	%99 = load i8, i8* %o5, align 1
	%100 = sext i8 %99 to i32
	%101 = load i8, i8* %o6, align 1
	%102 = sext i8 %101 to i32
	%103 = and i32 %100, %102
	store i32 %103, i32* %beta2, align 4
	%104 = load i32, i32* %beta2, align 4
	%105 = add i32 %104, 48
	%106 = call i32 @putchar(i32 %105)
	%107 = call i32 @putchar(i32 10)
	%o7 = alloca i8, align 1
	%o8 = alloca i8, align 1
	store i8 97, i8* %o8, align 1
	%108 = load i8, i8* %o8, align 1
	store i8 %108, i8* %o7, align 1
	%109 = load i8, i8* %o7, align 1
	%110 = sext i8 %109 to i32
	%111 = call i32 @putchar(i32 %110)
	%112 = load i8, i8* %o8, align 1
	%113 = sext i8 %112 to i32
	%114 = call i32 @putchar(i32 %113)
	%115 = call i32 @putchar(i32 10)
	%beta3 = alloca i32, align 4
	%116 = load i8, i8* %o7, align 1
	%117 = sext i8 %116 to i32
	%118 = load i8, i8* %o8, align 1
	%119 = sext i8 %118 to i32
	%120 = and i32 %117, %119
	store i32 %120, i32* %beta3, align 4
	%121 = load i32, i32* %beta3, align 4
	%122 = call i32 @putchar(i32 %121)
	%123 = call i32 @putchar(i32 10)
	ret i32 0
}

