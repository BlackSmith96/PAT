#include <iostream>
#include <cstdlib>
using namespace std;

long int gcd(long int a, long int b) {
    int t;
    for(;b != 0;) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main() {
    int N;
    cin >> N;
    long int sum_numerator = 0, sum_denominator = 1;
    long int numerator, denominator;
    char ch;

    for(int i = 0;i < N;++i) {
        cin >> numerator >> ch >> denominator;

        long int t_numerator = sum_denominator * numerator + sum_numerator * denominator;
        long int t_denominator = sum_denominator * denominator;
        long int common_part = gcd(abs(t_numerator),abs(t_denominator));
        sum_numerator = t_numerator / common_part;
        sum_denominator = t_denominator / common_part;
    }

    int integer_part = 0;
    if(sum_numerator > sum_denominator) {
        integer_part = sum_numerator / sum_denominator;
        sum_numerator %= sum_denominator;
    }

    if(integer_part){
        cout << integer_part;
        if(sum_numerator != 0)
            cout << ' ';
    }
    if(sum_numerator)
        cout << sum_numerator << '/' << sum_denominator;

    if(integer_part == 0 && sum_numerator == 0)
        cout << 0;
    return 0;
}