#pragma once
#include <iostream>

class MyClass2
{
public:
	class NestedClass 
	{
		public:
			void print() 
			{
				std::cout << "You are in the nested class";
			}
	};
};

