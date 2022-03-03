// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <iostream>


double pown(double value, uint16_t n) {
  int t = value;
  for (int i = 1; i < n; i++)
    value *= t;
  return value;
}

uint64_t fact(uint16_t n) {
  int res = 1;
  for (int i = 1; i<= n; i++){
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  double res = (pown(x, n) / fact(n));
  return res;
}

double expn(double x, uint16_t count) {
  double res = 0;
  for (uint16_t n = 0; n <= count; n++)
    res += pown(x, n) / fact(n);
  return res;
}

double sinn(double x, uint16_t count) {
  double s = 0;
  for (uint16_t i = 1; i <= count; i++) {
    int n = (2 * i) - 1;
    s = s + (pown(-1, (i - 1)) * calcItem(x, n));
  }
  return s;
}

double cosn(double x, uint16_t count) {
  double c = 0;
  for (uint16_t i = 1; i <= count; i++) {
    int n = (2 * i) - 2;
    c = c + (pown(-1, (i - 1)) * calcItem(x, n));
  }
  return c;
}

int main() {
  std::cout<<pown(3, 2)<<std::endl;
  std::cout<<fact(5)<<std::endl;
  std::cout<<calcItem(3, 4)<<std::endl;
  std::cout<<expn(1, 2)<<std::endl;
  std::cout<<sinn(0, 3)<<std::endl;
  std::cout<<cosn(1, 5)<<std::endl;
}
