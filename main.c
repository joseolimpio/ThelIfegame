/*
* Jogo da vida
* By - José Olimpio M. Negrão
* Gmail - joseolimpionegrao at gmail dot com
* Trabalho - "Game of life"
* Orientado por : Profº Apolinário.
* UFBA - 12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* method inspired on the method die from PHP */
#define die(text, args...) do { fprintf(stderr, text, ##args); free_arrays(); exit(1); } while(0)
#define debug(text, args...) do { if (is_debug) printf(text, ##args); } while(0)

char arq[30];
char is_debug = 0;
int linhas,colunas,cont_chars,celula;
int linha,coluna,geracao;
int ** vizinhos= NULL;
int ** tabela = NULL;

void free_arrays();
void set_tabela(int, int);

/**
 * Alloc memory for the matrix of data
 */
void set_tabela(int linha, int coluna)
{

    int i,j;

    tabela =(int**)malloc(linha*sizeof(int*));

    if(tabela == NULL)
    {
        die("- Espaco Insuficiente -");
    }

    for(i=0; i< linha; i++)
    {
        tabela[i] = (int*)malloc(coluna*sizeof(int));
        if(tabela[i] == NULL)
            die("- Espaco Insuficiente -");
    }
}

/**
 * TODO: This methods ( set_vizinhos and set_tabela ) should be the same method receiving the matrix to 
 * be filled/allocated 
 */
void set_vizinhos(int linha, int coluna)
{

    int i,j;

    vizinhos =(int**)malloc(linha* sizeof(int*));

    if(vizinhos == NULL)
    {
        die("- Espaco Insuficiente -");
    }

    for(i=0; i< linha; i++)
    {
        vizinhos[i] = (int*)malloc(coluna* sizeof(int));
        if(vizinhos[i] == NULL)
            die("- Espaco Insuficiente -");
    }
}

/**
 * TODO: This method should receive a matrix as parameter to be able to print any matrix 
 */
void imprimir_tabela()
{
    int i,j;
    for (i=1; i<=linha; i++)
    {
        for (j=1; j<=coluna; j++)
        {
            printf("%i",tabela[i][j]);
        }
        printf("\n");
    }
}

int conta_caracteres (char arq[30])
{
    FILE *fp;
    char c;
    if((fp = fopen(arq,"r")) == NULL)// Arquivo ASCII, para leitura
    {
        die( "Erro na abertura do arquivo [%s]\n", arq);
    }
    while (EOF != (c = getc(fp))) // Enquanto não chegar ao final do arquivo
        if (c != '\n')
        {
            cont_chars++;
        }
        else
        {
            fclose(fp);
        }
    fclose(fp);
    printf("%d \n",cont_chars);
    return(0);
}

void dimensoes(char arq[30])
{
    FILE *fp;
    int c;
    int i,j,x,y,h;
    char *buf_dimen = calloc(10, sizeof(char));
    if((fp = fopen(arq,"r")) == NULL)
    {
        die( "Erro na abertura do arquivo");
    }
    //usa o buff pra carregar a linha
    for (i=0; i <cont_chars; i++)
    {
        c = getc(fp);
        if((c != ' ')&&(c >=48)&&(c<=57))
        {
            if((c != EOF)&&(c != '\n'))
            {
                buf_dimen[i] = c;
            }
        }
        else
        {
            break;
        }
        printf("[%i] = %i\n",i,buf_dimen[i]);
    }
    linha = atoi(buf_dimen);
    //usa o buff pra carregar a coluna
    for (i=0; i <cont_chars; i++)
    {
        c = getc(fp);
        if((c != ' ')&&(c >=48)&&(c<=57))
        {
            if((c != EOF)&&(c != '\n'))
            {
                buf_dimen[i] = c;
            }
        }
        else
        {
            break;
        }
        printf("[%i] = %i\n",i,buf_dimen[i]); // debug
    }
    coluna = atoi(buf_dimen);
    fclose(fp);
    linhas =linha+2;
    colunas = coluna+2;
    printf("\n");
    set_tabela(linhas,colunas);
    set_vizinhos(linhas,colunas);
}

void zera_linhas()
{
    int i,j;
    for (i=0; i<linhas; i++)
    {
        for (j=0; j <colunas; j++)
        {
            tabela[i][j] = 0;
        }
    }
}


void salva_linha(char arq [30])
{
    FILE *fp;
    int c;
    int i,j,x,y,h;
    //tabela[linhas][colunas];
    zera_linhas();
    if((fp = fopen(arq,"rw")) == NULL)// Arquivo ASCII, para leitura
    {
        die( "Erro na abertura do arquivo [%s]\n", arq);
    }
    for (h=0; h <=cont_chars; h++)
    {
        c = getc(fp);
    }
    for (i=1; i<linhas; i++)
    {
        for (j=1; j<colunas; j++)
        {
            c = getc(fp);
            if((c  != EOF)&&(c != '\n')&&(c!= ' '))
            {
                tabela[i][j] = (c - 48);
                debug("[%i][%i]: %i",i,j,tabela[i][j]);
            }
        }
        printf("\n");
    }
    fclose(fp);
    printf("linha[%i], coluna[%i]",linhas,colunas);
    printf("\n");
    printf("\n");
    for (i=0; i<linhas; i++)
    {
        for (j=0; j<colunas; j++)
        {
            printf("%i",tabela[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Observador()
{

    int i,j,c,m,b;

    for (i=1; i<=linha; i++)
    {
        for (j=1; j<=coluna; j++)
        {

            c = tabela[i-1][j-1]+tabela[i-1][j]+tabela[i-1][j+1];
            m = tabela[i][j-1]+tabela[i][j+1];
            b = tabela[i+1][j-1]+tabela[i+1][j]+tabela[i+1][j+1];
            vizinhos[i][j] = c+m+b;
            //testando e matando
            if(vizinhos[i][j] != 2)
            {
                if((vizinhos[i][j]<2)|| vizinhos[i][j]>3)
                {
                    tabela[i][j] = 0;
                }
                else
                {
                    if(vizinhos[i][j]== 3)
                    {
                        tabela[i][j] = 1;
                    }
                }
            }


            // vizinhos [i][j] = count+c+m+b;
            //vizinhos[i][j] = 1;
            //printf("C[%i][%i]=[%i] \n",i,j,vizinhos[i][j]);
            //printf("Celula[%i][%i] Vizinhos[%i] \n",i,j,vizinhos[i][j]);
            //printf("Celula[%i][%i]",i,j);
        }
        printf("\n");
    }
    imprimir_tabela();
}


void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    /* printf("\x1B[2J"); */
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
#endif
}


int main(int argc, char *argv[])
{

    int g;
    int check_gera;
    geracao = 0;
    srand ((unsigned) time(NULL));

    if(argc > 1)
        strcpy( arq, argv[1]);
    else
        strcpy( arq, "default.txt");

    if(argc > 2)
        geracao = atoi(argv[2]);
    else
        geracao = 4;

    printf("\n\n");
    printf("\n\n");
    clear_screen();
    conta_caracteres(arq);
    dimensoes(arq);
    salva_linha(arq);
    printf("\n\n");
    clear_screen();
    printf("Original\n");
    printf("\n\n");
    printf("|---------------------------------------------------|\n");
    imprimir_tabela();
    printf("|---------------------------------------------------|\n");
    printf("\n\n");
    for (g=0; g<geracao; g++)
    {
        printf("|-----------------------------------------geracao[%i]\n",g);
        Observador();
        printf("|---------------------------------------------------|\n");
        printf("\n\n");
    }
    printf("geracoes[%i]",g);
    printf("\n\n");
    free_arrays();
#ifdef _WIN32
    /* if you are on unix system, is better run this code on terminal. dont just click on file ! */
    system("pause");
#endif

}

void free_arrays()
{
    if (tabela != NULL)
        free(tabela);
    if(vizinhos != NULL)
        free(vizinhos);

    tabela = NULL;
    vizinhos = NULL;

}
