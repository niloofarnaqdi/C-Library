#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool search(string s) {
    string  x;
    fstream user_file("user.txt");
    while (getline(user_file, x)) {
        if (x.find(s, 0) != string::npos)
            return true;
    }
    return false;
}

class User {
private:
    string password;
    string first_name;
    string last_name;
    string birth_date;

public:
    string user_name;

    void setFirstName(string f) {
        first_name = f;
    }

    void setLastName(string l) {
        last_name = l;
    }
    void setBithDate(string b) {
        birth_date = b;
    }

    void setPassword(string p) {
        password = p;
    }
    string getPassword() {
        return password;
    }

    bool sign_in() {
        string d = user_name + " " + password;
        if (search(d))
            return true;
        cout << "ther is no user with this charactristics" << "\n";
        return false;
    }

    bool sign_up() {
        if (search(user_name)) {
            cout << "this username already exist" << "\n";
            return false;
        }
        else {
            ofstream file("user.txt", ios_base::app);
            file << first_name << " " << last_name << " " << birth_date << " " << user_name << " " << password << "\n";
            file.close();
            return true;
        }
    }

};

class Books {
public:
    string title;
    string shelf_number;
    string author;
    string publlsher;
    string subjects;
    string edithion;
    string publlshed_year;
    string isbn;
    string length;

    void borrow(string username) {
        string book;
        User user;
        bool existence = false;
        ofstream newFile("new.txt", ios_base::app);
        ifstream booksfile1("book.txt");
        string myline = title + " " + shelf_number + " " + author + " " + edithion + " " +
            publlsher + " " + publlshed_year + " " + isbn + " " + length + " " + subjects;
        int lineNumber = 1;
        int line = 1;
        while (getline(booksfile1, book)) {
            if (book.find(myline, 0) != string::npos && book.find("not_free", 0) == string::npos) {
                existence = true;
                break;
            }
            lineNumber++;

        }

        if (existence) {
            string b;
            booksfile1.close();
            ifstream booksfile2("book.txt");
            while (getline(booksfile2, b)) {
                if (line != lineNumber)
                    newFile << b << "\n";
                else if (line == lineNumber)
                    newFile << myline << " " << "not_free " + username << "\n";
                line++;
            }
            remove("book.txt");
            rename("new.txt", "book.txt");
            cout << "enjoy your reading!" << "\n";
        }
        else
            cout << "the book that you looking for does not exsit. please search again and make sure that you enter the information correctly and the book is not taken by someone else" << "\n";
    }

    void give_back(string username) {
        string book;
        bool existence = false;
        ofstream newFile("new.txt", ios_base::app);
        ifstream booksfile1("book.txt");
        string myline = title + " " + shelf_number + " " + author + " " + edithion + " " +
            publlsher + " " + publlshed_year + " " + isbn + " " + length + " " + subjects;
        int lineNumber = 1;
        int line = 1;
        while (getline(booksfile1, book)) {
            if (book.find(myline, 0) != string::npos && book.find(username, 0) != string::npos) {
                existence = true;
                break;
            }
            lineNumber++;

        }
        if (existence) {
            string b;
            booksfile1.close();
            ifstream booksfile2("book.txt");
            while (getline(booksfile2, b)) {
                if (line != lineNumber)
                    newFile << b << "\n";
                else if (line == lineNumber)
                    newFile << myline << " " << "free" << " NULL" << "\n";
                line++;
            }
            remove("book.txt");
            rename("new.txt", "book.txt");
            cout << "thank you!!" << "\n";
        }
        else
            cout << "the book that you are looking for does not exsit. please search again and make sure that you've entered the information correctly and it's not borrowed by someone else" << "\n";

    }

};

bool N(string username) { //check the number of books that user borrowed before
    ifstream booksFile("book.txt");
    string book;
    int n = 0;
    while (getline(booksFile, book)) {
        if (book.find(username, 0) != string::npos)
            n++;
    }

    if (n < 2) {
        return true;
    }
    return false;
}
void Mission(string username) {
    string m;
    Books books;
    cout << "please choose your mission( search , borrow , give_back):" << "\n";
    cin >> m;
    if (m == "borrow") {
        if (N(username)) {
            cout << "please enter  precise characteristic of the book that you want:" << "\n";
            cin >> books.title >> books.shelf_number >> books.author >> books.edithion >>
                books.publlsher >> books.publlshed_year >> books.isbn >> books.length >> books.subjects;
            books.borrow(username);
        }
        else
            cout << "you have already borrowd 2 books. give back at least one book to get another one" << "\n";
    }

    if (m == "give_back") {
        cout << "please enter  precise characteristic of the book that you have:" << "\n";
        cin >> books.title >> books.shelf_number >> books.author >> books.edithion >>
            books.publlsher >> books.publlshed_year >> books.isbn >> books.length >> books.subjects;
        books.give_back(username);

    }
    if (m == "search") {

        string information[9];
        int data = 0;
        cout << "please enter any of the  following information that you have.(enter '-' if you didnt know!)" << "\n";
        cout << "title " << "shelfnubmer " << "auther " << "edithion " << "publisher " << "publishedyear " << "isbn " << "length " << "subject " << "\n";
        cin >> information[0] >> information[1] >> information[2] >> information[3] >>
            information[4] >> information[5] >> information[6] >> information[7] >> information[8];
        for (int i = 0; i < 9; i++) {
            if (information[i] != "-")
                data++;
        }

        string updat_info[data];
        int d = 0;
        for (int i = 0; i < 9; i++) {
            if (information[i] != "-") {
                updat_info[d] = information[i];
                d++;
            }
        }
        ifstream booksFile("book.txt");
        string info;
        bool b;
        cout << "result" << "\n";

        while (getline(booksFile, info)) {
            if ((information[0] == "-" || info.find(information[0]) < 100)
                && (information[1] == "-" || info.find(information[1]) < 100)
                && (information[2] == "-" || info.find(information[2]) < 0)
                && (information[3] == "-" || info.find(information[3]) < 0)
                && (information[4] == "-" || info.find(information[4]) < 0)
                && (information[5] == "-" || info.find(information[5]) < 0)
                && (information[6] == "-" || info.find(information[6]) < 0)
                && (information[7] == "-" || info.find(information[7]) < 0)
                && (information[8] == "-" || info.find(information[8]) < 0))
                cout << info << "\n";
        }
    }
    int f = 0;
    cout << "if you stil want to do mission enter 1 and if you want to exit enter 0" << "\n";
    cin >> f;
    if (f == 1) {
        Mission(username);
    }
}

int main() {
    string enter;
    string Password;
    string firstName;
    string lastName;
    string birthDate;
    User user;

    string mytext;
    bool c = true;
    int f = 0;
    cout << "enter sign_in or sign_up for start!:" << "\n";
    cin >> enter;
    while (f == 0) {

        if (enter == "sign_in") {
            cout << "please enter the following information:" << "\n";
            cout << "username password" << "\n";
            cin >> user.user_name >> Password;
            user.setPassword(Password);
            Password = user.getPassword();
            c = user.sign_in();
            if (!c) {
                cout << "pleas sign_in again" << "\n";
                f = 0;
            }
            else {
                f = 1;
                Mission(user.user_name);
            }
        }
        if (enter == "sign_up") {
            cout << "pleas inter the following information:" << "\n";
            cout << "firstname lastname birthdate username password" << "\n";
            cin >> firstName >> lastName >> birthDate >> user.user_name >> Password;
            user.setFirstName(firstName);
            user.setLastName(lastName);
            user.setBithDate(birthDate);
            user.setPassword(Password);
            c = user.sign_up();
            if (!c) {
                cout << "please sign up again" << "\n";
                f = 0;
            }
            else {
                f = 1;
                Mission(user.user_name);
            }
        }
    }
}