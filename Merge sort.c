#include<stdio.h>
void display(int arr[20],int n);
void split(int arr[20],int low,int high);
void merge(int arr[20],int low,int mid,int high);

void display(int arr[20],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void split(int arr[20],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		split(arr,low,mid);
		split(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
void merge(int arr[20],int low,int mid,int high){
	int i=low,h=low,j=mid+1,k,temp[20];
	while(h<=mid && j<=high){
		if(arr[h]<=arr[j]){
			temp[i++]=arr[h++];
		}
		else{
			temp[i++]=arr[j++];
		}
	}
	while(h<=mid){
		temp[i++]=arr[h++];
	}
	while(j<=high){
		temp[i++]=arr[j++];
	}
	for(k=low;k<=high;k++){
		arr[k]=temp[k];
	}
	printf("Pass: ");
	for(k=low;k<=high;k++){
		printf("%d ",arr[k]);
	}
	printf("\n");
}
void main(){
	int arr[20],i,n;
	printf("no of elements: ");
	scanf("%d",&n);
	printf("elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Given array:\n");
	display(arr,n);
	split(arr,0,n-1);
	printf("Sorted array:\n");
	display(arr,n);
}
