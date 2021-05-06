#include<iostream>
#include<vector>
using namespace std;
class KnapSack
{
private:
    
    //variables
    int totalWeight;
    int numberOfItems;
    vector<int> weights;
    vector<int> values;
    vector<vector<int>> table; // allocated table for dynamic programming 
    //healper functions
    void KnapSackAlgorithm() // fills in table 0
    {
        for(int i = 0; i < numberOfItems; i++) // loop through each item
        {
            for(int w = 0; w <= totalWeight; w++) // loop through each weight sub-problems 
            {
                
                if(w == 0) // if weight is 0 or when first item(no item to take from above)
                {
                    table[i].push_back(0);
                }
                else if(i == 0) // when we are iterating the first item 
                {
                    if(weights[i] <= w) // if we can choose first item
                    {
                        table[i].push_back(values[i]);
                    }
                    else // we can't use first item and can't take from above becasuse not item above exists 
                    {
                        table[i].push_back(0); 
                    }
                }
                else
                {
                    if(weights[i] <= w && (table[i - 1][w - weights[i]] + values[i]) > table[i - 1][w]) // we can choose item and if new value added has a bigger value than above item
                    {
                        table[i].push_back(table[i - 1][w - weights[i]] + values[i]); 
                    }
                    else // we can't use item, so take item from above and if item with new value added is not bigger than top value
                    {
                        table[i].push_back(table[i - 1][w]);
                    }
                }
            }
        }
    }
public:

    void printTable()
    {
       cout<<"Table:"<<endl;
        for(int i = 0; i < numberOfItems; i++)
        {
            for(int j = 0; j <= totalWeight; j++)
            {
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    int maxValue()
    {
        return table[numberOfItems - 1][totalWeight];
    }

    void itemsChose()
    {
        int i = numberOfItems - 1;
        int w = totalWeight;
        cout<<"Items used: ";
        while(table[i][w] != 0)
        {
            if(table[i][w] == table[i - 1][w]) // if cell above is same value then item was not use
            {
                i--; // move up one cell
            }
            else // above cell is not same value so item was use
            {
                cout<<i+1<<" ";
                w = w - weights[i];
                i--;
            }
        }
        cout<<endl;
    }

    //constructor, destructor, and copy constructor/operator
    KnapSack(){}
    KnapSack(int *w, int *v, int size, int t)
    {
        totalWeight = t;
        numberOfItems = size;
        for(int i = 0; i < size; i++)
        {
            weights.push_back(w[i]);
            values.push_back(v[i]);
        }
        table.reserve(size * t);
        KnapSackAlgorithm(); // fill in table 
    }
    KnapSack(KnapSack const &object)
    {
        totalWeight = object.totalWeight;
        weights = object.weights;
        table = object.table;
        values = object.values;
    }
    KnapSack& operator=(const KnapSack object)
    {
        if(this != &object)
        {
            totalWeight = object.totalWeight;
            weights = object.weights;
            table = object.table;
            values = object.values;
        }
        return *this;
    }
    ~KnapSack()
    {
        weights.clear();
        values.clear();
        table.clear();
    }
};

