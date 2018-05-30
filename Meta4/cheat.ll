; ModuleID = 'cheat.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define double @printint(double %n) #0 {
  %1 = alloca double, align 8
  store double %n, double* %1, align 8
  %2 = load double, double* %1, align 8
  %3 = fadd double %2, 1.000000e+00
  store double %3, double* %1, align 8
  br label %4

; <label>:4                                       ; preds = %7, %0
  %5 = load double, double* %1, align 8
  %6 = fcmp olt double %5, 1.000000e+01
  br i1 %6, label %7, label %10

; <label>:7                                       ; preds = %4
  %8 = load double, double* %1, align 8
  %9 = call double @printint(double %8)
  store double %9, double* %1, align 8
  br label %4

; <label>:10                                      ; preds = %4
  %11 = load double, double* %1, align 8
  ret double %11
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %g = alloca double, align 8
  store i32 0, i32* %1, align 4
  %2 = call double @printint(double 1.000000e+00)
  store double %2, double* %g, align 8
  ret i32 1
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-24ubuntu7 (tags/RELEASE_381/final)"}
