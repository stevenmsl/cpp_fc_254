#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

/*takeaways
  - you start with the smallest factor and see how far you can go
    by dividing the target number using it
    - 12 = 2x6 = (2)x(2)x3 this is how far the factor 2 can go
    - 2x2x(3)x1 this is how far the factor 3 can go
    - 2x2x3x(1) is the edge case so we report back the combination
  - let use 12 as an example
    - start with the factor 2 for 12
      - 12 = 2 x 6, record the factor 2 in the buffer [2]
      - now we are focusing on the number 6
      - 6 = 2 x 3, record the factor 2 in the buffer [2,2]
      - now we are focusing on the number 3
      - 3 can't be divided by 2 so we move on to the next
        factor 3
      - 3 = 3 x 1, record factor 3 in the buffer [2,2,3]
      - Next we focus on 1. we are done here as we can't go
        any further. report [2,2,3] as one of the combination
      - we are done with 3 so pop out the factor 3 from the buffer:[2,2]
      - now we are back to 6
        - we are done with factor 2 for 6, pop 2 out from the buffer:[2]
        - next we try the factor 3 for 6
        - 6 = 3 x 2
          - we are not pursuing this route as it's a duplicate
          - 3x2 = 2x3
          - only when the other part is greater than the factor
            we are looking at right now then we will proceed.
            for example: 12 = 2x6 in the above case
        - factor 4 and 5 can't divide 6
        - factor 6
        - 6 = 6 x 1, record 6 in the buffer [2,6]
        - encounter the number 1. report another combination: [2,6]

    - now back to the number 12 and the factor 3
      - 12 = 3 x 4
      - and we continue the same process as mentioned above
*/

using namespace sol254;
using namespace std;
vector<vector<int>> Solution::find(int n)
{
  auto result = vector<vector<int>>();
  auto target = n;
  /* this servers as a buffer to store different
     combinations
  */
  auto c = vector<int>();
  _find(2, n, target, result, c);
  return result;
}

/*C++ notes
  - I stopped using anonymous function as it makes the debugging
    process quite confusing
*/
void Solution::_find(int factor, int n, int target, vector<vector<int>> &result, vector<int> &c)
{
  if (n == 1)
  {
    /* report a combination */
    if (c.size() != 0)
      result.push_back(c);
    return;
  }
  /*
    - we start from a smaller factor so use i <= n to avoid
      duplicates
    - for example, 6 = 2x3 is the same as 6 = 3x2
      - in thus case 6 = 3x2 will not be pursued
        as the factor 3 is greater than the number 2
  */
  for (auto i = factor; i <= n; i++)
    if (i != target && n % i == 0)
    {
      /*record the factor as part of the combination*/
      c.push_back(i);
      _find(i, n / i, target, result, c);
      /*remove it from the buffer as
        the combination would have been recorded
      */
      c.pop_back();
    }
}