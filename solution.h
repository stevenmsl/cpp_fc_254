#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol254
{

  class Solution
  {
  private:
    static void _find(int factor, int n, int target, vector<vector<int>> &result, vector<int> &c);

  public:
    static vector<vector<int>> find(int n);
  };
}
#endif