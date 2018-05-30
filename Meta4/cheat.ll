; ModuleID = 'cheat.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define void @printint(i32 %n) #0 {
  %1 = alloca i32, align 4
  store i32 %n, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = icmp slt i32 %2, 0
  br i1 %3, label %4, label %8

; <label>:4                                       ; preds = %0
  %5 = call i32 @putchar(i32 45)
  %6 = load i32, i32* %1, align 4
  %7 = sub nsw i32 0, %6
  store i32 %7, i32* %1, align 4
  br label %8

; <label>:8                                       ; preds = %4, %0
  %9 = load i32, i32* %1, align 4
  %10 = sdiv i32 %9, 10
  %11 = icmp ne i32 %10, 0
  br i1 %11, label %12, label %15

; <label>:12                                      ; preds = %8
  %13 = load i32, i32* %1, align 4
  %14 = sdiv i32 %13, 10
  call void @printint(i32 %14)
  br label %15

; <label>:15                                      ; preds = %12, %8
  %16 = load i32, i32* %1, align 4
  %17 = srem i32 %16, 10
  %18 = add nsw i32 %17, 48
  %19 = call i32 @putchar(i32 %18)
  ret void
}

declare i32 @putchar(i32) #1

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 1, i32* %i, align 4
  br label %2

; <label>:2                                       ; preds = %5, %0
  %3 = load i32, i32* %i, align 4
  %4 = icmp slt i32 %3, 500
  br i1 %4, label %5, label %9

; <label>:5                                       ; preds = %2
  %6 = load i32, i32* %i, align 4
  call void @printint(i32 %6)
  %7 = load i32, i32* %i, align 4
  %8 = add nsw i32 %7, 1
  store i32 %8, i32* %i, align 4
  br label %2

; <label>:9                                       ; preds = %2
  %10 = load i32, i32* %1, align 4
  ret i32 %10
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-24ubuntu7 (tags/RELEASE_381/final)"}
