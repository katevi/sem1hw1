#include <iostream>   

int main()
{
	FILE *file;
	fopen_s(&file, "cppstudio.txt", "r");   

	char currentSymbol = ' ';
	int count = 0;
	bool isNotEmpty = false;
	while (!feof(file)) 
	{
		currentSymbol = fgetc(file);
		if ((currentSymbol != ' ') and (currentSymbol != '\n') and (currentSymbol != '\t'))
		{
			isNotEmpty = true;
		}
		if ((currentSymbol == '\n') and (isNotEmpty))
		{
			count++;
			isNotEmpty = false;
		}
		if ((currentSymbol == EOF) and (isNotEmpty) and (count > 0))
			count++;
	}
	std::cout << "Number of non-empty rows:" << count;
}