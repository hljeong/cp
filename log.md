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
- then f22 training 4
- solved
  - thekingofthenorth: min cut, 1 edge for each cell
  - tetration: trivial math, pow(n, 1 / n)
  - damsindistress: dfs

## 11.15.22
- f22 training 4
- solved
  - invasion: dijkstra

## 11.16.22
- f22 training 4
- finding mod math problem for f22 training 5
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
- f22 training 5
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
- wb22 training 1 (bapc prelim 2017)
- solved
  - ghostbusters2: mst w connectivity constraint
  - enviousexponents: flip latest possible 0 bit
  - diastrousdoubling: keep track up to (1 << 62) - 1
  - crowdcontrol: dijkstra w path max
  - abandonedanimal: check if prefix and suffix overlap

## 12.17.22
- wb22 traning 2 makeup (ncpc 2015)
- solved
  - adjoin: find half diameters, connect into star
  - justaquiz: dp on trie

## 12.19.22
- wb22 training upsolve
- wb22 training 4 (maps 2022)
- solved
  - boomingbusiness: dp[i][j] = height <= i, weight j + edge case when j < i 
  - journalediting: bitmask dp sorted by popcount
  - downtime: fifo q, ans = max q size / k ceiled
  - entertainmentbox: sort by end desc then start asc, greedily select latest possible available track
  - floppy: keep track of all possible positions
  - bumped: dijkstra from s and t
  - lessvsfewer: python parse
  - pandemicshopping: casework
- unsolved
  - yetanotherdivisorproblem
  - primebitcount 

## 12.22.22
- wb22 training 5 (ncpc 2018)
- solved
  - houselawn: check all possible start points in lcm cycle
  - intergalacticbidding: greedily choose largest since superincreasing
  - kingscolors: incl-excl
- unsolved
  - explosion

## 12.24.22
- wb22 training upsolve
- solved
  - intelligenceinfection: scc, compress, topsort, private message all bad nodes (nodes that have enemy downstream) and public message sources of good nodes incrementally

## 12.25.22
- wb22 training upsolve
- solved
  - companypicnic: dp on tree, either use or not use
  - spaceprobe: union all bad segs to start at
  - suspensionbridges: stupid problem, bin search for a
  - umbraldecoding: quadtree

## 12.26.22
- upsolve
- wb22 training 8 (hk 2016)
- solved
  - raftingtrip: scc then make reverse tree then propagate w sightseeing spot cnt backtracking
  - playingwithnumbers: greedy
  - teamup: tricky construction of forest, then recursively assign
  - 1dfroggereasy: sim
- unsolved
  - perfecttree
  - 1dfroggerhard

## 12.27.22
- wb22 training 7 (ncpc 2018)
- solved
  - compass
  - raffle: find formula, ++r until decrease
  - autocorrect: build trie, lca for lcp, dp backwards for each word; official solution: add shortcut edges and bfs
  - exponial: generalized euler theorem
  - 1dfroggerhard: scc, compress graph, propagate reachability, reverse graph and dfs

## 12.28.22
- wb22 training upsolve
- solved
  - bells: sift n thru ans for n - 1
  - altruisticamphibians: sort by weight dec, dp on weight
  - deliverydelays: run dijkstra on each notable node, precompute wait time and trip time for each interval of orders, bin search on wait time + dp for reachability

## 12.29.22
- wb22 training 8 (maps 2020)
- robert strong recc smootharray
- solved
  - magicalcows: farms that double keep doubling
  - roundtrips: scc, can add edge between any pair of sccs
  - divideandconquer: need to check if b^m = -1 mod d, then b^(2 m) = 1 mod d, then order of b mod d must be even, check if b^(d') = 1 mod d (no if true), where d' is largest odd factor of d - 1 [benq](https://codeforces.com/blog/entry/74977?#comment-594342)
  - thewrathofkahn: find width of valid part of graph (remove scc + downstream), equivalent to path cover of poset
  - easymultiplication: transitions on mod graph, dijkstra then construct via bfs
  - smootharray: operate on mod k of array; optimize O(n^3) dp by only iterating over values you dont need to change in inner loop
