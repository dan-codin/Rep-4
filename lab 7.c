#include<stdio.h>
#include<stdlib.h>

//glabal 2D arrays to hold array values and the number of time each value is swap
int arrayOne2D[9][2], arrayTwo2D[9][2];

//total number of swap operations
int totalNumOfSwaps = 0;

//function to increment count whenever an element is swapped
void numSwapCount(int array2D[9][2], int n, int x, int y){


    for( int i = 0; i < n - 1; i++){
            if(array2D[i][0] == x){
                array2D[i][1] += 1;

            }
            if(array2D[i][0] == y){
                array2D[i][1]+= 1;

            }
            
    }
}

//function to perform bubble sort
int* bubbleSort(int arr[], int arr2D [9][2], int n){
    //int variables i and j for counters and temp to temporay hold the value at the array index being sorted
    // int totalSwaps keeps a tally on the number of swaps
    int i, j, temp;

    //for loop to traverse array
    for(i = 0; i < n-1; i++){

        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                //perform swap
                numSwapCount(arr2D, n, arr[j],arr[j+1]);
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                //increment total number of swap operations
                totalNumOfSwaps+=1;
            }

        }

    }
        return arr;

}
 //fuction to display sorted array and the number of swaps
void printArray(int arr[], int arr2D[9][2], int n ){
    for(int i = 0; i < n; i++){
        printf("%d : ",arr[i]);
        for(int j = 0; j < n; j++){
            if(arr2D[j][0]== arr[i]){
        
                printf("%d\n", arr2D[j][1]);
             }
        }

    }
    printf("total # of swaps: %d\n", totalNumOfSwaps);
    totalNumOfSwaps = 0;

}

int* selectionSort(int arr [], int arr2D [9][2], int n){

    int i, j, min_index, temp;

    //move the boundary of unsorted array
    for(i=0; i < n-1; i++){
        //minimum element
        min_index = i;
        for( j = i+1; j<n; j++){
            if(arr[j]< arr[min_index]){
                min_index = j;
            //swap the minimum with first element
                temp = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = temp;
                numSwapCount(arr2D, n, arr[i], arr[min_index]);
                totalNumOfSwaps++;
            }
        }
    }

    return arr;
}
//entry to the program
void main(){
    int array1[]= {97,  16,  45,  63,  13,  22,  7,  58,  72};
    int array2[] ={90,  80,  70,  60,  50,  40,  30,  20,  10};

    
    for(int i =0; i < 9; i++){
            arrayOne2D[i][0] = array1[i];
            arrayOne2D[i][1] = 0;
            arrayTwo2D[i][0] = array2[i];
            arrayTwo2D[i][1] = 0;
        
    };

    bubbleSort(array1, arrayOne2D, 9);
    printf("array1:\n");
    printArray(array1,arrayOne2D, 9);

    bubbleSort(array2,arrayTwo2D, 9);
    printf("\n\narray2:\n");
    printArray(array2, arrayTwo2D, 9);

    totalNumOfSwaps = 0;

    array1 [0] = 97;
    array1 [1] = 16;
    array1 [2] = 45;
    array1 [3] = 63;
    array1 [4] = 13;
    array1 [5] = 22;
    array1 [6] = 7;
    array1 [7] = 58;
    array1 [8] = 72;

    array2 [0] = 90;
    array2 [1] = 80;
    array2 [2] = 70;
    array2 [3] = 60;
    array2 [4] = 50;
    array2 [5] = 40;
    array2 [6] = 30;
    array2 [7] = 20;
    array2 [8] = 10;
    
    for(int i =0; i < 9; i++){
            arrayOne2D[i][0] = array1[i];
            arrayOne2D[i][1] = 0;
            arrayTwo2D[i][0] = array2[i];
            arrayTwo2D[i][1] = 0;
        
    };

    selectionSort(array1, arrayOne2D, 9);
    printf("\nSelection Sort:\n");
    printf("array1:\n");
    printArray(array1,arrayOne2D, 9);

    selectionSort(array2,arrayTwo2D, 9);
    printf("\n\narray2:\n");
    printArray(array2, arrayTwo2D, 9);

}