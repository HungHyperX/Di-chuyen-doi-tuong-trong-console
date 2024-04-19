#include <stdio.h>
#include "console.h"

#define consoleWidth 80
#define consoleHeight 25

enum Move{UP, DOWN, LEFT, RIGHT};

struct Obj{
    char s[10];
    int x;
    int y;
    enum Move move;
};

int main(){
    struct Obj obj;

    strcpy(obj.s, "Hello");
    obj.y = 0;
    obj.x = consoleWidth/2;
    obj.move = DOWN;

    while(1){
        //clrscr();
        Sleep(200);
        system("cls");
        gotoxy(obj.x, obj.y);
        printf("%s",obj.s);


        if(kbhit())                 // phát hiện có phím nhấn vào
        {
           char key = _getch();            // lưu phím nhấn vào
           if(key == 'A' || key == 'a')            // nhấn A di chuyển sang trái
                obj.move =LEFT;
           if(key == 'D' || key == 'd')            //nhấn D sang phải
                obj.move = RIGHT;
           if(key == 'W' || key == 'w')           //nhấn W lên trên
                obj.move = UP;
           if(key == 'S' || key == 's')             // nhấn S xuống dưới
                obj.move = DOWN;
        }

        if(obj.y >= consoleHeight-1)              //chạm biên dưới
            obj.move = UP;                                  // đt di chuyển lên trên
        else if(obj.y <= 0)                               // chạm biên trên
            obj.move = DOWN;                          // đt di chuyển xuống dưới
        if(obj.x <= 0)                                      // chạm biên trái
            obj.move = RIGHT;                          // đối tượng di chuyển sang phải
        if(obj.x>=consoleWidth-1)                  // chạm biên phải
            obj.move = LEFT;                            // đối tượng di chuyển sang trái


        if (obj.move == DOWN)                // DOWN = đi xuống, y tăng dần
            obj.y++;
        else if (obj.move == UP)                 // UP = đi lên y, giảm dần
            obj.y--;
        if (obj.move == LEFT)                   // LEFT = sang trái, x giảm dần
            obj.x--;
        if (obj.move == RIGHT)               //RIGHT = sang phải, x tăng dần
            obj.x++;


        Sleep(0);

    }
    return 0;
}
