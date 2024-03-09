#include <iostream>
#include <string>

void printMap(){
    for(uint16_t z=0; z<sizeof(map)/sizeof(map[0])+1; z++){
        for(uint16_t i=0; i<sizeof(map)/sizeof(map[0])+1; i++){
            std::cout<<map[z][i];
        }
        std::cout<<"\n";
    }
}
void Menu(){
    uint16_t switched=0;
    int8_t inMenu=1;
    while(inMenu>0){
        system("cls");
        printf("Enter a number to select:  \n");
        printf("Play [0] \n");
        printf("Settings [1] \n");
        std::cin>>switched;
        if(switched==0){
            system("cls");
            inMenu=0;
        }
        if(switched==1){
            system("cls");
            printf("Resolution of render: \n");
            std::cout<<resolution[0]<<" * "<<resolution[1]<<" symbols \n";
            printf("If you want to change, enter 1. \n");
            printf("If you want to exit, enter 0. \n");
            while(1){
                int16_t change;
                std::cin>>change;
                if(change==0){
                    break;
                }
                if(change==1){
                    printf("Enter the horizontal(X-) resolution: \n");
                    std::cin>>resolution[1];
                    printf("Enter the vertical(Y|) resolution: \n");
                    std::cin>>resolution[0];
                    break;
                }
            }
            inMenu=2;
        }
        

    }
}
void history(){
    uint8_t null;
    printf("LONODON **42 YEAR  \n");
    printf("----------------------- \n----------_______------ \n---------|------|------ \n---------|#----#|------ \n----_____|#----#|------ \n---|-----|#----#|------ \n---|-----|------|------ \n");
    printf("Press 'Enter' to skip:  \n");
    std::cin>>null;
    printf("LONODON **42 YEAR  \n");
    printf(" \n");
    printf("Press 'Enter' to skip:  \n");
    std::cin>>null;
}