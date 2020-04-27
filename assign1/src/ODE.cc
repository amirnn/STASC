#include "ODE.h"

namespace STASC
{
/*
* params: parameter lambda, timeStep can be one single value or a vector of time points.
*/
ODE::ODE(SystemFunction sysfunc, State initialState, std::vector<double> timeStepsVec) : systemFunction{sysfunc}, stateVector{initialState}, timeStepsVec{timeStepsVec}
{
}

ODE::~ODE()
{
}
inline State operator+(const State &first, const State &second)
{
    State resultState;
    assert(first.size() == second.size());
    for (size_t i = 0; i < first.size(); ++i)
    {
        resultState.push_back(first.at(i) + second.at(i));
    }
    return resultState;
}
State ODE::getStateVector()
{
    return stateVector;
}

double ODE::getTime()
{
    return time;
}

// returns the gradient at that point in time.
State ODE::du_dt(double time)
{
    State &currentState{stateVector};
    State gradient = systemFunction(currentState, time);
    return gradient;
}

// uses gradient and integrates using time step
void ODE::int_u_dt(IntegrationMode mode)
{
    if (mode == IntegrationMode::ERK1)
    {   
        State newState;
        State gradient = du_dt(time); // uses general time.
        double timeStep = timeStepsVec.at(currentTimeIndex + 1) - timeStepsVec.at(currentTimeIndex);
        gradient = gradient * timeStep;
        for (auto &element : gradient)
        {
            element *= timeStep;
        }
        newState = gradient + stateVector;
        // for (size_t i=0;i < gradient.size();++i){
        //     newState.push_back(gradient.at(i)+ stateVector.at(i));
        // }
        stateVector = newState; // Update the state
        currentTimeIndex++;     // Update the index of time Vector.
        time += timeStep;
    }
};
} // namespace STASC
