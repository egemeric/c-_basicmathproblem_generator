#include <iostream>
#include <sstream>
using namespace std;

class MathProblem{

protected:
    bool istrue;
public:
    void isAnswerTrue(bool true_or_false){this->istrue=true_or_false;}
    virtual void setproblem()=0;
    virtual void askuserforanswer()=0;
    virtual void displayproblem()=0;

};

class IntegerProblem: public MathProblem{
    int num1,num2,correctanswer,useranswer;
public:
    void setproblem()
    {srand(time(0));
     num1=rand() %100+1;
     num2=rand() %100+1;
     this->correctanswer=num1+num2;
     //displayproblem();
     }
     void displayproblem()
     {cout<<"Question is:"<<num1<<"+"<<num2<<"= ?\n";
    // askuserforanswer();
     }
     void askuserforanswer()
    {     cout<<"Enter answer: ";
          cin>>this->useranswer;

           if(correctanswer==useranswer)
           {
             cout<<"Good job\n";
             isAnswerTrue(true);
           }
           else
           {cout<<"Sorry! the correct answer is "<<correctanswer<<endl;
           isAnswerTrue(false);}
      }

};
class FractionProblem: public MathProblem{
int n1,d1,n2,d2,corn,cord,usern,userd;
public:
void setproblem()
     {   srand(time(0));
         n1=rand() %10+1; n2=rand()%10+1;
         d1=rand() %10+1; d2=rand()%10+1;
         int scd;
         scd = (d1 > d2) ? d1: d2;
         while (true)//find lcm
         {
             if (scd % d1 == 0 && scd % d2 == 0)
             break;
            ++scd;
         }

         corn=(scd/d1*n1)+(scd/d2*n2);
         cord=(scd);
         //displayproblem();
     }
void displayproblem()
    {
    cout<<"Question is:"<<n1<<"/"<<d1<<" + "<<n2<<"/"<<d2<<"= ?\n";
    //askuserforanswer();
}
 void askuserforanswer()
    {     char dummychar;


          cout<<"Enter answer(a / b) include'/': ";
          cin>>usern>>dummychar>>userd;
          if(dummychar!='/'){
             cout<<"'/' is must included or blank space error\n";
            exit(0);
             }





           if(float(float(corn)/float(cord))==float(float(usern)/float(userd)))
           {
             cout<<"Good job\n";
             isAnswerTrue(true);
           }
           else
           {cout<<"Sorry! the correct answer is "<<corn<<"/"<<cord<<endl;
           isAnswerTrue(false);

           }
      }


};

int main(){
int i=0;
MathProblem *ptr;
do{
cout<<"\nPlease choose type of addition problem:\n 1. Fraction\n 2. Integer\n 3. Quit\n";
cin>>i;
 if(i==2)
 {
    ptr=new IntegerProblem;
    ptr->setproblem();
    ptr->displayproblem();
    ptr->askuserforanswer();
 }
 else if(i==1){
     ptr=new FractionProblem;
     ptr->setproblem();
     ptr->displayproblem();
     ptr->askuserforanswer();
 }

}while(i!=3);
return(0);
}
