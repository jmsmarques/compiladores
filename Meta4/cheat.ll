; ModuleID = 'cheat.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@a1 = global i8 52, align 1
@a5 = global i16 1, align 2
@a3 = global double 1.100000e+00, align 8
@a = common global i32 0, align 4
@a2 = common global i8 0, align 1

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %c = alloca i8, align 1
  store i32 0, i32* %1, align 4
  store i32 1, i32* %a, align 4
  store i32 -5, i32* %b, align 4
  %2 = call i32 @putchar(i32 97)
  %3 = load i32, i32* %a, align 4
  ret i32 %3
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
  %b3 = alloca double, align 8
  store i32 %h0, i32* %1, align 4
  store i8 %h1, i8* %2, align 1
  store double %h2, double* %3, align 8
  store double 1.200000e+00, double* %b3, align 8
  %4 = load i32, i32* %b2, align 4
  %5 = sub nsw i32 0, %4
  store i32 %5, i32* %b1, align 4
  ret i8 103
}

; Function Attrs: nounwind uwtable
define void @f9(i32 %j1, i8 signext %j2, double %j3) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i8, align 1
  %3 = alloca double, align 8
  %c1 = alloca i32, align 4
  %c2 = alloca i32, align 4
  %c3 = alloca double, align 8
  store i32 %j1, i32* %1, align 4
  store i8 %j2, i8* %2, align 1
  store double %j3, double* %3, align 8
  store double 1.200000e+00, double* %c3, align 8
  %4 = load i32, i32* %c2, align 4
  %5 = mul nsw i32 %4, 5
  store i32 %5, i32* %c1, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @empty() #0 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define double @factorial(i32 %x) #0 {
  %1 = alloca i32, align 4
  store i32 %x, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = sitofp i32 %2 to double
  %4 = load i32, i32* %1, align 4
  %5 = sub nsw i32 %4, 1
  %6 = call double @factorial(i32 %5)
  %7 = fmul double %3, %6
  ret double %7
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-24ubuntu7 (tags/RELEASE_381/final)"}
