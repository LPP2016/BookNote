#include <stdio.h>
#include <stdlib.h>
#define LEN 100
int *p;			// 数据指针
int main()
{
	/* 分配内存 */
	p = (int*)malloc(LEN * sizeof(int));
	if (p==NULL)
	{
		fprintf(stderr, "cannot allocate memory for pointer!\r\n");
		exit(1);
	}
	int i;
	/* kernel */
	for (i=0;i<LEN;++i)p[i]=i;
	/* 显示输出 */
	for (i=0;i<LEN;++i)printf("%d\t",p[i]);
	printf("\r\n");
	/* 释放内存 */
	free(p);
	/* 退出程序 */
	exit(0);
}