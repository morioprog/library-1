---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  - icon: ':question:'
    path: fps/ntt-friendly-fps.hpp
    title: "NTT mod\u7528FPS\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':question:'
    path: ntt/ntt-avx2.hpp
    title: ntt/ntt-avx2.hpp
  - icon: ':question:'
    path: modint/simd-montgomery.hpp
    title: modint/simd-montgomery.hpp
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/polynomial-gcd.hpp
    title: "\u591A\u9805\u5F0FGCD"
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_polynomials
    links:
    - https://judge.yosupo.jp/problem/inv_of_polynomials
  bundledCode: "#line 1 \"verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_polynomials\"\n\n#include\
    \ <immintrin.h>\n//\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3\
    \ \"misc/fastio.hpp\"\nusing namespace std;\n\nnamespace fastio {\nstatic constexpr\
    \ int SZ = 1 << 17;\nchar ibuf[SZ], obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\
    \nstruct Pre {\n  char num[40000];\n  constexpr Pre() : num() {\n    for (int\
    \ i = 0; i < 10000; i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--)\
    \ {\n        num[i * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n\
    \  }\n} constexpr pre;\n\ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir\
    \ - pil);\n  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n\
    \  pil = 0;\n}\ninline void flush() {\n  fwrite(obuf, 1, por, stdout);\n  por\
    \ = 0;\n}\n\ninline void rd(char& c) { c = ibuf[pil++]; }\ntemplate <typename\
    \ T>\ninline void rd(T& x) {\n  if (pil + 32 > pir) load();\n  char c;\n  do\n\
    \    c = ibuf[pil++];\n  while (c < '-');\n  bool minus = 0;\n  if (c == '-')\
    \ {\n    minus = 1;\n    c = ibuf[pil++];\n  }\n  x = 0;\n  while (c >= '0') {\n\
    \    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n  }\n  if (minus) x = -x;\n\
    }\ninline void rd() {}\ntemplate <typename Head, typename... Tail>\ninline void\
    \ rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline void\
    \ wt(char c) { obuf[por++] = c; }\ntemplate <typename T>\ninline void wt(T x)\
    \ {\n  if (por > SZ - 32) flush();\n  if (!x) {\n    obuf[por++] = '0';\n    return;\n\
    \  }\n  if (x < 0) {\n    obuf[por++] = '-';\n    x = -x;\n  }\n  int i = 12;\n\
    \  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf + i, pre.num + (x % 10000)\
    \ * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n    if (x < 10)\
    \ {\n      wt(char('0' + char(x)));\n    } else {\n      uint32_t q = (uint32_t(x)\
    \ * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n      obuf[por + 0]\
    \ = '0' + q;\n      obuf[por + 1] = '0' + r;\n      por += 2;\n    }\n  } else\
    \ {\n    if (x < 1000) {\n      memcpy(obuf + por, pre.num + (x << 2) + 1, 3);\n\
    \      por += 3;\n    } else {\n      memcpy(obuf + por, pre.num + (x << 2), 4);\n\
    \      por += 4;\n    }\n  }\n  memcpy(obuf + por, buf + i + 4, 12 - i);\n  por\
    \ += 12 - i;\n}\n\ninline void wt() {}\ntemplate <typename Head, typename... Tail>\n\
    inline void wt(Head head, Tail... tail) {\n  wt(head);\n  wt(tail...);\n}\ntemplate\
    \ <typename T>\ninline void wtn(T x) {\n  wt(x, '\\n');\n}\n\nstruct Dummy {\n\
    \  Dummy() { atexit(flush); }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\n\
    using fastio::wt;\nusing fastio::wtn;\n#line 9 \"verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp\"\
    \n//\n#line 3 \"fps/ntt-friendly-fps.hpp\"\nusing namespace std;\n\n#line 3 \"\
    ntt/ntt-avx2.hpp\"\nusing namespace std;\n\n#line 3 \"modint/simd-montgomery.hpp\"\
    \nusing namespace std;\n#line 5 \"modint/simd-montgomery.hpp\"\n\n__attribute__((target(\"\
    sse4.2\"))) __attribute__((always_inline)) __m128i\nmy128_mullo_epu32(const __m128i\
    \ &a, const __m128i &b) {\n  return _mm_mullo_epi32(a, b);\n}\n\n__attribute__((target(\"\
    sse4.2\"))) __attribute__((always_inline)) __m128i\nmy128_mulhi_epu32(const __m128i\
    \ &a, const __m128i &b) {\n  __m128i a13 = _mm_shuffle_epi32(a, 0xF5);\n  __m128i\
    \ b13 = _mm_shuffle_epi32(b, 0xF5);\n  __m128i prod02 = _mm_mul_epu32(a, b);\n\
    \  __m128i prod13 = _mm_mul_epu32(a13, b13);\n  __m128i prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02,\
    \ prod13),\n                                    _mm_unpackhi_epi32(prod02, prod13));\n\
    \  return prod;\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_mul_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &r,\n                   const __m128i &m1) {\n  return _mm_sub_epi32(\n    \
    \  _mm_add_epi32(my128_mulhi_epu32(a, b), m1),\n      my128_mulhi_epu32(my128_mullo_epu32(my128_mullo_epu32(a,\
    \ b), r), m1));\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_add_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &m2,\n                   const __m128i &m0) {\n  __m128i ret = _mm_sub_epi32(_mm_add_epi32(a,\
    \ b), m2);\n  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2),\
    \ ret);\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_sub_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &m2,\n                   const __m128i &m0) {\n  __m128i ret = _mm_sub_epi32(a,\
    \ b);\n  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);\n\
    }\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline)) __m256i\n\
    my256_mullo_epu32(const __m256i &a, const __m256i &b) {\n  return _mm256_mullo_epi32(a,\
    \ b);\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline)) __m256i\n\
    my256_mulhi_epu32(const __m256i &a, const __m256i &b) {\n  __m256i a13 = _mm256_shuffle_epi32(a,\
    \ 0xF5);\n  __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);\n  __m256i prod02 = _mm256_mul_epu32(a,\
    \ b);\n  __m256i prod13 = _mm256_mul_epu32(a13, b13);\n  __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02,\
    \ prod13),\n                                       _mm256_unpackhi_epi32(prod02,\
    \ prod13));\n  return prod;\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline))\
    \ __m256i\nmontgomery_mul_256(const __m256i &a, const __m256i &b, const __m256i\
    \ &r,\n                   const __m256i &m1) {\n  return _mm256_sub_epi32(\n \
    \     _mm256_add_epi32(my256_mulhi_epu32(a, b), m1),\n      my256_mulhi_epu32(my256_mullo_epu32(my256_mullo_epu32(a,\
    \ b), r), m1));\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline))\
    \ __m256i\nmontgomery_add_256(const __m256i &a, const __m256i &b, const __m256i\
    \ &m2,\n                   const __m256i &m0) {\n  __m256i ret = _mm256_sub_epi32(_mm256_add_epi32(a,\
    \ b), m2);\n  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0,\
    \ ret), m2),\n                          ret);\n}\n\n__attribute__((target(\"avx2\"\
    ))) __attribute__((always_inline)) __m256i\nmontgomery_sub_256(const __m256i &a,\
    \ const __m256i &b, const __m256i &m2,\n                   const __m256i &m0)\
    \ {\n  __m256i ret = _mm256_sub_epi32(a, b);\n  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0,\
    \ ret), m2),\n                          ret);\n}\n#line 6 \"ntt/ntt-avx2.hpp\"\
    \n\nconstexpr int SZ = 1 << 19;\nuint32_t buf1_[SZ * 2] __attribute__((aligned(64)));\n\
    uint32_t buf2_[SZ * 2] __attribute__((aligned(64)));\n\ntemplate <typename mint>\n\
    struct NTT {\n  static constexpr uint32_t get_pr() {\n    uint32_t mod = mint::get_mod();\n\
    \    using u64 = uint64_t;\n    u64 ds[32] = {};\n    int idx = 0;\n    u64 m\
    \ = mod - 1;\n    for (u64 i = 2; i * i <= m; ++i) {\n      if (m % i == 0) {\n\
    \        ds[idx++] = i;\n        while (m % i == 0) m /= i;\n      }\n    }\n\
    \    if (m != 1) ds[idx++] = m;\n\n    uint32_t pr = 2;\n    while (1) {\n   \
    \   int flg = 1;\n      for (int i = 0; i < idx; ++i) {\n        u64 a = pr, b\
    \ = (mod - 1) / ds[i], r = 1;\n        while (b) {\n          if (b & 1) r = r\
    \ * a % mod;\n          a = a * a % mod;\n          b >>= 1;\n        }\n    \
    \    if (r == 1) {\n          flg = 0;\n          break;\n        }\n      }\n\
    \      if (flg == 1) break;\n      ++pr;\n    }\n    return pr;\n  };\n\n  static\
    \ constexpr uint32_t mod = mint::get_mod();\n  static constexpr uint32_t pr =\
    \ get_pr();\n  static constexpr int level = __builtin_ctzll(mod - 1);\n  mint\
    \ dw[level], dy[level];\n  mint *buf1, *buf2;\n\n  constexpr NTT() {\n    setwy(level);\n\
    \    buf1 = reinterpret_cast<mint *>(::buf1_);\n    buf2 = reinterpret_cast<mint\
    \ *>(::buf2_);\n  }\n\n  constexpr void setwy(int k) {\n    mint w[level], y[level];\n\
    \    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n    y[k - 1] = w[k - 1].inverse();\n\
    \    for (int i = k - 2; i > 0; --i)\n      w[i] = w[i + 1] * w[i + 1], y[i] =\
    \ y[i + 1] * y[i + 1];\n    dw[0] = dy[0] = w[1] * w[1];\n    dw[1] = w[1], dy[1]\
    \ = y[1], dw[2] = w[2], dy[2] = y[2];\n    for (int i = 3; i < k; ++i) {\n   \
    \   dw[i] = dw[i - 1] * y[i - 2] * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] *\
    \ y[i];\n    }\n  }\n\n  __attribute__((target(\"avx2\"))) void ntt(mint *a, int\
    \ n) {\n    int k = n ? __builtin_ctz(n) : 0;\n    if (k == 0) return;\n    if\
    \ (k == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0]\
    \ + a1;\n      return;\n    }\n    if (k & 1) {\n      int v = 1 << (k - 1);\n\
    \      if (v < 8) {\n        for (int j = 0; j < v; ++j) {\n          mint ajv\
    \ = a[j + v];\n          a[j + v] = a[j] - ajv;\n          a[j] += ajv;\n    \
    \    }\n      } else {\n        const __m256i m0 = _mm256_set1_epi32(0);\n   \
    \     const __m256i m2 = _mm256_set1_epi32(mod + mod);\n        int j0 = 0;\n\
    \        int j1 = v;\n        for (; j0 < v; j0 += 8, j1 += 8) {\n          __m256i\
    \ T0 = _mm256_loadu_si256((__m256i *)(a + j0));\n          __m256i T1 = _mm256_loadu_si256((__m256i\
    \ *)(a + j1));\n          __m256i naj = montgomery_add_256(T0, T1, m2, m0);\n\
    \          __m256i najv = montgomery_sub_256(T0, T1, m2, m0);\n          _mm256_storeu_si256((__m256i\
    \ *)(a + j0), naj);\n          _mm256_storeu_si256((__m256i *)(a + j1), najv);\n\
    \        }\n      }\n    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 <<\
    \ (k - 2 - (k & 1));\n    mint one = mint(1);\n    mint imag = dw[1];\n    while\
    \ (v) {\n      if (v == 1) {\n        mint ww = one, xx = one, wx = one;\n   \
    \     for (int jh = 0; jh < u;) {\n          ww = xx * xx, wx = ww * xx;\n   \
    \       mint t0 = a[jh + 0], t1 = a[jh + 1] * xx;\n          mint t2 = a[jh +\
    \ 2] * ww, t3 = a[jh + 3] * wx;\n          mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n\
    \          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;\n          a[jh + 0]\
    \ = t0p2 + t1p3, a[jh + 1] = t0p2 - t1p3;\n          a[jh + 2] = t0m2 + t1m3,\
    \ a[jh + 3] = t0m2 - t1m3;\n          xx *= dw[__builtin_ctz((jh += 4))];\n  \
    \      }\n      } else if (v == 4) {\n        const __m128i m0 = _mm_set1_epi32(0);\n\
    \        const __m128i m1 = _mm_set1_epi32(mod);\n        const __m128i m2 = _mm_set1_epi32(mod\
    \ + mod);\n        const __m128i r = _mm_set1_epi32(mint::r);\n        const __m128i\
    \ Imag = _mm_set1_epi32(imag.a);\n        mint ww = one, xx = one, wx = one;\n\
    \        for (int jh = 0; jh < u;) {\n          if (jh == 0) {\n            int\
    \ j0 = 0;\n            int j1 = v;\n            int j2 = j1 + v;\n           \
    \ int j3 = j2 + v;\n            int je = v;\n            for (; j0 < je; j0 +=\
    \ 4, j1 += 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i T0P2 = montgomery_add_128(T0, T2, m2, m0);\n        \
    \      const __m128i T1P3 = montgomery_add_128(T1, T3, m2, m0);\n            \
    \  const __m128i T0M2 = montgomery_sub_128(T0, T2, m2, m0);\n              const\
    \ __m128i T1M3 = montgomery_mul_128(\n                  montgomery_sub_128(T1,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P2, T1P3, m2, m0));\n   \
    \           _mm_storeu_si128((__m128i *)(a + j1),\n                          \
    \     montgomery_sub_128(T0P2, T1P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j2),\n                               montgomery_add_128(T0M2, T1M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M2, T1M3, m2, m0));\n            }\n   \
    \       } else {\n            ww = xx * xx, wx = ww * xx;\n            const __m128i\
    \ WW = _mm_set1_epi32(ww.a);\n            const __m128i WX = _mm_set1_epi32(wx.a);\n\
    \            const __m128i XX = _mm_set1_epi32(xx.a);\n            int j0 = jh\
    \ * v;\n            int j1 = j0 + v;\n            int j2 = j1 + v;\n         \
    \   int j3 = j2 + v;\n            int je = j1;\n            for (; j0 < je; j0\
    \ += 4, j1 += 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i MT1 = montgomery_mul_128(T1, XX, r, m1);\n          \
    \    const __m128i MT2 = montgomery_mul_128(T2, WW, r, m1);\n              const\
    \ __m128i MT3 = montgomery_mul_128(T3, WX, r, m1);\n              const __m128i\
    \ T0P2 = montgomery_add_128(T0, MT2, m2, m0);\n              const __m128i T1P3\
    \ = montgomery_add_128(MT1, MT3, m2, m0);\n              const __m128i T0M2 =\
    \ montgomery_sub_128(T0, MT2, m2, m0);\n              const __m128i T1M3 = montgomery_mul_128(\n\
    \                  montgomery_sub_128(MT1, MT3, m2, m0), Imag, r, m1);\n     \
    \         _mm_storeu_si128((__m128i *)(a + j0),\n                            \
    \   montgomery_add_128(T0P2, T1P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_sub_128(T0P2, T1P3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j2),\n               \
    \                montgomery_add_128(T0M2, T1M3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j3),\n                               montgomery_sub_128(T0M2, T1M3, m2,\
    \ m0));\n            }\n          }\n          xx *= dw[__builtin_ctz((jh += 4))];\n\
    \        }\n      } else {\n        const __m256i m0 = _mm256_set1_epi32(0);\n\
    \        const __m256i m1 = _mm256_set1_epi32(mod);\n        const __m256i m2\
    \ = _mm256_set1_epi32(mod + mod);\n        const __m256i r = _mm256_set1_epi32(mint::r);\n\
    \        const __m256i Imag = _mm256_set1_epi32(imag.a);\n        mint ww = one,\
    \ xx = one, wx = one;\n        for (int jh = 0; jh < u;) {\n          if (jh ==\
    \ 0) {\n            int j0 = 0;\n            int j1 = v;\n            int j2 =\
    \ j1 + v;\n            int j3 = j2 + v;\n            int je = v;\n           \
    \ for (; j0 < je; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {\n              const __m256i\
    \ T0 = _mm256_loadu_si256((__m256i *)(a + j0));\n              const __m256i T1\
    \ = _mm256_loadu_si256((__m256i *)(a + j1));\n              const __m256i T2 =\
    \ _mm256_loadu_si256((__m256i *)(a + j2));\n              const __m256i T3 = _mm256_loadu_si256((__m256i\
    \ *)(a + j3));\n              const __m256i T0P2 = montgomery_add_256(T0, T2,\
    \ m2, m0);\n              const __m256i T1P3 = montgomery_add_256(T1, T3, m2,\
    \ m0);\n              const __m256i T0M2 = montgomery_sub_256(T0, T2, m2, m0);\n\
    \              const __m256i T1M3 = montgomery_mul_256(\n                  montgomery_sub_256(T1,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm256_storeu_si256((__m256i *)(a\
    \ + j0),\n                                  montgomery_add_256(T0P2, T1P3, m2,\
    \ m0));\n              _mm256_storeu_si256((__m256i *)(a + j1),\n            \
    \                      montgomery_sub_256(T0P2, T1P3, m2, m0));\n            \
    \  _mm256_storeu_si256((__m256i *)(a + j2),\n                                \
    \  montgomery_add_256(T0M2, T1M3, m2, m0));\n              _mm256_storeu_si256((__m256i\
    \ *)(a + j3),\n                                  montgomery_sub_256(T0M2, T1M3,\
    \ m2, m0));\n            }\n          } else {\n            ww = xx * xx, wx =\
    \ ww * xx;\n            const __m256i WW = _mm256_set1_epi32(ww.a);\n        \
    \    const __m256i WX = _mm256_set1_epi32(wx.a);\n            const __m256i XX\
    \ = _mm256_set1_epi32(xx.a);\n            int j0 = jh * v;\n            int j1\
    \ = j0 + v;\n            int j2 = j1 + v;\n            int j3 = j2 + v;\n    \
    \        int je = j1;\n            for (; j0 < je; j0 += 8, j1 += 8, j2 += 8,\
    \ j3 += 8) {\n              const __m256i T0 = _mm256_loadu_si256((__m256i *)(a\
    \ + j0));\n              const __m256i T1 = _mm256_loadu_si256((__m256i *)(a +\
    \ j1));\n              const __m256i T2 = _mm256_loadu_si256((__m256i *)(a + j2));\n\
    \              const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));\n \
    \             const __m256i MT1 = montgomery_mul_256(T1, XX, r, m1);\n       \
    \       const __m256i MT2 = montgomery_mul_256(T2, WW, r, m1);\n             \
    \ const __m256i MT3 = montgomery_mul_256(T3, WX, r, m1);\n              const\
    \ __m256i T0P2 = montgomery_add_256(T0, MT2, m2, m0);\n              const __m256i\
    \ T1P3 = montgomery_add_256(MT1, MT3, m2, m0);\n              const __m256i T0M2\
    \ = montgomery_sub_256(T0, MT2, m2, m0);\n              const __m256i T1M3 = montgomery_mul_256(\n\
    \                  montgomery_sub_256(MT1, MT3, m2, m0), Imag, r, m1);\n     \
    \         _mm256_storeu_si256((__m256i *)(a + j0),\n                         \
    \         montgomery_add_256(T0P2, T1P3, m2, m0));\n              _mm256_storeu_si256((__m256i\
    \ *)(a + j1),\n                                  montgomery_sub_256(T0P2, T1P3,\
    \ m2, m0));\n              _mm256_storeu_si256((__m256i *)(a + j2),\n        \
    \                          montgomery_add_256(T0M2, T1M3, m2, m0));\n        \
    \      _mm256_storeu_si256((__m256i *)(a + j3),\n                            \
    \      montgomery_sub_256(T0M2, T1M3, m2, m0));\n            }\n          }\n\
    \          xx *= dw[__builtin_ctz((jh += 4))];\n        }\n      }\n      u <<=\
    \ 2;\n      v >>= 2;\n    }\n  }\n\n  __attribute__((target(\"avx2\"))) void intt(mint\
    \ *a, int n,\n                                            int normalize = true)\
    \ {\n    int k = n ? __builtin_ctz(n) : 0;\n    if (k == 0) return;\n    if (k\
    \ == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0]\
    \ + a1;\n      if (normalize) {\n        a[0] *= mint(2).inverse();\n        a[1]\
    \ *= mint(2).inverse();\n      }\n      return;\n    }\n    int u = 1 << (k -\
    \ 2);\n    int v = 1;\n    mint one = mint(1);\n    mint imag = dy[1];\n    while\
    \ (u) {\n      if (v == 1) {\n        mint ww = one, xx = one, yy = one;\n   \
    \     u <<= 2;\n        for (int jh = 0; jh < u;) {\n          ww = xx * xx, yy\
    \ = xx * imag;\n          mint t0 = a[jh + 0], t1 = a[jh + 1];\n          mint\
    \ t2 = a[jh + 2], t3 = a[jh + 3];\n          mint t0p1 = t0 + t1, t2p3 = t2 +\
    \ t3;\n          mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\n        \
    \  a[jh + 0] = t0p1 + t2p3, a[jh + 2] = (t0p1 - t2p3) * ww;\n          a[jh +\
    \ 1] = t0m1 + t2m3, a[jh + 3] = (t0m1 - t2m3) * ww;\n          xx *= dy[__builtin_ctz(jh\
    \ += 4)];\n        }\n      } else if (v == 4) {\n        const __m128i m0 = _mm_set1_epi32(0);\n\
    \        const __m128i m1 = _mm_set1_epi32(mod);\n        const __m128i m2 = _mm_set1_epi32(mod\
    \ + mod);\n        const __m128i r = _mm_set1_epi32(mint::r);\n        const __m128i\
    \ Imag = _mm_set1_epi32(imag.a);\n        mint ww = one, xx = one, yy = one;\n\
    \        u <<= 2;\n        for (int jh = 0; jh < u;) {\n          if (jh == 0)\
    \ {\n            int j0 = 0;\n            int j1 = v;\n            int j2 = v\
    \ + v;\n            int j3 = j2 + v;\n            for (; j0 < v; j0 += 4, j1 +=\
    \ 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i T0P1 = montgomery_add_128(T0, T1, m2, m0);\n        \
    \      const __m128i T2P3 = montgomery_add_128(T2, T3, m2, m0);\n            \
    \  const __m128i T0M1 = montgomery_sub_128(T0, T1, m2, m0);\n              const\
    \ __m128i T2M3 = montgomery_mul_128(\n                  montgomery_sub_128(T2,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P1, T2P3, m2, m0));\n   \
    \           _mm_storeu_si128((__m128i *)(a + j2),\n                          \
    \     montgomery_sub_128(T0P1, T2P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_add_128(T0M1, T2M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M1, T2M3, m2, m0));\n            }\n   \
    \       } else {\n            ww = xx * xx, yy = xx * imag;\n            const\
    \ __m128i WW = _mm_set1_epi32(ww.a);\n            const __m128i XX = _mm_set1_epi32(xx.a);\n\
    \            const __m128i YY = _mm_set1_epi32(yy.a);\n            int j0 = jh\
    \ * v;\n            int j1 = j0 + v;\n            int j2 = j1 + v;\n         \
    \   int j3 = j2 + v;\n            int je = j1;\n            for (; j0 < je; j0\
    \ += 4, j1 += 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i T0P1 = montgomery_add_128(T0, T1, m2, m0);\n        \
    \      const __m128i T2P3 = montgomery_add_128(T2, T3, m2, m0);\n            \
    \  const __m128i T0M1 = montgomery_mul_128(\n                  montgomery_sub_128(T0,\
    \ T1, m2, m0), XX, r, m1);\n              __m128i T2M3 = montgomery_mul_128(\n\
    \                  montgomery_sub_128(T2, T3, m2, m0), YY, r, m1);\n         \
    \     _mm_storeu_si128((__m128i *)(a + j0),\n                               montgomery_add_128(T0P1,\
    \ T2P3, m2, m0));\n              _mm_storeu_si128(\n                  (__m128i\
    \ *)(a + j2),\n                  montgomery_mul_128(montgomery_sub_128(T0P1, T2P3,\
    \ m2, m0), WW,\n                                     r, m1));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_add_128(T0M1, T2M3, m2,\
    \ m0));\n              _mm_storeu_si128(\n                  (__m128i *)(a + j3),\n\
    \                  montgomery_mul_128(montgomery_sub_128(T0M1, T2M3, m2, m0),\
    \ WW,\n                                     r, m1));\n            }\n        \
    \  }\n          xx *= dy[__builtin_ctz(jh += 4)];\n        }\n      } else {\n\
    \        const __m256i m0 = _mm256_set1_epi32(0);\n        const __m256i m1 =\
    \ _mm256_set1_epi32(mod);\n        const __m256i m2 = _mm256_set1_epi32(mod +\
    \ mod);\n        const __m256i r = _mm256_set1_epi32(mint::r);\n        const\
    \ __m256i Imag = _mm256_set1_epi32(imag.a);\n        mint ww = one, xx = one,\
    \ yy = one;\n        u <<= 2;\n        for (int jh = 0; jh < u;) {\n         \
    \ if (jh == 0) {\n            int j0 = 0;\n            int j1 = v;\n         \
    \   int j2 = v + v;\n            int j3 = j2 + v;\n            for (; j0 < v;\
    \ j0 += 8, j1 += 8, j2 += 8, j3 += 8) {\n              const __m256i T0 = _mm256_loadu_si256((__m256i\
    \ *)(a + j0));\n              const __m256i T1 = _mm256_loadu_si256((__m256i *)(a\
    \ + j1));\n              const __m256i T2 = _mm256_loadu_si256((__m256i *)(a +\
    \ j2));\n              const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));\n\
    \              const __m256i T0P1 = montgomery_add_256(T0, T1, m2, m0);\n    \
    \          const __m256i T2P3 = montgomery_add_256(T2, T3, m2, m0);\n        \
    \      const __m256i T0M1 = montgomery_sub_256(T0, T1, m2, m0);\n            \
    \  const __m256i T2M3 = montgomery_mul_256(\n                  montgomery_sub_256(T2,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm256_storeu_si256((__m256i *)(a\
    \ + j0),\n                                  montgomery_add_256(T0P1, T2P3, m2,\
    \ m0));\n              _mm256_storeu_si256((__m256i *)(a + j2),\n            \
    \                      montgomery_sub_256(T0P1, T2P3, m2, m0));\n            \
    \  _mm256_storeu_si256((__m256i *)(a + j1),\n                                \
    \  montgomery_add_256(T0M1, T2M3, m2, m0));\n              _mm256_storeu_si256((__m256i\
    \ *)(a + j3),\n                                  montgomery_sub_256(T0M1, T2M3,\
    \ m2, m0));\n            }\n          } else {\n            ww = xx * xx, yy =\
    \ xx * imag;\n            const __m256i WW = _mm256_set1_epi32(ww.a);\n      \
    \      const __m256i XX = _mm256_set1_epi32(xx.a);\n            const __m256i\
    \ YY = _mm256_set1_epi32(yy.a);\n            int j0 = jh * v;\n            int\
    \ j1 = j0 + v;\n            int j2 = j1 + v;\n            int j3 = j2 + v;\n \
    \           int je = j1;\n            for (; j0 < je; j0 += 8, j1 += 8, j2 +=\
    \ 8, j3 += 8) {\n              const __m256i T0 = _mm256_loadu_si256((__m256i\
    \ *)(a + j0));\n              const __m256i T1 = _mm256_loadu_si256((__m256i *)(a\
    \ + j1));\n              const __m256i T2 = _mm256_loadu_si256((__m256i *)(a +\
    \ j2));\n              const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));\n\
    \              const __m256i T0P1 = montgomery_add_256(T0, T1, m2, m0);\n    \
    \          const __m256i T2P3 = montgomery_add_256(T2, T3, m2, m0);\n        \
    \      const __m256i T0M1 = montgomery_mul_256(\n                  montgomery_sub_256(T0,\
    \ T1, m2, m0), XX, r, m1);\n              const __m256i T2M3 = montgomery_mul_256(\n\
    \                  montgomery_sub_256(T2, T3, m2, m0), YY, r, m1);\n         \
    \     _mm256_storeu_si256((__m256i *)(a + j0),\n                             \
    \     montgomery_add_256(T0P1, T2P3, m2, m0));\n              _mm256_storeu_si256(\n\
    \                  (__m256i *)(a + j2),\n                  montgomery_mul_256(montgomery_sub_256(T0P1,\
    \ T2P3, m2, m0), WW,\n                                     r, m1));\n        \
    \      _mm256_storeu_si256((__m256i *)(a + j1),\n                            \
    \      montgomery_add_256(T0M1, T2M3, m2, m0));\n              _mm256_storeu_si256(\n\
    \                  (__m256i *)(a + j3),\n                  montgomery_mul_256(montgomery_sub_256(T0M1,\
    \ T2M3, m2, m0), WW,\n                                     r, m1));\n        \
    \    }\n          }\n          xx *= dy[__builtin_ctz(jh += 4)];\n        }\n\
    \      }\n      u >>= 4;\n      v <<= 2;\n    }\n    if (k & 1) {\n      v = 1\
    \ << (k - 1);\n      if (v < 8) {\n        for (int j = 0; j < v; ++j) {\n   \
    \       mint ajv = a[j] - a[j + v];\n          a[j] += a[j + v];\n          a[j\
    \ + v] = ajv;\n        }\n      } else {\n        const __m256i m0 = _mm256_set1_epi32(0);\n\
    \        const __m256i m2 = _mm256_set1_epi32(mod + mod);\n        int j0 = 0;\n\
    \        int j1 = v;\n        for (; j0 < v; j0 += 8, j1 += 8) {\n          const\
    \ __m256i T0 = _mm256_loadu_si256((__m256i *)(a + j0));\n          const __m256i\
    \ T1 = _mm256_loadu_si256((__m256i *)(a + j1));\n          __m256i naj = montgomery_add_256(T0,\
    \ T1, m2, m0);\n          __m256i najv = montgomery_sub_256(T0, T1, m2, m0);\n\
    \          _mm256_storeu_si256((__m256i *)(a + j0), naj);\n          _mm256_storeu_si256((__m256i\
    \ *)(a + j1), najv);\n        }\n      }\n    }\n    if (normalize) {\n      mint\
    \ invn = mint(n).inverse();\n      for (int i = 0; i < n; i++) a[i] *= invn;\n\
    \    }\n  }\n\n  __attribute__((target(\"avx2\"))) void inplace_multiply(\n  \
    \    int l1, int l2, int zero_padding = true) {\n    int l = l1 + l2 - 1;\n  \
    \  int M = 4;\n    while (M < l) M <<= 1;\n    if (zero_padding) {\n      for\
    \ (int i = l1; i < M; i++) buf1_[i] = 0;\n      for (int i = l2; i < M; i++) buf2_[i]\
    \ = 0;\n    }\n    const __m256i m0 = _mm256_set1_epi32(0);\n    const __m256i\
    \ m1 = _mm256_set1_epi32(mod);\n    const __m256i r = _mm256_set1_epi32(mint::r);\n\
    \    const __m256i N2 = _mm256_set1_epi32(mint::n2);\n    for (int i = 0; i <\
    \ l1; i += 8) {\n      __m256i a = _mm256_loadu_si256((__m256i *)(buf1_ + i));\n\
    \      __m256i b = montgomery_mul_256(a, N2, r, m1);\n      _mm256_storeu_si256((__m256i\
    \ *)(buf1_ + i), b);\n    }\n    for (int i = 0; i < l2; i += 8) {\n      __m256i\
    \ a = _mm256_loadu_si256((__m256i *)(buf2_ + i));\n      __m256i b = montgomery_mul_256(a,\
    \ N2, r, m1);\n      _mm256_storeu_si256((__m256i *)(buf2_ + i), b);\n    }\n\
    \    ntt(buf1, M);\n    ntt(buf2, M);\n    for (int i = 0; i < M; i += 8) {\n\
    \      __m256i a = _mm256_loadu_si256((__m256i *)(buf1_ + i));\n      __m256i\
    \ b = _mm256_loadu_si256((__m256i *)(buf2_ + i));\n      __m256i c = montgomery_mul_256(a,\
    \ b, r, m1);\n      _mm256_storeu_si256((__m256i *)(buf1_ + i), c);\n    }\n \
    \   intt(buf1, M, false);\n    const __m256i INVM = _mm256_set1_epi32((mint(M).inverse()).a);\n\
    \    for (int i = 0; i < l; i += 8) {\n      __m256i a = _mm256_loadu_si256((__m256i\
    \ *)(buf1_ + i));\n      __m256i b = montgomery_mul_256(a, INVM, r, m1);\n   \
    \   __m256i c = my256_mulhi_epu32(my256_mullo_epu32(b, r), m1);\n      __m256i\
    \ d = _mm256_and_si256(_mm256_cmpgt_epi32(c, m0), m1);\n      __m256i e = _mm256_sub_epi32(d,\
    \ c);\n      _mm256_storeu_si256((__m256i *)(buf1_ + i), e);\n    }\n  }\n\n \
    \ void ntt(vector<mint> &a) {\n    int M = (int)a.size();\n    for (int i = 0;\
    \ i < M; i++) buf1[i].a = a[i].a;\n    ntt(buf1, M);\n    for (int i = 0; i <\
    \ M; i++) a[i].a = buf1[i].a;\n  }\n\n  void intt(vector<mint> &a) {\n    int\
    \ M = (int)a.size();\n    for (int i = 0; i < M; i++) buf1[i].a = a[i].a;\n  \
    \  intt(buf1, M, true);\n    for (int i = 0; i < M; i++) a[i].a = buf1[i].a;\n\
    \  }\n\n  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b)\
    \ {\n    if (a.size() == 0 && b.size() == 0) return vector<mint>{};\n    int l\
    \ = a.size() + b.size() - 1;\n    if (min<int>(a.size(), b.size()) <= 40) {\n\
    \      vector<mint> s(l);\n      for (int i = 0; i < (int)a.size(); ++i)\n   \
    \     for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n     \
    \ return s;\n    }\n    int M = 4;\n    while (M < l) M <<= 1;\n    for (int i\
    \ = 0; i < (int)a.size(); ++i) buf1[i].a = a[i].a;\n    for (int i = (int)a.size();\
    \ i < M; ++i) buf1[i].a = 0;\n    for (int i = 0; i < (int)b.size(); ++i) buf2[i].a\
    \ = b[i].a;\n    for (int i = (int)b.size(); i < M; ++i) buf2[i].a = 0;\n    ntt(buf1,\
    \ M);\n    ntt(buf2, M);\n    for (int i = 0; i < M; ++i)\n      buf1[i].a = mint::reduce(uint64_t(buf1[i].a)\
    \ * buf2[i].a);\n    intt(buf1, M, false);\n    vector<mint> s(l);\n    mint invm\
    \ = mint(M).inverse();\n    for (int i = 0; i < l; ++i) s[i] = buf1[i] * invm;\n\
    \    return s;\n  }\n\n  void ntt_doubling(vector<mint> &a) {\n    int M = (int)a.size();\n\
    \    for (int i = 0; i < M; i++) buf1[i].a = a[i].a;\n    intt(buf1, M);\n   \
    \ mint r = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\n    for\
    \ (int i = 0; i < M; i++) buf1[i] *= r, r *= zeta;\n    ntt(buf1, M);\n    a.resize(2\
    \ * M);\n    for (int i = 0; i < M; i++) a[M + i].a = buf1[i].a;\n  }\n};\n#line\
    \ 3 \"fps/formal-power-series.hpp\"\nusing namespace std;\n\ntemplate <typename\
    \ mint>\nstruct FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n\
    \  using FPS = FormalPowerSeries;\n\n  FPS &operator+=(const FPS &r) {\n    if\
    \ (r.size() > this->size()) this->resize(r.size());\n    for (int i = 0; i < (int)r.size();\
    \ i++) (*this)[i] += r[i];\n    return *this;\n  }\n\n  FPS &operator+=(const\
    \ mint &r) {\n    if (this->empty()) this->resize(1);\n    (*this)[0] += r;\n\
    \    return *this;\n  }\n\n  FPS &operator-=(const FPS &r) {\n    if (r.size()\
    \ > this->size()) this->resize(r.size());\n    for (int i = 0; i < (int)r.size();\
    \ i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n  FPS &operator-=(const\
    \ mint &r) {\n    if (this->empty()) this->resize(1);\n    (*this)[0] -= r;\n\
    \    return *this;\n  }\n\n  FPS &operator*=(const mint &v) {\n    for (int k\
    \ = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n    return *this;\n  }\n\n\
    \  FPS &operator/=(const FPS &r) {\n    if (this->size() < r.size()) {\n     \
    \ this->clear();\n      return *this;\n    }\n    int n = this->size() - r.size()\
    \ + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this), g(r);\n      g.shrink();\n\
    \      mint coeff = g.back().inverse();\n      for (auto &x : g) x *= coeff;\n\
    \      int deg = (int)f.size() - (int)g.size() + 1;\n      int gs = g.size();\n\
    \      FPS quo(deg);\n      for (int i = deg - 1; i >= 0; i--) {\n        quo[i]\
    \ = f[i + gs - 1];\n        for (int j = 0; j < gs; j++) f[i + j] -= quo[i] *\
    \ g[j];\n      }\n      *this = quo * coeff;\n      this->resize(n, mint(0));\n\
    \      return *this;\n    }\n    return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \  }\n\n  FPS &operator%=(const FPS &r) {\n    *this -= *this / r * r;\n    shrink();\n\
    \    return *this;\n  }\n\n  FPS operator+(const FPS &r) const { return FPS(*this)\
    \ += r; }\n  FPS operator+(const mint &v) const { return FPS(*this) += v; }\n\
    \  FPS operator-(const FPS &r) const { return FPS(*this) -= r; }\n  FPS operator-(const\
    \ mint &v) const { return FPS(*this) -= v; }\n  FPS operator*(const FPS &r) const\
    \ { return FPS(*this) *= r; }\n  FPS operator*(const mint &v) const { return FPS(*this)\
    \ *= v; }\n  FPS operator/(const FPS &r) const { return FPS(*this) /= r; }\n \
    \ FPS operator%(const FPS &r) const { return FPS(*this) %= r; }\n  FPS operator-()\
    \ const {\n    FPS ret(this->size());\n    for (int i = 0; i < (int)this->size();\
    \ i++) ret[i] = -(*this)[i];\n    return ret;\n  }\n\n  void shrink() {\n    while\
    \ (this->size() && this->back() == mint(0)) this->pop_back();\n  }\n\n  FPS rev()\
    \ const {\n    FPS ret(*this);\n    reverse(begin(ret), end(ret));\n    return\
    \ ret;\n  }\n\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(), r.size()));\n\
    \    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n \
    \   return ret;\n  }\n\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
    \ begin(*this) + min((int)this->size(), sz));\n  }\n\n  FPS operator>>(int sz)\
    \ const {\n    if ((int)this->size() <= sz) return {};\n    FPS ret(*this);\n\
    \    ret.erase(ret.begin(), ret.begin() + sz);\n    return ret;\n  }\n\n  FPS\
    \ operator<<(int sz) const {\n    FPS ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, mint(0));\n    return ret;\n  }\n\n  FPS diff() const {\n    const int n\
    \ = (int)this->size();\n    FPS ret(max(0, n - 1));\n    mint one(1), coeff(1);\n\
    \    for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n \
    \     coeff += one;\n    }\n    return ret;\n  }\n\n  FPS integral() const {\n\
    \    const int n = (int)this->size();\n    FPS ret(n + 1);\n    ret[0] = mint(0);\n\
    \    if (n > 0) ret[1] = mint(1);\n    auto mod = mint::get_mod();\n    for (int\
    \ i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);\n    for (int i =\
    \ 0; i < n; i++) ret[i + 1] *= (*this)[i];\n    return ret;\n  }\n\n  mint eval(mint\
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto &v : *this) r += w * v, w\
    \ *= x;\n    return r;\n  }\n\n  FPS log(int deg = -1) const {\n    assert((*this)[0]\
    \ == mint(1));\n    if (deg == -1) deg = (int)this->size();\n    return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n  }\n\n  FPS pow(int64_t k, int\
    \ deg = -1) const {\n    const int n = (int)this->size();\n    if (deg == -1)\
    \ deg = n;\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i] != mint(0))\
    \ {\n        if (i * k > deg) return FPS(deg, mint(0));\n        mint rev = mint(1)\
    \ / (*this)[i];\n        FPS ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n\
    \        ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg)\
    \ ret.resize(deg, mint(0));\n        return ret;\n      }\n    }\n    return FPS(deg,\
    \ mint(0));\n  }\n\n  static void *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const\
    \ FPS &r);\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int\
    \ ntt_pr();\n  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n\
    };\ntemplate <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\
    \n/**\n * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n */\n#line\
    \ 7 \"fps/ntt-friendly-fps.hpp\"\n\ntemplate <typename mint>\nvoid FormalPowerSeries<mint>::set_fft()\
    \ {\n  if (!ntt_ptr) ntt_ptr = new NTT<mint>;\n}\n\ntemplate <typename mint>\n\
    FormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(\n    const FormalPowerSeries<mint>&\
    \ r) {\n  if (this->empty() || r.empty()) {\n    this->clear();\n    return *this;\n\
    \  }\n  set_fft();\n  auto ret = static_cast<NTT<mint>*>(ntt_ptr)->multiply(*this,\
    \ r);\n  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());\n}\n\n\
    template <typename mint>\nvoid FormalPowerSeries<mint>::ntt() {\n  set_fft();\n\
    \  static_cast<NTT<mint>*>(ntt_ptr)->ntt(*this);\n}\n\ntemplate <typename mint>\n\
    void FormalPowerSeries<mint>::intt() {\n  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->intt(*this);\n\
    }\n\ntemplate <typename mint>\nvoid FormalPowerSeries<mint>::ntt_doubling() {\n\
    \  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->ntt_doubling(*this);\n}\n\n\
    template <typename mint>\nint FormalPowerSeries<mint>::ntt_pr() {\n  set_fft();\n\
    \  return static_cast<NTT<mint>*>(ntt_ptr)->pr;\n}\n\ntemplate <typename mint>\n\
    FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {\n  assert((*this)[0]\
    \ != mint(0));\n  if (deg == -1) deg = (int)this->size();\n  FormalPowerSeries<mint>\
    \ res(deg);\n  res[0] = {mint(1) / (*this)[0]};\n  for (int d = 1; d < deg; d\
    \ <<= 1) {\n    FormalPowerSeries<mint> f(2 * d), g(2 * d);\n    for (int j =\
    \ 0; j < min((int)this->size(), 2 * d); j++) f[j] = (*this)[j];\n    for (int\
    \ j = 0; j < d; j++) g[j] = res[j];\n    f.ntt();\n    g.ntt();\n    for (int\
    \ j = 0; j < 2 * d; j++) f[j] *= g[j];\n    f.intt();\n    for (int j = 0; j <\
    \ d; j++) f[j] = 0;\n    f.ntt();\n    for (int j = 0; j < 2 * d; j++) f[j] *=\
    \ g[j];\n    f.intt();\n    for (int j = d; j < min(2 * d, deg); j++) res[j] =\
    \ -f[j];\n  }\n  return res.pre(deg);\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ FormalPowerSeries<mint>::exp(int deg) const {\n  using fps = FormalPowerSeries<mint>;\n\
    \  assert((*this).size() == 0 || (*this)[0] == mint(0));\n  if (deg == -1) deg\
    \ = this->size();\n\n  fps inv;\n  inv.reserve(deg + 1);\n  inv.push_back(mint(0));\n\
    \  inv.push_back(mint(1));\n\n  auto inplace_integral = [&](fps& F) -> void {\n\
    \    const int n = (int)F.size();\n    auto mod = mint::get_mod();\n    while\
    \ ((int)inv.size() <= n) {\n      int i = inv.size();\n      inv.push_back((-inv[mod\
    \ % i]) * (mod / i));\n    }\n    F.insert(begin(F), mint(0));\n    for (int i\
    \ = 1; i <= n; i++) F[i] *= inv[i];\n  };\n\n  auto inplace_diff = [](fps& F)\
    \ -> void {\n    if (F.empty()) return;\n    F.erase(begin(F));\n    mint coeff\
    \ = 1, one = 1;\n    for (int i = 0; i < (int)F.size(); i++) {\n      F[i] *=\
    \ coeff;\n      coeff += one;\n    }\n  };\n\n  fps b{1, 1 < (int)this->size()\
    \ ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};\n  for (int m = 2; m < deg; m *= 2) {\n\
    \    auto y = b;\n    y.resize(2 * m);\n    y.ntt();\n    z1 = z2;\n    fps z(m);\n\
    \    for (int i = 0; i < m; ++i) z[i] = y[i] * z1[i];\n    z.intt();\n    fill(begin(z),\
    \ begin(z) + m / 2, mint(0));\n    z.ntt();\n    for (int i = 0; i < m; ++i) z[i]\
    \ *= -z1[i];\n    z.intt();\n    c.insert(end(c), begin(z) + m / 2, end(z));\n\
    \    z2 = c;\n    z2.resize(2 * m);\n    z2.ntt();\n    fps x(begin(*this), begin(*this)\
    \ + min<int>(this->size(), m));\n    inplace_diff(x);\n    x.push_back(mint(0));\n\
    \    x.ntt();\n    for (int i = 0; i < m; ++i) x[i] *= y[i];\n    x.intt();\n\
    \    x -= b.diff();\n    x.resize(2 * m);\n    for (int i = 0; i < m - 1; ++i)\
    \ x[m + i] = x[i], x[i] = mint(0);\n    x.ntt();\n    for (int i = 0; i < 2 *\
    \ m; ++i) x[i] *= z2[i];\n    x.intt();\n    x.pop_back();\n    inplace_integral(x);\n\
    \    for (int i = m; i < min<int>(this->size(), 2 * m); ++i) x[i] += (*this)[i];\n\
    \    fill(begin(x), begin(x) + m, mint(0));\n    x.ntt();\n    for (int i = 0;\
    \ i < 2 * m; ++i) x[i] *= y[i];\n    x.intt();\n    b.insert(end(b), begin(x)\
    \ + m, end(x));\n  }\n  return fps{begin(b), begin(b) + deg};\n}\n\n/**\n * @brief\
    \ NTT mod\u7528FPS\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/ntt-friendly-fps.md\n\
    \ */\n#line 3 \"fps/polynomial-gcd.hpp\"\nusing namespace std;\n\n#line 6 \"fps/polynomial-gcd.hpp\"\
    \n\nnamespace poly_gcd {\n\ntemplate <typename mint>\nusing FPS = FormalPowerSeries<mint>;\n\
    template <typename mint>\nusing Arr = pair<FPS<mint>, FPS<mint>>;\n\ntemplate\
    \ <typename mint>\nstruct Mat {\n  using fps = FPS<mint>;\n  fps a00, a01, a10,\
    \ a11;\n\n  Mat() = default;\n  Mat(const fps& a00_, const fps& a01_, const fps&\
    \ a10_, const fps& a11_)\n      : a00(a00_), a01(a01_), a10(a10_), a11(a11_) {}\n\
    \n  Mat& operator*=(const Mat& r) {\n    fps A00 = a00 * r.a00 + a01 * r.a10;\n\
    \    fps A01 = a00 * r.a01 + a01 * r.a11;\n    fps A10 = a10 * r.a00 + a11 * r.a10;\n\
    \    fps A11 = a10 * r.a01 + a11 * r.a11;\n    A00.shrink();\n    A01.shrink();\n\
    \    A10.shrink();\n    A11.shrink();\n    swap(A00, a00);\n    swap(A01, a01);\n\
    \    swap(A10, a10);\n    swap(A11, a11);\n    return *this;\n  }\n\n  static\
    \ Mat I() { return Mat(fps{mint(1)}, fps(), fps(), fps{mint(1)}); }\n\n  Mat operator*(const\
    \ Mat& r) const { return Mat(*this) *= r; }\n};\n\ntemplate <typename mint>\n\
    Arr<mint> operator*(const Mat<mint>& m, const Arr<mint>& a) {\n  using fps = FPS<mint>;\n\
    \  fps b0 = m.a00 * a.first + m.a01 * a.second;\n  fps b1 = m.a10 * a.first +\
    \ m.a11 * a.second;\n  b0.shrink();\n  b1.shrink();\n  return {b0, b1};\n};\n\n\
    template <typename mint>\nvoid InnerNaiveGCD(Mat<mint>& m, Arr<mint>& p) {\n \
    \ using fps = FPS<mint>;\n  fps quo = p.first / p.second;\n  fps rem = p.first\
    \ - p.second * quo;\n  fps b10 = m.a00 - m.a10 * quo;\n  fps b11 = m.a01 - m.a11\
    \ * quo;\n  rem.shrink();\n  b10.shrink();\n  b11.shrink();\n  swap(b10, m.a10);\n\
    \  swap(b11, m.a11);\n  swap(b10, m.a00);\n  swap(b11, m.a01);\n  p = {p.second,\
    \ rem};\n}\n\ntemplate <typename mint>\nMat<mint> InnerHalfGCD(Arr<mint> p) {\n\
    \  int n = p.first.size(), m = p.second.size();\n  int k = (n + 1) / 2;\n  if\
    \ (m <= k) return Mat<mint>::I();\n  Mat<mint> m1 = InnerHalfGCD(make_pair(p.first\
    \ >> k, p.second >> k));\n  p = m1 * p;\n  if ((int)p.second.size() <= k) return\
    \ m1;\n  InnerNaiveGCD(m1, p);\n  if ((int)p.second.size() <= k) return m1;\n\
    \  int l = (int)p.first.size() - 1;\n  int j = 2 * k - l;\n  p.first = p.first\
    \ >> j;\n  p.second = p.second >> j;\n  return InnerHalfGCD(p) * m1;\n}\n\ntemplate\
    \ <typename mint>\nMat<mint> InnerPolyGCD(const FPS<mint>& a, const FPS<mint>&\
    \ b) {\n  Arr<mint> p{a, b};\n  p.first.shrink();\n  p.second.shrink();\n  int\
    \ n = p.first.size(), m = p.second.size();\n  if (n < m) {\n    Mat<mint> mat\
    \ = InnerPolyGCD(p.second, p.first);\n    swap(mat.a00, mat.a01);\n    swap(mat.a10,\
    \ mat.a11);\n    return mat;\n  }\n\n  Mat<mint> res = Mat<mint>::I();\n  while\
    \ (1) {\n    Mat<mint> m1 = InnerHalfGCD(p);\n    p = m1 * p;\n    if (p.second.empty())\
    \ return m1 * res;\n    InnerNaiveGCD(m1, p);\n    if (p.second.empty()) return\
    \ m1 * res;\n    res = m1 * res;\n  }\n}\n\ntemplate <typename mint>\nFPS<mint>\
    \ PolyGCD(const FPS<mint>& a, const FPS<mint>& b) {\n  Arr<mint> p(a, b);\n  Mat<mint>\
    \ m = InnerPolyGCD(a, b);\n  p = m * p;\n  if (!p.first.empty()) {\n    mint coeff\
    \ = p.first.back().inverse();\n    for (auto& x : p.first) x *= coeff;\n  }\n\
    \  return p.first;\n}\n\ntemplate <typename mint>\npair<int, FPS<mint>> PolyInv(const\
    \ FPS<mint>& f, const FPS<mint>& g) {\n  using fps = FPS<mint>;\n  pair<fps, fps>\
    \ p(f, g);\n  Mat<mint> m = InnerPolyGCD(f, g);\n  fps gcd_ = (m * p).first;\n\
    \  if (gcd_.size() != 1) return {false, fps()};\n  pair<fps, fps> x(fps{mint(1)},\
    \ g);\n  return {true, ((m * x).first % g) * gcd_[0].inverse()};\n}\n\n}  // namespace\
    \ poly_gcd\nusing poly_gcd::PolyGCD;\nusing poly_gcd::PolyInv;\n\n/**\n * @brief\
    \ \u591A\u9805\u5F0FGCD\n * @docs docs/fps/polynomial-gcd.md\n */\n#line 3 \"\
    modint/montgomery-modint.hpp\"\nusing namespace std;\n\ntemplate <uint32_t mod>\n\
    struct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n  using i32\
    \ = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr\
    \ u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2\
    \ - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32 r = get_r();\n\
    \  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r * mod == 1, \"\
    invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"invalid, mod >=\
    \ 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2 == 0\");\n\n\
    \  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
    \ int64_t &b)\n      : a(reduce(u64(b % mod + mod) * n2)){};\n\n  static constexpr\
    \ u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * u32(-r)) * mod) >>\
    \ 32;\n  }\n\n  constexpr mint &operator+=(const mint &b) {\n    if (i32(a +=\
    \ b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  constexpr mint &operator*=(const mint &b) {\n    a =\
    \ reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr mint &operator/=(const\
    \ mint &b) {\n    *this *= b.inverse();\n    return *this;\n  }\n\n  constexpr\
    \ mint operator+(const mint &b) const { return mint(*this) += b; }\n  constexpr\
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  constexpr\
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  constexpr\
    \ mint operator/(const mint &b) const { return mint(*this) /= b; }\n  constexpr\
    \ bool operator==(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 13 \"verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp\"\
    \n\nint main() {\n  using mint = LazyMontgomeryModInt<998244353>;\n  using fps\
    \ = FormalPowerSeries<mint>;\n  int N, M;\n  rd(N, M);\n  fps f(N), g(M);\n  for\
    \ (int i = 0; i < N; i++) {\n    int n;\n    rd(n);\n    f[i] = n;\n  }\n  for\
    \ (int i = 0; i < M; i++) {\n    int n;\n    rd(n);\n    g[i] = n;\n  }\n\n  auto\
    \ [flg, h] = PolyInv(f, g);\n  if (flg) {\n    wtn(h.size());\n    if (h.size())\
    \ {\n      for (int i = 0; i < (int)h.size(); i++) {\n        if (i) wt(' ');\n\
    \        wt(h[i].get());\n      }\n      wt('\\n');\n    }\n  } else {\n    wtn(-1);\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_polynomials\"\n\n\
    #include <immintrin.h>\n//\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #include \"../../misc/fastio.hpp\"\n//\n#include \"../../fps/ntt-friendly-fps.hpp\"\
    \n#include \"../../fps/polynomial-gcd.hpp\"\n#include \"../../modint/montgomery-modint.hpp\"\
    \n\nint main() {\n  using mint = LazyMontgomeryModInt<998244353>;\n  using fps\
    \ = FormalPowerSeries<mint>;\n  int N, M;\n  rd(N, M);\n  fps f(N), g(M);\n  for\
    \ (int i = 0; i < N; i++) {\n    int n;\n    rd(n);\n    f[i] = n;\n  }\n  for\
    \ (int i = 0; i < M; i++) {\n    int n;\n    rd(n);\n    g[i] = n;\n  }\n\n  auto\
    \ [flg, h] = PolyInv(f, g);\n  if (flg) {\n    wtn(h.size());\n    if (h.size())\
    \ {\n      for (int i = 0; i < (int)h.size(); i++) {\n        if (i) wt(' ');\n\
    \        wt(h[i].get());\n      }\n      wt('\\n');\n    }\n  } else {\n    wtn(-1);\n\
    \  }\n}"
  dependsOn:
  - misc/fastio.hpp
  - fps/ntt-friendly-fps.hpp
  - ntt/ntt-avx2.hpp
  - modint/simd-montgomery.hpp
  - fps/formal-power-series.hpp
  - fps/polynomial-gcd.hpp
  - modint/montgomery-modint.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
  requiredBy: []
  timestamp: '2020-09-15 23:09:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
- /verify/verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp.html
title: verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
---