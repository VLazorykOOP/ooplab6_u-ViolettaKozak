#include "Lab6Example.h"
#include <iostream>
namespace SpaceExample1 {
    ///Задача. Створити дві ієрархії класів без віртуального та з віртуальним спадкуванням, 
    // з елементами даних класів у кожному класі. Схема успадкування на рисунку за варіантами. 
    // Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. 
    // Вивести розміри об’єктів даних класів.
	class Animal
	{
	public:
		Animal() {};
		~Animal() {};

	private:

	};

	class Miths
	{
	public:
		Miths() {};
		~Miths() {};

	private:

	};

	class MithicsAnimal: protected Animal, Miths
	{
	public:
		MithicsAnimal() {};
		~MithicsAnimal() {};

	private:

	};

	class God: protected Miths
	{
	public:
		God() {};
		~God() {};

	private:

	};

	class Unicorn: protected MithicsAnimal
	{
	public:
		Unicorn() {};
		~Unicorn() {};

	private:

	};

	class Griffin: protected Unicorn, God, MithicsAnimal
	{
	public:
		Griffin() {};
		~Griffin() {};

	private:

	};

	
}