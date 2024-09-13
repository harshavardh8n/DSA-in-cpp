#include <iostream>
using namespace std;

struct table
{
    // int ver;
    int dist;
    int pver;
};

class G
{
    int v, e, visit[20], graph[20][20];
    string source[20], destination[20], landmark_name[20];
    struct table T[20];

public:
    void Init();
    void read_G();
    void DIJK();
};

void G::Init()
{
    cout << "\n=============================================================================================\n";

    int i, j;
    cout << " \n >>> Enter the City Info :- " << endl;
    cout << " \n >> Enter No Of Landmarks in Cities    ::  ";
    cin >> v;
    cout << " \n >> Enter Total No of Paths            ::  ";
    cin >> e;

    cout << "\n >>> Enter The Names of Landmarks in City  :- " << endl;

    for (i = 0; i < v; i++)
    {
        cout << "\n >> Enter Name of Landmark No " << (i+1) << "    :: ";
        cin >> landmark_name[i];
    }

    for (i = 0; i < v; i++)
    {
        visit[i] = 0;
    }

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            graph[i][j] = 9999;
        }
    }

    for (i = 0; i < v; i++)
    {
        T[i].dist = 9999;
        T[i].pver = 0;
    }
    cout << "\n=============================================================================================\n";
}

void G::read_G()
{
    int i, j, s, d, w, flag1 = 0, flag2 = 0;

    for (int i = 0; i < e; i++)
    {
        cout << "\n=============================================================================================\n";

        cout << "\n >>>  Landmark Path " << (i + 1) << " :- " << endl;
        cout << " \n >> Enter Landmark No " << (i + 1) << "                 ::  ";
        cin >> source[i];

        for(int k = 0; k<v ; k++)
        {
            if( landmark_name[k] == source[i])
            {
                s = (k+1);
                flag1 = 1;
                break;        
            }
        }

        if(flag1 == 0)
        {
            cout<<" >>--> Invalid Landmark Entered "<<endl;
            break;
        }

        cout << " >> Enter Destination Landmark No " << (i + 1) << "     ::  ";
        cin >> destination[i];

        for(int k = 0; k<v ; k++)
        {
            if( landmark_name[k] == destination[i])
            {
                d = (k+1);
                flag2 = 1;
                break;        
            }
        }

        if(flag2 == 0)
        {
            cout<<" >>--> Invalid Landmark Entered "<<endl;
            break;
        }

        cout << " >> Enter Distance Between Landmarks " << (i + 1) << "  ::  ";
        cin >> w;

        graph[d - 1][s - 1] = w;
        graph[s - 1][d - 1] = w;

    }
    cout << "\n=============================================================================================\n";
}

void G::DIJK()
{
    int src, i, j, Y, Min, Edge_count = 0;
    string S;
    char ch;
    cout << "\n >> Enter The Source Landmark      ::  ";
    cin >> S;

    for (int k = 0; k < v; k++)
    {
        if(S == landmark_name[k])
        {
            src = (k+1);
            break;
        }
    }

    src--;
    visit[src] = 1;
    T[src].dist = 0;
    T[src].pver = 0;

    do
    {
        Min = 9999;
        for (i = 0; i < v; i++)
        {
            if (src != i && graph[src][i] != Min && visit[i] == 0)
            {
                if (T[i].dist > (T[src].dist + graph[src][i]))
                {
                    T[i].dist = T[src].dist + graph[src][i];
                    T[i].pver = src;
                }
            }
        }

        Min = 9999;
        for (j = 0; j < v; j++)
        {
            if (visit[j] == 0 && T[j].dist < Min)
            {
                Min = T[j].dist;
                src = j;
            }
        }

        visit[src] = 1;
        Edge_count++;

    } while (Edge_count < v);

    cout << endl << " >>> Distance Table :- " << endl << endl;
    cout <<" >>> " << " Vertex " << "  ---  " << " Distance " << "  ---  " << " Previous Vertex " << endl << endl;

    for (i = 0; i < v; i++)
    {
        Y = T[i].pver;
        
        cout <<" -->   "<< S << "         " << T[i].dist << "         " << landmark_name[Y] << endl << endl;
    }

    cout << endl
         << " >>> Source    --    Destination    --    Distance " << endl << endl;

    for (i = 0; i < v; i++)
    {
        cout <<" -> " << S << "    --->    " << landmark_name[i] << "   ::   " << T[i].dist << endl << endl;
    }
}

int main()
{

    cout << "\n \t\t\t ======================= \n";
    cout << " \t\t\t ||  Graph Of A City  || \n";
    cout << " \t\t\t ======================= \n\n";

    cout << "\n=============================================================================================\n\n";

    G shortd;

    int choice;

    while (1)
    {

        cout << " >>> Graph Menu :- \n \n 1] New Landmark \n 2] Exit Program \n\n >> Enter The Operation To be Performed :: ";
        cin >> choice;
        cout << "\n=============================================================================================\n";

        if (choice == 2)
        {
            cout << "\n --> Program Exited Successfully \n ";
            break;
        }

        if (choice == 1)
        {
            shortd.Init();
            shortd.read_G();
            shortd.DIJK();
            break;
        }
    }

    cout << "\n=============================================================================================\n";

    return 0;
}