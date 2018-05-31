; ModuleID = 'cheat.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define void @func(i32 %a) #0 {
  %1 = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 2, i32* %1, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define void @testa_rel() #0 {
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
  br i1 %6, label %7, label %9

; <label>:7                                       ; preds = %0
  %8 = call i32 @putchar(i32 115)
  br label %11

; <label>:9                                       ; preds = %0
  %10 = call i32 @putchar(i32 110)
  br label %11

; <label>:11                                      ; preds = %9, %7
  store i32 10, i32* %a, align 4
  %12 = load i32, i32* %a, align 4
  %13 = load i32, i32* %b, align 4
  %14 = icmp slt i32 %12, %13
  %15 = zext i1 %14 to i32
  %16 = load i32, i32* %c, align 4
  %17 = icmp slt i32 %15, %16
  br i1 %17, label %18, label %20

; <label>:18                                      ; preds = %11
  %19 = call i32 @putchar(i32 115)
  br label %22

; <label>:20                                      ; preds = %11
  %21 = call i32 @putchar(i32 110)
  br label %22

; <label>:22                                      ; preds = %20, %18
  store i32 10, i32* %a, align 4
  store i32 10, i32* %b, align 4
  %23 = load i32, i32* %a, align 4
  %24 = load i32, i32* %b, align 4
  %25 = icmp slt i32 %23, %24
  %26 = zext i1 %25 to i32
  %27 = load i32, i32* %b, align 4
  %28 = load i32, i32* %c, align 4
  %29 = icmp slt i32 %27, %28
  %30 = zext i1 %29 to i32
  %31 = icmp eq i32 %26, %30
  br i1 %31, label %32, label %34

; <label>:32                                      ; preds = %22
  %33 = call i32 @putchar(i32 115)
  br label %36

; <label>:34                                      ; preds = %22
  %35 = call i32 @putchar(i32 110)
  br label %36

; <label>:36                                      ; preds = %34, %32
  ret void
}

declare i32 @putchar(i32) #1

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %f = alloca i32, align 4
  %b = alloca i16, align 2
  %m = alloca double, align 8
  %n = alloca double, align 8
  %i = alloca i32, align 4
  %h = alloca i32, align 4
  %o1 = alloca i32, align 4
  %o2 = alloca i32, align 4
  %beta = alloca i32, align 4
  %o3 = alloca i16, align 2
  %o4 = alloca i16, align 2
  %beta1 = alloca i32, align 4
  %o5 = alloca i8, align 1
  %o6 = alloca i8, align 1
  %beta2 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 0, i32* %a, align 4
  %2 = load i32, i32* %a, align 4
  %3 = add nsw i32 %2, 48
  %4 = call i32 @putchar(i32 %3)
  %5 = load i32, i32* %a, align 4
  call void @func(i32 %5)
  %6 = load i32, i32* %a, align 4
  %7 = add nsw i32 %6, 48
  %8 = call i32 @putchar(i32 %7)
  %9 = call i32 @putchar(i32 10)
  call void @testa_rel()
  store i32 0, i32* %f, align 4
  %10 = load i32, i32* %f, align 4
  %11 = add nsw i32 %10, 48
  %12 = call i32 @putchar(i32 %11)
  store i16 0, i16* %b, align 2
  store double 9.700000e+01, double* %m, align 8
  %13 = load i16, i16* %b, align 2
  %14 = sext i16 %13 to i32
  %15 = load i16, i16* %b, align 2
  %16 = sext i16 %15 to i32
  %17 = and i32 %14, %16
  %18 = sitofp i32 %17 to double
  store double %18, double* %n, align 8
  %19 = load double, double* %n, align 8
  %20 = fadd double %19, 1.000000e+00
  %21 = load double, double* %m, align 8
  %22 = fsub double %20, %21
  %23 = fcmp olt double %22, 1.000000e-11
  br i1 %23, label %30, label %24

; <label>:24                                      ; preds = %0
  %25 = load double, double* %m, align 8
  %26 = load double, double* %n, align 8
  %27 = fadd double %26, 1.000000e+00
  %28 = fsub double %25, %27
  %29 = fcmp olt double %28, 1.000000e-11
  br label %30

; <label>:30                                      ; preds = %24, %0
  %31 = phi i1 [ true, %0 ], [ %29, %24 ]
  %32 = zext i1 %31 to i32
  %33 = add nsw i32 %32, 48
  %34 = call i32 @putchar(i32 %33)
  store i32 97, i32* %i, align 4
  %35 = load i16, i16* %b, align 2
  %36 = sext i16 %35 to i32
  %37 = load i16, i16* %b, align 2
  %38 = sext i16 %37 to i32
  %39 = and i32 %36, %38
  store i32 %39, i32* %h, align 4
  %40 = load i32, i32* %i, align 4
  %41 = load i32, i32* %h, align 4
  %42 = add nsw i32 %41, 1
  %43 = icmp eq i32 %40, %42
  %44 = zext i1 %43 to i32
  %45 = add nsw i32 %44, 48
  %46 = call i32 @putchar(i32 %45)
  %47 = call i32 @putchar(i32 10)
  store i32 1, i32* %o2, align 4
  store i32 1, i32* %o1, align 4
  %48 = load i32, i32* %o1, align 4
  %49 = add nsw i32 %48, 48
  %50 = call i32 @putchar(i32 %49)
  %51 = load i32, i32* %o2, align 4
  %52 = add nsw i32 %51, 48
  %53 = call i32 @putchar(i32 %52)
  %54 = call i32 @putchar(i32 10)
  %55 = load i32, i32* %o1, align 4
  %56 = load i32, i32* %o2, align 4
  %57 = and i32 %55, %56
  store i32 %57, i32* %beta, align 4
  %58 = load i32, i32* %beta, align 4
  %59 = add nsw i32 %58, 48
  %60 = call i32 @putchar(i32 %59)
  %61 = call i32 @putchar(i32 10)
  store i16 1, i16* %o4, align 2
  store i16 1, i16* %o3, align 2
  %62 = load i16, i16* %o3, align 2
  %63 = sext i16 %62 to i32
  %64 = add nsw i32 %63, 48
  %65 = call i32 @putchar(i32 %64)
  %66 = load i16, i16* %o4, align 2
  %67 = sext i16 %66 to i32
  %68 = add nsw i32 %67, 48
  %69 = call i32 @putchar(i32 %68)
  %70 = call i32 @putchar(i32 10)
  %71 = load i16, i16* %o3, align 2
  %72 = sext i16 %71 to i32
  %73 = load i16, i16* %o4, align 2
  %74 = sext i16 %73 to i32
  %75 = and i32 %72, %74
  store i32 %75, i32* %beta1, align 4
  %76 = load i32, i32* %beta1, align 4
  %77 = add nsw i32 %76, 48
  %78 = call i32 @putchar(i32 %77)
  %79 = call i32 @putchar(i32 10)
  store i8 1, i8* %o6, align 1
  store i8 1, i8* %o5, align 1
  %80 = load i8, i8* %o5, align 1
  %81 = sext i8 %80 to i32
  %82 = add nsw i32 %81, 48
  %83 = call i32 @putchar(i32 %82)
  %84 = load i8, i8* %o6, align 1
  %85 = sext i8 %84 to i32
  %86 = add nsw i32 %85, 48
  %87 = call i32 @putchar(i32 %86)
  %88 = call i32 @putchar(i32 10)
  %89 = load i8, i8* %o5, align 1
  %90 = sext i8 %89 to i32
  %91 = load i8, i8* %o6, align 1
  %92 = sext i8 %91 to i32
  %93 = and i32 %90, %92
  store i32 %93, i32* %beta2, align 4
  %94 = load i32, i32* %1, align 4
  ret i32 %94
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-24ubuntu7 (tags/RELEASE_381/final)"}
