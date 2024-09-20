#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <unordered_map>
#include <random>
#include <stdexcept>

#include <fstream>

#include <Windows.h> // чистый си //API ОС, на что руг антивирус

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


namespace RED
{
	constexpr int SIZE = 4;
};


struct Rand
{
	int iSeed; // Глобал переменные
	const int A; // Оно неизмен
	//constexpr int A нельзя исп, так как на момент комп. значение не изв
	const int C;
	const int RealM;
	const int M; // Простое число лучше

	Rand(int _A, int _C, int _M, int _RealM)
		: A(_A), C(_C), M(_M), RealM(_RealM)
	{
		iSeed = time(0);
	}

	int Get()
	{
		//Конгуэрентный ген. случ чисел
		int iRet = (iSeed * A + C) % M;
		iSeed = iRet;
		return iRet % RealM;
	}
};


void RandomGen(int* ptrAnswer, Rand& fRand)
{
	for (int i = 0; i < RED::SIZE; ++i)
	{
		ptrAnswer[i] = fRand.Get();
	}
}


void GameLoop(int* ptrAnswer)
{
	int arrPlayer[RED::SIZE];

	while (true)
	{
		

		bool isCorrect = true;
		do
		{
			isCorrect = true;
			cout << "Введите 4 числа (от 0 до 9) для угадайки: ";
			cout << "\n";
			try
			{
				for (int i = 0; i < RED::SIZE; ++i)
				{
					int iChoose;
					cin >> iChoose;
					if ((iChoose < 0) || (iChoose > 9))
					{
						isCorrect = false;
					}
					arrPlayer[i] = iChoose;
				}

				if (!isCorrect)
				{
					throw out_of_range("Negativ num");
				}

				//Перенести всё в метод
				//return
			}
			catch (...) // Отлавливание ошибки
			{
				cout << "Одна ошибка, и ты ошибся";
				cout << "\n";
				isCorrect = false;
			}
		} while (!isCorrect);



		int iCow = 0;
		int iNoCow = 0;


		set<int> setCounting;
		for (int i = 0; i < RED::SIZE; ++i)
		{
			setCounting.insert(ptrAnswer[i]);
		}


		for (int i = 0; i < RED::SIZE; ++i)
		{
			if (arrPlayer[i] == ptrAnswer[i])
			{
				++iNoCow;
				continue;
			}
			
			if (setCounting.count(arrPlayer[i]))
			{
				++iCow;
			}
		}

		if (iNoCow == RED::SIZE)
			break;


		cout << "Всего " << iNoCow << " Быков ";
		cout << "\n";
		cout << "И " << iCow << " Коров ";
		cout << "\n";

	}

	cout << "Победа";
	string s;
	getline(cin, s);

}


void solve()
{
	fcin.open("input.txt");
	fcout.open("output.txt");

	int arrAnswer[RED::SIZE];
	
	Rand fRand(11, 22, int(1e4+7), 10);
	// рандомная генерация
	RandomGen(arrAnswer, fRand);

	GameLoop(arrAnswer);
}




int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода



	solve();
	//__ctrdumpmemoryleak
}