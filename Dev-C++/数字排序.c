#include<stdio.h>
void jianDan(int a[],int n)//���� 
{
	int i,j;
	int tip;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				tip=a[i];
				a[i]=a[j];
				a[j]=tip;
			}
}
void maoPao(int a[],int n)//���� 
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(a[j]<a[j+1])
			{
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
			}
}
int main()
{
	int a[99];
	int i=0;
	int j;
	int n;
	printf("����������:\n");
	while(scanf("%d",&a[i])==1)
	{
		if(getchar()=='\n')
		break;
		i++;
	}
	printf("[1]���� [2]����\n[ ]\b\b");
	scanf("%d",&n);
	if(n==1)
	jianDan(a,i+1);//��ѡ������
	else if(n==2)
	maoPao(a,i+1);//ð������ 
	printf("�����:\n");
	for(j=0;j<i+1;j++)
		printf("%5d ",a[j]);
	return 0;
}
