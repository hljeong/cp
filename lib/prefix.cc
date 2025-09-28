#include "../misc/tmpl.cc"

vi prefix(const str &s) {
  int n = s.size();
  vi pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    pi[i] = j + (s[i] == s[j]);
  }
  return pi;
}

struct Alphabet {
  static constexpr int MAX_CHAR = numeric_limits<char>::max();
  const string_view symbols;
  const char delimiter;
  const int size;
  const ar<int, MAX_CHAR> idx;
  static constexpr auto build_idx(string_view symbols) { 
    ar<int, MAX_CHAR> idx{};
    for (int i = 0; i < symbols.size(); i++) idx[symbols[i]] = i;
     return idx;
  }
  constexpr Alphabet(string_view symbols) :
    symbols{symbols},
    delimiter(ranges::max(symbols) + 1),
    size(symbols.size()),
    idx(build_idx(symbols)) {}
  constexpr char operator[](int idx) const { return symbols[idx]; };
  constexpr int operator[](char c) const { return idx[c]; };
};

constexpr Alphabet lowercase{"abcdefghijklmnopqrstuvwxyz"sv};

vc<vi> prefix_automaton(str s, const Alphabet &alphabet = lowercase) {
  s += alphabet.delimiter;
  int n = s.size();
  vi pi = prefix(s);
  vc<vi> transition(n, vi(alphabet.size));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < alphabet.size; c++) {
      if (i && alphabet[c] != s[i]) transition[i][c] = transition[pi[i - 1]][c];
      else transition[i][c] = i + (alphabet[c] == s[i]);
    }
  }
  return transition;
}
