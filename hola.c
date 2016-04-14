#include <stdio.h>
#include <stdlib.h>

int main(){
	/*int a[3] = { 5,8,1 };
	int *p,*q;
	int i;
	p = a;
	q = &a[1];
	q++;
	q=&a[2];
	printf("p= %d\n, &a= %p\n, q=%d\n, q2=%d\n",*p,&a,*q,(*q+1));
	return 0;
}*/
	char *p;
	int n=5;
	p=(char *)malloc(n+1);
	int i;
	int largo=4;
	char arreglo[4]={'h','o','l','a'};
	for (i=0;i<largo;i++){
		p=&arreglo[i];
		printf("%c\n",(*p));
		p++;
	}
	*p='\0';
	printf("%c\n",*p);
	free((char*)p);
	return 0;
}
