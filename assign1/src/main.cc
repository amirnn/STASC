#include <iostream>
#include <armadillo>
#include "ODE.h"
#include "sysFunc.h"
/* I should make it compatible with armadillo, currently it is working with std::vector containers 
to be able to make it work with armadillo I need to make it generic.
*/

using namespace STASC;
int main()
  {
  constexpr size_t timeStepsCount = 1000;
  constexpr double stepSize = 0.1;
  std::vector<double> timeStepsVec(timeStepsCount);
  for (size_t i=0; i < timeStepsCount; i++){
    timeStepsVec.at(i) = i * stepSize;
  }

  ODE ode(SysFunc::sysFuncOne,SysFunc::initialStateOne,timeStepsVec);

  std::vector<State> systemTrajectory;
  // Integrate and collect the state at each time point
  for (size_t i=0; i < timeStepsCount - 1 ;i++){
    ode.int_u_dt(STASC::IntegrationMode::ERK1);
    systemTrajectory.push_back(ode.getStateVector());
  }
  assert( systemTrajectory.size() == timeStepsCount -1);
  
  for (auto element : systemTrajectory)
    std::cout << element.at(0).real() << "\n"; // show the position.

  return 0;

  }
