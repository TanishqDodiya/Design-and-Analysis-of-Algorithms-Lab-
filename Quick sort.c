#include<stdio.h>
void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int par(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}
void quickSort(int arr[],int low,int high,int pass){
	if(low<high){
		int pi=par(arr,low,high);
		printf("Pass: ");
		for(int i=low;i<=high;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
		pass++;
		quickSort(arr,low,pi-1,pass);
		quickSort(arr,pi+1,high,pass);
	}
}
int main(){
	int arr[50],n;
	printf("number of elements: ");
	scanf("%d ",&n);
	printf("elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n");
	printf("Original array: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	quickSort(arr,0,n-1,1);
	printf("Sorted array: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

