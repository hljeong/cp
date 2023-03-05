# log

## 3.4.23
- cf1794 virtual
- solved
  - 1794a: check longest, match chars + check palindrome in the middle
  - 1794b: turn 1s into 2s, then 1 sweep greedy
  - 1794c: find max `i` such that `a[i] < k - i`
  - 1794d: choose n primes as bases, compute sum of multinomials w dp
  - 1794e: hash tree by # of nodes @ each depth

## 3.3.23
- upsolve
- cf1800 virtual
- solved
  - 1796e: keep multiset of vertical path lens for each node + global multiset of 2nd mins + reroot, editorial impl is clean
  - 1800a: impl
  - 1800b: greedy
  - 1800c1
  - 1800c2: go in reverse order, if 0 then ++quota, otherwise either push to pq or replace minimum if larger
  - 1800d: +1 if`s[i] != s[i + 2]`
  - 1800e1
  - 1800e2: dsu positions + check multiset equality
  - 1800f: check parity by bitmask, iterate thru 26 possible missing chars (odd parity means exists!)
  - 1800g: tree hash

## 3.2.23
- upsolve
- solved
  - 1796d: dp on # processed, # x's added, before/in/after max sum segment
- unsolved
  - 1796e

## 3.1.23
- cf1796 virtual
- solved
  - 1796a: construct string and brute force check
  - 1796b: check if first char or last char equal or if they contain same substring of len 2
  - 1796c: only $2^k$ or $3 \cdot 2^{k - 1}$ works, binsearch for bounds for both
- unsolved
  - 1796d

## 2.28.23
- upsolve
- solved
  - 1791g2: try each starting tp w prefix sum + binsearch

# 2.27.23
- cf1791 virtual
- solved
  - 1791a: trivial
  - 1791b: trivial
  - 1791c: contract 2ptr until `s[i] == s[j]`
  - 1791d: rolling prefix/suffix freq table
  - 1791e: keep max flip/no flip for prev 2 inds
  - 1791f: need at most 4 ops, use sgt to keep count
  - 1791g1: greedy on `a[i] + i + 1`

## 2.23.23
- endgame training (selection of ncpc 2022)
- unsolved
  - enigmaticenumeration

## 2.20.23
- pacnw 2015
- solved
  - airports: path cover
  - excellence: sort, match start w end
  - hilbertsort: recursively solve, rotating appropriately
- unsolved: olympics

## 2.18.23
- w23 training 6 (ncpc 2019)
- solved
  - hothike: brute force
  - eenymeeny: brute force impl
  - cocoacoalition: casework, can do any in 3
  - gameofgnomes: for each c k's to tower on one of the stacks, compute damage in O(1)
  - jealousyoungsters: gale-shapley

## 2.16.23
- uci week 6 training
- solved
  - 1523b: repeat 1 2 no each pair 3 times
  - 1011c: binsearch
  - 810b: greedy
  - 534c: math
  - 527d: dp
  - 1509b: check valid balance forward and backward

## 2.12.23
- cf1793
- pacnw 2019
- solved
  - 1793a: casework
  - 1793b: min to max then min
  - 1793c: shrink seg until condition reached
  - 1793d: compute contribution for each mex
  - rainbowstrings: product of `1 + f[c]` for each char `c`
  - carrycamfailure: deterministic digit by digit, recursively try

## 2.11.23
- upsolve
- solved
  - stabletable: bitmask dp
  - pinnedfiles: find matching prefix + suffix then fix rest

## 2.7.23
- codesprint testsolving
- solved
  - cypherdecypher

## 2.4.23
- w23 training 4 (naq 2022)
- w23 training 5 makeup (ecna 2021)
- solved
  - metronome: divide by 4
  - movienight: scc then dp on tree counting
  - mazeman: flood fill
  - beastbullies: defend until survive from suffix
  - platformplacing: greedy
  - noonerizedspumbers: impl
  - abridgedreading: dp on tree
  - statues: impl
  - ballofwhacks: find all transformations
  - 1sforall: brute force
  - tollroads: qry offline, sort by weight, small-to-large

## 2.2.23
- w23 training 3 makeup
- solved
  - fairplay: straight match
  - deceleratingjump: dp
  - evolutionaryexcerpt: greedy
  - gyratingglyphs: solve 15 at a time
  - armcoordination: aabb
  - lopsidedlineup: greedy

## 1.28.23
- trying out kattis challenge
- unicup 1
- cf
- solved
  - unrealestate: segtree sweepline
  - drxvst1: trivial
  - clampedsequence: try all lower and upper bounds
  - cf793d: interval dp, extra state to keep track of which endpoint
  - generators: power as node, mst
  - cf762c: compute prefix and suffix longest subseq, binary search
  - ballcolors: permute bad colors, permute good colors, sticks and stones
  - paludarium: binary search, take care of 0 0 edge case

## 1.26.23
- looking at problems for tryout3
- solved
  - babylonian: python
  - islands3: flood fill to clouds but not from clouds
  - periodicstrings: impl
  - alphabet: brute force lis
  - water: flow w capacity increase updates
  - paint: dp w binary search
  - zigzag2: stupid max segtree

## 1.21.23
- w23 training 2 makeup
- solved
  - rankproblem: sim
  - simplysudoku: (robert)
  - overthehill1: sim
  - oreperationsresearch: (robert) dp, knapsack for transition eligibility
  - restroommonitor: greedily assign non-toilet paper ppl to non-toilet paper stalls
  - weightytomes: recursive dp
  - workers: (robert) min cost max flow
  - scholarslawn: (robert) geometry
- unsolved
  - overthehill2

## 1.29.23
- solved
  - molekule: back and forth edges

## 1.20.23
- w23 training 1 makeup
- solved
  - cf237a: print max simultaneous
  - ninepacks: knapsack
  - bigtruck: dijkstra + construct dag + dp
  - robotopia: stupid casework
  - arcade: markov gauss
  - primonimo: gauss

## 1.14.23
- solved
  - ac dp t: insert at each step
  - ac dp u: $3^n$ traverse submasks

## 1.5.23
- wb22 training 11
- solved
  - jigsaw: brute force check
  - incompletesort: fix 1st and 2nd quarters then 2nd half

## 1.4.23
- solved
  - distributinglevels

## 1.3.23
- upsolve
- solved
  - lexiographiclecturing: find normalized delta between chars of adj strings, for each starting point, if next -1 comes before next 1 then invalid; otherwise take max of next 1
  - decorativedominoes: max matching has to be n + reconstruct matching
  - adolescentarchitecture: dfs to find path containing all nodes, keep track of dfs stack
  - gravitygrid: get finished board, for each win, find min winning time
  - landscaping: supersource to low cells w weight b, high cells to super sink w weight b, connect pairwise adj cells w weight a
  - explosion: compress dp state by sorting

## 1.2.23
- wb training 10 (gcpc 2020)
- solved
  - flipflow: sim
  - impressiveintegers: no if 2, 3, 5; 1 on top if even, 4 on top if odd > 1
  - knightlyknowledge: try all monument (x, y) pairs
  - mixtapemanagement: in perm order, find prev, append 1s until length i, append 2
  - confinedcatching: occupying diagonals of a square containing enemy wins
- unsolved
  - exhaustingerrands
  - hecticharbour

## 1.1.23
- wb22 training 9 (calgary 2021)
- solved
  - haltingafterall: sim
  - workingfromhome: sim
  - combinatorialstanleycup: 1 << popcount
  - thecouncil: for each edge, greedily give to better endpoint
  - whichbits: binary search with pruning
  - concertrehearsal: bin search to construct graph, bin lift to count
  - wordpuzzle: rotate subseq then subseq dp
  - evensubstrings: segtree on prefix/suffix freq, count of 0-sum substrings, xor sum

## 12.29.22
- wb22 training 8 (maps 2020)
- robert strong recc smootharray
- solved
  - magicalcows: farms that double keep doubling
  - roundtrips: scc, can add edge between any pair of sccs
  - divideandconquer: need to check if b^m = -1 mod d, then b^(2 m) = 1 mod d, then order of b mod d must be even, check if b^(d') = 1 mod d (no if true), where d' is largest odd factor of d - 1 [benq](https://codeforces.com/blog/entry/74977?#comment-594342)
  - keywords: trivial
  - thewrathofkahn: find width of valid part of graph (remove scc + downstream), equivalent to path cover of poset
  - easymultiplication: transitions on mod graph, dijkstra then construct via bfs
  - smootharray: operate on mod k of array; optimize O(n^3) dp by only iterating over values you dont need to change in inner loop

## 12.28.22
- wb22 training upsolve
- solved
  - bells: sift n thru ans for n - 1
  - altruisticamphibians: sort by weight dec, dp on weight
  - deliverydelays: run dijkstra on each notable node, precompute wait time and trip time for each interval of orders, bin search on wait time + dp for reachability

## 12.27.22
- wb22 training 7 (ncpc 2018)
- solved
  - compass
  - raffle: find formula, ++r until decrease
  - autocorrect: build trie, lca for lcp, dp backwards for each word; official solution: add shortcut edges and bfs
  - exponial: generalized euler theorem
  - 1dfroggerhard: scc, compress graph, propagate reachability, reverse graph and dfs

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

## 12.25.22
- wb22 training upsolve
- solved
  - companypicnic: dp on tree, either use or not use
  - spaceprobe: union all bad segs to start at
  - suspensionbridges: stupid problem, bin search for a
  - umbraldecoding: quadtree

## 12.24.22
- wb22 training upsolve
- solved
  - intelligenceinfection: scc, compress, topsort, private message all bad nodes (nodes that have enemy downstream) and public message sources of good nodes incrementally

## 12.22.22
- wb22 training 5 (ncpc 2018)
- solved
  - houselawn: check all possible start points in lcm cycle
  - intergalacticbidding: greedily choose largest since superincreasing
  - kingscolors: incl-excl
- unsolved
  - explosion

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

## 12.17.22
- wb22 traning 2 makeup (ncpc 2015)
- solved
  - adjoin: find half diameters, connect into star
  - justaquiz: dp on trie

## 12.13.22
- wb22 training 1 (bapc prelim 2017)
- solved
  - ghostbusters2: mst w connectivity constraint
  - enviousexponents: flip latest possible 0 bit
  - diastrousdoubling: keep track up to (1 << 62) - 1
  - crowdcontrol: dijkstra w path max
  - abandonedanimal: check if prefix and suffix overlap

## 12.1.22
- robert couldnt solve this 2.4 problem
- solved
  - ada: impl

## 11.24.22
- finishing up new dinic / forward star template
- solved
  - ridehailing: min path cover

## 11.20.22
- f22 training 5
- solved
  - randomdigitalexponentiation: brute force from the back
- unsolved
  - leapfrog: brute force crt

## 11.19.22
- looking at jason's math problems
- solved
  - dvdscreensaver: reflection trick, crt
  - pseudoprime: check if prime, fast exp
  - threedigits: separately keep exponents for 2 and 5
  - hopscotch: combinatorics

## 11.17.22
- talking to suhas
- unsolved
  - landscaping

## 11.16.22
- f22 training 4
- finding mod math problem for f22 training 5
- solved
  - perica: sort + combinatorics
- unsolved
  - treequivalence

## 11.15.22
- f22 training 4
- solved
  - invasion: dijkstra

## 11.13.22
- looking at robert's graph problems
- then looking randomly at other practices
- then f22 training 4
- solved
  - thekingofthenorth: min cut, 1 edge for each cell
  - tetration: trivial math, pow(n, 1 / n)
  - damsindistress: dfs

## 11.12.22
- looking at robert's graph problems
- solved
  - dominoes2: trivial dfs
  - flowerytrails: dijkstra backtracking
  - onaveragetheyrepurple: ans = dist - 1, tricky!
  - customscontrols: greedy, tricky!

## 11.10.22
- looking at robert's graph problems
- solved
  - emptyingbaltic: pq flood fill
- unsolved
  - treequivalence: tree isomorphism

## 11.9.22
- looking at robert's graph problems
- solved
  - treehouses: straight mst
  - curveknights: straight topsort
  - breakingbad: straight bipartite checking

## 11.5.22
- doing [uchicago set](https://open.kattis.com/contests/saogxm)
- solved
  - fairdivision: greedy
  - minimumscalar: greedy
  - bank: greedy
  - jigsaw: 

## 11.4.22
- solving problems for dp training set
- solved
  - brackets: bracket sequence dp
  - bracketpairing: bracket sequence dp, cfg disambuation
  - piecesofparentheses: bracket sequence dp, tricky
  - reportcard: ez dp
  - potioncommotion: impl w edge case
  - gradingonacurve: binsearch
