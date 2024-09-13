#include <iostream>
using namespace std;
#define row 10
#define col 10
#define true 1
#define false 0
#define infi 5000 // infi for infinity

class Prims
{
    int graph[row][col], nodes;
    string name1[20], name2[20];

public:
    Prims();

    void Create_Graph();
    void Prims_Algo();
};

Prims ::Prims()
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            graph[i][j] = 0;
}

void Prims ::Create_Graph()
{
    cout << "\n=============================================================================================\n";

    int i, j, s, d, w, edg, flag1 = 0;

    cout << "\n >> Enter Total No. of Departments in College  :: ";
    cin >> nodes;

    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            graph[i][j] = infi;
        }
    }
    cout << " >> Enter Total No. of Paths                   :: ";
    cin >> edg;
    cout << endl;

    cout << " >>> Enter The Names of College Departments :- \n\n";

    for (i = 0; i < nodes; i++)
    {
        cout << " >> Name of Department " << (i + 1) << " :: ";
        cin >> name1[i];
        cout << endl;
    }
    cout << "\n=============================================================================================\n";

    cout << "\n=============================================================================================\n";
    cout << " >>> Enter Info of College Campus :- " << endl;

    for (int i = 0; i < edg; i++)
    {
        cout << "\n >>> Path " << (i + 1) << " :- \n\n";

        cout << " >> Enter Source       :: "; // Enter vertex as 1,2,3,..
        cin >> name2[i];

        for (int j = 0; j < nodes; j++)
        {
            if (name2[i] == name1[j])
            {
                s = (i + 1);
                flag1 = 1;
            }
        }

        if (flag1 == 0)
        {
            cout << "\n --> This Department is Not Available in the College " << endl; 
            cout<<"\n=============================================================================================\n";

            break;
        }

        cout << " >> Enter Destination  :: "; // Enter vertex as 1,2,3,.
        cin >> name2[i + 1];

        int flag2 = 0;

        for (int j = 0; j < nodes; j++)
        {
            if (name2[i + 1] == name1[j])
            {
                d = (i + 2);
                flag2 = 1;
            }
        }

        if (flag2 == 0)
        {
            cout << "\n --> This Department is Not Available in the College " << endl;  
            cout<<"\n=============================================================================================\n";

            break;
        }

        cout << " >> Enter Distance     :: ";
        cin >> w;

        graph[d - 1][s - 1] = w;
        graph[s - 1][d - 1] = w;
    }
}

void Prims ::Prims_Algo()
{
    cout << "\n=============================================================================================\n";

    int visited[row], i, j, ne; // ne for no. of edges
    int min, cost = 0, z;
    string x, y;

    for (i = 0; i < nodes; i++)
        visited[i] = false;
    visited[0] = true;
    ne = 0;

    while (ne < nodes - 1)
    {
        min = infi;

        for (i = 0; i < nodes; i++)
        {
            if (visited[i] == true)
            {
                for (j = 0; j < nodes; j++)
                {
                    if (visited[j] == false)
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = name2[i];
                            y = name2[j];
                            z = j;
                        }
                    }
                }
            }
        }

        visited[z] = true;
        cout << "\n >>--> " << x << " --> " << y << " :: " << min;
        cost = cost + min;
        ne++;
    }
    cout << "\n\n >-> Minimum Distance Between Departments = " << cost;
    cout << "\n=============================================================================================\n\n";
}

int main()
{
    cout << "\n \t\t\t =============================== \n";
    cout << " \t\t\t ||  Graph Of College Campus  || \n";
    cout << " \t\t\t =============================== \n\n";

    cout << "\n=============================================================================================\n\n";

    Prims MST;
    int choice;

    while(1)
    {

        cout<<" Graph Menu :- \n \n 1] New College \n 2] Exit Program \n\n >> Enter The Operation To be Performed :: ";
        cin>>choice;
        cout<<"\n=============================================================================================\n";
    
        if(choice == 2)
        {
            cout<<"\n --> Program Exited Successfully \n ";
            break;
        }

        if(choice == 1)
        {
            MST.Create_Graph();
            MST.Prims_Algo();
            break;
        }   
    }

    cout << "\n=============================================================================================\n";

    return 0;
}
