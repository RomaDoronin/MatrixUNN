// Matrix.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "ClMatrix.h"
#include "iostream"
#include "fstream"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	double F;

	ClMatrix a(3,3), b(3,3), c(3,3);

	ifstream ifs("file.txt");

	ifs >> a;

	ifs.close();

	cin >> b;

	cout << endl << a << endl;

	c = a * b;

	cout << "a * b = "  << endl << c << endl;

	c.TrMax();

	cout << "с“ = " << endl << c << endl;

	c*=10;

	cout << "c*10 = " << endl << c;

	ofstream ofs("file.txt");

	ofs << a;

	ofs.close();

	return 0;
}

