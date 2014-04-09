#include <iostream>
#include <vector>
typedef std::vector<unsigned long long int> VU;
#define FLORENTINE (9)
#include <string>

unsigned long long int count01
(VU &v,
 VU &lower_limit,
 VU &upper_limit,
 unsigned long long int first_empty_index,
 unsigned long long int sum_so_far) {
  unsigned long long int result(0);
  if (sum_so_far <= FLORENTINE) {
    unsigned long long int n(v.size());
    for (unsigned long long int i1 = 0; i1 < 10; ++i1) {
      v[first_empty_index] = i1;
      if ((first_empty_index + 1 >= n) &&
	  ((sum_so_far + i1 * i1) <= FLORENTINE)) {
      }
      if (first_empty_index + 1 >= n) {
	bool lower_limit_check = (lower_limit.size() <= 2 * n - 1);
	if (lower_limit_check && (lower_limit.size() >= 2 * n - 1)) {
	  unsigned long long int i2 = 0;
	  for (;
	       (i2 < 2 * n - 1) &&
		 (v[i2 < n ? i2 : 2 * n - 2 - i2] == lower_limit[i2]);
	       ++i2);
	  // std::cout << "i2 = " << i2 << std::endl;
	  lower_limit_check =
	    (i2 >= 2 * n - 1) ||
	    (v[i2 < n ? i2 : 2 * n - 2 - i2] >= lower_limit[i2]);
	}
	bool upper_limit_check = (upper_limit.size() >= 2 * n - 1);
	if (upper_limit_check && (upper_limit.size() <= 2 * n - 1)) {
	  unsigned long long int i2 = 0;
	  for (;
	       (i2 < 2 * n - 1) &&
		 (v[i2 < n ? i2 : 2 * n - 2 - i2] == upper_limit[i2]);
	       ++i2);
	  // std::cout << "i2 = " << i2 << std::endl;
	  upper_limit_check =
	    (i2 >= 2 * n - 1) ||
	    (v[i2 < n ? i2 : 2 * n - 2 - i2] <= upper_limit[i2]);
	}
	if (lower_limit_check &&
	    upper_limit_check &&
	    ((sum_so_far + i1 * i1) <= FLORENTINE)) {
	  result += 1;
	  // std::cout << "result += 1 for ";
	}
	// for (unsigned long long int i2 = 0; i2 < n; ++i2) 
	//   std::cout << v[i2];
	// std::cout << std::endl;
      } else
	result +=
	  count01(v,
		  lower_limit,
		  upper_limit,
		  first_empty_index + 1,
		  sum_so_far + 2 * i1 * i1);
    }

  }
  return result;
}

VU transform01(std::string &s) {
  VU v(s.size());
  for (unsigned long long int i1 = 0; i1 < s.size(); ++i1) {
    v[i1] = std::stoull (s.substr(i1, 1));
    // std::cout << v[i1];
  }
  // std::cout << std::endl;
  return v;
}

int main() {
  {
    unsigned long long int T;
    std::cin >> T;
    for (unsigned long long int test_case = 1; test_case <= T; ++test_case) {
      std::string s;
      std::cin >> s;
      VU lower_limit = transform01(s);
      std::cin >> s;
      VU upper_limit = transform01(s);
      unsigned long long int result = 0;
      for (unsigned long long int i1 = lower_limit.size(); i1 <= upper_limit.size(); ++i1) {
	VU v(i1);
	for (unsigned long long int i2 = 1; i2 <= 9; ++i2) {
	  v[0] = i2;
	  result +=
	    count01(v,
		    lower_limit,
		    upper_limit,
		    0,
		    i1 <= 1 ? (i2 * i2): (2 * i2 * i2));
	}
      }
      std::cout << "Case #" << test_case << ": " << result << std::endl;
    }
  }
  return 0;
}
