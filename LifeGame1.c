/*
* Jogo da vida
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arq[30];
int linhas;

int colunas;
int tamanho;


struct celula
{
    int status;
    int vizinhos;
    int linha;
    int coluna;
};




int conta_linha (char arq[30])
{
      FILE *fp;
    char c;

		if((fp = fopen(arq,"r")) == NULL)/* Arquivo ASCII, para leitura */
		     {
				printf( "Erro na abertura do arquivo");
				exit(0);
			  }

    while (EOF != (c = getc(fp))) /* Enquanto não chegar ao final do arquivo*/
     if (c=='\n')
         {

        linhas=linhas+1;

         }

      fclose(fp);
    printf("%d \n",linhas);



	return(0);
}





int conta_coluna (char arq[30])
{
      FILE *fp;
		char c;

		if((fp = fopen(arq,"r")) == NULL)/* Arquivo ASCII, para leitura */
		     {
				printf( "Erro na abertura do arquivo");
				exit(0);
			  }

    while (EOF != (c = getc(fp))) /* Enquanto não chegar ao final do arquivo*/

     if ((c != ' ')&&(c != '\n'))
       {
       colunas++;
       }
     else{fclose(fp);}
      fclose(fp);
    printf("%d \n",colunas);



	return(0);
}

int salva_linha(char arq [30])
{
        FILE *fp;
		int c;
        char str[20];
		int i,j,x,y,h;
		printf("%d \n",linhas);
		printf("%d \n",colunas);
		//x=linhas*sizeof(char*);
		//y=colunas*sizeof(char*);
        int tabela[linhas][colunas];
		if((fp = fopen(arq,"r")) == NULL)/* Arquivo ASCII, para leitura */
	     {
				printf( "Erro na abertura do arquivo");
				exit(0);
         }



               for (i=0;i<linhas;i++)
        {


               for (j=0;j<colunas;j++)
                   {
                   while((c = getc(fp) ) != EOF)
                             printf("%i\n",c);
                             if(c!= 10)
                             {
                             tabela[i][j]= getc(fp);
                             printf("tabela[%i][%i]: %c\n",i,j,tabela[i][j]);
                             }




                    }
                    printf("\n");


          }

   fclose(fp);


        // teste
     // for (i=0;i<linhas;i++)
    //    {
     //       for (j=0;j<colunas;j++)
     //       {
          // printf("%i",&tabela[i][j]);
     //       tabela[i][j]= 1;
      //      }
     // printf("\n");
     //}

 for(i=0; i<linhas; i++)
  {
    for(j=0; j<colunas; j++)
  {
 printf("tabela[%i][%i]: %c\n",i,j,tabela[i][j]);

 }
 printf("\n");
 }







        printf("\n");
        return(0);
}



int leia_isso(char arq[30])
{
        FILE *fp;
		char c;
		int i;
        int coluna1,linha1;
		if((fp = fopen(arq,"r")) == NULL)/* Arquivo ASCII, para leitura */
		     {
				printf( "Erro na abertura do arquivo");
				exit(0);
			  }
       while((c = getc(fp) ) != EOF)
    printf("%c",c);
     // if ((c != ' ')&&(c != '\n'))
     // {
    //     linha1 = c;
    //  }
    //  if((c = ' ')&&(c!='\n'))
     //  {
     //  }

        fclose(fp);
        printf("\n");

	return(0);
}




int main()
{



printf("insira o nome do arquivo, a exemplo 'ok.txt' :\n");
//scanf("%arq", &arq);
gets(arq);
conta_linha(arq);
conta_coluna(arq);
leia_isso(arq);
salva_linha(arq);
system("pause");

}
