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
		}
		
	}

	Fin.close();
	Fout.close();
	return 0;
}