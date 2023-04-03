#include "Solution008.h"
#include <map>
#include <stack>

bool Solution008::isValid(std::string s)
{
   std::map<char, char> brackets{ {')', '('}, {'}', '{'}, {']', '['} };
   std::stack<char> st{};
   for (auto& ch : s)
   {
      switch (ch)
      {
      case '(':
      case '{':
      case '[':
         st.push(ch);
         break;
      case ')':
      case '}':
      case ']':
         if (!st.empty() && st.top() == brackets[ch])
            st.pop();
         else
            return false;
         break;
      default:
         return false;
         break;
      }
   }
   return st.empty();
}
