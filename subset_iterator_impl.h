#pragma once

template <typename T>
void subset_iterator<T>::advance()
{
    size_t i = 0;
    while (i < m_exists.size()) {
        if (m_exists[i]) {
            m_exists[i] = false;
            ++i;
        } else {
            m_exists[i] = true;
            break;
        }
    }
    if (i == m_exists.size()) {
        m_is_end = true;
    }
}

template <typename T>
std::vector<T> subset_iterator<T>::current_subset() const
{
    std::vector<T> result;
    for (int i = 0; i < m_exists.size(); ++i) {
        if (m_exists[i]) {
            result.push_back(m_set[i]);
        }
    }
    return std::move(result);
}
