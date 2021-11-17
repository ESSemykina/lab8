#include <iostream>
#include <fstream>
#define N  100
#define M  100
int main()
{
	std::ifstream in("input.txt");

	int** matrix = new int*[N];
	for (int i = 0; i < N; i++)
		matrix[i] = new int[M];
	
	int	min;
	int min2;
	int sum = 0;
	min = INT_MAX;
	int n, m;
	in >> n >> m;

	// Ввод
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			in >> matrix[i][j];


	// Обработка
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum = sum + matrix[i][j];
		}
		if (sum < min)
		{
			min = sum;
			min2 = i;
			sum = 0;
		}
		sum = 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (i == min2)
		{
			for (int j = 0; j < m; j++)
			{
				matrix[i][j] = min;
			}
		}
	}


	// Вывод
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}


	for (int i = 0; i < N; i++)
		delete[] matrix[i];

	delete[] matrix;

	


}
