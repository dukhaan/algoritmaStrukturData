#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKS 200

typedef struct{
    char nama[MAKS],grade;
    float tugas,uas,uts,akhir;
}daftarnilai;

typedef struct{
    char nama[MAKS];
    float nilai;
}ranking;

void input(daftarnilai *);
void tampil(daftarnilai *);
int n;

int main(){
    daftarnilai student[MAKS];
    puts("MENGHITUNG NILAI AKHIR");
    puts("MATA KULIAH KONSEP PEMROGRAMAN\n");
    printf("Berapa jumlah mahasiswa ? ");
    scanf("%d", &n);
    printf("\nMasukkan DATA MAHASISWA\n\n");
    input(student);
    tampil(student);
    return 0;
}
void input(daftarnilai *data){
    int i;
    for(i=0; i<n; i++){
        printf("Mahasiswa ke-%d", i+1);
        fflush(stdin);
        printf("\nNama\t\t : ");
        gets((*data).nama);
        fflush(stdin);
        printf("Nilai tugas\t : ");
        scanf("%f", &(*data).tugas);
        fflush(stdin);
        printf("Nilai uts\t : ");
        scanf("%f", &(*data).uts);
        printf("Nilai uas\t : ");
        scanf("%f", &(*data).uas);
        puts("");
        data++;
    }
}
void tampil(daftarnilai *data){
    int j;
    ranking tertinggi;
    printf("\t\t\tDAFTAR NILAI\n");
    printf("\t\tMATAKULIAH KONSEP PEMROGRAMAN\n");
    printf("-------------------------------------------------------------------------\n");
    printf("No\tNama\t\t\t\tNilai\t\t\tGrade\n");
    printf("\tMahasiswa\t\tTugas\tUTS\tUAS\tAkhir\n");
    printf("-------------------------------------------------------------------------\n");
    for(j=0; j<n; j++)
    {
        (*data).akhir = ((*data).tugas*0.2)+((*data).uts*0.4)+((*data).uas*0.4);
        if(j == 0 || tertinggi.nilai<(*data).akhir)
        {
            strcpy(tertinggi.nama,(*data).nama);tertinggi.nilai = (*data).akhir;
        }
        if((*data).akhir>=80)
            (*data).grade = 'A';
        else if((*data).akhir>=70)
            (*data).grade = 'B';
        else if((*data).akhir>=60)
            (*data).grade = 'C';
        else if((*data).akhir>=50)
            (*data).grade = 'D';
        else if((*data).akhir<50)
            (*data).grade = 'E';

        printf("%d\t%s\t\t\t%g\t%g\t%g\t%g\t%c\n",j+1,(*data).nama,(*data).tugas,(*data).uts,(*data).uas,(*data).akhir,(*data).grade);
        data++;
    }
    printf("-------------------------------------------------------------------------\n\n");
    printf("Total Mahasiswa = %d", n);
    printf("\n\nNilai Tertinggi");
	printf("\nNama mahasiswa\t= %s",tertinggi.nama);
	printf("\nNilai\t= %g",tertinggi.nilai);
}
