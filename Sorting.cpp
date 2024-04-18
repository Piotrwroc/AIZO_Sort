#include "Sorting.h"

#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

template <typename T>
void Sorting<T>::sorting_menu(T *tab, int size)
{
    //bool q = true;
    //while (q)
        int wybor_algorytmu = 0;
        cout << "Wybierz algorytm:" << endl;
        cout << "1. InsertionSort" << endl;
        cout << "2. HeapSort" << endl;
        cout << "3. ShellSort" << endl;
        cout << "4. ShellSort Knutha" << endl;
        cout << "5. QuickSort(pierwszy)" << endl;
        cout << "6. QuickSort(srodkowy)" << endl;
        cout << "7. QuickSort(ostatni)" << endl;
        cout << "8. QuickSort(losowy)" << endl;
        cout << endl;;
        cin >> wybor_algorytmu;
        if (wybor_algorytmu > 0 && wybor_algorytmu <= 8)
        {
            //uruchomienie sortowania na wczytanej lub wygenerowanej tablicy
            cout << endl << "Czas sortowania wyniosi: " << f_sorting(tab, size, wybor_algorytmu) << " ms" << endl; 
        }
        
}

template <typename T>
double Sorting<T>::f_sorting(T* tab, int size, int wybor_algorytmu)
{
    std::chrono::duration<double> time{};
    switch (wybor_algorytmu)
    {
    case 1:
    {
        const auto start = std::chrono::high_resolution_clock::now();
        s_InsertionSort(tab, size);
        const auto end = std::chrono::high_resolution_clock::now();
        //auto time = std::chrono::duration_cast<chrono::milliseconds>(end - start);
        time = end - start;
        break;
    }

    case 2:
    {
        const auto start = std::chrono::high_resolution_clock::now();
        s_HeapSort(tab, size);
        const auto end = std::chrono::high_resolution_clock::now();
        //auto time = std::chrono::duration_cast<chrono::milliseconds>(end - start);
        time = end - start;
        break;
    }

    case 3:
    {
        const auto start = std::chrono::high_resolution_clock::now();
        s_ShellSort(tab, size, 0);
        const auto end = std::chrono::high_resolution_clock::now();
        //auto time = std::chrono::duration_cast<chrono::milliseconds>(end - start);
        time = end - start;
        break;
    }

    case 4:
    {
        const auto start = std::chrono::high_resolution_clock::now();
        s_ShellSort(tab, size, 1);
        const auto end = std::chrono::high_resolution_clock::now();
        //auto time = std::chrono::duration_cast<chrono::milliseconds>(end - start);
        time = end - start;
        break;
    }

    case 5:
    {
        const auto start = std::chrono::high_resolution_clock::now();
        s_QuickSort(tab, 0, size - 1, 'f');
        const auto end = std::chrono::high_resolution_clock::now();
        //auto time = std::chrono::duration_cast<chrono::milliseconds>(end - start);
        time = end - start;
        break;
    }
    case 6:
    {
        const auto start = std::chrono::high_resolution_clock::now();
        s_QuickSort(tab, 0, size - 1, 'm');
        const auto end = std::chrono::high_resolution_clock::now();
        //auto time = std::chrono::duration_cast<chrono::milliseconds>(end - start);
        time = end - start;
        break;
    }
    case 7:
    {
        const auto start = std::chrono::high_resolution_clock::now();
        s_QuickSort(tab, 0, size - 1, 'l');
        const auto end = std::chrono::high_resolution_clock::now();
        //auto time = std::chrono::duration_cast<chrono::milliseconds>(end - start);
        time = end - start;
        break;
    }
    case 8:
    {
        const auto start = std::chrono::high_resolution_clock::now();
        s_QuickSort(tab, 0, size - 1, 'r');
        const auto end = std::chrono::high_resolution_clock::now();
        //auto time = std::chrono::duration_cast<chrono::milliseconds>(end - start);
        time = end - start;
        break;
    }

    default:
    {
        cout << "Wybrano niepoprawna opcje" << endl;
        break;
    }

}
return time.count()*1000;
}


template<typename T>
void Sorting<T>::s_InsertionSort(T *tab, int size)
{
        int i, k, j;
        for (i = size - 2; i >= 0; i--)
        {
            k = tab[i];
            j = i + 1;  
            while ((j < size) && (k > tab[j]))
            {
                tab[j - 1] = tab[j];
                j++;
            }
            tab[j - 1] = k;
        }
}

template<typename T>
void Sorting<T>::heapify(T *tab, int size, int i) // przywracanie w³asnoœci kopca
{

    // wczytanie najwiekszego elementu jako korzenia
    int largest = i;

    // stosowanie wzoru na potomka po lewej
    int l = i * 2 + 1;

    // i po prawej
    int r = i * 2 + 2;

    // Porownanie lewego potomka z korzeniem
    if (l < size && tab[l] > tab[largest])
        largest = l;

    // Porownanie prawego potomka z najwiekszym aktualnie elementem
    if (r < size && tab[r] > tab[largest])
        largest = r;

    // Zamiana elementow jesli najwiekszy z nich nie jest korzeniem
    if (largest != i) {
        swap(tab[i], tab[largest]);


        heapify(tab, size, largest);
    }
}

template<typename T>
void Sorting<T>::s_HeapSort(T *tab, int size)
{

    // Budowanie kopca
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(tab, size, i);

    // odkrywanie elememntow z kopca po kolei

    for (int i = size - 1; i > 0; i--) {

        // Przesuwanie aktualnego korzenia
        swap(tab[0], tab[i]);


        heapify(tab, i, 0);
    }
}
   
template<typename T>
void Sorting<T>::s_ShellSort(T *tab, int size, int mode)
{

    int h, i, j, x;

    // Wyznaczenie wartoœci pocz¹tkowego przesuniêcia
    if (mode == 0)
    {
        for (h = 1; h < size; h = 3 * h + 1);
        h /= 9;
        if (!h) h++; // istotne dla ma³ych rozmiarow tablic, dla wiêkszych mo¿na pomin¹æ!
    }
    if (mode == 1)
    {
        h = size / 2; //ciag zaproponowany przez tworce algorytmu
    }


    // Sortowanie

    while (h)
    {
        for (j = size - h - 1; j >= 0; j--)
        {
            x = tab[j];
            i = j + h;
            while ((i < size) && (x > tab[i]))
            {
                tab[i - h] = tab[i];
                i += h;
            }
            tab[i - h] = x;
        }
        h /= 3;
    }

}

template<typename T>
int Sorting<T>::partition(T *tab, int low, int high, char pivotType) //zwracanie pivota i ustawianie elementow rosnaco
{ 
    int pivot;
    switch (pivotType) 
    {
    case 'l': // last - ostatni element pivotem
    { 
        pivot = tab[int(high)];
        break;
    }
    case 'm': // middle - œrodkowy element pivotem
    {
        pivot = tab[int(low + high) / 2];

        break;
    }
    case 'f': // first - pierwszy element pivotem
    {
        pivot = tab[int(low)];
        break;
    }
    case 'r': // random - losowy element pivotem
    {
        srand(time(NULL));

        pivot = tab[int(low + rand() % (high - low))];
        break;
    }
    deafult:
    cout << "error" << endl;
        return 0;
    }

    int l = low;
    int r = high;
    while (true) {
        while (tab[l] < pivot)   ++l;
        while (tab[r] > pivot)  --r;
        if (l < r) {
            swap(tab[l], tab[r]);
            ++l;
            --r;
        }
        else {
            if (r == high) r--;
            return r;
        }
    }
}
template<typename T>
void Sorting<T>::s_QuickSort(T *tab, int low, int high, char pivotType)
{

    if (low >= high)          return;
    int m = partition(tab, low, high, pivotType);

    s_QuickSort(tab, low, m, pivotType);
    s_QuickSort(tab, m + 1, high, pivotType);
}




