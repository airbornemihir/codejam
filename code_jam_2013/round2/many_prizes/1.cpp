// many_prizes.cpp : Defines the entry point for the console application.
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


FILE *fin, *fout;

unsigned long int bzzt(unsigned int N,
		       unsigned long int P,
		       unsigned long int largest_group_size) {
  unsigned long int group_size = largest_group_size;
  unsigned int matches_won = 0;
  unsigned int temp1 = 1;
  while (group_size > P) {
    group_size = group_size / 2;
    matches_won += 1;
    temp1 = temp1 * 2;
  }
  return (largest_group_size - temp1);
}

void dotestcase(unsigned int i1) {
  unsigned int N;
  unsigned long int P;
  fscanf(fin, "%u", &N);
  fscanf(fin, "%lu", &P);

  unsigned long int largest_group_size = 1;
  for (unsigned int i2 = 0; i2 < N; ++i2) {
    largest_group_size = largest_group_size * 2;
  }

  fprintf(fout,
	  "Case #%u: %lu %lu\n",
	  1 + i1,
	  largest_group_size - 2 -
	  bzzt(N,
	       largest_group_size - P,
	       largest_group_size),
	  bzzt(N, P, largest_group_size));
}

int _tmain(int argc, _TCHAR* argv[])
{
  fin = fopen("input.txt", "r");
  fout = fopen("output.txt", "w");
  unsigned int T;
  fscanf(fin, "%u", &T);
  for (unsigned int i1 = 0; i1 < T; ++i1) {
    dotestcase(i1);
  }
  fclose(fout);
  fclose(fin);
  return 0;
}

