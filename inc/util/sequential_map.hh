#pragma once
#include <array>

template<typename KeyT, typename ValT, size_t N>
class SequentialMap {
public:
    struct PairT {
        KeyT key;
        ValT element;
    };
    std::array<PairT, N> data;

    const ValT& at(const KeyT key) const {
        for (auto & pair : data) {
            if (pair.key == key)
                return pair.element;
        }
        return data[0].element;
    }
};

// const SequentialMap<PSProfileID, psProfile, 2> sar = {{{
//     {PSProfileID::RP25, {100, 200, 300, 400}},
//     {PSProfileID::RP35, {1000, 2000, 3000, 4000}}
// }}};

