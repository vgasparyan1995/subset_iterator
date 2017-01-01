#pragma once

#include <iterator>
#include <vector>

namespace std {

template <typename T>
class subset_iterator
{
public:
    subset_iterator()
        : m_is_end(true)
    {}

    template <typename Iter>
    subset_iterator(Iter from, Iter to)
        : m_set(from, to)
        , m_exists(std::distance(from, to), false)
        , m_is_end(from == to)
    {}
    
    subset_iterator(std::initializer_list<T> il)
        : m_set(il.begin(), il.end())
        , m_exists(il.size(), false)
        , m_is_end(il.size() == 0)
    {}

    subset_iterator(const subset_iterator&) = default;
    subset_iterator& operator=(const subset_iterator&) = default;
    ~subset_iterator() = default;

    subset_iterator& operator++ ()
    {
        advance();
        return *this;
    }

    subset_iterator operator++ (int)
    {
        auto tmp = (*this);
        advance();
        return tmp;
    }

    std::vector<T> operator* () const
    {
        return current_subset();
    }

    bool is_end() const
    {
        return m_is_end;
    }

private:
    void advance();
    std::vector<T> current_subset() const;

private:
    std::vector<T> m_set;
    std::vector<bool> m_exists;
    bool m_is_end;
};

#include "subset_iterator_impl.h"

} // namespace std
