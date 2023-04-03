#include "Solution037.h"
#include <functional>
#include <algorithm>

int Solution037::minimumLines(std::vector<std::vector<int>>& stockPrices)
{
   if (stockPrices.size() < 2)
      return 0;
   sort(stockPrices.begin(), stockPrices.end());
   std::function<int(int, int)> gcd
   {
      [&](int a, int b)
      {
         return b == 0 ? a : gcd(b, a % b);
      }
   };
   int counter{ 0 };
   int dx{ std::numeric_limits<int>::max() },
      dy{ std::numeric_limits<int>::max() };
   for (int i{ 1 }; i < stockPrices.size(); i++)
   {
      int tx{ stockPrices[i][0] - stockPrices[i - 1][0] },
         ty{ stockPrices[i][1] - stockPrices[i - 1][1] },
         g{ gcd(tx, ty) };
      tx /= g;
      ty /= g;
      counter += tx != dx || ty != dy;
      dx = tx;
      dy = ty;
   }
   return counter;
}
