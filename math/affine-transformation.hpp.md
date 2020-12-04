---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u30A2\u30D5\u30A3\u30F3\u5909\u63DB"
    links: []
  bundledCode: "#line 2 \"math/affine-transformation.hpp\"\n\ntemplate <typename mint>\n\
    struct Affine {\n  mint a, b;\n  constexpr Affine() : a(1), b(0) {}\n  constexpr\
    \ Affine(mint _a, mint _b) : a(_a), b(_b) {}\n  mint operator()(mint x) { return\
    \ a * x + b; }\n  friend Affine operator*(const Affine& l, const Affine& r) {\n\
    \    return Affine(l.a * r.a, l.b * r.a + r.b);\n  }\n  bool operator==(const\
    \ Affine& r) const { return a == r.a && b == r.b; }\n  bool operator!=(const Affine&\
    \ r) const { return a != r.a || b != r.b; }\n  friend ostream& operator<<(ostream&\
    \ os, const Affine& r) {\n    os << \"( \" << r.a << \", \" << r.b << \" )\";\n\
    \    return os;\n  }\n};\n\n/**\n * @brief \u30A2\u30D5\u30A3\u30F3\u5909\u63DB\
    \n */\n"
  code: "#pragma once\n\ntemplate <typename mint>\nstruct Affine {\n  mint a, b;\n\
    \  constexpr Affine() : a(1), b(0) {}\n  constexpr Affine(mint _a, mint _b) :\
    \ a(_a), b(_b) {}\n  mint operator()(mint x) { return a * x + b; }\n  friend Affine\
    \ operator*(const Affine& l, const Affine& r) {\n    return Affine(l.a * r.a,\
    \ l.b * r.a + r.b);\n  }\n  bool operator==(const Affine& r) const { return a\
    \ == r.a && b == r.b; }\n  bool operator!=(const Affine& r) const { return a !=\
    \ r.a || b != r.b; }\n  friend ostream& operator<<(ostream& os, const Affine&\
    \ r) {\n    os << \"( \" << r.a << \", \" << r.b << \" )\";\n    return os;\n\
    \  }\n};\n\n/**\n * @brief \u30A2\u30D5\u30A3\u30F3\u5909\u63DB\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/affine-transformation.hpp
  requiredBy: []
  timestamp: '2020-12-03 23:28:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
documentation_of: math/affine-transformation.hpp
layout: document
redirect_from:
- /library/math/affine-transformation.hpp
- /library/math/affine-transformation.hpp.html
title: "\u30A2\u30D5\u30A3\u30F3\u5909\u63DB"
---