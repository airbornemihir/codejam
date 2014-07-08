// cheaters.cpp : Defines the entry point for the console application.
//

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <cstdio>
#include <tchar.h>

// TODO: reference additional headers your program requires here
#include <cassert>

#include <set>
typedef std::multiset<unsigned long int> ulint_multiset;

#include <vector>
typedef std::vector<unsigned long int> ulint_vector;

#define SLOTS 37

FILE *fin, *fout;

void dotestcase(unsigned int i1) {

  unsigned long int B;
  unsigned int N;
  fscanf(fin, "%lu", &B);
  fscanf(fin, "%u", &N);
  // 1 <= N <= 37
  ulint_multiset temp1;
  for (unsigned int i2 = 0; i2 < N; ++i2) {
    unsigned long int temp2;
    fscanf(fin, "%lu", &temp2);
    temp1.insert(temp2);
  }
  ulint_vector their_money;
  for (unsigned int i2 = N; i2 < SLOTS; ++i2) {
    their_money.push_back(0);
  }
  for (ulint_multiset::iterator i2 = temp1.begin(); i2 != temp1.end(); ++i2) {
    their_money.push_back(*i2);
  }
  assert(their_money.size() == SLOTS);
  //at this point, their_money has all the bets in sorted order. There
  //might, however, still be no slots with a zero bet on them. Our
  //next task is to ensure at least one has a zero bet by subtracting
  //the minimum from each.
  unsigned long int temp2 = their_money[0];
  for (unsigned int i2 = 0; (temp2 > 0) && (i2 < SLOTS); ++i2) {
    their_money[i2] = their_money[i2] - temp2;
  }

  for (unsigned int i2 = 1; i2 <= SLOTS; ++i2) {
    //binary search
    unsigned int high, low;
    high = B;
    low = 0;
    while (high - low > 1) {
      bool insufficiency = false;
      for (unsigned int i3 = 0; i3 < SLOTS && their_money; ++i3)
    }
  }
  fprintf(fout, "Case #%u: %f\n", 1 + i1, 0.0);
}

int _tmain(int argc, _TCHAR* argv[])
{
  fin = fopen("input.txt", "r");
  fout = fopen("output.txt", "w");

  unsigned int T;
  for (unsigned int i1 = 0; i1 < T; ++i1) {
    dotestcase(i1);
  }

  fclose(fout);
  fclose(fin);
  return 0;
}

