#include <vector>

using namespace std;

int main
{
   vector<vector<int>*> v;
   
   for(int i = 0; i < 10, i++)
   {
      vector<int>* p = new vector<int>(1, i);
      
      v.push_back(p);
   }
   
   //static_cast<string>
   
   return 0;
}