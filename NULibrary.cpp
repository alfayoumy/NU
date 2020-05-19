//NU Library
//ECEN307 Project
//Fall 2019
//Amr Medhat Assem  ID 19105223
//


#include<iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int concat(int a, int b);

class Hashing
{
int hash_bucket;    // No. of buckets

    // Pointer to an array containing buckets
list<vector<string>> *hashtable;

public:
Hashing(int V);  // Constructor

    // inserts a key into hash table
void insert_key(int val, vector<string> val2);

    // deletes a key from hash table
void delete_key(int key, vector<string> key2);

int look_forbn(int key, vector<string> key2);

void look_forln(int key, string key2);

void look_forau(int key, vector<string> key2);

void cpschange(int key, vector<string> key2, string cps);

void retrn(int key, vector<string> key2, string cps);

void getinfo(int key, vector<string> key2);

int copies(int key, vector<string> key2);

void shelf(int key, vector<string> key2, string cps);

void borrow(int key, vector<string> key2, string cps);

int hashFunction(int x) {
return (x % hash_bucket);
    }

void printHash();

void displayHash();
};


Hashing::Hashing(int b)
{
this->hash_bucket = b;
hashtable = new list<vector<string>>[hash_bucket];
}

//insert to hash table
void Hashing::insert_key(int key, vector<string> key2)
{
    int index = hashFunction(key);
    hashtable[index].push_back(key2);
}


void Hashing::borrow(int key, vector<string> key2, string cps)
{
    int index = hashFunction(key);
    vector<string> newbook;
    for (auto x : hashtable[index]) {
    if ((*(x.cbegin())==*(key2.cbegin())) && (*(x.cbegin()+1)==*(key2.cbegin()+1)) && (*(x.cbegin()+2)==*(key2.cbegin()+2)) && (*(x.cbegin()+3)==*(key2.cbegin()+3)))
	{
	    for(int i=0; i<x.size()-1; i++)
                newbook.push_back(x[i]);
    }

}
    cps=to_string((stoi(cps)-1));
    newbook.push_back(cps);
    delete_key(key,key2);
    insert_key(key,newbook);
}


void Hashing::retrn(int key, vector<string> key2, string cps)
{
    int index = hashFunction(key);
    vector<string> newbook;
    for (auto x : hashtable[index]) {
    if ((*(x.cbegin())==*(key2.cbegin())) && (*(x.cbegin()+1)==*(key2.cbegin()+1)) && (*(x.cbegin()+2)==*(key2.cbegin()+2)) && (*(x.cbegin()+3)==*(key2.cbegin()+3)))
	{
	    for(int i=0; i<x.size()-1; i++)
                newbook.push_back(x[i]);
    }

}
    cps=to_string((stoi(cps)+1));
    newbook.push_back(cps);
    delete_key(key,key2);
    insert_key(key,newbook);
}


void Hashing::cpschange(int key, vector<string> key2, string cps)
{
    int index = hashFunction(key);
    vector<string> newbook;
    for (auto x : hashtable[index]) {
    if ((*(x.cbegin())==*(key2.cbegin())) && (*(x.cbegin()+1)==*(key2.cbegin()+1)) && (*(x.cbegin()+2)==*(key2.cbegin()+2)) && (*(x.cbegin()+3)==*(key2.cbegin()+3)))
	{
	    for(int i=0; i<x.size()-1; i++)
                newbook.push_back(x[i]);
    }

}
    newbook.push_back(cps);
    delete_key(key,key2);
    insert_key(key,newbook);
}


void Hashing::shelf(int key, vector<string> key2, string shelf)
{
    int index = hashFunction(key);
    int i;
    vector<string> newbook;
    for (auto x : hashtable[index]) {
    if ((*(x.cbegin())==*(key2.cbegin())) && (*(x.cbegin()+1)==*(key2.cbegin()+1)) && (*(x.cbegin()+2)==*(key2.cbegin()+2)) && (*(x.cbegin()+3)==*(key2.cbegin()+3)))
	{
	    for(i=0; i<x.size()-2; i++)
                newbook.push_back(x[i]);
            newbook.push_back(shelf);
            newbook.push_back(x[++i]);
    }

}

    delete_key(key,key2);
    insert_key(key,newbook);
}


void Hashing::delete_key(int key, vector<string> key2)
{

    int index = hashFunction(key);
    for (auto x : hashtable[index]) {
    if ((*(x.cbegin())==*(key2.cbegin())) && (*(x.cbegin()+1)==*(key2.cbegin()+1)) && (*(x.cbegin()+2)==*(key2.cbegin()+2)) && (*(x.cbegin()+3)==*(key2.cbegin()+3)))
	{
                key2.push_back(x[x.size()-2]);
                key2.push_back(x[x.size()-1]);
    }

}

list<vector<string>> :: iterator it;
it=find(hashtable[index].begin(), hashtable[index].end(), key2);
       hashtable[index].erase(it);
   }


void Hashing::look_forau(int key, vector<string> key2)
{
  int index = hashFunction(key);
list <vector<string>> :: iterator it;
cout<<endl<<"Books by: "<<*(key2.cbegin()+1)<<" "<<*(key2.cbegin())<<endl;;

for (auto x : hashtable[index]) {
            if ((*(x.cbegin())==*(key2.cbegin())) && (*(x.cbegin()+1)==*(key2.cbegin()+1))) { //) {
                for (auto it = x.cbegin(); it != x.cend(); it++)
        {
	    cout<<*it;
		if((it+1) != x.cend()) cout<<", ";
    if((it) == x.cbegin()+3) cout<<" Shelf #";
    if((it) == x.cbegin()+4) cout<<" Cps: ";
        }
	cout<<endl;
    }
}
}


void Hashing::look_forln(int key, string key2)
{
int index = hashFunction(key);
list <string> :: iterator it;
      for (auto x : hashtable[index]) {
            if (*x.cbegin()==key2) {
                for (auto it = x.cbegin(); it != x.cend(); it++)
        {
	    cout<<*it;
		if((it+1) != x.cend()) cout<<", ";
    if((it) == x.cbegin()+3) cout<<" Shelf #";
    if((it) == x.cbegin()+4) cout<<" Cps: ";
        }
	cout<<endl;
    }
}
}


int Hashing::look_forbn(int key, vector<string> key2)
{
int index = hashFunction(key);
int found=0;
for (auto x : hashtable[index]) {
    if ((*(x.cbegin())==*(key2.cbegin())) && (*(x.cbegin()+1)==*(key2.cbegin()+1)) && (*(x.cbegin()+2)==*(key2.cbegin()+2)) && (*(x.cbegin()+3)==*(key2.cbegin()+3)))
        found=1;
    }
return found;
}





// display the hash table
void Hashing::displayHash() {
    for(int j=0; j<26; j++) {
        char k=('A'+j);
    for(int m=0; m<26; m++) {
        char l=('a'+m);
        int c=concat(k,l);
        if(hashtable[c].begin()!=hashtable[c].end()) {
            cout<<k<<l<<"\t";

            for (auto x : hashtable[c]) {
                cout<<endl<< "\t";

        //for (auto it = x.cbegin(); it != x.cbegin()+4 ; it++)
		for (auto it = x.cbegin(); it != x.cend(); it++)
        {
	    cout<<*it;
		if((it+1) != x.cend()) cout<<", ";
    if((it) == x.cbegin()+3) cout<<" Shelf #";
    if((it) == x.cbegin()+4) cout<<" Cps: ";
        }
    }
    cout<<endl;
    }
}
}
}


int concat(int a, int b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);
    string s = s1 + s2;
    int c = stoi(s);
    return c;
}


void Hashing::getinfo(int key, vector<string> key2)
{
    int index = hashFunction(key);
    for (auto x : hashtable[index]) {
    if ((*(x.cbegin())==*(key2.cbegin())) && (*(x.cbegin()+1)==*(key2.cbegin()+1)) && (*(x.cbegin()+2)==*(key2.cbegin()+2)) && (*(x.cbegin()+3)==*(key2.cbegin()+3)))
	{
                cout<<endl<<"Book is on shelf #"<<x[x.size()-2]<<endl;
                cout<<"No. of available copies is "<<x[x.size()-1]<<endl;
    }

}
}


int Hashing::copies(int key, vector<string> key2)
{
    int index = hashFunction(key);
    for (auto x : hashtable[index]) {
        if ((*(x.cbegin())==*(key2.cbegin())) && (*(x.cbegin()+1)==*(key2.cbegin()+1)) && (*(x.cbegin()+2)==*(key2.cbegin()+2)) && (*(x.cbegin()+3)==*(key2.cbegin()+3)))
                return stoi(x[x.size()-1]);
}
return 0;
}



// display the hash table
void Hashing::printHash() {
     ofstream ofile("output.txt");     //read file
if (ofile.is_open()) {
    for(int j=0; j<26; j++) {
        char k=('A'+j);
    for(int m=0; m<26; m++) {
        char l=('a'+m);
        int c=concat(k,l);
        if(hashtable[c].begin()!=hashtable[c].end()) {
            ofile<<k<<l<<"\t";

            for (auto x : hashtable[c]) {
                ofile<<endl<< "\t";

		for (auto it = x.cbegin(); it != x.cend(); it++)
        {
	    ofile<<*it;
		if((it+1) != x.cend()) ofile<<", ";
    if((it) == x.cbegin()+3) ofile<<" Shelf #";
    if((it) == x.cbegin()+4) ofile<<" Cps: ";
        }
    }
    ofile<<endl;
    }
}
}
}
else cout<<endl<<"File not found!";
}


// main program
int main() {


int m=-1, rep=0; string s;
Hashing h(90123);

ifstream inFile("data.txt");     //read file
    if (inFile.is_open())
    {
        string line;
        while( getline(inFile,line) )
        {
            stringstream ss(line);
            string LName, FName, BName, Yr, shelf, cps;
            getline(ss,LName,'/');     //cout<<"\""<<firstLetter<<", \""<<LName<<"\"";
            char firstLetter = LName.at(0); char secondLetter = LName.at(1);
            getline(ss,FName,'/'); //cout<<", \""<<FName<<"\"";
            getline(ss,BName,'/');    //cout<<", \""<<BName<<"\"";
            getline(ss,Yr,'/');    //cout<<", \""<<Yr<<"\"";
            getline(ss,shelf,'/');
            getline(ss,cps);
            vector<string> bookname={LName,FName,BName,Yr,shelf,cps};

                int cnc=concat(int(firstLetter), int(secondLetter));
                h.insert_key(cnc,bookname);
        }
            // display the Hash table

        cout<<endl<<"Hash table created:"<<endl;
        h.displayHash();
        cout<<"\n";
    }


while (m!=0) {
if (m==1) {     //display

            // display the Hash table
        cout<<endl<<"Hash table created:"<<endl;
        h.displayHash();
        cout<<"\n";
        system("pause");
    }


if (m==2) {     //delete existing entry
  //insert the keys into the hash table
cout<<"Input Book Name to delete"<<endl;
string line;
            string LName, FName, BName, Yr;
            stringstream ss(line);
            cin.ignore();
            getline(cin,LName,'/');       char firstLetter = LName.at(0); char secondLetter = LName.at(1);
            getline(cin,FName,'/'); //cout<<", \""<<Fhashtable[index]Name<<"\"";
            getline(cin,BName,'/');    //cout<<", \""<<BName<<"\"";
            getline(cin,Yr);    //cout<<", \""<<Yr<<"\"";
            vector<string> bookname={LName,FName,BName,Yr};
          int cnc=concat(int(firstLetter), int(secondLetter));
        if (h.look_forbn(cnc,bookname)) {
              h.delete_key(cnc,bookname);
                             // display the Hash table
              cout<<"Hash table after deletion:"<<endl;
              h.displayHash();
            }
        else cout<<"Book is not found/Invalid entry"<<endl;
        system("pause");

}


if (m==3) {     //insert entry

cout<<"Input Book Name to insert OR return"<<endl;
string line;
            string LName, FName, BName, Yr, shelf, cps;
            cin.ignore();
            getline(cin,LName,'/');     char firstLetter = LName.at(0); char secondLetter = LName.at(1);  //cout<<LName<<"\""; //"\""<<firstLetter<<", \""
            getline(cin,FName,'/'); //cout<<", \""<<FName<<"\"";
            getline(cin,BName,'/');    //cout<<", \""<<BName<<"\"";
            getline(cin,Yr);//,'/');    //cout<<", \""<<Yr<<"\"";
            vector<string> bookname={LName,FName,BName,Yr};
            string srch=LName+'/'+FName+'/'+BName+'/'+Yr;

int cnc=concat(int(firstLetter), int(secondLetter));
if (!h.look_forbn(cnc,bookname)) {
        string cps, shelf;
        cout<<endl<<"Enter shelf position (ie S30): ";
        cin>> shelf;
        bookname.push_back(shelf);
        cout<<endl<<"Enter no. of copies (ie 5): ";
        cin>> cps;
        bookname.push_back(cps);
        h.insert_key(cnc,bookname);
}

else    {
            string cp; int cond;
            cout<<"Book already exists"<<endl;
            h.getinfo(cnc,bookname);
            cout<<endl<<"Enter 1 to return a copy, 2 to change number of copies, 0 to return to main menu: ";
            cin>>cond;
            if(cond==2) {
            cout<<endl<<"Enter no. of copies: "<<endl;
            cin>>cp;
            h.cpschange(cnc,bookname,cp);
            }
            if(cond==1) {
            int cps=h.copies(cnc,bookname);
            h.retrn(cnc,bookname,to_string(cps));
            }
            if(cond==0)
            ;
        }
  // display the Hash table
  cout<<"Hash table after: "<<endl;
  h.displayHash();
  system("pause");
}


if (m==4) {     //look for book by book name
cout<<"Input Book Name to look for:"<<endl;
cin.ignore();
string line;
            string LName, FName, BName, Yr;
            stringstream ss(line);
            getline(cin,LName,'/');     char firstLetter = LName.at(0); char secondLetter = LName.at(1);  //cout<<LName<<"\""; //"\""<<firstLetter<<", \""
            getline(cin,FName,'/'); //cout<<", \""<<FName<<"\"";
            getline(cin,BName,'/');    //cout<<", \""<<BName<<"\"";
            getline(cin,Yr);    //cout<<", \""<<Yr<<"\"";
            vector<string> bookname={LName,FName,BName,Yr};

  int cnc=concat(int(firstLetter), int(secondLetter));
  if (h.look_forbn(cnc,bookname)) cout<<"Book is available"<<endl;
  else cout<<"Book is unavailable"<<endl;
  system("pause");
}


if (m==6) {     //look for book by author name
  //insert the keys into the hash table
cout<<"Input author name to look for:"<<endl;
cin.ignore();
string line;
            string LName, FName, BName, Yr;
            stringstream ss(line);
            getline(cin,LName,'/');     char firstLetter = LName.at(0); char secondLetter = LName.at(1);  //cout<<LName<<"\""; //"\""<<firstLetter<<", \""
            getline(cin,FName);
            vector<string> bookname={LName,FName};
  int cnc=concat(int(firstLetter), int(secondLetter));
  h.look_forau(cnc,bookname);
  system("pause");
}


if (m==5) {     //look for book by author's last name
cout<<"Input author's last name to look for:"<<endl;
    cin.ignore();
    string LName;
    getline(cin,LName);     char firstLetter = LName.at(0); char secondLetter = LName.at(1);
  int cnc=concat(int(firstLetter), int(secondLetter));
  h.look_forln(cnc,LName);
  system("pause");
}


if (m==7) {     //get info
cout<<"Input Book Name to get info for:"<<endl;
cin.ignore();
string line;
            string LName, FName, BName, Yr;
            stringstream ss(line);
            getline(cin,LName,'/');     char firstLetter = LName.at(0); char secondLetter = LName.at(1);  //cout<<LName<<"\""; //"\""<<firstLetter<<", \""
            getline(cin,FName,'/'); //cout<<", \""<<FName<<"\"";
            getline(cin,BName,'/');    //cout<<", \""<<BName<<"\"";
            getline(cin,Yr);    //cout<<", \""<<Yr<<"\"";
            vector<string> bookname={LName,FName,BName,Yr};
            string srch=LName+'/'+FName+'/'+BName+'/'+Yr;

  int cnc=concat(int(firstLetter), int(secondLetter));
  if (h.look_forbn(cnc,bookname))
    {
          cout<<"Book is available"<<endl;
          h.getinfo(cnc,bookname);
    }

else cout<<"Book is unavailable"<<endl;
  system("pause");
}


if (m==8) {     //change position
cout<<"Input Book Name to change position for:"<<endl;
cin.ignore();
string line;
            string LName, FName, BName, Yr;
            stringstream ss(line);
            getline(cin,LName,'/');     char firstLetter = LName.at(0); char secondLetter = LName.at(1);  //cout<<LName<<"\""; //"\""<<firstLetter<<", \""
            getline(cin,FName,'/'); //cout<<", \""<<FName<<"\"";
            getline(cin,BName,'/');    //cout<<", \""<<BName<<"\"";
            getline(cin,Yr);    //cout<<", \""<<Yr<<"\"";
            vector<string> bookname={LName,FName,BName,Yr};
            string srch=LName+'/'+FName+'/'+BName+'/'+Yr;

  int cnc=concat(int(firstLetter), int(secondLetter));
  if (h.look_forbn(cnc,bookname))
    {
        string shelf;
        cout<<endl<<"Enter new position (ie. #C30): "<<endl;
        cin>> shelf;
        h.shelf(cnc,bookname,shelf);
        h.getinfo(cnc,bookname);
    }

else cout<<"Book is not found/Invalid entry"<<endl;
  system("pause");
}


if (m==9) {     //borrow
cout<<"Input Book Name to borrow:"<<endl;
cin.ignore();
string line;
            string LName, FName, BName, Yr;
            stringstream ss(line);
            getline(cin,LName,'/');     char firstLetter = LName.at(0); char secondLetter = LName.at(1);  //cout<<LName<<"\""; //"\""<<firstLetter<<", \""
            getline(cin,FName,'/'); //cout<<", \""<<FName<<"\"";
            getline(cin,BName,'/');    //cout<<", \""<<BName<<"\"";
            getline(cin,Yr);    //cout<<", \""<<Yr<<"\"";
            vector<string> bookname={LName,FName,BName,Yr};

  int cnc=concat(int(firstLetter), int(secondLetter));
  int cps=h.copies(cnc,bookname);
  if (cps)
    {
        cout<<"Book is found"<<endl;
        cout<<"Info AFTER borrowing:"<<endl;
        h.borrow(cnc,bookname,to_string(cps));
        h.getinfo(cnc,bookname);
//        system("pause");
    }

else cout<<"Book is not found/Invalid entry"<<endl;
  system("pause");
}

system("cls");
cout<<endl<<R"(
  _   _   _    _     _        _____   ____    _____               _____   __     __
 | \ | | | |  | |   | |      |_   _| |  _ \  |  __ \      /\     |  __ \  \ \   / /
 |  \| | | |  | |   | |        | |   | |_) | | |__) |    /  \    | |__) |  \ \_/ /
 | . ` | | |  | |   | |        | |   |  _ <  |  _  /    / /\ \   |  _  /    \   /
 | |\  | | |__| |   | |____   _| |_  | |_) | | | \ \   / ____ \  | | \ \     | |
 |_| \_|  \____/    |______| |_____| |____/  |_|  \_\ /_/    \_\ |_|  \_\    |_|

)"<<endl;
cout<<endl<<"\t\tINPUT FORMAT: LastName/FirstName/BookTitle/PublishingYear\n\nSelect option from the menu: \n1 to view the library\n2 to delete an existing book\n3 to return/insert a book\n4 to check availability by book name\n5 to look for a book by author's last name\n6 to look for a book by author's full name\n7 to get info for an existing book\n8 to change position for an existing book\n9 to borrow a book\n0 to exit and/or save\n\n\tYour option is: ";
cin>>m;
}

char save;
cout<<endl<<"Save before exit? Enter Y for Yes, N for No"<<endl;
cin>>save;
if (save=='Y' || save=='y') {
        h.printHash();
        cout<<endl<<"Success"<<endl;
}
else return 0;
}
