#include <iostream>
#include <armadillo>
#include <boost/tuple/tuple.hpp>
#include "gnuplot-iostream.h"
#include "ODE.h"
#include "sysFunc.h"

/* I should make it compatible with armadillo, currently it is working with std::vector containers 
to be able to make it work with armadillo I need to make it generic.
*/

using namespace STASC;
int main()
{

  std::vector<State> systemTrajectory;
  constexpr size_t timeStepsCount = 1000;
  constexpr double stepSize = 0.1;
  std::vector<double> timeStepsVec(timeStepsCount);
  std::vector<double> position;

  // ODE
  {
    for (size_t i = 0; i < timeStepsCount; i++)
    {
      timeStepsVec.at(i) = i * stepSize;
    }

    ODE ode(SysFunc::sysFuncOne, SysFunc::initialStateOne, timeStepsVec);

    // Integrate and collect the state at each time point
    for (size_t i = 0; i < timeStepsCount - 1; i++)
    {
      ode.int_u_dt(STASC::IntegrationMode::ERK1);
      systemTrajectory.push_back(ode.getStateVector());
    }
    assert(systemTrajectory.size() == timeStepsCount - 1);
     for ( auto element : systemTrajectory)
        position.push_back(element.at(0).real());
    //   std::cout << element.at(0).real() << "\n"; // show the position.
  }

  // GNU Plot
  // std::cout << "position size: " << position.size() << std::endl;
  // std::cout << "time vector size: " << timeStepsVec.size() << std::endl;

  if(true){
    /* output */
    // to make sizes match.
    position.push_back(*position.cend()); // Duplicating the last element.
    Gnuplot gp;
    gp << "plot '-' using 1:2 with linespoint" << std::endl;
    gp.send1d(std::make_tuple(timeStepsVec, position));
  }

  return 0;
}
