#include <iostream>
#include "MyClass.h"
#include "MyClass2.h"
#include "MyClass3.h"
#include <vector>
#include <thread>
#include <mutex>
#include <semaphore>
#include <iterator>
#include <atomic>

using std::vector;
using std::thread;
using std::cout;
using std::endl;
using std::mutex;
using std::counting_semaphore;
using std::atomic;

atomic<int> number{0};
mutex m;
counting_semaphore<10> semahore(1);

void func()
{
	for (size_t i = 0; i < 1000000; i++)
	{
		number++;
	}
}

int main()
{
	/*thread t1(func);
	thread t2(func);
	t1.join();
	t2.join();
	cout << number;*/

	/*vector<int> vec{0,1,2,3,4,5,6,7,8,9};

	vector<int>::iterator ptr;
	
	ptr = vec.begin()+2;

	cout << *ptr;*/
}