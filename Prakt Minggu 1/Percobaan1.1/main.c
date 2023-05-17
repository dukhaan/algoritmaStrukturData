#include <stdio.h>
#include <stdlib.h>
#define MAKS 200

struct data {
    char nama[MAKS],grade;
    float tugas,uts,uas,akhir;
};

void input(struct data []);
void tampil(struct data []);
int n;

int main()
{
    struct data student[MAKS];
    puts("MENGHITUNG NILAI AKHIR");
    puts("MATA KULIAH KONSEP PEMROGRAMAN");
    puts("");
    printf("Berapa Jumlah mahasiswa ? ");
    scanf("%d",&n);
    printf("\nMasukkan DATA Mahasiswa\n\n");
    input(student);
    tampil(student);

    return 0;
}

void input(struct data mahasiswa[MAKS]){
    int i;
    for(i=0;i<n;i++){
        printf("Mahasiswa ke-%d",i+1);
        fflush(stdin);

        printf("\nNama \t\t: ");
        gets(mahasiswa[i].nama);
        fflush(stdin);

        printf("Nilai Tugas\t :");
        scanf("%f",&mahasiswa[i].tugas);

        printf("Nilai uts\t :");
        scanf("%f",&mahasiswa[i].uts);

        printf("Nilai uas\t :");
        scanf("%f",&mahasiswa[i].uas);

        puts("");
    }
}

void tampil(struct data mahasiswa[MAKS]){
    int j;
    printf("\n\n\t\t\tDAFTAR NILAI\n");
    printf("\t\tMATAKULIAH KONSEP PEMROGRAMAN\n");
    printf("-------------------------------------------------------------------------\n");
    printf("No\tNama\t\t\t\tNilai\t\t\tGrade\n");
    printf("\tMahasiswa\t\tTugas\tUTS\tUAS\tAkhir\n");
    printf("-------------------------------------------------------------------------\n");
    for(j=0;j<n;j++){
        mahasiswa[j].akhir= (mahasiswa[j].tugas*0.2)+(mahasiswa[j].uts*0.4)+(mahasiswa[j].uas*0.4);
        if(mahasiswa[j].akhir>=80)
            mahasiswa[j].grade = 'A';
        else if(mahasiswa[j].akhir>=70)
            mahasiswa[j].grade = 'B';
        else if(mahasiswa[j].akhir>=60)
            mahasiswa[j].grade = 'C';
        else if(mahasiswa[j].akhir>=50)
            mahasiswa[j].grade = 'D';
        else if(mahasiswa[j].akhir<50)
            mahasiswa[j].grade = 'E';
        printf("%d\t%s\t\t\t%g\t%g\t%g\t%g\t%c\n",j+1,mahasiswa[j].nama,mahasiswa[j].tugas,mahasiswa[j].uts,mahasiswa[j].uas,mahasiswa[j].akhir,mahasiswa[j].grade);
    }
    printf("-------------------------------------------------------------------------\n\n");
    printf("Total Mahasiswa = %d", n);
}
