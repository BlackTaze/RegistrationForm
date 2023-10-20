#include <iostream>
#include <fstream>

using namespace std;



class Password
{
public:
	
	
	int Entrance()
	{
		string login = "login.txt";
		string password = "password.txt";

		fstream log;
		fstream pass;

		log.open(login, fstream::in | fstream::out | fstream::app);
		pass.open(password, fstream::in | fstream::out | fstream::app);

		if (!log.is_open() && !pass.is_open()) {
			cout << "Ошибка / Error ";
		}
		else {
			string login_checker;
			string password_checker;

			while (!log.eof()) {
				login_checker = "";
				log >> login_checker;
			}
				while (!pass.eof()) {
					password_checker = "";
					pass >> password_checker;
				}

			string login_correct;
			string password_correct;

			cout << "Введите логин: / Enter login:  " << endl; cin >> login_correct;
			cout << "Введите пароль: / Enter password:  " << endl; cin >> password_correct;

			if (login_correct != login_checker && password_correct != password)  cout << "Введены неверные данные! / Wrong data! "; 
			else  cout << "Данные введены верно / Welcome!" << endl; 

		}
		return 0;
	}



	int Sign_up()
	{
		string login = "login.txt";
		string password = "password.txt";

		fstream log;
		fstream pass;

		log.open(login, fstream::in | fstream::out | fstream::app);
		pass.open(password, fstream::in | fstream::out | fstream::app);

		if (!log.is_open() && !pass.is_open()) {
			cout << "Ошибка / Error ";
		}
		else {
			string login_checker;
			string password_checker;

			cout << "Введите логин: / Enter login:  " << endl; cin >> login_checker;
			cout << "Введите пароль: / Enter password: "; cin >> password_checker;
			
			log << login_checker;
			pass << password_checker;
			cout << "Регистрация успешно завершена! / Registration completed successfully! ";


		}
		return 0;

	}

};

class Menu 
{
public:
	int RunMenu() {
		int option;
		cout << "Добро пожаловать! / Welcome!" << endl;
		cout << "1. Вход / Entrance " << endl;
		cout << "2. Регистрация / Sign Up" << endl;
		cin >> option;

		switch (option)
		{
		case 1:
			system("cls");
			Password passE;
			passE.Entrance();
			break;

		case 2:
			system("cls");
			Password passS;
			passS.Sign_up();
			break;
		default:
			cout << "Выбран неверный пункт / Wrong option ";
			break;
		}
		return 0;

	}

};

int main()
{
	Menu menu;

	menu.RunMenu();

}
