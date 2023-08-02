/************** CRUISE TRAVEL MANAGENMENT *****************
            A Project based on Cruise Travel Management
            by ASHUTOSH SINGH THAKUR                   */
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<ctype.h>
#include<stdlib.h>
#include<process.h>

using namespace std;

long int code;      //code for every database

void borderLine(char c)
{
    for(int i=0; i<122; i++)
    cout<<c;
}

class persdetails //class for collecting the personal details
{   /*Private data members of class persdetails
    by default                  */
                                //Data members to store:
    int trvlcode;
    int age[10];                  //Age of members
    char name[10][20];       //Name for each member.
    char add[50];              //Address of peoples
    int num;                    //number of children below 5 years
    char sex[10];
    char  familyname[25];   //Name of database
    int numppl;                //Total number of people
    char passnum[10][10];   //Passport number for each member
    char phnum[11];

public:
    void p_input(int);
    void p_output();
    void givefam();         //display the familyname of Database
    int givecode();         //access the code
    int give();              // access the number of children below 5 years
}P_object;                  //  A object of class persdetails

int persdetails::give()
{
    return num;
}
void persdetails::givefam()
{
    cout<<familyname;
}
int persdetails::givecode()
{
    return trvlcode;
}
void persdetails::p_input(int cd) //input function() of class persdetails
{
    trvlcode=cd;
    num=0;
    cout<<"\n\n";
    borderLine(char(205));
    cout<<"\n\n\n\t\t\t   :::::::::::::::::::::::::: PERSONAL DETAILS ::::::::::::::::::::::::::\n";
    cout<<"\t\t\t\t\t\t      ~~~~~~~~~~~~~~~~\n\n\n";
    borderLine(char(205));
    cout<<"\n\n\n\t\t\t\t\t\t* Please fill in the details :\n\n\n";
    borderLine(char(196));
    cout<<"\n\n\n";
    char c;     cin.get(c);                              //to remove input buffer
    cout<<"\n\t\t\t\t\t1. Family Name : ";
    gets(familyname);                                 //to take familyname
    for(int i=0;i<strlen(familyname);i++)           //to change all alphabets of
    {
        familyname[i]=toupper(familyname[i]);   //familyname to uppercase
    }
    cout<<"\n\t\t\t\t\t2. Address : ";              //take address
    gets(add);
    cout<<"\n\t\t\t\t\t3. Contact Number(10 Digit Mobile Number) : ";
    gets(phnum);                        //take phone number of user
    phnum[10]=' ';
    phnum[11]='\0';
    cout<<"\n";
    borderLine(char(196));
    cin.get(c);
    cout<<"\n\t\t\t\t\tEnter The Number of People Traveling : ";
    cin>>numppl;
    cin.get(c);
    system("cls");
    if(numppl>0)
    {
        borderLine('*');
        cout<<"\n\n\t\t\t\t\tPlease Enter The Details of each Member(s) : \n\n";
        for(int i=0;i<numppl;i++)
        {
            borderLine(char(196));
            cout<<"\n\n\t\t\t\t\t\tMember "<<i+1;
            cout<<"\n\t\t\t\t\t\t~~~~~~~~";
            cout<<"\n\n\t\t\t\tFirst Name : ";
            gets(name[i]);
            cout<<"\n\t\t\t\tAge : ";
            cin>>age[i];
            cin.get(c);
            cout<<"\n\t\t\t\tSex (M/F) : ";
            cin>>sex[i];        cin.get(c);
            cout<<"\n\t\t\t\tPassport Number : ";
            gets(passnum[i]);
            if(age[i]>5)            num++; //to calculate no of travelers below 5 years
        }
        cout<<"\n\n";
        borderLine(char(196));
        getch();
    }
}
void persdetails::p_output() //output function() of class persdetails
{
    system("cls");
    cout<<"\n\n";
    borderLine(char(205));
    cout<<"\n\n\n\t\t\t\t\t*************** PERSONAL DETAILS ***************\n\n\n";
    borderLine(char(205));
    cout<<"\n\n\t\t\t\t\t\tFamily Name\t:\t "<<familyname;
    cout<<"\n\t\t\t\t\t\tAddress \t:\t "<<add;
    cout<<"\n\t\t\t\t\t\tPhone Number\t:\t "<<phnum<<"\t\t\t\t";
    /*         To display information in good formate    */
    //upper line
    cout<<"\n\n\n\t\t\t\t"<<char(201);   for(int i=0;i<20;i++) cout<<char(205);
    cout<<char(203);for(int i=0;i<7;i++) cout<<char(205);
    cout<<char(203);for(int i=0;i<7;i++) cout<<char(205);
    cout<<char(203);for(int i=0;i<20;i++) cout<<char(205);  cout<<char(187);

    cout<<"\n\t\t\t\t"<<char(186)<<"\tName\t     "<<char(186);
    cout<<"  Age  "<<char(186)<<"  Sex  "<<char(186)<<"\t Passport Number  "<<char(186);

    cout<<"\n\t\t\t\t"<<char(204);   for(int i=0;i<20;i++) cout<<char(205);
    cout<<char(206);for(int i=0;i<7;i++) cout<<char(205);
    cout<<char(206);for(int i=0;i<7;i++) cout<<char(205);
    cout<<char(206);for(int i=0;i<20;i++) cout<<char(205);  cout<<char(185);

    for(int i=0;i<numppl;i++)   //loop to display details of each member
    {
        cout<<"\n\t\t\t\t"<<char(186)<<"     ";
        cout<<name[i];  for(int j=0;j<15-strlen(name[i]);j++)   cout<<" ";
        cout<<char(186)<<"  ";
        if(age[i]<10) cout<<'0';    cout<<age[i]<<"   "<<char(186);
        cout<<"   "<<sex[i]<<"   "<<char(186)<<"     "<<passnum[i];
        for(int j=0;j<(15-strlen(passnum[i]));j++)    cout<<" ";  cout<<char(186);
    }
    //lower line
    cout<<"\n\t\t\t\t"<<char(200);   for(int i=0;i<20;i++) cout<<char(205);
    cout<<char(202);for(int i=0;i<7;i++) cout<<char(205);
    cout<<char(202);for(int i=0;i<7;i++) cout<<char(205);
    cout<<char(202);for(int i=0;i<20;i++) cout<<char(205);  cout<<char(188)<<"\n";
    getch();
}

class travdetails //class which holds the travel details
{
    int trvtcode;   //code of travel
    int day;
    int month;
    int year;
    int num1;
    int bdg_pt;
    int go_pt;
    int deck;
    int cabin;
    /*  Facilities */
    int pool;
    int gym;
    int sports;
    int salon;
    int spa;
    int theater;
public:
    void initial();
    void t_input(int);
    void t_output();
    void Bill_Comp();
    int gtcode();
    void accept(int);
}T_object;
void travdetails::initial()                 // Initialize all facilities as 'NO'
{
    pool=gym=theater=sports=salon=2;
}
void travdetails::accept(int c)     //to get number of people above 5 years
{
    num1=c;
}
int travdetails::gtcode()
{
    return trvtcode;
}
void travdetails::t_input(int cd) //input func()-class2
{
    cabin=2;
    T_object.initial();     //call initial function
    trvtcode=cd;         // assign travel code
    int i=1,opt;
    system("cls");
    do
    {
        system("cls");
        borderLine(char(205));
        cout<<"\n\n\t\t\t\t\t\t_||__TRAVEL DETAILS__";
        cout<<"\n\t\t\t\t\t\t\\___________________/";
        cout<<"\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n\n\t\t\t\tPlease enter the following details for your journey:\n";
        borderLine(':');
        //give options to user
        cout<<"\n\t\t\t\t   *Note:Options marked with are compulsory.";
        cout<<"\n\n\t\t\t\t\t\tPlease do select them.";
        cout<<"\n\n\n\t\t\t\t\t\t*1.Boarding Point";
        cout<<"\n\t\t\t\t\t\t*2.Destination\n\t\t\t\t\t\t*3.Date of Departure";
        cout<<"\n\t\t\t\t\t\t*4.Deck\n\t\t\t\t\t\t*5.Cabin\n\t\t\t\t\t\t 6.Swimming Pool";
        cout<<"\n\t\t\t\t\t\t 7.Gymnasium\n\t\t\t\t\t\t 8.Sports\n\t\t\t\t\t\t 9.Salon";
        cout<<"\n\t\t\t\t\t\t 10.Spa\n\t\t\t\t\t\t 11.Theater\n\t\t\t\t\t\t 12.Back\n\n";
        borderLine(':');
        borderLine(char(219));
        cout<<"\n\t\t\t\t\t\t    ";   cin>>opt;
        switch(opt)
        {
            case 1 :   system("cls");
                        cout<<"\n\n\n";
                        borderLine(char(205));
            cout<<"\n\n\n\t\t\t\t\t********Select Boarding point:********\n\n\n";
            borderLine(char(205));
            cout<<"\n\n\t\t\t\t\t\t\t<1>.Mumbai";
            cout<<"\n\n\t\t\t\t\t\t\t<2>.Cochin";
            cout<<"\n\n\t\t\t\t\t\t\t<3>.Chennai\n\n";
            borderLine(char(219));
            cout<<"\n\n\t\t\t\t\t\t\t   ";  cin>>bdg_pt;
            break;

            case 2 :    system("cls");
                            cout<<"\n\n\n";
                            borderLine(':');
            cout<<"\n\n\t\t\t\t\t********* Select Destination *********\n\n";
            borderLine(':');
            cout<<"\n\n\t\t\t\t 1.New York\t\t6.Dubai\t\t\t11.Antananariv";
            cout<<"\n\n\t\t\t\t 2.Miami\t\t7.Lisbon\t\t12.Cairo\n\n";
            cout<<"\t\t\t\t 3.Rio De Janeiro\t8.London\t\t13.Perth";
            cout<<"\n\n\t\t\t\t 4.Colombo\t\t9.Copenhagen\t\t14.Sydney";
            cout<<"\n\n\t\t\t\t 5.Hong Kong\t\t10.Cape Town\t\t15.Wellington\n\n\n";

            borderLine(char(219));
            cout<<"\n\n\n\t\t\t\t\t\t\t    ";           cin>>go_pt;
            break;

            case 3 :       system("cls");
                            cout<<"\n\n\n";
                            borderLine(char(205));
            cout<<"\n\n\t\t\t\t\t\t *****Date of Departure***** \n\n";
            borderLine(char(205));
            cout<<"\n\n\t\t\t * Note:Format for entering : ";
            cout<<"Day(press space)Month(press space)Year *";
            cout<<"\n\n\t\t\t\tEnter your preferred date of departure: ";
            cin>>day>>month>>year;
            if(year<1000)   year+=2000;                     //To assign year in 21st century
            break;

            case 4 :    system("cls");
                        cout<<"\n\n\n";
                        borderLine(char(178));
            cout<<"\n\n\t\t\t\t\t\tEnter The Choice Of Deck\n\n";
            borderLine(char(176));
            cout<<"\n\n\t\t\t\t\t\t   <1>.Top Deck";
            cout<<"\n\n\t\t\t\t\t\t   <2>.Middle Decks";
            cout<<"\n\n\t\t\t\t\t\t   <3>.Bottom Deck\n\n";
            borderLine(char(177));
            cout<<"\n\n\t\t\t\t\t\t\t ";        cin>>deck;
            break;

            case 5 :       system("cls");
                            borderLine(char(178));
            cout<<"\n\n\t\t\t\t\t\tEnter The Choice Of Cabin\n\n";
            borderLine(char(176));
            cout<<"\n\n\t\t\t\t\t\t   <1>.AC\n\n\t\t\t\t\t\t   <2>.Non AC\n\n";
            borderLine(char(177));
            cout<<"\n\n\t\t\t\t\t\t\t ";        cin>>cabin;
            break;

            case 6 :       system("cls");
                            borderLine(char(178));
            cout<<"\n\n\t\t\t\t   Do You Like To Avail The Facility Of A Swimming Pool\n\n";
            borderLine(char(176));
            cout<<"\n\n\t\t\t\t\t\t   <1>.YES\n\n\t\t\t\t\t\t   <2>.NO\n\n";
            borderLine(char(177));
            cout<<"\n\n\t\t\t\t\t\t\t ";        cin>>pool;
            break;

            case 7 :       system("cls");
                            borderLine(char(178));
            cout<<"\n\n\t\t\t\t   Do You Like To Avail The Facility Of A Gymnasium\n\n";
            borderLine(char(176));
            cout<<"\n\n\t\t\t\t\t\t   <1>.YES\n\n\t\t\t\t\t\t   <2>.NO\n\n";
            borderLine(char(177));
            cout<<"\n\n\t\t\t\t\t\t\t ";    cin>>gym;
            break;

            case 8 :       system("cls");
                            borderLine(char(178));
            cout<<"\n\n\t\t\t\t   Do You Like To Avail The Sports Facilities Offered\n\n";
            borderLine(char(176));
            cout<<"\n\n\t\t\t\t\t\t   <1>.YES\n\n\t\t\t\t\t\t   <2>.NO\n\n";
            borderLine(char(177));
            cout<<"\n\n\t\t\t\t\t\t\t ";    cin>>sports;
            break;

            case 9 :       system("cls");
                            borderLine(char(178));
            cout<<"\n\n\t\t\t\t   Do You Like To Avail The Facility Of Salon\n\n";
            borderLine(char(176));
            cout<<"\n\n\t\t\t\t\t\t   <1>.YES\n\n\t\t\t\t\t\t   <2>.NO\n\n";
            borderLine(char(177));
            cout<<"\n\n\t\t\t\t\t\t\t ";    cin>>salon;
            break;

            case 10 :     system("cls");
                            borderLine(char(178));
            cout<<"\n\n\t\t\t\tDo You Like To Avail The Facility";
            cout<<" Of Spa and Ayurvedic Treatment\n\n";
            borderLine(char(176));
            cout<<"\n\n\t\t\t\t\t\t   <1>.YES\n\n\t\t\t\t\t\t   <2>.NO\n\n";
            borderLine(char(177));
            cout<<"\n\n\t\t\t\t\t\t\t ";        cin>>spa;
            break;

            case 11 :     system("cls");
                            borderLine(char(178));
            cout<<"\n\n\t\t\t\tDo You Like To Avail The Facility Of Amphitheater\n\n";
            borderLine(char(176));
            cout<<"\n\n\t\t\t\t\t\t   <1>.YES\n\n\t\t\t\t\t\t   <2>.NO\n\n";
            borderLine(char(177));
            cout<<"\n\n\t\t\t\t\t\t\t ";    cin>>theater;
            break;

            case 12 :   i=0;
            break;
        }
    }while(i==1);
}
void boardpt(int c,char C[]) //for easy o/p
{
    if(c==1)        strcpy(C,"Mumbai");
    else if(c==2)   strcpy(C,"Cochin");
    else if(c==3)   strcpy(C,"Chennai");
}
void dest(int d,char C[]) //for easy o/p
{
    switch(d)
    {
        case 1 :     strcpy(C,"New York");
        break;
        case 2 :     strcpy(C,"Miami");
        break;
        case 3 :     strcpy(C,"Rio De Janero");
        break;
        case 4 :     strcpy(C,"Colombo");
        break;
        case 5 :     strcpy(C,"Hong Kong");
        break;
        case 6 :     strcpy(C,"Dubai");
        break;
        case 7 :     strcpy(C,"Lisbon");
        break;
        case 8 :     strcpy(C,"London");
        break;
        case 9 :     strcpy(C,"Copenhagen");
        break;
        case 10 :   strcpy(C,"Cape Town");
        break;
        case 11 :   strcpy(C,"Antananriv");
        break;
        case 12 :   strcpy(C,"Cairo");
        break;
        case 13 :   strcpy(C,"Perth");
        break;
        case 14 :   strcpy(C,"Sydney");
        break;
        case 15 :   strcpy(C,"Willington");
        break;
    }
}
void travdetails::t_output() //output func()-class2
{
    system("cls");
    char Places[25];
    borderLine(char(205));
    cout<<"\n\n\n\t\t\t\t********************* TRAVEL DETAILS ";
    cout<<"*********************\n\n\n";
    borderLine(char(205));
    boardpt(bdg_pt,Places);
    cout<<"\n\n\t\t\t\t\t\tBoarding Point : "<<Places;
    dest(go_pt,Places);
    cout<<"\n\n\t\t\t\t\t\tDestination : "<<Places;
    cout<<"\n\n\t\t\t\t\t\tDate of departure : ";
    cout<<day<<"/"<<month<<"/"<<year;
    cout<<"\n\n\t\t\t\t\t\tDeck : ";
    switch(deck)
    {
        case 1:cout<<"Top Deck";
        break;
        case 2:cout<<"Middle Deck";
        break;
        case 3:cout<<"Bottom Deck";
        break;
    }
    cout<<"\n\n\t\t\t\t\t\tCabin : ";
    switch(cabin)
    {
        case 1:cout<<"AC cabin";
        break;
        case 2:cout<<"Non-AC cabin";
        break;
    }
    cout<<"\n\n";
    borderLine(char(178));
    cout<<"\n\n\t\t\t\t\t\tFacilities availed for are :";
    cout<<"\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    if(pool==1)
        cout<<"\n\t\t\t\t\t\t"<<char(4)<<" Swimming Pool";
    if(gym==1)
        cout<<"\n\t\t\t\t\t\t"<<char(4)<<" Gymnasuim";
    if(sports==1)
        cout<<"\n\t\t\t\t\t\t"<<char(4)<<" Sports Facilities";
    if(spa==1)
        cout<<"\n\t\t\t\t\t\t"<<char(4)<<" Spa and Ayurvedic Treatment";
    if(salon==1)
        cout<<"\n\t\t\t\t\t\t"<<char(4)<<" Salon";
    if(theater==1)
        cout<<"\n\t\t\t\t\t\t"<<char(4)<<" Theater";
    else if((pool!=1)&&(gym!=1)&&(sports!=1)&&(spa!=1)&&(salon!=1)&&(theater!=1))
        cout<<"\n\n\t\t\t\t\t\t.You have No any Facility. \n ";

    cout<<"\n\n";
    borderLine(char(177));
    getch();
}
void family(int c,int&flag) //to display familyname + to check for record
{
    flag=0;
    system("cls");
    ifstream ifl("PersonalDetails.dat",ios::binary);
    if(!ifl)
        cout<<"\n\n\t\t\t\t\t!!Error!!!     Data is Empty!\n";
    else
    {
        ifl.read((char*)&P_object,sizeof(P_object));
        while(!ifl.eof())
        {
            if(P_object.givecode()==c)
            {
                flag=1;     break;
            }
            ifl.read((char*)&P_object,sizeof(P_object));
        }
    }
    if(flag==1)
    {
        cout<<"\n\n\n\n\n\n";
        borderLine(char(223));
        cout<<"\n\n\t\t\t\t\t********** ";
        P_object.givefam();
        cout<<" FAMILY DATABASE **********\n\n";
        borderLine(char(205));
    }
    else
    {
        cout<<"\n\n\n";
        borderLine(char(205));
        cout<<"\n\n\t\t\t\t\t\tERROR! in locating the file!\n\n";
        borderLine(char(205));
    }
    ifl.close();
}
void editp(int c) //to edit persdetails
{
    ofstream ofl2("temp.dat",ios::binary);
    if(!ofl2)
    cout<<"\n\n\n\n\t\t\t\t\tError While Opening File";
    ifstream ifl4("PersonalDetails.dat",ios::binary);
    if(!ifl4)
    cout<<"\n\n\n\n\t\t\t\t\tError While Opening File\n";
    ifl4.read((char*)&P_object,sizeof(P_object));
    while(!ifl4.eof())
    {
        if(P_object.givecode()==c)
        {
            system("cls");
            cout<<"\n\n\n\t\t\t\t\t*Please Enter the New details of the record*\n";
            P_object.p_input(c);
            ofl2.write((char*)&P_object,sizeof(P_object));
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n";
            borderLine(char(223));   cout<<"\n";
            borderLine(char(205));
            cout<<"\n\n\n\t\t\t\t\t:::::::::::Modification Successful::::::::::: \n\t\t\t\t\t\t  ";
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            borderLine(char(205));    cout<<"\n";
            borderLine(char(223));
            ifl4.read((char*)&P_object,sizeof(P_object));
        }
        else
        {
            ofl2.write((char*)&P_object,sizeof(P_object));
            ifl4.read((char*)&P_object,sizeof(P_object));
        }
    }
    ifl4.close();
    ofl2.close();
    remove("PersonalDetails.dat");
    rename("temp.dat","PersonalDetails.dat");
    getch();
}
void editt(int c) //to edit travdetails
{
    ofstream ofl2("temp.dat",ios::binary);
    if(!ofl2)   cout<<"\n\n\n\n\t\t\t\t\t\tError While Opening File";
    ifstream ifl4("TravelDetails.dat",ios::binary);
    if(!ifl4)
    cout<<"\n\n\n\n\t\t\t\t\t\tError While Opening File";
    ifl4.read((char*)&T_object,sizeof(T_object));
    while(!ifl4.eof())
    {
        if(T_object.gtcode()==c)
        {
            system("cls");
            cout<<"\n\n\t\t\t\tPlease Enter the New details of the record\n";
            T_object.t_input(c);
            ofl2.write((char*)&T_object,sizeof(T_object));
            system("cls");
            cout<<"\n\n\n\n";
            borderLine(char(223));   cout<<"\n";
            borderLine(char(205));
            cout<<"\n\n\n\t\t\t\t\t:::::::::::Modification Successful:::::::::::";
            cout<<" \n\t\t\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            borderLine(char(205));    cout<<"\n";
            borderLine(char(223));
            ifl4.read((char*)&T_object,sizeof(T_object));
        }
        else
        {
            ofl2.write((char*)&T_object,sizeof(T_object));
            ifl4.read((char*)&T_object,sizeof(T_object));
        }
    }
    ifl4.close();
    ofl2.close();
    remove("TravelDetails.dat");
    rename("temp.dat","TravelDetails.dat");
    getch();
}
void deletion(int c) //common delete func()
{
    ofstream ofl2("temp.dat",ios::binary);
    if(!ofl2)
        cout<<"\n\n\n\t\t\t\t\t\t*Error While Opening File*\n\n\n";
    ifstream ifl4("PersonalDetails.dat",ios::binary);
    if(!ifl4)
        cout<<"\n\n\n\t\t\t\t\t\t*Error While Opening File*\n\n\n";
    ifl4.read((char*)&P_object,sizeof(P_object));
    while(!ifl4.eof())
    {
        ifl4.read((char*)&P_object,sizeof(P_object));
        if(P_object.givecode()!=c)
            ofl2.write((char*)&P_object,sizeof(P_object));
    }
    ofl2.close();
    ifl4.close();
    remove("PersonalDetails.dat");                  //Deleting original file
    rename("temp.dat","PersonalDetails.dat");   //Reaming temp.dat as PersonalDetails.dat

    ofstream ofl3("temp.dat",ios::binary);
    if(!ofl3)
        cout<<"\n\n\n\t\t\t\t\t\tError While Opening File";
    ifstream ifl5("TravelDetails.dat",ios::binary);
    if(!ifl5)
        cout<<"\n\n\n\t\t\t\t\t\tError While Opening File";
    ifl5.read((char*)&T_object,sizeof(T_object));
    while(!ifl5.eof())
    {
        if(T_object.gtcode()!=c)
            ofl3.write((char*)&T_object,sizeof(T_object));
        ifl5.read((char*)&T_object,sizeof(T_object));
    }
    ofl3.close();
    ifl5.close();
    remove("TravelDetails.dat");
    rename("temp.dat","TravelDetails.dat");
    system("cls");
    cout<<"\n\n\n\n";
    borderLine(char(223));   cout<<"\n";
    borderLine(char(205));
    cout<<"\n\n\n\t\t\t\t\t:::::::::::Deletion Successful::::::::::: ";
    cout<<"\n\t\t\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~\n\n";
    borderLine(char(205));    cout<<"\n";
    borderLine(char(223));     cout<<"\n\n\n";
    getch();
}
void travdetails::Bill_Comp() //computation+bill generation
{
    char Places[25];
    long int G_Total=0,hr=0,dcst=10000,dck=1000,cabn=2000,swpool=5000,\
    gm=2000,spfts=7500,slon=6000,sp=20000,ttr=500;

    //to calculate the cost for destination
    switch(go_pt)
    {
        case 1 :
        case 2 :
        case 3 :    hr=30*24;
                    dcst=249999;
                    break;
        case 4 :
        case 5 :
        case 6 :    hr=7*24;
                    dcst=74999;
                    break;
        case 7 :
        case 8 :
        case 9 :    hr=24*24;
                    dcst=129999;
                    break;
        case 10 :
        case 11 :
        case 12 :  hr=15*24;
                    dcst=99999;
                    break;
        case 13 :
        case 14 :
        case 15 :  hr=12*24;
                    dcst=119999;
                    break;
    }
    switch(deck)    //calculate deck price
    {
        case 1 :    dck=7500;        break;
        case 2 :    dck=5000;        break;
        case 3 :    dck=1000;
    }
    switch(cabin)   //calculate price for cabin
    {
        case 1 :    cabn=5000;      break;
        case 2 :    cabn=2000;      break;
    }
    system("cls");
    //to display a ship in bill
    cout<<"\n\t\t\t\t"<<char(197);
    for(int i=0;i<61;i++)   cout<<char(196);    cout<<char(197);
    cout<<"\n\t\t\t\t"<<char(179);
    cout<<"\t\t              __________       \t \t      "<<char(179);
    cout<<"\n\t\t\t\t"<<char(179);
    cout<<"\t\t______||_____/          \\_________  \t      "<<char(179);
    cout<<"\n\t\t\t\t"<<char(179)<<"\t\t\\\t\t\t\t /\t      "<<char(179);
    cout<<"\n\t\t\t\t"<<char(179)<<"\t\t \\\t   :::::BILL:::::     \t/\t      "<<char(179);
    cout<<"\n\t\t\t\t"<<char(179)<<"\t\t  \\____________________________/\t      "<<char(179);
    cout<<"\n\t\t\t\t"<<char(195);

    for(int i=0;i<61;i++)   cout<<"-";    cout<<char(180);

    //Display details
    cout<<"\n\t\t\t\t"<<char(179);
    for(int i=0;i<61;i++)   cout<<" ";    cout<<char(179);
    boardpt(bdg_pt,Places);
    cout<<"\n\t\t\t\t"<<char(179)<<"\t\tBoarding point : "<<Places;
    for(int i=0;i<29-strlen(Places);i++) cout<<" ";  cout<<char(179);

    cout<<"\n\t\t\t\t"<<char(179);
    for(int i=0;i<61;i++)   cout<<" ";    cout<<char(179);
    dest(go_pt,Places);
    cout<<"\n\t\t\t\t"<<char(179)<<"\t\tDestination : "<<Places;
    for(int i=0;i<32-strlen(Places);i++) cout<<" ";  cout<<char(179);

    cout<<"\n\t\t\t\t"<<char(179);
    for(int i=0;i<61;i++)   cout<<" ";    cout<<char(179);
    cout<<"\n\t\t\t\t"<<char(179)<<"\t\tDate of Departure : ";
    if(day<10)   cout<<'0';   cout<<day<<"/";
    if(month<10)   cout<<'0';   cout<<month<<"/"<<year;
    for(int i=0;i<16;i++) cout<<" ";  cout<<char(179);

    hr=hr/24; //to calculate date of arrival
    day=day+hr;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        if(day>31)
        {
            month=month+1;
            day=day%31;
        }
    }
    if(month==4||month==6||month==9||month==11)
    {
        if(day>30)
        {
            month=month+1;
            day=day%30;
        }
    }
    if(month==2)
    {
        if(day>28)
        {
            month=month+1;
            day=day%28;
        }
    }
    if(month==13)
    {
        month=1;
        year++;
    }
    cout<<"\n\t\t\t\t"<<char(179);
    for(int i=0;i<61;i++)   cout<<" ";    cout<<char(179);
    cout<<"\n\t\t\t\t"<<char(179)<<"\t\tDate of Arrival : ";
    if(day<10)   cout<<'0';   cout<<day<<"/";
    if(month<10)   cout<<'0';   cout<<month<<"/"<<year;
    for(int i=0;i<18;i++) cout<<" ";  cout<<char(179);

    //Descriptions of charges
    cout<<"\n\t\t\t\t"<<char(179)<<"   ";
    cout<<char(201);   for(int i=0;i<17;i++) cout<<char(205);
    cout<<char(203);    for(int i=0;i<11;i++) cout<<char(205);
    cout<<char(203);    for(int i=0;i<11;i++) cout<<char(205);
    cout<<char(203);    for(int i=0;i<11;i++) cout<<char(205);
    cout<<char(187)<<"   "<<char(179);

    cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186);

    cout<<"\tSubject\t      "<<char(186)<<"   Cost    "<<char(186);
    cout<<" number of "<<char(186)<<"  Amount   "<<char(186)<<"   "<<char(179);
    cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186);
    for(int i=0;i<17;i++) cout<<" ";
    cout<<char(186)<<"  (for 1)  ";
    cout<<char(186)<<"  People   "<<char(186);
    for(int i=0;i<11;i++) cout<<" ";  cout<<char(186)<<"   "<<char(179);
    cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(204);
    for(int i=0;i<17;i++) cout<<char(205);
    cout<<char(206);for(int i=0;i<11;i++) cout<<char(205);
    cout<<char(206);for(int i=0;i<11;i++) cout<<char(205);
    cout<<char(206);for(int i=0;i<11;i++) cout<<char(205);
    cout<<char(185)<<"   "<<char(179);
//                           charges on Travel
    cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186)<<" Travel \t      ";
    cout<<char(186)<<"  "<<dcst;    if(dcst<100000) cout<<" ";
    cout<<"   "<<char(186)<<"    ";
    if(num1<10) cout<<'0'; cout<<num1<<"     "<<char(186);
    G_Total+=num1*dcst;cout<<"  "<<G_Total;
    if(G_Total<100000) cout<<"  ";
    else if(G_Total<1000000)  cout<<" ";
    cout<<"  "<<char(186)<<"   "<<char(179);
//                 charges on Deck
    cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186)<<" Deck   \t      ";
    cout<<char(186)<<"  "<<dck<<"     "<<char(186)<<"    ";
    if(num1<10) cout<<'0'; cout<<num1<<"     "<<char(186);
    G_Total+=num1*dck;    cout<<"  "<<num1*dck;
    if(num1*dck<10000)    cout<<" ";
    cout<<"    "<<char(186)<<"   "<<char(179);
//                  charges on Cabin
    cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186)<<" Cabin  \t      ";
    cout<<char(186)<<"  "<<cabn<<"     "<<char(186)<<"    ";
    if(num1<10) cout<<'0'; cout<<num1<<"     "<<char(186);
    G_Total+=num1*cabn;
    cout<<"  "<<num1*cabn;
    if(num1*cabn<10000)    cout<<" ";  cout<<"    "<<char(186)<<"   "<<char(179);
        //Charges on other faculties
    if(pool==1)
    {
        cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186)<<" Swimming Pool   ";
        cout<<char(186)<<"  "<<swpool<<"     "<<char(186)<<"    ";
        if(num1<10) cout<<'0'; cout<<num1<<"     "<<char(186);
        G_Total+=num1*swpool;      cout<<"  "<<num1*swpool;
        if(num1*swpool<10000)    cout<<" ";    cout<<"    "<<char(186)<<"   "<<char(179);
    }
    if(gym==1)
    {
        cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186)<<" Gym    \t      ";
        cout<<char(186)<<"  "<<gm<<"     "<<char(186)<<"    ";
        if(num1<10) cout<<'0'; cout<<num1<<"     "<<char(186);
        G_Total+=num1*gm;        cout<<"  "<<num1*gm;
        if(num1*gm<10000)    cout<<" ";    cout<<"    "<<char(186)<<"   "<<char(179);
    }
    if(sports==1)
    {
        cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186)<<" Sports  \t      ";
        cout<<char(186)<<"  "<<spfts<<"     "<<char(186)<<"    ";
        if(num1<10) cout<<'0'; cout<<num1<<"     "<<char(186);
        G_Total+=num1*spfts;       cout<<"  "<<num1*spfts;
        if(num1*spfts<10000)     cout<<" ";     cout<<"    "<<char(186)<<"   "<<char(179);
    }
    if(salon==1)
    {
        cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186)<<" Salon  \t      ";
        cout<<char(186)<<"  "<<slon<<"     "<<char(186)<<"    ";
        if(num1<10) cout<<'0'; cout<<num1<<"     "<<char(186);
        G_Total+=num1*slon;        cout<<"  "<<num1*slon;
        if(num1*slon<10000) cout<<" ";     cout<<"    "<<char(186)<<"   "<<char(179);
    }
    if(spa==1)
    {
        cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186)<<" Spa  \t      ";
        cout<<char(186)<<"  "<<sp<<"    "<<char(186)<<"    ";
        if(num1<10) cout<<'0'; cout<<num1<<"     "<<char(186);
        G_Total+=num1*sp;      cout<<"  "<<num1*sp;
        if(num1*sp<1000000&&num1*sp>=100000)   cout<<" ";
        else    cout<<"  "; cout<<"  "<<char(186)<<"   "<<char(179);
    }
    if(theater==1)
    {
        cout<<"\n\t\t\t\t"<<char(179)<<"   "<<char(186)<<" Theater  \t      ";
        cout<<char(186)<<"  "<<ttr<<"      "<<char(186)<<"    ";
        if(num1<10) cout<<'0'; cout<<num1<<"     "<<char(186);
        G_Total+=num1*ttr;      cout<<"  "<<num1*ttr;
        if(num1==1)   cout<<"  ";
        else cout<<" "; cout<<"    "<<char(186)<<"   "<<char(179);
    }
    cout<<"\n\t\t\t\t"<<char(179)<<"   ";
    cout<<char(200);   for(int i=0;i<17;i++) cout<<char(205);
    cout<<char(202);for(int i=0;i<11;i++) cout<<char(205);
    cout<<char(202);for(int i=0;i<11;i++) cout<<char(205);
    cout<<char(202);for(int i=0;i<11;i++) cout<<char(205);
    cout<<char(188)<<"   "<<char(179);
//          Display Grand Total
    cout<<"\n\t\t\t\t"<<char(179);
    for(int i=0;i<61;i++)   cout<<" ";    cout<<char(179);
    cout<<"\n\t\t\t\t"<<char(179);
    cout<<"\t\t Grand Total : Rs ";
    long i=G_Total;
    if(G_Total>100000) //to provide comma’s for grand total
    {
    cout<<G_Total/100000<<",";
    G_Total=G_Total%100000;
    }
    if(G_Total>1000)
    {
    cout<<G_Total/1000<<",";
    G_Total=G_Total%1000;
    }
    cout<<G_Total<<".00                ";
    if(i<100000)   cout<<"   ";
    else if(i<1000000)  cout<<" ";     cout<<char(179);
    cout<<"\n\t\t\t\t"<<char(179);
    for(int i=0;i<61;i++)   cout<<" ";    cout<<char(179);

    cout<<"\n\t\t\t\t"<<char(179);
    cout<<" ! All Travelers below the age of 5 have not been charged !  "<<char(179);
    cout<<"\n\t\t\t\t"<<char(179);
    for(int i=0;i<61;i++)   cout<<" ";    cout<<char(179);
    cout<<"\n\t\t\t\t"<<char(197);
    for(int i=0;i<61;i++)   cout<<char(196);    cout<<char(197)<<"\n\n";
    getch();            //wait for any input
}

int main()
{
    system("cls");
    cout<<"\n\n\n\n\n\n";
    borderLine(char(205));
    cout<<'\n';
    borderLine(':');
    cout<<"\n\n\n\n\n\n\t\t\t\t\t********** CRUISE DATABASE MANAGEMENT";
    cout<<" **********\n\n\n\n\n\n";
    borderLine(':');
    cout<<'\n';
    borderLine(char(205));
    ifstream fl("INITIALL.dat",ios::binary); //initialisation of code
    if(!fl)
    {
        fl.read((char*)&code,sizeof(code));
        code=100000;
        fl.close();
    }   //end of if
    fl.read((char*)&code,sizeof(code));
    fl.close();
    int opt,opt1,opt2,opt3,opt4;
    int acceptcode,flag;
    getch();
    system("cls");
    do  //do 1st
    {
        system("cls");
        cout<<"\n\n";
        borderLine(':');
        cout<<"\n\n\n\t\t\t\t      *******.WELCOME TO THE CRUISE";
        cout<<" DATABASE SYSTEM.*******\n\n\n";
        borderLine(':');
        cout<<"\n\n\t\t\t\t\t\t\t MAIN MENU \n";
        cout<<"\t\t\t\t\t\t\t ~~~~~~~~~\n";
        borderLine(char(205));
        cout<<"\n\n\t\t\t\t\t\tPlease select a kind of user:";
        cout<<"\n\n\t\t\t\t\t\t\t<1>.New User";
        cout<<"\n\n\t\t\t\t\t\t\t<2>.Existing User";
        cout<<"\n\n\t\t\t\t\t\t\t<3>.Exit\n";
        borderLine(char(205));
        cout<<"\n\n\t\t\t\t\t\t\t     ";
        cin>>opt;
        switch(opt)     //SWITCH FOR opt
        {
            case 1 :
                do      //do while 2nd
                {
                    system("cls");
                    cout<<"\n\n\n";
                    borderLine(char(178));
                    cout<<"\n\n\n\t\t\t\t\t\t::::::::::NEW USER::::::::::\n";
                    cout<<"\t\t\t\t\t\t\t  ********\n\n\n";
                    borderLine(char(178));
                    cout<<"\n\n\t\t\t\t\tChoose the type of details you want to enter:";
                    cout<<"\n\n\t\t\t\t\t\t\t1.Persnal Details";
                    cout<<"\n\n\t\t\t\t\t\t\t2.Travel Details";
                    cout<<"\n\n\t\t\t\t\t\t\t3.Back\n\n";
                    borderLine(char(219));
                    cout<<"\n\n\t\t\t\t\t\t\t";
                    cin>>opt1;
                    switch(opt1)        //switch for opt1
                    {
                        case 1 :
                                {     code++;
                                    system("cls");
                                    P_object.p_input(code);
                                    ofstream ofl("PersonalDetails.dat",ios::binary|ios::app);
                                    if(!ofl)
                                    {   cout<<"\n\n\t\t\t\tSorry!The File ";
                                        cout<<"Cannot Be Opened For Writing\n\n";
                                    }
                                    ofl.write((char*)&P_object,sizeof(P_object));
                                    ofl.close();
                                    break;
                                }   //case 1 close
                        case 2 :
                                {
                                    T_object.t_input(code);
                                    ofstream ofl1("TravelDetails.dat",ios::binary|ios::app);
                                    if(!ofl1)
                                    {
                                        cout<<"\n\n\t\tSorry.The File ";
                                        cout<<"Cannot Be Opened For Writing\n";
                                    }
                                    ofl1.write((char*)&T_object,sizeof(T_object));
                                    ofl1.close();
                                    system("cls");
                                    cout<<"\n\n\n\n\t\t\t\t\t!!!!!Your Details Have Been Registered.";
                                    cout<<"\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~";
                                    cout<<"~~~~~~~~~~~~~~~~~~~~";
                                    cout<<"\n\n\n\n\t\t\t\t\tPlease Make A Note Of This Code : [";
                                    cout<<code<<']'<<"\n\t\t\t\t\t\t\t\t\t **********";
                                    cout<<"\n\n\n\t\t\t* For modifications,Please visit ";
                                    cout<<"existing user section in the main screen\n\n";
                                    borderLine(char(177));
                                    getch();
                                    break;
                                }       // case 2 close
                    }       //end of switch for opt1
                }while(opt1!=3);        //end of do while 2nd
                break;      //end of case 1 for opt
            case 2 :
                    {
                        system("cls");
                        cout<<"\n\n\n";
                        borderLine(char(223));
                        cout<<"\n\n\t\t\t\t\t\t***** EXISTING USER *****\n\n\n";
                        borderLine(char(223));
                        if(code==100000)
                        {
                            cout<<"\n\n\t\t\t\t\t\t    No Existing User";
                            cout<<"\n\t\t\t\t\t\t   ~~~~~~~~~~~~~~~~~~\n";
                            break;
                        }
                        else
                            cout<<"\n\n\t\t\t\tPlease Enter The Travel Code ";
                            cout<<"That Was Given To You\n\n\t\t\t\t\t\t\t ";
                        cin>>acceptcode;
                        if(acceptcode>code)
                        {
                            cout<<"\nNo such record has been created!";
                            break;
                        }
                        family(acceptcode,flag);
                        cout<<"\n\n\n\t\t\t\t\t\t\tCode no : [";
                        cout<<acceptcode<<"]\n\t\t\t\t\t\t\t          ~~~~~~~~\n\n\n";
                        getch();
                        if(flag==1)     //condition for match a code
                        {
                            do          //do while 3rd
                            {
                                system("cls");
                                borderLine(char(205));
                                cout<<"\n\n\t\t\t\t\t\t@@@@@@@@@ Information ";
                                cout<<"Center @@@@@@@@@";
                                cout<<"\n\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~\n\n";
                                borderLine(char(205));
                                cout<<"\n\n\t\t\t\tPlease select the type of operation ";
                                cout<<"that you would like to perform:";
                                cout<<"\n\n\t\t\t\t\t\t\t1.View Personal Details";
                                cout<<"\n\n\t\t\t\t\t\t\t2.View Travel Details";
                                cout<<"\n\n\t\t\t\t\t\t\t3.Edit Details";
                                cout<<"\n\n\t\t\t\t\t\t\t4.Compute Bill";
                                cout<<"\n\n\t\t\t\t\t\t\t5.Back\n\n";
                                borderLine(char(219));
                                cout<<"\n\n\t\t\t\t\t\t\t  ";       cin>>opt2;
                                switch(opt2)        //switch for opt2
                                {
                                    case 1:
                                        {
                                            ifstream ifl("PersonalDetails.dat",ios::binary);
                                            if(!ifl)
                                                cout<<"\n\n\n\n\t\t\t\t\t\tError\n\t";
                                            ifl.read((char*)&P_object,sizeof(P_object));
                                            while(!ifl.eof())
                                            {
                                                if(P_object.givecode()==acceptcode)
                                                    break;
                                                ifl.read((char*)&P_object,sizeof(P_object));
                                            }
                                            P_object.p_output();
                                            ifl.close();
                                            break;
                                        }
                                case 2:
                                {   ifstream ifl1("TravelDetails.dat",ios::binary);
                                    if(!ifl1)
                                        cout<<"\n\n\n\n\t\t\t\t\t\tError\n\t";
                                    ifl1.read((char*)&T_object,sizeof(T_object));
                                    while(!ifl1.eof())
                                        {
                                            if(T_object.gtcode()==acceptcode)
                                                break;
                                            ifl1.read((char*)&T_object,sizeof(T_object));
                                        }
                                    T_object.t_output();
                                    ifl1.close();
                                    break;
                                }
                                case 3 :
                                    do      //do while 4th   - in case 3 of opt2
                                    {
                                        system("cls");
                                        cout<<"\n\n\n";
                                        borderLine(char(178));
                                        cout<<"\n\n\n\t\t\t\t\t\t *****Edit Details***** \n\n\n";
                                        borderLine(char(177));
                                        cout<<"\n\n\t\t\t\tPlease select from among ";
                                        cout<<"the editing options:\n\n";
                                        cout<<"\t\t\t\t\t\t\t<1>.Modify";
                                        cout<<"\n\n\t\t\t\t\t\t\t<2>.Delete";
                                        cout<<"\n\n\t\t\t\t\t\t\t<3>.Back\n\n";
                                        borderLine(char(205));
                                        cout<<"\n\n\t\t\t\t\t\t\t   ";     cin>>opt3;
                                        switch(opt3)            //switch for opt3
                                        {
                                            case 1:
                                                do          //do while 5th - in case 1 of opt3
                                                {
                                                    system("cls");
                                                    cout<<"\n\n\n";
                                                    borderLine(char(205));
                                                    cout<<"\n\n\t\t\t\t\t\t:::::::::::Modification::::::::::: ";
                                                    cout<<"\n\t\t\t\t\t\t          ";
                                                    cout<<"~~~~~~~~~~~~~~\n\n";
                                                    borderLine(char(205));
                                                    cout<<"\n\n\t\t\t\t\tChoose The Type Of ";
                                                    cout<<"Details You Want To Modify :";
                                                    cout<<"\n\n\t\t\t\t\t\t\t<1>.Personal Details";
                                                    cout<<"\n\n\t\t\t\t\t\t\t<2>.Travel Details";
                                                    cout<<"\n\n\t\t\t\t\t\t\t<3>.Back\n\n";
                                                    borderLine(char(223));
                                                    cout<<"\n\n\t\t\t\t\t\t\t   ";
                                                    cin>>opt4;
                                                    switch(opt4)    //switch for opt4
                                                    {
                                                        case 1 :    editp(acceptcode);   break;
                                                        case 2 :    editt(acceptcode);   break;
                                                        case 3 :    break;
                                                    }       //end of  switch for opt4
                                                }while(opt4!=3);            //do while 5th - in case 1 of opt3 CLOSE
                                                break;          //end of case 1 for opt3
                                            case 2 :
                                                deletion(acceptcode);
                                                opt3=3;
                                                opt2=5;     break;
                                            case 3 :      break;
                                        }       //end of switch for opt3
                                    }while(opt3!=3);        //end of do while 4th   - in case 3 of opt2
                                    break;      //end of case 3 of opt2
                                case 4:
                                    {   ifstream ifl3("PersonalDetails.dat",ios::binary);
                                        if(!ifl3)
                                        {
                                            cout<<"\n\n\n";
                                            borderLine(char(205));
                                            cout<<"\n\n\t\t\t\t\t\tERROR! File is not found !\n\n";
                                            borderLine(char(205));
                                        }
                                        ifl3.read((char*)&P_object,sizeof(P_object));
                                        while(!ifl3.eof())
                                        {
                                            if(P_object.givecode()==acceptcode)
                                                break;
                                            ifl3.read((char*)&P_object,sizeof(P_object));
                                        }
                                        ifstream ifl2("TravelDetails.dat",ios::binary);
                                        if(!ifl2)
                                        {
                                            cout<<"\n\n\n";
                                            borderLine(char(205));
                                            cout<<"\n\n\t\t\t\t\t\tERROR! File is not found !\n\n";
                                            borderLine(char(205));
                                        }
                                        ifl2.read((char*)&T_object,sizeof(T_object));
                                        while(!ifl2.eof())
                                        {
                                            if(T_object.gtcode()==acceptcode)
                                                break;
                                            ifl2.read((char*)&T_object,sizeof(T_object));
                                        }
                                        T_object.accept(P_object.give());
                                        T_object.Bill_Comp();
                                        ifl2.close();
                                        break;
                                    }   //end of case 4 for opt2
                                case 5 :    break;
                            }   //end of switch(opt2)
                        }while(opt2!=5);    //do while 3rd close
                    }       //condition for code close
                    break;
                }   //end of case 2 for opt
            case 3 :
                ofstream fil("INITIALL.dat",ios::binary); //storing code value
                if(!fil)
                {
                        cout<<"\n\n\n";
                        borderLine(char(205));
                        cout<<"\n\n\t\t\t\t\t\tERROR! File is not found !\n\n";
                        borderLine(char(205));
                }
                fil.write((char*)&code,sizeof(code));
                fil.close();
                system("cls");
                cout<<"\n\n\n\n\n";
                borderLine(char(219));    //' █ ' character
                cout<<'\n';
                borderLine(char(205));
                cout<<'\n';
                borderLine(':');
                cout<<"\n\n\n\n\n\n\t\t\t\t\t   ********** Thank You";
                cout<<" **********\n\n\n\n\n\n";
                borderLine(':');
                cout<<'\n';
                borderLine(char(205));
                cout<<'\n';
                borderLine(char(219));
                cout<<"\n\n\n";
                getch();
            exit(0);           //end of case 3 for opt
        }               //end of switch for opt
        getch();
    }while(1);      // end of do 1st (infinite loop till exit selected)
}
