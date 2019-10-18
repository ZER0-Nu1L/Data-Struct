//The parameter  is data
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

#define TEST1//creat & write
#define TEST2//read

#define S 0
#define CHAR 0
#define STRING 0
#define BLOCK 0

#define STRUCT 1

typedef struct node {
	int n;
	char str[100];
}block;
int main(int argc, char* argv[])//�������ַ���ָ�룬��Ҫ���� 
{
	FILE * fp;
	if (argc != 2)
	{
		printf("Please enter the correct number of parameters\n");
		exit(EXIT_FAILURE);
	}
//******************************************
//**** The input and output function:   ****
//******************************************
# ifdef TEST1
	
	//Write function:
	fp = fopen(argv[1], "wb");
	/*if ((fp = fopen(argv[1], "rb")) == NULL)
	{
		printf("%s can't open the file! \nNow creat one for you!\n", argv[1]);
		fp = fopen(argv[1], "wb");
	}
	*/
	#if S
		printf("%s opens!\n\n", argv[1]);
		fprintf(fp, "fprintf success\n");//�Ƿ���֮��� 
		fputc('f',fp);fputc('u',fp);fputc('t',fp);fputc('c',fp);fputc(' ',fp);fputc('s',fp);fputc('u',fp);fputc('c',fp);fputc('c',fp);fputc('e',fp);fputc('s',fp);fputc('s',fp);fputc('\n',fp);
		fwrite("fwrite success!!", sizeof(char), sizeof("fwrite success!!") / sizeof(char), fp);
	#endif

	#if STRUCT
		block node;
		node.n = 100;
		strcpy(node.str, "Hello world!");
		fwrite(&node, sizeof(block), 1, fp);//-----------------

		block nodes[10];
		char temp[20];
		for (int i = 0; i < 10; i++)
		{
			nodes[i].n = i*111;
			char no[10] = "No.";
			itoa(i, temp, 10);
			strcpy(nodes[i].str, strcat(no, temp));
			//fwrite(nodes + i, sizeof(block), 1, fp);
		}
		fwrite(nodes, sizeof(block), sizeof(nodes)/sizeof(block), fp);//һ����д��Ҳ����
	#endif
	
	fclose(fp);
#endif
	//�ļ���д��ʽ��ת������������ 		------------------------------------------------------------Q1
	//��ʱ�Ľ���������ļ��ؿ�

# ifdef TEST2
//Read function:
	
		if ((fp = fopen(argv[1], "rb")) == NULL)
		{
			printf("%s can't open the file! \n", argv[1]);
			exit(EXIT_FAILURE);
		}
	#if S
		#if CHAR
			char c;
			while ((c = getc(fp)) != EOF && !feof(fp))
				putc(c, stdout);

			printf("%d\n", ftell(fp));
			fseek(fp, 0, SEEK_SET);
			printf("%d\n\n", ftell(fp));
		#endif

	//Why fgets()  doesn't work???------------------------------------------------------------Q2
	//����ΪNULL��fgetc���� 
		#if STRING
			char str[100];
			char* a = fgets(str, 60, fp);
			fputs(str, stdout);

			printf("%d?��\n", a);//NULL
			printf("%d\n", ftell(fp));//��������

			printf("%d\n", ftell(fp));
			fseek(fp, 0, SEEK_SET);
			printf("%d\n\n", ftell(fp));
		#endif

		#if BLOCK
			//-----------------------------------------------------------Q3
			char str[20];//������ȵĿ����ǣ�freadԽ�磬û��'\0'---------A3	
			memset(str, '\0', sizeof(str));
			fread(str, sizeof(str[0]), sizeof(str) / sizeof(char), fp);
			puts(str);
	
			/*			fprintf `F�ux?
						success
						`F�ux? 

			�ĳɶ�����д��
				fprintf success
				futc`F�ux?
				 success
				fputs succe`F�ux? 
			�ĳ�fwrite����,ȥ�����з� 
				fwrite success!!`F�uxl
				fwrite success!!`F�uxl 
			fwrite("fwrite success!!", sizeof(char), sizeof("fwrite success!!")/sizeof(char), fp); strlen
			*/
			printf("%d\n", ftell(fp));
			fseek(fp, 0, SEEK_SET);
			printf("%d\n\n", ftell(fp));
		#endif
	#endif
	
	#if STRUCT
		block noder;
		fread(&noder, sizeof(block), 1, fp);
		printf("%d %s\n", noder.n, noder.str);

		block noders[10];
//		for (int i = 0; i < 10; i++)
//			fread(noders+i, sizeof(block), 1, fp);
		fread(noders, sizeof(block), sizeof(noders)/sizeof(block), fp);//һ���Զ���Ҳ����
		for (int i = 0; i < 10; i++)
			printf("%d %s\n", noders[i].n, noders[i].str);
	#endif

	fclose(fp);
#endif

	printf("\nSuessess!");
	system("pause");
	return 0;
}
