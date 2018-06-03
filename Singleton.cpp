/*http://cpp-reference.ru/patterns/creational-patterns/singleton/
Одиночка — это порождающий паттерн проектирования, который гарантирует, что у класса есть только один экземпляр, и предоставляет к нему глобальную точку доступа.
Гарантирует наличие единственного экземпляра класса. Чаще всего это полезно для доступа к какому-то общему ресурсу, например, базе данных.
Предоставляет глобальную точку доступа. Это не просто глобальная переменная, через которую можно достучаться к определённому объекту.
Глобальные переменные не защищены от записи, поэтому любой код может подменять их значения без вашего ведома.*/
#include "stdafx.h"
#include <iostream>
class Singleton 
{
	private:
		
		//Конструкторы и операторы присваивания недоступны пользователю
		Singleton() = default; 
		~Singleton() = default;

		//Также недоступны операторы new, копирования и присваивающего копирования
		void* operator new(std::size_t) = delete;
		Singleton(const Singleton&) = delete; 
		Singleton& operator=(Singleton&) = delete;
	
	public:
		//Для создания объекта класса используется ункция getInstance, которая единожды создаёт объект p_instance
		static Singleton * getInstance()
		{
			static  Singleton * p_instance;
			return p_instance;
		}
};

void foo() 
{
	auto a = Singleton::getInstance();
	std::cout << &a << std::endl;

}

void bar() 
{
	auto b = Singleton::getInstance();
	std::cout << &b << std::endl;
}

//Чтобы убедиться в том, что переменная не создаётся вновь добавим две функции bar и foo.
//Обе функции выведут на экран одинаковый адрес
int main()
{
	foo();
	bar();
    return 0;
}

