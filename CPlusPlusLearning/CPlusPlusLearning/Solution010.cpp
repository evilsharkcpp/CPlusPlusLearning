#include "Solution010.h"

std::vector<std::string> Solution010::generateParenthesis(int n)
{
   std::vector<std::string> res;
   if (n == 0)
      res.push_back("");
   else
      for (int i = 0; i < n; i++)
         for (auto& left : generateParenthesis(i))
            for (auto& right : generateParenthesis(n - 1 - i))
               res.push_back("(" + left + ")" + right);
   return res;
}
