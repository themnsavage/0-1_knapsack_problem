#include<iostream>
#include "KnapSack.cpp"
using namespace std;
int main()
{
    int w[4] = {5,3,4,2};
    int v[4] = {60,50,70,30};
    KnapSack table(w, v, 4, 5);//weights[], values[], size of arrays, total weight/max weight
    cout<<"max value is: "<<table.maxValue()<<endl;
    table.printTable();
    table.itemsChose();
    return 0;

}