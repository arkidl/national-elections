#include <stdio.h>
#include <stdlib.h>

/**

Input/s:
•	n, k
•	the data for n voters (name, surname, PIN)
•	m
•	the data for m voters (name, surname, PIN)

output/s:
•	the info for the kth person in the merged and sorted list

**/

struct Voter
{
    char name[15], surname[15];
    int PIN;
};

void getData(struct Voter lstVoters[], int n)
{
    for(int i=0; i<n; i++)
        scanf("%s%s%d", lstVoters[i].name, lstVoters[i].surname, &lstVoters[i].PIN);
    return;
}
void printData(struct Voter lstVoters[], int n)
{
    for(int i=0; i<n; i++)
        printf("%s %s %d\n", lstVoters[i].name, lstVoters[i].surname, lstVoters[i].PIN);
    return;
}
void merge(struct Voter list1[], int n, struct Voter list2[], int m, struct Voter fullList[])
{
    for(int i=0; i<(m+n); i++)
    {
        if(i<n)
            fullList[i] = list1[i];
        else
            fullList[i] = list2[i-n];
    }
    return;
}
void sortStruct(struct Voter lst[], int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i; j<n; j++)
            if(lst[i].PIN>lst[j].PIN)
            {
                struct Voter temp=lst[i];
                lst[i]=lst[j];
                lst[j]= temp;
            }
    return;
}
void printElement(struct Voter lst[], int k)
{
    printf("%s %s %d", lst[k].name, lst[k].surname, lst[k].PIN);
    return;
}
int main()
{
    int n, k, m;
    scanf("%d%d", &n, &k);
    struct Voter list1[5000], list2[5000], fullList[10000];
    getData(list1, n);
    //printData(list1, n);
    scanf("%d", &m);
    getData(list2, m);
    //printData(list2, m);
    merge(list1, n, list2, m, fullList);
    //printData(fullList, n+m);
    sortStruct(fullList, n+m);
    //printData(fullList, n+m);
    printElement(fullList, k-1);

    return 0;
}
