#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>

class Address
{
public:
	std::string city;
	std::string street;
	int house_num;
	int flat_num;
	Address()
	{
		this->city = " ";
		this->street = " ";
		this->house_num = 0;
		this->flat_num = 0;
	}
	Address(std::string city, std::string street, int house_num, int flat_num)
	{
		this->city = city;
		this->street = street;
		this->house_num = house_num;
		this->flat_num = flat_num;
	}
	std::string output(std::string City, std::string Street, int house_num, int flat_num)
	{
		std::string str;
		str = str + City;
		str = str + ", " + Street;
		std::string stdNum1 = std::to_string(house_num);
		std::string stdNum2 = std::to_string(flat_num);
		str = str + ", " + stdNum1;
		str = str + ", " + stdNum2;
		return str;
	}
};
void sort(Address* address, int size)
{
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = 0; i < size; ++i)
		{
			if (address[i].city < address[i + 1].city)
			{
				Address temp = address[i];
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
		Address* address = new Address[number];
		for (int i = 0; i < number; ++i)
		{
			std::string city;
			std::string street;
			int house_num = 0;
			int flat_num = 0;
			Fin >> city;
			Fin >> street;
			Fin >> house_num;
			Fin >> flat_num;
			address[i] = Address(city, street, house_num, flat_num);
		}
		sort(address, number);
		for (int i = 0; i < number; ++i)
		{
			std::string city = address[i].city;
			std::string street = address[i].street;
			int house_num = address[i].house_num;
			int flat_num = address[i].flat_num;
			Address add(city, street, house_num, flat_num);
			Fout << add.output(city, street, house_num, flat_num);
			Fout << "\n";
		}
		delete[] address;
	}

	Fin.close();
	Fout.close();
	return 0;
}