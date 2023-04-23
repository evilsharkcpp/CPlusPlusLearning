#include "Solution027.hpp"

std::vector<int> Solution027::countPoints(std::vector<std::vector<int>>& points,
   std::vector<std::vector<int>>& queries)
{
   auto isInside
   {
       [](std::vector<int>& query, std::vector<int>& point)
       {
           return pow((point[0] - query[0]), 2) + pow(point[1] - query[1], 2) <= pow(query[2], 2);
       }
   };

   std::vector<int> result{};
   result.reserve(queries.size());
   for (auto& query : queries)
   {
      int hitsCount{};
      for (auto& point : points)
         if (isInside(query, point))
            hitsCount++;
      result.push_back(hitsCount);
   }
   return result;
}
