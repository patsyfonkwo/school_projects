#include "unordered_list.h"

//int main(int argc, char * argv[])
//{
//    const char * input_file = argc == 2 ? argv[1] : "random.txt";
//    measure_lists(input_file);
//    return 0;
//}

#include <iostream>
#include "Timer.h"
int main(){
    
    int x = 10;
    UnorderedArrayList alist = UnorderedArrayList(x);
    cout << alist.name << endl;
    
    Timer t;
    double eTime;
    t.start();
    for (int i=0, j; i<1000000000; i++)
        j++;
    t.elapsedUserTime(eTime);
    cout << eTime << endl;
    return 0;

    return 0;
}
