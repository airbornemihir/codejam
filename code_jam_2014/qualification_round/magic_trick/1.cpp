#include <iostream>
#include <set>
#include <vector>
typedef std::set<unsigned int> SU;
typedef std::vector<SU> VSU;

int main() {
  unsigned int T;
  std::cin >> T;
  for (unsigned int i1 = 1; i1 <= T; ++i1) {
    VSU a[2];
    unsigned int ia[2];
    for (unsigned int i2 = 1; i2 <= 2; ++i2) {
      a[i2 - 1] = VSU(4);
      std::cin >> ia[i2 - 1];
      for (unsigned int i3 = 1; i3 <= 16; ++i3) {
        unsigned int temp1;
        std::cin >> temp1;
        a[i2 - 1][(i3 - 1) / 4].insert(temp1);
      }
    }
    SU common;
    for (unsigned int i3 = 1; i3 <= 16; ++i3) 
      if (a[0][ia[0] - 1].find(i3) != a[0][ia[0] - 1].end() &&
          a[1][ia[1] - 1].find(i3) != a[1][ia[1] - 1].end())
        common.insert(i3);
    
    std::cout << "Case #" << i1 << ": ";
    if (common.size() <= 0)
      std::cout << "Volunteer cheated!";
    else if (common.size() <= 1)
      std::cout << *(common.begin());
    else
      std::cout << "Bad magician!";
    std::cout << std::endl;
  }
  return 0;
}
