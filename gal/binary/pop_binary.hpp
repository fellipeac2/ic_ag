//
// Created by fellipe on 24/10/17.
//

#ifndef IC_1TH_POP_BINARY_H
#define IC_1TH_POP_BINARY_H

#include <vector>
#include <iterator>
#include <algorithm>
#include <gal/binary/chrm_binary.hpp>
#include <memory>

template <class Tc>
class pop_binary {
public:
    typedef std::shared_ptr<pop_binary> ptr;
    typedef std::vector<Tc> container_type;

    explicit pop_binary() {}
    ~pop_binary() = default;
    pop_binary(const pop_binary &) = delete;
    pop_binary(const pop_binary &&) noexcept = delete;

    pop_binary &operator=(const pop_binary & rhs)  {
        _vector = std::move(rhs._vector);
    }
    pop_binary &operator=(pop_binary && rhs) noexcept = delete;

    const Tc &operator[](size_t i) const {
        return _vector.at(i);
    }

    Tc &operator[](size_t i) {
        return _vector.at(i);
    }

    const Tc & at(size_t i) const {
        return _vector.at(i);
    }

    Tc & at(size_t i) {
        return _vector.at(i);
    }

    void push_back(Tc & rhs) {
        _vector.push_back(rhs);
    }
//
    void push_back(const Tc & rhs) {
        _vector.push_back(rhs);
    }

    void push_back(std::pair<Tc, Tc> & pair) {
        _vector.push_back(pair.first);
        _vector.push_back(pair.second);
    }
    void push_back(const std::pair<Tc, Tc> & pair) {
        _vector.push_back(pair.first);
        _vector.push_back(pair.second);
    }

    void pop_back() {
        _vector.pop_back();
    }


    void pop_front() {
        _vector.erase(_vector.begin());
    }

    const size_t size() const {
        return _vector.size();
    }

    size_t size() {
        return _vector.size();
    }

    Tc & get_back() {
        return _vector[_vector.size() - 1];
    }

    const Tc & get_back() const {
        return _vector[_vector.size() - 1];
    }



    friend std::ostream& operator<<(std::ostream& os, const pop_binary& po)
    {
        for(int i = 0; i < po.size(); i++)
            os << *(po[i].get()) << '\n';
        return os;
    }

    template <class E>
    typename E::CompareType rank() {
        std::sort(_vector.begin(), _vector.end(), [](const Tc & a, const Tc & b) {
            E c(a);
            E d(b);
            return c < d;
        });
        typename E::CompareType sum = 0;
        for(int i = 0; i < _vector.size(); i++)
            sum += E(_vector[i]).get_eval();
        return sum;
    }

    template <class T>
    static ptr initial_population(size_t N) {
        ptr pop(new pop_binary<Tc>());
        for(size_t i = 0; i < N; i++) {
            Tc chm(new T());
            chm->random();
            pop->push_back(chm);
        }
        return pop;
    }

    template <class E>
    static std::pair<Tc, Tc> & get_parents_by_roulette(pop_binary::ptr ordened_pop, typename E::CompareType total_fitness) {
        std::pair<Tc, Tc> * parents = new std::pair<Tc, Tc>();
        typename E::CompareType fitness_accumulated = 0;
        typename E::CompareType prob_numb = ((typename E::CompareType) (rand()%((int) (total_fitness * 10000))))/10000;
        for(size_t i = 0; i < ordened_pop->size(); i++) {
            fitness_accumulated += E(ordened_pop->at(i)).get_eval();
            if(prob_numb <= fitness_accumulated) {
                parents->first = ordened_pop->at(i);
                break;
            }
        }
        fitness_accumulated = 0;
        prob_numb = ((typename E::CompareType) (rand()%((int) (total_fitness * 10000))))/10000;
        for(size_t i = 0; i < ordened_pop->size(); i++) {
            fitness_accumulated += E(ordened_pop->at(i)).get_eval();
            if(prob_numb <= fitness_accumulated) {
                parents->second = ordened_pop->at(i);
                break;
            }
        }

        std::cout << '\t' << "Selecionou na roleta: " << std::endl;
        std::cout << '\t' << *parents->first << std::endl << '\t' << *parents->second << std::endl << std::endl;
        return *parents;
    };


private:
    container_type _vector;
};

#endif //IC_1TH_POP_BINARY_H
