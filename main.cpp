#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

vector<bool> eratosthenes(int n){
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n;++i){
        if(!is_prime[i]) continue;
        for (int j = 2; j * i <= n;++j)
            is_prime[i * j] = false;
    }
    return is_prime;
}

int main()
{
    // Get input.
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> n;
    while (getline(ss, s, ' '))
    {
        n.push_back(stoi(s));
    }

    // get prime numbers each of that is less than 100,000.
    int n_prime_numbers = 100000;
    vector<bool> is_prime = eratosthenes(n_prime_numbers);
    vector<int> prime_numbers;
    for (int i = 2; i < n_prime_numbers; ++i)
    {
        if(is_prime[i])
            prime_numbers.push_back(i);
    }

    // Check whether inputs cover all prime numbers each of that is less than 100,000.
    sort(n.begin(), n.end());
    sort(prime_numbers.begin(), prime_numbers.end());
    if(n.size()!=prime_numbers.size()){
        cout << "Incorrect." << endl;
        return 0;
    }
    for (int i = 0; i < n.size();++i)
    {
        if(n[i]<=0 || n[i] != prime_numbers[i]){
            cout << "Incorrect." << endl;
            return 0;
        }
    }
    cout << "Correct." << endl;
    return 0;
}