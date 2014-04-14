#include <iostream>
#include <cstdio>

int main() {
  unsigned int T;
  std::cin >> T;
  for (unsigned int i1 = 1; i1 <= T; ++i1) {
    double C, F, X;
    std::cin >> C >> F >> X;
    double duration = 0.0, rate;
    for (rate = 2.0; (X / rate) > ((C / rate) + (X / (rate + F))); rate += F) {
      duration += C / rate;
    }
    duration += X / rate;
    printf("Case #%u: %.7f\n", i1, duration);
  }

  return 0;
}
