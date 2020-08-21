#pragma once
#include <array>

template<typename KeyT, typename ValT, size_t N>
class SequentialMap {
public:
    struct PairT {
        const KeyT key;
        ValT element;
    };
    std::array<PairT, N> data;

    const ValT& operator[](const KeyT key) const {
        for (auto & pair : data) {
            if (pair.key == key)
                return pair.element;
        }
        return data[0].element;
    }
    ValT& operator[](const KeyT key) {
        for (auto & pair : data) {
            if (pair.key == key)
                return pair.element;
        }
        return data[0].element;
    }
};

