; ModuleID = 'cheat.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@a = global double 1.000000e+00, align 8

; Function Attrs: nounwind uwtable
define signext i8 @teste(double %a, double %c, i8 signext %d) #0 {
  %1 = alloca double, align 8
  %2 = alloca double, align 8
  %3 = alloca i8, align 1
  %g = alloca i8, align 1
  %k = alloca double, align 8
  %j = alloca double, align 8
  store double %a, double* %1, align 8
  store double %c, double* %2, align 8
  store i8 %d, i8* %3, align 1
  store double 9.800000e+01, double* %1, align 8
  store i8 4, i8* %3, align 1
  store double 3.400000e+01, double* %1, align 8
  %4 = load double, double* %1, align 8
  %5 = load double, double* %2, align 8
  %6 = fadd double %4, %5
  store double %6, double* %2, align 8
  store i8 48, i8* %g, align 1
  store double 3.000000e+00, double* %k, align 8
  %7 = load double, double* %k, align 8
  %8 = load double, double* %k, align 8
  %9 = fcmp oeq double %7, %8
  %10 = zext i1 %9 to i32
  %11 = load double, double* %1, align 8
  %12 = load double, double* %1, align 8
  %13 = fsub double -0.000000e+00, %12
  %14 = fcmp une double %11, %13
  %15 = zext i1 %14 to i32
  %16 = add nsw i32 %10, %15
  %17 = sitofp i32 %16 to double
  store double %17, double* %j, align 8
  %18 = call i32 @putchar(i32 102)
  %19 = call i32 @putchar(i32 10)
  %20 = load i8, i8* %3, align 1
  ret i8 %20
}

declare i32 @putchar(i32) #1

; Function Attrs: nounwind uwtable
define i32 @cao(double %a, i32 %b, i16 signext %c, i8 signext %d) #0 {
  %1 = alloca double, align 8
  %2 = alloca i32, align 4
  %3 = alloca i16, align 2
  %4 = alloca i8, align 1
  store double %a, double* %1, align 8
  store i32 %b, i32* %2, align 4
  store i16 %c, i16* %3, align 2
  store i8 %d, i8* %4, align 1
  %5 = load i32, i32* %2, align 4
  %6 = trunc i32 %5 to i8
  store i8 %6, i8* %4, align 1
  %7 = load i8, i8* %4, align 1
  %8 = sext i8 %7 to i32
  %9 = add nsw i32 %8, 48
  %10 = call i32 @putchar(i32 %9)
  %11 = load i16, i16* %3, align 2
  %12 = sitofp i16 %11 to double
  store double %12, double* %1, align 8
  %13 = load i8, i8* %4, align 1
  %14 = sext i8 %13 to i16
  store i16 %14, i16* %3, align 2
  %15 = load i16, i16* %3, align 2
  %16 = sext i16 %15 to i32
  %17 = add nsw i32 %16, 48
  %18 = call i32 @putchar(i32 %17)
  %19 = load i16, i16* %3, align 2
  %20 = sext i16 %19 to i32
  %21 = load i8, i8* %4, align 1
  %22 = sext i8 %21 to i32
  %23 = mul nsw i32 %20, %22
  %24 = srem i32 %23, 2
  store i32 %24, i32* %2, align 4
  %25 = load i32, i32* %2, align 4
  ret i32 %25
}

; Function Attrs: nounwind uwtable
define signext i16 @fl() #0 {
  ret i16 48
}

; Function Attrs: nounwind uwtable
define void @troll(i32 %a) #0 {
  %1 = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = add nsw i32 %2, 48
  %4 = call i32 @putchar(i32 %3)
  %5 = load i32, i32* %1, align 4
  call void @troll(i32 %5)
  ret void
}

; Function Attrs: nounwind uwtable
define signext i8 @volta(double %a, i32 %b) #0 {
  %1 = alloca double, align 8
  %2 = alloca i32, align 4
  %f = alloca i16, align 2
  %l = alloca i8, align 1
  store double %a, double* %1, align 8
  store i32 %b, i32* %2, align 4
  store i16 2, i16* %f, align 2
  %3 = load i32, i32* %2, align 4
  %4 = trunc i32 %3 to i8
  store i8 %4, i8* %l, align 1
  %5 = load i16, i16* %f, align 2
  %6 = sitofp i16 %5 to double
  store double %6, double* %1, align 8
  %7 = call signext i16 @fl()
  %8 = sext i16 %7 to i32
  %9 = load i32, i32* %2, align 4
  %10 = trunc i32 %9 to i8
  store i8 %10, i8* %l, align 1
  %11 = call signext i16 @fl()
  %12 = trunc i16 %11 to i8
  %13 = call signext i8 @teste(double 2.000000e+00, double 2.000000e+00, i8 signext %12)
  %14 = sext i8 %13 to i32
  %15 = add nsw i32 %8, %14
  store i32 %15, i32* %2, align 4
  %16 = call i32 @putchar(i32 %15)
  %17 = call signext i16 @fl()
  %18 = sext i16 %17 to i32
  %19 = load i32, i32* %2, align 4
  %20 = trunc i32 %19 to i8
  store i8 %20, i8* %l, align 1
  %21 = call signext i16 @fl()
  %22 = trunc i16 %21 to i8
  %23 = call signext i8 @teste(double 2.000000e+00, double 2.000000e+00, i8 signext %22)
  %24 = sext i8 %23 to i32
  %25 = add nsw i32 %18, %24
  store i32 %25, i32* %2, align 4
  %26 = trunc i32 %25 to i8
  ret i8 %26
}

; Function Attrs: nounwind uwtable
define i32 @volta3(i32 %a) #0 {
  %1 = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = add nsw i32 %2, 3
  store i32 %3, i32* %1, align 4
  %4 = load i32, i32* %1, align 4
  ret i32 %4
}

; Function Attrs: nounwind uwtable
define i32 @volta2(i32 %a) #0 {
  %1 = alloca i32, align 4
  %f = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = add nsw i32 %2, 2
  store i32 %3, i32* %1, align 4
  %4 = load i32, i32* %1, align 4
  %5 = call i32 @volta3(i32 %4)
  store i32 %5, i32* %f, align 4
  %6 = load i32, i32* %f, align 4
  ret i32 %6
}

; Function Attrs: nounwind uwtable
define i32 @volta1(i32 %a) #0 {
  %1 = alloca i32, align 4
  %b = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 2, i32* %b, align 4
  %2 = load i32, i32* %1, align 4
  %3 = add nsw i32 %2, 1
  store i32 %3, i32* %1, align 4
  %4 = load i32, i32* %1, align 4
  %5 = call i32 @volta2(i32 %4)
  ret i32 %5
}

; Function Attrs: nounwind uwtable
define i32 @func(i32 %a, i16 signext %b, i8 signext %c, double %d) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i16, align 2
  %3 = alloca i8, align 1
  %4 = alloca double, align 8
  store i32 %a, i32* %1, align 4
  store i16 %b, i16* %2, align 2
  store i8 %c, i8* %3, align 1
  store double %d, double* %4, align 8
  %5 = load i32, i32* %1, align 4
  %6 = add nsw i32 %5, 48
  %7 = call i32 @putchar(i32 %6)
  %8 = load i16, i16* %2, align 2
  %9 = sext i16 %8 to i32
  %10 = add nsw i32 %9, 48
  %11 = call i32 @putchar(i32 %10)
  %12 = load i8, i8* %3, align 1
  %13 = sext i8 %12 to i32
  %14 = add nsw i32 %13, 48
  %15 = call i32 @putchar(i32 %14)
  %16 = load double, double* %4, align 8
  %17 = fcmp oeq double %16, 1.000000e+02
  %18 = zext i1 %17 to i32
  %19 = add nsw i32 %18, 48
  %20 = call i32 @putchar(i32 %19)
  ret i32 0
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %p = alloca i32, align 4
  %g = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i16, align 2
  %c = alloca i8, align 1
  %d = alloca double, align 8
  store i32 0, i32* %p, align 4
  %1 = load i32, i32* %p, align 4
  %2 = icmp ne i32 %1, 0
  %3 = xor i1 %2, true
  %4 = zext i1 %3 to i32
  %5 = load i32, i32* %p, align 4
  %6 = icmp ne i32 %5, 0
  %7 = xor i1 %6, true
  %8 = zext i1 %7 to i32
  %9 = add nsw i32 %4, %8
  %10 = add nsw i32 %9, 48
  %11 = call i32 @putchar(i32 %10)
  %12 = call i32 @volta1(i32 1)
  %13 = add nsw i32 %12, 48
  %14 = call i32 @putchar(i32 %13)
  store i32 5, i32* %g, align 4
  %15 = load i32, i32* %g, align 4
  %16 = load i32, i32* %g, align 4
  %17 = icmp eq i32 %15, %16
  %18 = zext i1 %17 to i32
  %19 = load i32, i32* %g, align 4
  %20 = load i32, i32* %g, align 4
  %21 = icmp ne i32 %19, %20
  %22 = zext i1 %21 to i32
  %23 = add nsw i32 %22, 48
  %24 = add nsw i32 %18, %23
  %25 = call i32 @putchar(i32 %24)
  %26 = call i32 @cao(double 1.000000e+00, i32 2, i16 signext 3, i8 signext 4)
  %27 = call i32 @putchar(i32 %26)
  store i32 97, i32* %a, align 4
  store i16 98, i16* %b, align 2
  store i8 99, i8* %c, align 1
  store double 1.000000e+02, double* %d, align 8
  %28 = call i32 @func(i32 1, i16 signext 1, i8 signext 1, double 1.000000e+00)
  call void @troll(i32 0)
  %29 = load i32, i32* %a, align 4
  %30 = load i32, i32* %a, align 4
  %31 = trunc i32 %30 to i16
  %32 = load i32, i32* %a, align 4
  %33 = trunc i32 %32 to i8
  %34 = load i32, i32* %a, align 4
  %35 = sitofp i32 %34 to double
  %36 = call i32 @func(i32 %29, i16 signext %31, i8 signext %33, double %35)
  %37 = load i32, i32* %a, align 4
  call void @troll(i32 %37)
  %38 = load i16, i16* %b, align 2
  %39 = sext i16 %38 to i32
  %40 = load i16, i16* %b, align 2
  %41 = load i16, i16* %b, align 2
  %42 = trunc i16 %41 to i8
  %43 = load i16, i16* %b, align 2
  %44 = sitofp i16 %43 to double
  %45 = call i32 @func(i32 %39, i16 signext %40, i8 signext %42, double %44)
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
  %57 = call i32 @func(i32 %51, i16 signext %53, i8 signext %54, double %56)
  %58 = load i32, i32* %a, align 4
  %59 = load i16, i16* %b, align 2
  %60 = load i8, i8* %c, align 1
  %61 = load double, double* %d, align 8
  %62 = call i32 @func(i32 %58, i16 signext %59, i8 signext %60, double %61)
  ret i32 0
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-24ubuntu7 (tags/RELEASE_381/final)"}
