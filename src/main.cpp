#include <iostream>
#include "backtracking.h"
#include "bruteforce.h"
#include "meet_in_the_middle.h"

int main(){

    item item1; item item2; item item3; item item4; item item5; item itemA; item itemB; item item6;
    itemA.size = 15; itemA.value = 2;
    itemB.size = 15; itemB.value = 3;
    item1.size = 3; item1.value = 10;
    item2.size = 4; item2.value = 10;
    item3.size = 1; item3.value = 100;
    item4.size = 10; item4.value = 20;
    item5.size = 5; item5.value = 15;
    item6.size = 5; item6.value = 1;

    vector<item> items = {item1, item2, item3, item4, item5};

    backpack bkp1 = solveA(15, items);
    cout<<"Bruteforce: "<<endl;
    cout<<bkp1.value<<endl;
    cout<<bkp1.load<<endl;

    backpack bkp2 = solveB(15, items);
    cout<<"Meet in the middle: "<<endl;
    cout<<bkp2.value<<endl;
    cout<<bkp2.load<<endl;

    backpack bkp3 = solveC(15, items);
    cout<<"Backtracking: "<<endl;
    cout<<bkp3.value<<endl;
    cout<<bkp3.load<<endl;




    return 1;
}