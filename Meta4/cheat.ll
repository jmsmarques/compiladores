; ModuleID = 'cheat.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@t = global i32 1, align 4
@o = global i8 97, align 1

; Function Attrs: nounwind uwtable
define void @sin(i32 %a, i16 signext %b, i8 signext %c) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i16, align 2
  %3 = alloca i8, align 1
  %g = alloca i32, align 4
  %h = alloca i8, align 1
  %j = alloca i32, align 4
  %i = alloca i32, align 4
  %l = alloca i32, align 4
  %y = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i16 %b, i16* %2, align 2
  store i8 %c, i8* %3, align 1
  %4 = load i32, i32* %1, align 4
  %5 = load i8, i8* %3, align 1
  %6 = sext i8 %5 to i32
  %7 = add nsw i32 %4, %6
  %8 = load i8, i8* %3, align 1
  %9 = sext i8 %8 to i32
  %10 = load i32, i32* %1, align 4
  %11 = add nsw i32 %9, %10
  %12 = load i8, i8* %3, align 1
  %13 = sext i8 %12 to i32
  %14 = load i8, i8* %3, align 1
  %15 = sext i8 %14 to i32
  %16 = add nsw i32 %13, %15
  %17 = load i8, i8* %3, align 1
  %18 = sext i8 %17 to i32
  %19 = load i32, i32* %1, align 4
  %20 = add nsw i32 %18, %19
  %21 = add nsw i32 %16, %20
  store i32 1, i32* %g, align 4
  store i8 97, i8* %h, align 1
  %22 = load i8, i8* %h, align 1
  %23 = sext i8 %22 to i32
  %24 = load i32, i32* %g, align 4
  %25 = add nsw i32 %23, %24
  store i32 %25, i32* %j, align 4
  %26 = load i8, i8* %h, align 1
  %27 = sext i8 %26 to i32
  %28 = load i32, i32* %g, align 4
  %29 = add nsw i32 %27, %28
  store i32 %29, i32* %j, align 4
  %30 = load i32, i32* %1, align 4
  %31 = load i8, i8* %3, align 1
  %32 = sext i8 %31 to i32
  %33 = add nsw i32 %30, %32
  store i32 %33, i32* %i, align 4
  %34 = load i32, i32* %1, align 4
  %35 = load i8, i8* %3, align 1
  %36 = sext i8 %35 to i32
  %37 = add nsw i32 %34, %36
  store i32 %37, i32* %i, align 4
  %38 = load i32, i32* @t, align 4
  %39 = load i8, i8* @o, align 1
  %40 = sext i8 %39 to i32
  %41 = add nsw i32 %38, %40
  store i32 %41, i32* %l, align 4
  %42 = load i32, i32* @t, align 4
  %43 = load i8, i8* @o, align 1
  %44 = sext i8 %43 to i32
  %45 = add nsw i32 %42, %44
  store i32 %45, i32* %l, align 4
  %46 = load i8, i8* %h, align 1
  %47 = sext i8 %46 to i32
  %48 = load i8, i8* @o, align 1
  %49 = sext i8 %48 to i32
  %50 = add nsw i32 %47, %49
  store i32 %50, i32* %y, align 4
  %51 = load i8, i8* %h, align 1
  %52 = sext i8 %51 to i32
  %53 = load i8, i8* @o, align 1
  %54 = sext i8 %53 to i32
  %55 = add nsw i32 %52, %54
  store i32 %55, i32* %y, align 4
  %56 = load i32, i32* %j, align 4
  %57 = load i8, i8* %h, align 1
  %58 = sext i8 %57 to i32
  %59 = add nsw i32 %56, %58
  %60 = load i32, i32* @t, align 4
  %61 = add nsw i32 %59, %60
  %62 = load i32, i32* %y, align 4
  %63 = add nsw i32 %61, %62
  %64 = load i8, i8* @o, align 1
  %65 = sext i8 %64 to i32
  %66 = add nsw i32 %63, %65
  %67 = load i32, i32* %l, align 4
  %68 = add nsw i32 %66, %67
  %69 = load i32, i32* %i, align 4
  %70 = add nsw i32 %68, %69
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %e = alloca i8, align 1
  %a = alloca i32, align 4
  store i8 97, i8* %e, align 1
  store i32 1, i32* %a, align 4
  %1 = load i8, i8* %e, align 1
  %2 = sext i8 %1 to i32
  %3 = load i32, i32* %a, align 4
  %4 = add nsw i32 %2, %3
  %5 = call i32 @putchar(i32 %4)
  %6 = load i8, i8* %e, align 1
  %7 = icmp ne i8 %6, 0
  %8 = xor i1 %7, true
  %9 = xor i1 %8, true
  %10 = zext i1 %9 to i32
  %11 = call i32 @putchar(i32 %10)
  call void @sin(i32 1, i16 signext 2, i8 signext 3)
  ret i32 0
}

declare i32 @putchar(i32) #1

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-24ubuntu7 (tags/RELEASE_381/final)"}
