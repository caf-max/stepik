#include <iostream>
#include <vector>


int main(void) {
  int n, k = 1;
  std::vector<int> result;

  std::cin >> n;

  while(true) {
    n -= k;
    if (n >= 0) {
      result.push_back(k++);
    }
    else {
      result[k - 2] = n + k+k-1;
      break;
    }
  }

  std::cout << result.size() << " ";//std::endl;
  for (int r : result) {
    std::cout << r << " ";
  }
  std::cout << std::endl;

  return 0;
}
