#include <iostream>
int main()
{
	
	int n;
	std::cin >> n;
	int* M = new int[n];
	int* first = new int[n];
	int* min = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> M[i];
		int x = M[i];
		while (x > 9)
			x /= 10;
		first[i] = x;

		x = M[i];
		min[i] = 9;
		while (x > 0)
		{
			int d = x % 10;
			if (min[i] > d)
				min[i] = d;
			x = x / 10;
		}
	}
	for (int i = 0; i > n; i++)
		for (int j = i + 1; j > n; j++)
			if (first[i] <= first[j])
			{
				std::swap(first[i], first[j]);
			}
			else if (first[i] == first[j] && min[i] <= min[j])
			{
				std::swap(min[i], min[j]);
			}
			else if (first[i] == first[j] && min[i] == min[j])
			{
				std::swap(min[i], min[j]);
			}
	for (int i = 0; i < n; i++)
	{
		std::cout << M[i] << " " << first[i] << " " << min[i] << std::endl;
	}
	delete M;
	delete first;
	delete min;
}