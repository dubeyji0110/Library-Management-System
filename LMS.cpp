#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

class Library{
    public:
        char bookName[50], authorName[50], publication[50], bookId[50];
        int price, quantity, B;
        
        Library(){
            strcpy(bookName, "No Name");
            strcpy(authorName, "No Author");
            strcpy(publication, "No Publication");
            strcpy(bookId, "No Id");
            price = 0;
            quantity = 0;
            B = 0;
        }

        void start();
        void student();
        void modifyBook();
        void Admin();
        void changePass();
        void newBook();
        void pass();
        void showBook(int);
        void bookList(int);
        void getBook(int);
        int branch(int);
        void issueBook();
        void der(char[], int, int);
        void fine(int, int, int, int, int, int);
};

void Library::start(){
    int ch;
    cout << "\t~~~~~~~~~~~~~~~~~~~~ LIBRARY MANAGEMENT SYSTEM ~~~~~~~~~~~~~~~~~~~~\n\t\t\t\t\t\t\t\tBy: Devansh Dubey\n";
    cout << "\n\t\t\t>>> LOGIN MENU <<<\n";;
    cout << "\n\t\t\t1. Admin User\n\t\t\t2. Student\n\t\t\t3. Exit\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> ch;

    if(ch == 1)
        pass();
    else if(ch == 2){
        system("cls");
        student();
    }
    else if(ch == 3)
        exit(0);
    else{
        cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
        system("PAUSE");
        system("cls");
        start();
    }
}

void Library::student(){
    int ch;
    cout << "\t\t~~~~~~~~~~~~~~~~~~~~ STUDENT SECTION ~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\t\t\t>>> MENU <<<\n";
    cout << "\n\t\t\t1. View BookList\n\t\t\t2. Search a Book\n\t\t\t3. Go to Login Menu\n\t\t\t4. Exit\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> ch;

    if(ch == 1)
        bookList(1);
    else if(ch == 2)
        getBook(1);
    else if(ch == 3){
        system("cls");
        start();
    }
    else if(ch == 4)
        exit(0);
    else{
        cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
        system("PAUSE");
        system("cls");
        student();
    }
}

void Library::pass(){
    int i = 0;
    char s[21], str[21] = "Admin123", ch;
    cout << "\n\t\t\tEnter Password: ";
    while(true){
        ch = getch();
        if(ch == 13){
            s[i] = '\0';
            break;
        }
        else if(ch == 8 && i > 0){
            i--;
            cout << "\b \b";
        }
        else{
            cout << "*";
            s[i] = ch;
            i++;
        }
    }
    ifstream inf("password.txt");
    inf >> str;
    inf.close();

    for(i = 0; s[i] == str[i] && s[i] != '\0' && str[i] != '\0'; i++);
    if(s[i] == '\0' && str[i] == '\0'){
        system("cls");
        Admin();
    }
    else{
        cout << "\n\n\t\t\tWRONG PASSWORD!!\n\t\t\t";
        system("PAUSE");
        system("cls");
        start();
    }
}

void Library::Admin(){
    int ch;
    cout << "\t\t~~~~~~~~~~~~~~~~~~~~ ADMIN SECTION ~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\t\t\t>>> MENU <<<\n";
    cout << "\n\t\t\t1. View BookList\n\t\t\t2. Search a Book\n\t\t\t3. Modify/Add Book\n\t\t\t4. Issue Book\n\t\t\t5. Go to Login Menu\n\t\t\t6. Change Password\n\t\t\t7. Exit\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> ch;

    switch(ch){
        case 1:
            bookList(2);
            break;
        case 2:
            getBook(2);
            break;
        case 3:
            modifyBook();
            break;
        case 4:
            issueBook();
            break;
        case 5:
            system("cls");
            start();
            break;
        case 6:
            changePass();
            break;
        case 7:
            exit(0);
        default:
            cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
            system("PAUSE");
            system("cls");
            Admin();
    }
}

void Library::changePass(){
    int i = 0;
    char ch, s[21], str[11] = "Admin12345";
    system("cls");
    cout << "\n\t\t\tEnter Old Password: ";
    while(true){
        ch = getch();
        if(ch == 13){
            s[i] = '\0';
            break;
        }
        else if(ch == 8 && i > 0){
            i--;
            cout << "\b \b";
        }
        else{
            cout << "*";
            s[i] = ch;
            i++;
        }
    }
    ifstream inf("password.txt");
    inf >> str;
    inf.close();

    for(i = 0; s[i] == str[i] && s[i] != '\0' && str[i] != '\0'; i++);
    if(s[i] == '\0' && str[i] == '\0'){
        system("cls");
        cout << "\n\t\t\tNew Password should be of exactly 10 Characters and should not contain 'spaces'.\n";
        cout << "\n\t\t\tEnter New Password: ";
        fflush(stdin);
        i = 0;
        int j = 0;
        while(true){
            j++;
            ch = getch();
            if(ch == 13){
                for(i = 0; s[i] != ' ' && s[i] != '\0'; i++);
                if(j != 10 || s[i] == ' '){
                    cout << "\n\n\t\t\tPassword Does met given criteria\n\t\t\t";
                    system("PAUSE");
                    system("cls");
                    changePass();
                    Admin();
                }
                s[i] = '\0';
                break;
            }
            else if(ch == 8 && i > 0){
                i--;
                cout << "\b \b";
            }
            else{
                cout << "*";
                s[i] = ch;
                i++;
            }
        }
        ofstream outf("temp.txt");
        outf << s;
        outf.close();
        remove("password.txt");
        rename("temp.txt", "password.txt");

        cout << "\n\n\t\t\tPassword Changed Successfully!\n\t\t\t";
        system("PAUSE");
        system("cls");
        Admin();
    }
    else{
        cout << "\n\t\t\tIncorrect Password\n";
        system("cls");
        Admin();
    }
}

void Library::newBook(){
    int i;
    fflush(stdin);
    cout << "\n\n\t\t\tEnter Book Details:\n";
    cout << "\n\n\t\t\tEnter Book's Name: ";
    cin.getline(bookName, 50);
    for(i = 0; bookName[i] != '\0'; i++)
        if(bookName[i] >= 'a' && bookName[i] <= 'z')
            bookName[i] -= 32;
    cout <<  "\t\t\tEnter Author Name: ";
    cin.getline(authorName, 50);
    cout << "\t\t\tEnter Publication: ";
    cin.getline(publication, 50);
    cout << "\t\t\tEnter Book's ID: ";
    cin.getline(bookId, 50);
    cout << "\t\t\tEnter Book's Price: ";
    cin >> price;
    cout << "\t\t\tEnter Book's Quantity: ";
    cin >> quantity;
}

void Library::showBook(int i){
    cout << "\n\t\t\tBook Name: " << bookName << endl;
    cout << "\t\t\tBook's Author: " << authorName << endl;
    cout << "\t\t\tBook's ID: " << bookId << endl;
    cout << "\t\t\tBook's Publication: " << publication << endl;
    
    if(i == 2){
        cout << "\t\t\tBook's Price: " << price << endl;
        cout << "\t\t\tBook's Quantity: " << quantity << endl;
    }
}

void Library::bookList(int i){
    int b, r = 0;
    system("cls");
    b = branch(i);
    system("cls");

    ifstream intf("Booksdata.txt", ios::binary);
    if(!intf){
        cout << "\n\t\t\tFile not Found!\n\t\t\t";
        system("PAUSE");
    }
    else{
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~ BOOK LIST ~~~~~~~~~~~~~~~~~~~~\n";
        intf.read((char*) this, sizeof(*this));

        while(!intf.eof()){
            if(b == B){
                if(quantity == 0 && i == 1){

                }
                else{
                    r++;
                    cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~ " << r << " ~~~~~~~~~~~~~~~~~~~~\n";
                    showBook(i);
                }
            }
            intf.read((char*) this, sizeof(*this));
        }
    }
    cout << "\n\t\t\t";
    system("PAUSE");
    system("cls");
    if(i == 1)
        student();
    else
        Admin();
}

void Library::modifyBook(){
    char ch, str[100];
    int i = 0, b, cnt = 0;
    system("cls");
    cout << "\t\t\tMENU\n";
    cout << "\n\t\t\t1. Modify Existing Book\n\t\t\t2. Add new Book\n\t\t\t3. Delete a Book\n\t\t\t4. Go to Admin Menu\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> i;

    if(i == 0){
        system("cls");
        b = branch(2);
        system("cls");

        ifstream intf1("Booksdata.txt", ios::binary);
        if(!intf1){
            cout << "\n\t\t\tFile not Found!\n\t\t\t";
            system("PAUSE");
            system("cls");
            Admin();
        }
        intf1.close();
        system("cls");
        cout << "\n\t\t\tMENU\n";
        cout << "\n\t\t\t1. Search Book Name\n\t\t\t2. Search Book ID\n";
        cout << "\n\t\t\tEnter your choice: ";
        cin >> i;
        fflush(stdin);

        if(i == 1){
            system("cls");
            cout << "\n\t\t\tEnter Book's Name: ";
            cin.getline(str, 100);
            system("cls");
            fstream intf("Booksdata.txt", ios::in|ios::out|ios::ate|ios::binary);
            intf.seekg(0);
            intf.read((char*)this, sizeof(*this));
            
            while(!intf.eof()){
                for(i = 0; b == B && bookName[i] != '\0' && str[i] != '\0' && (str[i] == bookName[i] || str[i] == bookName[i] + 32); i++);
                if(bookName[i] == '\0' && str[i] == '\0'){
                    cnt++;
                    newBook();
                    intf.seekp(intf.tellp() - sizeof(*this));
                    intf.write((char*) this, sizeof(*this));
                    break;
                }
                intf.read((char*) this, sizeof(*this));
            }
            intf.close();
        }
        else if(i == 2){
            cout << "\n\t\t\tEnter Book's ID: ";
            cin.getline(str, 100);
            system("cls");

            fstream intf("Booksdata.txt", ios::in|ios::out|ios::ate|ios::binary);
            intf.seekg(0);
            intf.read((char*) this, sizeof(*this));

            while(!intf.eof()){
                for(i = 0; b == B && bookId[i] != '\0' && str[i] != '\0' && bookId[i] == str[i]; i++);
                if(bookId[i] == '\0' && str[i] == '\0'){
                    cnt++;
                    newBook();
                    intf.seekp(intf.tellp() - sizeof(*this));
                    intf.write((char*) this, sizeof(*this));
                    break;
                }
                intf.read((char*) this, sizeof(*this));
            }
            intf.close();
        }
        else{
            cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
            system("PAUSE");
            system("cls");
            modifyBook();
        }
        
        if(cnt == 0){
            cout << "\n\t\t\tBook not Found!\n\t\t\t";
            system("PAUSE");
            system("cls");
            modifyBook();
        }
        else{
            cout << "\n\t\t\tUpdated Successfully!\n\t\t\t";
            system("PAUSE");
        }
    }
    else if(i == 2){
        system("cls");
        B = branch(2);
        newBook();
        ofstream outf("Booksdata.txt", ios::app|ios::binary);
        outf.write((char*) this, sizeof(*this));
        outf.close();
        cout << "\n\t\t\tBook Added Successfully!\n\t\t\t";
        system("PAUSE");
    }
    else if(i == 3){
        system("cls");
        b = branch(2);
        ifstream intf1("Booksdata.txt", ios::binary);
        
        if(!intf1){
            cout << "\n\t\t\tFile not Found\n\t\t\t";
            system("PAUSE");
            intf1.close();
            system("cls");
            Admin();
        }

        intf1.close();
        system("cls");
        cout << "\n\t\t\tMENU\n";
        cout << "\n\t\t\t1. Delete by Bookname\n\t\t\t2. Delete by Book ID\n";
        cout << "\n\t\t\tEnter your choice: ";
        cin >> i;
        fflush(stdin);

        if(i == 1){
            system("cls");
            cout << "\n\t\t\tEnter Book's Name: ";
            cin.getline(str, 100);
            ofstream outf("temp.txt", ios::app|ios::binary);
            ifstream intf("Booksdata.txt", ios::binary);
            intf.read((char*) this, sizeof(*this));

            while(!intf.eof()){
                for(i = 0; b == B && bookName[i] != '\0' && str[i] != '\0' && bookName[i] == str[i]; i++);
                if(bookName[i] == '\0' && str[i] == '\0'){
                    cnt++;
                    intf.read((char*) this, sizeof(*this));
                }
                else{
                    outf.write((char*) this, sizeof(*this));
                    intf.read((char*) this, sizeof(*this));
                }
            }
            intf.close();
            outf.close();
            remove("Booksdata.txt");
            rename("temp.txt", "Books.data");
        }
        else if(i == 2){
            system("cls");
            cout << "\n\t\t\tEnter Book's ID: ";
            cin.getline(str, 100);
            ofstream outf("temp.txt", ios::app|ios::binary);
            ifstream intf("Booksdata.txt", ios::binary);
            intf.read((char*) this, sizeof(*this));

            while(!intf.eof()){
                for(i = 0; b == B && bookId[i] != '\0' && str[i] != '\0' && bookId[i] == str[i]; i++);
                if(bookId[i] == '\0' && str[i] == '\0'){
                    cnt++;
                    intf.read((char*) this, sizeof(*this));
                }
                else{
                    outf.write((char*) this, sizeof(*this));
                    intf.read((char*) this, sizeof(*this));
                }
            }
            intf.close();
            outf.close();
            remove("Booksdata.txt");
            rename("temp.txt", "Books.data");
        }
        else{
            cout << "\n\t\t\tInvalid Input!\n\t\t\t";
            system("PAUSE");
            system("cls");
            modifyBook();
        }

        if(cnt == 0){
            cout << "\n\t\t\tBook not Found!\n\t\t\t";
            system("PAUSE");
            system("cls");
            modifyBook();
        }
        else{
            cout << "\n\t\t\tBook Deleted!\n\t\t\t";
            system("cls");
        }
    }
    else if(i == 4){
        system("cls");
        Admin();
    }
    else{
        cout << "\n\t\t\tInvalid Input!\n\t\t\t";
        system("PAUSE");
        system("cls");
        Admin();
    }
}

void Library::getBook(int x){
    int i, b, cnt = 0;
    char ch[100];
    system("cls");
    b = branch(x);

    ifstream intf("Booksdata.txt", ios::binary);
    if(!intf){
        cout << "\n\t\t\tFile not Found!\n\t\t\t";
        system("PAUSE");
        system("cls");
        if(x == 1)
            student();
        else
            Admin();
    }
    system("cls");
    cout << "\n\t\t\tMENU\n";
    cout << "\n\t\t\t1. Search by Book's Name\n\t\t\t2. Search by Book's ID\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> i;
    
    fflush(stdin);
    intf.read((char*) this, sizeof(*this));
    if(i == 1){
        cout << "\n\t\t\tEnter Book's Name: ";
        cin.getline(ch, 100);
        system("cls");

        while(!intf.eof()){
            for(i = 0; b == B && quantity != 0 && bookName[i] != '\0' && ch[i] != '\0' && (ch[i] == bookName[i] || ch[i] == bookName[i] + 32); i++);
            if(bookName[i] == '\0' && ch[i] == '\0'){
                cout << "\n\t\t\tBook Found!\n";
                showBook(x);
                cnt++;
                break;
            }
            intf.read((char*) this, sizeof(*this));
        }
    }
    else if(i == 2){
        cout << "\n\t\t\tEnter Book's ID: ";
        cin.getline(ch, 100);
        system("cls");

        while(!intf.eof()){
            for(i = 0; b == B && quantity != 0 && bookId[i] != '\0' && ch[i] != '\0' && ch[i] == bookId[i]; i++);
            if(bookId[i] == '\0' && ch[i] == '\0'){
                cout << "\n\t\t\tBook Found!\n";
                showBook(x);
                cnt++;
                break;
            }
            intf.read((char*) this, sizeof(*this));
        }
    }
    else{
        cnt++;
        cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
        system("PAUSE");
        system("cls");
        getBook(x);
    }
    intf.close();
    if(cnt == 0)
        cout << "\n\t\t\tBook not Available!\n";
    cout << "\n\t\t\t";
    system("PAUSE");
    system("cls");
    if(x == 1)
        student();
    else
        Admin();
}

int Library::branch(int x){
    int i;
    cout << "\n\t\t\tMENU\n";
    cout << "\n\t\t\t1. Bit\n\t\t\t2. Elctrical\n\t\t\t3. Electronics\n\t\t\t4. Civil\n\t\t\t5. Mechanics\n\t\t\t6. 1st Year\n\t\t\t7. Back to Main Menu\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> i;

    if(i < 7 && i > 0)
        return i;
    else if(i == 7){
        system("cls");
        if(x == 1)
            student();
        else
            Admin();
    }
    else{
        cout << "\n\t\t\tInvalid Choice!\n\t\t\t";
        system("PAUSE");
        system("cls");
        branch(x);
    }
}

void Library::issueBook(){
    char s[50], str[20];
    int b, i, j, d, m, y, dd, mm, yy, cnt = 0;
    system("cls");
    cout << "\n\t\t\tMENU\n";
    cout << "\n\t\t\t1. Issue Book\n\t\t\t2. View Issued Books\n\t\t\t3. Search Student who Issued Book\n\t\t\t4. Re-Issue Book\n\t\t\t6. Back to Main Menu\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> i;

    fflush(stdin);
    if(i == 1){
        system("cls");
        b = branch(2);
        system("cls");
        fflush(stdin);
        cout << "\n\t\t\tEnter Book's Name: ";
        cin.getline(bookName, 100);
        cout << "\n\t\t\tEnter Book's ID: ";
        cin.getline(bookId, 20);
        der(bookId, b, 1);
        cout << "\n\t\t\tEnter Student's Name: ";
        cin.getline(authorName, 100);
        cout << "\n\t\t\tEnter Student's ID: ";
        cin.getline(publication, 20);
        cout << "\n\t\t\tEnter Date: ";
        cin >> quantity >> B >> price;

        ofstream outf("student.txt", ios::binary|ios::app);
        outf.write((char*) this, sizeof(*this));
        outf.close();
        cout << "\n\t\t\tBook Issued!\n";
    }
    else if(i == 2){
        ifstream intf("student.txt", ios::binary);
        system("cls");
        cout << "\n\t\t\tIssued Books:\n";
        intf.read((char*) this, sizeof(*this));

        i = 0;
        while(!intf.eof()){
            i++;
            cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~ " << i << ". ~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\n\t\t\tStudent's Name: " << authorName << "\n\t\t\tStudent's ID: " << bookId << "\n\t\t\tBook's Name: " << bookName << "\n\t\t\tBook's ID: " << publication << "\n\t\t\tDate: " << quantity << "/" << B << "/" << price << endl;
            intf.read((char*) this, sizeof(*this));
        }
        intf.close();
    }
    else if(i == 3){
        system("cls");
        fflush(stdin);
        cout << "\n\t\t\tEnter Student's Name: ";
        cin.getline(s, 50);
        cout << "\n\t\t\tEnter Student's ID: ";
        cin.getline(str, 50);
        system("cls");

        ifstream intf("student.txt", ios::binary);
        intf.read((char*) this, sizeof(*this));
        cnt++;

        while(!intf.eof()){
            for(i = 0; publication[i] != '\0' && str[i] != '\0' && publication[i] == str[i]; i++);
            if(publication[i] == '\0' && str[i] == '\0'){
                cnt++;
                if(cnt == 1){
                    cout << "\n\t\t\tDETAILS: \n";
                    cout << "\n\t\t\tStudent's Name: " << authorName;
                    cout << "\n\t\t\tStudent's ID: " << publication;
                }

                cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~ " << cnt << " . Book Details ~~~~~~~~~~~~~~~~~~~~\n";
                cout << "\n\t\t\tBook's Name: " << bookName;
                cout << "\n\t\t\tBook's ID: " << publication;
                cout << "\n\t\t\tDate: " << quantity << "/" << B << "/" << price << endl;
            }
            intf.read((char*) this, sizeof(*this));
        }
        intf.close();
        if(cnt == 0)
            cout << "\n\t\t\tNo Record Found\n";
    }
    else if(i == 4){
        system("cls");
        fflush(stdin);
        cout << "\n\t\t\tEnter Student's ID: ";
        cin.getline(s, 50);
        cout << "\n\t\t\tEnter Book's ID: ";
        cin.getline(str, 50);

        fstream intf("student.txt", ios::in|ios::out|ios::ate|ios::binary);
        intf.seekg(0);
        intf.read((char*) this, sizeof(*this));
        while(!intf.eof()){
            for(i = 0; publication[i] != '\0' && str[i] != '\0' && publication[i] == str[i]; i++);
            for(j = 0; bookId[j] != '\0' && s[j] != '\0' && bookId[j] == s[j]; j++);

            if(publication[i] == '\0' && bookId[j] == '\0' && s[j] == '\0' && str[i] == '\0'){
                d = quantity;
                m = B;
                y = price;
                cout << "\n\t\t\tEnter New Date: ";
                cin >> quantity >> B >> price;
                fine(d, m, y, quantity, B, price);
                intf.seekp(intf.tellp() - sizeof(*this));
                intf.write((char*) this, sizeof(*this));
                cout << "\n\t\t\tBook Re-Issued!\n";
                break;
            }
            intf.read((char*) this, sizeof(*this));
        }
        intf.close();
    }
    else if(i == 5){
        system("cls");
        b = branch(2);
        system("cls");
        fflush(stdin);
        
        cout << "\n\t\t\tEnter Book ID: ";
        cin.getline(str, 50);
        der(str, b, 2);
        cout << "\n\t\t\tEnter Student's ID: ";
        cin.getline(s, 50);
        cout << "Enter Present Date: ";
        cin >> d >> m >> y;

        ofstream outf("temp.txt", ios::app|ios::binary);
        ifstream intf("student.txt", ios::binary);
        intf.read((char*) this, sizeof(*this));

        while(!intf.eof()){
            for(i = 0; publication[i] != '\0' && str[i] != '\0' && publication[i] == str[i]; i++);
            for(j = 0; bookId[j] != '\0' && s[j] != '\0' && s[j] == bookId[j]; j++);
            if(publication[i] == '\0' && str[i] == '\0' && bookId[j] == '\0' && s[j] == '\0' && cnt == 0){
                cnt++;
                intf.read((char*) this, sizeof(*this));
                fine(quantity, B, price, d, m, y);
                cout << "\n\t\t\tBook Returned!\n";
            }
            else{
                outf.write((char*) this, sizeof(*this));
                intf.read((char*) this, sizeof(*this));
            }
        }
        intf.close();
        outf.close();
        cout << "\t\t\t";
        system("PAUSE");
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }
    else if(i == 6){
        system("cls");
        Admin();
    }
    else{
        cout << "\n\t\t\tInvalid Input!\n\t\t\t";
        system("PAUSE");
        system("cls");
        Admin();
    }
}

void::Library::der(char s[], int b, int x){
    int i, cnt = 0;
    fstream intf("Booksdata.txt", ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*) this, sizeof(*this));

    while(!intf.eof()){
        for(i = 0; b == B && publication[i] != '\0' && s[i] != '\0' && s[i] == publication[i]; i++);
        if(publication[i] == '\0' && s[i] == '\0'){
            cnt++;
            if(x == 1)
                quantity--;
            else
                quantity++;
            intf.seekp(intf.tellp() - sizeof(*this));
            intf.write((char*) this, sizeof(*this));
            break;
        }
        intf.read((char*) this, sizeof(*this));
    }
    if(cnt == 0){
        cout << "\n\t\t\tBook Not Found!\n\t\t\t";
        system("PAUSE");
        system("cls");
        issueBook();
    }
    intf.close();
}

void Library::fine(int d, int m, int y, int dd, int mm, int yy){
    long int n1, n2;
    int yrs, l, i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    n1 = y * 365 + d;
    for(i = 0; i < m-1; i++)
        n1 += monthDays[i];
    yrs = y;
    if(m <= 2)
        yrs--;
    l = yrs / 4 - yrs / 100 + yrs / 400;
    n1 += l;
    n2 = yy * 365 + dd;
    for(i = 0; i < mm-1; i++)
        n2 += monthDays[i];
    yrs = yy;
    if(m <= 2)
        yrs--;
    l = yrs / 4 - yrs / 100 - yrs / 400;
    n2 += l;
    n1 = n2 - n1;
    n2 = n1 - 15;
    if(n2 > 0)
        cout << "\n\t\t\tTotal fine is: " << n2 << endl;
}

int main(){
    Library ob;
    ob.start();
    return 0;
}