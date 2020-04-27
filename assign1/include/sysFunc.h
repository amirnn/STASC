#pragma once

#include <functional>
#include "ODE.h"
using namespace STASC;

constexpr std::complex<double> lambda1{2};
constexpr std::complex<double> lambda2{-0.5};
State initialStateOne {1,10};
State sysFuncOne(const State &state, double time)
{
    State gradient(state.size());
    gradient[0] = -lambda1 * state[1];
    gradient[1] = lambda2 * state[0];
    return gradient;
}

State sysFuncTwo(const State &state, double time)
{

    State nextState;
    return nextState;
}
