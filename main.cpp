#include <iostream>
#include <string.h>
using namespace std;

int main()
{   char match[100][100];
    char match2[100][100];
    char phone[100][100];
    char province[100][100];
    char city[100][100];
    char name[100][100];
    char qu[100][100];
    char street[100][100];
    char address[100][100];
    int i,j;
    int k;
    int n;
    int m;
    int f;
    cin>>n;
    int g=0;
    for(i=0;i<n;i++)
    {
        cin>>match[i];
    }
    for(i=0;i<n;i++)//�ҳ��ֻ�����
    {   k=0;
        for(j=0;j<strlen(match[i]);j++)
        { f=0;
           if(match[i][j]>='0'&&match[i][j]<='9')//�ҳ���һ������
                {

                  for(m=j;m<=j+11;m++)//�жϴ�������ֿ�ʼ��ʮһ�������Ƿ�Ϊ�ֻ����룬�����ֻ�����͵�ַ���룬�ֻ����룺ʮһλ����ʮ��λ�����������֡���ַ���룺���޶�λ���������ֻ��������������
                  {//�ֻ���������������ô��
                      if(match[i][m]>='0'&&match[i][m]<='9')
                      {
                          k++;
                      }


                  }
                  if(k==11)//�ҵ��ֻ�����
                  {   g=0;

                      for(m=j;m<=j+10;m++)
                      {
                          phone[i][g]=match[i][m];
                          g++;
                      }
                      g=0;
                      for(f=0;f<=strlen(match[i]);f++)
                      {if(f==j)
                          {
                              f+=11;
                          }
                          match2[i][g]=match[i][f];
                          g++;


                      }
                      break;
                  }
                  else
             {
                 j=m;
             }
                }

        }
    }
  //��������ַ�ֽ�
  //�ȿ���ֱϽ��
  char cf[100];
  char cf2[100];
  int z=0;
  for(i=0;i<n;i++)
  {
      for(j=0;j<strlen(match2[i]);j++)
      {g=0;
          if(match2[i][j]==',')
          {
              for(g=0;g<j;g++)
              {
                  name[i][g]=match2[i][g];

              }
              break;
          }


          }
          j++;
          int k;
          g=j;
          for(;j<strlen(match2[i]);)
          {
            cf[0]=match2[i][j++];
            cf[1]=match2[i][j++];
            z=0;
            if(strcmp(cf,"��")==0)//���м�
            {cout<<j<<'\n';
                for(k=g;k<j-2;k++)
                {
                    province[i][z++]=match2[i][k];

                }
                z=0;
                for(k=g;k<j;k++)
                {

                    city[i][z++]=match2[i][k];
                }
                g=j;
                break;
            }
            else
            {
                z=0;

                  if(strcmp(cf,"ʡ")==0)
                  {
                      for(;g<j;g++)
                      {
                          province[i][z++]=match2[i][g];

                      }

                      for(;j<strlen(match2[i]);)
                      {
                          cf[0]=match2[i][j++];
                          cf[1]=match2[i][j++];
                          z=0;

                          if(strcmp(cf,"��")==0)
                          {
                              for(;g<j;g++)
                              {
                                  city[i][z++]=match2[i][g];

                              }
                              break;
                          }
                          memset(cf2,0,sizeof(cf2));
                      }
                      break;
                  }
            }
          memset(cf,0,sizeof(cf));
          }
          z=0;
          memset(cf2,0,sizeof(cf2));
          int o=0;

          for(j=g;j<strlen(match2[i]);)
            {z=0;
              cf[0]=match2[i][j++];
              cf[1]=match2[i][j++];

              o=j;
              cf2[0]=match2[i][o++];
              cf2[1]=match2[i][o];
              if(strcmp(cf,"��")==0||strcmp(cf,"��")==0||strcmp(cf,"��")==0)
              {
                 for(k=g;k<j;k++)
                 {
                    qu[i][z++]=match2[i][k];
                 }
                 g=j;
                 for(;j<strlen(match2[i]);)
                 {
                      memset(cf,0,sizeof(cf));
                 memset(cf2,0,sizeof(cf2));
                 cf[0]=match2[i][j++];
              cf[1]=match2[i][j++];

              o=j;
              cf2[0]=match2[i][o++];
              cf2[1]=match2[i][o];
              z=0;
              if(strcmp(cf,"��")==0||strcmp(cf,"��")==0)
              {
                  for(k=g;k<j;k++)
                    {
                        street[i][z++]=match2[i][k];
                    }
                        z=0;
                    for(k=j;k<strlen(match2[i]);k++)
                    {
                     address[i][z++]=match2[i][k];
                    }
                    break;

              }
              else if(strcmp(cf,"��")==0&&strcmp(cf2,"��")==0)
              {
                   for(k=g;k<j+2;k++)
                    {
                        street[i][z++]=match2[i][k];
                    }
                        z=0;
                    for(k=j+2;k<strlen(match2[i]);k++)
                    {
                     address[i][z++]=match2[i][k];
                    }
                    break;
              }
              if(cf[0]>='0'&&cf[0]<='9')
              {
                  for(k=g;k<strlen(match2[i]);k++)
                  {

                      address[i][z++]=match2[i][k];
                  }
                  break;
              }

             if(j==strlen(match2[i]))
                     {

                         for(k=g;k<strlen(match2[i]);k++)
                  {
                      address[i][z++]=match2[i][k];

                  }break;

                     }

                 }



              break;
              }
              else if(strcmp(cf,"��")==0||(strcmp(cf,"��")==0&&(strcmp(cf2,"��")==0))||strcmp(cf,"��")==0)
              {
                  for(k=g;k<j;k++)
                    {
                        street[i][z++]=match2[i][k];
                    }
                        z=0;
                    for(k=j;k<strlen(match2[i]);k++)
                    {
                     address[i][z++]=match2[i][k];
                    }
                    break;

              }
          }

  }
  int l=strlen(address[i]);
  for(i=0;i<n;i++)
  {
      address[i][l]='\0';
  }
for(i=0;i<n;i++)
{
    cout<<"{\"����\".:\""<<name[i]<<"\",\"�ֻ�\":\""<<phone[i]<<"\",\"��ַ\":[\""<<province[i]<<"\",\""<<city[i]<<"\",\""<<qu[i]<<"\",\""<<street[i]<<"\",\""<<address[i]<<"\"]}";
}
    return 0;
}
