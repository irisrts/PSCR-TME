#pragma once
#include <vector>

template<typename K, typename V>

class HashMap<K, V>{
    class Entry{
        public:
        string mot;
        const int cle;
    };

    public:
    vector<forward_list<Entry>> buckets;
    int size;

    HashMap(int taille) : size(taille), buckets[size]{
        for(const auto &)
    }
};