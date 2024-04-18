#ifndef GENERATION_H
#define GENERATION_H

template<class T>
class Generation
{
public:
	void menu_generation(T* tab, int size);
	void generation_type(T* tab, int size, int wybor_generacji);
	void f_generation(T* tab, int size, int beginning);	
};

#endif GENERATION_H



