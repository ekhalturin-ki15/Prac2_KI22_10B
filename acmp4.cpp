#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <random>

#include <fstream>

#ifndef _DEBUG
	#include <bits/stdc++.h>
#endif

using namespace std;
#define ALL(v) v.begin(), v.end()
typedef  long long ll;

template<class T>
using pi = pair<T, T>;

template<class T>
using p3 = tuple<T, T, T>;

template<class T>
using matrix = vector<vector<T>>;
#define ENDL cout <<"\n"

typedef vector<ll> vi;

//input file stream
ifstream fcin;
ofstream fcout;

constexpr int SIZE = 4;


struct Rand
{
	int iSeed; // Глобал переменные
	const int A; // Оно неизмен
	//constexpr int A нельзя исп, так как на момент комп. значение не изв
	const int C;
	const int M;

	Rand(int _A, int _C, int _M) 
		: A(_A), C(_C), M(_M)
	{
		iSeed = time(0);
	}

	int Get()
	{
		//Конгуэрентный ген. случ чисел
		int iRet = (iSeed * A + C) % M;
		iSeed = iRet;
		return iRet;
	}
};


void RandomGen(int* ptrAnswer, Rand& fRand)
{
	for (int i = 0; i < SIZE; ++i)
	{
		ptrAnswer[i] = fRand.Get();
	}



}



void solve()
{
	fcin.open("input.txt");
	fcout.open("output.txt");

	int arrPlayer[SIZE];
	int arrAnswer[SIZE];
	
	Rand fRand(11, 22, 107);
	// рандомная генерация
	RandomGen(arrAnswer, fRand);



}




int main()
{
	solve();
	//__ctrdumpmemoryleak
}