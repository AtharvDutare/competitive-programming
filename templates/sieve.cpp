#include <bits/stdc++.h>
using namespace std;
vector<ll> sieve(ll lm) {
    //O(NloglogN)
    //assume all are prime
    vector<bool> is_prime(lm + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(ll i=2;i*i<=lm;i+=1) {
        if(is_prime[i]){
            for (ll j=i*i;j<=lm;j+=i) {
                is_prime[j] = false;
            }
        }
    }   
    vector<ll> primes;
    for (ll i=2;i<=lm;i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}