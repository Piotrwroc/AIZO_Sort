#include "Generation.h"


#include <iostream>
#include <random>

using namespace std;

template <class T>
void Generation<T>::menu_generation(T* tab, int size)
{
    int wybor_generacji = 0;
    
        cout << endl;
        cout << "Wybierz opcje generowania: " << endl;
        cout << "1. tablica losowa" << endl;
        cout << "2. tablica posortowana rosnaco" << endl;
        cout << "3. tablica posortowana malejaco" << endl;
        cout << "4. tablica posortowana czesciowo 33%" << endl;
        cout << "5. tablica posortowana czesciowo 66%" << endl;
        cout << endl;
        cin >> wybor_generacji;     
        generation_type(tab, size, wybor_generacji);
}

template <class T>
void Generation<T>::generation_type(T* tab, int size, int wybor_generacji)
{
    switch (wybor_generacji)
    {
    case 1:
    {
        f_generation(tab, size, 0); //tablica ca³kowicie losowa      
        break;
    }
    case 2:
    {
        for (int i = 0; i < size; i++) //tablica posortowana rosn¹co
        {
            tab[i] = i;
        }       
        break;
    }
    case 3:
    {
        for (int i = size; i > 0; i--) //tablica posortowana malej¹co
        {
            tab[size - i] = i;
        }
        break;
    }
    case 4:
    {
        for (int i = 0; i < (size / 3); i++) //tablica posortowana czêœciowo 33%
        {
            tab[i] = i;
        }
        f_generation(tab, size, (size / 3));
        break;
    }
    case 5:
    {
        for (int i = 0; i < size * 2 / 3; i++)  // tablica posortowana czêœciowo 66%
        {
            tab[i] = i;
        }
        f_generation(tab, size, size *2 / 3);
        break;
    }
    default:
    {
        cout << "Wybrano niepoprawna opcje" << endl;
        break;
    }
    }
}

template<class T>
void Generation<T>::f_generation(T* tab, int size, int beginning)
{

    std::random_device rd;
    std::mt19937 gen(rd());

    // Ustawienie zakresu od beggining do size
    std::uniform_real_distribution<float> distribution((float)beginning, (float)size);

    // Wype³niamy tablicê przyk³adowymi danymi
    for (int i = beginning; i < size; i++) 
    {
        tab[i] = (T)distribution(gen);
    }
}