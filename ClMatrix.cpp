#include "StdAfx.h"

#include "ClMatrix.h"

/*ClMatrix::ClMatrix(int _SizeN, int _SizeM)
{
	SizeN = _SizeN;
	SizeM = _SizeM;
}*/

/*
ClMatrix::~ClMatrix(void)
{
}*/


ClMatrix& ClMatrix::operator=(const ClMatrix& A)
{
	int i,j;
	for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			Max[i][j] = A.Max[i][j];
	return(*this);
}

ClMatrix ClMatrix::operator+(const ClMatrix& A)
{
	int i,j;
	ClMatrix temp(SizeN, SizeM);
	for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			temp.Max[i][j] = A.Max[i][j] + Max[i][j];
	return(temp);
}


ClMatrix ClMatrix::operator-(const ClMatrix& A)
{
	int i,j;
	ClMatrix temp(SizeN, SizeM);
	for(i=0;i<A.SizeN;i++)
		for(j=0;j<A.SizeM;j++)
			temp.Max[i][j] = Max[i][j] - A.Max[i][j];
	return(temp);
}

ClMatrix ClMatrix::operator*(const ClMatrix& A)
{
	int i,j,k;
	ClMatrix temp(SizeN, SizeM);
	for(i=0;i<A.SizeN;i++)
		for(j=0;j<A.SizeM;j++)
			for(k=0;k<A.SizeN;k++)
				temp.Max[i][j] += Max[i][k]*A.Max[k][j];
	return(temp);
}

//--------------------------------------------------------------
/*
ClMatrix ClMatrix::operator+=(const ClMatrix& A)
{
	int i,j;
	for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			Max[i][j] = Max[i][j] + A.Max[i][j];
}

ClMatrix ClMatrix::operator-=(const ClMatrix& A)
{
	int i,j;
	for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			Max[i][j] = Max[i][j] - A.Max[i][j];
}

ClMatrix ClMatrix::operator*=(const ClMatrix& A)
{
	int i,j;
	for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			Max[i][j] = Max[i][j] * A.Max[i][j];
}
*/
//--------------------------------------------------------------

ClMatrix ClMatrix::operator+(int D)
{
	int i,j;
    ClMatrix temp(SizeN, SizeM);
    for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			temp.Max[i][j] = Max[i][j] + D;
	return(temp);
}



ClMatrix ClMatrix::operator-(int D)
{
	int i,j;
    ClMatrix temp(SizeN, SizeM);
    for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			temp.Max[i][j] = Max[i][j] - D;
	return(temp);
}

ClMatrix ClMatrix::operator*(int D)
{
	int i,j;
    ClMatrix temp(SizeN, SizeM);
    for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			temp.Max[i][j] = Max[i][j] * D;
	return(temp);
}

ClMatrix ClMatrix::operator/(int D)
{
	int i,j;
    ClMatrix temp(SizeN, SizeM);
    for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			temp.Max[i][j] = Max[i][j] / D;
	return(temp);
}

void ClMatrix::operator+=(double D)
{
	int i,j;
	for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			Max[i][j] = Max[i][j] + D;
}

void ClMatrix::operator-=(double D)
{
	int i,j;
	for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			Max[i][j] = Max[i][j] - D;
}

void ClMatrix::operator*=(double D)
{
	int i,j;
	for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			Max[i][j] = Max[i][j] * D;
}

void ClMatrix::operator/=(double D)
{
	int i,j;
	for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			Max[i][j] = Max[i][j] / D;
}

int ClMatrix::operator==(ClMatrix A)
{
	int i, j, flag = 1;
	for (i = 0; i < SizeN; i++)
	for (j = 0; j < SizeM; j++)
	if (A.Max[i][j] != Max[i][j])
	{
		flag = 0;
	}
	return(flag);
}

int ClMatrix::operator!=(ClMatrix A)
{
	int i,j,flag=0;
	for(i=0;i<SizeN;i++)
		for(j=0;j<SizeM;j++)
			if (A.Max[i][j]!=Max[i][j])
			{ 
				flag = 1;
			}
	return(flag);
}

/*double& ClMatrix::operator[][](int i, int j)
{ 	
	return(&Max[i][j]);
} */

//----------------------------------------------------------------//Вычисление определителя

void ClMatrix::Resist(int st1, int st2, double D)
{
	int j;
	for(j=0;j<SizeN;j++)
		Max[st1][j]=Max[st1][j]-Max[st2][j]*D;
}

void ClMatrix::SwapStl(int i1, int i2)
{
	double c;
	int i;
	for(i=0;i<SizeN;i++)
	{
		c = Max[i][i1];
		Max[i][i1] = Max[i][i2];
		Max[i][i2] = c;
	}
}


void ClMatrix::Gauss()
{
	double D;
	int i,j,k=1;
	for(i=0;i<SizeN-1;i++)
		for(j=(i+1);j<SizeN;j++)
		{
			if (j!=i)
			{
				k=1;
				if (Max[i][i]==0)
				{
					while (Max[i][i+k]==0)
					{
						k++;
						if (i+k==SizeN) break;
					}
					SwapStl(i,i+k);
				}
				D=Max[j][i]/Max[i][i];
				Resist(j,i,D);
			}
		}
}

double ClMatrix::Det() 
{
	Gauss();
	double determin=1;
	int i,j;
	for(i=0;i<SizeN;i++)
		determin *= Max[i][i];
	return(determin);
}


//-----------------------------------------------------------------------------

double ClMatrix::Det(int ii, int jj) 
{
	Gauss();
	double determin=1;
	int i,j;
	for(i=0;i<SizeN;i++)
		if ((i!=ii) || (i!=jj))  determin *= Max[i][i]; 
	return(determin);
}



ClMatrix ClMatrix::ReturnMat() //Вычисление обратной матрицы
{
	ClMatrix temp(SizeN, SizeM);
	int i,j;
	for(i=0;i<SizeN-1;i++)
		for(j=0;j<SizeN;j++)
			temp.Max[i][j]=Det(i,j) / Det();
	return(temp);
}

//-----------------------------------------------------------------------------
	

void ClMatrix::TrMax()     //Вычисление транспонированной матрицы
{
	double temp;
	int i,j;
	for(i=0;i<SizeN;i++)
		for(j=i+1;j<SizeM;j++)
		{
			temp = Max[i][j];
			Max[i][j] = Max[j][i];
			Max[j][i] = temp;
	    }
}