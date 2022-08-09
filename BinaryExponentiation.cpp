/*

Binary Exponentiation:

    This method is used to calculate the powers of a number. 

    To calculate a^n we generally multiply 'a' n-times which has complexitiy of O(n).

    But this can be done in O(log n).

    This method is highly useful when we have to take the modulo of a^n with a prime number and n is of order 10^9 or above.


Working Principle:

    Recursive method:

        First we would create a power function which will be called when we need to calculate the power of 'a' raised to 'n'
        power(int a, int n).

        Then we would do:
            if n is odd then-----> power(a,n) = power(a,n/2) * power(a,n/2) * a;        //in case of odd n/2 == (n-1)/2
            if n is even then----> power(a,n) = power(a,n/2) * power(a,n/2);

            Hence power function will be called recursively multiple times.

            Note: We won't call the power(a,n/2) twice. But once and multiply it twice.

    Iterative Method:

        First we convert the n in it's binary form:

            The catch is we compute the power of at a binary digit by multiplying the power at previous binary digit(lower significant bit) twice. 
            Whenever there is one we multiply the answer obtained till that point of time.

*/

//Recursive is easier to implement than iterative method so mostly we'd use recursive method

/******************************************************IMPLEMENTATION**************************************************************/

#include<bits/stdc++.h>
#define mod1 1000000007ll
#define binary(n,k) bitset<k>(n).to_string()
typedef long long ll;
using namespace std;

ll recursive_power(ll a, ll n){
    if(n==0) return 1;a%=mod1;
    ll k = recursive_power(a,n/2);
    if(n%2)return (((k*k)%mod1)*a)%mod1;
    return ((k*k)%mod1);
}
ll iterative_power(ll a, ll n){
    ll ans = 1;
    while(n>0){
        if(n&1)ans = (ans*a)%mod1;
        a = (a*a)%mod1; n>>=1;
    }
    return ans;
}
int main(){
    ll a,n; cin>>a>>n;
    cout<<recursive_power(a,n)<<endl;
    cout<<iterative_power(a,n)<<endl;
}

/************************************************************************************************************************************/