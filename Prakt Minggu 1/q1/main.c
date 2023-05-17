#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day,month,year;
} Date;

int sameDay (Date, Date);

int main()
{
    Date day1 = {23,2,2023};
    Date day2 = {23,2,2023};

    if(sameDay(day1,day2) == 1){
        printf("It is the same day\n");
    } else {
        printf("It is not the same day\n");
    }


    return 0;
}

int sameDay (Date day1, Date day2){
    if(day1.day == day2.day && day1.month == day2.month && day1.year == day2.year){
        return 1;
    } else {
        return 0;
    }
}
