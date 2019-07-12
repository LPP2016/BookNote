#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define LEN 100
int *p;			// 数据指针
int main(int argc, char **argv)
{
	int size;		// MPI进程个数
	int p_start;	// 该进程处理数据起始地址
	int p_len;		// 该进程处理数据长度
	int pid;		// 当前进程的编号
	/* 分配内存 */
	p = (int*)malloc(LEN * sizeof(int));
	if (p==NULL)
	{
		fprintf(stderr, "cannot allocate memory for pointer!\r\n");
		exit(1);
	}
	register int i;
	/* MPI初始化 */
	MPI_Init(NULL, NULL);
	/* 获取MPI进程个数 */
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	/* 获取当前进程号 */
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	/* 计算数据起始地址和长度 */
	p_len = LEN/size;
	p_start = pid * p_len;
	if ((pid==size-1) && (p_start+p_len!=LEN)) p_len=LEN-p_start; // 最后一个节点
	/* kernel */
	for (i=p_start;i<p_start+p_len;++i) p[i]=i;
	/* 如果当前节点不是主节点，那么要把数据发送给主节点；主节点负责接收从节点发来的数据 */
	if (pid!=0) MPI_Send(&p[p_start], p_len, MPI_INT, 0, pid, MPI_COMM_WORLD);
	else
	{
		// int *buf = (int*)malloc(LEN * sizeof(int));
		for (i=1;i<size;++i)
		{
			if (i!=size-1) MPI_Recv(&p[i*p_len], p_len, MPI_INT, i, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			else MPI_Recv(&p[i*p_len], LEN-i*p_len, MPI_INT, i, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
	}
	/* MPI结束 */
	MPI_Finalize();
	/* 归约到主节点显示输出 */
	if(pid==0) for (i=0;i<LEN;++i) printf("%d\t",p[i]);
	printf("\r\n");
	/* 释放内存 */
	free(p);
	/* 退出程序 */
	exit(0);
}