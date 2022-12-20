#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>

class Address
{
	std::string city;
	std::string street;
	int house_num;
	int flat_num;
public:
	Address(std::string city, std::string street, int house_num, int flat_num)
	{
		this->city = city;
		this->street = street;
		this->house_num = house_num;
		this->flat_num = flat_num;
	}
	std::string out(std::string city, std::string street, int house_num, int flat_num)
	{
		std::string str;
		str = str + city;
		str = str + ", " + street;
		std::string strNum1 = std::to_string(house_num);
		std::string strNum2 = std::to_string(flat_num);
		str = str + ", " + strNum1;
		str = str + ", " + strNum2;
		return str;
	}
};
void sort(std::string* address , int size)
{
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (address[i].compare(address[i + 1])>0)
			{
				std::string temp = address[i];
				address[i] = address[i + 1];
				address[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}
int main(int argc, char** argv)
{
	system("chcp 1251");
	std::ifstream Fin("in.txt");
	std::ofstream Fout("out.txt");
	if (Fin.is_open() != 0)
	{
		int number = 0;
		Fin >> number;
		Fout << number;
		Fout << "\n";
		std::string* address = new std::string[number];
		std::string city;
		std::string street;
		int house_num = 0;
		int flat_num = 0;
		for (int i = 0; i < number; ++i)
		{
			Fin >> city;
			Fin >> street;
			Fin >> house_num;
			Fin >> flat_num;
			Address add(city, street, house_num, flat_num);
			address[i] = add.out(city, street, house_num, flat_num);
		}
		sort(address, number);
		for (int i = 0; i < number; i++)
		{
			Fout << address[i];
			Fout << "\n";
		}
	}

	Fin.close();
	Fout.close();
	return 0;
}