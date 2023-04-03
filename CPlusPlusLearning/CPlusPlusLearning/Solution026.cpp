#include "Solution026.h"
#include <unordered_set>

int Solution026::minAreaRect(std::vector<std::vector<int>>& points)
{
   struct Hash
   {
      size_t operator()(const std::pair<int, int>& x) const
      {
         return std::hash<long long>()(((long long)x.first) ^ ((long long)x.second));
      }
   };
   std::unordered_set<std::pair<int, int>, Hash> seen;
   int result{ std::numeric_limits<int>::max() };
   for (const auto& p : points)
   {
      int x1{ p[0] }, y1{ p[1] };
      for (auto& pair : seen)
      {
         auto x2{ pair.first }, y2{ pair.second };
         if (seen.count({ x1, y2 }) && seen.count({ x2, y1 }))
         {
            int area{ abs(x1 - x2) * abs(y1 - y2) };
            result = std::min(area, result);
         }
      }
      seen.emplace(x1, y1);
   }
   return result == std::numeric_limits<int>::max() ? 0 : result;
}
