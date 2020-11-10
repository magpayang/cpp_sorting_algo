#include <iostream>

using namespace std;

void buble_sort(int input_array[], int array_size);
void selection_sort(int input_array[], int array_size);
void insertion_sort(int input_array[], int array_size);
void Shell_sort(int input_array[], int array_size);
void SplitArray(int input_array[], int size_of_array, int start_idx, int end_idx);

int * merge_func(int * input_array, int array_size, int first_idx, int midpoint_idx, int last_idx);
int * merge_sort(int * input_array, int array_size, int first_idx, int last_idx);
void printArray(int * input_array, int array_size);

int main(){
    cout << "-- Original Array --" << endl;
//    int my_array[] = {9,8,7,6,5,4,3,2,1,0};
//    int my_array[] = {5,3,1,0};
    int my_array[] = {9,9,9,5,4,3,2,1,3,4,3,2,1,3,4,5,6,7,8,9,9,7,6,5,4,6,6,6,0,0,0,4,3,2,2,5,6,7,8,9,7,6,5,4,3,3,0,0,3,3,2,3,4,3,2,4,5,6,7,8,9,0,8,8,9,0,9};
    int array_size = *(&my_array + 1) - my_array;
    printArray(my_array, array_size);

    cout<<"\n-- Sorting --\n";
    insertion_sort(my_array, array_size);

//    cout<<"-- Sorted Array --\n";
//    printArray(my_array, array_size);
//    cout<<endl;

    int my_array2[] = {9,9,9,5,4,3,2,1,3,4,3,2,1,3,4,5,6,7,8,9,9,7,6,5,4,6,6,6,0,0,0,4,3,2,2,5,6,7,8,9,7,6,5,4,3,3,0,0,3,3,2,3,4,3,2,4,5,6,7,8,9,0,8,8,9,0,9};

    cout<<"\n-- Sorting --\n";
    merge_sort(my_array2, array_size, 0, array_size-1);

//    cout<<"-- Sorted Array --\n";
//    printArray(my_array2, array_size);
//    cout<<endl;

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
        printArray(input_array, array_size);
        cout<<"\n";
    }

    cout<<"\n";
    }

void Shell_sort(int input_array[], int array_size){  // general form of insertion sort
    int gaps[] = {63,33,17,9,5,3,1};  // https://en.wikipedia.org/wiki/Thomas_N._Hibbard
    int gaps_size = *(&gaps+1)-gaps;
    for (int jdx = 0; jdx<gaps_size; ++jdx){ // loop through gap array
        int gap = gaps[jdx];

        for(int idx = gap; idx<array_size; ++idx){ // loop through the array
            int current = input_array[idx];
            int current_index = idx;
            int increment=0;

            while((idx-gap-increment>=0)&&(input_array[idx - gap -increment] > current)){
                    input_array[idx-increment] = input_array[idx-gap-increment];
                    increment += gap;
            }
            input_array[idx-gap-increment+gap] = current;
        }
    }

    for (int kdx = 0; kdx < array_size; ++kdx){
        cout<<input_array[kdx]<<" ";
    }
    cout<<"\n";
}

int * merge_func(int * input_array, int array_size, int first_idx, int midpoint_idx, int last_idx){
    int length_left_array = midpoint_idx - first_idx + 1; // at base case, midpoint_idx = first_idx. add 1 to allow space for array
    int length_right_array = last_idx - midpoint_idx;

    int left_array[length_left_array];
    int right_array[length_right_array];

    for (int i = 0; i < length_left_array; ++i){
        left_array[i] = input_array[first_idx + i];
    }
    for (int i = 0; i < length_right_array; ++i){
        right_array[i] = input_array[midpoint_idx + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = first_idx;

    while(i < length_left_array && j < length_right_array){
//        cout<<"k: "<<k<<" i: "<<i<<" j: "<<j<<"\n";
        if (left_array[i] <= right_array[j]){

            input_array[k] = left_array[i];
            ++i;
        }
        else {

            input_array[k] = right_array[j];
            ++j;
        }
        ++k;
    }

    while( i < length_left_array ){
        input_array[k] = left_array[i];
        i++;
        k++;
    }

    while( j < length_right_array ){
        input_array[k] = right_array[j];
        j++;
        k++;
    }
    printArray(input_array, array_size);
    cout<<"\n";
}

int * merge_sort(int * input_array, int array_size, int first_idx, int last_idx){
    if (first_idx < last_idx){ // for as long as first_idx does not equal to last_idx, were fine
        int midpoint_idx = (first_idx + last_idx)/2; // floor division.
        // left_array[] = {items from first_idx to midpoint_idx}. right_array[] = {items from midpoint_idx + 1 to last_index]}
        merge_sort(input_array, array_size, first_idx, midpoint_idx);
        merge_sort(input_array, array_size, midpoint_idx + 1, last_idx);
        merge_func(input_array, array_size, first_idx, midpoint_idx,last_idx);
    }
}

void printArray(int * input_array, int array_size){
    for (int i = 0; i < array_size; ++i){
        cout<<input_array[i]<<" ";
    }
}

void printArray2(int * input_array, int array_size){
    for (int i = 0; i < array_size; ++i){
        if (input_array[i] == 9){
            cout<<"+"<<" ";
        }
        else{
            cout<<" "<<" ";
        }
    }
}

void SplitArray(int input_array[], int size_of_array, int start_idx, int end_idx){
    int new_array[end_idx - start_idx];

    for (int idx = 0; idx<(end_idx-start_idx); ++idx){
        new_array[idx] = input_array[idx];
    }

    cout<<"New array \n";
    for (int idx = 0; idx < (end_idx-start_idx); ++ idx){
        cout<<new_array[idx]<<" ";
    }
    cout<<"\n";
}


