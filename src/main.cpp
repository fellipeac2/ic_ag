//
// Created by fellipe on 18/10/17.
//
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <map>

#define Px 22
#define Py 22
#define P 44
#define Min -100
#define Max 100

#define N 100
#define E 1
#define T_c 0.65
#define T_m 0.01

using namespace std;

typedef bitset<P> chrm_type;
typedef vector<chrm_type*> pop_type;
typedef multimap<double, chrm_type*> ordered_pop_type;
typedef pair<double, chrm_type*> ordered_pop_pair_type;
typedef multimap<double, chrm_type*>::iterator ordered_pop_iterator;
typedef multimap<double, chrm_type*>::reverse_iterator ordered_pop_reverse_iterator;
typedef pair<chrm_type*, chrm_type*> chrm_pair;


double f(chrm_type *chrm) {
//    unsigned long xx = (*chrm>>Px).to_ulong();
//    cout << (Max - Min) << endl;
    double x = (*chrm>>Px).to_ullong() * (Max - Min)/(pow(2, Px)-1) + Min;
    double y = ((*chrm<<Px)>>Py).to_ullong()* (Max - Min)/(pow(2, Px)-1) + Min;
//    cout << x << '\t' << y << endl;
    return 1 - 0.5 - (pow(sin(sqrt(pow(x,2)+pow(y,2))),2) - 0.5)
                 /pow((1.0+0.001*(pow(x,2)+pow(y,2))),2);
}

pop_type * initial_population() {
    pop_type * pop = new pop_type();
    for(int j = 0; j < N; j++) {
        chrm_type * x = new chrm_type();
        for (int i = 0; i < P; i++)
            x->set(i, rand() % 2);
        pop->push_back(x);
    }
    return pop;
}

ordered_pop_type * rank_population(pop_type * pop) {
    ordered_pop_type * ordered_pop = new ordered_pop_type();
    for(int i = 0; i < pop->size(); i++) {
        ordered_pop->insert(ordered_pop_pair_type(f(pop->at(i)), pop->at(i)));
    }
    return ordered_pop;
}

chrm_type * get_best(ordered_pop_type * ordered_pop, size_t x) {
    ordered_pop_reverse_iterator rit = ordered_pop->rbegin();
    for(int i = 0; i < x; i++)
        rit++;
    return rit->second;
}

void print_pop(pop_type * pop) {
    for(int i = 0; i < pop->size(); i++) {
        cout << pop->at(i)->to_string() << '\t' << 1-f(pop->at(i)) << endl;
    }
}

void print_ordered_pop(ordered_pop_type * ordered_pop) {
    for(ordered_pop_iterator it = ordered_pop->begin(); it != ordered_pop->end(); ++it) {
        std::cout << 1-it->first << "\t" << it->second->to_string() << std::endl;
    }
}

double get_total_fitness(ordered_pop_type * ordered_pop) {
    double total_fitness = 0;
    for(ordered_pop_iterator it = ordered_pop->begin(); it != ordered_pop->end(); ++it)
        total_fitness += it->first;
    return total_fitness;

}

chrm_type * get_parent(ordered_pop_type * ordered_pop, double total_fitness) {
    double fitness_accumulated = 0;
    double prob_numb = ((double) (rand()%((int) (total_fitness * 1000))))/1000;
    for(ordered_pop_iterator it = ordered_pop->begin(); it != ordered_pop->end(); ++it) {
        fitness_accumulated += it->first;
        if(prob_numb <= fitness_accumulated) {
            return it->second;
        }
    }
    return 0;
}

chrm_pair * crossover(chrm_type * parent1, chrm_type * parent2) {
    chrm_type * child1 = new chrm_type();
    chrm_type * child2 = new chrm_type();

    int point = rand() % P;
    cout << "\tPonto de corte: " << point << endl;
    float prob_crossover = ((float) (rand() % 10000))/10000;
    cout << "\tA probabilidade em crossover foi de " << prob_crossover << endl;
    if(prob_crossover <= T_c) {
        for(size_t i = 0; i < point; i++) {
            child1->set(i, parent1->test(i));
            child2->set(i, parent2->test(i));
        }
        for(size_t i = point; i < P; i++) {
            child1->set(i, parent2->test(i));
            child2->set(i, parent1->test(i));
        }
    } else {
        child1 = parent1;
        child2 = parent2;
    }
    cout << "\tFilho 1: " << endl;
    cout << '\t' << child1->to_string() << '\t' << 1 -f(child1) << endl;
    cout << "\tFilho 2: " << endl;
    cout << '\t' << child2->to_string() << '\t' << 1 -f(child2) << endl << endl;
    return new chrm_pair(child1, child2);
}

chrm_type * mutation(chrm_type * chrm) {
    chrm_type * new_chrm = new chrm_type();
    for(size_t i = 0; i < P; i++) {
        float prob_mutation = ((float) (rand() % 1000))/1000;
        if (prob_mutation <= T_m)
            new_chrm->set(i, !chrm->test(i));
        else
            new_chrm->set(i, chrm->test(i));
    }
    return new_chrm;
}

bool add_pop_till_max(pop_type * pop, chrm_type * chrm) {
    if(pop->size() < N) {
        pop->push_back(chrm);
        return true;
    } else {
        return false;
    }
}

int main() {

    streambuf* orig_buf = cout.rdbuf();
    cout.rdbuf(NULL); // Comentar isso daqui vai permitir depurar o log cout.
    srand(time(NULL));
    int t = 0;

    pop_type * population = initial_population();
    chrm_type * best;
    while(t < 1000) {
        ordered_pop_type * ordered_population = rank_population(population);
        double total_fitness = get_total_fitness(ordered_population);
        cout << "População numero " << t<<endl;
        print_pop(population);
        cout << "População ordenada: "<<endl;
        print_ordered_pop(ordered_population);
        best = get_best(ordered_population, 0);
        cout << "O melhor dessa população é: " << endl;
        cout << best->to_string() << '\t' << 1 -f(best) << endl;

        pop_type * new_population = new pop_type();

        cout << "Construindo a descendência: " << endl;
        for(int i = 0; i < N; i++) {
            cout << "\tCruzamento numero: " << i << endl;
            chrm_type * parent1 = get_parent(ordered_population, total_fitness);
            chrm_type * parent2 = get_parent(ordered_population, total_fitness);

            cout << "\tPai 1: " << endl;
            cout << '\t'<<parent1->to_string() << '\t' << 1 -f(parent1) << endl;
            cout << '\t' << "Pai 2: " << endl;
            cout << '\t'<<parent2->to_string() << '\t' << 1 -f(parent2) << endl;

            chrm_pair * childs = crossover(parent1, parent2);
            cout << "\tMutação dos cromossomos filhos: "<<endl;
            childs->first = mutation(childs->first);
            childs->second = mutation(childs->second);

            cout << "\tFilho 1 mutado: " << endl;
            cout << '\t' << childs->first->to_string() << '\t' << 1 -f(childs->first) << endl;
            cout << "\tFilho 2 mutado: " << endl;
            cout << '\t' << childs->second->to_string() << '\t' << 1 -f(childs->second) << endl << endl;

            new_population->push_back(childs->first);
            new_population->push_back(childs->second);
        }
//        for(int i = 0; i < N; i++)
//            new_population->pop_back();
        cout << "Nova descendência construida: " << endl;
        print_pop(new_population);
        cout << "Ordenado: " << endl;
        //Rankiar a descendência;
        ordered_pop_type * ordered_new_population = rank_population(new_population);
        print_ordered_pop(ordered_new_population);

        cout << "Descendência + elitismo: " << endl;

//        new_population->clear();
//        for(ordered_pop_reverse_iterator it = ordered_new_population->rbegin(); it != ordered_new_population->rend(); ++it) {
//            new_population->push_back(it->second);
//        }

        for(int i = 0; i < N; i++)
            new_population->pop_back();
        for(int i = 0; i < E; i++)
            new_population->at(i) = get_best(ordered_population, i);
        print_pop(new_population);

        cout << "--------------------------------------------------------" << endl;
        population = new_population;
        t++;
    }

    cout.rdbuf(orig_buf);
    cout << best->to_string() << '\t' << 1 - f(best) << endl;
}
