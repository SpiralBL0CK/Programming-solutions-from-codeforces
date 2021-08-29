#include<iostream>
using namespace std;
int c = 0;
struct ad_list { //A structure of type adj_list
   int d;
   ad_list *next;
}
*np = NULL, *np1 = NULL, *p = NULL, *q = NULL;
struct Gr { //A structure of type Gr
   int v;
   ad_list *ptr;
}
arr[6];
void addRevEdge(int s, int d) { //add reverse edges in the graph
   np1 = new ad_list;
   np1->d = s;
   np1->next = NULL;
   if (arr[d].ptr == NULL) {
      arr[d].ptr = np1;
      q = arr[d].ptr;
      q->next = NULL;
   } else {
      q = arr[d].ptr;
      while (q->next != NULL) {
         q = q->next;
      }
      q->next = np1;
   }
}
void addEdge(int s, int d) { // add edges in the graph
   np = new ad_list;
   np->d = d;
   np->next = NULL;
   if (arr[s].ptr == NULL) {
      arr[s].ptr = np;
      p = arr[s].ptr;
      p->next = NULL;
   } else {
      p = arr[s].ptr;
      while (p->next != NULL) {
         p = p->next;
      }
      p->next = np;
   }
}
void print_g(int n) {
   for (int i = 0; i < n; i++) {
      cout << "Adjacency List of " << arr[i].v << ": ";
      while (arr[i].ptr != NULL) {
         cout << (arr[i].ptr)->d<< " ";
         arr[i].ptr = (arr[i].ptr)->next;
      }
      cout << endl;
   }
}
int checkDAG(int n) {
   int count = 0;
   int size = n - 1;
   for (int i = 0; i < n; i++) {
      if (count == size) {
         return 1;
      }
      if (arr[i].ptr == NULL) {
         count++;
         for (int j = 0; j < n; j++) {
            while (arr[j].ptr != NULL) {
               if ((arr[j].ptr)->d == (arr[i].ptr)->d) {
                  (arr[j].ptr)->d = -1;
               }
               arr[i].ptr = (arr[i].ptr)->next;
            }
         }
      }
   }
   return 0;
}

int main() {
   int v = 4;
   cout << "Number of vertices: " << v << endl;
   for (int i = 0; i < v; i++) {
      arr[i].v = i;
      arr[i].ptr = NULL;
   }
   addEdge(1, 0);
   addEdge(3, 1);
   addEdge(2, 1);
   addEdge(0, 3);
   addEdge(4, 1);
   print_g(v);
   cout << "The given graph is 'Directed Acyclic Graph' :";
   if (checkDAG(v) == 1)
      cout << " yes";
   else
      cout << " no";
}