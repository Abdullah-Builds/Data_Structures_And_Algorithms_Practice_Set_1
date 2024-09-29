#include<iostream>
using namespace std;

void BubbLe_SORT(int *arr, int n){
	
	for(int i=0; i<n; i++){
		for( int j=i+1; j<n; j++){
			if( arr[i] > arr[j]){
				int temporary = arr[i];
				arr[i] = arr[j];
				arr[j] = temporary;
			}
		}
	}
}
void print(int arr[], int n){
	
	for(int i=0; i<6; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	
	int arr[6] = {9,6,1,2,10,-1};
	
	cout << "Before Sorting : " << endl;
	print(arr,6);
	
	BubbLe_SORT(arr,6);
	
	cout << "After Sorting : " << endl;
	print(arr,6);
}
