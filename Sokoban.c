#include <stdio.h>
#include <windows.h>
#define height 19
#define lenght 25
int x, y, game=0;
char map[height][lenght];
char map_image[height][lenght] =                                            {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 1,
    1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 1,
    1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 1, 1, 1, 0, 3, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 3, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

void SetColor(int ForgC){
     WORD wColor;

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void image(){
    int a,b;
    for (a=0;a<height; a++){
        for (b=0;b<lenght;b++){
            map[a][b]=map_image[a][b];
            if(map[a][b]==2){
            x=a;
            y=b;
            }
        }
    }
}
void print(){
    int a,b;
    SetColor(7);
    system("cls");
    for (a=0; a<height;a++){
        for (b=0;b<lenght;b++){
            if (map[a][b]==1){
                SetColor(21);
                printf ("%c", 219);
            }
            else
                if (map[a][b]==0)
                    printf (" ");
                else
                    if (map[a][b]==2 ||map[a][b]==6){
                        SetColor(7);
                        printf ("%c", 2);
                        }
                    else
                        if (map[a][b]==3){
                            SetColor(22);
                            printf ("%c", 177);
                        }
                        else
                            if (map[a][b]==4){
                                SetColor(14);
                                printf ("o");
                            }
                            else
                                {
                                    SetColor(14);
                                    printf ("x");
                                }
        }
        printf ("\n");
    }
}
void movement(){
    int direc;
    direc=0;
    while (direc!=114 && direc!= 72 && direc!= 75  && direc!= 77 && direc!= 80)
        direc=getch();
    if(direc==114){
        image();
    }
    if (direc==72){
        if (map[x-1][y]!=1){
            if (map[x-1][y]==0){
                if (map[x][y]==2){
                map[x][y]=0;
                map[x-1][y]=2;
                }
                else {
                    map[x][y]=4;
                    map[x-1][y]=2;
                }
            }
            else{
                if(map[x-1][y]==4){
                    map[x-1][y]=6;
                    map[x][y]=0;
                }
                else{
                    if(map[x-1][y]==3){
                        if(map[x-2][y]==0){
                            map[x-2][y]=3;
                            map[x-1][y]=2;
                            if (map[x][y]==2)
                                map[x][y]=0;
                            if (map[x][y]==6)
                                map[x][y]=4;
                            }
                            else{
                                if(map[x-2][y]==4){
                                    map[x-2][y]=5;
                                    map[x-1][y]=2;
                                    map[x][y]=0;
                                }
                            }
                    }
                    else{
                        if (map[x-1][y]==5){
                                if (map[x-2][y]==0){
                                    map[x-2][y]=3;
                                    map[x-1][y]=6;
                                    map[x][y]=0;
                            }
                        }


                    }

                }
            }
            if(map[x-1][y]==3 && map[x-2][y]==3 || map[x-1][y]==3 && map[x-2][y]==1 || map[x-1][y]==5 && map[x-2][y]==1 || map[x-1][y]==3 && map[x-2][y]==5){}
            else
            x--;
        }
    }
if (direc==80){
        if (map[x+1][y]!=1){
            if (map[x+1][y]==0){
                if (map[x][y]==2){
                map[x][y]=0;
                map[x+1][y]=2;
                }
                else {
                map[x][y]=4;
                map[x+1][y]=2;
                }
            }
            else{
                if(map[x+1][y]==4){
                map[x+1][y]=6;
                map[x][y]=0;
                }
                else{
                    if(map[x+1][y]==3){
                        if(map[x+2][y]==0){
                            map[x+2][y]=3;
                            map[x+1][y]=2;
                            if (map[x][y]==2)
                                map[x][y]=0;
                            if (map[x][y]==6)
                            map[x][y]=4;
                        }
                        else{
                            if(map[x+2][y]==4){
                            map[x+2][y]=5;
                            map[x+1][y]=2;
                            map[x][y]=0;
                            }
                        }
                    }
                    else{
                        if (map[x+1][y]==5){
                                if (map[x+2][y]==0){
                                    map[x+2][y]=3;
                                    map[x+1][y]=6;
                                    map[x][y]=0;
                            }
                        }


                    }

                }
            }
                        if(map[x+1][y]==3 && map[x+2][y]==3 || map[x+1][y]==3 && map[x+2][y]==1 || map[x+1][y]==5 && map[x+2][y]==1 || map[x+1][y]==3 && map[x+2][y]==5){}
            else
        x++;
        }
    }
    if (direc==75){

        if (map[x][y-1]!=1){

            if (map[x][y-1]==0){
                if (map[x][y]==2){
                map[x][y]=0;
                map[x][y-1]=2;
                }
                else {
                map[x][y]=4;
                map[x][y-1]=2;
                }
            }
            else{
                if(map[x][y-1]==4){
                    map[x][y-1]=6;
                    map[x][y]=0;
                }
                else{
                    if(map[x][y-1]==3){
                        if(map[x][y-2]==0){
                            map[x][y-2]=3;
                            map[x][y-1]=2;
                            if (map[x][y]==2)
                                map[x][y]=0;
                            if (map[x][y]==6)
                                map[x][y]=4;
                            }
                        else{
                            if(map[x][y-2]==4){
                                map[x][y-2]=5;
                                map[x][y-1]=2;
                                map[x][y]=0;
                            }
                        }
                    }
                    else{
                        if (map[x][y-1]==5){
                                if (map[x][y-2]==0){
                                    map[x][y-2]=3;
                                    map[x][y-1]=6;
                                    map[x][y]=0;
                            }
                        }
                    }

                }
            }
                        if(map[x][y-1]==3 && map[x][y-2]==3 || map[x][y-1]==3 && map[x][y-2]==1 || map[x][y-1]==5 && map[x][y-2]==1 || map[x][y-1]==3 && map[x][y-2]==5){}
            else
            y--;
        }
    }
    if (direc==77){
        if (map[x][y+1]!=1){
            if (map[x][y+1]==0){
                if (map[x][y]==2){
                map[x][y]=0;
                map[x][y+1]=2;
                }
                else {
                map[x][y]=4;
                map[x][y+1]=2;
                }
            }
            else{
                if(map[x][y+1]==4){
                map[x][y+1]=6;
                map[x][y]=0;
                }
                else{
                    if(map[x][y+1]==3){
                        if(map[x][y+2]==0){
                            map[x][y+2]=3;
                            map[x][y+1]=2;
                            if (map[x][y]==2)
                                map[x][y]=0;
                            if (map[x][y]==6)
                            map[x][y]=4;
                        }
                        else{
                            if(map[x][y+2]==4){
                            map[x][y+2]=5;
                            map[x][y+1]=2;
                            map[x][y]=0;
                            }
                        }
                    }
                    else{
                        if (map[x][y+1]==5){
                                if (map[x][y+2]==0){
                                    map[x][y+2]=3;
                                    map[x][y+1]=6;
                                    map[x][y]=0;
                            }
                        }
                    }
                }
            }
            if(map[x][y+1]==3 && map[x][y+2]==3 || map[x][y+1]==3 && map[x][y+2]==1 || map[x][y+1]==5 && map[x][y+2]==1 || map[x][y+1]==3 && map[x][y+2]==5){
            }
            else
                y++;
        }
    }
}
void verify(){
int a,b, obj=0;
    for (a=0;a<height;a++){
        for (b=0;b<lenght;b++){
            if (map[a][b]==5)
            obj++;
        }
    }
    if(obj==3){
    game=1;
    }
}
int main(){
    image();
    print();
    while (game!=1){
        movement();
        verify();
        print();
    }
    if(game==1){
        system("cls");
        SetColor(8);
        printf ("\n\n\n\n\n\n\n\n\n\n                              PARABENS, VOCE VENCEU!\n\n\n\n\n\n\n\n\n");
        getch();
    }
}
