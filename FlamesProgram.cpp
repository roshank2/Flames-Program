#include <iostream>
#include<stdio.h>
#include<cstring>
#include<bits/stdc++.h>

using namespace std;

class flames
{
    string yname, cname;
public:

    void inputdata()
    {
        cout<<"\nEnter your Name: ";
        getline(cin,yname);
        transform(yname.begin(), yname.end(), yname.begin(), ::tolower);
        yname.erase(std::remove_if(yname.begin(), yname.end(), ::isspace), yname.end());

        cout<<"Enter your Partner's Name: ";
        getline(cin,cname);
        transform(cname.begin(), cname.end(), cname.begin(), ::tolower);
        cname.erase(std::remove_if(cname.begin(), cname.end(), ::isspace), cname.end());
    }

    string repeat(string s, int n)
{
    string s1 = s;

    for (int z=1; z<n;z++)
        s += s1;
    return s;
}

    string calc()
    {

        for(int i=0;i<yname.length();i++)
        {
            for(unsigned int j=0;j<cname.length();j++)
            {
                if(yname[i]==cname[j])
                {
                    yname.erase(i,1);
                    cname.erase(j,1);
                    i=-1;
                }
            }

        }

       unsigned int cnt=yname.length()+cname.length();

       //cout<<yname<<endl<<cname<<endl;

      // cout<<cnt;

            string fl="FLAMES";
            unsigned int m=0;
            char ch2;

            while(fl.length()>1)
        {
        int k;
        if(cnt>=fl.length())
        {
            k=cnt/fl.length()+2;
        }
        else
        {
            k=fl.length()/cnt+2;
        }

        string retfl=repeat(fl,k);
        //cout<<retfl<<endl;
        for(unsigned int l=m;l<retfl.length();l++)
        {
            if((l+1)==(cnt+m))
            {
            ch2=retfl[l];
            //cout<<ch2<<endl;
            }
        }

        for(unsigned int n=0;n<fl.length();n++)
        {
            if(ch2==fl[n])
            {
                m=n;
                fl.erase(n,1);
            }
        }

        }
        return fl;
    }

    void disp()
        {
            string ch;
            if(yname==cname)
                ch="F";
            else
                ch=calc();

        switch(ch[0])
        {
        case 'F':
            cout<<"\nFriendship"<<endl;
            break;
        case 'L':
            cout<<"\nLove"<<endl;
            break;
        case 'A':
            cout<<"\nAffection"<<endl;
            break;
        case 'M':
            cout<<"\nMarriage"<<endl;
            break;
        case 'E':
            cout<<"\nEnemy"<<endl;
            break;
        case 'S':
            cout<<"\nSibling"<<endl;
            break;
        default:
            cout<<"\nInvalid"<<endl;
            break;
        }
    }
};

int main()
{
    flames f1;
    cout << "\n\t\tF.L.A.M.E.S"<< endl;
    f1.inputdata();
    f1.disp();
    return 0;
}
