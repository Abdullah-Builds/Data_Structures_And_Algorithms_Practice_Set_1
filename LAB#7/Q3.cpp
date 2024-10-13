#include<iostream>
using namespace std;

void Merge_Ascending( int* arr, int s, int e, int mid){
	int len1 = mid - s + 1;
	int len2 = e - mid;
	
	int* temp1 = new int [len1];
	int* temp2 = new int [len2];
	int k = s;
	
	for( int i=0; i<len1; i++){
		temp1[i] = arr[k++];
	}
	for( int i=0; i<len2; i++){
		temp2[i] = arr[k++];
	}
	
	int index1 = 0;
	int index2 = 0;
	k = s;
	
	while( index1 < len1 && index2 < len2 ){
		if( temp1[index1] < temp2[index2] ){
			arr[k++] = temp1[index1++];
		}
		else{
			arr[k++] = temp2[index2++];
		}
	}
	
	while( index1 < len1 ){
		arr[k++] = temp1[index1++];
	}
	while( index2 < len2 ){
		arr[k++] = temp2[index2++];
	}  
	
	delete[]temp1;
	delete[]temp2; 	
}


void Merge_Descending( int* arr, int s, int e, int mid){
	int len1 = mid - s + 1;
	int len2 = e - mid;
	
	int* temp1 = new int [len1];
	int* temp2 = new int [len2];
	int k = s;
	
	for( int i=0; i<len1; i++){
		temp1[i] = arr[k++];
	}
	for( int i=0; i<len2; i++){
		temp2[i] = arr[k++];
	}
	
	int index1 = 0;
	int index2 = 0;
	k = s;
	
	while( index1 < len1 && index2 < len2 ){
		if( temp1[index1] > temp2[index2] ){
			arr[k++] = temp1[index1++];
		}
		else{
			arr[k++] = temp2[index2++];
		}
	}
	
	while( index1 < len1 ){
		arr[k++] = temp1[index1++];
	}
	while( index2 < len2 ){
		arr[k++] = temp2[index2++];
	}	
	
	delete[]temp1;
	delete[]temp2;
}

void Merge_Sort_Ascending( int* arr, int s, int e){
	
	if( s >= e ) return;
	
	int mid = s + ( e-s )/2;
	Merge_Sort_Ascending( arr, s, mid );
	Merge_Sort_Ascending( arr, mid + 1, e );
	Merge_Ascending( arr, s, e, mid );	
}

void Merge_Sort_Descending( int* arr, int s, int e){
	
	if( s >= e ) return;
	
	int mid = s + ( e-s )/2;
	Merge_Sort_Descending( arr, s, mid );
	Merge_Sort_Descending( arr, mid + 1, e );
	Merge_Descending( arr, s, e, mid );	
}

int* Sort_Array_In_Ascending( int* arr, int n ){
	int *arr1 = new int [n];
	for(int i=0; i<n; i++){
		arr1[i] = arr[i];
	}
	Merge_Sort_Ascending( arr1, 0, n-1 );
	return arr1;
}
int* Sort_Array_In_Descending( int* arr, int n ){
	int *arr1 = new int [n];
	for(int i=0; i<n; i++){
		arr1[i] = arr[i];
	}
	Merge_Sort_Descending( arr1, 0, n-1 );
	return arr1;
}

int main(){
	int arr[10] = {9,2,3,5,7,1,8,0,6,4};
	int n = 10;
	
	int* Ascending123 = Sort_Array_In_Ascending( arr, n );
    int* Descending123 = Sort_Array_In_Descending( arr, n );	
    
    cout  << "Ascending : " << " ";
    for(int i=0; i<n; i++){
    	cout << Ascending123[i] << " ";
	}
	
	cout << endl << "Descending : " << " ";
	for(int i=0; i<n; i++){
    	cout << Descending123[i] << " ";
	}
}
