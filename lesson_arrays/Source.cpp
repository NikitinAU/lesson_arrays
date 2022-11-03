#include "ImPureF.h"
int main()
{
	std::srand(std::time(NULL));
	bool ok = true;
	while (ok)
	{
		int task = 0;
		std::cout << "available tasks: 1 2 3 4 5 6 7\nenter 0 to quit\nenter task number:\n";
		std::cin >> task;
		switch (task)
		{
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		case 4: task4(); break;
		case 5: task5(); break;
		case 6: task6(); break;
		case 7: task7(); break;
		case 0: ok = false; break;
		default: std::cout << "no such task! try again\n"; break;
		}
		system("pause");
		system("cls");
	}
	std::cout << "goodbye!\n";
	return 0;
}