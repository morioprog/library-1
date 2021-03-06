#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../../template/template.hpp"
#include "../../tree/heavy-light-decomposition.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N);
  vvi g(N);
  rep(i,N){
    ini(n);
    g[i].resize(n);
    in(g[i]);
  }
  HeavyLightDecomposition<vvi> hld(g);
  ini(Q);
  rep(_,Q){
    ini(u,v);
    out(hld.lca(u,v));
  }
}