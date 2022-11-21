#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int main()
{
  string genes; 
  cin >> genes; 
  string genesFolding; 
  genesFolding.resize(2 * genes.size() + 1); 
  int i = 0; 
  for (auto c : genes) 
    genesFolding[2 * i] = '#', 
    genesFolding[2 * i + 1] = c, 
    ++i; 
    genesFolding.back() = '#';  
  
  vector<int> radio(genesFolding.size(), 0);         
  int cabeza = 0, cola = genesFolding.size() - 1;    
  int radioBordo = -1, centro = -1;                  
  for (int i = 0; i < genesFolding.size(); ++i)  
  {  
    radio[i] = radioBordo >= i ? min(radio[centro + centro - i],
    radioBordo - i) : 1;

    while (i + radio[i] < genesFolding.size() && i - radio[i] >= 0 && genesFolding[i + radio[i]] == genesFolding[i - radio[i]])  
      ++radio[i];

    if (i + radio[i] - 1 > radioBordo) 
      radioBordo = i + radio[i] - 1, centro = i;  

    if (i % 2 == 0 && radio[i] - 1 >= i - cabeza) 
    
      cabeza = i, cola = i + radio[i] - 1;
  }
  for (int i = genesFolding.size() - 1; i >= cabeza; i -= 2) 
    if (radio[i] - 1 >= cola - i) 
      cola -= min(i - cabeza, cola - i); 

  int respuesta = (cola - cabeza) / 2; 
  cout << respuesta; 

}
