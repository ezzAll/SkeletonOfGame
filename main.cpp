#include <iostream>
#include <windows.h>
#include "AI.h"
#include "Random.h"
#include "Menu.h"
#include <vector>

using namespace std;


uint16_t SetResolution(uint8_t type, uint8_t typeOfScroll){
    switch(type)
    {
        case(0): {
            if(y-resolution[0]/2<0&&typeOfScroll==0){
                return 0;
            } else if(typeOfScroll==0){
                return y-resolution[0]/2;
            }
            if(y+resolution[0]/2>mapSize[0]&&typeOfScroll==1){
                return mapSize[0];
            } else if(typeOfScroll==1){
                return y+resolution[0]/2;
            }

        }
        case(1): {
            if(x-resolution[1]/2<0&&typeOfScroll==0){
                return 0;
            } else if(typeOfScroll==0){
                return x-resolution[1]/2;
            }
            if(x+resolution[1]/2>mapSize[1]&&typeOfScroll==1){
                return mapSize[1];
            } else if(typeOfScroll==1){
                return x+resolution[1]/2;
            }

        }
    }
}
void Controller(){
    string correct;
    std::cin>>correct;

    //return 0;
    if(correct=="w"&&y>0&&map[y-1][x]=='.'){
        map[y][x]='.';
        y-=1;
        map[y][x]='P';
    }
    if(correct=="s"&&y<mapSize[1]-1&&map[y+1][x]=='.'){
        map[y][x]='.';
        y+=1;
        map[y][x]='P';
    }
    if(correct=="a"&&map[y][x-1]=='.'&&x>0){
        map[y][x]='.';
        x-=1;
        map[y][x]='P';
    }
    if(correct=="d"&&map[y][x+1]=='.'&&x+1<mapSize[0]){
        map[y][x]='.';
        x+=1;
        map[y][x]='P';
    }
}

int main(){
    Menu();
    while(1){
        system("cls"); 
        //std::cout<<x/*<<" "<<y<<"\n"*/;
        for(int16_t i=SetResolution(0,0); i<SetResolution(0,1); i+=1){
            for(int16_t z=SetResolution(1,0); z<SetResolution(1,1); z+=1){
                std::cout<<map[i][z];
                map[y][x]='P';
            }
            std::cout<<"\n";
        }
        std::cout<<"\n x: "<<x<<"  y: "<<y<<"\n";
        Controller();
    }
    return 0;
}