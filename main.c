#include <stdio.h>
#include <stdlib.h>

void View(int x[], int y[], int n){
    int i, j=1, pass, temp1, temp2;
    for(pass=1;pass<n;pass++){
        for(i=0;i<n-pass;i++){
            if(x[i] > x[i+1]){
                temp1 = x[i];
                temp2 = y[i];
                x[i] = x[i+1];
                y[i] = y[i+1];
                x[i+1] = temp1;
                y[i+1] = temp2;
            }
        }
    }
    printf("\nTabel Stok APD\n");
    printf("+==============================+\n");
    printf("| No | Storage Kode | Stok APD |\n");
    printf("+==============================+\n");
    for(i=0; i<n; i++){
        printf("| %i  |\t     %i      |\t %i   |\n", j, x[i], y[i]);
        j++;
    }
    printf("+==============================+\n");
}

int masuk(int x){
    int y;
    printf("Masukkan jumlah yang ditambahkan : ");
    scanf("%i", &y);
    x = x + y;
    printf("Jumlah sekarang = %i\n\n", x);
    return x;
}

int keluar(int x){
    int y;
    printf("Masukkan jumlah yang dikurangkan : ");
    scanf("%i", &y);
    if(y > x){
        x = 0;
    }else{
        x = x - y;
    }
    printf("Jumlah sekarang = %i\n\n", x);
    return x;
}

void SortAsc(int x[], int y[], int n){
    int i, j=1, pass, temp1, temp2;
    for(pass=1;pass<n;pass++){
        for(i=0;i<n-pass;i++){
            if(y[i] > y[i+1]){
                temp1 = y[i];
                temp2 = x[i];
                y[i] = y[i+1];
                x[i] = x[i+1];
                y[i+1] = temp1;
                x[i+1] = temp2;
            }
        }
    }
    printf("\nPengurutan stok terkecil hingga terbesar : \n");
    printf("+==============================+\n");
    printf("| No | Storage Kode | Stok APD |\n");
    printf("+==============================+\n");
    for(i=0; i<n; i++){
        printf("| %i  |\t     %i      |\t %i   |\n", j, x[i], y[i]);
        j++;
    }
    printf("+==============================+\n");
}

void SortDesc(int x[], int y[], int n){
    int i, j=1, pass, temp1, temp2;
    for(pass=1;pass<n;pass++){
        for(i=0;i<n-pass;i++){
            if(y[i] < y[i+1]){
                temp1 = y[i];
                temp2 = x[i];
                y[i] = y[i+1];
                x[i] = x[i+1];
                y[i+1] = temp1;
                x[i+1] = temp2;
            }
        }
    }
    printf("\nPengurutan stok terbesar hingga terkecil : \n");
    printf("+==============================+\n");
    printf("| No | Storage Kode | Stok APD |\n");
    printf("+==============================+\n");
    for(i=0; i<n; i++){
        printf("| %i  |\t     %i      |\t %i   |\n", j, x[i], y[i]);
        j++;
    }
    printf("+==============================+\n");
}

void Min(int x[], int y[], int n){
    int min=0, i, j;
    for(i=1;i<n;i++){
        if(y[i] <= y[min]){
            min = i;
        }
    }
    printf("\nStorage dengan Stok APD terendah adalah\n");
    printf("Storage %i dengan stok %i\n", x[min],y[min]);
}

void Max(int x[], int y[], int n){
    int max=0, i, j;
    for(i=1;i<n;i++){
        if(y[i] >= y[max]){
            max = i;
        }
    }
    printf("\nStorage dengan Stok APD terbanyak adalah\n");
    printf("Storage %i dengan stok %i\n", x[max],y[max]);
}

int main()
{
    int pilih, kode, length;
    int kode_apd[4] = {1,2,3,4};
    int stok_apd[4] = {129,125,122,130};
    char cpilih;
    length = sizeof(kode_apd) / sizeof(*kode_apd);
    Awal: //untuk mengembalikkan ke awal program
    printf("+==========================+\n");
    printf("|   Program Tugas Besar    |\n");
    printf("|   Program  APD  Storage  |\n");
    printf("+==========================+\n\n");
    printf("Pilih Menu :\n");
    printf("1. Tampilkan Stok APD\n");
    printf("2. Input APD Masuk\n");
    printf("3. Input APD Keluar\n");
    printf("4. Urutkan Stok APD\n");
    printf("5. Cari Storage dengan Stok APD terendah\n");
    printf("6. Cari Storage dengan Stok APD terbanyak\n\n");
    printf("Masukkan pilihan : ");
    scanf("%i", &pilih);
    if(pilih == 1){
        View(kode_apd,stok_apd,length);
    }else if(pilih == 2){
        Ulang2:
        printf("Masukkan kode APD : ");
        scanf("%i", &kode);
        if(kode == kode_apd[0]){
            stok_apd[0] = masuk(stok_apd[0]);
        }else if(kode == kode_apd[1]){
            stok_apd[1] = masuk(stok_apd[1]);
        }else if(kode == kode_apd[2]){
            stok_apd[2] = masuk(stok_apd[2]);
        }else if(kode == kode_apd[3]){
            stok_apd[3] = masuk(stok_apd[3]);
        }else{
            printf("Kode Salah!\n\n");
            goto Ulang2;
        }
    }else if(pilih == 3){
        Ulang3:
        printf("Masukkan kode APD : ");
        scanf("%i", &kode);
        if(kode == kode_apd[0]){
            stok_apd[0] = keluar(stok_apd[0]);
        }else if(kode == kode_apd[1]){
            stok_apd[1] = keluar(stok_apd[1]);
        }else if(kode == kode_apd[2]){
            stok_apd[2] = keluar(stok_apd[2]);
        }else if(kode == kode_apd[3]){
            stok_apd[3] = keluar(stok_apd[3]);
        }else{
            printf("Kode Salah!\n\n");
            goto Ulang3;
        }
    }else if(pilih == 4){
        Ulang4:
        printf("1. Ascending (Terkecil - Terbesar)\n");
        printf("2. Descending (Terbesar - Terkecil)\n");
        printf("Masukkan Pilihan : ");
        scanf("%i", &pilih);
        if(pilih == 1){
            SortAsc(kode_apd,stok_apd,length);
        }else if(pilih == 2){
            SortDesc(kode_apd,stok_apd,length);
        }else{
            printf("Pilihan tidak ada!\n\n");
            goto Ulang4;
        }
    }else if(pilih == 5){
        Min(kode_apd,stok_apd,length);
    }else if(pilih == 6){
        Max(kode_apd,stok_apd,length);
    }else{
        printf("Pilihan tidak ada!\n\n");
        goto Awal;
    }
    printf("\nKembali ke menu awal? (y/n) : ");
    cpilih = getche();
    if(cpilih == 'y'){
        printf("\n");
        system("pause");
        system("cls");
        goto Awal;
    }else{
        exit(0);
    }
    return 0;
}
