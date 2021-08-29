#include <iosteram>

using namespace std;

int main()
{
    int n,s;
    cin >> n >> s;
    if(2*n < s){
        cout << "yes";
        for(int i = 0 ; i < n-1;i++)
        {
            cout << 2 << " ";
            s-=2;
        }
        cout << s << '\n';
        cout << 1;
    }
    else{
        cout << "NO";
    }
    return 0;
}

//https://www.cyberforum.ru/algorithms/thread2698239.html