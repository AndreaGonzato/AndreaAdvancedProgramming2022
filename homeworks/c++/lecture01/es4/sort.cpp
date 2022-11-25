#include<iostream>

void swap(int array[], int index1, int index2){
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;    
}

void bubbleSort(int array[], int size){
    std::cout<<size<<std::endl;
    for (int i = 0; i < size-1; i++){
        for (int j = i+1; j < size; j++){
            if(array[j] < array[i]){
                swap(array, j, i);
            }

        }
        
    }
}

int main(){
    std::cout<<"How many element you want to sort?"<<std::endl;
    int size;
    std::cin>>size;
    int array[size];

    std::cout<<"Enter all the elements"<<std::endl;
    for (int i = 0; i < size; i++){
        std::cin>>array[i];
    }


    // sort 
    bubbleSort(array, size);

    //print
    for (int i = 0; i < size; i++)
    {
        std::cout<<array[i]<<" ";
    }


    std::cout<<" "<<std::endl;

    
    return 0;
}