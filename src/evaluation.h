//
// Created by fellipe on 24/10/17.
//

#ifndef IC_1TH_EVALUATION_H
#define IC_1TH_EVALUATION_H

#include <cmath>
#include <gal/binary/chrm_binary.hpp>


#define Px 22
#define Py 22
#define P 44
#define Min -100
#define Max 100

class evaluation {
public:
    typedef double CompareType;
    explicit evaluation(chrm_binary<P>::ptr chrm);
    bool operator<(evaluation & rhs);
    CompareType get_eval();
    friend std::ostream& operator<<(std::ostream& os, const evaluation& ev);
private:
    CompareType _eval;
    chrm_binary<P>::ptr _chrm;
};

#endif //IC_1TH_EVALUATION_H
