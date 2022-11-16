#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

/** Defini��o do tipo de dados 'byte'
* 'unsigned char': � o tipo que consegue gravar no intervalo que vai de 0 a 255 bytes
*/
typedef unsigned char byte;

/** Defini��o da �rvore */
typedef struct nodeArvore
{
    int                 frequencia;
    byte                c;
    struct nodeArvore   *esquerda;
    struct nodeArvore   *direita;
} nodeArvore;

/** Defini��o da fila de prioridade (implementada como lista simplesmente encadeada) */

typedef struct nodeLista
{
    nodeArvore          *n;
    struct nodeLista    *proximo;
} nodeLista;

typedef struct lista
{
    nodeLista   *head;
    int         elementos;
} lista;

/**
* A fun��o strdup � dependente de implementa��o nas plataformas n�o POSIX (Windows, etc)
* Segue uma implementa��o desta fun��o como solu��o para o problema.
*/

char *strdup(const char *s)
{
    char *p = malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}

/** Fun��o que faz aloca��o de mem�ria e trata os ponteiros soltos acerca de n�s da lista encadeada.
* Obs: cada n� da lista encadeada � conectado a um n� 'raiz' de �rvore.
* @param: um n� de uma �rvore.
*/

nodeLista *novoNodeLista(nodeArvore *nArv)
{
    // Aloca mem�ria
    nodeLista *novo;
    if ( (novo = malloc(sizeof(*novo))) == NULL ) return NULL;

    // Adiciona a �rvore ao n�
    novo->n = nArv;

    // Faz o campo pr�ximo apontar para NULL
    novo->proximo = NULL;

    return novo;
}

/** Fun��o que faz aloca��o de mem�ria e trata os ponteiros soltos acerca de n�s da �rvore
* @param: o byte a ser gravado no n�, a frequencia do byte, ponteiros para os n�s filhos
*/

nodeArvore *novoNodeArvore(byte c, int frequencia, nodeArvore *esquerda, nodeArvore *direita)
{
    // Aloca mem�ria
    nodeArvore *novo;

    if ( ( novo = malloc(sizeof(*novo)) ) == NULL ) return NULL;

    // Atribui na �rvore os valores passados como par�metro
    novo->c = c;
    novo->frequencia = frequencia;
    novo->esquerda = esquerda;
    novo->direita = direita;

    return novo;
}

/** Fun��o que um novo n� na lista encadeada que representa a fila de prioridade.
* @param: um n� previamente criado, a lista que receber� o n�
*/

void insereLista(nodeLista *n, lista *l)
{
    // Se a lista passada como par�metro n�o tem um n� no in�cio (vazia), insira o n� no in�cio
    if (!l->head)
    {
        l->head = n;
    }

    // Se o campo 'frequ�ncia' do 'n�' par�metro for menor que o campo 'frequ�ncia' do primeiro item (head)
    // da lista, incluir o novo n� como head, e colocar o head antigo como next desse novo

    else if (n->n->frequencia < l->head->n->frequencia)
    {
        n->proximo = l->head;
        l->head = n;
    }
    else
    {
        // n� auxiliar que inicia apontando para o segundo n� da lista (head->proximo)
        nodeLista *aux = l->head->proximo;
        // n� auxiliar que inicia apontando para o primeiro n� da lista
        nodeLista *aux2 = l->head;

        // La�o que percorre a lista e insere o n� na posi��o certa de acordo com sua frequ�ncia.
        //
        // Se sabe que aux come�a apontando para o segundo item da lista e aux2 apontando para o primeiro.
        // Sendo assim, os ponteiros seguir�o mudando de posi��o enquanto aux n�o for o fim da lista,
        // e enquanto a frequ�ncia do n� apontado por aux for menor ou igual a frequ�ncia do 'n�' par�metro.

        while (aux && aux->n->frequencia <= n->n->frequencia)
        {
            aux2 = aux;
            aux = aux2->proximo;
        }

        // Se insere o n� na posi��o certa.
        aux2->proximo = n;
        n->proximo = aux;
    }

    // Incrementa quantidade de elementos
    l->elementos++;
}

/** Fun��o que 'solta' o n� apontado por 'head' da lista (o de menor frequ�ncia)
* (faz backup do n� e o desconecta da lista)
* @param: uma lista encadeada.
*/

nodeArvore *popMinLista(lista *l)
{

    // Ponteiro auxilar que aponta para o primeiro n� da lista
    nodeLista *aux = l->head;

    // Ponteiro auxiliar que aponta para a �rvore contida em aux (�rvore do primeiro n� da lista)
    nodeArvore *aux2 = aux->n;

    // Aponta o 'head' da lista para o segundo elemento dela
    l->head = aux->proximo;

    // Libera o ponteiro aux
    free(aux);
    aux = NULL;

    // Decrementa a quantidade de elementos
    l->elementos--;

    return aux2;
}

/** Fun��o que conta a frequ�ncia de ocorr�ncias dos bytes de um dado arquivo
* @param: um arquivo, uma lista de bytes
*/

void getByteFrequency(FILE *entrada, unsigned int *listaBytes)
{

    byte c;

    /***
    *
    * fread( array/bloco de memoria , tamanho de cada elemento, quantos elementos, arquivo de entrada )
    * fread retorna a quantidade de blocos lidos com sucesso
    *
    * Faz a leitura de 1 bloco de tamanho 1 byte a partir do arquivo 'entrada'
    * e salva no espaco de memoria de 'c'.
    *
    * Converte esse byte num valor decimal, acessa o bucket correspondente e incrementa o valor (frequ�ncia).
    *
    ***/

    while (fread(&c, 1, 1, entrada) >= 1)
    {
        listaBytes[(byte)c]++;
    }
    rewind(entrada); // "rebobina o arquivo"

}

#include <stdbool.h>

//  Obtem o c�digo come�ando no n� n, utilizando o byte salvo em 'c', preenchendo 'buffer', desde o bucket 'tamanho'

/**
/ Fun��o recursiva que percorre uma �rvore de huffman e para ao encontrar o byte procurado (c)
/ @param: n� para iniciar a busca, byte a ser buscado, buffer para salvar os n�s percorridos, posi��o para escrever
**/

bool pegaCodigo(nodeArvore *n, byte c, char *buffer, int tamanho)
{

    // Caso base da recurs�o:
    // Se o n� for folha e o seu valor for o buscado, colocar o caractere terminal no buffer e encerrar

    if (!(n->esquerda || n->direita) && n->c == c)
    {
        buffer[tamanho] = '\0';
        return true;
    }
    else
    {
        bool encontrado = false;

        // Se existir um n� � esquerda
        if (n->esquerda)
        {
            // Adicione '0' no bucket do buffer correspondente ao 'tamanho' nodeAtual
            buffer[tamanho] = '0';

            // fazer recurs�o no n� esquerdo
            encontrado = pegaCodigo(n->esquerda, c, buffer, tamanho + 1);
        }

        if (!encontrado && n->direita)
        {
            buffer[tamanho] = '1';
            encontrado = pegaCodigo(n->direita, c, buffer, tamanho + 1);
        }
        if (!encontrado)
        {
            buffer[tamanho] = '\0';
        }
        return encontrado;
    }

}

// Algoritmo para construir a �rvore de huffman, inspirado no seguinte pseudoc�digo:
// http://www.cs.gettysburg.edu/~ilinkin/courses/Spring-2014/cs216/assignments/a8.html
//
// procedure BUILD-TREE(frequencies):
//     pq ? make empty priority queue
//     for each (symbol, key) in frequencies:
//         h ? make a leaf node for the (symbol, key) pair
//         INSERT(pq, h)
//
//     n ? size[pq]
//     for i = 1 to n-1:
//         h1 ? POP-MIN(pq)
//         h2 ? POP-MIN(pq)
//         h3 ? MAKE-NODE(h1, h2)
//         INSERT(pq, h3)
//
//     return POP-MIN(pq)

/** Fun��o que constr�i a �rvore de huffman
* @param: a fila de prioridade.
*/

nodeArvore *BuildHuffmanTree(unsigned *listaBytes)
{
    // Lista com head apontando pra NULL e com campo 'elementos' valendo 0;
    lista l = {NULL, 0};

    // Popula usando a array 'listaBytes' (que cont�m as frequ�ncias) uma lista encadeada de n�s.
    // Cada n� cont�m uma �rvore.
    for (int i = 0; i < 256; i++)
    {
        if (listaBytes[i]) // Se existe ocorr�ncia do byte
        {
            // Insere na lista 'l' um n� referente ao byte i e sua respectiva frequ�ncia (guardada em listaBytes[i]).
            // Faz os n�s esquerdo e direito das �rvores apontarem para NULL;
            insereLista(novoNodeLista(novoNodeArvore(i, listaBytes[i], NULL, NULL)), &l);
        }
    }

    while (l.elementos > 1) // Enquanto o n�mero de elementos da lista for maior que 1
    {
        // N� esquerdo chama a fun��o popMinLista() que vai na lista e pega a �rvore fixada no primeiro n�
        // (que � a que cont�m a menor frequ�ncia)
        nodeArvore *nodeEsquerdo = popMinLista(&l);

        // Pega o outro n� que tem menor frequ�ncia
        nodeArvore *nodeDireito = popMinLista(&l);

        // Preenche com '#' o campo de caractere do n� da �rvore.
        // Preenche o campo 'frequ�ncia' com a soma das frequ�ncias de 'nodeEsquerdo' e 'nodeDireito'.
        // Aponta o n� esquerdo para nodeEsquerdo e o n� direito para nodeDireito
        nodeArvore *soma = novoNodeArvore(
                               '#',
                               nodeEsquerdo->frequencia + nodeDireito->frequencia, nodeEsquerdo, nodeDireito
                           );

        // Reinsere o n� 'soma' na lista l
        insereLista(novoNodeLista(soma), &l);
    }

    return popMinLista(&l);
}

/** Fun��o que libera mem�ria da �rvore de huffman
* @param: n� de uma (sub)�rvore.
*/

void FreeHuffmanTree(nodeArvore *n)
{
    // Caso base da recurs�o, enquanto o n� n�o for NULL
    if (!n) return;
    else
    {
        nodeArvore *esquerda = n->esquerda;
        nodeArvore *direita = n->direita;
        free(n);
        FreeHuffmanTree(esquerda);
        FreeHuffmanTree(direita);
    }
}

/** Fun��o que faz bitmasking no byte lido e retorna um valor booleano confirmando sua exist�ncia
* Ideia do bitmasking surgiu da leitura de http://ellard.org/dan/www/CS50-95/s10.html
* @param: arquivo para ler o byte, posi��o que se deseja mascarar o byte, byte a ser feita a checagem
*/

int geraBit(FILE *entrada, int posicao, byte *aux )
{
    // � hora de ler um bit?
    (posicao % 8 == 0) ? fread(aux, 1, 1, entrada) : NULL == NULL ;

    // Exclama��o dupla converte para '1' (inteiro) se n�o for 0. Caso contr�rio, deixa como est� (0)
    // Joga '1' na casa bin�ria 'posicao' e v� se "bate" com o byte salvo em *aux do momento
    // Isso � usado para percorrer a �rvore (esquerda e direita)
    return !!((*aux) & (1 << (posicao % 8)));
}

/** Fun��o para notificar aus�ncia do arquivo. Encerra o programa em seguida.
*/
void erroArquivo()
{
    printf("Arquivo nao encontrado\n");
    exit(0);
}

/** Fun��o que comprime um arquivo utilizando a compress�o de huffman
* @param: arquivo a comprimir, arquivo resultado da compress�o
*/

void CompressFile(const char *arquivoEntrada, const char *arquivoSaida)
{

    clock_t inicio, final;
    double tempoGasto;
    inicio = clock();

    unsigned listaBytes[256] = {0};

    // Abre arquivo do par�metro arquivoEntrada no modo leitura de bin�rio
    FILE *entrada = fopen(arquivoEntrada, "rb");
    (!entrada) ? erroArquivo() : NULL == NULL ;

    // Abre arquivo do par�metro arquivoSaida no modo escrita de bin�rio
    FILE *saida = fopen(arquivoSaida, "wb");
    (!saida) ? erroArquivo() : NULL == NULL ;

    getByteFrequency(entrada, listaBytes);

    // Populando a �rvore com a lista de frequ�ncia de bytes
    nodeArvore *raiz = BuildHuffmanTree(listaBytes);

    // Grava a lista de frequ�ncia nos primeiros 256 bytes do arquivo
    fwrite(listaBytes, 256, sizeof(listaBytes[0]), saida);

    // Move o ponteiro do stream 'saida' para a posi��o posterior ao tamanho de um unsigned int
    // � aqui que posteriormente ser� salvo o valor da vari�vel 'tamanho'
    fseek(saida, sizeof(unsigned int), SEEK_CUR);

    byte c;
    unsigned tamanho = 0;
    byte aux = 0;

    /***
    * fread( array/bloco de memoria , tamanho de cada elemento, quantos elementos, arquivo de entrada )
    * fread retorna a quantidade de bytes lidos com sucesso
    *
    * Faz a leitura de 1 bloco de tamanho 1 byte a partir do arquivo 'entrada'
    * e salva no espaco de memoria de 'c'.
    ***/

    while (fread(&c, 1, 1, entrada) >= 1)
    {

        // Cria um buffer vazio
        char buffer[1024] = {0};

        // Busca o c�digo come�ando no n� 'raiz', utilizando o byte salvo em 'c', preenchendo 'buffer', desde o bucket deste �ltimo
        pegaCodigo(raiz, c, buffer, 0);

        // La�o que percorre o buffer
        for (char *i = buffer; *i; i++)
        {
            // Se o caractere na posi��o nodeAtual for '1'
            if (*i == '1')
            {
                // 2 elevado ao resto da divis�o de 'tamanho' por 8
                // que � o mesmo que jogar um '1' na posi��o denotada por 'tamanho % 8'
                //aux = aux + pow(2, tamanho % 8);
                aux = aux | (1 << (tamanho % 8));
            }

            tamanho++;

            // J� formou um byte, � hora de escrev�-lo no arquivo
            if (tamanho % 8 == 0)
            {
                fwrite(&aux, 1, 1, saida);
                // Zera a vari�vel auxiliar
                aux = 0;
            }
        }
    }

    // Escreve no arquivo o que sobrou
    fwrite(&aux, 1, 1, saida);

    // Move o ponteiro do stream para 256 vezes o tamanho de um unsigned int, a partir do in�cio dele (SEEK_SET)
    fseek(saida, 256 * sizeof(unsigned int), SEEK_SET);

    // Salva o valor da vari�vel 'tamanho' no arquivo saida
    fwrite(&tamanho, 1, sizeof(unsigned), saida);

    final = clock();
    tempoGasto = (double)(final - inicio) / CLOCKS_PER_SEC;

    // Calcula tamanho dos arquivos
    fseek(entrada, 0L, SEEK_END);
    double tamanhoEntrada = ftell(entrada);

    fseek(saida, 0L, SEEK_END);
    double tamanhoSaida = ftell(saida);

    FreeHuffmanTree(raiz);

    printf("Arquivo de entrada: %s (%g bytes)\nArquivo de saida: %s (%g bytes)\nTempo gasto: %gs\n", arquivoEntrada, tamanhoEntrada / 1000, arquivoSaida, tamanhoSaida / 1000, tempoGasto);
    printf("Taxa de compressao: %d%%\n", (int)((100 * tamanhoSaida) / tamanhoEntrada));

    fclose(entrada);
    fclose(saida);

}

/** Fun��o que descomprime um arquivo utilizando a compress�o de huffman
* @param: arquivo a descomprimir, arquivo resultado da descompress�o
*/

void DecompressFile(const char *arquivoEntrada, const char *arquivoSaida)
{

    clock_t inicio, final;
    double tempoGasto;
    inicio = clock();

    unsigned listaBytes[256] = {0};

    // Abre arquivo do par�metro arquivoEntrada no modo leitura de bin�rio
    FILE *entrada = fopen(arquivoEntrada, "rb");
    (!entrada) ? erroArquivo() : NULL == NULL ;

    // Abre arquivo do par�metro arquivoSaida no modo escrita de bin�rio
    FILE *saida = fopen(arquivoSaida, "wb");
    (!saida) ? erroArquivo() : NULL == NULL ;

    // L� a lista de frequ�ncia que encontra-se nos primeiros 256 bytes do arquivo
    fread(listaBytes, 256, sizeof(listaBytes[0]), entrada);

    // Constr�i �rvore
    nodeArvore *raiz = BuildHuffmanTree(listaBytes);

    // L� o valor dessa posi��o do stream para dentro da vari�vel tamanho
    unsigned tamanho;
    fread(&tamanho, 1, sizeof(tamanho), entrada);

    unsigned posicao = 0;
    byte aux = 0;

    // Enquanto a posicao for menor que tamanho
    while (posicao < tamanho)
    {
        // Salvando o nodeArvore que encontramos
        nodeArvore *nodeAtual = raiz;

        // Enquanto nodeAtual n�o for folha
        while ( nodeAtual->esquerda || nodeAtual->direita )
        {
            nodeAtual = geraBit(entrada, posicao++, &aux) ? nodeAtual->direita : nodeAtual->esquerda;
        }

        fwrite(&(nodeAtual->c), 1, 1, saida);
    }

    FreeHuffmanTree(raiz);

    final = clock();
    tempoGasto = (double)(final - inicio) / CLOCKS_PER_SEC;

    fseek(entrada, 0L, SEEK_END);
    double tamanhoEntrada = ftell(entrada);

    fseek(saida, 0L, SEEK_END);
    double tamanhoSaida = ftell(saida);

    printf("Arquivo de entrada: %s (%g bytes)\nArquivo de saida: %s (%g bytes)\nTempo gasto: %gs\n", arquivoEntrada, tamanhoEntrada / 1000, arquivoSaida, tamanhoSaida / 1000, tempoGasto);
    printf("Taxa de descompressao: %d%%\n", (int)((100 * tamanhoSaida) / tamanhoEntrada));

    fclose(saida);
    fclose(entrada);
}


int main(int argc, char *argv[])
{
    // Caso os par�metros informados sejam insuficientes
    if (argc < 4)
    {
        printf("Uso: huffman [OPCAO] [ARQUIVO] [ARQUIVO]\n\n");
        printf("Opcoes:\n");
        printf("\t-c\tComprime\n");
        printf("\t-x\tDescomprime\n");
        printf("\nExemplo: ./huffman -c comprima.isso nisso.hx\n");
        return 0;
    }

    if (strcmp("-c", argv[1]) == 0)
    {
        if (strstr(argv[3], ".hx"))
        {
            CompressFile(argv[2], argv[3]);
        }
        else
        {
            printf("O arquivo resultante da compressao deve ter a extensao '.hx'.\n");
            printf("Exemplo: \n\t./huffman -c comprima.isso nisso.hx\n");
            return 0;
        }
    }
    else if (strcmp("-x", argv[1]) == 0)
    {
        if (strstr(argv[2], ".hx"))
        {
            DecompressFile(argv[2], argv[3]);
        }
        else
        {
            printf("O arquivo a ser descomprimido deve ter a extensao '.hx'.\n");
            printf("Exemplo: \n\t./huffman -x descomprime.hx nisso.extensao\n");
            return 0;
        }
    }
    else
    {
        printf("Uso: huffman [OPCAO] [ARQUIVO] [ARQUIVO]\n\n");
        printf("Opcoes:\n");
        printf("\t-c\tComprime\n");
        printf("\t-x\tDescomprime\n");
        printf("\nExemplo: ./huffman -c comprima.isso nisso.hx\n");
        return 0;
    }

    //CompressFile("meslo.ttf", "meslo.hx");
    //DecompressFile("meslo.hx", "meslo_copy.ttf");

    return 0;
}