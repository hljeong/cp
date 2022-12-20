# log

## 11.4.22
- solving problems for dp training set
- solved
  - brackets: bracket sequence dp
  - bracketpairing: bracket sequence dp, cfg disambuation
  - piecesofparentheses: bracket sequence dp, tricky
  - reportcard: ez dp
  - potioncommotion: impl w edge case
  - gradingonacurve: binsearch

## 11.5.22
- doing [uchicago set](https://open.kattis.com/contests/saogxm)
- solved
  - fairdivision: greedy
  - minimumscalar: greedy
  - bank: greedy

## 11.9.22
- looking at robert's graph problems
- solved
  - treehouses: straight mst
  - curveknights: straight topsort
  - breakingbad: straight bipartite checking

## 11.10.22
- looking at robert's graph problems
- solved
  - emptyingbaltic: pq flood fill
- unsolved
  - treequivalence: tree isomorphism

## 11.12.22
- looking at robert's graph problems
- solved
  - dominoes2: trivial dfs
  - flowerytrails: dijkstra backtracking
  - onaveragetheyrepurple: ans = dist - 1, tricky!
  - customscontrols: greedy, tricky!

## 11.13.22
- looking at robert's graph problems
- then looking randomly at other practices
- then training #4
- solved
  - thekingofthenorth: min cut, 1 edge for each cell
  - tetration: trivial math, pow(n, 1 / n)
  - damsindistress: dfs

## 11.15.22
- solving training #4
- solved
  - invasion: dijkstra

## 11.16.22
- solving training #4
- finding mod math problsm for training #5
- solved
  - perica: sort + combinatorics
- unsolved
  - treequivalence

## 11.17.22
- talking to suhas
- unsolved
  - landscaping

## 11.19.22
- looking at jason's math problems
- solved
  - dvdscreensaver: reflection trick, crt
  - pseudoprime: check if prime, fast exp
  - threedigits: separately keep exponents for 2 and 5
  - hopscotch: combinatorics

## 11.20.22
- doing training #5
- solved
  - randomdigitalexponentiation: brute force from the back
- unsolved
  - leapfrog: brute force crt

## 11.24.22
- finishing up new dinic / forward star template
- solved
  - ridehailing: min path cover

## 11.26.22
- acpc 2022
- solved
  - undeadoralive: trivial
  - simplefactoring: check discriminant
  - ordinals: impl
  - contingencyplanning: trivial
  - supplyroutes: offline, reverse, dsu
  - trickyfactoring: ans = # factors of ac + ac is perfect sq

## 12.1.22
- robert couldnt solve this 2.4 problem
- solved
  - ada: impl

## 12.13.22
- wb training 1 (bapc prelim 2017)
- solved
  - ghostbusters2: mst w connectivity constraint
  - enviousexponents: flip latest possible 0 bit
  - diastrousdoubling: keep track up to (1 << 62) - 1
  - crowdcontrol: dijkstra w path max
  - abandonedanimal: check if prefix and suffix overlap

## 12.17.22
- wb traning 2 makeup (ncpc 2015)
- solved
  - adjoin: find half diameters, connect into star
  - justaquiz: dp on trie

## 12.19.22
- wb training 1 upsolve
- solved
  - boomingbusiness: `dp[i][j] =` height <= i, weight j + edge case when j < i 
  - journalediting: bitmask dp sorted by popcount
  - downtime: fifo q, ans = max q size / k ceiled
