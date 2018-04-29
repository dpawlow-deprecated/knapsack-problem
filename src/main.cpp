#include <iostream>
#include <chrono>
#include "backtracking.h"
#include "bruteforce.h"
#include "meet_in_the_middle.h"
#include "dynamic_programming.h"

void printResult(unsigned long value, string text) {
    cout<<text;
    cout<<"Value: "<<value<<", ";
    cout<<endl;
}

void test1() {
    Item item1 = Item(10, 3);
    Item item2 = Item(10, 4);
    Item item3 = Item(100, 1);
    Item item4 = Item(20, 10);
    Item item5 = Item(15, 5);
    Item item6 = Item(1, 5);
    Item itemA = Item(2, 15);
    Item itemB = Item(3, 15);

    vector<Item> items = {itemA, item1, item2, item3, item4, item5, item6, itemB};
    cout<<"Test1. Valor Correcto: 135"<<endl;

    printResult(bruteforce(15, items), "Bruteforce: ");
    printResult(meet_in_the_middle(15, items), "Meet in the middle: ");
    printResult(backtracking(15, items), "Backtracking: ");

    cout << "Dinámica: " << dynamicProgramming(15, items) << endl;
}

void test2() {
    Item item1 = Item(10, 3);
    Item item2 = Item(10, 4);
    Item item3 = Item(100, 1);
    Item item4 = Item(20, 10);
    Item item5 = Item(15, 5);

    vector<Item> items = {item1, item2, item3, item5};
    cout<<"Test2. Valor Correcto: 135"<<endl;

    printResult(bruteforce(15, items), "Bruteforce: ");
    printResult(meet_in_the_middle(15, items), "Meet in the middle: ");
    printResult(backtracking(15, items), "Backtracking: ");

    cout << "Dinámica: " << dynamicProgramming(15, items) << endl;

}

void test3(){
    Item item1 = Item(5, 10);
    Item item2 = Item(4, 15);
    Item item3 = Item(13, 5);
    Item item4 = Item(8, 10);
    Item item5 = Item(8, 5);

    vector<Item> items = {item1, item2, item3, item4, item5};
    cout<<"Test3. Valor Correcto: 29"<<endl;

    cout << "Bruteforce: " << bruteforce(25, items) << endl;
    cout << "Meet in the middle: " << meet_in_the_middle(25, items) << endl;
    cout << "Backtracking: " << backtracking(25, items) << endl;
    cout << "Dinámica: " << dynamicProgramming(25, items) << endl;
}

int main(){
    test1();
    test2();
    test3();

    return 1;
}