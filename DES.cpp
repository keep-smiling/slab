#include <bits/stdc++.h>
using namespace std;
string Permutation(vector<int> array, string inp){
    string out = "";
    for(int i=0;i<array.size();i++)
        out += inp[array[i]-1];
    return out;
}
class S_DES{
public:
    string KEY,K1,K2,IPOut,InvIPOut;
    string F1Out;
    string INPUT,OUTPUT;
    void initialize(string key){
        if(key.size()!=10){
            cout<<"\nInValid Key-Length "<<key<<" "<<key.size();
            exit(1);
        }
        KEY = key;
	    Keys_Generation();
	}
    void Keys_Generation(){
        
        vector<int> P10(10);
		int sak[10]={3 ,5, 2, 7, 4, 10, 1, 9, 8, 6};
        for(int i=0;i<10;i++)
            P10[i]=sak[i];
        string P10_output = Permutation(P10,KEY);
        cout<<"P10 output while generating key: "<<P10_output<<endl;
        string P10_left = P10_output.substr(0,5), P10_right = P10_output.substr(5,5);
        string pl = LShift(P10_left,1), pr = LShift(P10_right,1);
        string plpr = pl+pr;
       
        vector<int> P8(10,0);
        int sak1[8]={6, 3, 7, 4, 8, 5, 10, 9};
        for(int i=0;i<8;i++)
            P8[i]=sak1[i];
        K1 = Permutation(P8,plpr);
        cout<<"K1: "<<K1<<endl;
	    string pl1=LShift(pl,2), pr1=LShift(pr,2);
        plpr = pl1+pr1;
        K2 = Permutation(P8,plpr);
        cout<<"K2: "<<K2<<endl;
    }

	string LShift(string input,int n){
        string output = input;
        char firstbit;
	    while(n--){
            firstbit = output[0];
            output = output.substr(1,output.size()-1);
            output += firstbit;
        }
        return output;
    }
    void DES_Encryption(){
	    IP();
        string LIP = IPOut.substr(0,4);
        string RIP = IPOut.substr(4,4);
        cout<<"IP output: "<<IPOut<<endl;
        Function_F(LIP,RIP,1);
        cout<<"Fn Output: "<<F1Out<<endl;
        string L1 = F1Out.substr(0,4), R1 = F1Out.substr(4,4);
	    Function_F(R1,L1,2);
        cout<<"Fn Output second time: "<<F1Out<<endl;
        InvIP(F1Out);
        cout<<"Encrypted Cipher-string: "<<InvIPOut<<endl;
	}
    /*Method to perform Initial-Permutation*/
	void IP(){
        vector<int> IP_array(8,0);
        int number[8]={2, 6, 3, 1, 4, 8, 5, 7};
        
        for(int i=0;i<8;i++)
            IP_array[i]=number[i];
        IPOut = Permutation(IP_array,INPUT);
	}
    /*Method to perform Inverse of Initial-Permutation*/
    void InvIP(string input){
    vector<int> InvIPArray(8,0);
    int number[8]={4, 1, 3, 5, 7, 2, 8, 6};
    for(int i=0;i<8;i++)
        InvIPArray[i]=number[i];
    InvIPOut = Permutation(InvIPArray,input);
    }
	void Function_F(string linput,string rinput,int key)
	{
        
        vector<int> E_P(8,0);
        int nn2[8]={4, 1, 2, 3, 2, 3, 4, 1};
        for(int i=0;i<8;i++)
            E_P[i]==nn2[i];
        string E_POutput = Permutation(E_P,rinput);
        string EXOR_Output;
        if(key == 1)
            EXOR_Output = EX_OR(E_POutput,K1);
        else
            EXOR_Output = EX_OR(E_POutput,K2);
        string LEXOR = EXOR_Output.substr(0,4),REXOR = EXOR_Output.substr(4,4);
        string SBOX0_Output=SBOX0(LEXOR);
        string SBOX1_Output=SBOX1(REXOR);
        string SBOX_Output = SBOX0_Output+SBOX1_Output;
        
        vector<int> P4(4,0);
        int v4[4]={2, 4, 3, 1};
        for(int i=0;i<4;i++)
            P4[i]=v4[i];
        string P4_Output = Permutation(P4,SBOX_Output);
        string fk_Output = EX_OR(P4_Output,linput);
        F1Out = fk_Output + rinput;
	}
	string EX_OR(string a,string b){
        string output = "";
        for(int i=0;i<a.size();i++){
            if(a[i] == b[i])
                output += "0";
            else
                output += "1";
        }
        return output;
	}
    string SBOX0(string l)
	{
        
        vector<int> temp(4,0);
        vector<vector<int> > S0(4,temp);
        int number[4][4]={
		{1, 0, 3, 2},
		{3, 2, 1, 0},
		{0, 2 ,1, 3},
		{3, 1, 3, 2}
		};
        for(int i=0;i<4;i++){
            for(int j = 0;j<4;j++)
                S0[i][j]=number[i][j];
        }
        string bits[]={"00","01","10","11"};
	    string lrow = l.substr(0,1)+l.substr(3,1),lcol = l.substr(1,1)+l.substr(2,1);
	    string SO;
        int i,lr,lc,b;
        for(i=0;i<4;i++){
            if(lrow == bits[i])
                lr=i;
            if(lcol == bits[i])
                lc=i;
        }
        b=S0[lr][lc];
        return bits[b];
	}
    string SBOX1(string l)
	{
        
        vector<int> temp(4,0);
        vector<vector<int> > S0(4,temp);
        int number[4][4]={
		{0, 1, 2, 3},
		{2, 0, 1, 3},
		{3, 0 ,1, 0},
		{2, 1, 0, 3}
		};
        for(int i=0;i<4;i++){
            for(int j = 0;j<4;j++)
                S0[i][j]=number[i][j];
        }
        string bits[]={"00","01","10","11"};
	    string lrow = l.substr(0,1)+l.substr(3,1),lcol = l.substr(1,1)+l.substr(2,1);
	    string SO;
        int i,lr,lc,b;
        for(i=0;i<4;i++){
            if(lrow == bits[i])
                lr=i;
            if(lcol == bits[i])
                lc=i;
        }
        b=S0[lr][lc];
        return bits[b];
	}
};
int main()
{
    int i,n=10,choice;
    string key;
    S_DES S;
    cout<<"\nEnter the 10-bits KEY: ";
            cin>>key;
            cout<<"\nNotedown this key, as same key is used for Decryption\n";
            S.initialize(key);
            cout<<"Enter string to encrypt: ";
            cin>>S.INPUT;
            S.DES_Encryption();
    
    return 0;
}
