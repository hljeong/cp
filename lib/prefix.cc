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

  template <class T> using Map = ar<T, MAX_CHAR + 1>;
};

constexpr Alphabet lowercase{"abcdefghijklmnopqrstuvwxyz"sv};

auto prefix_automaton(str s, const Alphabet &alphabet = lowercase) {
  s += alphabet.delimiter;
  int n = s.size();
  vi pi = prefix(s);
  vec<Alphabet::Map<int>> transition(n, Alphabet::Map<int>{});
  for (int i = 0; i < n; i++) {
    for (char c : alphabet.symbols) {
      if (i && c != s[i]) transition[i][c] = transition[pi[i - 1]][c];
      else transition[i][c] = i + (c == s[i]);
    }
  }
  return transition;
}

namespace experimental {

template <size_t N> struct ConstexprString {
  char value[N];
  consteval ConstexprString(const char (&s)[N]) {
    for (size_t i = 0; i < N; i++) value[i] = s[i];
  }
  consteval operator string_view() const { return {value, N - 1}; }
};

template <ConstexprString Symbols> struct Alphabet {
  static constexpr int MAX_CHAR = numeric_limits<char>::max();
  static constexpr string_view symbols = Symbols;
  static constexpr size_t size = symbols.size();

  static constexpr char max_char() {
    char mc = 0;
    for (char c : symbols) ckmax(mc, c);
    return mc;
  }

  static_assert(max_char() != static_cast<char>(MAX_CHAR));
  static constexpr char delimiter = static_cast<char>(max_char() + 1);

  static constexpr auto build_idx() {
    ar<int, MAX_CHAR> idx{};
    for (size_t i = 0; i < size; i++) idx[symbols[i]] = i;
    return idx;
  }

  static constexpr auto idx = build_idx();

  constexpr char operator[](int i) const { return symbols[i]; }
  constexpr int operator[](char c) const { return idx[c]; }
};

using LowerCase = Alphabet<"abcdefghijklmnopqrstuvwxyz">;
LowerCase lowercase;

template <class Alphabet = LowerCase> nvec<int, 2> prefix_automaton(str s, Alphabet alphabet = {}) {
  s += alphabet.delimiter;
  int n = s.size();
  vi pi = prefix(s);
  auto transition = make_nvec<int>(n, alphabet.size, 0);
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < alphabet.size; c++) {
      if (i && alphabet[c] != s[i]) transition[i][c] = transition[pi[i - 1]][c];
      else transition[i][c] = i + (alphabet[c] == s[i]);
    }
  }
  return transition;
}

}
