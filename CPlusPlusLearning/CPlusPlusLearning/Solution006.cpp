#include "Solution006.hpp"
#include <queue>
#include <map>

std::vector<std::string> Solution006::letterCombinations(std::string digits)
{
   std::queue<std::string> letters{};
   std::map<char, std::string> container{ {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
   for (auto& ch : digits)
   {
      if (letters.empty())
      {
         for (auto& t : container[ch])
         {
            letters.push(std::string(1, t));
         }
      }
      else
      {
         int queueSize = letters.size();
         for (int i{ 0 }; i < queueSize; i++)
         {
            std::string comb = letters.front();
            letters.pop();
            for (auto& t : container[ch])
            {
               letters.push(comb + std::string(1, t));
            }
         }
      }
   }
   std::vector<std::string> result;
   while (!letters.empty())
   {
      result.push_back(letters.front());
      letters.pop();
   }
   return result;
}