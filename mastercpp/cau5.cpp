#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;





struct Team {
    char name[101];
    char members[3][20];
    int solved;
    int penalty;
};



int readFile(Team a[], const char* filename) {
    int n=0;
    char line[100];

    ifstream fin("standing.txt");


    while (fin.getline(line,100)) {
        strcpy(a[n].name , strtok(line , "|"));
        strcpy(a[n].members[0] , strtok(NULL, ","));
        strcpy(a[n].members[1] , strtok(NULL, ","));
        strcpy(a[n].members[2] , strtok(NULL, "|"));
        a[n].solved = atoi(strtok(NULL, "|"));
        a[n].penalty = atoi( strtok(NULL, "|"));
        n++;

    }

    fin.close();
    return n;

}


int main () {

    Team a[100];
    int n;

    n=readFile(a , "standing.txt");


    for (int i=0;i<n-1;i++) {
        for (int j = i+1;j<n;j++) {
            if (a[i].solved < a[j].solved) {
                swap(a[j] , a[i]);
            }
            if (a[i].solved == a[j].solved) {
                if (a[i].penalty < a[j].penalty) {
                    swap(a[j] , a[i]);
                }
            }

        }
    }
    int x=0; 
    int index;
    for (int i = 0;i<n-1;i++) {
        if (a[i].solved != a[i+1].solved) {
            if (i<=30) {
                 x=a[i].solved;
                 index=i;
            }
        }
    }

    cout << x << endl;


    ofstream fout("southern.txt.");

    for (int i= 0;i<index;i++) {
        fout << a[i].name << "|" << a[i].solved << "|" << a[i].penalty << endl;
    }




    fout.close();














    return 0;
}