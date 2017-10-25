//
// Created by fellipe on 24/10/17.
//

#ifndef IC_1TH_CHRM_BINARY_H
#define IC_1TH_CHRM_BINARY_H

#include <bitset>
#include <iostream>
#include <memory>

template <size_t N>
class chrm_binary {
public:
    typedef std::shared_ptr<chrm_binary> ptr;
    typedef std::bitset<N> set_type;

    explicit chrm_binary() : _bitset(*(new chrm_binary<N>::set_type())){ }
    explicit chrm_binary(std::string str) : _bitset(*(new set_type(str))){}

    virtual ~chrm_binary() = default;
    chrm_binary(const chrm_binary &) = default;
    chrm_binary(chrm_binary &&) noexcept = default;

    const bool operator[](size_t i) const {
        return _bitset.test(i);
    }
    const bool at(size_t i) const {
        return _bitset.test(i);
    }
    typename std::bitset<N>::reference operator[](size_t i) {
        return _bitset.operator[](i);
    }
    typename std::bitset<N>::reference at(size_t i) {
        return _bitset.operator[](i);
    }
    void flip(size_t i) {
        _bitset.flip(i);
    }
    const std::basic_string<char, std::char_traits<char>, std::allocator<char>> to_string() const {
        return _bitset.to_string();
    }
    unsigned long long int to_ullong() {
        return _bitset.to_ullong();
    }
    chrm_binary &operator<<(size_t i) {
        _bitset.operator<<=(i);
        return *this;
    }
    chrm_binary &operator>>(size_t i) {
        _bitset.operator>>=(i);
        return *this;
    }
    set_type get_set() {
        return _bitset;
    }
    chrm_binary & random() {
        for(size_t i = 0; i < N; i++)
            _bitset.set(i, rand() % 2);
        return *this;
    }

    friend std::ostream & operator<<(std::ostream &os, const chrm_binary<N> &ch) {
        os << ch._bitset.to_string();
        return os;
    }

    // Operadores

    static ptr mutation(const ptr & old, double taxa) {
        ptr _new( new chrm_binary<N>());
        for(size_t i = 0; i < N; i++) {
            float prob_mutation = ((float) (rand() % 1000))/1000;
            if (prob_mutation <= taxa)
                _new->at(i) = !old->at(i);
            else
                _new->at(i) = old->at(i);
        }
        return _new;
    }
    static std::pair<ptr, ptr> & mutation(std::pair<ptr, ptr> & chrms, double taxa) {
        chrms.first = mutation(chrms.first, taxa);
        chrms.second = mutation(chrms.second, taxa);
        std::cout << '\t' << "Mutados: " << std::endl;
        std::cout << '\t' << *chrms.first << std::endl << '\t' << *chrms.second << std::endl << std::endl;
        return chrms;
    }
    static std::pair<ptr, ptr> & crossover_1point(std::pair<ptr, ptr> & parents, double taxa) {
        std::pair<ptr, ptr> * children = new std::pair<ptr, ptr>();
        int point = rand() % N;
        float prob_crossover = ((float) (rand() % 10000))/10000;

        if(prob_crossover <= taxa) {
            std::cout << "\tCrossover sucess!" << std::endl;
            children->first = ptr(new chrm_binary<N>());
            children->second = ptr(new chrm_binary<N>());
            for(size_t i = 0; i < point; i++) {
                children->first->at(i) = parents.first->at(i);
                children->second->at(i) = parents.second->at(i);
            }
            for(size_t i = point; i < N; i++) {

                children->first->at(i) = parents.second->at(i);
                children->second->at(i) = parents.first->at(i);
            }
        } else {
            std::cout << "\tCrossover fail!" << std::endl;
            children->first = parents.first;
            children->second = parents.second;
        }

        std::cout << "\tChildren:\n\t" << *children->first << "\n\t" << *children->second << std::endl << std::endl;

        return *children;
    }

private:
    set_type & _bitset;
};

#endif //IC_1TH_CHRM_BINARY_H
