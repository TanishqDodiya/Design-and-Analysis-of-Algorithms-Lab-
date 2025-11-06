#include<stdio.h>
int i;
void read1(int a[],int n){
	printf("Enter %d elements : ",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void bubbleSort(int a[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void display(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int binarySearch(int a[i],int low,int high,int key){
	int mid;
	while(low<=high){
		mid = (low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(key < a[mid])
			high = mid-1;
		else
			low=mid+1;
	}
	return -1;
}
