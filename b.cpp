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

#define ROW 4
#define COL 5

uint64_t minu(unsigned long  int a, unsigned  long int b)
{
    return (a < b) ? a : b;
}
 
// A utility function to find min
// of three uint64_tegers
uint64_t minz(uint64_t a, uint64_t b, uint64_t c)
{
    return minu(minu(a, b), c);
}
 
// A utility function to find
// max of two uint64_tegers
uint64_t max(uint64_t a, uint64_t b)
{
    return (a > b) ? a : b;
}

bool mult_with_overflow_check(){
    cout << "baa nesimtitule vrei sa faci mare hack;muie nu!";
    return true;
}
/*

uint64_t mult_with_overflow_check(uint64_t a, uint64_t b) {
  if (a > b) return mult_with_overflow_check(b, a);
  if (a > UINT32_MAX) overflow();
  uint32_t c = b >> 32;
  uint32_t d = UINT32_MAX & b;
  uint64_t r = a * c;
  uint64_t s = a * d;
  if (r > UINT32_MAX) overflow();
  r <<= 32;
  return addition_with_overflow_check(s, r);
}*/

void printMatrix(map<uint64_t,map<uint64_t,uint64_t>>& matrix)
{
    if(matrix.empty()){
        cout << "matrix is NULL";
    }

    for(auto & outer_map_pair : matrix) {
        for(auto & inner_map_pair : outer_map_pair.second) {
            printf("%lu     ",inner_map_pair.second);
        }
        cout << "\n";
    }
}

void diagonalOrder(map<uint64_t,map<uint64_t,uint64_t>>& matrix)
{
    if(matrix.empty()){
        cout << "matrix is NULL";
    }

    for(int line = 1;line <= (ROW + COL - 1);line++)
    {
        /* Get column index of the first element
           in this line of output.
           The index is 0 for first ROW lines and
           line - ROW for remaining lines  */
        int start_col =  max(0, line - ROW);
 
        /* Get count of elements in this line. The
           count of elements is equal to minimum of
           line number, COL-start_col and ROW */
         int count = minz(line, (COL - start_col), ROW);
    
        /* Print elements of this line */
        for(int j = 0; j < count; j++)
            cout << setw(5) <<
            matrix[minu(ROW, line) - j - 1][start_col + j];
 
        /* Print elements of next
           diagonal on next line */
        cout << "\n";
    }

}



void insertintomatrix(map<uint64_t,map<uint64_t,uint64_t>>& matrix,vector<int>&lista)
{
    map<uint64_t,map<uint64_t,uint64_t>> temp;
    temp[0][0] = 0;
    temp[1][0] = 0;
    temp[0][1] = 0;
    bool done_list;
    int counter_lista = 0;

    printMatrix(temp);

    if(matrix.empty()){
        cout << "matrix is NULL";
    }

    for(int line = 1;line <= (ROW + COL - 1);line++)
    {
        /* Get column index of the first element
           in this line of output.
           The index is 0 for first ROW lines and
           line - ROW for remaining lines  */
        int start_col =  max(0, line - ROW);
 
        /* Get count of elements in this line. The
           count of elements is equal to minimum of
           line number, COL-start_col and ROW */
         int count = minz(line, (COL - start_col), ROW);
    
        /* Print elements of this line */
        for(int j = 0; j < count; j++){
            counter_lista+=1;
            if(counter_lista == lista.size())
            {
                done_list = true;
            }
            if(done_list)
            {
                //aici faci read_input(lista) si process si aia e :)   
            }
            temp[minu(ROW, line) - j - 1][start_col + j] = j;
            cout << setw(5) <<
            temp[minu(ROW, line) - j - 1][start_col + j];
        }
 
        /* Print elements of next
           diagonal on next line */
        cout << "\n";
    }
    printMatrix(temp);


}


void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
    	    std::cout << input.at((i)) << "\n";
		}
}

void convert(vector<int>&lista,int n)
{
    int base = 1;
 
    int temp = n;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        lista.push_back(last_digit);
    }
}

int main()
{
    map<uint64_t,map<uint64_t,uint64_t>> matrix;
    
    //just test functionality
    matrix[0][0] = 0;
    matrix[1][0] = 2;
    matrix[0][1] = 1;
    printMatrix(matrix);
    diagonalOrder(matrix);
    uint64_t width;
    uint64_t height;
    vector<int> list;
    insertintomatrix(matrix,list);

    cin >> width;
    cin >> height;
    convert(list,width);
    std::reverse(list.begin(),list.end());    // 9 8 7 6 5 4 3 2 1
    print(list);
    return 0;
}