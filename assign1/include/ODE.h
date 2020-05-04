#pragma once

#include <complex>
#include <vector>
#include <functional>
#include <string>
#include <cassert>

namespace STASC
{
typedef std::vector<std::complex<double>> State;
typedef std::function<State(State &state, double time)> SystemFunction;
enum class IntegrationMode
{
    ERK1 //Euler Forward Method.
};
class ODE
{
private:
    State stateVector; // initilizes with the initial state and then always holds latest state
    std::vector<double> timeStepsVec;
    size_t currentTimeIndex{0};
    double time{0}; // The universal time. TODO: Can be unitless.
    SystemFunction systemFunction;

public:
    ODE(SystemFunction sysfunc, State initialState ,std::vector<double> timeStepsVec);
    State du_dt(double time);
    void int_u_dt(IntegrationMode mode /*, double timeStep*/);
    State getStateVector();
    double getTime();
    ~ODE();
};


} // namespace ODE
