#include<stdio.h>
void read1(int a[],int n){
	printf("Enter %d elements : ",n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		
	}
}

int linearSearch(int a[],int st,int end,int key)
{
	if(st>end){
		return -1;
	
	}
	if (st>end){
		return -1;
	}
	if(a[st]==key){
		return st;
	}else{
		st+=1;
		return linearSearch(a,st,end,key);

	}
}
