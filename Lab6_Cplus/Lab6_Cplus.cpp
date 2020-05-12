#include <sys/types.h>
#include <fcntl.h> 
#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

struct Human
{
	string Surname;			//Фамилия
	int Group;				//Группа
	int Math;				//Математика
	int Physics;			//Физика
	int Chemistry;			//Химия
	int Cash;				//Пенсия
};

void task()
{
	cout << "Размер структуры Human: " << sizeof(Human) << " bytes";
	string Surname[] = { "Иванов А.Г.","Соколов В.И.","Марков Н.В.","Громов Д.П." };
	const int N = 4;
	Human* human = new Human[N];
	char path[] = "db.bin";
	cout << endl << endl << "Генерация структуры:" << endl;
	for (size_t i = 0; i < N; i++)
	{
		cout << (human[i].Surname = Surname[i])<< "\t" << "Группа: " <<(human[i].Group = 100 + rand()% 7 ) << "\t" <<"Математика: "<< (human[i].Math = 0 + rand() % 100) << "\t" << "Физика: " <<(human[i].Physics = 0 + rand() % 100) << "\t" <<"Химия: " <<(human[i].Chemistry = 0 + rand() % 100) << "\t" << "Пенсия: " << (human[i].Cash = 200 +rand()%2000) << endl;
	}

	FILE* f_out, * f_in;
	f_out = fopen(path, "wb");
	fwrite(human, sizeof(Human), N, f_out);
	fclose(f_out);

	delete[] human;
	human = nullptr;

	cout << endl << endl << "Считывание из файла: " << endl;
	Human* restoredDB = new Human[N];
	f_in = fopen(path, "rb");
	fread(restoredDB, sizeof(Human), N, f_in);
	fclose(f_in);
	for (size_t i = 0; i < N; i++)
	{
		cout << restoredDB[i].Surname << "\t" << "Группа: " << restoredDB[i].Group << "\t" << "Математика: " << restoredDB[i].Math << "\t" << "Физика: " << restoredDB[i].Physics << "\t" << "Химия: " << restoredDB[i].Chemistry << "\t" << "Пенсия: " << restoredDB[i].Cash << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Task 1 \n";
	task();
}