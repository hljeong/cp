#include "../misc/tmpl.cc"

template <ranges::range R> auto freq(const R &collection) {
  map<ranges::range_value_t<R>, int> f;
  for (auto element : collection) f[element]++;
  return f;
}
