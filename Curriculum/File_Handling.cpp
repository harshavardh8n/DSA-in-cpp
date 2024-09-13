#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct student
{
    int roll_no;
    char name[10];
    char div[10];
    char add[10];
};

class records
{
public:
    student rec;
    void create();
    void display();
    void search();
    void Delete();
    void insert();
    void modify();
};

void records::create()
{
    cout << "\n=============================================================================================\n";

    char ans;
    ofstream fout;

    fout.open("studrec.txt", ios::out | ios::binary);

    if (!fout.is_open())
    {
        cout << " --> File can not be opened ";
        exit(0);
    }

    do
    {
        cout << "\n >> Enter Roll No Of Student   ::  ";
        cin >> rec.roll_no;

        cout << "\n >> Enter Name Of Student      ::  ";
        cin >> rec.name;

        cout << "\n >> Enter Division Of Student  ::  ";
        cin >> rec.div;

        cout << "\n >> Enter Address Of Student   ::  ";
        cin >> rec.add;
        fout.write((char *)&rec, sizeof(rec));

        cout << "\n >> Do You Want To Add More Records 'y' For Yes :: ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    cout << "\n=============================================================================================\n";
    
    fout.close();
}

void records::display()
{
    cout << "\n=============================================================================================\n";

    ifstream fin;
    fin.open("studrec.txt", ios::in | ios::binary);

    if (!fin) // file not found
    {
        cout << "\n --> File Not Found ! \n Check Local Directory, Or Try Creating The File First From Menu Option \n ";
        return;
    }

    else
    {
        fin.read((char *)&rec, sizeof(rec)); // read first record
        cout << " \n Roll No \t\t Name \t\t Division \t\t Address ";

        while (!fin.eof()) // read file till  end of file
        {
            cout << "\n   "
                 << rec.roll_no << " \t\t  " << rec.name << " \t\t  " << rec.div << " \t\t  " << rec.add;
            fin.read((char *)&rec, sizeof(rec));
            // read next record
        }
    }

    cout << "\n\n=============================================================================================\n";

    fin.close();
}

void records::search()
{
    cout << "\n=============================================================================================\n";

    int r, i = 0;
    ifstream fin;

    fin.open("studrec.txt", ios::in | ios::binary); // open file in reading mode
    bool flag = false;

    cout << "\n >> Enter Roll No :: ";
    cin >> r;

    if (!fin)
    {
        cout << " --> Error ! ";
    }
    else
    {
        // read first record
        while (!fin.eof()) // search till end of file
        {
            fin.read((char *)&rec, sizeof(rec));

            if (rec.roll_no == r) // if key is equal to correct roll number
            {
                flag = true; // set flag
                cout << "\n --> Record Found ... \n";
                cout << " \n \t Roll \t\t\t Name \t\t\t Div \t\t\t Address ";
                cout << "\n"
                     << rec.roll_no << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
                break;
            }
        }
    }

    if (flag == 0) // if roll no. is not found
    {
        cout << "\n --> Record Not Found ! \n";
    }

    cout << "\n=============================================================================================\n";

    fin.close();
}

void records::Delete()
{
    cout << "\n=============================================================================================\n";

    cout << "\n >> Enter Roll No of The Student :: ";
    int rno, flag = 0;
    cin >> rno;

    fstream fin("studrec.txt", ios::in | ios::binary); // open file in read mode
    fstream fout("temp.txt", ios::out | ios::binary);  // create new temp file for temporary data storage

    if (!fin)
    {
        cout << "\n --> File Not Found !\n Check Local Directory, Or Try Creating The File First From Menu Option \n ";
        return;
    }

    else
    {
        fin.read((char *)&rec, sizeof(rec));

        while (!fin.eof())
        {
            if (rec.roll_no != rno) // if current record is not that to be updated
            {
                fout.write((char *)&rec, sizeof(rec)); // write to the temp file
            }

            else // if current record is that ts to be updated
            {
                cout << "\n --> Record Found and Deleted! \n";
                flag = 1;
            }

            fin.read((char *)&rec, sizeof(rec)); // read next record from the
        }

        fin.close();
        fout.close();
        remove("studrec.txt");
        rename("temp.txt", "studrec.txt");

        if (flag == 0) // flag remained same then
        {
            cout << "\n --> Record With Roll No " << rno << " Is Not Found In The File 'StudentData.dat' \n";
        }
    }

    cout << "\n=============================================================================================\n";

}

void records::insert()
{
    cout << "\n=============================================================================================\n";

    cout << "\n >>> Fill Student Details :- \n \n ";

    cin.ignore();

    fstream fout("studrec.txt", ios::app | ios::binary); // open file in append mode
    fstream fin("studrec.txt", ios::in | ios::binary);   // open file in read with different pointer
    student rec1;

    fin.read((char *)&rec1, sizeof(rec1));

    int flag = 1;

    while (!fin.eof()) // read file till end for roll no. validity check
    {
        if (rec1.roll_no == rec.roll_no)
        {
            cout << "\n Student With Roll No. " << rec.roll_no << " already exist !\n";
            flag = 0;
            break;
        }

        else
        {
            fin.read((char *)&rec1, sizeof(rec1)); // read next record
        }
    }

    if (flag == 1) // if roll no. is unique then only write to the file
    {
        cout << "\n >> Name     ::  ";
        cin >> rec.name;
        cout << "\n >> Address  ::  ";
        cin >> rec.add;
        cout << "\n >> Roll No  ::  ";
        cin >> rec.roll_no;
        cout << "\n Division    ::  ";
        cin >> rec.div;

        fout.write((char *)&rec, sizeof(rec)); // write to the file
        cout << "\n --> Record Added Successfully To The File !\n";
    }
    cout << "\n=============================================================================================\n";

    fin.close();
}

void records::modify()
{
    cout << "\n=============================================================================================\n";

    cout << "\n >> Enter Roll No Of The Student  ::  ";
    int rno, flag = 0;
    cin >> rno;

    ifstream fin;
    fin.open("studrec.txt", ios::in | ios::binary); // open file in read mode
    ofstream fout;
    fout.open("temp.txt", ios::out | ios::binary); // create new temp file for temporary data storage

    if (!fin)
    {
        cout << " \n --> File Not Found !\n Check Local Directory, Or Try Creating The File First From Menu Option \n ";
        return;
    }
    else
    {
        fin.read((char *)&rec, sizeof(rec));
        while (!fin.eof())
        {
            if (rec.roll_no != rno) // if current record is not that to be updated
            {
                fout.write((char *)&rec, sizeof(rec)); // write to the temp file
            }
            else // if current record is that ts to be updated
            {
                cout << "\n --> Record Found ! \n";
                flag = 1;
                cout << " \n >>> Fill student details :- \n ";
                cout << "\n >> Name      ::  ";
                cin >> rec.name;
                cout << "\n >> Roll No   ::  " << rno;
                rec.roll_no = rno;
                cin.ignore();
                cout << "\n >> Address   ::  ";
                cin >> rec.add;
                cout << "\n >> Division  ::  ";
                cin >> rec.div;
                fout.write((char *)&rec, sizeof(rec));                          // write to the file
                cout << "\n --> Record Updated Successfully To The File ! \n "; // write updated record to the temp file
            }
            fin.read((char *)&rec, sizeof(rec)); // read next record from the
        }
        fin.close();
        fout.close();

        remove("studrec.txt");
        rename("temp.txt", "studrec.txt");

        if (flag == 0) // flag remained same then
        {
            cout << "\n --> Record With Roll No " << rno << " Is Not Found In The File 'studrec.txt' \n";
        }
    }
    cout << "\n=============================================================================================\n";

}

int main()
{
    records obj;
    int ch, key;
    char ans;

    cout << "\n \t ===============================";
    cout << "\n \t ||   FILE HANDLING PROGRAM   ||";
    cout << "\n \t =============================== \n ";

    do
    {
        cout << "\n=============================================================================================\n";
        cout << "\n >>> Student Information :- " << endl;
        cout << "\n 1] Create \t 2] Display \n\n 3] Delete \t 4] Search \n\n 5] insert \t 6] modify \n\n 7] Exit ";
        cout << "\n\n >> Enter Your Choice :: ";
        cin >> ch;

        cout << "\n=============================================================================================\n";

        switch (ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.Delete();
            break;
        case 4:
            obj.search();
            break;
        case 5:
            obj.insert();
            break;
        case 6:
            obj.modify();
            break;
        }
    } while (ch != 7);

    cout << "\n --> Program Exited Successfully \n ";
    cout << "\n=============================================================================================\n";

    return 1;
}
