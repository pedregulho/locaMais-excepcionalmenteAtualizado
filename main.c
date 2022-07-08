#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <time.h>

// Registro / Tipo de Variavel
struct tCliente {
unsigned int rgCliente;
char nome[30];
float valor;
char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
int pontos;
};

// Registro / Tipo de Variavel
struct tVeiculos {
int vagas;
int codigo;
int alugado; //Se = 1 - Alugado // Se = 0 - Disponível
int codigoCliente; //Se alugado
int diaRetirada, diaDevolucao;
char modelo[30];
float valorDiaria;
char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
};

// Registro / Tipo de Variavel
struct tLocacao {
int codigoCliente;
float valorDiaria;
char modelo[30];
char deletado; // deletado = '*' / nao deletado = ' ' - exclusao logica
};

//Prototipos
int menu();
void cadastroDeCliente();
void cadastroDeVeiculo();
void listar();
void consultar();
void alterar();
void excluir();
void organizar();
void copiar();

//Programa Principal
int main(void) {
setlocale(LC_ALL,"Portuguese");
int op;

do{
op = menu();
switch (op) {

case 1:
menuCadastro();
break;

case 2:
menuListar();
break;

case 3:
menuConsultar();
break;

case 4:
alterar ();
break;

case 5:
menuLocacao ();
break;
}
}while (op != 0);

// system("pause");
return 0;
}

//Menu de Opcoes
int menu (void){

int opcao;
do {
printf("=== MENU PRINCIPAL ===\n");
printf("1. Menu de Cadastro\n");
printf("2. Menu de listagem\n");
printf("3. Menu de consulta\n");
printf("4. Alterar dados dos clientes\n");
printf("5. Menu de Locação\n");
printf("0. Sair\n");
printf("Digite sua opcao: ");
scanf("%d", &opcao);
if ((opcao < 0) || (opcao > 12))
printf ("Opcao Digitada Incorreta!\n");
} while ((opcao < 0) || (opcao > 12));

return opcao;
}

int menuCadastro (void){

int opcao;
do {
printf("=== MENU DE CADASTRO ===\n");
printf("1. Cadastro de cliente\n");
printf("2. Cadastro de veículo\n");
printf("3. Cadastro de locação\n");
printf("0. Sair\n");
printf("Digite sua opcao: ");
scanf("%d", &opcao);
switch (opcao) {

case 1:
printf("===Cadastro de cliente===\n");
cadastroDeCliente();
break;

case 2:
printf("===Cadastro de veículo===\n");
cadastroDeVeiculo();
break;

case 3:
printf("===Cadastro de locação===\n");
cadastrarLocacao();
break;
}
if ((opcao < 0) || (opcao > 12))
printf ("Opcao Digitada Incorreta!\n");
} while ((opcao < 0) || (opcao > 12));

return opcao;
}

int menuListar (void){

int opcao;
do {
printf("=== MENU LISTAR ===\n");
printf("1. Listar clientes\n");
printf("2. Listar veículos\n");
printf("3. Listar todos\n");
printf("0. Sair\n");
printf("Digite sua opcao: ");
scanf("%d", &opcao);
switch (opcao) {

case 1:
printf("===Lista de clientes===\n");
listarClientes();
break;

case 2:
printf("===Lista de veículos===\n");
listarVeiculos();
break;

case 3:
printf("===Lista de ambos===\n");
listarTodos();
break;
}
if ((opcao < 0) || (opcao > 12))
printf ("Opcao Digitada Incorreta!\n");
} while ((opcao < 0) || (opcao > 12));

return opcao;
}

int menuConsultar (void){

int opcao;
do {
printf("=== MENU CONSULTAR ===\n");
printf("1. Consultar clientes\n");
printf("2. Consultar veículos\n");
printf("0. Sair\n");
printf("Digite sua opcao: ");
scanf("%d", &opcao);
switch (opcao) {

case 1:
printf("===Consulta de clientes===\n");
consultarCliente();
break;

case 2:
printf("===Consulta de veículos===\n");
consultarVeiculos();
break;
}
if ((opcao < 0) || (opcao > 12))
printf ("Opcao Digitada Incorreta!\n");
} while ((opcao < 0) || (opcao > 12));

return opcao;
}

int menuLocacao (void){

int opcao;
do {
printf("=== MENU LOCAÇÃO ===\n");
printf("1. Baixa na Locação\n");
printf("2. Pesquisar locação por cliente\n");
printf("3. Pesquisar pontos de fidelidade por cliente\n");
printf("0. Sair\n");
printf("Digite sua opcao: ");
scanf("%d", &opcao);
switch (opcao) {

case 1:
printf("===Consulta de clientes===\n");
consultarCliente();
break;

case 2:
printf("===Consulta de veículos===\n");
listarVeiculos();
break;

case 3:
printf("===Consulta de veículos===\n");
listarVeiculos();
break;
}
if ((opcao < 0) || (opcao > 12))
printf ("Opcao Digitada Incorreta!\n");
} while ((opcao < 0) || (opcao > 12));

return opcao;
}

//Funcao Inclusao
void cadastroDeCliente(){
struct tCliente clientes;

FILE *arq = fopen("clientes.pro", "ab");
if (arq == NULL){
printf("Erro ao abrir arquivo");
return;
}
printf("Digite o número do rg do cliente: \n");
scanf("%u", &clientes.rgCliente);
printf("Digite o nome do cliente: \n");
fflush(stdin);
gets(clientes.nome);
/*printf("Digite o valor do produto: \n");
scanf("%f", &clientes.valor);*/
fwrite (&clientes, sizeof(clientes), 1, arq);
fclose(arq);
}

void cadastroDeVeiculo(){
struct tVeiculos veiculos;

FILE *arq = fopen("veiculos.pro", "ab");
if (arq == NULL){
printf("Erro ao abrir arquivo");
return;
}
printf("Digite a quantidade de vagas do veiculo: \n");
scanf("%d", &veiculos.vagas);
printf("Digite o modelo do veiculo: \n");
fflush(stdin);
gets(veiculos.modelo);
printf("Digite o valor da diária do veículo: \n");
scanf("%f", &veiculos.valorDiaria);
veiculos.codigo = randomCode(rand() % 10);
veiculos.alugado = 0;
fwrite (&veiculos, sizeof(veiculos), 1, arq);
fclose(arq);
}

void listarCarrosDisponiveis (numVagas, dataRetirada, dataDevolucao){

    struct tVeiculos veiculos;
    char alugado[10];
    FILE *arq = fopen("veiculos.pro", "rb");
    if (arq == NULL){
    printf("Arquivo inexistente!");
    return;
    }


    while (fread (&veiculos, sizeof(veiculos), 1, arq))
        if(veiculos.alugado == 1){
            strcpy ( alugado, "Sim" );
        }else{
            strcpy ( alugado, "Não" );// Datas atuais 10 e 20 // 15 e 25 // 2 e 8
        }
        if(veiculos.vagas >= numVagas && (!(dataRetirada > veiculos.diaRetirada && dataRetirada < veiculos.diaDevolucao) && !(dataDevolucao > veiculos.diaRetirada && dataDevolucao < veiculos.diaDevolucao))){
            printf("RG Cliente %i -- Modelo %s --- Vagas: %d --- Alugado?(%s) --- Codigo do veículo: %i\n", veiculos.codigoCliente, veiculos.modelo, veiculos.vagas, alugado, veiculos.codigo);
        }else{
            printf("Nenhum carro disponível\n");
        }
    fclose(arq);
}

//Cadastro de locação
void cadastrarLocacao()
{
    struct tVeiculos veiculos;

    FILE *arq = fopen("veiculos.pro", "rb");
    int numVagas, dataRetirada, dataDevolucao, codCliente, codCarro, seguro, achei;
    float valorDiaria;

    printf("Quantas vagas para o carro?\n");
    scanf("%i", &numVagas);

    printf("Digite a data de retirada\n");
    scanf("%i", &dataRetirada);

    printf("Digite a data de devolução\n");
    scanf("%i", &dataDevolucao);

    listarCarrosDisponiveis(numVagas, dataRetirada, dataDevolucao);

    printf("Digite o rg do cliente:\n");
    scanf("%i", &codCliente);

    int acheiCod = pesquisarPorCliente(codCliente);

    if(acheiCod == 0){
        return;
    }

    printf("Digite o código do carro a ser alugado:\n");
    scanf("%i", &codCarro);

    printf("Deseja fazer seguro?(Digite 1 para sim e 0 para não):\n");
    scanf("%i", &seguro);

    while (fread (&veiculos, sizeof(veiculos), 1, arq)){
    if ((codCarro == veiculos.codigo)) {
        alterarSatus(codCarro, codCliente, dataRetirada, dataDevolucao);
        valorDiaria = veiculos.valorDiaria;
        achei = 1;
    }
    }

    int dias = dataDevolucao - dataRetirada;

    float valorTotal = dias*valorDiaria;

    if(seguro == 1){
        valorTotal = valorTotal + 50;
    }

    printf("%f\n", valorTotal);

    fclose(arq);


}

//Funcao Consultar clientes
int pesquisarPorCliente(codigoCliente){

FILE *arq = fopen("clientes.pro", "rb");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

struct tCliente clientes;
int cod, achei = 0;
cod = codigoCliente;

while (fread (&clientes, sizeof(clientes), 1, arq)){
if ((cod == clientes.rgCliente) && (clientes.deletado != '*')) {
printf("Cod %u --- Descricao: %-8s --- Valor R$ %4.2f\n",clientes.rgCliente, clientes.nome, clientes.valor);
achei = 1;
}
}

/*if (!achei)
printf ("\\nCodigo nao cadastrado!!\n");*/

fclose(arq);
return achei;
}

//Funcao Alterar status do veículo
void alterarSatus(codigoCarro, codigoCliente, dataRetirada, dataDevolucao){
FILE *arq = fopen("veiculos.pro", "r+b");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

struct tVeiculos veiculos;
int achei = 0;

while (fread (&veiculos, sizeof(veiculos), 1, arq)){
if (codigoCarro == veiculos.codigo){
achei = 1;

fseek(arq,sizeof(struct tVeiculos)*-1, SEEK_CUR);
veiculos.alugado = 1;
veiculos.codigoCliente = codigoCliente;
veiculos.diaRetirada = dataRetirada;
veiculos.diaDevolucao = dataDevolucao;

fwrite(&veiculos, sizeof(veiculos), 1, arq);
fseek(arq, sizeof(veiculos)* 0, SEEK_END);
return;
}
}

if (!achei)
printf ("\\nCodigo nao cadastrado!!\\n");

fclose(arq);
}

void baixaLocacao()
{
    struct tVeiculos veiculos;
    int dataRetirada, dataDevolucao, dataEntrega, diasAtraso, codCarro, rg;
    float valorDiaria;

    FILE *arq = fopen("veiculos.pro", "rb");

    printf("Digite o código do veículo:\n");
    scanf("%i", &codCarro);

    while (fread (&veiculos, sizeof(veiculos), 1, arq)){
    if ((codCarro == veiculos.codigo)) {
        valorDiaria = veiculos.valorDiaria;
        dataRetirada = veiculos.diaRetirada;
        dataDevolucao = veiculos.diaDevolucao;
        rg = veiculos.codigoCliente;
        int achei = 1;
    }
    }

    printf("Valor diaria : %f,Retirada: %i,Devolucao: %i\n", valorDiaria, dataRetirada, dataDevolucao);

    int diasLocacao = dataDevolucao - dataRetirada;

    float valorTotal = valorDiaria * (dataDevolucao - dataRetirada);//1000

    printf("Qual a data de entrega:\n");
    scanf("%i", &dataEntrega);//22

    if(dataEntrega > dataDevolucao){
        diasAtraso = dataEntrega - dataDevolucao;//2
        float subTotal = valorDiaria * diasAtraso;//200
        valorTotal = subTotal + (valorTotal * 1.05) + (30 * diasAtraso);//200 + 1050 + 60 = 1310
    }

    printf("%f\n", valorTotal);

    alterarSatusBaixa(codCarro);
    pontosFidelidades(rg, diasLocacao);

    fclose(arq);
}

//Funcao Alterar status do veículo na baixa
void alterarSatusBaixa(codigoCarro){
FILE *arq = fopen("veiculos.pro", "r+b");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

struct tVeiculos veiculos;
int achei = 0;

while (fread (&veiculos, sizeof(veiculos), 1, arq)){
if (codigoCarro == veiculos.codigo){
achei = 1;

fseek(arq,sizeof(struct tVeiculos)*-1, SEEK_CUR);
veiculos.alugado = 0;
veiculos.codigoCliente = 0;
veiculos.diaRetirada = 0;
veiculos.diaDevolucao = 0;

fwrite(&veiculos, sizeof(veiculos), 1, arq);
fseek(arq, sizeof(veiculos)* 0, SEEK_END);
return;
}
}

if (!achei)
printf ("Codigo nao cadastrado!!\n");

fclose(arq);
}

//Funcao Listar Clientes
void listarClientes (){

struct tCliente clientes;
FILE *arq = fopen("clientes.pro", "rb");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

while (fread (&clientes, sizeof(clientes), 1, arq))
printf("Código: %u --- Nome: %s --- Pontos de fidelidade: (%i)\n",clientes.rgCliente, clientes.nome, clientes.pontos);

fclose(arq);
}

//Funcao Listar Veículos
void listarVeiculos (){

struct tVeiculos veiculos;
FILE *arq = fopen("veiculos.pro", "rb");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

while (fread (&veiculos, sizeof(veiculos), 1, arq))
printf("Cod %hu --- Modelo: %s --- Valor da diária R$ %.2f --- Alugado(%i) --- Codigo cliente (%i)\n",veiculos.codigo, veiculos.modelo, veiculos.valorDiaria, veiculos.alugado, veiculos.codigoCliente);

fclose(arq);
}

void listarTodos()
{
    printf("\n===Lista de clientes===\n");
    listarClientes();

    printf("\n===Lista de veículos===\n");
    listarVeiculos();
}

//Funcao Randomizar código
int randomCode(unsigned int aleatorio){

unsigned short cod;
cod = ((aleatorio * (time(NULL)))%1000000); //num aleatório entre 0 e 999

return cod;
}

//Funcao Consultar Veículos
void consultarVeiculos(){

FILE *arq = fopen("veiculos.pro", "rb");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

struct tVeiculos veiculos;
int cod, achei = 0;
printf ("Digite o código de veículo que procura: \n");
scanf ("%d", &cod);

while (fread (&veiculos, sizeof(veiculos), 1, arq)){
if ((cod == veiculos.codigo)) {
printf("Cod %u --- Modelo: %s --- Valor R$ %.2f\n",veiculos.codigo, veiculos.modelo, veiculos.valorDiaria);
achei = 1;
}
}

if (!achei)
printf ("\\nCodigo nao cadastrado!!\n");

fclose(arq);

}

//Funcao Consultar clientes
void consultarCliente(){

FILE *arq = fopen("clientes.pro", "rb");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

struct tCliente clientes;
int cod, achei = 0;
printf ("Digite o rg que procura: \n");
scanf ("%d", &cod);

while (fread (&clientes, sizeof(clientes), 1, arq)){
if ((cod == clientes.rgCliente) && (clientes.deletado != '*')) {
printf("Cod %u --- Descricao: %-8s --- Valor R$ %4.2f\n",clientes.rgCliente, clientes.nome, clientes.valor);
achei = 1;
}
}

if (!achei)
printf ("\\nCodigo nao cadastrado!!\n");

fclose(arq);

}

void consultarLocacoes(){

FILE *arq = fopen("veiculos.pro", "rb");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

struct tVeiculos veiculos;
int cod, achei = 0;
printf ("Digite o rg do cliente que procura: \n");
scanf ("%d", &cod);

while (fread (&veiculos, sizeof(veiculos), 1, arq)){
if ((cod == veiculos.codigoCliente)) {
printf("Cod %hu --- Modelo: %s --- Valor da diária R$ %.2f --- Alugado(%i) --- Codigo cliente (%i)\n",veiculos.codigo, veiculos.modelo, veiculos.valorDiaria, veiculos.alugado, veiculos.codigoCliente);
achei = 1;
}
}

if (!achei)
printf ("\\nCodigo nao cadastrado!!\n");

fclose(arq);

}

//Funcao Extra de alterar dados do cliente
void alterar(){
FILE *arq = fopen("clientes.pro", "r+b");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

struct tCliente clientes;
int cod, achei = 0;
printf ("Digite o número rg do cliente que deseja alterar: \n");
scanf ("%d", &cod);

while (fread (&clientes, sizeof(clientes), 1, arq)){
if (cod == clientes.rgCliente){
printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n",clientes.rgCliente, clientes.nome, clientes.valor);
achei = 1;

fseek(arq,sizeof(struct tCliente)*-1, SEEK_CUR);
printf("Digite o novo nome: \n");
fflush(stdin);
gets(clientes.nome);
printf("Digite o novo rg do cliente....: \n");
scanf("%f", &clientes.rgCliente);
printf("Digite a nova quantidade de pontos....: \n");
scanf("%f", &clientes.pontos);

fwrite(&clientes, sizeof(clientes), 1, arq);
fseek(arq, sizeof(clientes)* 0, SEEK_END);
return;
}
}

if (!achei)
printf ("\\nCodigo nao cadastrado!!\\n");

fclose(arq);
}

//Exclusao Logica
void excluir(){

FILE *arq = fopen("clientes.pro", "r+b");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

struct tCliente clientes;
int cod, achei = 0;
char certeza;
printf ("\\nDigite o número do rg do cliente que deseja EXCLUIR: \\n");
scanf ("%d", &cod);

while (fread (&clientes, sizeof(clientes), 1, arq)){
if (cod == clientes.rgCliente){
printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\\n\\n",clientes.rgCliente, clientes.nome, clientes.valor);
achei = 1;

printf("\\nTem certeza que quer excluir este produto? s/n \\n");
fflush(stdin);
scanf("%c", &certeza);
if (certeza == 's'){
clientes.deletado = '*';
printf("\\nProduto excluido com Sucesso! \\n");
fseek(arq,sizeof(struct tCliente)*-1, SEEK_CUR);
fwrite(&clientes, sizeof(clientes), 1, arq);
fseek(arq, sizeof(clientes)* 0, SEEK_END);
return;
}
else if (certeza == 'n')
return;
}
}

if (!achei)
printf ("\\nCodigo nao cadastrado!!\\n");

fclose(arq);
}

//Organizar Arquivo
void organizar(){
struct tCliente clientes;
//struct tCliente produtosB; // arquivo de backup

FILE *arq = fopen("clientes.pro", "rb");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

FILE *arqB = fopen("BackupProdutos.pro", "wb");
if (arqB == NULL){
printf("Erro na abertura!");
return;
}

while (fread (&clientes, sizeof(clientes), 1, arq)){
if (clientes.deletado != '*'){

fseek(arqB,sizeof(clientes)*-1, SEEK_CUR);
fwrite(&clientes, sizeof(clientes), 1, arqB);
fseek(arqB, sizeof(clientes)* 0, SEEK_END);

}
}

fclose(arq);
fclose(arqB);

remove("clientes.pro");
int teste = 0;
teste = rename("BackupProdutos.pro", "clientes.pro");
if (teste == 0){
printf("\\nArquivo Renomeado com Sucesso! \\n");
printf("\\nArquivo organizado com Sucesso! %d \\n", teste);

}
else printf("\\nErro ao Renomear! %d \\n",teste);
return;

}

void pontosFidelidades(rg, diasLocacao)
{
FILE *arq = fopen("clientes.pro", "r+b");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

struct tCliente clientes;
int cod, achei = 0;
cod = rg;

while (fread (&clientes, sizeof(clientes), 1, arq)){
if (cod == clientes.rgCliente){
int pontosDeFidelidade = diasLocacao * 10;
achei = 1;

fseek(arq,sizeof(struct tCliente)*-1, SEEK_CUR);
clientes.pontos = clientes.pontos + pontosDeFidelidade;

fwrite(&clientes, sizeof(clientes), 1, arq);
fseek(arq, sizeof(clientes)* 0, SEEK_END);
return;
}
}

if (!achei)
printf ("\\nCodigo nao cadastrado!!\\n");


fclose(arq);

}

//Funcao Consultar clientes
void consultarPontosFidelidade(){

FILE *arq = fopen("clientes.pro", "rb");
if (arq == NULL){
printf("Arquivo inexistente!");
return;
}

struct tCliente clientes;
int cod, achei = 0;

while (fread (&clientes, sizeof(clientes), 1, arq)){
    if(clientes.pontos >= 500){
        printf("Cod %u --- Descricao: %-8s --- Valor R$ %4.2f\n",clientes.rgCliente, clientes.nome, clientes.valor);
    }
}

fclose(arq);

}
