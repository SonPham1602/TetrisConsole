#include<stdio.h>  
#include<conio.h>  

void main()  
{  
	int a[10],n,i;  

	printf("Nhap mot so bat ky: ");  
	scanf("%d",&n);  
	for(i=0;n>0;i++)  
	{  
		a[i]=n%2;  
		n=n/2;  
	}  
	printf("\nDang nhi phan cua so vua nhap la = ");  
	for(i=i-1;i>=0;i--)  
	{  
		printf("%d",a[i]);  
	}  

	printf("\n\n===========================\n");
	printf("VietJack chuc cac ban hoc tot!");
	getch();  
}  