#include <iostream>
#include <chrono>
#include "backtracking.h"
#include "bruteforce.h"
#include "meet_in_the_middle.h"
#include "dynamic_programming.h"
#include "experiments/backtracking_poda_optimalidad.h"
#include "experiments/backtracking_poda_factibilidad.h"
#include "experiments/backtracking_sin_poda.h"

void printResult(unsigned long value, string text) {
    cout<<text;
    cout<< "\t" << value <<", ";
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
    printResult(meet_in_the_middle(15, items), "Meet: ");
    printResult(backtracking(15, items), "Backtracking: ");
    printResult(backtrackingSinPoda(15, items), "Backtracking sin poda: ");
    printResult(backtrackingPodaFactibilidad(15, items), "Backtracking factibilidad: ");
    printResult(backtrackingPodaOptimalidad(15, items), "Backtracking optimalidad: ");
    printResult(dynamicProgramming(15, items), "Dinámica: ");
    cout<<endl;
}

void test2() {
    Item item1 = Item(10, 3);
    Item item2 = Item(10, 4);
    Item item3 = Item(100, 1);
    Item item4 = Item(20, 10);
    Item item5 = Item(15, 5);

    vector<Item> items = {item1, item2, item3, item4, item5};
    cout<<"Test2. Valor Correcto: 135"<<endl;

    printResult(bruteforce(15, items), "Bruteforce: ");
    printResult(meet_in_the_middle(15, items), "Meet: ");
    printResult(backtracking(15, items), "Backtracking: ");
    printResult(backtrackingSinPoda(15, items), "Backtracking sin poda: ");
    printResult(backtrackingPodaFactibilidad(15, items), "Backtracking factibilidad: ");
    printResult(backtrackingPodaOptimalidad(15, items), "Backtracking optimalidad: ");
    printResult(dynamicProgramming(15, items), "Dinámica: ");
    cout<<endl;
}

void test3(){
    Item item1 = Item(5, 10);
    Item item2 = Item(4, 15);
    Item item3 = Item(13, 5);
    Item item4 = Item(8, 10);
    Item item5 = Item(8, 5);

    vector<Item> items = {item1, item2, item3, item4, item5};
    cout<<"Test3. Valor Correcto: 29"<<endl;

    printResult(bruteforce(25, items), "Bruteforce: ");
    printResult(meet_in_the_middle(25, items), "Meet: ");
    printResult(backtracking(25, items), "Backtracking: ");
    printResult(backtrackingSinPoda(25, items), "Backtracking sin poda: ");
    printResult(backtrackingPodaFactibilidad(25, items), "Backtracking factibilidad: ");
    printResult(backtrackingPodaOptimalidad(25, items), "Backtracking optimalidad: ");
    printResult(dynamicProgramming(25, items), "Dinámica: ");
    cout<<endl;
}

void test4(){
    Item item1 = Item(5, 10);
    Item item2 = Item(4, 15);
    Item item3 = Item(13, 5);
    Item item4 = Item(8, 10);
    Item item5 = Item(8, 5);
    Item item6 = Item(5, 25);

    vector<Item> items = {item1, item2, item3, item4, item5, item6};
    cout<<"Test4. Valor Correcto: 29"<<endl;

    printResult(bruteforce(25, items), "Bruteforce: ");
    printResult(meet_in_the_middle(25, items), "Meet: ");
    printResult(backtracking(25, items), "Backtracking: ");
    printResult(backtrackingSinPoda(25, items), "Backtracking sin poda: ");
    printResult(backtrackingPodaFactibilidad(25, items), "Backtracking factibilidad: ");
    printResult(backtrackingPodaOptimalidad(25, items), "Backtracking optimalidad: ");
    printResult(dynamicProgramming(25, items), "Dinámica: ");
    cout<<endl;
}

void test5(){
    Item item3 = Item(13, 5);
    Item item4 = Item(8, 10);
    Item item5 = Item(8, 5);

    vector<Item> items = {item3, item4, item5};
    cout<<"Test5. Valor Correcto: 29"<<endl;

    printResult(bruteforce(25, items), "Bruteforce: ");
    printResult(meet_in_the_middle(25, items), "Meet: ");
    printResult(backtracking(25, items), "Backtracking: ");
    printResult(backtrackingSinPoda(25, items), "Backtracking sin poda: ");
    printResult(backtrackingPodaFactibilidad(25, items), "Backtracking factibilidad: ");
    printResult(backtrackingPodaOptimalidad(25, items), "Backtracking optimalidad: ");
    printResult(dynamicProgramming(25, items), "Dinámica: ");
    cout<<endl;
}


int main(){
    test1();
    test2();
    test3();
    test4();
    test5();

    return 1;
}