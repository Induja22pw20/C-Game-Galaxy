
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<string>
using namespace std;
class MAINPLAYER
{
        protected:
        string team_name;
        int money=0;
        public:
        void get_data()
        {
                cout<<"enter your team name";
                getline(cin,team_name);
                cout<<"enter the money you have";
                cin>>money;
        }
        void plusmoney(int a)
        {
                money=money+a;
        }
        void minusmoney(int b)
        {
                money=money-b;
        }
        void displaying()
        {
                try{
                        if(money<0)
                        {
                                throw "YOUR RUNNING OUT OF WALLET";
                        }
                        else
                        {
                                cout<<"_______________________________________________THE TOTAL AMOUNT EARNED IS="<<money<<"_______________________________________________________\n";
                                cout<<"THANK YOU FOR PARTICIPATING\t"<<team_name<<"------------------------:)";
                        }
                }
                catch(const char *message)
                {
                        cout<<message<<endl;
                }

        }
        virtual void  money_display()
        {
                cout<<"THE MONEY YOU ARE LEFT WITH"<<money<<endl;
        }
        friend int chm(MAINPLAYER);
};
int chm(MAINPLAYER ob)
{
        return ob.money;//returning current money balance
}
//__________________________________________________________________________________
class word:public MAINPLAYER
{
        private:
                string word[4]={"classroom","ball","apple","pushup"};
                string check[4]={"lcssrmoao","lbal","laepp","upuhsp"};
                int point;
        public:
                void getdetails();
                void display(int score);
                void money_display()
                {
                        cout<<"THE MONEY YOU ARE LEFT WITH"<<money<<endl;
                }
};
void word::getdetails()
{
        string ans;
        int correct=0;
        for(int i=0;i<4;i++)
        {
                cout<<check[i]<<endl;
                cout<<"ENTER THE CORRECT FORM OF THE JUMBLED WORDS"<<endl;
                getline(cin,ans);
                if(ans==word[i])
                {
                        cout<<"CONGRALUATIONS!..YOUR ANSWER IS CORRECT"<<endl;
                        correct++;
                }
                else
                 {
                        cout<<"SORRY!..YOUR ANSWER IS WRONG"<<endl;
                }
        }
        display(correct);
}
void word::display(int correct)
{
        cout<<"YOUR TOTAL SCORE IS "<<correct<<endl;
        money+=correct;//accessing data member of base class
}
//____________________________________________________________________________________$
class number:public MAINPLAYER
{
        public:
                void getdetails1();
                void display1(int point);
                void money_display()
                {
                        cout<<"THE MONEY YOU ARE LEFT WITH"<<money<<endl;
                }
};
void number::getdetails1()
{
 int point=0;
        int ans1;
        cout<<"12,11,13,12,14,13"<<endl;
        cout<<"WHAT IS THE NEXT NUMBER"<<endl;
        cin>>ans1;
        if(ans1==15)
        {
                cout<<"YOUR ANSWER IS CORRECT"<<endl;
                point++;
        }
        else
        {
                cout<<"SORRY! YOUR ANSWER IS WRONG"<<endl;
        }
        cout<<"80,10,70,15,60"<<endl;
        cout<<"WHAT IS THE NEXT NUMBER"<<endl;
        cin>>ans1;
        if(ans1==20)
        {
                cout<<"YOUR ANSWER IS CORRECT"<<endl;
                point++;
         }
        else
        {
                cout<<"YOUR ANSWER IS WRONG"<<endl;
        }
        cout<<"7,10,8,9,12"<<endl;
         cout<<"WHAT IS THE NEXT NUMBER"<<endl;
        cin>>ans1;
        if(ans1==10)
        {
                cout<<"YOUR ANSWER IS CORRECT"<<endl;
                point++;
                point++;
        }
        else
        {
                cout<<"YOUR ANSWER IS WRONG"<<endl;
        }

        display1(point);
};
void number::display1(int point)
{
        cout<<"YOUR TOTAL POINTS IS :"<<point<<endl;
        money+=point;
}
//____________________________________________________________________________
void displayp(char p[3][3])
{
    int i,j;
    cout<<"------------\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<" "<<p[i][j]<<" |";
        }
        cout<<"\n------------";
        cout<<"\n";
    }
}
int indexi(int a)
{
    if(a<=3 && a>=1)
    {
        return 0;
    }
    else if(a<=6)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
int indexj(int b)
{
    if(b%2==0)
    {
        if(b==4)
        {
            return 0;
        }
        else if(b==6)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    else if(b%3==0)
    {
        return 2;
    }
    else
    {
        if(b==1||b==7)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
//___________________________________________________________________
void ded(int x,char ho[])
{
    int i;
    cout<<"\nTOTAL LIFE\n";
    for(i=0;i<x;i++)
    {
        cout<<ho[i]<<"\t";
    }
}
int check(char a,char s[],int len)
{
    int i,c=0;
    for(i=0;i<len;i++)
    {
        if(a==s[i])
        {
            cout<<s[i]<<"\t";
            c++;
        }
        else
        {
            cout<<"__\t";
        }
    }
    cout<<c;
    if(c!=0)
    {
        return c;
    }
    else
    {
        return 0;
    }
}
//_______________________________________________________
class who:public MAINPLAYER
{
    public:
    string hint[5];
public:
    void display(int x)
    {
        cout<<hint[x];
    }
    friend void set_data(who);

};
void set_data(who ob[])
{
    ob[0].hint[0]="i was born in Allahabad\n";
    ob[0].hint[1]="my daughter is also a famous person\n";
    ob[0].hint[2]="my birthday is on 14th November\n";
    ob[0].hint[3]="i am the first prime minister of India\n";
    ob[0].hint[4]="children likes me very much\n";
    ob[1].hint[0]="i am a cricket player\n";
    ob[1].hint[1]="i play for csk\n";
    ob[1].hint[2]="number 7\n";
    ob[1].hint[3]="i am well known for my helicopter shot\n";
    ob[1].hint[4]="my nick name is mahi\n";
    ob[2].hint[0]="i am an actor\n";
    ob[2].hint[1]="my family members are also actors\n";
    ob[2].hint[2]="i am also a polititian\n";
    ob[2].hint[3]="i am well known for my acting\n";
    ob[2].hint[4]="i represented India at many international meet\n";
     ob[3].hint[0]="i am a singer\n";
    ob[3].hint[1]="i also mimic my voice as kids voice in movies\n";
    ob[3].hint[2]="i have won 4 National Film awards\n";
    ob[3].hint[3]="i am also called as Isaikuyil\n";
    ob[3].hint[4]="i am the nightingale of south India\n";
    ob[4].hint[0]="i am a dancer\n";
    ob[4].hint[1]="i introduced a new era of dancing\n";
    ob[4].hint[2]="i was also famous in north India but i was born and introduced in south india";
    ob[4].hint[3]="my father and my brothers are also dancers\n";
    ob[4].hint[4]="a dance show was also conducted with my name\n";
}
int main()
{
        MAINPLAYER mp;
        int len,w=0,l=0,c,val;
        string mytext;
        char g[20];
        string p1,p2;
        char str[20];
        char h[9]={'H','O','L','L','Y','W','O','O','D'};
        char guess;
        int m,n,i1,j1,k1,l1,v,pointsp=0,deduct=0;
        char puzz[3][3];
        int mainchoice,i;
        string wordx;
        word wo;
        number no;
        MAINPLAYER *b_ptr[2];
        b_ptr[0]=&wo;
        b_ptr[1]=&no;
        ifstream myfile("warning.txt");
        while(getline(myfile,mytext))
        {
                cout<<endl;
                cout<<mytext<<endl;
        }
        myfile.close();
        cout<<"__________________________________________________________WELCOME TO THE GAME OF PUZZLES_________________________________________________\n";
        cout<<"LET'S START\n";
        mp.get_data();
         while(1)
        {
                if(chm(mp)==0)
                {
                        cout<<"_____________________________SORRY YOU DON'T HAVE ENOUGH MONEY TO PLAY THIS GAME__________________________\n";
                        break;
                }
                cout<<"\n1.JUMBLED WORD\n2.NUMBER PUZZLE\n3.MEMORY GAME\n4.HOLLYWOOD\n5.GUESS MY NAME\n6.EXIT\n";
                cin>>mainchoice;
                cin.ignore(1,'\n');
                if(mainchoice==1)
                {
                        wo.getdetails();
                        b_ptr[0]->money_display();
                        ofstream check("point.txt");
                        check<<"THE GAME PLAYED IS JUMBLED WORDS"<<endl;
                        check.close();
                }
                else if(mainchoice==2)
                {
                        no.getdetails1();
                        b_ptr[1]->money_display();
                        ofstream check("point.txt");
                        check<<"THE GAME PLAYED IS NUMBER PUZZLE"<<endl;
                        check.close();
                }
                  else if(mainchoice==3)
                {                         puzz[0][0]='$';
                          puzz[0][1]='#';
                          puzz[0][2]='&';
                          puzz[1][0]='*';//bonus points
                          puzz[1][1]='#';
                          puzz[1][2]='@';
                          puzz[2][0]='&';
                          puzz[2][1]='$';
                          puzz[2][2]='@';
                          cout<<"if you want to display the puzzle press 1";
                          cin>>v;
                          if(v==1)
                          {
                                displayp(puzz);
                          }
                          while(1)
                          {
                                 l1:cout<<"enter your first choice";
                                cin>>m;
                                i1=indexi(m);
                                j1=indexj(m);
                                if(m==4)
                                {
                                        pointsp++;
                                }
                                cout<<"the character is\t"<<puzz[i1][j1]<<"\n";
                                cout<<"enter your second choice";
                                cin>>n;
                                if(n==4)
                                {
                                        pointsp++;
                                }
                                k1=indexi(n);
                                l1=indexj(n);
                                if(puzz[i1][j1]=='0'||puzz[k1][l1]=='0')
                                {
                                        deduct+=1;
                                        cout<<"wrong input\n";
                                        goto l1;
                                }

                                if(puzz[i1][j1]==puzz[k1][l1])
                                {
                                        cout<<"hurray!correct\n";
                                        cout<<"________________________first choice\t"<<puzz[i1][j1]<<"\n"<<"________________________second choice\t"<<puzz[k1][l1]<<"\n";
                                        puzz[i1][j1]='0';
                                        puzz[k1][l1]='0';
                                        pointsp+=2;
                                         if(pointsp==9)
                                        {
                                                cout<<"______________________!!!!!!!you win!!!!!!!_______________________\n";
                                                mp.plusmoney(100);
                                                break;
                                        }
                                }
                                else
                                {
                                        cout<<"no you are wrong\n";
                                        deduct+=2;
                                        cout<<"________________________first choice\t"<<puzz[i1][j1]<<"\n"<<"____________________________second choice\t"<<puzz[k1][l1]<<"\n";
                                        if(deduct>9)
                                        {
                                                cout<<"______________________#############GAME OVER##########___________________________\n";
                                                displayp(puzz);
                                                mp.minusmoney(100);
                                                break;
                                        }

                                }
                        }
                         ofstream check("point.txt");
                        check<<"THE GAME PLAYED IS MEMORY GAME"<<endl;
                        check.close();
                }
                else if(mainchoice==4)
                {
                         cout<<"___________________________WELCOME TO HOLLYWOOD GAME______________________________\n";
                         cout<<"enter the name of player 1";
                         cin>>p1;
                         cout<<"enter the name of player 2";
                         cin>>p2;
                         cout<<"so\t"<<p1<<"\t and\t"<<p2<<"\t lets start\n";
                         cout<<"TOTAL LIFE\n";
                         for(i=0;i<9;i++)
                         {
                                 cout<<h[i]<<"\t";
                         }
                         cout<<"\n";
                         cout<<p1<<"....enter the length word that\t"<<p2<<"\thas to find";
                         cin>>len;
                         cin.ignore(1,'\n');
                         deduct=9;
                         cout<<"\n enter the word\n";
                         for(i=0;i<len;i++)
                         {
                                 cin>>str[i];
                         }
                         cout<<p2<<"......GAME STARTS......\n";
                         c=0;
                         while(1)
                         {
                                 l2:cout<<"\n enter your guess";
                                 cin>>guess;
                                 for(i=0;i<l;i++)
                                 {
                                         if(g[i]==guess)
                                         {
                                                 c++;
                                         }
                                 }
                                 if(c==0)
                                 {
                                         g[l]=guess;
                                         l++;
                                 }
                                  else
                                 {
                                         cout<<"repeated input\n";
                                         c=0;
                                         goto l2;
                                 }
                                 v=check(guess,str,len);
                                 if(v!=0)
                                 {
                                         w+=v;
                                 }
                                 else
                                 {
                                         if(deduct<=0)
                                         {
                                                 cout<<"\n_________!!!!!!SORRY YOU LOSE!!!!!____________\n";
                                                 cout<<"THE ACTUAL WORD IS----------------------"<<str;
                                                 mp.minusmoney(50);
                                                 break;
                                         }
                                         else
                                         {
                                                 ded(--deduct,h);
                                         }
                                 }
                                 if(w==len)
                                 {
                                         cout<<"\n_____________!!!!!YOU WIN!!!!______________\n";
                                         cout<<"THE WORD IS-----------------------"<<str;
                                         mp.plusmoney(100);
                                         break;
                                 }
                        }
                        ofstream check("point.txt");
                        check<<"THE GAME PLAYED IS HOLLYWOOD"<<endl;
                        check.close();

                }
                 else if(mainchoice==5)
                {
                                 srand((unsigned)time(NULL));
                                 who ob[5];
                                 cout<<"_____________________________________________________WHO AM I_______________________________________________________\n";
                                 int m,i=0,ans;
                                 string name,player,g;
                                 m=rand()%5;
                                 if(m==1)
                                 {
                                         name="NEHRU";
                                 }
                                 else if(m==2)
                                 {
                                         name="DHONI";
                                 }
                                 else if(m==3)
                                 {
                                         name="KAMAL HASAN";
                                 }
                                 else if(m==4)
                                 {
                                         name="JANAKI";
                                 }
                                 else if(m==5)
                                 {
                                        name="PRABHU DEVA";
                                 }
                                 cout<<"enter your name\n";
                                 cin>>player;
                                 cout<<player<<"\t let's start\n";
                                 //cout<<"=============================="<<name<<"\n";
                                  set_data(ob);
                                 while(i<5)
                                 {
                                        cout<<"guess my name";
                                        cin.ignore(1,'\n');
                                        getline(cin,g);
                                         if(g!=name)
                                         {
                                                 cout<<"do you want a clue  ?enter 1 else enter 0\n";
                                                 cin>>ans;
                                                 if(ans==1)
                                                 {
                                                         ob[m-1].display(i);
                                                         i++;
                                                 }
                                         }
                                         else
                                         {
                                                cout<<"-----------------------------------------------YOU WIN!------------------------------------\n";
                                                mp.plusmoney(200);
                                                break;
                                         }
                                 }
                                 if(i==5)
                                 {
                                         mp.minusmoney(100);
                                         cout<<"you lost the game\n";
                                         cout<<"the correct answer is"<<name;
                                 }
                                 ofstream check("point.txt");
                                 check<<"THE GAME PLAYED IS GUESS MY NAME";
                                 check.close();

                }
                else
                {
                        mp.displaying();
                        ifstream check("point.txt");
                        while(getline(check,wordx))
                        {
                                cout<<endl;
                                cout<<wordx<<endl;
                        }
                        myfile.close();

                        break;
                }
          }
    }
