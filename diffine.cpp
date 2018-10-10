#include<bits/stdc++.h>
using namespace std;
// Power function to return value of a ^ b mod P
long long int power(long long int a, long long int b,
                                     long long int P)
{ 
    if (b == 1)
        return a;
 
    else
        return (((long long int)pow(a, b)) % P);
}
 

int main()
{
    long long int P, G, x, a, y, b, ka, kb; 
     
    cout<<"Enter number P"<<endl;
    cin>>P; 
    printf("The value of P : %lld\n", P); 
 	cout<<"Enter number G"<<endl;
    cin>>G;
    printf("The value of G : %lld\n\n", G); 
 
    cout<<"Enter number a"<<endl;
    
    cin>>a; 
    printf("The private key a for Alice : %lld\n", a);
    x = power(G, a, P); 
     
    cout<<"Enter number b"<<endl;
    cin>>b;
    printf("The private key b for Bob : %lld\n\n", b);
    y = power(G, b, P); 
 
   
    ka = power(y, a, P);
    kb = power(x, b, P);
     
    printf("Secret key for the Alice is : %lld\n", ka);
    printf("Secret Key for the Bob is : %lld\n", kb);
     
    return 0;
}
