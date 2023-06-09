#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

int tinhCuocTaxi(int soKm){
    int isoTienCuoc = 0; 
    
    if(soKm <= 15){
    isoTienCuoc = 14000*soKm; 
    }
    else if (soKm >= 15 && soKm <=30){
    isoTienCuoc = 14000+(soKm-1)*10000;
    }
    else if (soKm > 30){
    isoTienCuoc = 14000 + 29*10000 + (soKm - 30) *8000;
    }
    return isoTienCuoc; 
}

bool kiemTraNamNhuan(int nam){
   if (nam % 4 != 0) {
        return 0;
    } else if (nam % 100 != 0) {
        return 1;
    } else if (nam % 400 != 0) {
        return 0;
    } else {
        return 1;
    }
}

int demSoNamNhuan(int start_year, int end_year) {
    int count = 0;
    for (int year = start_year; year < end_year; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            count++;
        }
    }
    return count;
}

int tinhThu(int ngay, int thang , int nam){
int tongSoNgay = 0; 
int thu = 0;

if (kiemTraNamNhuan(nam) == 1){
switch (thang)
{
case 1:
    ngay = ngay;
    break;
case 2: 
    ngay = ngay + 31; 
    break;
case 3: 
    ngay = ngay + 31 + 29;
    break; 
case 4: 
    ngay = ngay + 31 + 29 + 31; 
    break; 
case 5 : 
    ngay = ngay + 31 + 29 + 31 + 30;
break; 
case 6 :
    ngay = ngay + 31 + 29 + 31 + 30 + 31;
break;  
case 7 :
    ngay = ngay + 31 + 29 + 31 + 30 + 31 + 30;
break;  
case 8 :
    ngay = ngay + 31 + 29 + 31 + 30 + 31 + 30 + 31;
break;  
case 9 : 
    ngay = ngay + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
break; 
case 10: 
    ngay = ngay + 31 + 29 + 31 + 30 + 31 + 30+ 31+31+30;
break; 
case 11: 
    ngay = ngay + 31 + 29 + 31 + 30 + 31+30+31+31+30+31;
break; 
case 12: 
    ngay = ngay + 31 + 29 + 31 + 30 + 31+30+31+31+30+31+30;
break; 
default:
    break;
}
// tính từ 1/1/1 thu hai đến nay đã bao nhiêu ngày 
int soNamNhuan = demSoNamNhuan(1,nam);

tongSoNgay = (nam -1) * 365 + (soNamNhuan) + ngay - 1 ;


thu = 2 + (tongSoNgay % 7);
return thu; 
} 
else {

switch (thang)
{
case 1:
    ngay = ngay;
    break;
case 2: 
    ngay = ngay + 31; 
    break;
case 3: 
    ngay = ngay + 31 + 28;
    break; 
case 4: 
    ngay = ngay + 31 + 28 + 31; 
    break; 
case 5 : 
    ngay = ngay + 31 + 28 + 31 + 30;
    break; 
case 6 :
    ngay = ngay + 31 + 28 + 31 + 30 + 31;
    break;  
case 7 :
    ngay = ngay + 31 + 28 + 31 + 30 + 31 + 30;
    break;  
case 8 :
    ngay = ngay + 31 + 28 + 31 + 30 + 31 + 30 + 31;
    break;  
case 9 : 
    ngay = ngay + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
    break; 
case 10: 
    ngay = ngay + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
    break; 
case 11: 
    ngay = ngay + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
    break; 
case 12: 
    ngay = ngay + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
    break; 
default:
    break;
}
int soNamNhuan = demSoNamNhuan(1,nam);

tongSoNgay = (nam - 1) * 365 + soNamNhuan + ngay - 1 ;

thu = 2 + (tongSoNgay % 7);
return thu; 
}
}

int main(int argc, char const *argv[])
{
    int x = 13; 
    printf("so tien taxi la %lu VND\n",tinhCuocTaxi(x));

    printf("thu cua ngay nhap vao la thu %d",tinhThu(9,11,1911));
    return 0;
}
