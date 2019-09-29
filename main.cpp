#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int y;
	char match[100][100];
	char match2[100][100];
	char phone[100][100];
	char province[100][100];
	char city[100][100];
	char name[100][100];
	char qu[100][100];
	char street[100][100];
	char address[100][100];
	int i, j;
	int k;
	int n;
	int m;
	int f;
	char hard[100];
	n = 1;
	int g = 0;
	cin >> hard[0];
	cin >> hard[1];
	for (i = 0; i < n; i++)
	{
		cin >> match[i];
	}
	for (i = 0; i < n; i++)//找出手机号码
	{
		k = 0;
		int y = strlen(match[i]);
		for (j = 0; j < y; j++)
		{
			f = 0;
			k = 0;

			if (match[i][j] >= '0'&&match[i][j] <= '9')//找出第一个数字
			{
				for (m = j; m <= j + 10; m++)//判断从这个数字开始后十一个数字是否为手机号码，区分手机号码和地址号码，手机号码：十一位，第十二位不可能是数字。地址号码：无限多位：隐患：手机号码若放在最后
				{//手机号码放在最后不能这么用

					if (match[i][m] >= '0'&&match[i][m] <= '9')
					{
						k++;
					}

				}
				if (k == 11)//找到手机号码
				{
					g = 0;
					for (m = j; m <= j + 10; m++)
					{
						phone[i][g] = match[i][m];
						g++;
					}
					g = 0;
					y = strlen(match[i]);
					for (f = 0; f <= y; f++)
					{
						if (f == j)
						{
							f += 11;
						}
						match2[i][g] = match[i][f];
						g++;
					}
					break;
				}

			}

		}
	}

	//接下来地址分解
	//先考虑直辖市
	char cf[100];
	char cf2[100];
	int z = 0;
	for (i = 0; i < n; i++)
	{
		y = strlen(match2[i]);
		for (j = 0; j < y; j++)
		{
			g = 0;
			if (match2[i][j] == ',')
			{
				for (g = 0; g < j; g++)
				{
					name[i][g] = match2[i][g];

				}
				break;
			}


		}
		j++;
		int k;
		g = j;
		y = strlen(match2[i]);
		for (; j < y;)
		{
			cf[0] = match2[i][j++];
			cf[1] = match2[i][j++];
			z = 0;
			if (strcmp(cf, "区") == 0)
			{
				for (; g < j; g++)
				{
					province[i][z++] = match2[i][g];

				}
				y = strlen(match2[i]);
				for (; j < y;)
				{
					cf[0] = match2[i][j++];
					cf[1] = match2[i][j++];
					z = 0;

					if (strcmp(cf, "市") == 0)
					{
						for (; g < j; g++)
						{
							city[i][z++] = match2[i][g];

						}
						break;
					}
					memset(cf2, 0, sizeof(cf2));
				}
				break;
			}
			else if (strcmp(cf, "市") == 0)//找市级
			{
				for (k = g; k < j - 2; k++)
				{
					province[i][z++] = match2[i][k];

				}
				z = 0;
				for (k = g; k < j; k++)
				{

					city[i][z++] = match2[i][k];
				}
				g = j;
				break;
			}
			else
			{
				z = 0;

				if (strcmp(cf, "省") == 0)
				{
					for (; g < j; g++)
					{
						province[i][z++] = match2[i][g];

					}
					y = strlen(match2[i]);
					for (; j < y;)
					{
						cf[0] = match2[i][j++];
						cf[1] = match2[i][j++];
						z = 0;

						if (strcmp(cf, "市") == 0 || strcmp(cf, "州") == 0)
						{
							for (; g < j; g++)
							{
								city[i][z++] = match2[i][g];

							}
							break;
						}
						memset(cf2, 0, sizeof(cf2));
					}
					break;
				}
			}
			memset(cf, 0, sizeof(cf));
		}
		z = 0;
		memset(cf2, 0, sizeof(cf2));
		int o = 0;
		y = strlen(match2[i]);
		for (j = g; j < y;)
		{
			z = 0;
			cf[0] = match2[i][j++];
			cf[1] = match2[i][j++];

			o = j;
			cf2[0] = match2[i][o++];
			cf2[1] = match2[i][o];
			if (strcmp(cf, "区") == 0 || strcmp(cf, "县") == 0 || strcmp(cf, "市") == 0)
			{
				for (k = g; k < j; k++)
				{
					qu[i][z++] = match2[i][k];
				}
				g = j;
				y = strlen(match2[i]);
				for (; j < y;)
				{
					memset(cf, 0, sizeof(cf));
					memset(cf2, 0, sizeof(cf2));
					cf[0] = match2[i][j++];
					cf[1] = match2[i][j++];

					o = j;
					cf2[0] = match2[i][o++];
					cf2[1] = match2[i][o];
					z = 0;

					if (strcmp(cf, "镇") == 0 || strcmp(cf, "乡") == 0)
					{
						for (k = g; k < j; k++)
						{
							street[i][z++] = match2[i][k];
						}
						z = 0;
						y = strlen(match2[i]);
						for (k = j; k < y; k++)
						{
							address[i][z++] = match2[i][k];
						}
						break;

					}
					else if (strcmp(cf, "街") == 0 && strcmp(cf2, "道") == 0)
					{
						for (k = g; k < j + 2; k++)
						{
							street[i][z++] = match2[i][k];
						}
						z = 0;
						y = strlen(match2[i]);
						for (k = j + 2; k < y; k++)
						{
							address[i][z++] = match2[i][k];
						}

						break;
					}

					if (cf[0] >= '0'&&cf[0] <= '9')
					{
						for (k = g; k < y; k++)
						{

							address[i][z++] = match2[i][k];
						}
						break;
					}

					if ((j - 1) == y)
					{

						for (k = g; y; k++)
						{
							address[i][z++] = match2[i][k];

						}
						break;

					}

				}



				break;
			}
			else  if (strcmp(cf, "镇") == 0 || strcmp(cf, "乡") == 0)
			{
				for (k = g; k < j; k++)
				{
					street[i][z++] = match2[i][k];
				}
				z = 0;
				for (k = j; k < y; k++)
				{
					address[i][z++] = match2[i][k];
				}
				break;

			}
			else if (strcmp(cf, "街") == 0 && strcmp(cf2, "道") == 0)
			{
				for (k = g; k < j + 2; k++)
				{
					street[i][z++] = match2[i][k];
				}
				z = 0;

				for (k = j + 2; k < y; k++)
				{
					address[i][z++] = match2[i][k];
				}

				break;
			}
		}

	}
	int l = strlen(address[0]);
	for (i = 0; i < n; i++)
	{
		address[0][l - 1] = '\0';
	}

	for (i = 0; i < n; i++)
	{  cout<<"{";
		cout << "\"姓名\":\"" << name[0] << "\",\"手机\":\"";
		for (j = 0; j < 11; j++)
		{
			cout << phone[0][j];
		}
			cout<< "\",\"地址\":[\"" << province[0] << "\",\"" << city[0] << "\",\"" << qu[0] << "\",\"" << street[0] << "\",\"" << address[0] << "\"]";
			cout<<"}";
	}

	return 0;
}
