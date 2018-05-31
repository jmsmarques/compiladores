; ModuleID = 'cheat.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @bigmod(i32 %a, i32 %p, i32 %m) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %c = alloca i32, align 4
  store i32 %a, i32* %2, align 4
  store i32 %p, i32* %3, align 4
  store i32 %m, i32* %4, align 4
  %5 = load i32, i32* %3, align 4
  %6 = icmp eq i32 %5, 0
  br i1 %6, label %7, label %8

; <label>:7                                       ; preds = %0
  store i32 1, i32* %1, align 4
  br label %39

; <label>:8                                       ; preds = %0
  %9 = load i32, i32* %3, align 4
  %10 = srem i32 %9, 2
  %11 = icmp ne i32 %10, 0
  br i1 %11, label %12, label %24

; <label>:12                                      ; preds = %8
  %13 = load i32, i32* %2, align 4
  %14 = load i32, i32* %4, align 4
  %15 = srem i32 %13, %14
  %16 = load i32, i32* %2, align 4
  %17 = load i32, i32* %3, align 4
  %18 = sub nsw i32 %17, 1
  %19 = load i32, i32* %4, align 4
  %20 = call i32 @bigmod(i32 %16, i32 %18, i32 %19)
  %21 = mul nsw i32 %15, %20
  %22 = load i32, i32* %4, align 4
  %23 = srem i32 %21, %22
  store i32 %23, i32* %1, align 4
  br label %39

; <label>:24                                      ; preds = %8
  %25 = load i32, i32* %2, align 4
  %26 = load i32, i32* %3, align 4
  %27 = sdiv i32 %26, 2
  %28 = load i32, i32* %4, align 4
  %29 = call i32 @bigmod(i32 %25, i32 %27, i32 %28)
  store i32 %29, i32* %c, align 4
  %30 = load i32, i32* %c, align 4
  %31 = load i32, i32* %4, align 4
  %32 = srem i32 %30, %31
  %33 = load i32, i32* %c, align 4
  %34 = load i32, i32* %4, align 4
  %35 = srem i32 %33, %34
  %36 = mul nsw i32 %32, %35
  %37 = load i32, i32* %4, align 4
  %38 = srem i32 %36, %37
  store i32 %38, i32* %1, align 4
  br label %39

; <label>:39                                      ; preds = %24, %12, %7
  %40 = load i32, i32* %1, align 4
  ret i32 %40
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %a = alloca i32, align 4
  %p = alloca i32, align 4
  %m = alloca i32, align 4
  %k = alloca i32, align 4
  store i32 3, i32* %a, align 4
  store i32 3, i32* %p, align 4
  store i32 5, i32* %m, align 4
  %1 = load i32, i32* %a, align 4
  %2 = load i32, i32* %p, align 4
  %3 = load i32, i32* %m, align 4
  %4 = call i32 @bigmod(i32 %1, i32 %2, i32 %3)
  store i32 %4, i32* %k, align 4
  %5 = load i32, i32* %k, align 4
  %6 = add nsw i32 %5, 48
  %7 = call i32 @putchar(i32 %6)
  %8 = call i32 @putchar(i32 10)
  ret i32 0
}

declare i32 @putchar(i32) #1

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-24ubuntu7 (tags/RELEASE_381/final)"}
