#include <iostream>

using namespace std;

template <class K, class V>
class myMap{
    K key[100];
    V value[100];
    int i;
public:
    myMap()
    {
        i = 0;
    }
    void add(K k, V v)
    {
        key[i] = k;
        value[i] = v;
        i++;
    }
    V get(K k)
    {
        for(int j = 0; j <= i; j++){
            if(key[j] == k){
                return value[j];
            }
        }
        cout << "not found\n";
    }
    int Size()
    {
        return i;
    }
};


int main()
{
    //cout << "Hello\n";
    myMap <char, int> mp;
    mp.add('a', 1);
    mp.add('b', 2);
    //mp.add("c", 3);

    cout << mp.get('b') << endl;
    //mp.get("c");
}
