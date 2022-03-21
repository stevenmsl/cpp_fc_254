#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol254;

/* Example 1:
Input: 1
Output: []
*/
tuple<int, vector<vector<int>>>
testFixture1()
{
  auto fc = vector<vector<int>>(0);
  return make_tuple(1, fc);
}

/* Example 2:
Input: 37
Output:[]
*/
tuple<int, vector<vector<int>>>
testFixture2()
{
  auto fc = vector<vector<int>>(0);
  return make_tuple(37, fc);
}

/*Example 3
Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
*/
tuple<int, vector<vector<int>>>
testFixture3()
{
  auto fc = vector<vector<int>>{{2, 6},
                                {2, 2, 3},
                                {3, 4}};
  return make_tuple(12, fc);
}

/*Example 4
Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/
tuple<int, vector<vector<int>>>
testFixture4()
{
  auto fc = vector<vector<int>>{{2, 16},
                                {2, 2, 8},
                                {2, 2, 2, 4},
                                {2, 2, 2, 2, 2},
                                {2, 4, 4},
                                {4, 8}};
  return make_tuple(32, fc);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << Util::toString(get<1>(f)) << endl;
  auto result = Solution::find(get<0>(f));
  cout << "result: " << Util::toString(result) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << Util::toString(get<1>(f)) << endl;
  auto result = Solution::find(get<0>(f));
  cout << "result: " << Util::toString(result) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - exepct to see " << Util::toString(get<1>(f)) << endl;
  auto result = Solution::find(get<0>(f));
  cout << "result: " << Util::toString(result) << endl;
}
void test4()
{
  auto f = testFixture4();
  cout << "Test 4 - exepct to see " << Util::toString(get<1>(f)) << endl;
  auto result = Solution::find(get<0>(f));
  cout << "result: " << Util::toString(result) << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}