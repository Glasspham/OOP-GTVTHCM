#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <vector>
using namespace std;
// Nhap cac mon do
void enter(int &n, int &W, vector<pair<int, int>> &items);
// dat co cac mon do da thu qua
void trace_back(int n, int W, vector<vector<int>> &dp, vector<pair<int, int>> &items);
// Giai phap tim cac mon do toi uu
void solution(int n, int W, vector<pair<int, int>> &items);
#endif