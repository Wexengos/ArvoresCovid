#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <vector>
#include "QuadTree.h"
#include "AVLTree.h"
#include "ArvB.h"
#include "RegistroCoordinates.h"

using namespace std;

using namespace std::chrono;
#define TAMANHOMAX 1431490
#define QUANTCIDADES 5571


//g++ -o teste -O3 *.cpp
//.teste
void menuPrincipal(Registro *registros,RegistroCoordinates *registrosCoord,Hashing *hashPrinci,QuadTree *quadPrinci,int *idhash,int t);
void moduloTeste(Registro *registro, RegistroCoordinates *registroCidades,Hashing *hashPrinci,QuadTree *quadPrinci,int *idhash,int t);


void criaArquivoSaidaTxt(string nomeArquivo)
{
    ofstream arq(nomeArquivo);
    arq.close();
}

void testeQuadTree(RegistroCoordinates *registroCidades, int N)
{

    QuadTree *quad = new QuadTree();

    //arq."Cidades Inseridades na QuadTree"<<endl;
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        NoArvQuad *no = new NoArvQuad();
        no->setLatitude(registroCidades[i].getLatitude());
        no->setLongitude(registroCidades[i].getLongitude());
        no->setNome(registroCidades[i].getcidade_nome());
        no->setCodigo(registroCidades[i].getcidadeCodigo());
        quad->insere(no);
      
    }
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    int tem = duration_cast<duration<double>>(fim - inicio).count();

    if (N <= 20)
    {
        cout << "Saida Console" << endl;
        quad->imprime();
    }
    else
    {
        cout << "Arquivo TXT criado" << endl;
        ofstream arq; // ("a:lista.dat", ios::ate | ios::out | ios::in)
        arq.open("QuadTree.txt", ios::ate | ios::out | ios::in);
        quad->imprimeTXT(arq);
        arq << "Tempo: " << tem << endl;
        arq.close();
    }

    vector<NoArvQuad*> vet;
    criaArquivoSaidaTxt("QuadIntervaloTXT");
    ofstream arq1;
    arq1.open("QuadIntervaloTXT", ios::ate | ios::out | ios::in);
    //referencias: x -> -21.0276    y -> -44.3204 ; 
    //                                   x0,   x,  y0,   y
    quad->cidadesNoIntervalo(vet, arq1, -18, -16, -22, -20);

    arq1<<"Contador: "<<quad->getCont() << endl;
    for(int i=0; i<vet.size(); i++)
    {
        arq1<<"Nome: " << vet.at(i)->getNome() << endl;
        cout << vet.at(i)->getNome() << endl;
    }
    arq1.close();

    cout << "Final" << endl;
}

void testeHash(Registro *registro, int N)
{

    Hashing *hash = new Hashing(N);
    int cont = 0;
    register int chave, id;

    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        
        chave = registro[i].getCodigoCidade() + registro[i].getDataInt();
        id = hash->insere(chave, &registro[i]);
        cont++;
       
    }
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    double tem = duration_cast<duration<double>>(fim - inicio).count();
    if (N <= 20)
    {
        cout << "Saida no Console ===> Cidades Inseridas na Hash" << endl;
        hash->imprime();
    }
    else
    {
        cout << "Arquivo TXT criado" << endl;
        ofstream arq; // ("a:lista.dat", ios::ate | ios::out | ios::in)
        arq.open("Hashing.txt", ios::ate | ios::out | ios::in);
        hash->imprimeTXT(arq);
        hash->casosTotaisCidade(330010);
        arq << "Tempo: " << tem << endl;
        arq.close();
    }
    cout << endl;
    cout << "Ch: " << hash->getChavesArmazenadas() << endl;
    cout << "Teste finalizado" << endl;
}

void testeAvl(Registro *registro, int N)
{
    Hashing *hash = new Hashing(N);
    register int chave, id;
    AVLTree *avl = new AVLTree();

    for (int i = 0; i < N; i++)
    {
        chave = registro[i].getCodigoCidade() + registro[i].getDataInt();
        id = hash->insere(chave, &registro[i]);
        avl->insere(id, hash);
    }

    if (N <= 20)
    {
        cout << "Saida no Console ===> Cidades Inseridas na Hash" << endl;
        avl->imprime(hash);
    }
    else
    {
        cout << "Arquivo TXT criado" << endl;
        ofstream arq; // ("a:lista.dat", ios::ate | ios::out | ios::in)
        arq.open("Avl.txt", ios::ate | ios::out | ios::in);
        avl->imprimeTXT(hash, arq);
        arq.close();
    }
  
    int cont=0;
    avl->buscaCodigo(315610, cont, hash);
    cout<<"(AVL) A cidade: "<<hash->getNome(315610)<<" Casos: "<<cont<<endl;
    cout << "Teste finalizado" << endl;
  
    hash->~Hashing();
}
void testeAVB(Registro *registro, int N)
{
    Hashing *hash = new Hashing(N);
    int cont = 0;
    register int chave, id;
    ArvB *arvB = new ArvB(20);

    for (int i = 0; i < N; i++)
    {
        chave = registro[i].getCodigoCidade() + registro[i].getDataInt();
        id = hash->insere(chave, &registro[i]);
        arvB->insereArvB(id, hash);
    }

    if (N <= 20)
    {
        cout << "Saida no Console ===> Cidades Inseridas na Hash" << endl;
        arvB->imprimeArv(hash);
    }
    else
    {
        cout << "Arquivo TXT criado" << endl;
        ofstream arq; // ("a:lista.dat", ios::ate | ios::out | ios::in)
        arq.open("AvB.txt", ios::ate | ios::out | ios::in);
        arvB->imprimeArvTXT(hash, arq);
        
    }
    int homer=0;
    arvB->buscaCodigo(315610,hash, homer);
    cout<<"(AVBuceta) A cidade: "<<hash->getNome(315610)<<" Casos: "<<homer<<endl;
    cout << "Teste finalizado" << endl;
    cout << endl;
    
    hash->~Hashing();
}


void etapa1(RegistroCoordinates *registrosCoordinate, QuadTree *quadPrincipal)
{       
        cout<<"Lendo Arquivo com as cidades e Armazenando na QuadTree"<<endl;
        registrosCoordinate->leArquivoCoordi(registrosCoordinate, QUANTCIDADES);
    
        for (int i = 0; i < QUANTCIDADES; i++)
        {
            NoArvQuad *no = new NoArvQuad();
            no->setLatitude(registrosCoordinate[i].getLatitude());
            no->setLongitude(registrosCoordinate[i].getLongitude());
            no->setNome(registrosCoordinate[i].getcidade_nome());
            no->setCodigo(registrosCoordinate[i].getcidadeCodigo());
           
            quadPrincipal->insere(no);
        }
  
}
void etapa2(Registro *registros,Hashing *hashingPrincipal,int *idhash)
{   
    cout<<"Lendo Registros e Armazenando na Hashing Table"<<endl;
    registros->leArquivo(registros,TAMANHOMAX);
    int chave, id;

    for (int i = 0; i < TAMANHOMAX; i++)
    {
        chave = registros[i].getCodigoCidade() + registros[i].getDataInt();
        id = hashingPrincipal->insere(chave, &registros[i]);
        idhash[i]=id;
    }   
    
    
}
void embaralhar(int *vet, int vetSize)
{   
    srand(time(NULL));
	for (int i = 0; i < vetSize; i++)
	{   
        if(vet[i]!=0){
            int r = rand() % vetSize;

            if(vet[r]!=0)
            {
                int temp = vet[i];
                vet[i] = vet[r];
                vet[r] = temp;
            }
        }
    }

   

}
void insere(int tamanho,Hashing *hashing,int *idhash,ArvB *ar)
{
    for(int j=0;j<tamanho;j++){
        ar->insereArvB(idhash[j],hashing);  
    }
}

void insere2(int tamanho,Hashing *hashing,int *idhash,AVLTree *ar)
{
    for(int j=0;j<tamanho;j++){
        ar->insere(idhash[j],hashing);  
    }
}

void execArvB(ArvB *arv,int N,std::ofstream& myfile,int *idhash,Hashing *hash,int tam,int codigo)
{
   
    
    int mediaComparacao = 0;
    double mediaTempoInsere = 0;
    double mediaBusca=0;
    int c;

    //Faz o teste para as quantidades de registros

    for (int exec = 0;exec < 5 ; exec++)
    {
        c = 0;

        high_resolution_clock::time_point inicio = high_resolution_clock::now();
        insere(N,hash,idhash,arv);   
        high_resolution_clock::time_point fim = high_resolution_clock::now();
        mediaTempoInsere = mediaTempoInsere + (duration_cast<duration<double>>(fim - inicio).count());

        //Busca
        high_resolution_clock::time_point inicio2 = high_resolution_clock::now();
        arv->buscaCodigo(codigo,hash,c); 
        high_resolution_clock::time_point fim2 = high_resolution_clock::now();
        mediaBusca = mediaBusca + (duration_cast<duration<double>>(fim2 - inicio2).count());

    }
    
    myfile<<"A cidade: "<<hash->getNome(codigo)<<" teve casos: "<< c/5 <<endl;
    myfile << "Media de Tempo em 5 execs de inserção: " << mediaTempoInsere / 5 << endl;
    myfile << "Media de Busca em 5 execs: " << mediaBusca / 5 << endl;
    c = 0;
   
}

void execAVL(AVLTree *arv,int N,std::ofstream& myfile,int *idhash,Hashing *hash,int tam,int codigo)
{
    int mediaComparacao = 0;
    double mediaTempoInsere = 0;
    double mediaBusca=0;
    int c;

    //Faz o teste para as quantidades de registros

    for (int exec = 0;exec < 5 ; exec++)
    {
        c = 0;

        high_resolution_clock::time_point inicio = high_resolution_clock::now();
        insere2(N,hash,idhash,arv);   
        high_resolution_clock::time_point fim = high_resolution_clock::now();
        mediaTempoInsere = mediaTempoInsere + (duration_cast<duration<double>>(fim - inicio).count());

        //Busca
        high_resolution_clock::time_point inicio2 = high_resolution_clock::now();
        arv->buscaCodigo(codigo,c,hash); 
        high_resolution_clock::time_point fim2 = high_resolution_clock::now();
        mediaBusca = mediaBusca + (duration_cast<duration<double>>(fim2 - inicio2).count());
    }
    

    myfile<<"A cidade: "<<hash->getNome(codigo)<<" teve casos: "<<c/5<<endl;
    myfile << "Media de Tempo em 5 execs de inserção: " << mediaTempoInsere / 5 << endl;
    myfile << "Media de Busca em 5 execs: " << mediaBusca / 5 << endl;
}

void buscaCasosS1(Hashing *hashPrinci,int *idHash,int tam)
{   
    int tamanhoN[] = {10000, 50000, 100000, 500000, 1000000};
    int opt;
    int codigo;
    int M=5;
    cout<<"Escolha como quer buscar a cidade" << endl;
    cout<<"Digite o Codigo da cidade"<<endl;
    cin >> codigo;
    //hashPrinci->casosTotaisCidade(codigo);

    //Randomização
    embaralhar(idHash,tam);//VETOR COM TODOS OS IDS GERADOS PELO HASHING SERA EMBARALHADO PARA GERAR IDS ALEATORIOS
    srand(time(NULL));
    
   

    criaArquivoSaidaTxt("saidaS1.txt");
    ofstream arq1;
    arq1.open("saidaS1.txt", ios::ate | ios::out | ios::in);

    ArvB *arvB = new ArvB(20);
    ArvB *arvB1 = new ArvB(200);
    AVLTree *arvl = new AVLTree();

    arq1<<"Arvore B com norma(20)"<<endl;
    for(int i=0;i<5;i++){
        arq1<<"Arvore com "<<tamanhoN[i]<<endl;
        execArvB(arvB,tamanhoN[i],arq1,idHash,hashPrinci,tam,codigo);
    }
    
    
    arq1<<"Arvore B com norma(200)"<<endl;
    for(int i=0;i<5;i++){
        arq1<<"Arvore com "<<tamanhoN[i]<<endl;
        execArvB(arvB,tamanhoN[i],arq1,idHash,hashPrinci,tam,codigo);
    }

    arq1<<"Arvore AVL"<<endl;
    for(int i=0;i<5;i++){
        arq1<<"Arvore com "<<tamanhoN[i]<<endl;
        execAVL(arvl,tamanhoN[i],arq1,idHash,hashPrinci,tam,codigo);
    }

}
void funcaoS2(Hashing *hashPrinci,int *idHash,int tam,QuadTree *quadPrinci)
{
     
    embaralhar(idHash,tam);//VETOR COM TODOS OS IDS GERADOS PELO HASHING SERA EMBARALHADO PARA GERAR IDS ALEATORIOS
    srand(time(NULL));
    int tamanhoN[] = {10000, 50000, 100000, 500000, 1000000};
    int N =  rand() % 4;
    int x0,y0,x,y;
    
    ArvB *arvB = new ArvB(20);
    AVLTree *arvl = new AVLTree();

    cout<<"Quant Aleatorios=> "<<tamanhoN[N]<<endl;
    for(int i=0;i<tamanhoN[N];i++)
    {
        arvB->insereArvB(idHash[i],hashPrinci);
    }

    for(int i=0; i<tamanhoN[N]; i++)
    {
        //cout<<"Inseriu "<<i<<endl;
        arvl->insere(idHash[i], hashPrinci);
    }
    
    cout<<"Escolha o intervalo que deseja busca"<<endl;
    cout<<"x0: "<<endl; cin>> x0;
    cout<<"y0: "<<endl; cin>> y0;
    cout<<"x: "<<endl; cin>> x;
    cout<<"y: "<<endl; cin>> y;

    vector<NoArvQuad*> vet;
    criaArquivoSaidaTxt("QuadIntervaloTXT");
    ofstream arq1;
    arq1.open("QuadIntervaloTXT", ios::ate | ios::out | ios::in);
    
    //referencias: x -> -21.0276    y -> -44.3204 ; 
    //                                   x0,   x,  y0,   y
    //-22.4694,-48.9863,
    //-7.0918,-38.1681,

    quadPrinci->cidadesNoIntervalo(vet, arq1, x0, x, y0, y);
    
    for(int i=0;i<vet.size();i++){
        int c=0;
        int &val=c;
        arvB->buscaCodigo(vet.at(i)->getCodigo(),hashPrinci,val);
        cout<<"A cidade: "<<hashPrinci->getNome(vet.at(i)->getCodigo())<<"Casos: "<<val<<endl;
    } 

    for(int j=0;j<vet.size();j++)
    {
        int cont=0;
        int &valor=cont;
        //arvl->buscaCodigo(vet.at(j)->getCodigo(), valor, hashPrinci);
        cout<<"(AVL) A cidade: "<<hashPrinci->getNome(vet.at(j)->getCodigo())<<"Casos: "<<valor<<endl;
    }
  
}

void etapa5(Hashing *hashPrinci,QuadTree *quadPrinci,int *idHash,int tam)
{  
    int opt;
    cout<<"Escolha uma opcao"<<endl;
    cout<<"[1] S1 "<<endl;
    cout<<"[2] S2 "<<endl;
    cin>>opt;


    if(opt == 1){
        buscaCasosS1(hashPrinci,idHash,tam);
    }
    if(opt == 2)
    {
        funcaoS2(hashPrinci,idHash,tam,quadPrinci);
    }

    
  
    


}
void menuPrincipal(Registro *registros,RegistroCoordinates *registrosCoord,Hashing *hashPrinci,QuadTree *quadPrinci,int *idhash,int t)
{   
   
    
    int menu;
    cout << "====================MENU PRINCIPAL====================" << endl;
    cout << "Digite:" << endl;
    cout << "[1] Carregar o arquivo de cidades " << endl;
    cout << "[2] Carregamento do arquivo pre-processado de casos" << endl;
    cout << "[3] Modulo de teste" << endl;
    cout << "[4] Etapa 5" << endl;
    cout << "[5] Fechar" << endl;
    cin >> menu;
    
    switch(menu)
    {
    case 1:
        system("cls");
        etapa1(registrosCoord,quadPrinci);
        cout << "Etapa 1 concluida!" << endl;
        menuPrincipal(registros,registrosCoord,hashPrinci,quadPrinci,idhash,t);
        break;
        
    case 2:
        system("cls");
        etapa2(registros,hashPrinci,idhash);
        cout << "Etapa 2 concluida!" << endl;
        menuPrincipal(registros,registrosCoord,hashPrinci,quadPrinci,idhash,t);
        break;
        
       
    case 3:
        system("cls");
        moduloTeste(registros, registrosCoord,hashPrinci,quadPrinci,idhash,t);
        cout << "Etapa 3 concluida!" << endl;
        break;
         
    case 4:
         system("cls");
         etapa5(hashPrinci,quadPrinci,idhash,t);
        menuPrincipal(registros,registrosCoord,hashPrinci,quadPrinci,idhash,t);
         
         break;
    case 5:
        cout << "Fechando Exec!" << endl;
        cout << "Muito obrigado Caniato" << endl;
        exit(1);
        break;
       
    default:
        cout << "Valor invalido" << endl;
        menuPrincipal(registros,registrosCoord,hashPrinci,quadPrinci,idhash,t);
        
        break;
    }
    cout << "Fim" << endl;
}
void moduloTeste(Registro *registro, RegistroCoordinates *registroCidades,Hashing *hashPrinci,QuadTree *quadPrinci,int *idhash,int t)
{
    
    int menuTeste, n;
    cout << "===============Modulo de Teste===============" << endl;
    cout << "[1] Insercao de N cidades na quad tree" << endl;
    cout << "[2] Insercao de N registros na tabela hash " << endl;
    cout << "[3] Insercao de N chaves na arvore AVL" << endl;
    cout << "[4] Insercao de N chaves na arvore B" << endl;
    cout << "[5] Voltar para o menu principal" << endl;

    cin >> menuTeste;

    switch (menuTeste)
    {
    case 1:
        system("cls");
        cout << "Digite N cidades que sera inseridas" << endl;
        cin >> n;
        criaArquivoSaidaTxt("QuadTree.txt");
        testeQuadTree(registroCidades, n);
        moduloTeste(registro, registroCidades,hashPrinci,quadPrinci,idhash,t);

        break;
    case 2:
         system("cls");
        cout << "Digite  N registro que sera inseridos" << endl;
        cin >> n;
        criaArquivoSaidaTxt("Hashing.txt");
        testeHash(registro, n);
        moduloTeste(registro, registroCidades,hashPrinci,quadPrinci,idhash,t);

        break;
    case 3:
        system("cls");
        cout << "Digite N chaves que sera inseridas na AVL" << endl;
        cin >> n;
        criaArquivoSaidaTxt("Avl.txt");
        testeAvl(registro, n);
        moduloTeste(registro, registroCidades,hashPrinci,quadPrinci,idhash,t);
        break;

    case 4:
        system("cls");
        cout << "Digite N cidades que sera inseridas na ARV B" << endl;
        cin >> n;
        criaArquivoSaidaTxt("AvB.txt");
        testeAVB(registro, n);
        moduloTeste(registro, registroCidades,hashPrinci,quadPrinci,idhash,t);

        break;
    case 5:
        menuPrincipal(registro,registroCidades,hashPrinci,quadPrinci,idhash,t);
    default:
        break;
    }
}
int main(int argc, char *argv[])
{   
    
    // string filename(argv[1]);
    // filename += "/brazil_covid19_cities_processado.csv";
    // cout<<filename<<endl;
    //RegistroCoordinates *registrosCoordinate = new RegistroCoordinates[QUANTCIDADES];
    //Registro *registros = new Registro[TAMANHOMAX];

    QuadTree *quadPrincipal = new QuadTree();
    RegistroCoordinates *registrosCoordinate = new RegistroCoordinates[QUANTCIDADES];
    Registro *registro = new Registro[TAMANHOMAX];
    Hashing *hashPrincipal = new Hashing(TAMANHOMAX);
    int tam = hashPrincipal->getTam();
    int *idHashing = new int[tam];
    
    
    menuPrincipal(registro,registrosCoordinate,hashPrincipal,quadPrincipal,idHashing,tam);

   
    return 0;
}
