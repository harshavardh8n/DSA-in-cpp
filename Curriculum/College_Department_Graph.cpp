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
    string source[20], destination[20], department_name[20];

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

    int i, j, s, d, w, edg, flag1 = 0, flag2 = 0;

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

    for (i = 0; i < nodes ; i++)
    {
        cout << "\n >> Enter Name of Department No " << (i+1) << "    :: ";
        cin >> department_name[i];
    }

    cout << "\n=============================================================================================\n";

    cout << " >>> Enter Info of College Campus :- " << endl;

    for (int i = 0; i < edg; i++)
    {
        cout << "\n=============================================================================================\n";

        cout << "\n >>> Path " << (i + 1) << " :- \n\n";

        cout << " >> Enter Source       :: "; // Enter vertex as 1,2,3,..
        cin >> source[i];

        for(int k = 0; k<nodes ; k++)
        {
            if( department_name[k] == source[i])
            {
                s = (k+1);
                flag1 = 1;
                break;        
            }
        }

        if(flag1 == 0)
        {
            cout << "\n --> This Department is Not Available in the College " << endl;  
            break;
        }

        cout << " >> Enter Destination Department No " << (i + 1) << "     ::  ";
        cin >> destination[i];

        for(int k = 0; k<nodes ; k++)
        {
            if( department_name[k] == destination[i])
            {
                d = (k+1);
                flag2 = 1;
                break;        
            }
        }

        if(flag2 == 0)
        {
            cout << "\n --> This Department is Not Available in the College " << endl;  
            break;
        }

        cout << " >> Enter Distance     :: ";
        cin >> w;

        graph[d - 1][s - 1] = w;
        graph[s - 1][d - 1] = w;
    }
    cout << "\n=============================================================================================\n";
}

void Prims ::Prims_Algo()
{
    cout << "\n=============================================================================================\n";

    int visited[row], i, j, ne, min, cost = 0, x, y;

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
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        visited[y] = true;
        cout << "\n >>--> " << department_name[x] << " --> " << department_name[y] << " :: " << min;
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
