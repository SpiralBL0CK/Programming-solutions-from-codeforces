#include <iostream>
#include <thread>
#include <array>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <mutex>
#include <condition_variable>

using namespace std;

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}


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
		if(ch >= 65 && ch <= 127){
			cout << "sorry we do not accept characters" << "\n";
			return false;
		}
		if( ch == ' ') {
			ptr+=1;
			*(ptr) = 0;
		} else{
			*(ptr) = (*ptr * 10) + (ch - '0');
		}
	*(a) = *(ptr);
	
	data = NULL;
	delete data;

	return true;
}

int do_print_hashmap(multimap<int,int> &hashmap_param){
	map<int, int>::iterator it;

	for (it = hashmap_param.begin(); it != hashmap_param.end(); it++)
	{
    		std::cout << it->first    // string (key)
              		<< ':'
              		<< it->second   // string's value 
              		<< std::endl;
	}

}

bool sub_custom(long long unsigned int *input_A,long long unsigned int *input_B){
     	
	if( !read_input(input_A) ){
                cout << "failed to read input";
                exit(0);
        }

        if( !read_input(input_B) ){
        cout << "failed to read input";
        exit(0);
        }

}

bool read_input_string(long long unsigned int *input_A,long long unsigned int *input_B,
				long long unsigned int *input_C, vector<int> *input_D)
{
	if( !read_input(input_A) ){
		cout << "failed to read input";
		exit(0);
	}

	if( !read_input(input_B) ){
    	cout << "failed to read input";
        exit(0);
	}

	if( !read_input(input_C) ){
        cout << "failed to read input";
        exit(0);
    }


	int aux = 0;
	int *addr;
	int *tmp;
	int cross = 0;
	int index = 0;
	int mod_helper = *(input_B);
	map<int,int> hashmap;
	
	while( *(input_A) ){
			while( *(input_B) ){
				index = ((*(input_B)-1) % mod_helper);
				cout << "Baga mare barosane ca acu bagi hashmap";
				cin >> cross;
				hashmap.insert({index,cross});
				*(input_B) -=1;
			}
		*(input_A) -=1;
		std::multimap<int,int> dst = flip_map(hashmap);
		std::map<int,int>::iterator it;
		
		while(mod_helper){
			for (it = dst.begin();it != dst.end(); it ++) {
				addr = &(it->second);
				tmp = &(it->second)+1;
				if ( *(tmp) - *(addr) < cross){
					cout << "yes";
				}
				else{
					cout << "no";
				}
				mod_helper -= 1;
			}
		}
	}
}
	
	

int main(){
    
	long long unsigned int input_A;
	long long unsigned int input_B;
	long long unsigned int input_C;
	vector<int> *input_D;

	read_input_string(&input_A,&input_B,&input_C,input_D);
	
    return 0;
}
