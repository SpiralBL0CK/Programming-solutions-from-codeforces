
#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <mutex>

#include <algorithm>
#include <atomic>
#include <inttypes.h>
#include <openssl/rand.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <string>

//	using namespace z3;
using namespace std;

const unsigned int MAX  = pow(10,9);
const int num_producers = 1;                //the three producers of random numbers
const int num_consumers = 1;                //the only consumer
const int producer_delay_to_produce = 10;   // in miliseconds
const int consumer_delay_to_consume = 30;   // in miliseconds

const int consumer_max_wait_time = 200;     // in miliseconds - max time that a consumer can wait for a product to be produced.

const int max_production = 1;              // When producers has produced this quantity they will stop to produce
const int max_products = 1;                // Maximum number of products that can be stored

//
//      Variables
//
atomic<int> num_producers_working(0);       // When there's no producer working the consumers will stop, and the program will stop.
stack<int> products;                        // The products stack, here we will store our products
mutex xmutex;                               // Our mutex, without this mutex our program will cry

condition_variable is_not_full;             // to indicate that our stack is not full between the thread operations
condition_variable is_not_empty;            // to indicate that our stack is not empty between the thread operations
int counter = 0;

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
    delete data;
	data = NULL;
	return true;
}


// print function for "thread safe" printing using a stringstream
void print(ostream& s) { cout << s.rdbuf(); cout.flush(); s.clear(); }

//reimplement this based on your struct :0
inline int d(int xx, int yy) { return xx * xx + yy * yy; }

void printv(std::vector<long long unsigned int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
    	    std::cout << input.at((i)) << "\n";
		}
}



//std::vector<long long unsigned int > asta tre ret
std::vector<long long unsigned int > read_input_task(){
    std::vector<long long unsigned int > x;
 

    cout << "acu bagi nr de M" << "\n";
	long long unsigned int *M =  new long long unsigned int[1000];
	if( !read_input(M) ){
		cout << "failed to read input";
	}	
  

    cout << "acu bagi nr de N" << "\n";
	long long unsigned int *N =  new long long unsigned int[1000];
	if( !read_input(N) ){
		cout << "failed to read input";
	}	
 

    cout << "acu bagi nr de x1" << "\n";
	long long unsigned int *x1 =  new long long unsigned int[1000];
	if( !read_input(x1) ){
		cout << "failed to read input";
	}	


    cout << "acu bagi nr de x2" << "\n";
	long long unsigned int *x2 =  new long long unsigned int[1000];
	if( !read_input(x2) ){
		cout << "failed to read input";
	}	


    cout << "acu bagi nr de y0" << "\n";
	long long unsigned int *y0 =  new long long unsigned int[1000];
	if( !read_input(y0) ){
		cout << "failed to read input";
	}	
 
    cout << "acu bagi nr de y1" << "\n";
	long long unsigned int *y1 =  new long long unsigned int[1000];
	if( !read_input(y1) ){
		cout << "failed to read input";
	}


    cout << "acu bagi nr de k" << "\n";
	long long unsigned int *k =  new long long unsigned int[1000];
	if( !read_input(k) ){
		cout << "failed to read input";
	}	
    long long unsigned int b = *(M);
    long long unsigned int c = *(N);
    long long unsigned int d = *(x1);
    long long unsigned int e = *(x2);
    long long unsigned int f = *(y0);
    long long unsigned int g = *(y1);
    long long unsigned int h = *(k);

    delete N;
    N = NULL;   delete M;
    M = NULL;   delete x1;
    x1 = NULL;   delete x2;
    x2 = NULL;   delete y0;
    y0 = NULL;   delete y1;
    y1 = NULL;   delete k;
    k = NULL; 
    
    x.push_back(b);
    x.push_back(c);
    x.push_back(d);
    x.push_back(e);
    x.push_back(f);
    x.push_back(g);
    x.push_back(h);

    return x;
    
}


int do_work(
int id,
long long unsigned int *num_rows,
long long unsigned int *num_cols,
long long unsigned int *x0,
long long unsigned int *x1,
long long unsigned int *y0,
long long unsigned int *y1,
long long unsigned int *k
)
{
    if(num_rows == NULL)
    {
        cout << "muie";
    }

    if(num_cols == NULL)
    {
        cout << "muie";
    }
    if(counter == 10){
        return 0;
    }
   
    counter+=1;
    int ans = 0 ;
    long long unsigned int temp = reinterpret_cast<long long unsigned int>(num_rows);
    long long unsigned int temp2 = reinterpret_cast<long long unsigned int>(num_cols);
    long long unsigned int x0_local = reinterpret_cast<long long unsigned int>(x0);
    long long unsigned int y0_local = reinterpret_cast<long long unsigned int>(y0);
    long long unsigned int x1_local = reinterpret_cast<long long unsigned int>(x1);
    long long unsigned int y1_local = reinterpret_cast<long long unsigned int>(y1);


    
    long long unsigned int cases = reinterpret_cast<long long unsigned int>(k);

    for (int i = 0; i <= cases; i++) {
			int j = cases - i;
			int dx = (i - 1) * temp;
			int dy = (j - 1) * temp2;
                
                if (i & 1) {
                    dx += min(temp - y0_local + temp - y1_local , x0_local  + x1_local );
                } else {
                    dx += min(temp - x0_local  + x1_local , x0_local  + temp - x1_local );
			    }

                if (j & 1) {
                    dy += min(temp2 - y0_local  + temp2 - y1_local , y0_local  + y1_local );
                } else {
                    dy += min(temp2 - y0_local  + y1_local , y0_local  + temp2 - y1_local );
                }
            ans = min(ans, d(dx, dy));
    }
    return ans;
}

void produce(int producer_id,
long long unsigned int *T,
long long unsigned int *M,
long long unsigned int *N,
long long unsigned int *x1,
long long unsigned int *x2,
long long unsigned int *y0,
long long unsigned int *y1,
long long unsigned int *k)
{
    while ( *(T) )
    {
        unique_lock<mutex> lock(xmutex);
        int product;
      

        is_not_full.wait(lock, [] { return products.size() != max_products; });
        product = do_work(producer_id,M,N,x1,x2,y0,y1,k);//GenerateNumber();
        
        vector<long long unsigned int> temp = read_input_task();
        long long unsigned int *M = temp[0];
        long long unsigned int *N = temp[1];
        long long unsigned int *x1 = temp[2];
        long long unsigned int *x2 = temp[3];
        long long unsigned int *y0 = temp[4];
        long long unsigned int *y1 = temp[5];
        long long unsigned int *k = temp[6];
       

        products.push(product);

        print(stringstream() << "Producer " << producer_id << " produced " << product << "\n");
        is_not_empty.notify_all();
        cout << *(T);
        *(T)-=1;
    }

}


//      Producer function, this is the body of a producer thread
void producer(int id,
long long unsigned int *T,
long long unsigned int *M,
long long unsigned int *N,
long long unsigned int *x1,
long long unsigned int *x2,
long long unsigned int *y0,
long long unsigned int *y1,
long long unsigned int *k)
{
        long long unsigned int a0_local = reinterpret_cast<long long unsigned int>(T);
        ++num_producers_working;
        for(int i = 0; i < *(T)-1; ++i)
        {
                produce(id,T,M,N,x1,x2,y0,y1,k);
                this_thread::sleep_for(chrono::milliseconds(producer_delay_to_produce));
        }

        print(stringstream() << "Producer " << id << " has exited\n");
        --num_producers_working;
}

//      Consume function, consumer_id will consume a product
void consume(int consumer_id)
{
    while (true)
    {
        unique_lock<mutex> lock(xmutex);
        int product;

        if(is_not_empty.wait_for(lock, chrono::milliseconds(consumer_max_wait_time),
                [] { return products.size() > 0; }))
        {
                product = products.top();
                products.pop();

                print(stringstream() << "Consumer " << consumer_id << " consumed " << product << "\n");
                is_not_full.notify_all();
        }
        else{
            break;
        }
        
    }

}


//      Consumer function, this is the body of a consumer thread
void consumer(int id)
{
        // Wait until there is any producer working
        while(num_producers_working == 0) {
            this_thread::yield();
        }

        while(num_producers_working != 0 || products.size() > 0)
        {
                consume(id);
                this_thread::sleep_for(chrono::milliseconds(consumer_delay_to_consume));
        }

        print(stringstream() << "Consumer " << id << " has exited\n");
}

int main()
{
    cout << "acu bagi nr de T" << "\n";
	long long unsigned int *T =  new long long unsigned int;
	if( !read_input(T) ){
		cout << "failed to read input";
	}	


    vector<long long unsigned int> temp = read_input_task();
    long long unsigned int *M = temp[0];
    long long unsigned int *N = temp[1];
    long long unsigned int *x1 = temp[2];
    long long unsigned int *x2 = temp[3];
    long long unsigned int *y0 = temp[4];
    long long unsigned int *y1 = temp[5];
    long long unsigned int *k = temp[6];

       
    vector<thread> producers_and_consumers;

    //cout << do_work(0,M,N,x1,x2,y0,y1,k);//GenerateNumber();
        

        // Create producers
        for(int i = 0; i < *(T)-1; ++i){
                producers_and_consumers.push_back(thread(producer, i,T,M,N,x1,x2,y0,y1,k));
  
        }

        // Create consumers
        for(int i = 0; i < 1; ++i){
                producers_and_consumers.push_back(thread(consumer, i));
        }

        // Wait for consumers and producers to finish
        for(auto& t : producers_and_consumers){
                t.join();
             
               
        }
    free(T);
    T=NULL;
    return 0;
    
}


