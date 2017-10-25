#include <iostream>
#include <gal/binary/chrm_binary.hpp>
#include <gal/binary/pop_binary.hpp>
#include "evaluation.h"

using namespace std;

typedef chrm_binary<44> chromossomo;
typedef chromossomo::ptr chromossomo_ptr;
typedef pop_binary<chromossomo_ptr> populacao;

#define N 100
#define Tm 0.0099
#define Tc 0.65

void print_pop(populacao::ptr p) {
    for(int i = 0;i < p->size(); i++)
        cout << evaluation(p->at(i)) << endl;
}

int main() {

    streambuf* orig_buf = cout.rdbuf();
    cout.rdbuf(NULL); // Comentar isso daqui vai permitir depurar o log cout.

    srand(time(NULL));
    populacao::ptr pop = populacao::initial_population<chromossomo>(N);
    double total = pop->rank<evaluation>();
    print_pop(pop);
    cout << endl;
    int t = 0;
    while(t < 2000) {
        total = pop->rank<evaluation>();
        populacao::ptr nova_pop(new populacao());
        for (size_t i = 0; i < N ; i++) {
            nova_pop->push_back(
                    chromossomo::mutation(
                            chromossomo::crossover_1point(
                                    populacao::get_parents_by_roulette<evaluation>(pop, total),
                                    Tc
                            ),
                            Tm
                    )
            );
        }
        nova_pop->rank<evaluation>();
        for(size_t i = 0; i < N;i++)
            nova_pop->pop_front();
        nova_pop->at(0) = pop->get_back();
        pop = nova_pop;
        print_pop(pop);
        cout << endl;
        cout << "---------------------------" << endl;
        t++;
    }

    cout.rdbuf(orig_buf);
    cout << evaluation(pop->get_back())<< endl;
    return 0;
}
