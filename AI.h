#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
//#include <main.cpp>
uint16_t x=5;
uint16_t y=5;
uint8_t mapSize[2]{10,10}; //Размеры
char map[][10]{
{"......#.."},
{"......#.."},
{"......#.."},
{"......#.."},
{"......#.."},
{"......#.."},
{"......#.."},
{"......#.."},
{"......#.."},
{"........."},
{"......#.."}
};
/*string map[10][10]{
{"#","#",".",".",".",".","#",".",".","."},
{".",".",".",".",".",".","#",".",".","."},
{".",".",".",".",".",".","#",".",".","."},
{".",".",".",".",".","#",".",".",".","."},
{".",".",".",".",".",".","#",".",".","."},
{".",".",".",".",".",".","#",".",".","."},
{".",".",".",".",".",".",".",".",".","."}};*/ //Карта
int16_t resolution[2]{8,8}; //Количество символов

class SimpleAI{
    private:
        //std::vector<int> Exp={{-1,0}};
        uint16_t rotateX; //Направвлление по X
        uint16_t rotateY; //Направвлление по Y
        int findTravel(){
            switch(rotateX){
                case 0: posX-=1; return 0; break;
                case 1: posX+=1; return 0; break;
            }
            switch(rotateY){
                case 0: posY+=1; return 0; break;
                case 1: posY-=1; return 0; break;
            }
        }
    public:
        uint16_t posX,posY;
        void doFind(){
            //std::vector<int> toExp={{0,0}};
            //toExp.push_back((posY,posX));
            if(posX>x&&map[posY][posX-1]=='.'){
                rotateX=0; //Направление >
            } else if(posX<x&&posX+1<mapSize[1]&&map[posY][posX+1]=='.'){
                rotateX=1; //Направление <
            } else{
                rotateX=-1;
            }
            if(posY<y&&map[posY+1][posX]=='.'){
                rotateY=0; //Направление <
            } else if(posY>y&&posY+1<mapSize[0]&&map[posY-1][posX]=='.'){
                rotateY=1; //Направление >
            } else {
                rotateY=-1;
            }
            map[posY][posX]='.';
            findTravel();
            map[posY][posX]='M';
            std::cout<<posX<<" "<<posY<<"\n";
        }
};