#include <iostream>
int n = 47;

#pragma pack(push,1)
struct cat
{
	bool IsAgressive; 
	bool AbilityForReproduction; 
	int age; 
	double weight; 
	char name[20]; 
	char breed[20]; 
};
#pragma pack(pop)

int main()
{
	int* din = new int;
	int local;
	std::cout << "Adresses: \n Global: " << &n << std::endl
		<< " Dinamic: " << din << std::endl
		<< " Automatic: " << &local << std::endl;
	delete din;
	//---------------------------------------------------------------------------------------------------------------------------------------------------------//
	const int sizeArr = 3;
	int Arr[sizeArr];
	std::cout << "Single static array: \n";

	for (int i = 0; i < sizeArr; ++i)
	{
		Arr[i] = i;
		std::cout << i << ") " << &Arr[i] << std::endl;
	}

	const int sizeArrDin = 3;
	int* ArrDin = new int[sizeArrDin];
	ArrDin[0] = 0;
	ArrDin[1] = 1;
	ArrDin[2] = 2;

	std::cout << "Single dinamic array: \n";

	for (int i = 0; i < sizeArrDin; ++i)
		std::cout << i << ") " << &ArrDin[i] << std::endl;

	const int sizeArr1_1 = 2;
	const int sizeArr1_2 = 2;
	int Arr1[sizeArr1_1][sizeArr1_2];
	std::cout << "Double static array: \n";

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			Arr1[i][j] = i + j;
			std::cout << "Arr1[" << i << "][" << j << "] = " << &Arr1[i][j] << std::endl;;
		}

	const int sizeArrDin1_1 = 2;
	const int sizeArrDin1_2 = 2;
	int** ArrDin1 = new int* [sizeArrDin1_1];

	for (int count = 0; count < 2; count++)
	{
		ArrDin1[count] = new int[sizeArrDin1_2];
	}

	std::cout << "Double dinamic: \n";

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			ArrDin1[i][j] = i + j;
			std::cout << "ArrDin1[" << i << "][" << j << "] = " << &ArrDin1[i][j] << std::endl;
		}

	for (int i = 0; i < 2; i++)
	{
		delete[] ArrDin1[i];
	}

	delete[] ArrDin;
	//---------------------------------------------------------------------------------------------------------------------------------------------------------//
	cat Rikky;
	Rikky.age = 10;
	Rikky.AbilityForReproduction = 0;
	Rikky.IsAgressive = 1;
	Rikky.weight = 14;
	std::cout << sizeof(Rikky) << std::endl << std::endl
		<< sizeof(Rikky.AbilityForReproduction) << "    " << &Rikky.AbilityForReproduction << std::endl
		<< sizeof(Rikky.age) << "    " << &Rikky.age << std::endl
		<< sizeof(Rikky.breed) << "    " << &Rikky.breed << std::endl
		<< sizeof(Rikky.IsAgressive) << "    " << &Rikky.IsAgressive << std::endl
		<< sizeof(Rikky.name) << "    " << &Rikky.name << std::endl
		<< sizeof(Rikky.weight) << "    " << &Rikky.weight << std::endl;
	std::cout << "Sum of fields: "
		<< sizeof(Rikky.AbilityForReproduction) + sizeof(Rikky.age) + sizeof(Rikky.breed) + sizeof(Rikky.IsAgressive) + sizeof(Rikky.name) + sizeof(Rikky.weight) << std::endl;
}