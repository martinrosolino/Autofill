#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
    {
    char list[]="Inserta aqui la lista de palabras";
    char editablelist[strlen(list)];//strtok modifica el string, por lo que crea una copia para no perder el original
    char root[10];//Prefijo
    char delim[]=" ";//Separador entre palabras

    typedef struct s
        {
        char data[strlen(list)];
        struct s *tie;
        }stack;

    int rootsize,k=1;
    char *temp;
    stack *p,*aux;

    strcpy(root,"1");

    while(root[0]!='0')
        {
        printf("Ingresa la raiz (0 para salir): ");
        gets(root);
        p=aux=NULL;
        rootsize=strlen(root);
        strcpy(editablelist,list);

        for(k=0;editablelist[k]!=0;k++)
            editablelist[k]=tolower(editablelist[k]);

        for(k=0;root[k]!=0;k++)
            root[k]=tolower(root[k]);

        temp=strtok(editablelist,delim);//Separa editablelist por espacios

        while(temp!=NULL)
            {
            if(strncmp(temp,root,rootsize)==0)//Si la palabra obtenida por strtok coincide con el prefijo lo apila
                {
                aux=(stack *) malloc(sizeof(stack));
                strcpy(aux->data,temp);
                aux->tie=p;
                p=aux;
                }
            temp=strtok(NULL,delim);//Separa editablelist por espacios
            }

        aux=p;
        while(aux)//Recorre pila para impresion
            {
            aux->data[0]=toupper(aux->data[0]);
            printf("-%s\n",aux->data);
            aux=aux->tie;
            }
        free(aux);
        printf("---------------------------------\n");
        }

    return 0;
    }

