#include "Solution054.h"

int Solution054::titleToNumber(std::string columnTitle)
{
   int result{}, degree{ (int)columnTitle.size() - 1 };
   for (const auto& ch : columnTitle)
      result += (ch - 'A' + 1) * pow(26, degree--);
   return result;
}
