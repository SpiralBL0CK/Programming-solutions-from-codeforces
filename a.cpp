#include <iostream>
using namespace std;

int check(long long unsigned int a,long long unsigned int b)
{
	if( a > b ){
		return a;
	}
	return b;
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
	return true;
}


int main(int argc,char*argv[])
{
	long long unsigned int a;
	long long unsigned int b;
	if( !read_input(&a) ){
		cout << "failed to read input";
	}	
	if( !read_input(&b) ){
    	cout << "failed to read input";
    }
	if(a > b)
	{
		cout << a;
	}else {
		cout << b;
	}
	return 0;
}
