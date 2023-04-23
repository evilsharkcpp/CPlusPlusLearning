#pragma once
#include <random>

///<summary>
/// https://leetcode.com/problems/generate-random-point-in-a-circle 
///</summary>
class Solution052
{
   double _r, _x, _y;
   std::mt19937 _rng{ std::random_device{}() };
   std::uniform_real_distribution<double> _uni{ 0, 1 };
   const double PI{ acos(-1.0) };
public:
   Solution052(double radius, double xCenter, double yCenter) :
      _r(radius), _x(xCenter), _y(yCenter) {}

   std::vector<double> randPoint();
};

