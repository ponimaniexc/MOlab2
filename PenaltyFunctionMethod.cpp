#include "PenaltyFunctionMethod.h"

double PenaltyFunctionMethod::VspFunction()
{
	return func(x) - r * (g1(x) + g2(x));
}
