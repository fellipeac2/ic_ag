//
// Created by fellipe on 25/10/17.
//

#include "evaluation.h"

evaluation::evaluation(chrm_binary<44>::ptr chrm) : _chrm(chrm) {

    chrm_binary<44>::set_type set = chrm->get_set();

    double x = (set>>Px).to_ullong() * (Max - Min)/(pow(2, Px)-1) + Min;
    double y = ((set<<Px)>>Py).to_ullong()* (Max - Min)/(pow(2, Px)-1) + Min;
    _eval = 1 - 0.5 - (pow(sin(sqrt(pow(x,2)+pow(y,2))),2) - 0.5)
                      /pow((1.0+0.001*(pow(x,2)+pow(y,2))),2);
}

bool evaluation::operator<(evaluation & rhs) {
    return _eval < rhs._eval;
}

evaluation::CompareType evaluation::get_eval() {
    return _eval;
}

std::ostream &operator<<(std::ostream &os, const evaluation &ev) {
    os << ev._chrm->to_string() << '\t' << 1- ev._eval;
    return os;
}
