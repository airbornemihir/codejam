// ticket_swapping.cpp : Defines the entry point for the console application.
//

#include <cstdio>

typedef struct horde {
  unsigned long int o;
  unsigned long int e;
  unsigned long int p;
} horde;

#include <cassert>

#include <map>
typedef std::multimap<unsigned long int, horde> station_map;

#include <stack>
typedef std::stack<horde> horde_stack;
#define MOD_BASE 1000002013

FILE *fin, *fout;

void dotestcase(unsigned long int i1) {
  int N, M;
  fscanf(fin, "%u", &N);
  fscanf(fin, "%u", &M);
  station_map o_map, e_map;
  unsigned long int legal_total = 0, illegal_total = 0;
  for (unsigned long int i2 = 0; i2 < M; ++i2) {
    horde current;
    fscanf(fin, "%lu", &current.o);
    fscanf(fin, "%lu", &current.e);
    fscanf(fin, "%lu", &current.p);

    legal_total += (current.p *
		    ((((current.e - current.o) *
		       (N + N - current.e + current.o + 1)) / 2) % MOD_BASE)) % MOD_BASE;
    if (legal_total >= MOD_BASE)
      legal_total = legal_total - MOD_BASE;
    assert(legal_total < MOD_BASE);
    
    o_map.insert(station_map::value_type(current.o, current));
    e_map.insert(station_map::value_type(current.e, current));
  }
  // input done.
  horde_stack o_stack;
  station_map::iterator i4 = o_map.begin();
  for (station_map::iterator i3 = e_map.begin(); i3 != e_map.end(); ++i3) {
    unsigned long int e = i3->first;
    horde &current = i3->second;
    while (i4 != o_map.end() && i4->first <= e) {
      o_stack.push(i4->second);
      ++i4;
    }
    // pushed everything we could push
    while (current.p > 0) {
      horde &stack_next = o_stack.top();
      if (stack_next.p > current.p) {
	stack_next.p = stack_next.p - current.p;
	illegal_total += (current.p * ((((current.e - stack_next.o) *
					 (N + N - current.e + stack_next.o + 1)) / 2) % MOD_BASE)) % MOD_BASE;
	current.p = 0;
      } else {
	current.p = current.p - stack_next.p;
	illegal_total += (stack_next.p * ((((current.e - stack_next.o) *
					    (N + N - current.e + stack_next.o + 1)) / 2) % MOD_BASE)) % MOD_BASE;
	stack_next.p = 0;
	o_stack.pop();
      }
      if (illegal_total >= MOD_BASE)
	illegal_total = illegal_total - MOD_BASE;
      assert(illegal_total < MOD_BASE);
    }
  }
  unsigned long int temp1;
  if (legal_total >= illegal_total)
    temp1 = legal_total - illegal_total;
  else
    temp1 = (MOD_BASE + legal_total) - illegal_total;
  fprintf(fout, "Case #%lu: %lu\n", 1 + i1, temp1);
}

int main()
{
  // fin = fopen("input.txt", "r");
  // fout = fopen("output.txt", "w");
  fin = stdin; fout = stdout;
  unsigned long int T;
  fscanf(fin, "%lu", &T);
  for (unsigned long int i1 = 0; i1 < T; ++i1) {
    dotestcase(i1);
  }
  // fclose(fout);
  // fclose(fin);
  return 0;
}

