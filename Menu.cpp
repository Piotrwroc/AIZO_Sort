#include "Menu.h"
#include "Menu_Settings.h"
#include "Menu_Settings.cpp"

#include <iostream>
#include <cstdlib>


using namespace std;

void Menu::f_menu()
{
    bool x = true;
    while (x)
    {
        system("cls");
        int wybor_typu=0;
        cout << "Autorem programu jest Piotr Jozefek 272311" << endl;
        cout << "Wybierz typ danych: " << endl;
        cout << "1. Int" << endl;
        cout << "2. Float" << endl;
        cout << "3. Double" << endl;
        cout << "4. Char" << endl;
        cout << "5. Wylaczenie programu" << endl;
        cout << endl;
        cin >> wybor_typu;

        switch (wybor_typu)
        {
        case 1:
        {
            Menu_Settings<int> Menu_int; //Storzenie klasy z szablonem int
            Menu_int.f_menu_settings();

            break;
        }

        case 2:
        {
            Menu_Settings<float> Menu_float; //Storzenie klasy z szablonem float
            Menu_float.f_menu_settings();

            break;
        }

        case 3:
        {
            Menu_Settings<double> Menu_double; //Storzenie klasy z szablonem double
            Menu_double.f_menu_settings();

            break;
        }

        case 4:
        {
            Menu_Settings<char> Menu_char; //Storzenie klasy z szablonem char
            Menu_char.f_menu_settings();

            break;
        }

        case 5:
        {
            cout << "Zakonczono dzialanie programu" << endl;
            exit(0);
            break;
        }

        default:
        {
            cout << "Wybrano niepoprawna opcje" << endl;
            break;
        }
        }
    }
}