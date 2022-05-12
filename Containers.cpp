#include <iostream>
#include <ctime>

#include <algorithm>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>


using namespace std;



int main()
{
	
	array <int, 100001> myarray;
	for (int i = 100000; i > 0; i--)
		myarray[i] = rand();
	clock_t time1 = clock();
	time1 = clock();
	sort(myarray.begin(), myarray.end());
	cout << "ARRAY: " << clock() - time1 << endl;

	vector <int> myvector;
	myvector.reserve(100000);
	for (int i = 100000; i > 0; i--)
		myvector.push_back(rand());
	clock_t time2 = clock();
	time2 = clock();
	sort(myvector.begin(), myvector.end());
	cout << "VECTOR: " << clock() - time2 << endl;


	deque <int> mydeque;
	for (int i = 100000; i > 0; i--)
		mydeque.push_back(rand());
	clock_t time3 = clock();
	time3 = clock();
	sort(mydeque.begin(), mydeque.end());
	cout << "DEQUE: " << clock() - time3 << endl;

	list <int> mylist;
	for (int i = 100000; i > 0; i--)
		mylist.push_back(rand());
	clock_t time4 = clock();
	time4 = clock();
	mylist.sort();
	cout << "LIST: " << clock() - time4 << endl;
	
	forward_list <int> myforwardlist;
	for (int i = 100000; i > 0; i--)
		myforwardlist.push_front(rand());
	clock_t time5 = clock();
	time5 = clock();
	myforwardlist.sort();
	cout << "FORWARD LIST: " << clock() - time5 << endl;
	
	

	
}