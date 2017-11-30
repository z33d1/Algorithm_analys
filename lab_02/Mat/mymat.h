#ifndef MYMAT_H
#define MYMAT_H

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Err { };

template <typename T>
unsigned long int classicMatMult(const vector<vector<T> >&, const vector<vector<T> >&);
template <typename T>
unsigned long int VinogradMatMult(const vector<vector<T> >&, const vector<vector<T> >&);
template <typename T>
unsigned long int betterVinogradMatMult(const vector<vector<T> >&, const vector<vector<T> >&);

template <typename T>
void randFill(vector<vector<T> >&, const int, const int);
template <typename T>
void matClr(vector<vector<T> >& mat);

#endif // MYMAT_H
