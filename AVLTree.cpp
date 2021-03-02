#include "AVLTree.h"
#include <cmath>


AVLTree::AVLTree()
{
    raiz = NULL;
}

AVLTree::~AVLTree()
{
    // destrutor vazio (só para avaliação)
}

int AVLTree::altura()
{
    if(raiz == NULL)
    {
        cout << "Arvore Vazia!" << endl;
        return -1;
    }
    else
        return auxAltura(raiz);
}

int AVLTree::alturaNo(NoArv *p)
{
    if(p == NULL)
    {
        return -1;
    }
    else
        return auxAltura(p);
}

int AVLTree::auxAltura(NoArv *p)
{
    if(p!=NULL)
    {
        int he = auxAltura(p->getEsq());
        int hd = auxAltura(p->getDir());

        return 1 + (he > hd ? he : hd);
    }
    else return -1;
}

int AVLTree::getBalanceada(NoArv *N) 
{ 
    if (N == NULL) 
        return 0;
    else 
        return alturaNo(N->getDir()) - alturaNo(N->getEsq()); 
} 

NoArv* AVLTree::rotacaoSimplesEsquerda(NoArv *no)
{
    NoArv* q = no->getDir();
    no->setDir(q->getEsq());
    q->setEsq(no);

    //raiz = q;
    return q;
}

NoArv* AVLTree::rotacaoSimplesDireita(NoArv *no)
{
    NoArv* q = no->getEsq();
    no->setEsq(q->getDir());
    q->setDir(no);

    //raiz = q;
    return q;
}

NoArv* AVLTree::rotacaoDuplaEsquerda(NoArv *p)
{
    NoArv* q = p->getDir(); 
    NoArv* r = q->getEsq();

    p->setDir(r->getEsq());
    q->setEsq(r->getDir());

    r->setEsq(p);
    r->setDir(q);

    //raiz = r;
    return r;
}

NoArv* AVLTree::rotacaoDuplaDireita(NoArv *p)
{
    NoArv* q = p->getEsq();
    NoArv* r = q->getDir();

    p->setEsq(r->getDir());
    q->setDir(r->getEsq());

    r->setDir(p);
    r->setEsq(q);

    //raiz = r;
    return r;
} 
int AVLTree::dataigual(int x,NoArv *p,Hashing *tabela)
{
  
    if(tabela->getData(x) < tabela->getData(p->getInfo()))
        return 1;
    else 
        return 0;

    
}
void AVLTree::insere(int x,Hashing *tabela)
{
    raiz = auxInsere(raiz, x,tabela);
}

NoArv* AVLTree::auxInsere(NoArv *p, int x,Hashing *tabela)
{   
    
    
   
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
       // p->setAltura(1);
    } 
    /*
    else if(x < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), x,tabela));
    else if(x > p->getInfo())
        p->setDir(auxInsere(p->getDir(), x,tabela));
    else
        return p; 
    */
   
    else if(tabela->getCodigo(x) < tabela->getCodigo(p->getInfo()))
        p->setEsq(auxInsere(p->getEsq(), x,tabela));
    else if(tabela->getCodigo(x) > tabela->getCodigo(p->getInfo()))
        p->setDir(auxInsere(p->getDir(),x,tabela));
    else if(dataigual(x,p,tabela))
         p->setEsq(auxInsere(p->getEsq(), x,tabela));
    else 
        p->setDir(auxInsere(p->getDir(),x,tabela));
    
    return p;
    // checa se o No esta balanceado
    
    int equilibrio = getBalanceada(p); 

    //cout << "o no com chave " << p->getInfo() << " tem balanceamento "     << equilibrio  << endl; 
    p->setAltura(alturaNo(p));
    //cout << "o no com chave " << p->getInfo() << " possui altura igual a " << p->getAltura() << endl; 
 
    // Se está desbalanceada, vai ser um dos 4 casos:
    // Rotacao simples a esquerda:
    
    if((getBalanceada(p) > 2) && (  getBalanceada(p->getDir()) == 1  || 
                                    getBalanceada(p->getDir()) == 0  ))
    {
        
        return rotacaoSimplesEsquerda(p);
    }
    // Rotacao simples a direita:

    if((getBalanceada(p) ==-2) && (  getBalanceada(p->getEsq()) == 1  ||
                                     getBalanceada(p->getEsq()) == 0  ))

        return rotacaoSimplesDireita(p);

    // Rotacao dupla a esquerda:
    
    if((getBalanceada(p) == 2) && (  getBalanceada(p->getDir()) ==-1  ))

        return rotacaoDuplaEsquerda(p);
        //p->setDir(rotacaoSimplesDireita(p->getDir()));
        //return rotacaoSimplesEsquerda(p);

    // Rotacao dupla a direita:

    if((getBalanceada(p) ==-2) && (  getBalanceada(p->getEsq()) == 1  ))

        return rotacaoDuplaDireita(p); 
        //p->setEsq(rotacaoSimplesEsquerda(p->getEsq()));
        //return rotacaoSimplesDireita(p);
 
   
    return p; 
}

void AVLTree::imprime(Hashing *tabela)
{
    auxImprime(raiz,tabela);
    cout << endl;
}

int AVLTree::max(int a, int b)
{
    return (a > b) ? a : b;
}

void AVLTree::auxImprime(NoArv *p,Hashing *tabela)
{
    if(p != NULL)
    {
        cout << p->getInfo() << " "<<"MEU CU ASSADINHO: "<<tabela->getCodigo(p->getInfo())<<"MEU PIRUZINHO: "<<tabela->getData(p->getInfo())<<endl;
        auxImprime(p->getEsq(),tabela);
        auxImprime(p->getDir(),tabela);
    }
}

int AVLTree::impares()
{
    int impa = 0;

    if(raiz == NULL)
    {
        cout << "Arvore vazia" << endl;
        return -1;
    }
    else
    {
        auxImpares(raiz, &impa);
        return impa;
    }
}

void AVLTree::auxImpares(NoArv *p, int *impa)
{
    if(p != NULL)
    {
        if(p->getInfo()%2 != 0)
        {
            (*impa)++;
        }
        auxImpares(p->getEsq(), impa);
        auxImpares(p->getDir(), impa);
    }
}

int AVLTree::soma()
{
    int soma = 0;

    if(raiz == NULL)
    {
        cout << "Arvore vazia" << endl;
        return -1;
    }
    else
    {
        auxSoma(raiz, &soma);
        return soma;
    }
}

void AVLTree::auxSoma(NoArv *p, int *soma)
{
    if(p != NULL)
    {
        (*soma) += p->getInfo();
        auxSoma(p->getEsq(), soma);
        auxSoma(p->getDir(), soma);
    }
}

int AVLTree::maiorValor()
{
    int maior;
    NoArv *p = raiz;
    if(p == NULL)
    {
        cout << "Arvore vazia! BURRO" << endl;
        return -1;
    }
    else
    {
        maior = raiz->getInfo();

        auxMaiorValor(p, &maior);
        return maior;
    }
}

void AVLTree::auxMaiorValor(NoArv *p, int *maior)
{
    if(p != NULL)
    {
        {
            auxMaiorValor(p->getEsq(), maior);
            if(p->getInfo() > *maior)
                *maior = p->getInfo();
            auxMaiorValor(p->getDir(), maior);
        }
    }
}

int AVLTree::menorValor()
{
    int menor;
    NoArv *p = raiz;
    if(p == NULL)
    {
        cout << "Arvore vazia!" << endl;
        return -1;
    }
    else
    {
        menor = raiz->getInfo();

        auxMenorValor(p, &menor);
        return menor;
    }
}

void AVLTree::auxMenorValor(NoArv *p, int *menor)
{
    if(p != NULL)
    {
        if(p->getInfo() < *menor)
            *menor = p->getInfo();
        auxMenorValor(p->getEsq(), menor);
        auxMenorValor(p->getDir(), menor);
    }
}

int AVLTree::numNos()
{
    int nos = 0;
    if(raiz == NULL)
    {
        cout << "Arvore Vazia!" << endl;
        return -1;
    }
    else
    {
        auxNumNos(raiz, &nos);
        return nos;
    }
}

void AVLTree::auxNumNos(NoArv *p, int *nos)
{
    if(p != NULL)
    {
        (*nos)++;
        auxNumNos(p->getEsq(), nos);
        auxNumNos(p->getDir(), nos);
    }
}

bool AVLTree::eCheia()
{
    if(raiz != NULL)
    {
        if((numNos() == pow(2,(altura()+1) - 1)))
        {
            return true;
        }
        else
            return false;
    }
    return false;
}

float AVLTree::media()
{
    int cont;
    float soma;

    if (raiz == NULL)
    {
        cout << "Arvore vazia!" << endl;
        return -1;
    }
    else
        auxMedia(raiz, &cont, &soma);
        return soma/(float)cont;
}

void AVLTree::auxMedia(NoArv *p, int *cont, float *media)
{
    if(p != NULL)
    {
        *media = *media + p->getInfo();
        (*cont)++;
    }
    auxMedia(p->getEsq(), cont, media);
    auxMedia(p->getDir(), cont, media);
}

int AVLTree::maiores(int val)
{
    int maior = 0;
    if(raiz == NULL)
    {
        cout << "Arvore vazia! " << endl;
        return -1;
    }
    else
    {
        auxMaiores(raiz, val, &maior);
        return maior;
    }
}

void AVLTree::auxMaiores(NoArv *p, int val, int *maior)
{
    if(p != NULL)
    {
        if(p->getInfo() > val)
        {
            (*maior)++;
        }
        auxMaiores(p->getEsq(), val, maior);
        auxMaiores(p->getDir(), val, maior);
    }
}

void AVLTree::imprimeNivel(int k)
{
    int cont = 0;
    if(raiz == NULL)
    {
        cout << "Arvore vazia!" << endl;
        return;
    }
    else
        auxImprimeNivel(raiz, cont, k);
}

void AVLTree::auxImprimeNivel(NoArv *p, int cont, int k)
{
    if(p != NULL)
    {
        if(cont == k)
            cout << p->getInfo() << ", " << endl;
        auxImprimeNivel(p->getEsq(), cont+1, k);
        auxImprimeNivel(p->getDir(), cont+1, k);
    }
}

///atual funciona como o cont do exerc. anterior
/*float AVLTree::mediaNivel(int k)
{
    float soma = 0;
    int cont = 0, atual = 0;
    if(raiz == NULL)
    {
        cout << "Arvore vazia!" << endl;
        return -1;
    }
    else
        auxMediaNivel(raiz, atual, &cont, &soma, k);
    return soma/(float)cont;
}

float AVLTree::auxMediaNivel(NoArv *p, int atual, int *cont, float *soma, int k)
{
    if(p == NULL)
    {
        return 0;
    }
    else if(atual == k)
    {
        *soma = *soma + p->getInfo();
        (*cont)++;
    }
    auxMediaNivel(p->getEsq(), atual + 1, cont, soma, k);
    auxMediaNivel(p->getDir(), atual + 1, cont, soma, k);
}*/

void AVLTree::imprimeFilhos(int x)
{
    NoArv *p = raiz;
    if(p == NULL)
    {
        cout << "Arvore vazia! " << endl;
        return;
    }
    else
    {
        while(p != NULL)
        {
            if(p->getInfo() == x)
            {
                cout << "Filho do no " << x << " a esquerda: " << ((p->getEsq())->getInfo()) << endl;
                cout << "Filho do no " << x << " a direita: " << ((p->getDir())->getInfo()) << endl;
                p = NULL;
            }
            else if(p->getInfo() > x)
            {
                p = p->getEsq();
            }
            else if(p->getInfo() < x)
            {
                p = p->getDir();
            }
        }
        return;
    }
}

/*void AVLTree::imprimeIntervalo(int x, int y)
{
    if(raiz == NULL)
    {
        cout << "Arvore vazia! " << endl;
        return;
    }
    else
        cout << "Imprimindo nos no intervalo " << x << " a " << y << endl;
        auxImprimeIntervalo(raiz, x, y);
}

void AVLTree::auxImprimeIntervalo(NoArv *p, int x, int y)
{
    if(p != NULL)
    {
        if(p->getInfo() < x)
        {
            auxImprimeIntervalo(p->getDir(), x, y);
        }
        else if(p->getInfo() > y)
        {
            auxImprimeIntervalo(p->getEsq(), x, y);
        }
        else if((p->getInfo()) >= x && (p->getInfo() <= y))
        {
            auxImprimeIntervalo(p->getEsq(), x, y);
            cout << p->getInfo() << ", " << endl;
            auxImprimeIntervalo(p->getDir(), x, y);
        }
    }
}*/

void AVLTree::imprimeCrescente()
{
    if(raiz == NULL)
    {
        return;
    }
    else
    {
        cout << "Imprimindo os valores em ordem crescente: ";
        auxImprimeCrescente(raiz);
    }
}

void AVLTree::auxImprimeCrescente(NoArv *p)
{
    if(p!=NULL)
    {
        auxImprimeCrescente(p->getEsq());
        cout << p->getInfo() << " ";
        auxImprimeCrescente(p->getDir());
    }
}

void AVLTree::imprimeDecrescente()
{
    if(raiz == NULL)
    {
        return;
    }
    else
    {
        cout << "Imprimindo os valores em ordem decrescente: ";
        auxImprimeDecrescente(raiz);
    }
}

void AVLTree::auxImprimeDecrescente(NoArv *p)
{
    if(p!=NULL)
    {
        auxImprimeDecrescente(p->getDir());
        cout << p->getInfo() << " ";
        auxImprimeDecrescente(p->getEsq());
    }
}

///inserindo do vetor em uma matriz degenerada:
/*void AVLTree::insereDoVetor1(int n, int *vet)
{
    NoArv *p = raiz;
    int i = 0;
    if(raiz == NULL)
    {
        while(i < n)
        {
            insere(vet[i]);;
            i++;
        }
    }
} */

///inserindo do vetor em uma matriz completa:
/*void AVLTree::insereDoVetor2(int n, int *vet)
{
    NoArv *p = raiz;
    int meio = (n/2)+1;
    int i = 0;
    int j = meio + 1;
    if(raiz == NULL)
    {
        p->setInfo(vet[meio]);
        while(i < meio)
        {
            insere(vet[i]);
            i++;
        }
        while(j < n)
        {
            insere(vet[j]);
            j++;
        }
    }
    return;
}*/

NoArv* AVLTree::buscaValor(int val, Hashing *tabela)
{
    NoArv* p = raiz;
    if(raiz == NULL)
    {
        cout << "Arvore vazia!";
        return NULL;
    }

    //teste com AVL padrão
    /*else
    {
        while(p != NULL)
        {
            if(p->getInfo() == val)
            {
                return p;
            }
            else if(p->getInfo() < val)
                p = p->getDir();
            else if(p->getInfo() > val)
                p = p->getEsq();
        }
        return NULL;
    } */

    //teste com a AVL do trab memo
    else
    {
        while(p != NULL)
        {
            if( tabela->getCodigo(p->getInfo()) == tabela->getCodigo(val) )
            {
                if( tabela->getData(p->getInfo()) == tabela->getData(val) )
                    return p;
                else if( tabela->getData(p->getInfo()) < tabela->getData(val) )
                    p = p->getDir();
                else if( tabela->getData(p->getInfo()) > tabela->getData(val) )
                    p = p->getEsq();
            }
        
            else if( tabela->getCodigo(p->getInfo()) < tabela->getCodigo(val) )
                p = p->getEsq();
            else if( tabela->getCodigo(p->getInfo()) > tabela->getCodigo(val) )
                p = p->getDir();
        }
        
        //valor nao encontrado
        return NULL;
    }
    

}

/*int AVLTree::classificaNo(int val)
{
    NoArv *noVal = raiz;
    if(noVal != NULL)
    {
        while(noVal != NULL)
        {
            if(noVal->getInfo() == val)
            {
                if(noVal->getEsq() == NULL && noVal->getDir() != NULL)
                {
                    return 1;
                }
                else if(noVal->getDir() == NULL && noVal->getEsq() != NULL)
                {
                    return 1;
                }
                else if(noVal->getDir() == NULL && noVal->getEsq() == NULL)
                {
                    return 0;
                }
                else if(noVal->getDir() != NULL && noVal->getEsq() != NULL)
                {
                    return 2;
                }
            }
            else if(noVal->getInfo() < val)
                noVal = noVal->getDir();
            else if(noVal->getInfo() > val)
                noVal = noVal->getEsq();
        }
    }
}*/

void AVLTree::remove(int x)
{
    raiz = auxRemove(raiz, x);
}

NoArv* AVLTree::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv* AVLTree::removeNo1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir(); //filho único é da direita
    else
        aux = p->getEsq(); //filho único é da esquerda
    delete p;
    return aux;
}

NoArv* AVLTree::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir(); //nó à direita de p
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

NoArv* AVLTree::auxRemove(NoArv *p, int x)
{
    if(p == NULL)
        return NULL;
    else if(x < p->getInfo())//remove na sub. esquerda
        p->setEsq(auxRemove(p->getEsq(), x));
    else if(x > p->getInfo())// remove na sub. direita
        p->setDir(auxRemove(p->getDir(), x));
    else
    {// achou o nó a ser removido, p->getInfo() == x
        if((p->getEsq() == NULL)&&(p->getDir() == NULL))
            p = removeFolha(p);// p aponta para uma folha
        else if((p->getEsq() == NULL)||(p->getDir() == NULL))
            p = removeNo1Filho(p); //p tem só um filho
        else
        {
            //p tem dois filhos
            NoArv *aux = menorSubArvDireita(p);
            // troca as informações
            int auxInt = aux->getInfo();
            p->setInfo(auxInt);
            aux->setInfo(x);
            // recursão: para a subarv. direita
            p->setDir(auxRemove(p->getDir(), x));
        }
    }
    return p;
}