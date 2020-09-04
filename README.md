# C-Snippets-

Este snippet c++ dibuja un calendario en la terminal con este formato.
This c ++ snippet draws a calendar in the terminal in this format.

""" | L | M | M | J | V | S | D |
 00  **  **  **  **  **  **
 **  **  **  **  **  **  **
 **  **  **  **  **  **  **
 **  **  **  **  **  **  **
 **  ** """
 
 """ | L | M | M | J | V | S | D |
 --  --  --  --  --  00  **
 **  **  **  **  **  **  **
 **  **  **  **  **  **  **
 **  **  **  **  **  **  **
 **  **  **  **  **  **  **
 ** """
 
 Los días marcados con ** son los dias del mes que no se encuentren en el array days.
 The days marked with ** are the days of the month that are not in the days array.

void drawCalendar(int m, int ye, IntegerArrayMonth days){

  int monthL = 0;
  bool f = false;
  bool is = false;
  IntegerArrayWeek weekdays = {0,1,2,3,4,5,6};
  int weekCounter = 0;
  switch(m){
    case 2:
      monthL = 28;
      break;

    case 4:
      monthL = 30;
      break;


    case 6:
        monthL = 30;
        break;

    case 9:
      monthL = 30;
      break;

    case 11:
      monthL = 30;
      break;

    default:
      monthL = 31;
    }

  printf("| L | M | M | J | V | S | D |");
  printf("\n");

  for(int x = 0; x < monthL; x++){
        is = false;
        for(int y = 0; y<7; y++){

            if(weekdays[y] == dayofweek(x, m, ye)){


                f = true;
                for(int z = 0; z < 31; z++){


                    if(days[z] == x){

                        is = true;

                      }


                  }
                if(x < 10 && is){
                    printf(" 0%d ", x);
                  }
                else if(is){
                    printf(" %d ", x);
                  }

                if(!is){

                    printf(" ** ");

                  }
              }
            if(!f){

                printf(" -- ");
                weekCounter++;

              }

          }

        weekCounter++;
        if(weekCounter == 7){

            printf("\n");
            weekCounter = 0;

          }


    }


  }
  
Este snippet recive un dia, mes, año y retorna el dia de la semana.
This snippet receives a day, month, year and returns the day of the week.
  
int dayofweek(int d, int m, int y)
{
    IntegerArray t = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y = y - (m < 3);
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
