#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10

typedef struct Siswa
{
    int No;
    char Nama[50];
    int Nilai;
} Siswa;

void insertionSort(Siswa *);
void selectionSort(Siswa *);
void bubbleSort(Siswa *);
void shellSort(Siswa *);

//Merge & Quick
void mergeShortRecursive(Siswa *, int , int );
void mergeData(Siswa *, int , int , int );

void quickShortRecursive(Siswa *, int, int );
int quickPartitionData(Siswa *, int, int );

void showData(Siswa *);
void allmenu(Siswa *, Siswa *, int );
void swap(Siswa *, Siswa *);
void modeAscDesc();
void modeSorting();
void backupArray(Siswa *, Siswa *);

int menuSort = 0, metodeAscDesc = 0, metodeSorting = 0;
Siswa temp;

int main()
{
    Siswa data[MAX] =
    {
        {5, "Cici", 92},
        {4, "Budi", 94},
        {7, "Ade", 87},
        {8, "Gita", 85},
        {2, "Fajar", 86},
        {3, "Dodi", 82},
        {1, "Eka", 83},
        {6, "Jono", 89},
        {10, "Ira", 95},
        {9, "Hana", 93}
    };

    Siswa dataBackup[MAX];

    while(menuSort != 7)
    {
        backupArray(&data, &dataBackup);

        puts("MENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Shell Sort\n4. Bubble Sort\n5. Merge Short\n6. Quick Short\n7. Exit");
        printf("\nPilihan anda [1/2/3/4/5/6/7] : ");
        scanf("%d", &menuSort);

        if (menuSort == 7)
        {
            exit(0);
        }
        else if (menuSort < 1 || menuSort > 7)
        {
            printf("Menu yang dimasukkan salah!\n");
        }
        else
        {
            modeSorting();
            modeAscDesc();
            if (metodeSorting < 1 || metodeSorting > 7)
                printf("Menu yang dimasukkan salah!\n");
            else
                allmenu(data, dataBackup, menuSort);
        }
    }
    return 0;
}

void allmenu(Siswa *data, Siswa *dataBackup, int menuSort)
{
    puts("Sebelum");
    showData(data);
    switch (menuSort)
    {
    case 1:
        insertionSort(dataBackup);
        puts("Insertion Sort :\n");
        break;
    case 2:
        selectionSort(dataBackup);
        puts("Selection Sort :\n");
        break;
    case 3:
        shellSort(dataBackup);
        puts("Shell Sort :\n");
        break;
    case 4:
        bubbleSort(dataBackup);
        puts("Bubble Sort :\n");
        break;
    case 5:
        mergeShortRecursive(dataBackup, 0, MAX-1);
        puts("Merge Sort :\n");
        break;
    case 6:
        quickShortRecursive(dataBackup, 0, MAX-1);
        puts("Quick Sort :\n");
        break;
    case 7:
        exit(0);
        break;
    default:
        printf("Invalid menu!\n");
        return 1;
    }
    puts("Setelah:");
    showData(dataBackup);
    puts("");
}

void insertionSort(Siswa *siswa)
{
    int i, j;
    puts("");

    for (i = 1; i < MAX; i++)
    {
        temp = siswa[i];
        j = i - 1;

        while (j >= 0 && ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[j].No > temp.No) ||
                          (metodeSorting == 1 && metodeAscDesc == 2 && siswa[j].No < temp.No) ||
                          (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[j].Nama, temp.Nama) > 0) ||
                          (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[j].Nama, temp.Nama) < 0) ||
                          (metodeSorting == 3 && metodeAscDesc == 1 && siswa[j].Nilai > temp.Nilai) ||
                          (metodeSorting == 3 && metodeAscDesc == 2 && siswa[j].Nilai < temp.Nilai)
                          ))
        {
            siswa[j+1] = siswa[j];
            j--;
        }

        siswa[j+1] = temp;
    }
}

void selectionSort(Siswa *siswa)
{
    int i, j, min;
    for (i = 0; i < MAX - 1; i++)
    {
        min = i;
        for (j = i + 1; j < MAX; j++)
        {
            if ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[j].No < siswa[min].No) ||
                (metodeSorting == 1 && metodeAscDesc == 2 && siswa[j].No > siswa[min].No) ||
                (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[j].Nama, siswa[min].Nama) < 0) ||
                (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[j].Nama, siswa[min].Nama) > 0) ||
                (metodeSorting == 3 && metodeAscDesc == 1 && siswa[j].Nilai < siswa[min].Nilai) ||
                (metodeSorting == 3 && metodeAscDesc == 2 && siswa[j].Nilai > siswa[min].Nilai))
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = siswa[i];
            siswa[i] = siswa[min];
            siswa[min] = temp;
        }
    }
}

void bubbleSort(Siswa *siswa)
{
    int i, j;
    puts("");
    for (i = 0; i < MAX-1; i++)
    {
        for (j = 0; j < MAX-i-1; j++)
        {
            if ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[j].No > siswa[j+1].No) ||
                (metodeSorting == 1 && metodeAscDesc == 2 && siswa[j].No < siswa[j+1].No) ||
                (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[j].Nama, siswa[j+1].Nama) > 0) ||
                (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[j].Nama, siswa[j+1].Nama) < 0) ||
                (metodeSorting == 3 && metodeAscDesc == 1 && siswa[j].Nilai > siswa[j+1].Nilai) ||
                (metodeSorting == 3 && metodeAscDesc == 2 && siswa[j].Nilai < siswa[j+1].Nilai))
            {
                temp = siswa[j];
                siswa[j] = siswa[j+1];
                siswa[j+1] = temp;
            }
        }
    }
}

void shellSort(Siswa *siswa)
{
    int k, i, j;
    puts("");
    for (k = MAX/2; k > 0; k = k/2)
    {
        for (i = k; i < MAX; i++)
        {
            temp = siswa[i];
            j = i;
            while (j >= k && ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[j-k].No > temp.No) ||
                              (metodeSorting == 1 && metodeAscDesc == 2 && siswa[j-k].No < temp.No) ||
                              (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[j-k].Nama, temp.Nama) > 0) ||
                              (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[j-k].Nama, temp.Nama) < 0) ||
                              (metodeSorting == 3 && metodeAscDesc == 1 && siswa[j-k].Nilai > temp.Nilai) ||
                              (metodeSorting == 3 && metodeAscDesc == 2 && siswa[j-k].Nilai < temp.Nilai)))
            {
                siswa[j] = siswa[j-k];
                j -= k;
            }
            siswa[j] = temp;
        }
    }
}

void mergeShortRecursive(Siswa *siswa, int left, int right)
{
    int med;

    if(left < right)
    {
        med = (left + right) / 2;
        mergeShortRecursive(siswa, left, med);
        mergeShortRecursive(siswa, med+1, right);
        mergeData(siswa, left, med, right);
    }
}

void mergeData(Siswa *siswa, int left, int med, int right)
{
    int kiri1, kiri2, kanan1, kanan2, i, j;
    Siswa hasil[MAX];

    kiri1 = left;
    kanan1 = med;
    kiri2 = med+1;
    kanan2 = right;
    i = left;

    while((kiri1 <= kanan1) && (kiri2 <= kanan2))
    {
        if((metodeSorting == 1 && metodeAscDesc == 1 && siswa[kiri1].No <= siswa[kiri2].No) ||
           (metodeSorting == 1 && metodeAscDesc == 2 && siswa[kiri1].No >= siswa[kiri2].No) ||
           (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[kiri1].Nama, siswa[kiri2].Nama) < 0) ||
           (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[kiri1].Nama, siswa[kiri2].Nama) > 0) ||
           (metodeSorting == 3 && metodeAscDesc == 1 && siswa[kiri1].Nilai <= siswa[kiri2].Nilai) ||
           (metodeSorting == 3 && metodeAscDesc == 2 && siswa[kiri1].Nilai >= siswa[kiri2].Nilai))
        {
            hasil[i] = siswa[kiri1];
            kiri1++;
        } else
        {
            hasil[i] = siswa[kiri2];
            kiri2++;
        }
        i++;
    }

    while(kiri1 <= kanan1)
    {
        hasil[i] = siswa[kiri1];
        kiri1++;
        i++;
    }

    while(kiri2 <= kanan2)
    {
        hasil[i] = siswa[kiri2];
        kiri2++;
        i++;
    }

    j = left;
    while(j <= right)
    {
        siswa[j] = hasil[j];
        j++;
    }
}

void quickShortRecursive(Siswa *siswa, int p, int r)
{
    int q;

    if(p < r)
    {
        q = quickPartitionData(siswa, p, r);
        quickShortRecursive(siswa, p, q);
        quickShortRecursive(siswa, q+1, r);
    }
}

int quickPartitionData(Siswa *siswa, int p, int r)
{
    Siswa pivot = siswa[p];
    int i = p;
    int j = r;

    do {
        while ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[j].No > pivot.No) ||
               (metodeSorting == 1 && metodeAscDesc == 2 && siswa[j].No < pivot.No) ||
               (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[j].Nama, pivot.Nama) > 0) ||
               (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[j].Nama, pivot.Nama) < 0) ||
               (metodeSorting == 3 && metodeAscDesc == 1 && siswa[j].Nilai > pivot.Nilai) ||
               (metodeSorting == 3 && metodeAscDesc == 2 && siswa[j].Nilai < pivot.Nilai))
               {
                   j--;
               }

        while ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[i].No < pivot.No) ||
               (metodeSorting == 1 && metodeAscDesc == 2 && siswa[i].No > pivot.No) ||
               (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[i].Nama, pivot.Nama) < 0) ||
               (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[i].Nama, pivot.Nama) > 0) ||
               (metodeSorting == 3 && metodeAscDesc == 1 && siswa[i].Nilai < pivot.Nilai) ||
               (metodeSorting == 3 && metodeAscDesc == 2 && siswa[i].Nilai > pivot.Nilai))
               {
                   i++;
               }

        if(i < j)
        {
            swap(&siswa[i], &siswa[j]);
            j--;
            i++;
        }
        else
            return j;

    } while (i <= j);
    return j;
}

void swap(Siswa *a, Siswa *b)
{
    Siswa temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void modeAscDesc()
{
    printf("\nPengurutan yang dipilih:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan anda [1/2]: ");
    scanf("%d", &metodeAscDesc);
}

void modeSorting()
{
    printf("\nPengurutan yang dipilih:\n");
    printf("1. SortByNO\n");
    printf("2. SortByNama\n");
    printf("3. SortByNilai\n");

    printf("Pilihan anda [1/2/3]: ");
    scanf("%d", &metodeSorting);
}

void showData(Siswa *siswa)
{
    printf("+-----+----------------------+-------+\n");
    printf("| %-3s | %-20s | %-5s |\n", "No", "Nama", "Nilai");
    printf("+-----+----------------------+-------+\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("| %3d | %-20s | %-5d |\n", siswa[i].No, siswa[i].Nama, siswa[i].Nilai);
    }
    printf("+-----+----------------------+-------+\n");
}

void backupArray(Siswa *data, Siswa *dataBackup)
{
    int i;

    for(i = 0; i < MAX; i++)
        dataBackup[i] = data[i];
}
