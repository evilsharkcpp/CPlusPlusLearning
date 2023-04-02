#include "Solution.h"
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <functional>

bool Solution::isMatch(std::string text, std::string pattern)
{
   size_t m = text.length(), n = pattern.length();
   auto dp = std::vector<std::vector<bool>>(m + 1, std::vector<bool>(n + 1, false));
   dp[m][n] = true;

   for (int i = m; i >= 0; i--)
      for (int j = n - 1; j >= 0; j--)
      {
         bool first_match = (i < m &&
            (pattern[j] == text[i] ||
               pattern[j] == '.'));
         if (j + 1 < n && pattern[j + 1] == '*')
            dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
         else
            dp[i][j] = first_match && dp[i + 1][j + 1];
      }
   return dp[0][0];
}

int Solution::maxArea(std::vector<int>& height)
{
   int maxSquare = 0;
   int left = 0;
   int right = height.size() - 1;
   while (left < right)
   {
      int h = std::min(height[left], height[right]);
      maxSquare = std::max(maxSquare, h * (right - left));
      if (height[left] < height[right])
         left++;
      else
         right--;
   }
   return maxSquare;
}

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs)
{
   if (strs.size() == 1)
      return strs[0];
   std::string currentStr = strs[0];
   for (const auto& str : strs)
   {
      std::string tmp;
      for (int i = 0; i < str.length() && i < currentStr.length(); i++)
         if (str[i] == currentStr[i])
            tmp += str[i];
         else
            break;
      currentStr = tmp;
   }
   return currentStr;
}

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2)
{
   ListNode* root = new ListNode();
   ListNode* res = root;
   while (list1 != nullptr && list2 != nullptr)
   {
      if (list1->val < list2->val)
      {
         root->next = list1;
         list1 = list1->next;
      }
      else
      {
         root->next = list2;
         list2 = list2->next;
      }
      root = root->next;
   }
   if (list1 != nullptr)
      root->next = list1;
   if (list2 != nullptr)
      root->next = list2;
   return res->next;
}

std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums)
{
   std::vector<std::vector<int>> result{};
   std::set<std::vector<int>> s{};
   std::sort(nums.begin(), nums.end());
   for (int i{ 0 }; i < nums.size() - 2 && nums[i] <= 0; i++)
   {
      int left = i + 1;
      int right = nums.size() - 1;
      while (right > left)
      {
         int sum = nums[i] + nums[left] + nums[right];
         if (sum == 0)
         {
            s.insert({ nums[i], nums[left], nums[right] });
            //ignore duplicates of nums[left]
            while (left < right && nums[left] == nums[left + 1]) left++;
            //ignore duplicates of nums[right]
            while (left < right && nums[right] == nums[right - 1]) right--;
            left++;
            right--;
         }
         else
            if (sum > 0)
               right--;
            else
               left++;
         while (i < nums.size() - 2 && nums[i] == nums[i + 1]) i++;
      }
   }
   result.assign(s.begin(), s.end());
   return result;
}

std::vector<std::string> Solution::letterCombinations(std::string digits)
{
   std::queue<std::string> letters{};
   std::map<char, std::string> container{ {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
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

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
   auto startPtr = head;
   auto middlePtr = head;
   auto middleIndex = 0;
   auto size = 0;
   while (startPtr != nullptr)
   {
      startPtr = startPtr->next;
      if (middleIndex++ % 2 == 0)
         middlePtr = middlePtr->next;
      size++;
   }
   auto removeIndex = size - n;
   if (removeIndex == 0)
      return head->next;
   if (removeIndex > middleIndex)
   {
      while (middleIndex++ != removeIndex - 1)
         middlePtr = middlePtr->next;
      auto tmp = middlePtr->next;
      middlePtr->next = tmp->next;
   }
   else
   {
      auto startIndex = 0;
      startPtr = head;
      while (startIndex++ != removeIndex - 1)
         startPtr = startPtr->next;
      auto tmp = startPtr->next;
      startPtr->next = tmp->next;

   }
   return head;
}

bool Solution::isValid(std::string s)
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

ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists)
{
   ListNode* head = {};
   for (auto& list : lists)
   {
      head = mergeTwoLists(list, head);
   }
   return head;
}

std::vector<std::string> Solution::generateParenthesis(int n)
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

int Solution::removeDuplicates(std::vector<int>& nums)
{
   int insertIndex{ 1 };
   for (int i{ 1 }; i < nums.size(); i++)
      if (nums[i - 1] != nums[i])
         nums[insertIndex++] = nums[i];
   return insertIndex;
}

int Solution::strStr(std::string haystack, std::string needle)
{
   for (int i = 0; i < haystack.length(); i++)
   {
      bool isEqual = true;
      for (int k = 0; k < needle.length(); k++)
      {
         if (i + k >= haystack.length())
            return -1;
         if (haystack[i + k] != needle[k])
         {
            isEqual = false;
            break;
         }
      }
      if (isEqual)
         return i;
   }
   return -1;
}

int Solution::search(std::vector<int>& nums, int target)
{
   int start = 0;
   int end = nums.size() - 1;
   int middle = 0;
   while (start <= end)
   {
      middle = start + (end - start) / 2;
      if (nums[middle] == target)
         return middle;
      if (nums[start] <= nums[middle])
      {
         if (target >= nums[start] && target < nums[middle])
            end = middle - 1;
         else
            start = middle + 1;
      }
      else
      {
         if (target <= nums[end] && target > nums[middle])
            start = middle + 1;
         else
            end = middle - 1;
      }
   }
   return -1;
}

int Solution::searchInsert(std::vector<int>& nums, int target)
{
   if (target <= nums.front()) return 0;
   if (target > nums.back()) return nums.size();
   int startIndex{}, endIndex{ (int)nums.size() - 1 }, middleIndex{};
   while (startIndex < endIndex)
   {
      middleIndex = (endIndex + startIndex) / 2;
      if (nums[middleIndex] < target && nums[middleIndex + 1] >= target)
         return middleIndex + 1;
      if (nums[middleIndex] >= target)
         endIndex = middleIndex;
      else
         startIndex = middleIndex;
   }
   return -1;
}

bool Solution::isPalindrome(int x)
{
   if (x < 0 || (x % 10 == 0 && x != 0)) return false;
   int reverseX{};
   while (x > reverseX)
   {
      reverseX = reverseX * 10 + x % 10;
      x /= 10;
   }
   return x == reverseX || x == reverseX / 10;
}

int Solution::projectionArea(std::vector<std::vector<int>>& grid)
{
   int xyArea{};
   std::vector<int> xzProjection{}, yzProjection{};
   for (auto& column : grid)
   {
      if (yzProjection.size() < column.size())
         yzProjection.resize(column.size(), 0);
      int xzMaxArea{};
      int i{ 0 };
      for (auto& row : column)
      {
         if (row != 0) xyArea++;
         yzProjection[i] = std::max(row, yzProjection[i]);
         xzMaxArea = std::max(xzMaxArea, row);
         i++;
      }
      xzProjection.push_back(xzMaxArea);
   }
   int totalArea{ xyArea };
   for (auto& area : xzProjection)
      totalArea += area;
   for (auto& area : yzProjection)
      totalArea += area;
   return totalArea;
}

int Solution::projectionAreaOptimized(std::vector<std::vector<int>>& grid)
{
   int totalArea{};
   for (int i{}; i < grid.size(); i++)
   {
      int xzMax{}, yzMax{};
      for (int j{}; j < grid[i].size(); j++)
      {
         if (grid[i][j] > 0)
            totalArea++;
         xzMax = std::max(xzMax, grid[i][j]);
         yzMax = std::max(yzMax, grid[j][i]);
      }
      totalArea += xzMax + yzMax;
   }
   return totalArea;
}

bool Solution::isRectangleOverlap(std::vector<int>& firstRect, std::vector<int>& secondRect)
{
   int xOverlap{ std::min(firstRect[2], secondRect[2]) - std::max(firstRect[0], secondRect[0]) },
      yOverlap{ std::min(firstRect[3], secondRect[3]) - std::max(firstRect[1], secondRect[1]) };
   return xOverlap > 0 && yOverlap > 0;
}

int Solution::computeArea(int xBottomFirst, int yBottomFirst, int xTopFirst, int yTopFirst,
   int xBottomSecond, int yBottomSecond, int xTopSecond, int yTopSecond)
{
   int xOverlap{ std::min(xTopFirst, xTopSecond) - std::max(xBottomFirst, xBottomSecond) },
      yOverlap{ std::min(yTopFirst, yTopSecond) - std::max(yBottomFirst, yBottomSecond) },
      overlapArea{};

   if (xOverlap > 0 && yOverlap > 0)
      overlapArea = xOverlap * yOverlap;
   return (xTopFirst - xBottomFirst) * (yTopFirst - yBottomFirst) +
      (xTopSecond - xBottomSecond) * (yTopSecond - yBottomSecond) - overlapArea;
}

bool Solution::checkOverlap(int radius, int xCenter, int yCenter,
   int xBottom, int yBottom, int xTop, int yTop)
{
   auto isInside
   {
       [=](int xPoint, int yPoint)
       {
           return (xPoint - xCenter) * (xPoint - xCenter) +
                  (yPoint - yCenter) * (yPoint - yCenter) <= radius * radius;
       }
   };
   return isInside(std::max(xBottom, std::min(xCenter, xTop)),
      std::max(yBottom, std::min(yCenter, yTop)));
}

bool Solution::validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3, std::vector<int>& p4)
{
   auto computeDist
   {
       [](std::vector<int>& p1, std::vector<int>& p2)
       {
           return pow((p2[0] - p1[0]), 2) + pow((p2[1] - p1[1]), 2);
       }
   };
   auto isSquare
   {
       [=](std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3, std::vector<int>& p4)
       {
           return computeDist(p1, p2) > 0 && computeDist(p1, p3) > 0 && computeDist(p1, p4) > 0 &&
           computeDist(p1, p2) == computeDist(p2, p3) && computeDist(p2, p3) == computeDist(p3, p4) &&
           computeDist(p3, p4) == computeDist(p4, p1) && computeDist(p1, p3) == computeDist(p2, p4);
       }
   };
   return isSquare(p1, p2, p3, p4) || isSquare(p1, p3, p2, p4) || isSquare(p1, p2, p4, p3);
}

ListNode* Solution::swapPairs(ListNode* firstHead)
{
   if (firstHead == nullptr || firstHead->next == nullptr)
      return firstHead;
   auto secondHead{ firstHead->next },
      next{ secondHead->next };
   secondHead->next = firstHead;
   firstHead->next = next;
   firstHead = secondHead;
   firstHead->next->next = swapPairs(next);
   return firstHead;
}

int Solution::minTimeToVisitAllPoints(std::vector<std::vector<int>>& points)
{
   auto totalTime{ 0 };
   for (int i{ 1 }; i < points.size(); i++)
   {
      auto dx{ points[i][0] - points[i - 1][0] },
         dy{ points[i][1] - points[i - 1][1] };
      totalTime += std::max(abs(dx), abs(dy));
   }
   return totalTime;
}

int Solution::maxPoints(std::vector<std::vector<int>>& points)
{
   if (points.size() == 1)
      return 1;

   int bestCount{};
   for (auto& p1 : points)
   {
      std::unordered_map<double, int> looksup{};
      for (auto& p2 : points)
      {
         auto dx{ p2[0] - p1[0] },
            dy{ p2[1] - p1[1] };
         if (dx == 0 && dy == 0)
            continue;
         auto k{ atan((double)dy / dx) };
         looksup[k]++;
      }
      for (auto& pair : looksup)
         bestCount = std::max(bestCount, pair.second + 1);
   }
   return bestCount;
}

bool Solution::checkStraightLine(std::vector<std::vector<int>>& coordinates)
{
   auto leftPoint{ coordinates.front() },
      rightPoint{ coordinates.back() };

   auto dx{ (rightPoint[0] - leftPoint[0]) },
      dy{ (rightPoint[1] - leftPoint[1]) };

   for (auto& point : coordinates)
   {
      auto leftPart{ (double)(point[0] - leftPoint[0]) / dx },
         rightPart{ (double)(point[1] - leftPoint[1]) / dy };
      bool isBeenOnAxisX{ ((rightPoint[0] - leftPoint[0]) == 0 && point[0] == leftPoint[0]) },
         isBeenOnAxisY{ ((rightPoint[1] - leftPoint[1]) == 0 && point[1] == leftPoint[1]) };
      if ((!isBeenOnAxisX && !isBeenOnAxisY) && leftPart != rightPart)
         return false;
   }
   return true;
}

bool Solution::checkStraightLineAnother(std::vector<std::vector<int>>& coordinates)
{
   auto leftPoint{ coordinates.front() },
      rightPoint{ coordinates.back() };

   auto dx{ (rightPoint[0] - leftPoint[0]) },
      dy{ (rightPoint[1] - leftPoint[1]) };

   for (auto& point : coordinates)
   {
      auto leftPart{ (double)(point[0] - leftPoint[0]) * dy },
         rightPart{ (double)(point[1] - leftPoint[1]) * dx };
      if (leftPart != rightPart)
         return false;
   }
   return true;
}

int Solution::removeElement(std::vector<int>& nums, int val)
{
   int i{};
   for (auto& num : nums)
      if (num != val)
      {
         nums[i] = num;
         i++;
      }
   return i;
}

int Solution::minAreaRect(std::vector<std::vector<int>>& points)
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

std::vector<int> Solution::countPoints(std::vector<std::vector<int>>& points, std::vector<std::vector<int>>& queries)
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

std::vector<std::vector<int>> Solution::kClosest(std::vector<std::vector<int>>& points, int k)
{
   sort(points.begin(), points.end(),
      [](std::vector<int>& p, std::vector<int>& q)
      {
         return pow(p[0], 2) + pow(p[1], 2) < pow(q[0], 2) + pow(q[1], 2);
      });
   return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
}

int Solution::lengthOfLastWord(std::string s)
{
   int length{};
   for (auto it{ s.rbegin() }; it != s.rend(); it++)
   {
      if (*it == ' ' && length > 0)
         break;
      if (*it == ' ')
         continue;
      length++;
   }
   return length;
}

void Solution::rotate(std::vector<std::vector<int>>& matrix)
{
   size_t n{ matrix.size() };
   for (size_t i{}; i < n / 2; i++)
      for (size_t j{ i }; j < n - i - 1; j++)
      {
         std::swap(matrix[i][j], matrix[j][n - 1 - i]);
         std::swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
         std::swap(matrix[i][j], matrix[n - 1 - j][i]);
      }
}

double Solution::largestTriangleArea(std::vector<std::vector<int>>& points)
{
   auto getSquare
   {
       [](std::vector<int> a, std::vector<int> b, std::vector<int> c)
       {
           std::vector<int> vFirst { b[0] - a[0], b[1] - a[1] },
                       vSecond { c[0] - a[0], c[1] - a[1] };
           return abs(1.0 / 2 * (vFirst[0] * vSecond[1] - vFirst[1] * vSecond[0]));
       }
   };
   double maxSquare{};
   for (int i{}; i < points.size() - 2; i++)
      for (int j{ i + 1 }; j < points.size() - 1; j++)
         for (int k{ j + 1 }; k < points.size(); k++)
            maxSquare = std::max(maxSquare, getSquare(points[i], points[j], points[k]));
   return maxSquare;
}

std::vector<std::vector<int>> Solution::allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
{
   std::vector<std::vector<int>> result;
   std::multimap<int, std::vector<int>> dists;
   for (int row{}; row < rows; row++)
      for (int col{}; col < cols; col++)
         result.push_back({ row, col });
   sort(result.begin(), result.end(),
      [&](std::vector<int>& a, std::vector<int>& b)
      {
         return abs(rCenter - a[0]) + abs(cCenter - a[1]) <
         abs(rCenter - b[0]) + abs(cCenter - b[1]);
      });
   return result;
}

std::vector<std::vector<int>> Solution::permute(std::vector<int>& nums)
{
   std::vector<std::vector<int>> result{};
   if (nums.size() == 1)
      return { nums };
   for (auto& num : nums)
   {
      std::swap(num, nums.front());
      auto out{ std::vector<int>(nums.begin() + 1, nums.end()) };
      auto comb{ permute(out) };
      std::swap(num, nums.front());
      for (auto& item : comb)
      {
         item.insert(item.begin(), num);
         result.push_back(item);
      }

   }
   return result;
}

bool Solution::isBoomerang(std::vector<std::vector<int>>& points)
{
   std::vector<int> a{ points[1][0] - points[0][0], points[1][1] - points[0][1] },
      b{ points[2][0] - points[0][0], points[2][1] - points[0][1] };
   return abs(a[0] * b[1] - a[1] * b[0]) > 0;
}

int Solution::maximumDetonation(std::vector<std::vector<int>>& bombs)
{
   auto isInside
   {
       [](std::vector<int>& bombDetonated, std::vector<int>& bomb)
       {
           return pow(bombDetonated[0] - bomb[0], 2) +
                  pow(bombDetonated[1] - bomb[1], 2) <=
                  pow(bombDetonated[2], 2);
       }
   };
   size_t detonatedMaxCount{};
   std::unordered_set<int> detonatedBombs{};
   for (size_t bombFirstIndex{}; bombFirstIndex < bombs.size(); bombFirstIndex++)
   {
      detonatedBombs.clear();
      detonatedBombs.emplace(bombFirstIndex);
      auto detonatedBomb{ detonatedBombs.begin() };
      while (detonatedBomb != detonatedBombs.end())
      {
         auto previousSize{ detonatedBombs.size() };
         for (size_t bombIndex{}; bombIndex < bombs.size(); bombIndex++)
            if (detonatedBombs.count(bombIndex) == 0 && isInside(bombs[*detonatedBomb], bombs[bombIndex]))
               detonatedBombs.emplace(bombIndex);
         if (previousSize == detonatedBombs.size())
            detonatedBomb++;
         else
            detonatedBomb = detonatedBombs.begin();
      }
      detonatedMaxCount = std::max(detonatedMaxCount, detonatedBombs.size());
   }
   return detonatedMaxCount;
}

int Solution::mirrorReflection(int p, int q)
{
   std::function<int(int, int)> gcd
   {
      [&](int a, int b)
      {
         return b == 0 ? a : gcd(b, a % b);
      }
   };
   int m{ q / gcd(p, q) },
      n{ p / gcd(p, q) };
   switch (m % 2)
   {
   case 0:
      return n % 2 == 1 ? 0 : -1;
      break;
   case 1:
      return n % 2 == 1 ? 1 : 2;
      break;
   }
   return -1;
}

int Solution::minimumLines(std::vector<std::vector<int>>& stockPrices)
{
   std::function<int(int, int)> gcd
   {
      [&](int a, int b)
      {
         return b == 0 ? a : gcd(b, a % b);
      }
   };
   sort(stockPrices.begin(), stockPrices.end());
   if (stockPrices.size() < 2)
      return 0;
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

std::string Solution::addBinary(std::string a, std::string b)
{
   std::string result{};
   int carry{};
   int i{ (int)a.length() - 1 };
   int j{ (int)b.length() - 1 };

   while (i >= 0 || j >= 0 || carry)
   {
      if (i >= 0)
         carry += a[i--] - '0';
      if (j >= 0)
         carry += b[j--] - '0';
      result += carry % 2 + '0';
      carry /= 2;
   }
   reverse(result.begin(), result.end());
   return result;
}

std::vector<int> Solution::plusOne(std::vector<int>& digits)
{
   auto result{ std::vector<int>(digits) };
   for (auto it{ result.rbegin() }; it != result.rend(); it++)
      if (*it == 9)
         *it = 0;
      else
      {
         *it += 1;
         break;
      }
   if (result.front() == 0)
      result.insert(result.begin(), 1);
   return result;
}

int Solution::surfaceArea(const std::vector<std::vector<int>>& grid)
{
   int areaTotal{};
   size_t size{ grid.size() };
   for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
      {
         if (grid[i][j] != 0)
            areaTotal += grid[i][j] * 4 + 2;
         if (i != 0)
            areaTotal -= std::min(grid[i][j], grid[i - 1][j]) * 2;
         if (j != 0)
            areaTotal -= std::min(grid[i][j], grid[i][j - 1]) * 2;
      }
   return areaTotal;
}

int Solution::countLatticePoints(const std::vector<std::vector<int>>& circles)
{
   auto isInside
   {
       [](const std::vector<int>& circle, int x, int y)
       {
           return pow(x - circle[0], 2) + pow(y - circle[1], 2) <= pow(circle[2], 2);
       }
   };
   std::set<std::pair<int, int>> points{};
   std::set<std::vector<int>> seen{};
   for (const auto& circle : circles)
   {
      if (seen.count(circle))
         continue;
      seen.insert(circle);
      int xBottom{ circle[0] - circle[2] },
         yBottom{ circle[1] - circle[2] },
         xTop{ circle[0] + circle[2] },
         yTop{ circle[1] + circle[2] };
      for (auto x{ xBottom }; x <= xTop; x++)
         for (auto y{ yBottom }; y <= yTop; y++)
            if (isInside(circle, x, y))
               points.insert({ x,y });
   }
   return points.size();
}

int Solution::countLatticePointsOptimized(const std::vector<std::vector<int>>& circles)
{
   int xBottom{ std::numeric_limits<int>::max() },
      yBottom{ std::numeric_limits<int>::max() },
      xTop{ std::numeric_limits<int>::min() },
      yTop{ std::numeric_limits<int>::min() };
   for (const auto& circle : circles)
   {
      xBottom = std::min(xBottom, circle[0] - circle[2]);
      yBottom = std::min(yBottom, circle[1] - circle[2]);
      xTop = std::max(xTop, circle[0] + circle[2]);
      yTop = std::max(yTop, circle[1] + circle[2]);
   }
   int counter{};
   for (auto x{ xBottom }; x <= xTop; x++)
      for (auto y{ yBottom }; y <= yTop; y++)
         if (any_of(circles.begin(), circles.end(),
            [&x, &y](const std::vector<int>& circle)
            {
               return pow(x - circle[0], 2) + pow(y - circle[1], 2) <=
               pow(circle[2], 2);
            }))
            counter++;
            return counter;
}

int Solution::climbStairs(int n)
{
   std::vector<int> dp{};
   dp.reserve(n + 1);
   dp.push_back(1);
   dp.push_back(1);
   for (int i{ 2 }; i <= n; i++)
      dp.push_back(dp[i - 1] + dp[i - 2]);
   return dp.back();
}

int Solution::climbStairsOptimizedMemory(int n)
{
   int numberFirst{ 1 }, numberSecond{ 1 }, result{ 1 };
   for (int i{ 2 }; i <= n; i++)
   {
      result = numberFirst + numberSecond;
      numberFirst = numberSecond;
      numberSecond = result;
   }
   return result;
}

int Solution::singleNumber(std::vector<int>& nums)
{
   std::unordered_map<int, size_t> seen{};
   for (const auto& num : nums)
      seen[num]++;
   for (const auto& item : seen)
      if (item.second == 1)
         return item.first;
   return -1;
}

int Solution::singleNumberBitwiseOr(std::vector<int>& nums)
{
   int candidate{};
   for (const auto& num : nums)
      candidate ^= num;
   return candidate;
}

ListNode* Solution::deleteDuplicatesRecursive(ListNode* head)
{
   if (head == nullptr)
      return nullptr;
   if (head->next == nullptr)
      return head;
   ListNode* node{ nullptr };
   if (head->val == head->next->val)
   {
      node = head->next;
      head->next = node->next;
      delete node;
      deleteDuplicatesRecursive(head);
   }
   else
      deleteDuplicatesRecursive(head->next);
   return head;
}

ListNode* Solution::deleteDuplicatesIntoInput(ListNode* head)
{
   auto current{ head };
   while (current != nullptr && current->next != nullptr)
   {
      if (current->val == current->next->val)
      {
         auto node{ current->next };
         current->next = node->next;
         delete node;
      }
      else
         current = current->next;
   }
   return head;
}

ListNode* Solution::deleteDuplicates(ListNode* head)
{
   if (head == nullptr)
      return head;
   auto root{ new ListNode(head->val) };
   auto current{ head }, rootCurrent{ root };
   while (current != nullptr)
   {
      if (current->val != rootCurrent->val)
      {
         rootCurrent->next = new ListNode(current->val);
         rootCurrent = rootCurrent->next;
      }
      current = current->next;
   }
   return root;
}

bool Solution::hasCycle(ListNode* head)
{
   std::unordered_set<ListNode*> seen{};
   while (head != nullptr)
   {
      if (seen.count(head) != 0)
         return true;
      seen.emplace(head);
      head = head->next;
   }
   return false;
}

bool Solution::hasCycleConstantMemory(ListNode* head)
{
   auto fast{ head }, slow{ head };
   while (fast != nullptr && fast->next != nullptr)
   {
      fast = fast->next;
      if (fast != nullptr)
         fast = fast->next;
      slow = slow->next;
      if (fast == slow)
         return true;
   }
   return false;
}

std::vector<int> Solution::inorderTraversalRecursive(TreeNode* root)
{
   std::vector<int> result{};
   std::function<void(TreeNode*)> inOrder
   {
       [&](TreeNode* node)
       {
           if (node == nullptr)
               return;
           inOrder(node->left);
           result.push_back(node->val);
           inOrder(node->right);
       }
   };
   inOrder(root);
   return result;
}

std::vector<int> Solution::inorderTraversal(TreeNode* root)
{
   std::vector<int> result{};
   std::stack<TreeNode*> roots{};
   while (!roots.empty() || root != nullptr)
   {
      if (root != nullptr)
      {
         roots.push(root);
         root = root->left;
      }
      else
      {
         root = roots.top();
         roots.pop();
         result.push_back(root->val);
         root = root->right;
      }
   }
   return result;
}

int Solution::maxProfit(std::vector<int>& prices)
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

std::vector<std::vector<int>> Solution::generate(int numRows)
{
   std::vector<std::vector<int>> result{};
   result.reserve(numRows);
   result.push_back({ 1 });
   for (size_t i{ 1 }; i < numRows; i++)
   {
      std::vector<int> rowNew{};
      rowNew.reserve(i + 1);
      rowNew.push_back(1);
      for (size_t j{ 1 }; j < result[i - 1].size(); j++)
         rowNew.push_back(result[i - 1][j] + result[i - 1][j - 1]);
      rowNew.push_back(1);
      result.push_back(rowNew);
   }
   return result;
}

std::vector<int> Solution::getRow(int rowIndex)
{
   std::vector<int> rowPrevious{ 1 };
   for (size_t i{}; i < rowIndex; i++)
   {
      std::vector<int> row{};
      row.reserve(i + 1);
      row.push_back(1);
      for (size_t j{ 1 }; j < rowPrevious.size(); j++)
         row.push_back(rowPrevious[j] + rowPrevious[j - 1]);
      row.push_back(1);
      rowPrevious = move(row);
   }
   return rowPrevious;
}

bool Solution::isPalindrome(std::string s)
{
   std::string str{};
   for (const auto& ch : s)
   {
      if (ch >= 'A' && ch <= 'Z')
         str += ch - ('Z' - 'z');
      if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
         str += ch;
   }

   auto len{ str.length() };
   for (size_t i{}; i < len / 2; i++)
      if (str[i] != str[len - 1 - i])
         return false;
   return true;
}

void Solution::merge(std::vector<int>& nums1, int m,
   std::vector<int>& nums2, int n)
{
   int i{ m - 1 }, j{ n - 1 },
      k{ m + n - 1 };

   while (i >= 0 && j >= 0)
   {
      if (nums1[i] > nums2[j])
      {
         nums1[k] = nums1[i];
         i--;
         k--;
      }
      else
      {
         nums1[k] = nums2[j];
         j--;
         k--;
      }
   }
   while (j >= 0)
   {
      nums1[k] = nums2[j];
      j--;
      k--;
   }
}

std::vector<double> Solution::SubSolution::randPoint()
{
   std::vector<double> pointRandom(2);
   double r{ sqrt(_uni(_rng)) * _r }, rad{ 2 * PI * _uni(_rng) };
   pointRandom[0] = _x + r * cos(rad);
   pointRandom[1] = _y + r * sin(rad);
   return pointRandom;
}
