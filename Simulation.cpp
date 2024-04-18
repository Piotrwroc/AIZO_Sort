#include "Simulation.h"

#include "Generation.h"
#include "Sorting.h"

#define REPETITION 100 //ustawienie liczby powtorzen generacji
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

template<typename T>
void Simulation<T>::simulation_mode(T* tab)
{
    if (tab != nullptr)
    {
        delete[] tab;
    }
    double czas;
    float suma[9] = { 0 };
    string filename;
    ofstream file;
    T* tab_copy = nullptr;
    int rozmiary[] = { 10000,20000,30000,40000,50000,60000,70000,80000 }; //zestaw danych
    //int rozmiary[] = { 80000 };
    for (int i = 0; i < 8; i++) //iterowanie po rozmiarach
    {

        tab = new T[rozmiary[i]];
        //tab_copy = new T[rozmiary[i]];
  
        for (int modeNum = 1; modeNum <= 5; modeNum++) //iterowanie po trybach generowania
        {         
            //iterowanie po trybach tablic
            filename = string(var_name()) + "_" + to_string(rozmiary[i]) + "_" + string(mode_name(modeNum));
            cout << filename << endl;
            file.open(filename + ".txt");         
            cout << "|";

            for (int rep = 0; rep < REPETITION; rep++) //powtorzenia pomiaru dla kazdego rozmiaru i trybu
            {
                tab_copy = new T[rozmiary[i]];
                cout << "=";

                Generation<T> generation;
                generation.generation_type(tab, rozmiary[i], modeNum);

                //for (int algNum = 1; algNum <=8 ; algNum++) //iterowanie po algorytmach
                for (int algNum = 3; algNum <=3 ; algNum++) //iterowanie po wybranym algorytmie  
                {
                    
                    for (int x = 0; x < rozmiary[i]; x++)
                    {
                        tab_copy[x] = tab[x]; //tworzenie kopii tablicy na potrzeby posortowania przez algorytm
                    }
                    Sorting<T> sorting;
                    czas = sorting.f_sorting(tab_copy, rozmiary[i], algNum);                 
                    //file << czas << "\t";
                    suma[algNum] += czas;
                }
                //file << endl;
            }
            delete[] tab_copy;
            cout << "|" << endl;          
            for (int algNum = 1; algNum <= 8; algNum++) 
            {
 
                file << suma[algNum] / (double)REPETITION << "\t";
            }
            file.close();
        }
        delete[] tab;
        //delete[] tab_copy;
    }
}

template<typename T>
const char* Simulation<T>::var_name()
{
    if (std::is_same<T, int>::value)
    {
        return "int";
    }
    else if (std::is_same<T, float>::value)
    {
        return "float";
    }
    else if (std::is_same<T, double>::value)
    {
        return "double";
    }
    else if (std::is_same<T, char>::value)
    {
        return "char";
    }

}

template <typename T>
const char* Simulation<T>::mode_name(int modeNum)
{
    switch (modeNum) 
    {
    case 1:
    {
        return "sortRand";
        break;
    }
    case 2:
    {
        return "sort33%";
        break;
    }
    case 3:
    {
        return "sort66%";
        break;
    }
    case 4:
    {
        return "sortInc";
        break;
    }
    case 5:
    {
        return "sortDsc";
        break;
    }
    {
    deafult:
        return "error";
    }
    }
}
