/***
 * @Author: Xu.WANG
 * @Date: 2021-10-26 17:41:47
 * @LastEditTime: 2021-10-26 17:45:13
 * @LastEditors: Xu.WANG
 * @Description:
 * @FilePath: \Kiri2D\KiriExtlib\include\remove_at.hpp
 */
#ifndef REMOVE_AT_HPP
#define REMOVE_AT_HPP

template <typename T>
void remove_at(std::vector<T> &vector, const std::vector<int> &to_remove)
{
    auto vector_base = vector.begin();
    std::vector<T>::size_type down_by = 0;

    for (auto iter = to_remove.cbegin();
         iter < to_remove.cend();
         iter++, down_by++)
    {
        std::vector<T>::size_type next = (iter + 1 == to_remove.cend()
                                              ? vector.size()
                                              : *(iter + 1));

        std::move(vector_base + *iter + 1,
                  vector_base + next,
                  vector_base + *iter - down_by);
    }
    vector.resize(vector.size() - to_remove.size());
}

#endif // REMOVE_AT_HPP
