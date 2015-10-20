#pragma once
#include "iostream"
using namespace std;

class ClMatrix
{
	int SizeN, SizeM;
	double **Max;

	void Gauss();
	void SwapStl(int i1, int i2);
	void Resist(int st1, int st2, double D);

public:
	ClMatrix(int _SizeN=100, int _SizeM=100)
	{
		int i=0,j=0;
		Max = new double*[_SizeN];
		for(i=0;i<_SizeN;i++)
		   Max[i] = new double[_SizeM];
		for(i=0;i<_SizeN;i++)
			for(j=0;j<_SizeM;j++)
				Max[i][j] = 0;
		SizeN=_SizeN;
		SizeM=_SizeM;
	}

	~ClMatrix()
	{ 
		for(int i=0; i<SizeN;i++)
			delete[] Max[i];
		delete[] Max; 
	}

	friend ostream& operator<<(ostream& os, ClMatrix A)    //!!!!!!!!!!!!
	{
		int i,j;
	       for(i=0;i<A.SizeN;i++)
	       {
	           for(j=0;j<A.SizeM;j++)
		       {
				   os << A.Max[i][j] << ' ';
		       }
			   os << endl;
	       }
		return(os);
	}
	friend istream& operator>>(istream& is, ClMatrix& A)   //!!!!!!!!!!!!
	{
		int i,j;

	       for(i=0;i<A.SizeN;i++)
	       {
	           for(j=0;j<A.SizeM;j++)
		       {
			       is >> A.Max[i][j];
		       }
	       }
		return(is);
	}


	ClMatrix operator+(const ClMatrix& A); 
	ClMatrix operator-(const ClMatrix& A);
	ClMatrix operator*(const ClMatrix& A);

	ClMatrix operator+=(const ClMatrix& A); 
	ClMatrix operator-=(const ClMatrix& A);
	ClMatrix operator*=(const ClMatrix& A);

	ClMatrix operator+(int D);
	ClMatrix operator-(int D);
	ClMatrix operator*(int D);
	ClMatrix operator/(int D);
	void operator+=(double D);
	void operator-=(double D);
	void operator*=(double D);
	void operator/=(double D);

	ClMatrix& operator=(const ClMatrix& A);        //Здесь что-то не так 

	int operator==(ClMatrix A);

	int operator!=(ClMatrix A);
/*	double& operator[][](int i, int j);     //!!!!!!!!!!!!!!!! */

	//Конструктор копирования                  //НЕ РАБОТАЕТ, ТОЧНЕЙ НЕ ЗНАЮ КАК РАБОТАЕТ!
	ClMatrix (const ClMatrix& c)
	{
		SizeN = c.SizeN;
		SizeM = c.SizeM;
		int i,j;
		Max = new double*[SizeN];
		for(i=0;i<SizeN;i++)
		   Max[i] = new double[SizeM];
		for(i=0;i<SizeN;i++)
			for(j=0;j<SizeM;j++)
				Max[i][j] = c.Max[i][j];
	}

	double Det();         //Вычисление определителя            
	ClMatrix ReturnMat(); //Вычисление обратной матрицы          //НЕ РАБОТАЕТ!
	void TrMax();     //Вычисление транспонированной матрицы

	double Det(int ii, int jj);


};
