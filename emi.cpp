#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <ctime>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;
static int c = 0, dd = 0, mm = 0, yy = 0;
class loan
{
  public:
    float loanamt;
    int n;
    time_t l_creation;
    struct emi{
        float principal;
        float interest;
        float t_emi;
        string emi_date;
        float p_remaining;
        struct emi *emis;
    };
    struct emi *head;
    struct emi *current;
    
    float t_amount;
    float emic;
    loan(int months){
        n = months;
        head = NULL;
        current = NULL;
    }
    void t_amountcalc(float la, int months);
    void emi_calc();
    void calculate_emi();
    string increment();
    float curr;
    void printList();

};

void loan::t_amountcalc(float la, int months){
    loanamt = la;
    float temp = la * float(pow(float(1 + float(12) / float(100)), float(months/12))); 
    cout<< "Principal Amount: "<<la<<endl;
    cout<< "No of EMIs: "<<months<<endl;
    t_amount = temp;
}

void loan::emi_calc(){
    float annualIntRate = 12;
    emic = loanamt * ((annualIntRate/1200) + ((annualIntRate/1200) / (pow(1 + (annualIntRate/1200), n) - 1)));  
    curr = t_amount;
    cout<<"EMI: "<<emic<<endl;
    cout<<"Total: "<<t_amount<<endl;
}

void loan::calculate_emi(){
    
    int i = 0;
    struct emi *link = (struct emi*) malloc(sizeof(struct emi)*n);
    link->emi_date = increment();
    link->principal = 
    // link->interest = loanamt * ((t_amount- loanamt)/12)*100;
    // curr = curr - emic - link->interest;
    // link->p_remaining = curr;
    // link->principal = curr + link->interest;
    
    link->emis = (struct emi*)head;
    head = link;
    
    
        //  cout<< link->emi_date << '\t' << link->interest << '\t' << link->p_remaining
        //  << '\t' << link->principal<<'\n';
   

}

void loan:: printList() {
   struct emi *ptr = head;
   	
   while(ptr != NULL) {
      cout<<"Print: " << ptr->emi_date << endl;
      ptr = ptr->emis;
   }
	
}

template <typename T>
string NumberToString(T pNumber)
{
 ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}

void setdate(int year, int month, int day){
    
    const char * months[12] = {"January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"};
    dd = day;
    mm = month;
    yy = year;
    cout<< "Loan Creation Date: ";
    cout << NumberToString(dd)<< '-' <<  NumberToString(months[mm-1]) << '-' <<  NumberToString(yy)<<endl;

}

string loan::increment(){
    const char * months[12] = {"January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"};

    if(dd > 29)
        dd = 28;

    if(mm == 12){
        mm = 0;
        yy += 1;
    }
    mm +=1;
    string ts = NumberToString(dd)+ '-' +  NumberToString(months[mm-1]) + '-' +  NumberToString(yy);
    return ts;

}



int main()
{
    loan lo(12);
    setdate(2020, 5, 8);
    lo.t_amountcalc(1000, 12);
    lo.emi_calc();
    for(int i =0; i<12;i++)         
        lo.calculate_emi();
        
    lo.printList();
    return 0;
}