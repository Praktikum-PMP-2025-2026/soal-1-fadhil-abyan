/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Muhammad Fadhil Abyan (13224008)
 *   Nama File           : soal1.c
 *   Deskripsi           : Mengganti data yang tidak valid pada suatu array dengan aturan tertentu. Data yang tidak valid ditandai dengan -1.
 *                         Jika sebelah kanan dan kiri dari data yang tidak valid, terdapat data, maka data yang tidak valid diisi dengan (kiri+kanan)/2
 *                         Jika sebelah kanan dari data yang tidak valid kosong, maka data yang tidak valid diisi dengan data sebelah kiri
 *                         Jika sebelah kiri dari data yang tidak valid kosong, maka data yang tidak valid diisi dengan data sebelah kanan
 *                         Jika sebelah kanan dan kiri data kosong, maka data diisi dengan 0.
 */


 #include <stdio.h>
 #include <string.h>
  
 int main(){
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i <n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n -1; i++){
        int temp1 = 0;
        int temp2 = 0;
        if((i != 0) && (i != n-1)){
            if(arr[i] == -1){
                for(int j = i+1; j < n; j++){
                    temp2 = arr[j];
                    if(arr[j] != -1){
                        break;
                    }
                }

                for(int j = i-1; j >= 0; j--){
                    temp1 = arr[j];
                    if(arr[j] != -1){
                        break;
                    }
                }
                
                if(temp1 != -1 && temp2 != -1){
                    arr[i] = (temp1+ temp2)/2;
                }
                else if(temp1 == -1){
                    arr[i] = temp2;
                }
                else if(temp2 == -1){
                    arr[i] = temp1;
                }
                else{
                    arr[i] = 0;
                }
                }
        }
        if (arr[0] == -1){
            for(int j = 1; j < n; j++){
                temp2 = arr[j];
                if(arr[j] != -1){
                    break;
                }
            }
            if(temp2 != -1){
                arr[0] = temp2;
            }
            else{
                arr[0] = 0;
            }
        }

        if (arr[n-1] == -1){
            for(int j = n-2; j >= 0; j--){
                temp1 = arr[j];
                if(arr[j] != -1){
                    break;
                }
            }
            if(temp1 != -1){
                arr[n-1] = temp1;
            }
            else{
                arr[n-1] = 0;
            }
        }

        }
        

    printf("RECOVERED ");
    int sum = 0;
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
        sum = sum + arr[i];
    }
    printf("\n");
    printf("MAX_SUM : %d\n", sum);

    return 0;
 }
 
