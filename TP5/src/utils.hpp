/**
 * @file utils.hpp
 * 
 * @brief This file contains the declarations of utility functions.
 */
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

#include "CLHEP/Random/MTwistEngine.h" 

void saveStatusWrapper(CLHEP::MTwistEngine *, std::string);
void restoreStatusWrapper(CLHEP::MTwistEngine*, std::string);
void performDraw(CLHEP::MTwistEngine*, int);
void performDrawWithPrint(CLHEP::MTwistEngine*, int);
double simulPi(CLHEP::MTwistEngine*, long);


#endif