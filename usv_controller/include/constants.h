#ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace USV_CONST_PRAM
{
  // Heading controller
  constexpr double Kp_psi { 4 };
  constexpr double Ki_psi { 1.0 };
  constexpr double Kd_psi { 4 };
  constexpr double mass_psi { 10.0 - 1.0 }; // Iz - nDotR
  constexpr double damp_psi { 20.0 }; // nR

  // Speed controller
  constexpr double Kp_u { 2.0 };
  constexpr double Ki_u { 1.0 };
  constexpr double mass_u { 29 - 5.0 }; // m - xDotU: 29 - 5
  constexpr double damp_u { 20.0 }; // xU



  
}
#endif
