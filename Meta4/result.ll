declare i32 @getchar()
declare i32 @putchar(i32)
define void @condition_if(i32 %a) {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = icmp ne i32 %2, 0
	br i1 %3, label %label1, label %label2

	label1:
	%4 = call i32 @putchar(i32 69)
	%5 = call i32 @putchar(i32 110)
	%6 = call i32 @putchar(i32 116)
	%7 = call i32 @putchar(i32 101)
	%8 = call i32 @putchar(i32 114)
	%9 = call i32 @putchar(i32 101)
	%10 = call i32 @putchar(i32 100)
	%11 = call i32 @putchar(i32 32)
	%12 = call i32 @putchar(i32 105)
	%13 = call i32 @putchar(i32 102)
	%14 = call i32 @putchar(i32 10)
	br label %label3

	label2:
	%15 = call i32 @putchar(i32 69)
	%16 = call i32 @putchar(i32 110)
	%17 = call i32 @putchar(i32 116)
	%18 = call i32 @putchar(i32 101)
	%19 = call i32 @putchar(i32 114)
	%20 = call i32 @putchar(i32 101)
	%21 = call i32 @putchar(i32 100)
	%22 = call i32 @putchar(i32 32)
	%23 = call i32 @putchar(i32 101)
	%24 = call i32 @putchar(i32 108)
	%25 = call i32 @putchar(i32 115)
	%26 = call i32 @putchar(i32 101)
	%27 = call i32 @putchar(i32 10)
	br label %label3

	label3:
	ret void
}

define void @condition_while(i32 %a, i32 %b) {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%2 = alloca i32, align 4
	store i32 %b, i32* %2, align 4
	%3 = load i32, i32* %1, align 4
	store i32 %3, i32* %1, align 4
	br label %label1

	label1:
	%4 = load i32, i32* %1, align 4
	%5 = load i32, i32* %2, align 4
	%6 = icmp sle i32 %4, %5
	%7 = zext i1 %6 to i32
	%8 = icmp ne i32 %7, 0
	br i1 %8, label %label2, label %label3

	label2:
	%9 = load i32, i32* %1, align 4
	%10 = call i32 @putchar(i32 %9)
	%11 = load i32, i32* %1, align 4
	%12 = add i32 %11, 1
	store i32 %12, i32* %1, align 4
	br label %label1

	label3:
	%13 = call i32 @putchar(i32 10)
	ret void
}

define void @comma_expressions(i32 %a) {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%2 = load i32, i32* %1, align 4
	%3 = add i32 %2, 1
	store i32 %3, i32* %1, align 4
	%4 = load i32, i32* %1, align 4
	%5 = load i32, i32* %1, align 4
	%6 = add i32 %5, 2
	store i32 %6, i32* %1, align 4
	%7 = load i32, i32* %1, align 4
	%jorge8 = alloca i32
	store i32 3, i32* %jorge8
	%8 = load i32, i32* %jorge8
	%9 = add i32 %8, 48
	%10 = call i32 @putchar(i32 %9)
	ret void
}

define i8 @call(i32 %a, i16 %b, i8 %c, double %d) {
	%1 = alloca i32, align 4
	store i32 %a, i32* %1, align 4
	%2 = alloca i16, align 2
	store i16 %b, i16* %2, align 2
	%3 = alloca i8, align 1
	store i8 %c, i8* %3, align 1
	%4 = alloca double, align 8
	store double %d, double* %4, align 8
	%5 = load i32, i32* %1, align 4
	%6 = add i32 %5, 1
	%7 = load i32, i32* %1, align 4
	%8 = trunc i32 %7 to i16
	%9 = load i8, i8* %3, align 1
	%10 = load double, double* %4, align 8
	%11 = call i8 @call(i32 %6,i16 %8,i8 %9,double %10)
	%12 = sext i8 %11 to i16
	store i16 %12, i16* %2, align 2
	%13 = load i32, i32* %1, align 4
	%14 = add i32 48, %13
	%15 = call i32 @putchar(i32 %14)
	%16 = load i16, i16* %2, align 2
	%17 = sext i16 %16 to i32
	%18 = add i32 48, %17
	%19 = call i32 @putchar(i32 %18)
	%20 = call i32 @putchar(i32 10)
	%21 = load i16, i16* %2, align 2
	%22 = trunc i16 %21 to i8
	ret i8 %22
}

@a = global i32 1, align 4
@b = global i16 2, align 2
@c = global i8 3, align 1
@d = global i32 4, align 4
define i32 @main() {
	call void @condition_if(i32 0)
	call void @condition_if(i32 1)
	call void @condition_while(i32 48,i32 57)
	call void @condition_while(i32 97,i32 122)
	call void @condition_while(i32 65,i32 90)
	call void @comma_expressions(i32 0)
	%1 = load i32, i32* @a, align 4
	%2 = load i32, i32* @a, align 4
	%3 = add i32 %1, %2
	%4 = add i32 %3, 48
	%5 = call i32 @putchar(i32 %4)
	%6 = load i32, i32* @a, align 4
	%7 = load i16, i16* @b, align 2
	%8 = sext i16 %7 to i32
	%9 = add i32 %6, %8
	%10 = add i32 %9, 48
	%11 = call i32 @putchar(i32 %10)
	%12 = load i32, i32* @a, align 4
	%13 = load i8, i8* @c, align 1
	%14 = sext i8 %13 to i32
	%15 = add i32 %12, %14
	%16 = add i32 %15, 48
	%17 = call i32 @putchar(i32 %16)
	%18 = load i32, i32* @a, align 4
	%19 = load i32, i32* @d, align 4
	%20 = add i32 %18, %19
	%21 = add i32 %20, 48
	%22 = call i32 @putchar(i32 %21)
	%23 = load i16, i16* @b, align 2
	%24 = load i16, i16* @b, align 2
	%25 = add i16 %23, %24
	%26 = sext i16 %25 to i32
	%27 = add i32 %26, 48
	%28 = call i32 @putchar(i32 %27)
	%29 = load i16, i16* @b, align 2
	%30 = load i8, i8* @c, align 1
	%31 = sext i8 %30 to i16
	%32 = add i16 %29, %31
	%33 = sext i16 %32 to i32
	%34 = add i32 %33, 48
	%35 = call i32 @putchar(i32 %34)
	%36 = load i16, i16* @b, align 2
	%37 = sext i16 %36 to i32
	%38 = load i32, i32* @d, align 4
	%39 = add i32 %37, %38
	%40 = add i32 %39, 48
	%41 = call i32 @putchar(i32 %40)
	%42 = load i8, i8* @c, align 1
	%43 = load i8, i8* @c, align 1
	%44 = add i8 %42, %43
	%45 = sext i8 %44 to i32
	%46 = add i32 %45, 48
	%47 = call i32 @putchar(i32 %46)
	%48 = load i8, i8* @c, align 1
	%49 = sext i8 %48 to i32
	%50 = load i32, i32* @d, align 4
	%51 = add i32 %49, %50
	%52 = add i32 %51, 48
	%53 = call i32 @putchar(i32 %52)
	%54 = load i32, i32* @d, align 4
	%55 = load i32, i32* @d, align 4
	%56 = add i32 %54, %55
	%57 = add i32 %56, 48
	%58 = call i32 @putchar(i32 %57)
	%59 = load i32, i32* @a, align 4
	%60 = load i32, i32* @a, align 4
	%61 = add i32 %59, %60
	%62 = add i32 %61, 48
	%63 = call i32 @putchar(i32 %62)
	%64 = load i16, i16* @b, align 2
	%65 = sext i16 %64 to i32
	%66 = load i32, i32* @a, align 4
	%67 = add i32 %65, %66
	%68 = add i32 %67, 48
	%69 = call i32 @putchar(i32 %68)
	%70 = load i8, i8* @c, align 1
	%71 = sext i8 %70 to i32
	%72 = load i32, i32* @a, align 4
	%73 = add i32 %71, %72
	%74 = add i32 %73, 48
	%75 = call i32 @putchar(i32 %74)
	%76 = load i32, i32* @d, align 4
	%77 = load i32, i32* @a, align 4
	%78 = add i32 %76, %77
	%79 = add i32 %78, 48
	%80 = call i32 @putchar(i32 %79)
	%81 = load i16, i16* @b, align 2
	%82 = load i16, i16* @b, align 2
	%83 = add i16 %81, %82
	%84 = sext i16 %83 to i32
	%85 = add i32 %84, 48
	%86 = call i32 @putchar(i32 %85)
	%87 = load i8, i8* @c, align 1
	%88 = sext i8 %87 to i16
	%89 = load i16, i16* @b, align 2
	%90 = add i16 %88, %89
	%91 = sext i16 %90 to i32
	%92 = add i32 %91, 48
	%93 = call i32 @putchar(i32 %92)
	%94 = load i32, i32* @d, align 4
	%95 = load i16, i16* @b, align 2
	%96 = sext i16 %95 to i32
	%97 = add i32 %94, %96
	%98 = add i32 %97, 48
	%99 = call i32 @putchar(i32 %98)
	%100 = load i8, i8* @c, align 1
	%101 = load i8, i8* @c, align 1
	%102 = add i8 %100, %101
	%103 = sext i8 %102 to i32
	%104 = add i32 %103, 48
	%105 = call i32 @putchar(i32 %104)
	%106 = load i32, i32* @a, align 4
	%107 = load i32, i32* @a, align 4
	%108 = sub i32 %106, %107
	%109 = add i32 %108, 48
	%110 = call i32 @putchar(i32 %109)
	%111 = load i32, i32* @a, align 4
	%112 = load i16, i16* @b, align 2
	%113 = sext i16 %112 to i32
	%114 = sub i32 %111, %113
	%115 = add i32 %114, 48
	%116 = call i32 @putchar(i32 %115)
	%117 = load i32, i32* @a, align 4
	%118 = load i8, i8* @c, align 1
	%119 = sext i8 %118 to i32
	%120 = sub i32 %117, %119
	%121 = add i32 %120, 48
	%122 = call i32 @putchar(i32 %121)
	%123 = load i32, i32* @a, align 4
	%124 = load i32, i32* @d, align 4
	%125 = sub i32 %123, %124
	%126 = add i32 %125, 48
	%127 = call i32 @putchar(i32 %126)
	%128 = load i16, i16* @b, align 2
	%129 = load i16, i16* @b, align 2
	%130 = sub i16 %128, %129
	%131 = sext i16 %130 to i32
	%132 = add i32 %131, 48
	%133 = call i32 @putchar(i32 %132)
	%134 = load i16, i16* @b, align 2
	%135 = load i8, i8* @c, align 1
	%136 = sext i8 %135 to i16
	%137 = sub i16 %134, %136
	%138 = sext i16 %137 to i32
	%139 = add i32 %138, 48
	%140 = call i32 @putchar(i32 %139)
	%141 = load i16, i16* @b, align 2
	%142 = sext i16 %141 to i32
	%143 = load i32, i32* @d, align 4
	%144 = sub i32 %142, %143
	%145 = add i32 %144, 48
	%146 = call i32 @putchar(i32 %145)
	%147 = load i8, i8* @c, align 1
	%148 = load i8, i8* @c, align 1
	%149 = sub i8 %147, %148
	%150 = sext i8 %149 to i32
	%151 = add i32 %150, 48
	%152 = call i32 @putchar(i32 %151)
	%153 = load i8, i8* @c, align 1
	%154 = sext i8 %153 to i32
	%155 = load i32, i32* @d, align 4
	%156 = sub i32 %154, %155
	%157 = add i32 %156, 48
	%158 = call i32 @putchar(i32 %157)
	%159 = load i32, i32* @d, align 4
	%160 = load i32, i32* @d, align 4
	%161 = sub i32 %159, %160
	%162 = add i32 %161, 48
	%163 = call i32 @putchar(i32 %162)
	%164 = load i32, i32* @a, align 4
	%165 = load i32, i32* @a, align 4
	%166 = sub i32 %164, %165
	%167 = add i32 %166, 48
	%168 = call i32 @putchar(i32 %167)
	%169 = load i16, i16* @b, align 2
	%170 = sext i16 %169 to i32
	%171 = load i32, i32* @a, align 4
	%172 = sub i32 %170, %171
	%173 = add i32 %172, 48
	%174 = call i32 @putchar(i32 %173)
	%175 = load i8, i8* @c, align 1
	%176 = sext i8 %175 to i32
	%177 = load i32, i32* @a, align 4
	%178 = sub i32 %176, %177
	%179 = add i32 %178, 48
	%180 = call i32 @putchar(i32 %179)
	%181 = load i32, i32* @d, align 4
	%182 = load i32, i32* @a, align 4
	%183 = sub i32 %181, %182
	%184 = add i32 %183, 48
	%185 = call i32 @putchar(i32 %184)
	%186 = load i16, i16* @b, align 2
	%187 = load i16, i16* @b, align 2
	%188 = sub i16 %186, %187
	%189 = sext i16 %188 to i32
	%190 = add i32 %189, 48
	%191 = call i32 @putchar(i32 %190)
	%192 = load i8, i8* @c, align 1
	%193 = sext i8 %192 to i16
	%194 = load i16, i16* @b, align 2
	%195 = sub i16 %193, %194
	%196 = sext i16 %195 to i32
	%197 = add i32 %196, 48
	%198 = call i32 @putchar(i32 %197)
	%199 = load i32, i32* @d, align 4
	%200 = load i16, i16* @b, align 2
	%201 = sext i16 %200 to i32
	%202 = sub i32 %199, %201
	%203 = add i32 %202, 48
	%204 = call i32 @putchar(i32 %203)
	%205 = load i8, i8* @c, align 1
	%206 = load i8, i8* @c, align 1
	%207 = sub i8 %205, %206
	%208 = sext i8 %207 to i32
	%209 = add i32 %208, 48
	%210 = call i32 @putchar(i32 %209)
	%211 = load i32, i32* @a, align 4
	%212 = load i32, i32* @a, align 4
	%213 = mul i32 %211, %212
	%214 = add i32 %213, 48
	%215 = call i32 @putchar(i32 %214)
	%216 = load i32, i32* @a, align 4
	%217 = load i16, i16* @b, align 2
	%218 = sext i16 %217 to i32
	%219 = mul i32 %216, %218
	%220 = add i32 %219, 48
	%221 = call i32 @putchar(i32 %220)
	%222 = load i32, i32* @a, align 4
	%223 = load i8, i8* @c, align 1
	%224 = sext i8 %223 to i32
	%225 = mul i32 %222, %224
	%226 = add i32 %225, 48
	%227 = call i32 @putchar(i32 %226)
	%228 = load i32, i32* @a, align 4
	%229 = load i32, i32* @d, align 4
	%230 = mul i32 %228, %229
	%231 = add i32 %230, 48
	%232 = call i32 @putchar(i32 %231)
	%233 = load i16, i16* @b, align 2
	%234 = load i16, i16* @b, align 2
	%235 = mul i16 %233, %234
	%236 = sext i16 %235 to i32
	%237 = add i32 %236, 48
	%238 = call i32 @putchar(i32 %237)
	%239 = load i16, i16* @b, align 2
	%240 = load i8, i8* @c, align 1
	%241 = sext i8 %240 to i16
	%242 = mul i16 %239, %241
	%243 = sext i16 %242 to i32
	%244 = add i32 %243, 48
	%245 = call i32 @putchar(i32 %244)
	%246 = load i16, i16* @b, align 2
	%247 = sext i16 %246 to i32
	%248 = load i32, i32* @d, align 4
	%249 = mul i32 %247, %248
	%250 = add i32 %249, 48
	%251 = call i32 @putchar(i32 %250)
	%252 = load i8, i8* @c, align 1
	%253 = load i8, i8* @c, align 1
	%254 = mul i8 %252, %253
	%255 = sext i8 %254 to i32
	%256 = add i32 %255, 48
	%257 = call i32 @putchar(i32 %256)
	%258 = load i8, i8* @c, align 1
	%259 = sext i8 %258 to i32
	%260 = load i32, i32* @d, align 4
	%261 = mul i32 %259, %260
	%262 = add i32 %261, 48
	%263 = call i32 @putchar(i32 %262)
	%264 = load i32, i32* @d, align 4
	%265 = load i32, i32* @d, align 4
	%266 = mul i32 %264, %265
	%267 = add i32 %266, 48
	%268 = call i32 @putchar(i32 %267)
	%269 = load i32, i32* @a, align 4
	%270 = load i32, i32* @a, align 4
	%271 = mul i32 %269, %270
	%272 = add i32 %271, 48
	%273 = call i32 @putchar(i32 %272)
	%274 = load i16, i16* @b, align 2
	%275 = sext i16 %274 to i32
	%276 = load i32, i32* @a, align 4
	%277 = mul i32 %275, %276
	%278 = add i32 %277, 48
	%279 = call i32 @putchar(i32 %278)
	%280 = load i8, i8* @c, align 1
	%281 = sext i8 %280 to i32
	%282 = load i32, i32* @a, align 4
	%283 = mul i32 %281, %282
	%284 = add i32 %283, 48
	%285 = call i32 @putchar(i32 %284)
	%286 = load i32, i32* @d, align 4
	%287 = load i32, i32* @a, align 4
	%288 = mul i32 %286, %287
	%289 = add i32 %288, 48
	%290 = call i32 @putchar(i32 %289)
	%291 = load i16, i16* @b, align 2
	%292 = load i16, i16* @b, align 2
	%293 = mul i16 %291, %292
	%294 = sext i16 %293 to i32
	%295 = add i32 %294, 48
	%296 = call i32 @putchar(i32 %295)
	%297 = load i8, i8* @c, align 1
	%298 = sext i8 %297 to i16
	%299 = load i16, i16* @b, align 2
	%300 = mul i16 %298, %299
	%301 = sext i16 %300 to i32
	%302 = add i32 %301, 48
	%303 = call i32 @putchar(i32 %302)
	%304 = load i32, i32* @d, align 4
	%305 = load i16, i16* @b, align 2
	%306 = sext i16 %305 to i32
	%307 = mul i32 %304, %306
	%308 = add i32 %307, 48
	%309 = call i32 @putchar(i32 %308)
	%310 = load i8, i8* @c, align 1
	%311 = load i8, i8* @c, align 1
	%312 = mul i8 %310, %311
	%313 = sext i8 %312 to i32
	%314 = add i32 %313, 48
	%315 = call i32 @putchar(i32 %314)
	%316 = load i32, i32* @a, align 4
	%317 = load i32, i32* @a, align 4
	%318 = sdiv i32 %316, %317
	%319 = add i32 %318, 48
	%320 = call i32 @putchar(i32 %319)
	%321 = load i32, i32* @a, align 4
	%322 = load i16, i16* @b, align 2
	%323 = sext i16 %322 to i32
	%324 = sdiv i32 %321, %323
	%325 = add i32 %324, 48
	%326 = call i32 @putchar(i32 %325)
	%327 = load i32, i32* @a, align 4
	%328 = load i8, i8* @c, align 1
	%329 = sext i8 %328 to i32
	%330 = sdiv i32 %327, %329
	%331 = add i32 %330, 48
	%332 = call i32 @putchar(i32 %331)
	%333 = load i32, i32* @a, align 4
	%334 = load i32, i32* @d, align 4
	%335 = sdiv i32 %333, %334
	%336 = add i32 %335, 48
	%337 = call i32 @putchar(i32 %336)
	%338 = load i16, i16* @b, align 2
	%339 = load i16, i16* @b, align 2
	%340 = sdiv i16 %338, %339
	%341 = sext i16 %340 to i32
	%342 = add i32 %341, 48
	%343 = call i32 @putchar(i32 %342)
	%344 = load i16, i16* @b, align 2
	%345 = load i8, i8* @c, align 1
	%346 = sext i8 %345 to i16
	%347 = sdiv i16 %344, %346
	%348 = sext i16 %347 to i32
	%349 = add i32 %348, 48
	%350 = call i32 @putchar(i32 %349)
	%351 = load i16, i16* @b, align 2
	%352 = sext i16 %351 to i32
	%353 = load i32, i32* @d, align 4
	%354 = sdiv i32 %352, %353
	%355 = add i32 %354, 48
	%356 = call i32 @putchar(i32 %355)
	%357 = load i8, i8* @c, align 1
	%358 = load i8, i8* @c, align 1
	%359 = sdiv i8 %357, %358
	%360 = sext i8 %359 to i32
	%361 = add i32 %360, 48
	%362 = call i32 @putchar(i32 %361)
	%363 = load i8, i8* @c, align 1
	%364 = sext i8 %363 to i32
	%365 = load i32, i32* @d, align 4
	%366 = sdiv i32 %364, %365
	%367 = add i32 %366, 48
	%368 = call i32 @putchar(i32 %367)
	%369 = load i32, i32* @d, align 4
	%370 = load i32, i32* @d, align 4
	%371 = sdiv i32 %369, %370
	%372 = add i32 %371, 48
	%373 = call i32 @putchar(i32 %372)
	%374 = load i32, i32* @a, align 4
	%375 = load i32, i32* @a, align 4
	%376 = sdiv i32 %374, %375
	%377 = add i32 %376, 48
	%378 = call i32 @putchar(i32 %377)
	%379 = load i16, i16* @b, align 2
	%380 = sext i16 %379 to i32
	%381 = load i32, i32* @a, align 4
	%382 = sdiv i32 %380, %381
	%383 = add i32 %382, 48
	%384 = call i32 @putchar(i32 %383)
	%385 = load i8, i8* @c, align 1
	%386 = sext i8 %385 to i32
	%387 = load i32, i32* @a, align 4
	%388 = sdiv i32 %386, %387
	%389 = add i32 %388, 48
	%390 = call i32 @putchar(i32 %389)
	%391 = load i32, i32* @d, align 4
	%392 = load i32, i32* @a, align 4
	%393 = sdiv i32 %391, %392
	%394 = add i32 %393, 48
	%395 = call i32 @putchar(i32 %394)
	%396 = load i16, i16* @b, align 2
	%397 = load i16, i16* @b, align 2
	%398 = sdiv i16 %396, %397
	%399 = sext i16 %398 to i32
	%400 = add i32 %399, 48
	%401 = call i32 @putchar(i32 %400)
	%402 = load i8, i8* @c, align 1
	%403 = sext i8 %402 to i16
	%404 = load i16, i16* @b, align 2
	%405 = sdiv i16 %403, %404
	%406 = sext i16 %405 to i32
	%407 = add i32 %406, 48
	%408 = call i32 @putchar(i32 %407)
	%409 = load i32, i32* @d, align 4
	%410 = load i16, i16* @b, align 2
	%411 = sext i16 %410 to i32
	%412 = sdiv i32 %409, %411
	%413 = add i32 %412, 48
	%414 = call i32 @putchar(i32 %413)
	%415 = load i8, i8* @c, align 1
	%416 = load i8, i8* @c, align 1
	%417 = sdiv i8 %415, %416
	%418 = sext i8 %417 to i32
	%419 = add i32 %418, 48
	%420 = call i32 @putchar(i32 %419)
	%421 = load i32, i32* @a, align 4
	%422 = load i32, i32* @a, align 4
	%423 = srem i32 %421, %422
	%424 = add i32 %423, 48
	%425 = call i32 @putchar(i32 %424)
	%426 = load i32, i32* @a, align 4
	%427 = load i16, i16* @b, align 2
	%428 = sext i16 %427 to i32
	%429 = srem i32 %426, %428
	%430 = add i32 %429, 48
	%431 = call i32 @putchar(i32 %430)
	%432 = load i32, i32* @a, align 4
	%433 = load i8, i8* @c, align 1
	%434 = sext i8 %433 to i32
	%435 = srem i32 %432, %434
	%436 = add i32 %435, 48
	%437 = call i32 @putchar(i32 %436)
	%438 = load i16, i16* @b, align 2
	%439 = sext i16 %438 to i32
	%440 = load i16, i16* @b, align 2
	%441 = sext i16 %440 to i32
	%442 = srem i32 %439, %441
	%443 = add i32 %442, 48
	%444 = call i32 @putchar(i32 %443)
	%445 = load i16, i16* @b, align 2
	%446 = sext i16 %445 to i32
	%447 = load i8, i8* @c, align 1
	%448 = sext i8 %447 to i32
	%449 = srem i32 %446, %448
	%450 = add i32 %449, 48
	%451 = call i32 @putchar(i32 %450)
	%452 = load i8, i8* @c, align 1
	%453 = sext i8 %452 to i32
	%454 = load i8, i8* @c, align 1
	%455 = sext i8 %454 to i32
	%456 = srem i32 %453, %455
	%457 = add i32 %456, 48
	%458 = call i32 @putchar(i32 %457)
	%459 = load i32, i32* @a, align 4
	%460 = load i32, i32* @a, align 4
	%461 = srem i32 %459, %460
	%462 = add i32 %461, 48
	%463 = call i32 @putchar(i32 %462)
	%464 = load i16, i16* @b, align 2
	%465 = sext i16 %464 to i32
	%466 = load i32, i32* @a, align 4
	%467 = srem i32 %465, %466
	%468 = add i32 %467, 48
	%469 = call i32 @putchar(i32 %468)
	%470 = load i8, i8* @c, align 1
	%471 = sext i8 %470 to i32
	%472 = load i32, i32* @a, align 4
	%473 = srem i32 %471, %472
	%474 = add i32 %473, 48
	%475 = call i32 @putchar(i32 %474)
	%476 = load i16, i16* @b, align 2
	%477 = sext i16 %476 to i32
	%478 = load i16, i16* @b, align 2
	%479 = sext i16 %478 to i32
	%480 = srem i32 %477, %479
	%481 = add i32 %480, 48
	%482 = call i32 @putchar(i32 %481)
	%483 = load i8, i8* @c, align 1
	%484 = sext i8 %483 to i32
	%485 = load i16, i16* @b, align 2
	%486 = sext i16 %485 to i32
	%487 = srem i32 %484, %486
	%488 = add i32 %487, 48
	%489 = call i32 @putchar(i32 %488)
	%490 = load i8, i8* @c, align 1
	%491 = sext i8 %490 to i32
	%492 = load i8, i8* @c, align 1
	%493 = sext i8 %492 to i32
	%494 = srem i32 %491, %493
	%495 = add i32 %494, 48
	%496 = call i32 @putchar(i32 %495)
	%497 = load i32, i32* @a, align 4
	%498 = load i32, i32* @a, align 4
	%499 = and i32 %497, %498
	%500 = add i32 %499, 48
	%501 = call i32 @putchar(i32 %500)
	%502 = load i32, i32* @a, align 4
	%503 = load i16, i16* @b, align 2
	%504 = sext i16 %503 to i32
	%505 = and i32 %502, %504
	%506 = add i32 %505, 48
	%507 = call i32 @putchar(i32 %506)
	%508 = load i32, i32* @a, align 4
	%509 = load i8, i8* @c, align 1
	%510 = sext i8 %509 to i32
	%511 = and i32 %508, %510
	%512 = add i32 %511, 48
	%513 = call i32 @putchar(i32 %512)
	%514 = load i16, i16* @b, align 2
	%515 = sext i16 %514 to i32
	%516 = load i16, i16* @b, align 2
	%517 = sext i16 %516 to i32
	%518 = and i32 %515, %517
	%519 = add i32 %518, 48
	%520 = call i32 @putchar(i32 %519)
	%521 = load i16, i16* @b, align 2
	%522 = sext i16 %521 to i32
	%523 = load i8, i8* @c, align 1
	%524 = sext i8 %523 to i32
	%525 = and i32 %522, %524
	%526 = add i32 %525, 48
	%527 = call i32 @putchar(i32 %526)
	%528 = load i8, i8* @c, align 1
	%529 = sext i8 %528 to i32
	%530 = load i8, i8* @c, align 1
	%531 = sext i8 %530 to i32
	%532 = and i32 %529, %531
	%533 = add i32 %532, 48
	%534 = call i32 @putchar(i32 %533)
	%535 = load i32, i32* @a, align 4
	%536 = load i32, i32* @a, align 4
	%537 = and i32 %535, %536
	%538 = add i32 %537, 48
	%539 = call i32 @putchar(i32 %538)
	%540 = load i16, i16* @b, align 2
	%541 = sext i16 %540 to i32
	%542 = load i32, i32* @a, align 4
	%543 = and i32 %541, %542
	%544 = add i32 %543, 48
	%545 = call i32 @putchar(i32 %544)
	%546 = load i8, i8* @c, align 1
	%547 = sext i8 %546 to i32
	%548 = load i32, i32* @a, align 4
	%549 = and i32 %547, %548
	%550 = add i32 %549, 48
	%551 = call i32 @putchar(i32 %550)
	%552 = load i16, i16* @b, align 2
	%553 = sext i16 %552 to i32
	%554 = load i16, i16* @b, align 2
	%555 = sext i16 %554 to i32
	%556 = and i32 %553, %555
	%557 = add i32 %556, 48
	%558 = call i32 @putchar(i32 %557)
	%559 = load i8, i8* @c, align 1
	%560 = sext i8 %559 to i32
	%561 = load i16, i16* @b, align 2
	%562 = sext i16 %561 to i32
	%563 = and i32 %560, %562
	%564 = add i32 %563, 48
	%565 = call i32 @putchar(i32 %564)
	%566 = load i8, i8* @c, align 1
	%567 = sext i8 %566 to i32
	%568 = load i8, i8* @c, align 1
	%569 = sext i8 %568 to i32
	%570 = and i32 %567, %569
	%571 = add i32 %570, 48
	%572 = call i32 @putchar(i32 %571)
	%573 = load i32, i32* @a, align 4
	%574 = load i32, i32* @a, align 4
	%575 = or i32 %573, %574
	%576 = add i32 %575, 48
	%577 = call i32 @putchar(i32 %576)
	%578 = load i32, i32* @a, align 4
	%579 = load i16, i16* @b, align 2
	%580 = sext i16 %579 to i32
	%581 = or i32 %578, %580
	%582 = add i32 %581, 48
	%583 = call i32 @putchar(i32 %582)
	%584 = load i32, i32* @a, align 4
	%585 = load i8, i8* @c, align 1
	%586 = sext i8 %585 to i32
	%587 = or i32 %584, %586
	%588 = add i32 %587, 48
	%589 = call i32 @putchar(i32 %588)
	%590 = load i16, i16* @b, align 2
	%591 = sext i16 %590 to i32
	%592 = load i16, i16* @b, align 2
	%593 = sext i16 %592 to i32
	%594 = or i32 %591, %593
	%595 = add i32 %594, 48
	%596 = call i32 @putchar(i32 %595)
	%597 = load i16, i16* @b, align 2
	%598 = sext i16 %597 to i32
	%599 = load i8, i8* @c, align 1
	%600 = sext i8 %599 to i32
	%601 = or i32 %598, %600
	%602 = add i32 %601, 48
	%603 = call i32 @putchar(i32 %602)
	%604 = load i8, i8* @c, align 1
	%605 = sext i8 %604 to i32
	%606 = load i8, i8* @c, align 1
	%607 = sext i8 %606 to i32
	%608 = or i32 %605, %607
	%609 = add i32 %608, 48
	%610 = call i32 @putchar(i32 %609)
	%611 = load i32, i32* @a, align 4
	%612 = load i32, i32* @a, align 4
	%613 = or i32 %611, %612
	%614 = add i32 %613, 48
	%615 = call i32 @putchar(i32 %614)
	%616 = load i16, i16* @b, align 2
	%617 = sext i16 %616 to i32
	%618 = load i32, i32* @a, align 4
	%619 = or i32 %617, %618
	%620 = add i32 %619, 48
	%621 = call i32 @putchar(i32 %620)
	%622 = load i8, i8* @c, align 1
	%623 = sext i8 %622 to i32
	%624 = load i32, i32* @a, align 4
	%625 = or i32 %623, %624
	%626 = add i32 %625, 48
	%627 = call i32 @putchar(i32 %626)
	%628 = load i16, i16* @b, align 2
	%629 = sext i16 %628 to i32
	%630 = load i16, i16* @b, align 2
	%631 = sext i16 %630 to i32
	%632 = or i32 %629, %631
	%633 = add i32 %632, 48
	%634 = call i32 @putchar(i32 %633)
	%635 = load i8, i8* @c, align 1
	%636 = sext i8 %635 to i32
	%637 = load i16, i16* @b, align 2
	%638 = sext i16 %637 to i32
	%639 = or i32 %636, %638
	%640 = add i32 %639, 48
	%641 = call i32 @putchar(i32 %640)
	%642 = load i8, i8* @c, align 1
	%643 = sext i8 %642 to i32
	%644 = load i8, i8* @c, align 1
	%645 = sext i8 %644 to i32
	%646 = or i32 %643, %645
	%647 = add i32 %646, 48
	%648 = call i32 @putchar(i32 %647)
	%649 = load i32, i32* @a, align 4
	%650 = load i32, i32* @a, align 4
	%651 = xor i32 %649, %650
	%652 = add i32 %651, 48
	%653 = call i32 @putchar(i32 %652)
	%654 = load i32, i32* @a, align 4
	%655 = load i16, i16* @b, align 2
	%656 = sext i16 %655 to i32
	%657 = xor i32 %654, %656
	%658 = add i32 %657, 48
	%659 = call i32 @putchar(i32 %658)
	%660 = load i32, i32* @a, align 4
	%661 = load i8, i8* @c, align 1
	%662 = sext i8 %661 to i32
	%663 = xor i32 %660, %662
	%664 = add i32 %663, 48
	%665 = call i32 @putchar(i32 %664)
	%666 = load i16, i16* @b, align 2
	%667 = sext i16 %666 to i32
	%668 = load i16, i16* @b, align 2
	%669 = sext i16 %668 to i32
	%670 = xor i32 %667, %669
	%671 = add i32 %670, 48
	%672 = call i32 @putchar(i32 %671)
	%673 = load i16, i16* @b, align 2
	%674 = sext i16 %673 to i32
	%675 = load i8, i8* @c, align 1
	%676 = sext i8 %675 to i32
	%677 = xor i32 %674, %676
	%678 = add i32 %677, 48
	%679 = call i32 @putchar(i32 %678)
	%680 = load i8, i8* @c, align 1
	%681 = sext i8 %680 to i32
	%682 = load i8, i8* @c, align 1
	%683 = sext i8 %682 to i32
	%684 = xor i32 %681, %683
	%685 = add i32 %684, 48
	%686 = call i32 @putchar(i32 %685)
	%687 = load i32, i32* @a, align 4
	%688 = load i32, i32* @a, align 4
	%689 = xor i32 %687, %688
	%690 = add i32 %689, 48
	%691 = call i32 @putchar(i32 %690)
	%692 = load i16, i16* @b, align 2
	%693 = sext i16 %692 to i32
	%694 = load i32, i32* @a, align 4
	%695 = xor i32 %693, %694
	%696 = add i32 %695, 48
	%697 = call i32 @putchar(i32 %696)
	%698 = load i8, i8* @c, align 1
	%699 = sext i8 %698 to i32
	%700 = load i32, i32* @a, align 4
	%701 = xor i32 %699, %700
	%702 = add i32 %701, 48
	%703 = call i32 @putchar(i32 %702)
	%704 = load i16, i16* @b, align 2
	%705 = sext i16 %704 to i32
	%706 = load i16, i16* @b, align 2
	%707 = sext i16 %706 to i32
	%708 = xor i32 %705, %707
	%709 = add i32 %708, 48
	%710 = call i32 @putchar(i32 %709)
	%711 = load i8, i8* @c, align 1
	%712 = sext i8 %711 to i32
	%713 = load i16, i16* @b, align 2
	%714 = sext i16 %713 to i32
	%715 = xor i32 %712, %714
	%716 = add i32 %715, 48
	%717 = call i32 @putchar(i32 %716)
	%718 = load i8, i8* @c, align 1
	%719 = sext i8 %718 to i32
	%720 = load i8, i8* @c, align 1
	%721 = sext i8 %720 to i32
	%722 = xor i32 %719, %721
	%723 = add i32 %722, 48
	%724 = call i32 @putchar(i32 %723)
	%725 = load i32, i32* @a, align 4
	%726 = load i32, i32* @a, align 4
	%727 = icmp slt i32 %725, %726
	%728 = zext i1 %727 to i32
	%729 = add i32 %728, 48
	%730 = call i32 @putchar(i32 %729)
	%731 = load i32, i32* @a, align 4
	%732 = load i16, i16* @b, align 2
	%733 = sext i16 %732 to i32
	%734 = icmp slt i32 %731, %733
	%735 = zext i1 %734 to i32
	%736 = add i32 %735, 48
	%737 = call i32 @putchar(i32 %736)
	%738 = load i32, i32* @a, align 4
	%739 = load i8, i8* @c, align 1
	%740 = sext i8 %739 to i32
	%741 = icmp slt i32 %738, %740
	%742 = zext i1 %741 to i32
	%743 = add i32 %742, 48
	%744 = call i32 @putchar(i32 %743)
	%745 = load i32, i32* @a, align 4
	%746 = load i32, i32* @d, align 4
	%747 = icmp slt i32 %745, %746
	%748 = zext i1 %747 to i32
	%749 = add i32 %748, 48
	%750 = call i32 @putchar(i32 %749)
	%751 = load i16, i16* @b, align 2
	%752 = load i16, i16* @b, align 2
	%753 = icmp slt i16 %751, %752
	%754 = zext i1 %753 to i32
	%755 = add i32 %754, 48
	%756 = call i32 @putchar(i32 %755)
	%757 = load i16, i16* @b, align 2
	%758 = load i8, i8* @c, align 1
	%759 = sext i8 %758 to i16
	%760 = icmp slt i16 %757, %759
	%761 = zext i1 %760 to i32
	%762 = add i32 %761, 48
	%763 = call i32 @putchar(i32 %762)
	%764 = load i16, i16* @b, align 2
	%765 = sext i16 %764 to i32
	%766 = load i32, i32* @d, align 4
	%767 = icmp slt i32 %765, %766
	%768 = zext i1 %767 to i32
	%769 = add i32 %768, 48
	%770 = call i32 @putchar(i32 %769)
	%771 = load i8, i8* @c, align 1
	%772 = load i8, i8* @c, align 1
	%773 = icmp slt i8 %771, %772
	%774 = zext i1 %773 to i32
	%775 = add i32 %774, 48
	%776 = call i32 @putchar(i32 %775)
	%777 = load i8, i8* @c, align 1
	%778 = sext i8 %777 to i32
	%779 = load i32, i32* @d, align 4
	%780 = icmp slt i32 %778, %779
	%781 = zext i1 %780 to i32
	%782 = add i32 %781, 48
	%783 = call i32 @putchar(i32 %782)
	%784 = load i32, i32* @d, align 4
	%785 = load i32, i32* @d, align 4
	%786 = icmp slt i32 %784, %785
	%787 = zext i1 %786 to i32
	%788 = add i32 %787, 48
	%789 = call i32 @putchar(i32 %788)
	%790 = load i32, i32* @a, align 4
	%791 = load i32, i32* @a, align 4
	%792 = icmp slt i32 %790, %791
	%793 = zext i1 %792 to i32
	%794 = add i32 %793, 48
	%795 = call i32 @putchar(i32 %794)
	%796 = load i16, i16* @b, align 2
	%797 = sext i16 %796 to i32
	%798 = load i32, i32* @a, align 4
	%799 = icmp slt i32 %797, %798
	%800 = zext i1 %799 to i32
	%801 = add i32 %800, 48
	%802 = call i32 @putchar(i32 %801)
	%803 = load i8, i8* @c, align 1
	%804 = sext i8 %803 to i32
	%805 = load i32, i32* @a, align 4
	%806 = icmp slt i32 %804, %805
	%807 = zext i1 %806 to i32
	%808 = add i32 %807, 48
	%809 = call i32 @putchar(i32 %808)
	%810 = load i32, i32* @d, align 4
	%811 = load i32, i32* @a, align 4
	%812 = icmp slt i32 %810, %811
	%813 = zext i1 %812 to i32
	%814 = add i32 %813, 48
	%815 = call i32 @putchar(i32 %814)
	%816 = load i16, i16* @b, align 2
	%817 = load i16, i16* @b, align 2
	%818 = icmp slt i16 %816, %817
	%819 = zext i1 %818 to i32
	%820 = add i32 %819, 48
	%821 = call i32 @putchar(i32 %820)
	%822 = load i8, i8* @c, align 1
	%823 = sext i8 %822 to i16
	%824 = load i16, i16* @b, align 2
	%825 = icmp slt i16 %823, %824
	%826 = zext i1 %825 to i32
	%827 = add i32 %826, 48
	%828 = call i32 @putchar(i32 %827)
	%829 = load i32, i32* @d, align 4
	%830 = load i16, i16* @b, align 2
	%831 = sext i16 %830 to i32
	%832 = icmp slt i32 %829, %831
	%833 = zext i1 %832 to i32
	%834 = add i32 %833, 48
	%835 = call i32 @putchar(i32 %834)
	%836 = load i8, i8* @c, align 1
	%837 = load i8, i8* @c, align 1
	%838 = icmp slt i8 %836, %837
	%839 = zext i1 %838 to i32
	%840 = add i32 %839, 48
	%841 = call i32 @putchar(i32 %840)
	%842 = load i32, i32* @a, align 4
	%843 = load i32, i32* @a, align 4
	%844 = icmp sgt i32 %842, %843
	%845 = zext i1 %844 to i32
	%846 = add i32 %845, 48
	%847 = call i32 @putchar(i32 %846)
	%848 = load i32, i32* @a, align 4
	%849 = load i16, i16* @b, align 2
	%850 = sext i16 %849 to i32
	%851 = icmp sgt i32 %848, %850
	%852 = zext i1 %851 to i32
	%853 = add i32 %852, 48
	%854 = call i32 @putchar(i32 %853)
	%855 = load i32, i32* @a, align 4
	%856 = load i8, i8* @c, align 1
	%857 = sext i8 %856 to i32
	%858 = icmp sgt i32 %855, %857
	%859 = zext i1 %858 to i32
	%860 = add i32 %859, 48
	%861 = call i32 @putchar(i32 %860)
	%862 = load i32, i32* @a, align 4
	%863 = load i32, i32* @d, align 4
	%864 = icmp sgt i32 %862, %863
	%865 = zext i1 %864 to i32
	%866 = add i32 %865, 48
	%867 = call i32 @putchar(i32 %866)
	%868 = load i16, i16* @b, align 2
	%869 = load i16, i16* @b, align 2
	%870 = icmp sgt i16 %868, %869
	%871 = zext i1 %870 to i32
	%872 = add i32 %871, 48
	%873 = call i32 @putchar(i32 %872)
	%874 = load i16, i16* @b, align 2
	%875 = load i8, i8* @c, align 1
	%876 = sext i8 %875 to i16
	%877 = icmp sgt i16 %874, %876
	%878 = zext i1 %877 to i32
	%879 = add i32 %878, 48
	%880 = call i32 @putchar(i32 %879)
	%881 = load i16, i16* @b, align 2
	%882 = sext i16 %881 to i32
	%883 = load i32, i32* @d, align 4
	%884 = icmp sgt i32 %882, %883
	%885 = zext i1 %884 to i32
	%886 = add i32 %885, 48
	%887 = call i32 @putchar(i32 %886)
	%888 = load i8, i8* @c, align 1
	%889 = load i8, i8* @c, align 1
	%890 = icmp sgt i8 %888, %889
	%891 = zext i1 %890 to i32
	%892 = add i32 %891, 48
	%893 = call i32 @putchar(i32 %892)
	%894 = load i8, i8* @c, align 1
	%895 = sext i8 %894 to i32
	%896 = load i32, i32* @d, align 4
	%897 = icmp sgt i32 %895, %896
	%898 = zext i1 %897 to i32
	%899 = add i32 %898, 48
	%900 = call i32 @putchar(i32 %899)
	%901 = load i32, i32* @d, align 4
	%902 = load i32, i32* @d, align 4
	%903 = icmp sgt i32 %901, %902
	%904 = zext i1 %903 to i32
	%905 = add i32 %904, 48
	%906 = call i32 @putchar(i32 %905)
	%907 = load i32, i32* @a, align 4
	%908 = load i32, i32* @a, align 4
	%909 = icmp sgt i32 %907, %908
	%910 = zext i1 %909 to i32
	%911 = add i32 %910, 48
	%912 = call i32 @putchar(i32 %911)
	%913 = load i16, i16* @b, align 2
	%914 = sext i16 %913 to i32
	%915 = load i32, i32* @a, align 4
	%916 = icmp sgt i32 %914, %915
	%917 = zext i1 %916 to i32
	%918 = add i32 %917, 48
	%919 = call i32 @putchar(i32 %918)
	%920 = load i8, i8* @c, align 1
	%921 = sext i8 %920 to i32
	%922 = load i32, i32* @a, align 4
	%923 = icmp sgt i32 %921, %922
	%924 = zext i1 %923 to i32
	%925 = add i32 %924, 48
	%926 = call i32 @putchar(i32 %925)
	%927 = load i32, i32* @d, align 4
	%928 = load i32, i32* @a, align 4
	%929 = icmp sgt i32 %927, %928
	%930 = zext i1 %929 to i32
	%931 = add i32 %930, 48
	%932 = call i32 @putchar(i32 %931)
	%933 = load i16, i16* @b, align 2
	%934 = load i16, i16* @b, align 2
	%935 = icmp sgt i16 %933, %934
	%936 = zext i1 %935 to i32
	%937 = add i32 %936, 48
	%938 = call i32 @putchar(i32 %937)
	%939 = load i8, i8* @c, align 1
	%940 = sext i8 %939 to i16
	%941 = load i16, i16* @b, align 2
	%942 = icmp sgt i16 %940, %941
	%943 = zext i1 %942 to i32
	%944 = add i32 %943, 48
	%945 = call i32 @putchar(i32 %944)
	%946 = load i32, i32* @d, align 4
	%947 = load i16, i16* @b, align 2
	%948 = sext i16 %947 to i32
	%949 = icmp sgt i32 %946, %948
	%950 = zext i1 %949 to i32
	%951 = add i32 %950, 48
	%952 = call i32 @putchar(i32 %951)
	%953 = load i8, i8* @c, align 1
	%954 = load i8, i8* @c, align 1
	%955 = icmp sgt i8 %953, %954
	%956 = zext i1 %955 to i32
	%957 = add i32 %956, 48
	%958 = call i32 @putchar(i32 %957)
	%959 = load i32, i32* @a, align 4
	%960 = load i32, i32* @a, align 4
	%961 = icmp sle i32 %959, %960
	%962 = zext i1 %961 to i32
	%963 = add i32 %962, 48
	%964 = call i32 @putchar(i32 %963)
	%965 = load i32, i32* @a, align 4
	%966 = load i16, i16* @b, align 2
	%967 = sext i16 %966 to i32
	%968 = icmp sle i32 %965, %967
	%969 = zext i1 %968 to i32
	%970 = add i32 %969, 48
	%971 = call i32 @putchar(i32 %970)
	%972 = load i32, i32* @a, align 4
	%973 = load i8, i8* @c, align 1
	%974 = sext i8 %973 to i32
	%975 = icmp sle i32 %972, %974
	%976 = zext i1 %975 to i32
	%977 = add i32 %976, 48
	%978 = call i32 @putchar(i32 %977)
	%979 = load i32, i32* @a, align 4
	%980 = load i32, i32* @d, align 4
	%981 = icmp sle i32 %979, %980
	%982 = zext i1 %981 to i32
	%983 = add i32 %982, 48
	%984 = call i32 @putchar(i32 %983)
	%985 = load i16, i16* @b, align 2
	%986 = load i16, i16* @b, align 2
	%987 = icmp sle i16 %985, %986
	%988 = zext i1 %987 to i32
	%989 = add i32 %988, 48
	%990 = call i32 @putchar(i32 %989)
	%991 = load i16, i16* @b, align 2
	%992 = load i8, i8* @c, align 1
	%993 = sext i8 %992 to i16
	%994 = icmp sle i16 %991, %993
	%995 = zext i1 %994 to i32
	%996 = add i32 %995, 48
	%997 = call i32 @putchar(i32 %996)
	%998 = load i16, i16* @b, align 2
	%999 = sext i16 %998 to i32
	%1000 = load i32, i32* @d, align 4
	%1001 = icmp sle i32 %999, %1000
	%1002 = zext i1 %1001 to i32
	%1003 = add i32 %1002, 48
	%1004 = call i32 @putchar(i32 %1003)
	%1005 = load i8, i8* @c, align 1
	%1006 = load i8, i8* @c, align 1
	%1007 = icmp sle i8 %1005, %1006
	%1008 = zext i1 %1007 to i32
	%1009 = add i32 %1008, 48
	%1010 = call i32 @putchar(i32 %1009)
	%1011 = load i8, i8* @c, align 1
	%1012 = sext i8 %1011 to i32
	%1013 = load i32, i32* @d, align 4
	%1014 = icmp sle i32 %1012, %1013
	%1015 = zext i1 %1014 to i32
	%1016 = add i32 %1015, 48
	%1017 = call i32 @putchar(i32 %1016)
	%1018 = load i32, i32* @d, align 4
	%1019 = load i32, i32* @d, align 4
	%1020 = icmp sle i32 %1018, %1019
	%1021 = zext i1 %1020 to i32
	%1022 = add i32 %1021, 48
	%1023 = call i32 @putchar(i32 %1022)
	%1024 = load i32, i32* @a, align 4
	%1025 = load i32, i32* @a, align 4
	%1026 = icmp sle i32 %1024, %1025
	%1027 = zext i1 %1026 to i32
	%1028 = add i32 %1027, 48
	%1029 = call i32 @putchar(i32 %1028)
	%1030 = load i16, i16* @b, align 2
	%1031 = sext i16 %1030 to i32
	%1032 = load i32, i32* @a, align 4
	%1033 = icmp sle i32 %1031, %1032
	%1034 = zext i1 %1033 to i32
	%1035 = add i32 %1034, 48
	%1036 = call i32 @putchar(i32 %1035)
	%1037 = load i8, i8* @c, align 1
	%1038 = sext i8 %1037 to i32
	%1039 = load i32, i32* @a, align 4
	%1040 = icmp sle i32 %1038, %1039
	%1041 = zext i1 %1040 to i32
	%1042 = add i32 %1041, 48
	%1043 = call i32 @putchar(i32 %1042)
	%1044 = load i32, i32* @d, align 4
	%1045 = load i32, i32* @a, align 4
	%1046 = icmp sle i32 %1044, %1045
	%1047 = zext i1 %1046 to i32
	%1048 = add i32 %1047, 48
	%1049 = call i32 @putchar(i32 %1048)
	%1050 = load i16, i16* @b, align 2
	%1051 = load i16, i16* @b, align 2
	%1052 = icmp sle i16 %1050, %1051
	%1053 = zext i1 %1052 to i32
	%1054 = add i32 %1053, 48
	%1055 = call i32 @putchar(i32 %1054)
	%1056 = load i8, i8* @c, align 1
	%1057 = sext i8 %1056 to i16
	%1058 = load i16, i16* @b, align 2
	%1059 = icmp sle i16 %1057, %1058
	%1060 = zext i1 %1059 to i32
	%1061 = add i32 %1060, 48
	%1062 = call i32 @putchar(i32 %1061)
	%1063 = load i32, i32* @d, align 4
	%1064 = load i16, i16* @b, align 2
	%1065 = sext i16 %1064 to i32
	%1066 = icmp sle i32 %1063, %1065
	%1067 = zext i1 %1066 to i32
	%1068 = add i32 %1067, 48
	%1069 = call i32 @putchar(i32 %1068)
	%1070 = load i8, i8* @c, align 1
	%1071 = load i8, i8* @c, align 1
	%1072 = icmp sle i8 %1070, %1071
	%1073 = zext i1 %1072 to i32
	%1074 = add i32 %1073, 48
	%1075 = call i32 @putchar(i32 %1074)
	%1076 = load i32, i32* @a, align 4
	%1077 = load i32, i32* @a, align 4
	%1078 = icmp sge i32 %1076, %1077
	%1079 = zext i1 %1078 to i32
	%1080 = add i32 %1079, 48
	%1081 = call i32 @putchar(i32 %1080)
	%1082 = load i32, i32* @a, align 4
	%1083 = load i16, i16* @b, align 2
	%1084 = sext i16 %1083 to i32
	%1085 = icmp sge i32 %1082, %1084
	%1086 = zext i1 %1085 to i32
	%1087 = add i32 %1086, 48
	%1088 = call i32 @putchar(i32 %1087)
	%1089 = load i32, i32* @a, align 4
	%1090 = load i8, i8* @c, align 1
	%1091 = sext i8 %1090 to i32
	%1092 = icmp sge i32 %1089, %1091
	%1093 = zext i1 %1092 to i32
	%1094 = add i32 %1093, 48
	%1095 = call i32 @putchar(i32 %1094)
	%1096 = load i32, i32* @a, align 4
	%1097 = load i32, i32* @d, align 4
	%1098 = icmp sge i32 %1096, %1097
	%1099 = zext i1 %1098 to i32
	%1100 = add i32 %1099, 48
	%1101 = call i32 @putchar(i32 %1100)
	%1102 = load i16, i16* @b, align 2
	%1103 = load i16, i16* @b, align 2
	%1104 = icmp sge i16 %1102, %1103
	%1105 = zext i1 %1104 to i32
	%1106 = add i32 %1105, 48
	%1107 = call i32 @putchar(i32 %1106)
	%1108 = load i16, i16* @b, align 2
	%1109 = load i8, i8* @c, align 1
	%1110 = sext i8 %1109 to i16
	%1111 = icmp sge i16 %1108, %1110
	%1112 = zext i1 %1111 to i32
	%1113 = add i32 %1112, 48
	%1114 = call i32 @putchar(i32 %1113)
	%1115 = load i16, i16* @b, align 2
	%1116 = sext i16 %1115 to i32
	%1117 = load i32, i32* @d, align 4
	%1118 = icmp sge i32 %1116, %1117
	%1119 = zext i1 %1118 to i32
	%1120 = add i32 %1119, 48
	%1121 = call i32 @putchar(i32 %1120)
	%1122 = load i8, i8* @c, align 1
	%1123 = load i8, i8* @c, align 1
	%1124 = icmp sge i8 %1122, %1123
	%1125 = zext i1 %1124 to i32
	%1126 = add i32 %1125, 48
	%1127 = call i32 @putchar(i32 %1126)
	%1128 = load i8, i8* @c, align 1
	%1129 = sext i8 %1128 to i32
	%1130 = load i32, i32* @d, align 4
	%1131 = icmp sge i32 %1129, %1130
	%1132 = zext i1 %1131 to i32
	%1133 = add i32 %1132, 48
	%1134 = call i32 @putchar(i32 %1133)
	%1135 = load i32, i32* @d, align 4
	%1136 = load i32, i32* @d, align 4
	%1137 = icmp sge i32 %1135, %1136
	%1138 = zext i1 %1137 to i32
	%1139 = add i32 %1138, 48
	%1140 = call i32 @putchar(i32 %1139)
	%1141 = load i32, i32* @a, align 4
	%1142 = load i32, i32* @a, align 4
	%1143 = icmp sge i32 %1141, %1142
	%1144 = zext i1 %1143 to i32
	%1145 = add i32 %1144, 48
	%1146 = call i32 @putchar(i32 %1145)
	%1147 = load i16, i16* @b, align 2
	%1148 = sext i16 %1147 to i32
	%1149 = load i32, i32* @a, align 4
	%1150 = icmp sge i32 %1148, %1149
	%1151 = zext i1 %1150 to i32
	%1152 = add i32 %1151, 48
	%1153 = call i32 @putchar(i32 %1152)
	%1154 = load i8, i8* @c, align 1
	%1155 = sext i8 %1154 to i32
	%1156 = load i32, i32* @a, align 4
	%1157 = icmp sge i32 %1155, %1156
	%1158 = zext i1 %1157 to i32
	%1159 = add i32 %1158, 48
	%1160 = call i32 @putchar(i32 %1159)
	%1161 = load i32, i32* @d, align 4
	%1162 = load i32, i32* @a, align 4
	%1163 = icmp sge i32 %1161, %1162
	%1164 = zext i1 %1163 to i32
	%1165 = add i32 %1164, 48
	%1166 = call i32 @putchar(i32 %1165)
	%1167 = load i16, i16* @b, align 2
	%1168 = load i16, i16* @b, align 2
	%1169 = icmp sge i16 %1167, %1168
	%1170 = zext i1 %1169 to i32
	%1171 = add i32 %1170, 48
	%1172 = call i32 @putchar(i32 %1171)
	%1173 = load i8, i8* @c, align 1
	%1174 = sext i8 %1173 to i16
	%1175 = load i16, i16* @b, align 2
	%1176 = icmp sge i16 %1174, %1175
	%1177 = zext i1 %1176 to i32
	%1178 = add i32 %1177, 48
	%1179 = call i32 @putchar(i32 %1178)
	%1180 = load i32, i32* @d, align 4
	%1181 = load i16, i16* @b, align 2
	%1182 = sext i16 %1181 to i32
	%1183 = icmp sge i32 %1180, %1182
	%1184 = zext i1 %1183 to i32
	%1185 = add i32 %1184, 48
	%1186 = call i32 @putchar(i32 %1185)
	%1187 = load i8, i8* @c, align 1
	%1188 = load i8, i8* @c, align 1
	%1189 = icmp sge i8 %1187, %1188
	%1190 = zext i1 %1189 to i32
	%1191 = add i32 %1190, 48
	%1192 = call i32 @putchar(i32 %1191)
	%1193 = load i32, i32* @a, align 4
	%1194 = load i32, i32* @a, align 4
	%1195 = icmp ne i32 %1193, %1194
	%1196 = zext i1 %1195 to i32
	%1197 = add i32 %1196, 48
	%1198 = call i32 @putchar(i32 %1197)
	%1199 = load i32, i32* @a, align 4
	%1200 = load i16, i16* @b, align 2
	%1201 = sext i16 %1200 to i32
	%1202 = icmp ne i32 %1199, %1201
	%1203 = zext i1 %1202 to i32
	%1204 = add i32 %1203, 48
	%1205 = call i32 @putchar(i32 %1204)
	%1206 = load i32, i32* @a, align 4
	%1207 = load i8, i8* @c, align 1
	%1208 = sext i8 %1207 to i32
	%1209 = icmp ne i32 %1206, %1208
	%1210 = zext i1 %1209 to i32
	%1211 = add i32 %1210, 48
	%1212 = call i32 @putchar(i32 %1211)
	%1213 = load i32, i32* @a, align 4
	%1214 = load i32, i32* @d, align 4
	%1215 = icmp ne i32 %1213, %1214
	%1216 = zext i1 %1215 to i32
	%1217 = add i32 %1216, 48
	%1218 = call i32 @putchar(i32 %1217)
	%1219 = load i16, i16* @b, align 2
	%1220 = load i16, i16* @b, align 2
	%1221 = icmp ne i16 %1219, %1220
	%1222 = zext i1 %1221 to i32
	%1223 = add i32 %1222, 48
	%1224 = call i32 @putchar(i32 %1223)
	%1225 = load i16, i16* @b, align 2
	%1226 = load i8, i8* @c, align 1
	%1227 = sext i8 %1226 to i16
	%1228 = icmp ne i16 %1225, %1227
	%1229 = zext i1 %1228 to i32
	%1230 = add i32 %1229, 48
	%1231 = call i32 @putchar(i32 %1230)
	%1232 = load i16, i16* @b, align 2
	%1233 = sext i16 %1232 to i32
	%1234 = load i32, i32* @d, align 4
	%1235 = icmp ne i32 %1233, %1234
	%1236 = zext i1 %1235 to i32
	%1237 = add i32 %1236, 48
	%1238 = call i32 @putchar(i32 %1237)
	%1239 = load i8, i8* @c, align 1
	%1240 = load i8, i8* @c, align 1
	%1241 = icmp ne i8 %1239, %1240
	%1242 = zext i1 %1241 to i32
	%1243 = add i32 %1242, 48
	%1244 = call i32 @putchar(i32 %1243)
	%1245 = load i8, i8* @c, align 1
	%1246 = sext i8 %1245 to i32
	%1247 = load i32, i32* @d, align 4
	%1248 = icmp ne i32 %1246, %1247
	%1249 = zext i1 %1248 to i32
	%1250 = add i32 %1249, 48
	%1251 = call i32 @putchar(i32 %1250)
	%1252 = load i32, i32* @d, align 4
	%1253 = load i32, i32* @d, align 4
	%1254 = icmp ne i32 %1252, %1253
	%1255 = zext i1 %1254 to i32
	%1256 = add i32 %1255, 48
	%1257 = call i32 @putchar(i32 %1256)
	%1258 = load i32, i32* @a, align 4
	%1259 = load i32, i32* @a, align 4
	%1260 = icmp ne i32 %1258, %1259
	%1261 = zext i1 %1260 to i32
	%1262 = add i32 %1261, 48
	%1263 = call i32 @putchar(i32 %1262)
	%1264 = load i16, i16* @b, align 2
	%1265 = sext i16 %1264 to i32
	%1266 = load i32, i32* @a, align 4
	%1267 = icmp ne i32 %1265, %1266
	%1268 = zext i1 %1267 to i32
	%1269 = add i32 %1268, 48
	%1270 = call i32 @putchar(i32 %1269)
	%1271 = load i8, i8* @c, align 1
	%1272 = sext i8 %1271 to i32
	%1273 = load i32, i32* @a, align 4
	%1274 = icmp ne i32 %1272, %1273
	%1275 = zext i1 %1274 to i32
	%1276 = add i32 %1275, 48
	%1277 = call i32 @putchar(i32 %1276)
	%1278 = load i32, i32* @d, align 4
	%1279 = load i32, i32* @a, align 4
	%1280 = icmp ne i32 %1278, %1279
	%1281 = zext i1 %1280 to i32
	%1282 = add i32 %1281, 48
	%1283 = call i32 @putchar(i32 %1282)
	%1284 = load i16, i16* @b, align 2
	%1285 = load i16, i16* @b, align 2
	%1286 = icmp ne i16 %1284, %1285
	%1287 = zext i1 %1286 to i32
	%1288 = add i32 %1287, 48
	%1289 = call i32 @putchar(i32 %1288)
	%1290 = load i8, i8* @c, align 1
	%1291 = sext i8 %1290 to i16
	%1292 = load i16, i16* @b, align 2
	%1293 = icmp ne i16 %1291, %1292
	%1294 = zext i1 %1293 to i32
	%1295 = add i32 %1294, 48
	%1296 = call i32 @putchar(i32 %1295)
	%1297 = load i32, i32* @d, align 4
	%1298 = load i16, i16* @b, align 2
	%1299 = sext i16 %1298 to i32
	%1300 = icmp ne i32 %1297, %1299
	%1301 = zext i1 %1300 to i32
	%1302 = add i32 %1301, 48
	%1303 = call i32 @putchar(i32 %1302)
	%1304 = load i8, i8* @c, align 1
	%1305 = load i8, i8* @c, align 1
	%1306 = icmp ne i8 %1304, %1305
	%1307 = zext i1 %1306 to i32
	%1308 = add i32 %1307, 48
	%1309 = call i32 @putchar(i32 %1308)
	%1310 = load i32, i32* @a, align 4
	%1311 = load i32, i32* @a, align 4
	%1312 = icmp eq i32 %1310, %1311
	%1313 = zext i1 %1312 to i32
	%1314 = add i32 %1313, 48
	%1315 = call i32 @putchar(i32 %1314)
	%1316 = load i32, i32* @a, align 4
	%1317 = load i16, i16* @b, align 2
	%1318 = sext i16 %1317 to i32
	%1319 = icmp eq i32 %1316, %1318
	%1320 = zext i1 %1319 to i32
	%1321 = add i32 %1320, 48
	%1322 = call i32 @putchar(i32 %1321)
	%1323 = load i32, i32* @a, align 4
	%1324 = load i8, i8* @c, align 1
	%1325 = sext i8 %1324 to i32
	%1326 = icmp eq i32 %1323, %1325
	%1327 = zext i1 %1326 to i32
	%1328 = add i32 %1327, 48
	%1329 = call i32 @putchar(i32 %1328)
	%1330 = load i32, i32* @a, align 4
	%1331 = load i32, i32* @d, align 4
	%1332 = icmp eq i32 %1330, %1331
	%1333 = zext i1 %1332 to i32
	%1334 = add i32 %1333, 48
	%1335 = call i32 @putchar(i32 %1334)
	%1336 = load i16, i16* @b, align 2
	%1337 = load i16, i16* @b, align 2
	%1338 = icmp eq i16 %1336, %1337
	%1339 = zext i1 %1338 to i32
	%1340 = add i32 %1339, 48
	%1341 = call i32 @putchar(i32 %1340)
	%1342 = load i16, i16* @b, align 2
	%1343 = load i8, i8* @c, align 1
	%1344 = sext i8 %1343 to i16
	%1345 = icmp eq i16 %1342, %1344
	%1346 = zext i1 %1345 to i32
	%1347 = add i32 %1346, 48
	%1348 = call i32 @putchar(i32 %1347)
	%1349 = load i16, i16* @b, align 2
	%1350 = sext i16 %1349 to i32
	%1351 = load i32, i32* @d, align 4
	%1352 = icmp eq i32 %1350, %1351
	%1353 = zext i1 %1352 to i32
	%1354 = add i32 %1353, 48
	%1355 = call i32 @putchar(i32 %1354)
	%1356 = load i8, i8* @c, align 1
	%1357 = load i8, i8* @c, align 1
	%1358 = icmp eq i8 %1356, %1357
	%1359 = zext i1 %1358 to i32
	%1360 = add i32 %1359, 48
	%1361 = call i32 @putchar(i32 %1360)
	%1362 = load i8, i8* @c, align 1
	%1363 = sext i8 %1362 to i32
	%1364 = load i32, i32* @d, align 4
	%1365 = icmp eq i32 %1363, %1364
	%1366 = zext i1 %1365 to i32
	%1367 = add i32 %1366, 48
	%1368 = call i32 @putchar(i32 %1367)
	%1369 = load i32, i32* @d, align 4
	%1370 = load i32, i32* @d, align 4
	%1371 = icmp eq i32 %1369, %1370
	%1372 = zext i1 %1371 to i32
	%1373 = add i32 %1372, 48
	%1374 = call i32 @putchar(i32 %1373)
	%1375 = load i32, i32* @a, align 4
	%1376 = load i32, i32* @a, align 4
	%1377 = icmp eq i32 %1375, %1376
	%1378 = zext i1 %1377 to i32
	%1379 = add i32 %1378, 48
	%1380 = call i32 @putchar(i32 %1379)
	%1381 = load i16, i16* @b, align 2
	%1382 = sext i16 %1381 to i32
	%1383 = load i32, i32* @a, align 4
	%1384 = icmp eq i32 %1382, %1383
	%1385 = zext i1 %1384 to i32
	%1386 = add i32 %1385, 48
	%1387 = call i32 @putchar(i32 %1386)
	%1388 = load i8, i8* @c, align 1
	%1389 = sext i8 %1388 to i32
	%1390 = load i32, i32* @a, align 4
	%1391 = icmp eq i32 %1389, %1390
	%1392 = zext i1 %1391 to i32
	%1393 = add i32 %1392, 48
	%1394 = call i32 @putchar(i32 %1393)
	%1395 = load i32, i32* @d, align 4
	%1396 = load i32, i32* @a, align 4
	%1397 = icmp eq i32 %1395, %1396
	%1398 = zext i1 %1397 to i32
	%1399 = add i32 %1398, 48
	%1400 = call i32 @putchar(i32 %1399)
	%1401 = load i16, i16* @b, align 2
	%1402 = load i16, i16* @b, align 2
	%1403 = icmp eq i16 %1401, %1402
	%1404 = zext i1 %1403 to i32
	%1405 = add i32 %1404, 48
	%1406 = call i32 @putchar(i32 %1405)
	%1407 = load i8, i8* @c, align 1
	%1408 = sext i8 %1407 to i16
	%1409 = load i16, i16* @b, align 2
	%1410 = icmp eq i16 %1408, %1409
	%1411 = zext i1 %1410 to i32
	%1412 = add i32 %1411, 48
	%1413 = call i32 @putchar(i32 %1412)
	%1414 = load i32, i32* @d, align 4
	%1415 = load i16, i16* @b, align 2
	%1416 = sext i16 %1415 to i32
	%1417 = icmp eq i32 %1414, %1416
	%1418 = zext i1 %1417 to i32
	%1419 = add i32 %1418, 48
	%1420 = call i32 @putchar(i32 %1419)
	%1421 = load i8, i8* @c, align 1
	%1422 = load i8, i8* @c, align 1
	%1423 = icmp eq i8 %1421, %1422
	%1424 = zext i1 %1423 to i32
	%1425 = add i32 %1424, 48
	%1426 = call i32 @putchar(i32 %1425)
	%1427 = load i32, i32* @a, align 4
	%1428 = icmp ne i32 %1427, 0
	br i1 %1428, label %label1, label %label2

	label1:
	%1429 = load i32, i32* @a, align 4
	%1430 = icmp ne i32 %1429, 0
	br label %label2

	label2:
	%1431 = phi i1 [ false, %0 ], [ %1430, %label1 ]
	%1432 = zext i1 %1431 to i32
	%1433 = add i32 %1432, 48
	%1434 = call i32 @putchar(i32 %1433)
	%1435 = load i32, i32* @a, align 4
	%1436 = icmp ne i32 %1435, 0
	br i1 %1436, label %label3, label %label4

	label3:
	%1437 = load i16, i16* @b, align 2
	%1438 = icmp ne i16 %1437, 0
	br label %label4

	label4:
	%1439 = phi i1 [ false, %label2 ], [ %1438, %label3 ]
	%1440 = zext i1 %1439 to i32
	%1441 = add i32 %1440, 48
	%1442 = call i32 @putchar(i32 %1441)
	%1443 = load i32, i32* @a, align 4
	%1444 = icmp ne i32 %1443, 0
	br i1 %1444, label %label5, label %label6

	label5:
	%1445 = load i8, i8* @c, align 1
	%1446 = icmp ne i8 %1445, 0
	br label %label6

	label6:
	%1447 = phi i1 [ false, %label4 ], [ %1446, %label5 ]
	%1448 = zext i1 %1447 to i32
	%1449 = add i32 %1448, 48
	%1450 = call i32 @putchar(i32 %1449)
	%1451 = load i32, i32* @a, align 4
	%1452 = icmp ne i32 %1451, 0
	br i1 %1452, label %label7, label %label8

	label7:
	%1453 = load i32, i32* @d, align 4
	%1454 = icmp ne i32 %1453, 0
	br label %label8

	label8:
	%1455 = phi i1 [ false, %label6 ], [ %1454, %label7 ]
	%1456 = zext i1 %1455 to i32
	%1457 = add i32 %1456, 48
	%1458 = call i32 @putchar(i32 %1457)
	%1459 = load i16, i16* @b, align 2
	%1460 = icmp ne i16 %1459, 0
	br i1 %1460, label %label9, label %label10

	label9:
	%1461 = load i16, i16* @b, align 2
	%1462 = icmp ne i16 %1461, 0
	br label %label10

	label10:
	%1463 = phi i1 [ false, %label8 ], [ %1462, %label9 ]
	%1464 = zext i1 %1463 to i32
	%1465 = add i32 %1464, 48
	%1466 = call i32 @putchar(i32 %1465)
	%1467 = load i16, i16* @b, align 2
	%1468 = icmp ne i16 %1467, 0
	br i1 %1468, label %label11, label %label12

	label11:
	%1469 = load i8, i8* @c, align 1
	%1470 = icmp ne i8 %1469, 0
	br label %label12

	label12:
	%1471 = phi i1 [ false, %label10 ], [ %1470, %label11 ]
	%1472 = zext i1 %1471 to i32
	%1473 = add i32 %1472, 48
	%1474 = call i32 @putchar(i32 %1473)
	%1475 = load i16, i16* @b, align 2
	%1476 = icmp ne i16 %1475, 0
	br i1 %1476, label %label13, label %label14

	label13:
	%1477 = load i32, i32* @d, align 4
	%1478 = icmp ne i32 %1477, 0
	br label %label14

	label14:
	%1479 = phi i1 [ false, %label12 ], [ %1478, %label13 ]
	%1480 = zext i1 %1479 to i32
	%1481 = add i32 %1480, 48
	%1482 = call i32 @putchar(i32 %1481)
	%1483 = load i8, i8* @c, align 1
	%1484 = icmp ne i8 %1483, 0
	br i1 %1484, label %label15, label %label16

	label15:
	%1485 = load i8, i8* @c, align 1
	%1486 = icmp ne i8 %1485, 0
	br label %label16

	label16:
	%1487 = phi i1 [ false, %label14 ], [ %1486, %label15 ]
	%1488 = zext i1 %1487 to i32
	%1489 = add i32 %1488, 48
	%1490 = call i32 @putchar(i32 %1489)
	%1491 = load i8, i8* @c, align 1
	%1492 = icmp ne i8 %1491, 0
	br i1 %1492, label %label17, label %label18

	label17:
	%1493 = load i32, i32* @d, align 4
	%1494 = icmp ne i32 %1493, 0
	br label %label18

	label18:
	%1495 = phi i1 [ false, %label16 ], [ %1494, %label17 ]
	%1496 = zext i1 %1495 to i32
	%1497 = add i32 %1496, 48
	%1498 = call i32 @putchar(i32 %1497)
	%1499 = load i32, i32* @d, align 4
	%1500 = icmp ne i32 %1499, 0
	br i1 %1500, label %label19, label %label20

	label19:
	%1501 = load i32, i32* @d, align 4
	%1502 = icmp ne i32 %1501, 0
	br label %label20

	label20:
	%1503 = phi i1 [ false, %label18 ], [ %1502, %label19 ]
	%1504 = zext i1 %1503 to i32
	%1505 = add i32 %1504, 48
	%1506 = call i32 @putchar(i32 %1505)
	%1507 = load i32, i32* @a, align 4
	%1508 = icmp ne i32 %1507, 0
	br i1 %1508, label %label21, label %label22

	label21:
	%1509 = load i32, i32* @a, align 4
	%1510 = icmp ne i32 %1509, 0
	br label %label22

	label22:
	%1511 = phi i1 [ false, %label20 ], [ %1510, %label21 ]
	%1512 = zext i1 %1511 to i32
	%1513 = add i32 %1512, 48
	%1514 = call i32 @putchar(i32 %1513)
	%1515 = load i16, i16* @b, align 2
	%1516 = icmp ne i16 %1515, 0
	br i1 %1516, label %label23, label %label24

	label23:
	%1517 = load i32, i32* @a, align 4
	%1518 = icmp ne i32 %1517, 0
	br label %label24

	label24:
	%1519 = phi i1 [ false, %label22 ], [ %1518, %label23 ]
	%1520 = zext i1 %1519 to i32
	%1521 = add i32 %1520, 48
	%1522 = call i32 @putchar(i32 %1521)
	%1523 = load i8, i8* @c, align 1
	%1524 = icmp ne i8 %1523, 0
	br i1 %1524, label %label25, label %label26

	label25:
	%1525 = load i32, i32* @a, align 4
	%1526 = icmp ne i32 %1525, 0
	br label %label26

	label26:
	%1527 = phi i1 [ false, %label24 ], [ %1526, %label25 ]
	%1528 = zext i1 %1527 to i32
	%1529 = add i32 %1528, 48
	%1530 = call i32 @putchar(i32 %1529)
	%1531 = load i32, i32* @d, align 4
	%1532 = icmp ne i32 %1531, 0
	br i1 %1532, label %label27, label %label28

	label27:
	%1533 = load i32, i32* @a, align 4
	%1534 = icmp ne i32 %1533, 0
	br label %label28

	label28:
	%1535 = phi i1 [ false, %label26 ], [ %1534, %label27 ]
	%1536 = zext i1 %1535 to i32
	%1537 = add i32 %1536, 48
	%1538 = call i32 @putchar(i32 %1537)
	%1539 = load i16, i16* @b, align 2
	%1540 = icmp ne i16 %1539, 0
	br i1 %1540, label %label29, label %label30

	label29:
	%1541 = load i16, i16* @b, align 2
	%1542 = icmp ne i16 %1541, 0
	br label %label30

	label30:
	%1543 = phi i1 [ false, %label28 ], [ %1542, %label29 ]
	%1544 = zext i1 %1543 to i32
	%1545 = add i32 %1544, 48
	%1546 = call i32 @putchar(i32 %1545)
	%1547 = load i8, i8* @c, align 1
	%1548 = icmp ne i8 %1547, 0
	br i1 %1548, label %label31, label %label32

	label31:
	%1549 = load i16, i16* @b, align 2
	%1550 = icmp ne i16 %1549, 0
	br label %label32

	label32:
	%1551 = phi i1 [ false, %label30 ], [ %1550, %label31 ]
	%1552 = zext i1 %1551 to i32
	%1553 = add i32 %1552, 48
	%1554 = call i32 @putchar(i32 %1553)
	%1555 = load i32, i32* @d, align 4
	%1556 = icmp ne i32 %1555, 0
	br i1 %1556, label %label33, label %label34

	label33:
	%1557 = load i16, i16* @b, align 2
	%1558 = icmp ne i16 %1557, 0
	br label %label34

	label34:
	%1559 = phi i1 [ false, %label32 ], [ %1558, %label33 ]
	%1560 = zext i1 %1559 to i32
	%1561 = add i32 %1560, 48
	%1562 = call i32 @putchar(i32 %1561)
	%1563 = load i8, i8* @c, align 1
	%1564 = icmp ne i8 %1563, 0
	br i1 %1564, label %label35, label %label36

	label35:
	%1565 = load i8, i8* @c, align 1
	%1566 = icmp ne i8 %1565, 0
	br label %label36

	label36:
	%1567 = phi i1 [ false, %label34 ], [ %1566, %label35 ]
	%1568 = zext i1 %1567 to i32
	%1569 = add i32 %1568, 48
	%1570 = call i32 @putchar(i32 %1569)
	%1571 = load i32, i32* @a, align 4
	%1572 = icmp ne i32 %1571, 0
	br i1 %1572, label %label38, label %label37

	label37:
	%1573 = load i32, i32* @a, align 4
	%1574 = icmp ne i32 %1573, 0
	br label %label38

	label38:
	%1575 = phi i1 [ true, %label36 ], [ %1574, %label37 ]
	%1576 = zext i1 %1575 to i32
	%1577 = add i32 %1576, 48
	%1578 = call i32 @putchar(i32 %1577)
	%1579 = load i32, i32* @a, align 4
	%1580 = icmp ne i32 %1579, 0
	br i1 %1580, label %label40, label %label39

	label39:
	%1581 = load i16, i16* @b, align 2
	%1582 = icmp ne i16 %1581, 0
	br label %label40

	label40:
	%1583 = phi i1 [ true, %label38 ], [ %1582, %label39 ]
	%1584 = zext i1 %1583 to i32
	%1585 = add i32 %1584, 48
	%1586 = call i32 @putchar(i32 %1585)
	%1587 = load i32, i32* @a, align 4
	%1588 = icmp ne i32 %1587, 0
	br i1 %1588, label %label42, label %label41

	label41:
	%1589 = load i8, i8* @c, align 1
	%1590 = icmp ne i8 %1589, 0
	br label %label42

	label42:
	%1591 = phi i1 [ true, %label40 ], [ %1590, %label41 ]
	%1592 = zext i1 %1591 to i32
	%1593 = add i32 %1592, 48
	%1594 = call i32 @putchar(i32 %1593)
	%1595 = load i32, i32* @a, align 4
	%1596 = icmp ne i32 %1595, 0
	br i1 %1596, label %label44, label %label43

	label43:
	%1597 = load i32, i32* @d, align 4
	%1598 = icmp ne i32 %1597, 0
	br label %label44

	label44:
	%1599 = phi i1 [ true, %label42 ], [ %1598, %label43 ]
	%1600 = zext i1 %1599 to i32
	%1601 = add i32 %1600, 48
	%1602 = call i32 @putchar(i32 %1601)
	%1603 = load i16, i16* @b, align 2
	%1604 = icmp ne i16 %1603, 0
	br i1 %1604, label %label46, label %label45

	label45:
	%1605 = load i16, i16* @b, align 2
	%1606 = icmp ne i16 %1605, 0
	br label %label46

	label46:
	%1607 = phi i1 [ true, %label44 ], [ %1606, %label45 ]
	%1608 = zext i1 %1607 to i32
	%1609 = add i32 %1608, 48
	%1610 = call i32 @putchar(i32 %1609)
	%1611 = load i16, i16* @b, align 2
	%1612 = icmp ne i16 %1611, 0
	br i1 %1612, label %label48, label %label47

	label47:
	%1613 = load i8, i8* @c, align 1
	%1614 = icmp ne i8 %1613, 0
	br label %label48

	label48:
	%1615 = phi i1 [ true, %label46 ], [ %1614, %label47 ]
	%1616 = zext i1 %1615 to i32
	%1617 = add i32 %1616, 48
	%1618 = call i32 @putchar(i32 %1617)
	%1619 = load i16, i16* @b, align 2
	%1620 = icmp ne i16 %1619, 0
	br i1 %1620, label %label50, label %label49

	label49:
	%1621 = load i32, i32* @d, align 4
	%1622 = icmp ne i32 %1621, 0
	br label %label50

	label50:
	%1623 = phi i1 [ true, %label48 ], [ %1622, %label49 ]
	%1624 = zext i1 %1623 to i32
	%1625 = add i32 %1624, 48
	%1626 = call i32 @putchar(i32 %1625)
	%1627 = load i8, i8* @c, align 1
	%1628 = icmp ne i8 %1627, 0
	br i1 %1628, label %label52, label %label51

	label51:
	%1629 = load i8, i8* @c, align 1
	%1630 = icmp ne i8 %1629, 0
	br label %label52

	label52:
	%1631 = phi i1 [ true, %label50 ], [ %1630, %label51 ]
	%1632 = zext i1 %1631 to i32
	%1633 = add i32 %1632, 48
	%1634 = call i32 @putchar(i32 %1633)
	%1635 = load i8, i8* @c, align 1
	%1636 = icmp ne i8 %1635, 0
	br i1 %1636, label %label54, label %label53

	label53:
	%1637 = load i32, i32* @d, align 4
	%1638 = icmp ne i32 %1637, 0
	br label %label54

	label54:
	%1639 = phi i1 [ true, %label52 ], [ %1638, %label53 ]
	%1640 = zext i1 %1639 to i32
	%1641 = add i32 %1640, 48
	%1642 = call i32 @putchar(i32 %1641)
	%1643 = load i32, i32* @d, align 4
	%1644 = icmp ne i32 %1643, 0
	br i1 %1644, label %label56, label %label55

	label55:
	%1645 = load i32, i32* @d, align 4
	%1646 = icmp ne i32 %1645, 0
	br label %label56

	label56:
	%1647 = phi i1 [ true, %label54 ], [ %1646, %label55 ]
	%1648 = zext i1 %1647 to i32
	%1649 = add i32 %1648, 48
	%1650 = call i32 @putchar(i32 %1649)
	%1651 = load i32, i32* @a, align 4
	%1652 = icmp ne i32 %1651, 0
	br i1 %1652, label %label58, label %label57

	label57:
	%1653 = load i32, i32* @a, align 4
	%1654 = icmp ne i32 %1653, 0
	br label %label58

	label58:
	%1655 = phi i1 [ true, %label56 ], [ %1654, %label57 ]
	%1656 = zext i1 %1655 to i32
	%1657 = add i32 %1656, 48
	%1658 = call i32 @putchar(i32 %1657)
	%1659 = load i16, i16* @b, align 2
	%1660 = icmp ne i16 %1659, 0
	br i1 %1660, label %label60, label %label59

	label59:
	%1661 = load i32, i32* @a, align 4
	%1662 = icmp ne i32 %1661, 0
	br label %label60

	label60:
	%1663 = phi i1 [ true, %label58 ], [ %1662, %label59 ]
	%1664 = zext i1 %1663 to i32
	%1665 = add i32 %1664, 48
	%1666 = call i32 @putchar(i32 %1665)
	%1667 = load i8, i8* @c, align 1
	%1668 = icmp ne i8 %1667, 0
	br i1 %1668, label %label62, label %label61

	label61:
	%1669 = load i32, i32* @a, align 4
	%1670 = icmp ne i32 %1669, 0
	br label %label62

	label62:
	%1671 = phi i1 [ true, %label60 ], [ %1670, %label61 ]
	%1672 = zext i1 %1671 to i32
	%1673 = add i32 %1672, 48
	%1674 = call i32 @putchar(i32 %1673)
	%1675 = load i32, i32* @d, align 4
	%1676 = icmp ne i32 %1675, 0
	br i1 %1676, label %label64, label %label63

	label63:
	%1677 = load i32, i32* @a, align 4
	%1678 = icmp ne i32 %1677, 0
	br label %label64

	label64:
	%1679 = phi i1 [ true, %label62 ], [ %1678, %label63 ]
	%1680 = zext i1 %1679 to i32
	%1681 = add i32 %1680, 48
	%1682 = call i32 @putchar(i32 %1681)
	%1683 = load i16, i16* @b, align 2
	%1684 = icmp ne i16 %1683, 0
	br i1 %1684, label %label66, label %label65

	label65:
	%1685 = load i16, i16* @b, align 2
	%1686 = icmp ne i16 %1685, 0
	br label %label66

	label66:
	%1687 = phi i1 [ true, %label64 ], [ %1686, %label65 ]
	%1688 = zext i1 %1687 to i32
	%1689 = add i32 %1688, 48
	%1690 = call i32 @putchar(i32 %1689)
	%1691 = load i8, i8* @c, align 1
	%1692 = icmp ne i8 %1691, 0
	br i1 %1692, label %label68, label %label67

	label67:
	%1693 = load i16, i16* @b, align 2
	%1694 = icmp ne i16 %1693, 0
	br label %label68

	label68:
	%1695 = phi i1 [ true, %label66 ], [ %1694, %label67 ]
	%1696 = zext i1 %1695 to i32
	%1697 = add i32 %1696, 48
	%1698 = call i32 @putchar(i32 %1697)
	%1699 = load i32, i32* @d, align 4
	%1700 = icmp ne i32 %1699, 0
	br i1 %1700, label %label70, label %label69

	label69:
	%1701 = load i16, i16* @b, align 2
	%1702 = icmp ne i16 %1701, 0
	br label %label70

	label70:
	%1703 = phi i1 [ true, %label68 ], [ %1702, %label69 ]
	%1704 = zext i1 %1703 to i32
	%1705 = add i32 %1704, 48
	%1706 = call i32 @putchar(i32 %1705)
	%1707 = load i8, i8* @c, align 1
	%1708 = icmp ne i8 %1707, 0
	br i1 %1708, label %label72, label %label71

	label71:
	%1709 = load i8, i8* @c, align 1
	%1710 = icmp ne i8 %1709, 0
	br label %label72

	label72:
	%1711 = phi i1 [ true, %label70 ], [ %1710, %label71 ]
	%1712 = zext i1 %1711 to i32
	%1713 = add i32 %1712, 48
	%1714 = call i32 @putchar(i32 %1713)
	ret i32 0
}

