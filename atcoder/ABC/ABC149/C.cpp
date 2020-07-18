#include <iostream>
#include <vector>
#include <math.h>

#define Nmax 1000000
using namespace std;

//エラトステネスの篩
vector<long long> Primes;
void Eratosthenes(int N){
    Primes.resize(N);
	for(int i = 0; i < N; i++){
		Primes[i] = 1;
	}
	for(int i = 2; i*i < N; i++){
		if(Primes[i]){
			for(int j = 0; i * (j + 2) < N; j++){
				Primes[i *(j + 2)] = 0;
			}
		}
	}
}

//素数
int main(int argc, char const *argv[]){
    int a;
    cin >> a;
	Eratosthenes(a);
	return 0;
}
