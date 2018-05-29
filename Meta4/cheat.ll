; ModuleID = 'cheat.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@a = global i32 1, align 4
@a1 = global i8 52, align 1
@a5 = global i16 1, align 2
@a3 = global double 1.100000e+00, align 8
@a2 = common global i8 0, align 1

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i16, align 2
  %k = alloca i8, align 1
  store i32 0, i32* %1, align 4
  store i32 0, i32* %a, align 4
  store i16 1, i16* %b, align 2
  %2 = load i16, i16* %b, align 2
  %3 = sext i16 %2 to i32
  %4 = icmp ne i32 %3, 0
  %5 = zext i1 %4 to i32
  %6 = trunc i32 %5 to i8
  store i8 %6, i8* %k, align 1
  %7 = load i8, i8* %k, align 1
  %8 = sext i8 %7 to i32
  %9 = icmp sgt i32 %8, 0
  %10 = zext i1 %9 to i32
  %11 = icmp eq i32 %10, 0
  %12 = zext i1 %11 to i32
  store i32 -1, i32* %a, align 4
  %13 = and i32 %12, 1
  %14 = icmp ne i32 %13, 0
  br i1 %14, label %16, label %15

; <label>:15                                      ; preds = %0
  br label %16

; <label>:16                                      ; preds = %15, %0
  %17 = phi i1 [ false, %0 ], [ true, %15 ]
  %18 = zext i1 %17 to i32
  %19 = trunc i32 %18 to i16
  store i16 %19, i16* %b, align 2
  %20 = load i16, i16* %b, align 2
  %21 = sext i16 %20 to i32
  %22 = add nsw i32 %21, 48
  %23 = call i32 @putchar(i32 %22)
  %24 = load i32, i32* %a, align 4
  %25 = add nsw i32 %24, 48
  %26 = call i32 @putchar(i32 %25)
  %27 = load i8, i8* %k, align 1
  %28 = sext i8 %27 to i32
  %29 = add nsw i32 %28, 48
  %30 = call i32 @putchar(i32 %29)
  ret i32 1
}

declare i32 @putchar(i32) #1

; Function Attrs: nounwind uwtable
define i32 @f7(i32 %l1, i32 %l2, i32 %l3) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %g1 = alloca i32, align 4
  %g3 = alloca i32, align 4
  %g2 = alloca i8, align 1
  store i32 %l1, i32* %2, align 4
  store i32 %l2, i32* %3, align 4
  store i32 %l3, i32* %4, align 4
  %5 = load i32, i32* %g1, align 4
  %6 = icmp slt i32 %5, 1
  br i1 %6, label %7, label %8

; <label>:7                                       ; preds = %0
  store i8 98, i8* %g2, align 1
  br label %9

; <label>:8                                       ; preds = %0
  store i32 2, i32* %1, align 4
  br label %15

; <label>:9                                       ; preds = %7
  %10 = load i32, i32* %g3, align 4
  %11 = load i32, i32* %g1, align 4
  %12 = icmp ne i32 %10, %11
  br i1 %12, label %13, label %14

; <label>:13                                      ; preds = %9
  store i32 2, i32* %g1, align 4
  br label %14

; <label>:14                                      ; preds = %13, %9
  store i32 1, i32* %1, align 4
  br label %15

; <label>:15                                      ; preds = %14, %8
  %16 = load i32, i32* %1, align 4
  ret i32 %16
}

; Function Attrs: nounwind uwtable
define signext i8 @jot(i32 %h0, i8 signext %h1, double %h2) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i8, align 1
  %3 = alloca double, align 8
  %b1 = alloca i32, align 4
  %b2 = alloca i32, align 4
  %b5 = alloca i8, align 1
  %b6 = alloca i8, align 1
  %c3 = alloca i16, align 2
  %b3 = alloca double, align 8
  %b4 = alloca double, align 8
  store i32 %h0, i32* %1, align 4
  store i8 %h1, i8* %2, align 1
  store double %h2, double* %3, align 8
  %4 = load i8, i8* %b6, align 1
  %5 = sext i8 %4 to i32
  %6 = sub nsw i32 0, %5
  %7 = trunc i32 %6 to i8
  store i8 %7, i8* %b5, align 1
  %8 = load double, double* %b4, align 8
  %9 = fsub double -0.000000e+00, %8
  store double %9, double* %b3, align 8
  %10 = load i32, i32* %b2, align 4
  %11 = sub nsw i32 0, %10
  store i32 %11, i32* %b1, align 4
  store i16 -1, i16* %c3, align 2
  %12 = load i16, i16* %c3, align 2
  %13 = sext i16 %12 to i32
  %14 = sub nsw i32 0, %13
  %15 = trunc i32 %14 to i16
  store i16 %15, i16* %c3, align 2
  ret i8 103
}

; Function Attrs: nounwind uwtable
define void @f9(i32 %j1, i8 signext %j2, double %j3) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i8, align 1
  %3 = alloca double, align 8
  %c1 = alloca i32, align 4
  %c2 = alloca i32, align 4
  %c4 = alloca i16, align 2
  %c3 = alloca double, align 8
  store i32 %j1, i32* %1, align 4
  store i8 %j2, i8* %2, align 1
  store double %j3, double* %3, align 8
  store i32 3, i32* %c2, align 4
  store i16 2, i16* %c4, align 2
  store double 1.200000e+00, double* %c3, align 8
  %4 = load i32, i32* %c2, align 4
  %5 = sitofp i32 %4 to double
  %6 = load double, double* %c3, align 8
  %7 = fmul double %5, %6
  %8 = load i32, i32* %c1, align 4
  %9 = sitofp i32 %8 to double
  %10 = fdiv double %7, %9
  %11 = fadd double 5.000000e+00, %10
  %12 = fptosi double %11 to i16
  store i16 %12, i16* %c4, align 2
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @empty() #0 {
  ret i32 0
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-24ubuntu7 (tags/RELEASE_381/final)"}
