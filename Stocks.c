#include<stdio.h>
#define SIZE 10
#define DAYS 5
#define forn(i,e) for(int i = 0 ; i<e ;i++)

typedef struct STOCK {
    float Open;
    float Close;
    float High;
    float Low;
    long volume;   
}Stock;

Stock Data[DAYS][SIZE];
double Extra[SIZE];
double ind[SIZE];

char *list[] = {
    "Tata Steel",
    "AXIS Bank",
    "Bajaj Finserv",
    "Hindal Co",
    "HDFC Life",
    "Tata Motors",
    "SBI Bank ",
    "Wipro Ltd. ",
    "Adani Ports",
    "COAL India"
};

void loadData() {
    FILE *csvFile = fopen("stock_data.csv", "r");

    if (csvFile == NULL) {
        printf("Failed to open the CSV file.\n");
    }

    fscanf(csvFile, "%*s,%*s,%*s,%*s,%*s\n");

    forn(j,SIZE)
    {
        forn(i,DAYS)
        {
            fscanf(csvFile, "%f,%f,%f,%f,%ld\n", &Data[i][j].Open, &Data[i][j].High, &Data[i][j].Low, &Data[i][j].Close, &Data[i][j].volume);
        }
    }

    fclose(csvFile);
}

int startDate(int f,int l) {
    int start_date;

    do {
        printf("Enter Start Date: ");
        scanf("%d",&start_date);
    } while(start_date<f || start_date>l);
    start_date -= 16;

    return start_date;
}

int endDate(int f,int l) {
    int end_date;

    do {
        printf("Enter End Date: ");
        scanf("%d",&end_date);
    } while(end_date<f || end_date>l);
    end_date -= 16;

    return end_date;
}

void merge(double A[SIZE][2],int l,int m,int r,int date) {
    int i,j,k;
    i = l;
    j = m+1;
    k = l;

    while(i <= m && j <= r) {
        if(A[i][0] < A[j][0]) {
            Extra[k] = A[i][0];
            ind[k] = A[i][1];
            i++;
        }
        else if(A[i][0] > A[j][0]) {
            Extra[k] = A[j][0];
            ind[k] = A[j][1];
            j++;
        }
        else {
            if(Data[date][i].Close < Data[date][j].Close) {
                Extra[k] = A[i][0];
                ind[k] = A[i][1];
                i++;
            }
            else {
                Extra[k] = A[j][0];
                ind[k] = A[j][1];
                j++;
            }
        }
        k++;
    }

    while(i <= m) {
        Extra[k] = A[i][0];
        ind[k] = A[i][1];
        i++;
        k++;
    }

    while(j <= r) {
        Extra[k] = A[j][0];
        ind[k] = A[j][1];
        j++;
        k++;
    }

    i = l;
    while(i <= r) {
        A[i][0] = Extra[i];
        A[i][1] = ind[i];
        i++;
    }
}

void mergesort(double A[SIZE][2],int l,int r,int date) {
    if(l < r) {
        int m = (l+r)/2;
        mergesort(A,l,m,date);
        mergesort(A,m+1,r,date);
        merge(A,l,m,r,date);
    }
}

void priceChange() {
    int start_date,end_date,i;
    float pc;

    printf("Stocks listed from 1-10\n");
    
    do {
        printf("Enter the number of stock of interest: ");
        scanf("%d",&i);
    } while(i<1 || i>10);
    i--;

    printf("\nData of stocks from 16/10/23 to 20/10/23 available,\nPlease Enter dates in dd format within this range\n");

    start_date = startDate(16,20);

    end_date = endDate(16,20);

    pc = (Data[end_date][i].Close - Data[start_date][i].Open);
    pc /= Data[start_date][i].Open;
    pc *= 100;

    printf("Percentage change in the price of %s stock is: %.2f",list[i],pc);
}

void sortVolumeCloseP() {
    int date,i;

    printf("\nData of stocks from 16/10/23 to 20/10/23 available,\nPlease Enter dates in dd format within this range\n");

    date = startDate(16,20);

    double A[SIZE][2];

    forn(i,SIZE) 
    {
        A[i][0] = Data[date][i].volume;
        A[i][1] = i;
    }

    mergesort(A,0,SIZE-1,date); 

    forn(i,SIZE)
    {
        printf("%s\t-->\t%.2lf , %.2f\n",list[(int)ind[i]],A[i][0],Data[date][(int)ind[i]].Close);
    }
}

void profitLoss() {
    int buy_date,sell_date;
    float diff;

    printf("\nData of stocks from 16/10/23 to 20/10/23 available,\nPlease Enter dates in dd format within this range\n");

    buy_date = startDate(16,20);

    sell_date = endDate(16,20);

    forn(i,SIZE)
    {
        diff = (Data[sell_date][i].High - Data[buy_date][i].Low)/Data[buy_date][i].Low;
        if(diff < 0) {
            diff *= -1;
            printf("Loss for %s stock is : %.2f\n",list[i],diff*100);
        }
        else
            printf("Profit for %s stock is : %.2f\n",list[i],diff*100);
    }
}

void performance(int hi, int lo) {
    int start_date,end_date,i,index;
    float large,small,performance[SIZE];

    printf("\nData of stocks from 16/10/23 to 20/10/23 available,\nPlease Enter dates in dd format within this range\n");

    start_date = startDate(16,20);

    end_date = endDate(16,20);

    forn(i,SIZE)
    {
        performance[i] = (Data[end_date][i].Close - Data[start_date][i].Open);
        performance[i] /= Data[start_date][i].Open;
        performance[i] *= 100;
    }

    if(hi == 1) {
        large = performance[0];
        index = 0;

        for(i = 1; i<SIZE ; i++)
        {
            if(large < performance[i]) {
                large = performance[i];
                index = i;
            }
        }

        printf("%s stock has highest performance with highest gain of %.2f percentage\n",list[index],large);
    }

    if(lo == 1) {
        small = performance[0];
        index = 0;

        for(i = 1; i<SIZE ; i++)
        {
            if(small > performance[i]) {
                small = performance[i];
                index = i;
            }
        }

        printf("%s stock has lowest performance with least gain of %.2f percentage\n",list[index],small);
    }
}

void overallPerformance() {
    int start_date , end_date , i ;
    double overallsum[SIZE][2] = {0};
    double pc = 0;

    printf("\nData of stocks from 17/10/23 to 20/10/23 available,\nPlease Enter dates in dd format within this range\n");

    start_date = startDate(17,20);

    end_date = endDate(17,20);

    forn(i,SIZE) {
        int t = start_date;
        while(t <= end_date)
        {
            pc = ((Data[t][i].Close - Data[t-1][i].Open)/Data[t-1][i].Open) * 100;
            pc *= Data[t][i].volume;
            overallsum[i][0] += pc;
            t++;
        }
        overallsum[i][1] = i;
    }   
    
    mergesort(overallsum,0,SIZE-1,start_date);

    forn(i,SIZE) {
        printf("%s\t-->\t%.2lf\n",list[(int)ind[i]],overallsum[i][0]);
    }
}

void average() {
    int start_date , end_date , i ;
    double numer =0 ;
    long long denom =0 ;
    double average[SIZE];

    printf("\nData of stocks from 16/10/23 to 20/10/23 available,\nPlease Enter dates in dd format within this range\n");

    start_date = startDate(16,20);

    end_date = endDate(16,20);

    forn(i,SIZE)
    {
        int t = start_date;
        while(t <= end_date)
        {
            numer += (Data[t][i].Close * Data[t][i].volume);
            denom += Data[t][i].volume;
            t++;
        }
        average[i] = (numer/denom);
        printf("%s\t --> \t%lf\n",list[i],average[i]);
        numer =0;
        denom =0;
    }

    float finalavg = 0;

    forn(i,SIZE)
    {
        finalavg += average[i];
    }
    printf("\nFinal Average of all stocks: %.2f\n",finalavg/SIZE);
}

int main()
{
    loadData();
    int choice;

    do {
        printf("\nList:\n");
        forn(i,SIZE) {
            printf(" %d.%s\n",i+1,list[i]);
        }

        printf("\nMenu:\n 1:Percentage Change in Stock\n 2.Sorting by Volume-->Close Price\n 3.Profit or Loss of Stocks\n 4.Highest Performing Stock\n 5.Lowest Performing Stock\n 6.Overall Performance\n 7.Average value of all Stocks\n 8.Exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            priceChange();
        else if(choice == 2) 
            sortVolumeCloseP();   
        else if(choice == 3)
            profitLoss();
        else if(choice == 4)
            performance(1,0);
        else if(choice == 5)
            performance(0,1);
        else if(choice == 6)
            overallPerformance();
        else if(choice == 7)
            average();
        else if(choice != 8)
            printf("Invalid input -- Please Enter a valid number\n\n");

    } while(choice != 8);

    printf("Application terminates");
}