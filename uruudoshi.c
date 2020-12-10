#include <stdio.h>

void yesterday(int *y, int *m, int *d){
    printf("ルート：");
    if (*d == 1){
        printf("1");
        if (*m == 1){
            printf("-3\n");
            *d = 31;
            *m = 12;
            (*y)--;
        }
        else if (*m == 2 || *m == 4 || *m == 6 || *m == 8 || *m == 9 || *m == 11){
            printf("-4\n");
            (*m)--;
            *d = 31;
        }
        else if (*m == 5 || *m == 7 || *m == 10 || *m == 12){
            printf("-5\n");
            (*m)--;
            *d = 30; 
        }
        else if (*m == 3){//3月1日の場合
            printf("-6");
            *m = 2;
            if (*y % 4 == 0 && *y % 100 != 0){
                printf("-7\n");
                /* うるう年1 */
                *d = 29;
            }
            else if (*y % 1000 == 0){
                printf("-8\n");
                /* うるう年2 */
                *d = 29;
            }
            else{
                printf("-9\n");
                // 普通の年
                *d = 28;
            }                
        }
        else{
            printf("No such month!\n");
        } 
    }
    else if(*d >31){
        printf("No such day!\n");
    }
    else{//1日以外
        printf("2\n");
        (*d)--;
    }
}

void tomorrow(int *y, int *m, int *d){
    printf("ルート：");
    if (*d == 31){
        printf("1");
        *d = 1;
        if(*m == 12){//12月31日の場合
            printf("-6\n");
            *m = 1;
        }
        else{
            (*m)++;
        }
    }
    else if (*d == 30){
        printf("2");
        if(*m == 1 || 3 || 5 || 7 || 8 || 10 || 12){
            printf("-7\n");
            *d = 31;
        }
        else{
            printf("-8\n");
            *d = 1;
            (*m)++;
        }
    }
    else if (*d == 29){
        printf("3");
        if(*m == 2){
            printf("-9\n");
            *d = 1;
            (*m)++;
        }
        else{
            printf("-10\n");
            (*d)++;
        }
    }
    else if (*d == 28){
        printf("4");
        if(*m == 2){
            printf("-11");
            if(*y % 4 == 0 && *y % 100 != 0){
                printf("-13\n");
                // うるう年1
                (*d)++;
            }
            else if(*y % 1000 == 0){
                printf("-14\n");
                // うるう年2
                (*d)++;
            }
            else{
                printf("-15\n");
                // 普通の年
                *d = 1;
                (*m)++;                
            }

        }
        else{//2月以外
            printf("-12\n");
            (*d)++;
        }
    }
    else if(*d > 31){
        printf("No such day!\n");
    }
    else{//31, 30, 29, 28日以外
        printf("5\n");
        (*d)++;
    }        
}
int main(void){

    int day, month, year;
    int dcpy, mcpy, ycpy;

    // 年月日を入力させる
    printf("年：");
    scanf("%d", &year);
    ycpy = year;
    printf("月：");
    scanf("%d", &month);
    mcpy = month;
    printf("日：");
    scanf("%d", &day);
    dcpy = day;

    // 入力チェック
    /*printf("day = %d\n", day);
    printf("month = %d\n", month);
    printf("year = %d\n", year);
    printf("dcpy = %d\n", dcpy);
    printf("mcpy = %d\n", mcpy);
    printf("ycpy = %d\n", ycpy);*/
    
    // 前日と翌日を求める
    yesterday(&year, &month, &day);
    printf("前日：%d/%d/%d\n", year, month, day);
    tomorrow(&ycpy, &mcpy, &dcpy);
    printf("翌日：%d/%d/%d\n", ycpy, mcpy, dcpy);

    return 0;
}