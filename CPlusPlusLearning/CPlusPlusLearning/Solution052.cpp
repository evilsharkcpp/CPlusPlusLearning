#include "Solution052.hpp"

std::vector<double> Solution052::randPoint()
{
   std::vector<double> pointRandom(2);
   double r{ sqrt(_uni(_rng)) * _r }, rad{ 2 * PI * _uni(_rng) };
   pointRandom[0] = _x + r * cos(rad);
   pointRandom[1] = _y + r * sin(rad);
   return pointRandom;
}
