#ifndef MENU_SETTINGS_H
#define MENU_SETTINGS_H

#include "Generation.h"

template<typename T>
class Menu_Settings
{
private:
	int size;
	T* tab = nullptr;

public:
	void f_menu_settings();
	void load_array();
	void save_array();
	void create_array();
	void display_array();
	void sort_check();
	void sort_array();
};
#endif MENU_SETTINGS_H