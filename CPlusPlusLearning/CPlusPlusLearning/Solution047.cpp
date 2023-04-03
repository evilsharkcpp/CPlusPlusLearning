#include "Solution047.h"

int Solution047::maxProfit(std::vector<int>& prices)
{
   int priceMin{ std::numeric_limits<int>::max() };
   int profitMax{};
   for (const auto& price : prices)
   {
      priceMin = std::min(priceMin, price);
      profitMax = std::max(profitMax, price - priceMin);
   }
   return profitMax;
}
