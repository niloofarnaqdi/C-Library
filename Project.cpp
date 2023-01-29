#include<iostream>
#include<fstream>
using namespace std;

fstream books_file("books.txt");
fstream user_file("user.txt");

bool search(string s){
    string  x;
    while ( getline (user_file,x)){    
      if (x.find(s, 0) != string::npos) 
          return true;
    
    return false;
}

class User{
    
    private:

     string password;
     string first_name;
     string last_name;
     string birth_date;

    public:

     string user_name;

     void setFirstName(string f){
       first_name=f;
     }

     void setLastName(string l){
      last_name=l;
     }
     void setBithDate(string b){
      birth_date=b;;
     }

     void setPassword(string p){
      password=p;
     }
     string getPassword(){
      return password;
     }

     bool sign_in(){
       string d=user_name +" "+ password;
       if(search(d))
        return true;
       return false;
     }
    
     void sign_up(){
      if(search(user_name))
       cout<<"this user name already exist";
      else{
        ofstream file("user.txt",ios_base::app);
        file<<first_name<<" "<<last_name<<" "<<birth_date<<" "<<user_name<<" "<<password<<"\n";
        file.close();

      }
     }

};
class Books{
 public:
  string title;
  string shelf_number;
  string author;
  string publlsher;
  string subjects;
  int edithion;
  int publlshed_year;
  int isbn;
  int length;
  

};

int main(){
  string enter;                
  string Password;
  string firstName;
  string lastName;
  string birthDate;
  User user;
  Books books;
  string mytext;
  bool c=false;
  cin>>enter;
  if(enter=="sign_in"){
    cin>>user.user_name>>Password;
    user.setPassword(Password);
    Password=user.getPassword(); 
  }
  if(enter=="sign_up"){
    cin>>firstName>>lastName>>birthDate>>user.user_name>>Password;
    user.setFirstName(firstName);
    user.setLastName(lastName);
    user.setBithDate(birthDate);
    user.setPassword(Password);
    user.sign_up();
  }
  string info;
  cin>>books.title>>books.shelf_number>>books.author>>books.publlsher>>
  books.subjects>>books.edithion>>books.publlshed_year>>books.isbn>>books.length;
  string book;
  int c=0;



  //barrow
  while ( getline (user_file,book)){    
      if (book.find(user.user_name, 0) != string::npos) 
          c++;
    }
  if(c<2){
    cin>>books.title>>books.shelf_number>>books.author>>books.publlsher>>
    books.subjects>>books.edithion>>books.publlshed_year>>books.isbn>>books.length;
    ofstream newFile("new.txt");
    string myline= books.title + " " + books.shelf_number+ " " +books.author+ " " +books.publlsher+ " " +
    books.subjects+ " " +books.edithion+ " " +books.publlshed_year+ " " +books.isbn+ " " +books.length + " free" +"NULL";
    int lineNumber;
    while ( getline (user_file,book)){    
      if (book.find(myline, 0) != string::npos) 
          lineNumber;
    }
    int line=0;
    while( getline(books_file,book) ){
        if(line != lineNumber)
           newFile<< book << "\n";
        else
         newFile<<books.title + " " + books.shelf_number+ " " +books.author+ " " +books.publlsher+ " " +books.subjects+ 
         " " +books.edithion+ " " +books.publlshed_year+ " " +books.isbn+ " " +books.length + " not_free" +user.user_name;
        line++;
    }
    newFile.close()

    remove("books.txt")
    rename("newFile.txt","book.txt");
  }
  if(c==2){
    "you have to give back at least one book!!"
  }
  //give back

    cin>>books.title>>books.shelf_number>>books.author>>books.publlsher>>
    books.subjects>>books.edithion>>books.publlshed_year>>books.isbn>>books.length;
    ofstream newFile("new.txt");
    string myline= books.title + " " + books.shelf_number+ " " +books.author+ " " +books.publlsher+ " " +
    books.subjects+ " " +books.edithion+ " " +books.publlshed_year+ " " +books.isbn+ " " +books.length + " not_free" +user.user_name;
    int lineNumber;
    while ( getline (user_file,book)){    
      if (book.find(myline, 0) != string::npos) 
          lineNumber;
    }
    int line=0;
    while( getline(books_file,book) ){
        if(line != lineNumber)
           newFile<< book << "\n";
        else
         newFile<<books.title + " " + books.shelf_number+ " " +books.author+ " " +books.publlsher+ " " +books.subjects+ 
         " " +books.edithion+ " " +books.publlshed_year+ " " +books.isbn+ " " +books.length + "free" + "NULL";
        line++;
    }
    newFile.close()
    
    remove("books.txt")
    rename("newFile.txt","book.txt");






}
