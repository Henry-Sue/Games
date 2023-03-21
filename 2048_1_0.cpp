#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996);

void print_net();
void generator();
void operate();
int isover();

int net[4][4];

int main()
{
	printf("\"\"\"\n2048\n\"\"\"\nVersion: 1.0\nAuthor: Henry Sue\n\n");

	Sleep(1000);
	printf("*******************************************************"
		"\n1����1��3��5��2��Ϊ�����������������и��ӻ����Ǹ������˶���"
		"\n2����ͬ���ֵ��������ӣ���ײʱ���ֻ���ӡ�"
		"\n3��ÿ�λ���ʱ���հ״������ˢ�³�һ�����ֵĸ��ӡ�"
		"\n4�������治���˶�ʱ��������ȫ������������ʱ������Ϸ������"
		"\n******�����������������2048ʱ����Ϸʤ����******");

	Sleep(1000);
	char ret;

	do {
		printf("\n\nReady? [y/n]\n");
		scanf("%c", &ret);
		getchar();
		if (ret != 'y' && ret != 'n') {
			printf("?????????");
		}
		else if (ret == 'n') {
			return 0;
		}
	} while (ret != 'y');

	net[4][4] = (0);
	generator();
	print_net();

	while (1)
	{
		operate();
		generator();
		print_net();
		isover();
	}


}

void print_net()
{
	printf("\n------------------------------------------------\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 3)
			{
				printf("%d\n\n", net[i][j]);
			}
			else
			{
				printf("%d\t", net[i][j]);
			}
		}
	}
	printf("------------------------------------------------");
}

void generator()
{
	int ret = 1;
	do
	{
		time_t t;

		srand((unsigned)time(&t));
		int x = rand() % 3;
		int y = rand() % 3;

		if (net[x][y] == 0)
		{
			net[x][y] = 2;
			ret = 0;
		}

	} while (ret);
}

void operate()
{
	int con;
	scanf("%d", &con);
	switch (con)
	{

	case 1:
		//�ƶ� 
		for (int hor = 0; hor < 4; hor++) {
			int count = 0;
			for (int ver = 0; ver < 4; ver++) {
				if (net[hor][ver] != 0 && ver > 0) {
					if (net[hor][count] != net[hor][ver]) {
						net[hor][count] = net[hor][ver];
						net[hor][ver] = 0;
					}
					count += 1;
				}
				else {
					if (net[hor][ver] != 0 && ver == 0) {
						count += 1;
					}
				}
			}
		}
		//��ͬ���				
		for (int hor = 0; hor < 4; hor++) {
			for (int ver = 0; ver < 3; ver += 1) {
				if (net[hor][ver] == net[hor][ver + 1] && net[hor][ver] != 0) {
					net[hor][ver] = net[hor][ver] + net[hor][ver + 1];
					net[hor][ver + 1] = 0;
				}
			}
		}
		//��λ�ƶ� 
		for (int hor = 0; hor < 4; hor++) {
			int count = 0;
			for (int ver = 0; ver < 4; ver++) {
				if (net[hor][ver] != 0) {
					if (net[hor][count] != net[hor][ver]) {
						net[hor][count] = net[hor][ver];
						net[hor][ver] = 0;
					}
					count += 1;
				}
			}
		}
		break;

	case 3:
		//�ƶ� 
		for (int hor = 0; hor < 4; hor++) {
			int count = 3;
			for (int ver = 3; ver >= 0; ver--) {
				if (net[hor][ver] != 0 && ver < 3) {
					if (net[hor][count] != net[hor][ver]) {
						net[hor][count] = net[hor][ver];
						net[hor][ver] = 0;

					}
					count -= 1;
				}
				else {
					if (net[hor][ver] != 0 && ver == 3) {
						count -= 1;
					}
				}
			}
		}
		//��ͬ���				
		for (int hor = 0; hor < 4; hor++) {
			for (int ver = 3; ver > 0; ver--) {
				if (net[hor][ver] == net[hor][ver - 1] && net[hor][ver] != 0) {
					net[hor][ver] = net[hor][ver] + net[hor][ver - 1];
					net[hor][ver - 1] = 0;
				}
			}
		}
		//��λ�ƶ� 
		for (int hor = 0; hor < 4; hor++) {
			int count = 3;
			for (int ver = 3; ver >= 0; ver--) {
				if (net[hor][ver] != 0) {
					if (net[hor][count] != net[hor][ver]) {
						net[hor][count] = net[hor][ver];
						net[hor][ver] = 0;
					}
					count -= 1;
				}
			}
		}
		break;

	case 5:
		//�ƶ� 
		for (int ver = 0; ver < 4; ver++) {
			int count = 0;
			for (int hor = 0; hor < 4; hor++) {
				if (net[hor][ver] != 0 && hor > 0) {
					if (net[count][ver] != net[hor][ver]) {
						net[count][ver] = net[hor][ver];
						net[hor][ver] = 0;
					}
					count += 1;
				}
				else {
					if (net[hor][ver] != 0 && hor == 0) {
						count += 1;
					}
				}
			}
		}
		//��ͬ���				
		for (int ver = 0; ver < 4; ver++) {
			for (int hor = 0; hor < 3; hor += 1) {
				if (net[hor][ver] == net[hor + 1][ver] && net[hor][ver] != 0) {
					net[hor][ver] = net[hor][ver] + net[hor + 1][ver];
					net[hor + 1][ver] = 0;
				}
			}
		}
		//��λ�ƶ� 
		for (int ver = 0; ver < 4; ver++) {
			int count = 0;
			for (int hor = 0; hor < 4; hor++) {
				if (net[hor][ver] != 0) {
					if (net[count][ver] != net[hor][ver]) {
						net[count][ver] = net[hor][ver];
						net[hor][ver] = 0;
					}
					count += 1;
				}
			}
		}
		break;

	case 2:
		//�ƶ� 
		for (int ver = 0; ver < 4; ver++) {
			int count = 3;
			for (int hor = 3; hor >= 0; hor--) {
				if (net[hor][ver] != 0 && hor < 3) {
					if (net[count][ver] != net[hor][ver]) {
						net[count][ver] = net[hor][ver];
						net[hor][ver] = 0;
					}
					count--;
				}
				else {
					if (net[hor][ver] != 0 && hor == 3) {
						count--;
					}
				}
			}
		}
		//��ͬ���				
		for (int ver = 0; ver < 4; ver++) {
			for (int hor = 3; hor >= 0; hor--) {
				if (net[hor][ver] == net[hor - 1][ver] && net[hor][ver] != 0) {
					net[hor][ver] = net[hor][ver] + net[hor - 1][ver];
					net[hor - 1][ver] = 0;
				}
			}
		}
		//��λ�ƶ� 
		for (int ver = 0; ver < 4; ver++) {
			int count = 3;
			for (int hor = 3; hor >= 0; hor--) {
				if (net[hor][ver] != 0) {
					if (net[count][ver] != net[hor][ver]) {
						net[count][ver] = net[hor][ver];
						net[hor][ver] = 0;
					}
					count--;
				}
			}
		}
		break;
	}
}

int isover()
{
	int count = 0;
	for (int ver = 0; ver < 4; ver++) {
		for (int hor = 0; hor < 4; hor++) {
			if (net[hor][ver] == 0) {
				count++;
			}
			else if (net[hor][ver] == 2048) {
				printf("******** ��ʤ������********");
				system("pause");
				return 0;
			}
		}
	}
	if (count == 16) {
		printf("��Ϸ������");
		system("pause");
		return 0;
	}
}

