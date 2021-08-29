#include <iostream>
#include <math.h>
#include <cstring>
#include <array>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <sstream>
#include <atomic>
#include <thread>

using namespace std;

bool read_input(long long unsigned int *a)
{
	if( a == NULL )
	{
		cout << "null input parameter";
		return false;
	}

	long long unsigned int *data = new long long unsigned int[1000];
	if( !data ) {
		cout << "failed to allocate memory";
		return false;
	}

	long long unsigned int *ptr = data;
	long long unsigned int ch;
	while(( ch = getchar_unlocked()) != '\n') {
		if( ch == ' ') {
			ptr+=1;
			*(ptr) = 0;
		} else{
			*(ptr) = (*ptr * 10) + (ch - '0');
		}
	}
	*(a) = *(ptr);
	data = NULL;
	delete data;
	putchar_unlocked(c);
	return true;
}


const unsigned int MAX  = pow(10,9);
vector<unsigned int> input_B(MAX+2);

//! Efficiently remove an element from a vector without
//! preserving order. If the element is not the last element
//! in the vector, transfer the last element into its position
//! using a move if possible.
//! Regardless, we then shrink the size of the vector deleting
//! the element at the end, which will either be destructed or
//! the element we were deleting.
//! @note: Effectively invalidates the current iterator.
template<class ValueType>
bool unstable_remove(
    typename std::vector<ValueType>& container,
    typename std::vector<ValueType>::iterator it
    )
{
    // Leave in-situ if we are already the tail element.
    auto lastEl = container.end() - 1;
    if (it != lastEl) {
        // overwrite this element with what is in the last,
        // which should have the same effect as deleting this.
        *it = std::move(*lastEl);
    }
    // release the last cell of the vector, because it should
    // now either be destructed or contain the value we were
    // deleting.
    container.pop_back();
}

void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
    	    std::cout << input.at((i)) << "\n";
		}
}


void sieve(vector<unsigned int> *input_B){
	bool *a;
	

	a = (bool*)malloc(MAX * sizeof(bool));
	memset(a,true,MAX);
	unsigned int i = 1;
	while(i < MAX){
		while(((++i) < MAX) &&(!a[i]));
		
		if( 2 * i >= MAX)
			break;

		for(unsigned int k = 2 * i; k < MAX; k += i)
			if(a[k])
				a[k] = false;
		}
	   	for (unsigned int i = 2; i < MAX; i++)
        	if (a[i])
				input_B->at(i) =i;
				input_B+=4;
}

bool check_if_condition(int a)
{
	for(int i = 0 ; i < input_B.size();i+=1){
		if(input_B[i] == a){
			return true;
		}
	}
	return false;
	
}


void doWork(vector<int>& input, vector<bool> results, size_t current,size_t end, 
				atomic_int& totalPassed)
{
		end = min(end,input.size());
		int numPassed = 0;
		for(; current < end; ++current){
			if(input[current] == 1){
				results[current] = false;
				++numPassed;
				cout << "neither" << "\n";
			}
			if( check_if_condition(input[current])) {
				results[current] = true;
				++numPassed;
				cout << "prime" << "\n";
			}
			else{
				results[current] = false;
            	++numPassed;
				cout << "composite" << "\n"; 
			}
		}

		totalPassed.fetch_add(numPassed);
}


int main()
{
	cout << "acu bagi nr de elemente" << "\n";
	long long unsigned int *a;
	if( !read_input(a) ){
		cout << "failed to read input";
	}	
	int aux = 0 ;
	vector<int> input(static_cast<int>(*(a)));
	cout << "acu bagi numerele pt array" << "\n";
	while( *(a) ){
		cin >> input[aux];
		*(a) -=1;
		aux += 1;
	}
	cout << "done inainte de sieve" << "\n";
	sieve(&input_B);

	remove_if(input_B.begin(),input_B.end(),[](int i) { return i == 0; });
	cout << "dupa sieve filteting" << "\n";
	//good butt too slow
	//input_B.erase(std::remove_if(begin(input_B), end(input_B), [](int i) { return i == 0; }), end(input_B));

	/* still slow
	auto it = input_B.begin();
	while( it != input_B.end()) {
		if(*(it) == 0){
			unstable_remove(input_B,it);
			continue;
		}
		++it;
	}*/
	
	auto numThreads = thread::hardware_concurrency();
	
	vector<bool> results(input.size());
	atomic_int numPassed(0);

	vector<thread> threads;
	auto blockSize = input.size() / numThreads;

	for(size_t i = 0 ; i < numThreads -1; ++i){
		threads.emplace_back(doWork,std::ref(input),std::ref(results),
						i * blockSize,(i+1) * blockSize, std::ref(numPassed));
	}

	//also do work in this thread
    doWork(input, results, (numThreads-1) * blockSize, numThreads*blockSize, numPassed);

    for(auto& thread : threads)
		thread.join();

	std::vector<int> storage;
	storage.reserve(numPassed.load());
	
	auto itRes = results.begin();
    auto itInput = input.begin();
    auto endRes = results.end();

	for(; itRes != endRes; ++ itRes, ++itInput){
		if(*itRes)
			storage.emplace_back(*itInput);
	}
	

	std::cout << "Done" << std::endl;
	
	return 0;

}
