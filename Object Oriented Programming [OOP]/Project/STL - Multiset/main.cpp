#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

multiset <ll> shops;

void display()
{
    ofstream fp("Chocolates.txt", ios::app);  // Open file for writing

    if (!fp.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    fp << "Available chocolates : ";
    for (const auto &chocolate : shops) {
        fp << chocolate << " ";
    }
    fp << "\n";
    fp.close();  // Close the file
}

int main()
{
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        ll chocolates;
        cin >> chocolates;
        shops.insert(chocolates);
    }
    ll total = 0;
    for(int i = 0; i < k; i++){
        display();
        auto last_it = (--shops.end());
        ll buy = *last_it;
        total += buy;
        shops.erase(last_it); // To delete only last one from where purchased
        shops.insert(buy/2);
    }
    cout << total << endl;
}
