#include <iostream>

using namespace std;

void buble_sort(int input_array[], int array_size);
void selection_sort(int input_array[], int array_size);
void insertion_sort(int input_array[], int array_size);

int main(){
//    int my_array[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    int my_array[] = {9,8,7,6,5,4,3,2,1,0};
//    int my_array[] = {9,8,7,6,5,0,1,2,3,4};
//    int my_array[] = {0,1,2,3,4,5,6,7,8,9};
    int size_of_my_array = *(&my_array + 1) - my_array;

    for (int idx = 0; idx < size_of_my_array; ++ idx){
        cout<<my_array[idx]<<" ";
    }
    cout<<"\n";

   //buble_sort(my_array, size_of_my_array);
   //selection_sort(my_array, size_of_my_array);
   insertion_sort(my_array, size_of_my_array);

    return 0;

}

void buble_sort(int input_array[], int array_size){

    for (int idx = 0; idx < array_size - 1; ++idx){
        // loop for the number of passes. e.g. 1st pass, 2nd pass..
        // minimum number of passes = len - 1
        // cout<<input_array[idx]<<" ";
        for (int jdx = 0; jdx < (array_size - 1 - idx); ++jdx){
            // loop for number of comparison per pass
            int temp;
            if (input_array[jdx] > input_array[jdx+1] ){
                temp = input_array[jdx+1];
                input_array[jdx+1] = input_array[jdx];
                input_array[jdx] = temp;
            }
        for (int idx = 0; idx < array_size; ++idx){
            cout<<input_array[idx]<<" ";
        }
        cout<<"\n";
        }
    }
    cout<<"\n"<<array_size;
}

void selection_sort(int input_array[], int array_size){
    int current, current_index, temp;
    for (int idx = 0; idx < array_size; ++idx){
        current = current_index = temp = 0;
        // loop for number of passes
        // 1st pass, 2nd pass, ...

        for (int jdx = 0; jdx < array_size - idx; ++jdx){
            if (input_array[jdx] > current){
                current = input_array[jdx];
                current_index = jdx;
            }
        }
        temp = input_array[array_size - 1 - idx];   // get the last value of the array
        input_array[array_size - 1 - idx] = current; // replace it with the current largest found
        input_array[current_index] = temp;             // reinsert back the last value

        for (int kdx = 0; kdx < array_size; ++kdx){
            cout<<input_array[kdx]<<" ";
        }
    cout<<"\n";
    }
}

void insertion_sort(int input_array[], int array_size){
    for(int idx = 1; idx < array_size; ++idx){
        int current = input_array[idx];
        int current_index = idx;
        int increment = 0;

        while((input_array[idx-1-increment]>current) && (idx-1-increment>=0)){
                input_array[idx-increment]=input_array[idx-1-increment];
                ++increment;
              }
        input_array[idx-1-increment+1]=current;  // +1 is for shifting back to previous position
    }
        for (int kdx = 0; kdx < array_size; ++kdx){
            cout<<input_array[kdx]<<" ";
        }
    cout<<"\n";
    }

