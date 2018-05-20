; ModuleID = 'cheat.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@b = global i32 2, align 4
@a = common global i32 0, align 4

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

; Function Attrs: nounwind uwtable
define signext i8 @f1() #0 {
  ret i8 97
}

; Function Attrs: nounwind uwtable
define signext i16 @f2() #0 {
  ret i16 1
}

; Function Attrs: nounwind uwtable
define void @f3() #0 {
  ret void
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-24ubuntu7 (tags/RELEASE_381/final)"}
