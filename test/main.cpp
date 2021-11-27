#include <iostream>
#include <iomanip>
//#include <Windows.h>
#include <fstream>
using namespace std;

int ffor(double, double, double);
int fwhile(double, double, double, double Eps = 0.000000000005);
void testing();

int main()
{
	int counter = 0, maxRez = 0;
	//ofstream fout("log.txt");
	//for (int i = 0; i < 100; i++)
	//	for (int j = 0; j < 100; j++)
	//		for (int z = 0; z < 100; z++)
	//		{
	//			//cout << "iter: " << i << " " << j << " " << z << " rez: " << ffor(i, j, z) << endl;
	//			maxRez = max(maxRez, ffor(i, j, z));
	//			if (ffor(i, j, z) != fwhile(i, j, z))
	//			{
	//				cout << "wrong answer: " << i << " " << j << " " << z << endl;
	//				counter++;
	//			}
	//		}
	//cout << " count of wrong answ.: " << counter
	//	<< " max of el: " << maxRez << endl;

	//cout << ffor(1, 2, 9);
	testing();

	return 0;
}

void testing()
{
	bool flag = true;
	double eps;
	for (eps = 0.000000000000005; eps < 0.000000000005;)
	{
		flag = true;
		/*cout << "##############################\n eps: " <<
			fixed << setprecision(16) << eps << endl;*/
		for (int i = 0; i < 100 && flag; i++)
		{
			for (int j = 0; j < 100 && flag; j++)
			{
				for (int z = 0; z < 100 && flag; z++)
				{
					if (z % 10 == 0)
					{
						/*cout << "iter: " << i << " " << j << " " << z
							<< " rez: " << fwhile(i, j, z, eps)
							<< " eps: " << setprecision(16) << eps << endl;*/
					}
					int rez = fwhile(i, j, z, eps);
					if (rez > 100 || rez != ffor(i, j, z))
					{
						flag = false;
						/*cout << "error "<<((fwhile(i, j, z, eps) > 100) ? " first\n" : " second\n");
						cout << "iter: " << i << " " << j << " " << z
							<< " rez: " << fwhile(i, j, z, eps) << endl;*/
					}
				}
			}
		}
		eps += eps * 1 / 100;
		system("cls");
		cout << "eps: " << fixed << setprecision(20) << eps << endl;
	}
}

int ffor(double A, double B, double N)
{
	//cout << "\tFFOR\n";
	double h = 0;
	double x;
	double Fx;
	double Gx;
	int i;

	if (A > B)
		return 1;

	if (A != B)
	{
		if (N <= 0)
			return 2;
		h = (B - A) / N;
	}
	else
	{
		N = 0;
		h = 0;
	}

	x = A;
	for (i = 0; i <= N; i++)
	{
		x = A + i * h;
		Fx = sqrt(x * x + 4);
		Gx = 4 * exp(abs(x)) - 1;
		//cout << "i: " << i << " x: " << x << " fx: " << Fx << " gx: " << Gx << endl;
	}
	return i;
}

int fwhile(double A, double B, double N, double Eps)
{
	//cout << "\tFWHILE\n";
	double h = 0;
	double x;
	double Fx;
	double Gx;
	double razn;
	//double Eps;
	bool isStop;
	//Eps = 0.000000000005;//0.000000000005
	isStop = false;

	if (A > B)
		return 1;

	if (A != B)
	{
		if (N <= 0)
			return 2;
		h = (B - A) / N;
	}

	x = A;
	int i = 0;
	while (!isStop)
	{
		razn = abs(B - x);
		//cout << "razn: " << razn << endl;
		isStop = razn < Eps;
		Fx = sqrt(x * x + 4);
		Gx = 4 * exp(abs(x)) - 1;
		//cout << "i: " << i << " x: " << x << " fx: " << Fx << " gx: " << Gx << endl;
		x += h;
		i++;
		if (i > 100) return i;
	}
	return i;
}