#pragma once

#include <functional>
#include <complex>
#include "ODE.h"

namespace SysFunc{
using namespace STASC;
using namespace std::complex_literals;
constexpr std::complex<double> lambda1(1,0);
constexpr std::complex<double> lambda2(-1,0);
State initialStateOne {1,0};
State sysFuncOne(const State &state, double time)
{
    State gradient(state.size());
    gradient[0] = lambda1 * state[1];
    gradient[1] = lambda2 * state[0];
    return gradient;
}

State sysFuncTwo(const State &state, double time)
{

    State gradient(state.size());
    gradient[0] = lambda1 * state[0];
    gradient[1] = lambda2 * state[1];
    return gradient;
}
}
// end of namespace SysFunc

