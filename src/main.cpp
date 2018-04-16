#include <iostream>
#include <chrono>
#include "backtracking.h"
#include "bruteforce.h"
#include "meet_in_the_middle.h"
#include "dynamic_programming.h"

#include "experiments/compare_backtracking.h"
#include "experiments/compare_algorithms.h"

void printResult(int value, string text) {
    cout<<text;
    cout<<"Value: "<<value<<", ";
    cout<<endl;
}

void test1() {
    item item1; item item2; item item3; item item4; item item5; item itemA; item itemB; item item6;
    itemA.size = 15; itemA.value = 2;
    itemB.size = 15; itemB.value = 3;
    item1.size = 3; item1.value = 10;
    item2.size = 4; item2.value = 10;
    item3.size = 1; item3.value = 100;
    item4.size = 10; item4.value = 20;
    item5.size = 5; item5.value = 15;
    item6.size = 5; item6.value = 1;

    vector<item> items = {itemA, item1, item2, item3, item4, item5, item6, itemB};
    cout<<"Test1. Valor Correcto: 135"<<endl;

    printResult(bruteforce(15, items), "Bruteforce: ");
    printResult(meet_in_the_middle(15, items), "Meet in the middle: ");
    printResult(backtracking(15, items), "Backtracking: ");

    cout << "Dinámica: " << dynamicProgramming(15, items) << endl;
}

void test2() {
    item item1; item item2; item item3; item item5;
    item1.size = 3; item1.value = 10;
    item2.size = 4; item2.value = 10;
    item3.size = 1; item3.value = 100;
    item5.size = 5; item5.value = 15;

    vector<item> items = {item1, item2, item3, item5};
    cout<<"Test2. Valor Correcto: 135"<<endl;

    printResult(bruteforce(15, items), "Bruteforce: ");
    printResult(meet_in_the_middle(15, items), "Meet in the middle: ");
    printResult(backtracking(15, items), "Backtracking: ");

    cout << "Dinámica: " << dynamicProgramming(15, items) << endl;

}

void test3(){
    item item1; item item2; item item3; item item4; item item5;
    item1.size = 10; item1.value = 5;
    item2.size = 15; item2.value = 4;
    item3.size = 5; item3.value = 13;
    item4.size = 10; item4.value = 8;
    item5.size = 5; item5.value = 8;

    vector<item> items = {item1, item2, item3, item4, item5};
    cout<<"Test3. Valor Correcto: 29"<<endl;

    cout << "Bruteforce: " << bruteforce(25, items) << endl;
    cout << "Meet in the middle: " << meet_in_the_middle(25, items) << endl;
    cout << "Backtracking: " << backtracking(25, items) << endl;
    cout << "Dinámica: " << dynamicProgramming(25, items) << endl;
}

int main(){
    test3();

    return 1;
}