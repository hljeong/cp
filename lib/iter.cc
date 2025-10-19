#include "../misc/tmpl.cc"

template <r::forward_range R1, r::forward_range R2>
struct zip : r::view_interface<zip<R1, R2>>
{
  R1 r1; R2 r2;
  zip() = default;
  zip(R1 r1, R2 r2) : r1(r1), r2(r2) {}

  struct iterator {
    using iterator_category = forward_iterator_tag;
    using value_type = tup<r::range_reference_t<R1>, r::range_reference_t<R2>>;
    r::iterator_t<R1> it1; r::iterator_t<R2> it2;
    iterator() = default;
    iterator(auto a, auto b) : it1(a), it2(b) {}
    value_type operator*() const { return { *it1, *it2 }; }
    iterator &operator++() { it1++; it2++; return self; }
    bool operator==(const iterator &other) const { return it1 == other.it1 || it2 == other.it2; }
    bool operator!=(const iterator &other) const { return !(self == other); }
  };

  iterator begin() { return { r::begin(r1), r::begin(r2) }; }
  iterator end() { return { r::end(r1), r::end(r2) }; }
};

template <r::forward_range R1, r::forward_range R2> zip(R1, R2) -> zip<R1, R2>;

template <r::forward_range R> auto pairwise(R &&r) { return zip(r, r | rv::drop(1)); }
