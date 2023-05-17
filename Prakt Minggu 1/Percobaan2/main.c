#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int hari, bulan, tahun;
} Date;

typedef struct{
    int id;
    float gaji;
    char nama[32], jenis;
    Date tglLahir;
}pegawai;

int n;
void input(pegawai *data);
void tampil(pegawai *data);

int main(){
    pegawai dataPegawai[30];

    printf("\t\t\tData Pegawai");
    printf("\n\nBerapa jumlah pegawai? ");
    scanf("%d",&n);
    input(dataPegawai);
    tampil(dataPegawai);

    return 0;
}

void input(pegawai *data){
    int i;
    for(i=0; i<n; i++){
        printf("\nData pegawai ke-%d",i+1);
        fflush(stdin);
        printf("\nNama\t\t\t= ");
        gets((*data).nama);
        fflush(stdin);
        printf("Tgl lahir [dd-mm-yyyy]\t= ");
        scanf("%d-%d-%d",&(*data).tglLahir.hari,&(*data).tglLahir.bulan,&(*data).tglLahir.tahun);
        fflush(stdin);
        printf("Jenis Kelamin [L/P]\t= ");
        scanf("%c",&(*data).jenis);

        fflush(stdin);
        printf("Gaji perbulan\t\t= ");
        scanf("%f",&(*data).gaji);
        fflush(stdin);
        data++;
    }
}

void tampil(pegawai *data){
    int i;
    printf("\nData pegawai yang telah diinputkan \n");
    for(i=0; i<n; i++){
        printf("\nNo id\t\t : %d",i+1);
        printf("\nNama\t\t : %s",(*data).nama);
        printf("\nTanggal lahir\t : %d-%d-%d",(*data).tglLahir.hari,(*data).tglLahir.bulan,(*data).tglLahir.tahun);

        if((*data).jenis == 'L' || (*data).jenis == 'l')
            printf("\nJenis Kelamin\t : Laki-laki");
        else if((*data).jenis == 'P' || (*data).jenis == 'p')
            printf("\nJenis Kelamin\t : Perempuan");
        else
            printf("\nJenis Kelamin\t : Unknown");
        printf("\nGaji perbulan\t : Rp. %.2f",(*data).gaji);
        data++;
        puts("");
    }
}
