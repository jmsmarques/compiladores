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
  %l = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 5, i32* %l, align 4
  call void @f9(i32 1, i8 signext 1, double 1.000000e+00)
  ret i32 1
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
  %5 = load i32, i32* %2, align 4
  %6 = icmp slt i32 %5, 1
  br i1 %6, label %7, label %9

; <label>:7                                       ; preds = %0
  %8 = call i32 @putchar(i32 97)
  br label %15

; <label>:9                                       ; preds = %0
  %10 = load i32, i32* %2, align 4
  %11 = icmp sgt i32 %10, 0
  br i1 %11, label %12, label %14

; <label>:12                                      ; preds = %9
  %13 = call i32 @putchar(i32 98)
  br label %14

; <label>:14                                      ; preds = %12, %9
  store i32 2, i32* %1, align 4
  br label %16

; <label>:15                                      ; preds = %7
  store i32 1, i32* %1, align 4
  br label %16

; <label>:16                                      ; preds = %15, %14
  %17 = load i32, i32* %1, align 4
  ret i32 %17
}

declare i32 @putchar(i32) #1

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
define i32 @empty() #0 {
  ret i32 0
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-24ubuntu7 (tags/RELEASE_381/final)"}
