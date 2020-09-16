---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':question:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
    title: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/fps/fps-taylor-shift.md
    document_title: "\u5E73\u884C\u79FB\u52D5"
    links: []
  bundledCode: "#line 2 \"fps/formal-power-series.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint>\
    \ {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\n  FPS\
    \ &operator+=(const FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n\
    \    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n\n  FPS &operator+=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n\n  FPS &operator-=(const FPS &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n\
    \  FPS &operator-=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n\n  FPS &operator*=(const mint\
    \ &v) {\n    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n  \
    \  return *this;\n  }\n\n  FPS &operator/=(const FPS &r) {\n    if (this->size()\
    \ < r.size()) {\n      this->clear();\n      return *this;\n    }\n    int n =\
    \ this->size() - r.size() + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this),\
    \ g(r);\n      g.shrink();\n      mint coeff = g.back().inverse();\n      for\
    \ (auto &x : g) x *= coeff;\n      int deg = (int)f.size() - (int)g.size() + 1;\n\
    \      int gs = g.size();\n      FPS quo(deg);\n      for (int i = deg - 1; i\
    \ >= 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for (int j = 0; j < gs;\
    \ j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this = quo * coeff;\n     \
    \ this->resize(n, mint(0));\n      return *this;\n    }\n    return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n  }\n\n  FPS &operator%=(const FPS &r) {\n\
    \    *this -= *this / r * r;\n    shrink();\n    return *this;\n  }\n\n  FPS operator+(const\
    \ FPS &r) const { return FPS(*this) += r; }\n  FPS operator+(const mint &v) const\
    \ { return FPS(*this) += v; }\n  FPS operator-(const FPS &r) const { return FPS(*this)\
    \ -= r; }\n  FPS operator-(const mint &v) const { return FPS(*this) -= v; }\n\
    \  FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n  FPS operator*(const\
    \ mint &v) const { return FPS(*this) *= v; }\n  FPS operator/(const FPS &r) const\
    \ { return FPS(*this) /= r; }\n  FPS operator%(const FPS &r) const { return FPS(*this)\
    \ %= r; }\n  FPS operator-() const {\n    FPS ret(this->size());\n    for (int\
    \ i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n\
    \  }\n\n  void shrink() {\n    while (this->size() && this->back() == mint(0))\
    \ this->pop_back();\n  }\n\n  FPS rev() const {\n    FPS ret(*this);\n    reverse(begin(ret),\
    \ end(ret));\n    return ret;\n  }\n\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(),\
    \ r.size()));\n    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n    return ret;\n  }\n\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
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
    \ 3 \"modulo/binomial.hpp\"\nusing namespace std;\n\ntemplate <typename T>\nstruct\
    \ Binomial {\n  vector<T> fac_, finv_, inv_;\n  Binomial(int MAX) : fac_(MAX +\
    \ 10), finv_(MAX + 10), inv_(MAX + 10) {\n    MAX += 9;\n    fac_[0] = finv_[0]\
    \ = inv_[0] = 1;\n    for (int i = 1; i <= MAX; i++) fac_[i] = fac_[i - 1] * i;\n\
    \    finv_[MAX] = fac_[MAX].inverse();\n    for (int i = MAX - 1; i > 0; i--)\
    \ finv_[i] = finv_[i + 1] * (i + 1);\n    for (int i = 1; i <= MAX; i++) inv_[i]\
    \ = finv_[i] * fac_[i - 1];\n  }\n\n  inline T fac(int i) const { return fac_[i];\
    \ }\n  inline T finv(int i) const { return finv_[i]; }\n  inline T inv(int i)\
    \ const { return inv_[i]; }\n\n  T C(int n, int r) const {\n    if (n < r || r\
    \ < 0) return T(0);\n    return fac_[n] * finv_[n - r] * finv_[r];\n  }\n\n  T\
    \ C_naive(int n, int r) const {\n    if (n < r || r < 0) return T(0);\n    T ret\
    \ = 1;\n    for (T i = 1; i <= r; i += T(1)) {\n      ret *= n--;\n      ret *=\
    \ i.inverse();\n    }\n    return ret;\n  }\n\n  T P(int n, int r) const {\n \
    \   if (n < r || r < 0) return T(0);\n    return fac_[n] * finv_[n - r];\n  }\n\
    \n  T H(int n, int r) const {\n    if (n < 0 || r < 0) return (0);\n    return\
    \ r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 4 \"fps/taylor-shift.hpp\"\n\n\
    // calculate F(x + a)\ntemplate <typename mint>\nFormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint>\
    \ f, mint a,\n                                    Binomial<mint>& C) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  assert(C.fac_.size() >= f.size() + 1);\n \
    \ int N = f.size();\n  for (int i = 0; i < N; i++) f[i] *= C.fac(i);\n  reverse(begin(f),\
    \ end(f));\n  fps g(N, mint(1));\n  for (int i = 1; i < N; i++) g[i] = g[i - 1]\
    \ * a * C.inv(i);\n  f = (f * g).pre(N);\n  reverse(begin(f), end(f));\n  for\
    \ (int i = 0; i < N; i++) f[i] *= C.finv(i);\n  return f;\n}\n\n/**\n * @brief\
    \ \u5E73\u884C\u79FB\u52D5\n * @docs docs/fps/fps-taylor-shift.md\n */\n"
  code: "#pragma once\n#include \"./formal-power-series.hpp\"\n#include \"../modulo/binomial.hpp\"\
    \n\n// calculate F(x + a)\ntemplate <typename mint>\nFormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint>\
    \ f, mint a,\n                                    Binomial<mint>& C) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  assert(C.fac_.size() >= f.size() + 1);\n \
    \ int N = f.size();\n  for (int i = 0; i < N; i++) f[i] *= C.fac(i);\n  reverse(begin(f),\
    \ end(f));\n  fps g(N, mint(1));\n  for (int i = 1; i < N; i++) g[i] = g[i - 1]\
    \ * a * C.inv(i);\n  f = (f * g).pre(N);\n  reverse(begin(f), end(f));\n  for\
    \ (int i = 0; i < N; i++) f[i] *= C.finv(i);\n  return f;\n}\n\n/**\n * @brief\
    \ \u5E73\u884C\u79FB\u52D5\n * @docs docs/fps/fps-taylor-shift.md\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - modulo/binomial.hpp
  isVerificationFile: false
  path: fps/taylor-shift.hpp
  requiredBy: []
  timestamp: '2020-08-21 15:57:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
documentation_of: fps/taylor-shift.hpp
layout: document
redirect_from:
- /library/fps/taylor-shift.hpp
- /library/fps/taylor-shift.hpp.html
title: "\u5E73\u884C\u79FB\u52D5"
---
## fps-平行移動

$N$次の多項式$f(x)$に対して$g(x) = f(x+a)$を満たす$g(x)$を$\mathrm{O}(N \log N)$で計算するライブラリ。

#### 概要

$N$次の多項式$f(x)$に対して$g(x) = f(x+a)$となる$g(x)$を求める。これは、

$$f(x+a) = \sum_{n=0}^N f_n(x+a)^n$$

$$=\sum_{i=0}^Nx^i\sum_{n=i}^N(a^{n-i}f_n\ _nC_i)$$

$m=N-n,j=N-i$とおいて

$$=\sum_{j=0}^N\frac{x^j}{(N-j)!}\sum_{m=0}^j\frac{a^{j-m}}{(j-m)!}\left((N-m)!f_{N-m}\right)$$

と変形できるので畳み込みに帰着される。

#### 使い方

- `TaylorShift(f, a, C, deg)`: 多項式$f$について$f(x+a)$をdeg次の項まで求める。CにはBinomial構造体を渡す。