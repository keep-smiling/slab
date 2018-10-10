#include<bits/stdc++.h>
using namespace std;
void comp(string str,int k)
{
        int n=str.length();
        string res="";
        for(int i=0;i<n;i++)
        {
        
                if(str[i]>='a' && str[i]<='z')
                res+=char( (int(str[i])+k-97)%26 + 97  );
                else
                 res+=char( (int(str[i])+k-65)%26 + 65  );
        }
        cout<<"Encrypted message : ";
        cout<<res<<endl;
        
        str="";
        
        for(int i=0;i<n;i++)
        {
                if(res[i]>='a' && res[i]<='z')
                str+=char( (int(res[i])-k-97+26)%26 + 97  );
                else
                str+=char( (int(res[i])-k-65+26)%26 + 65  );
        }
        cout<<"Decrypted message : ";
        cout<<str<<endl;

}
int main()
{
        string str;
        int k;
        cout<<"Enter text and key value"<<endl;
        cin>>str;
        cin>>k;
        comp(str,k);
        return 0;
}
