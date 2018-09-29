
#include <iostream>

using namespace std;

int main() {

    int array[30] = {79, 81,  69,  82,  22,  85,  15,  70,  95,  15,  34 , 71 , 6 ,  91 , 8  , 7 ,  89  ,54 , 45  ,92 , 13  ,17 , 77  ,53 , 27 , 58 , 40 , 37  ,76 , 34};
    int tmp;
    int j;

    for(int k=15; k > 0; k/=2){
        for(int i=k;i<30;i++){
            tmp = array[i];
            for (j = i; j >= k && array[j-k] > tmp; j-=k){
                array[j] = array[j-k];
            } 
            array[j] = tmp;
        }
    }

    for (int z=0; z<30; z++){
        cout << array[z] << ' ';
    }
    cout << '\n';

}