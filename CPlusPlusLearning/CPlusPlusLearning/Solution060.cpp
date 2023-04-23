#include "Solution060.hpp"
#include <unordered_set>

int Solution060::partitionStringUsingSet(std::string s)
{
   int count{ 1 };
   std::unordered_set<char> letters{};

   for (const auto& ch : s)
   {
      if (letters.count(ch) != 0)
      {
         count++;
         letters.clear();
      }
      letters.emplace(ch);
   }

   return count;
}

int Solution060::partitionString(std::string s)
{
   std::vector<int> lastSeen(26, -1);
   int count{ 1 }, substringStart{};

   for (int i{}; i < s.length(); i++)
   {
      if (lastSeen[s[i] - 'a'] >= substringStart)
      {
         count++;
         substringStart = i;
      }
      lastSeen[s[i] - 'a'] = i;
   }
   return count;
}
