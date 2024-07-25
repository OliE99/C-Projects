#include <fstream>
#include <string.h>
#include <bits/stdc++.h>
#include <string>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

void adminFunction() {
    system("cls");
    cout << "\n\n\t\t\t\t\t | Logged In as Admin |\n";
    cout << "\n\n\t\t\t\t\t 1. Add Students Details";
    cout << "\n\n\t\t\t\t\t 2. Delete Students";
    // cout << "\n\n\t\t\t\t\t 3. Update Records";
    cout << "\n\n\t\t\t\t\t 4. View Table";
    cout << "\n\n\t\t\t\t\t 5. Main Menu";
    cout << "\n\n\t\t\t\t\t 6. Exit";

    int option;
    cout << "\n\n\t\t\t\t\t Enter choice : ";
    do {
        cin >> option;
        {
            switch (option) {
                
                case 1:
                    addData();
                    break;
                
                case 2:
                    deleteData();
                    break;

                case 3:
                    cout << "Option is currently unavailable"; //updateData();
                    break;

                case 4:
                    viewData();
                    break;
                
                case 5:
                    mainMenu();
                    break;
                
                case 6:
                    system("cls");
                    cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";
                
                for (int i = 0; i < 4; i++) {

                    Sleep(1000);
                    cout << ".";

                }

                exit(0);
                break;

                default:
                   system("cls");
                   cout << "\n\n\t\t\t\t\t Logged In as Admin";
                   cout << "\n\n\t\t\t\t\t 1. Add Students Record";
                   cout << "\n\n\t\t\t\t\t 2. Delete Record";
                   //  cout << "\n\n\t\t\t\t\t 3. update Record";
                   cout << "\n\n\t\t\t\t\t 4. View Table ";
                   cout << "\n\n\t\t\t\t\t 5. Main Menu ";
                   cout << "\n\n\t\t\t\t\t 6. Exit";

                   cout << "\n\n\t\t\t\t\t Invalid input!";

                   cout << "\n\n\t\t\t\t\t Enter choice : ";
            }
        }
    } while (option != '6');
}

void mainMenu() {
    system("cls");

    cout << "\n\n\n\n\t\t\t\t\t Login As : ";
    cout << "\n\n\n\n\t\t\t\t\t 1. Admin";
    cout << "\n\n\n\n\t\t\t\t\t 2. Student";
    cout << "\n\n\n\n\t\t\t\t\t 3. Exit";
    cout << "\n\n\n\n\t\t\t\t\t Enter your choice : ";

    int choice;
    cin >> choice;
    switch (choice) {
        
        case 1:
            adminVerification();
            break;
        
        case 2:
            system("cls");

            cout << "Welcome Student";
            studentFunction();
            break;
        
        case 3: 
            system("cls");
            cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";

            for (int i = 0; i < 4; i++) {

                Sleep(1000);
                cout << ".";

            }

            exit(0);
            break;
        
        default:
            cout << "Invalid input";

    }

    system("pause");

}

// All admin functions below

void deleteData() {
    system("cls");

    // Open file pointers
    fstream fin, fout;

    // Open the existing file
    fin.open("data.csv", ios::in);

    // Create a new file to store non-deleted data
    fout.open("datanew.csv", ios::out);

    int rollnum, roll1, marks, cout = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;

    // Get roll no. 
    // to decide the data to be deleted 
    cout << "Enter roll number "
         << "of the record to be deleted: ";
    cin >> rollnum;

    // Check if record exists
    // If it exists, leave it and
    // add all other data to a new file 
    while (!fin.eof()) {

        row.clear();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        int row_size = row.size();
        roll1 = stoi(row[0]);

        // writing all records,
        // except the record to be deleted,
        // into the new file 'reportcardnew.csv'
        // using fout pointer
        if (roll1 != rollnum) {
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record has been deleted\n";
    else 
        cout << "Record not found\n";
    
    // Close pointers
    fin.close();
    fout.close();

    // removing existing files
    remove ("data.csv");

    Sleep(2000);

    adminFunction();
}

void addData() {
    
}