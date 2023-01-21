#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct StackList
{
    int topo;
    char open;
}*stack1,sv1;

void pusho(struct StackList *sv1,struct StackList stack1[],char element,int stack_size)
{
    int i;

    if((stack_size-1)==((sv1->topo)+1))
    {
        printf("\nStack full.\nCannot Append...");
    }
    else
    {

        (sv1->topo)++;
        i=sv1->topo;
        stack1[i].open=element;
    }
}

char popo(struct StackList *sv1/*top*/,struct StackList stack1[]/*Array*/)
{
    char epop='\0';
    int i;

    if(sv1->topo==-1)
    {
        printf("\nStack empty...\nCannot pop element...");
        return(epop);
    }
    else
    {
        i=sv1->topo;
        epop=stack1[i].open;
        (sv1->topo)--;
        return(epop);
    }
}

int main()
{
    int i,count1=0,count2=0;
    float j=-1.0,fdec=0.0,sum1=0.0;
    int dec,flag,sum=0,stack_size=10;
    char element;
    char *str1;

    printf("\n\"\"\" This Program is to convert binary num. to decimal num. \"\"\"");
    printf("\nThis is a character Array.\nEnter how many elements you want to enter:");
    scanf("%d",&stack_size);
    fflush(stdin);

    stack1=(struct StackList *)calloc(stack_size,sizeof(struct StackList));
    str1=(char *)calloc(stack_size,sizeof(char));

    printf("\nEnter Binary number to convert into decimal number:");
    gets(str1);

    for(i=0;str1[i]!='\0';i++)
    {
        element=str1[i];
        if(str1[i]=='.')
        {
            flag=1;
            break;
        }
        pusho(&sv1,stack1,element,stack_size);
        count1=i;
    }

    printf("\n\nDecimal Number is : ");

    for(i=0;i<=count1;i++)
    {
        element=popo(&sv1,stack1);
        if(element=='1')
        {
            dec=1;
        }
        else if(element=='0')
        {
            dec=0;
        }
        dec=pow(2.0,i)*dec;
        sum=sum+dec;
    }

    if(flag!=1)
    {
       printf("%d",sum);
    }

    if(flag==1)
    {
        count2=strlen(str1);
        for(i=count1+2;i<count2;i++)
        {
            element=str1[i];
            pusho(&sv1,stack1,element,stack_size);
        }

        for(j=-(count2-count1-2);j<=-1;j++)
        {
            element=popo(&sv1,stack1);
            if(element=='1')
            {
                fdec=1;
            }
            else if(element=='0')
            {
                fdec=0;
            }
            fdec=pow(2.0,j)*fdec;
            sum1=sum1+fdec;
        }
        printf("%f",sum+sum1);
    }

    free(str1);
    free(stack1);
    return 0;
}