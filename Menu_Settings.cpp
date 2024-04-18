#include "Menu_Settings.h"
#include "Generation.h"
#include "Generation.cpp"
#include "Sorting.h"
#include "Sorting.cpp"
#include "Simulation.h"
#include "Simulation.cpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

template<typename T>
void Menu_Settings<T>::f_menu_settings()
{
    int wybor_funkcji = 0;
    bool y = true;
    while (y)
    {
        //system("cls");
        cout << endl;
        cout << "Wybierz funkcje programu: " << endl;
        cout << "1. Odczyt tablicy z pliku" << endl;
        cout << "2. Zapis tablicy do pliku " << endl;
        cout << "3. Generowanie tablicy" << endl;
        cout << "4. Wyswietlenie tablicy" << endl;
        cout << "5. Sprawdzenie posortowania tablicy" << endl;
        cout << "6. Sortowanie tablicy" << endl;
        cout << "7. Tryb symulacji" << endl;
        cout << "8. Zmien typ danych" << endl;
        cout << "9. Wylaczenie programu" << endl;
        cout << endl;
        cin >> wybor_funkcji;

        switch (wybor_funkcji)
        {
        case 1:
            load_array(); //zaladowanie tablicy z pliku
            break;

        case 2:
            save_array(); //zapis tablicy do pliku
            break;

        case 3:
        {
            create_array(); //stworzenie tablicy
            break;
        }
        case 4:
        {     
            display_array(); //wyswietlenie tablicy
            break;
        }
        case 5:
        {
            sort_check(); //Sprawdzenie czy tablica jest posortowania
            break;
        }
        case 6:
        {        
           sort_array(); //sortowanie tablicy
           break;
        }
        case 7:
        {     
            Simulation<T> simulation; //uruchomienie eksperymentu
            simulation.simulation_mode(tab);         
        }

        case 8:
        {
            y = false; //cofniecie do wyboru danych
            if (tab != nullptr)
            {
                delete[] tab; 
                tab = nullptr;
            }           
            break;      
        }

        case 9:
        {
            y = false;
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

template <typename T>
void Menu_Settings<T>::load_array()
{
    if (tab != nullptr) 
    {
        delete[] tab;
        tab = nullptr;
    }

    string filename;
    cout << "Podaj nazwe pliku: ";
    cin >> filename;

    ifstream file;
    file.open(filename);
    if (file.is_open())
    {
        file >> size; //wczytanie rozmiaru
        tab = new T[size];
        for (int i = 0; i < size; i++)
        {
            file >> tab[i]; //wczytanie tablicy
        }
        file.close();
        cout << "Odczyt udany" << endl << endl;
    }
    else
    {
        cout << "Nie mozna odtworzyc pliku: " << filename << endl << endl;
    }
}

template <typename T>
void Menu_Settings<T>::save_array()
{
        if (tab != nullptr) 
        {
            string filename;
            cout << "Podaj nazwe pliku do zapisania: " << endl;
            cin >> filename;
            filename += ".txt";
            ofstream file;

            file.open(filename);
            if (file.is_open())
            {
                file << size << endl; //zapis rozmiaru
                for (int i = 0; i < size; i++) 
                {
                    file << tab[i] << endl;     //zapis zawartosci zablicy
                }
                file.close(); 
            }
            cout << "Zapis udany" << endl;
        }
        else cout << "Nie ma tablicy do zapisania" << endl;
}

template <typename T>
void Menu_Settings<T>::create_array()
{
    cout << "Podaj rozmiar tablicy:" << endl;
    cin >> size;
    if (tab != nullptr) ///zwolnienie pamieci poprzedniej tablicy jesli taka istnia³a
    {
        delete[] tab;
        tab = nullptr;
    }
    tab = new T[size];
    Generation<T> generation; //stworzenie klasy do generowania tablic
    generation.menu_generation(tab, size);
}

template <typename T>
void Menu_Settings<T>::display_array()
{
    if (tab != nullptr) 
    {
            cout <<"[ " << tab[0]; 
            for (int i = 1; i < size; ++i) //wyswietlanie tablicy
            {
                cout << ", " << tab[i];
            }    
            cout << " ]" << endl;
    }
    else cout << "Nie ma tablicy do wyswietlenia" << endl;
}

template <typename T>
void Menu_Settings<T>::sort_check()
{
    bool question = true;
    if (tab != nullptr)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (tab[i] > tab[i + 1]) //sprawdzenie czy elementy sa rosnace
            {
                cout << "Tablica nie jest posortowana" << endl;
                question = false;
                break;
            }
        }
        if (question)
        {
            cout << "Tablica jest posortowana" << endl;
        }     
    }
    else cout << "Nie ma tablicy do sprawdzenia" << endl;
}

template <typename T>
void Menu_Settings<T>::sort_array()
{
    bool good = true;
    if (tab != nullptr)
    {
        T* tab_copy = nullptr;
        tab_copy = new T[size];
        copy(tab, tab + size, tab_copy);
        
        Sorting<T> sorting; //stworzenie klasy z sortowaniem
        sorting.sorting_menu(tab, size);

        sort(tab_copy,size+ tab_copy);
        for (int i = 0;i < size;i++)
        {
            if (tab[i] != tab_copy[i])
            {
               good=false;
            }
        else good = true;
        }

        if (good)
        {
            cout << "Algorytm dziala poprawnie"<<endl;
        }
        else cout << "Algorytm nie dziala poprawnie"<<endl;
    }
    else
    {
        cout << "Nie ma tablicy do posortowania" << endl;
    }
}
