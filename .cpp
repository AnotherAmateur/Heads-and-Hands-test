#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>


const int N = 15;					// Кол-во генерируемых массивов
const int ARRAYS_MAX_SIZE = 25;				// Максимальный размер массивов


std::vector<int>* arrays_creation_sorting(int n)	// Функция генерирует массивы и сортирует их в соответствии с требуемым порядком
{

	srand(time(NULL));

	std::vector<int>* array_ofArrays = new std::vector<int>[n];	// Объявление массивов

	for (int i = 0; i < n; i++)					// Заполнение массивов случайными числами
	{

		int rand_number = rand() % ARRAYS_MAX_SIZE + 1;

		array_ofArrays[i].reserve(rand_number);			// Предварительное выделение необходимой памяти под элементы вектора

		for (int j = 0; j < rand_number; j++)
		{
			array_ofArrays[i].push_back(rand());
		}

	}

	for (int i = 0; i < n; i++)					// Сортировка массивов методом sort() из файла algorithm
	{		
		(i % 2 == 0) ? sort(array_ofArrays[i].rbegin(), array_ofArrays[i].rend()) : sort(array_ofArrays[i].begin(), array_ofArrays[i].end());
	}

	return array_ofArrays;

}


int main()
{

	auto _array = arrays_creation_sorting(N);

	for (int i = 0; i < N; i++)		// Вывод результата в консоль
	{
		std::cout << "array " << i + 1 << ":\n";
		for (auto it : _array[i])
		{
			std::cout << it << ' ';
		}
		std::cout << std::endl << std::endl << std::endl;
	}

	return 0;
}
