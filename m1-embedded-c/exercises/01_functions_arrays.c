#include <stdio.h>

int sum_array(int array[], int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=array[i];
    }
    return sum;
}

int find_max(int array[], int size){
    int max = array[0];
    for (int i=1;i<size;i++){
        if (array[i]>max){
            max = array[i];
        }
    }
    return max;
}

int main(){
    printf("Hello Embedded C\n");

    int array[4]={5, 10, 15, 20};
    int sum=sum_array(array, 4);
    printf("Sum: %d\n",sum);

    int array2[5]={7,3,12,5,9};
    printf("Max: %d\n",find_max(array2,5));

    return 0;
}