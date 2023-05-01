#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include "Hfarmacia.hpp"


using namespace std;

int main(int argc, char *argv[1]) {
  map<string, float>mapremedios;
  map<string, int>mapcarrinho;
  
  escreverArquivo();
  
  string perfil = argv[1];
  if(perfil == "cliente"){
    carregarDados();
    while(true){
    cout<<"Escolha uma das opções abaixo:"<<endl;
    cout<<"1- Listar todos os remédios cadastrados: "<<endl;
    cout<<"2- Buscar um remédio por seu nome: "<<endl;
    cout<<"3- Selecionar um remédio para comprar: "<<endl;
    cout<<"4- Calcular o valor sua compra: "<<endl;
    cout<<"5- Excluir um medicamento do carrinho: "<<endl;
    cout<<"6- Sair: "<<endl;
    int opcao;
    cin>>opcao;
    if(opcao == 1){
       listarremedios();
    }
    if(opcao == 2){
       string nomeRemedio;
       cout<<"Digite o nome do remédio que você quer procurar: "<<endl;
       cin>>nomeRemedio;
       buscarRemedioMap(nomeRemedio);
    }
    if(opcao == 3){
      string remediocomprar;
      cout<<"Qual remédio você quer comprar"<<endl;
      cin>>remediocomprar;
      selecionarremedioparacomprar(remediocomprar);
    }
    if(opcao == 4){
      calcularovalordocarrinho();
    }
    if(opcao == 5){
      string remedioparaapagardocarrinho;
      cout<<"Digite o nome do remédio que você quer apagar: "<<endl;
      cin>>remedioparaapagardocarrinho;
      apagarremediocarrinho(remedioparaapagardocarrinho);
    }
    if(opcao == 6){
      break;
    }
  }

  }else if (perfil == "gerente"){
    string senha;
    cout<<"Digite a senha do administrado: "<<endl;
    cin>>senha;
    if(senha=="admin"){ // perguntar se posso fazer isso
    carregarDados();
    while(true){
    cout<<"Escolha uma das opções abaixo:"<<endl;
    cout<<"1- Listar todos os remédios e seu respectivos preços: "<<endl;
    cout<<"2- Adicionar um novo medicamento: "<<endl;
    cout<<"3- Buscar remédio por seu nome: "<<endl;
    cout<<"4- Atualizar o preço de um determinado remédio: "<<endl;
    cout<<"5- Excluir um remédio: "<<endl;
    cout<<"6- Sair: "<<endl;
    int opcao;
    cin>>opcao;
    if(opcao == 1){
       listarremedios();
    }
    if(opcao == 2){
      string nomemedicamentonovo;
      int valordomedicamentonovo;
      cout<<"Digite o nome do novo medicamento: "<<endl;
      cin>>nomemedicamentonovo;
      cout<<"Digite o valor do novo medicamento: "<<endl;
      cin>>valordomedicamentonovo;
      cadastrarremedios(nomemedicamentonovo,valordomedicamentonovo);
    }
    if(opcao == 3){
       string nomeRemedio;
       cout<<"Digite o nome do remédio que você quer procurar: "<<endl;
       cin>>nomeRemedio;
       buscarRemedioMap(nomeRemedio);
    }
    if(opcao == 4){
      string nomedoremedioprocurado;
      int novovalor;
      cout<<"Digite o nome do remédio que você quer atualizar o preço: "<<endl;
      cin>>nomedoremedioprocurado;
      cout<<"Digite o novo valor do remédio: "<<endl;
      cin>>novovalor;
      atualizarprecodoremedio(nomedoremedioprocurado, novovalor);
    }
    if(opcao == 5){
      string remedioparaapagar;
      cout<<"Digite o nome do remédio que você quer apagar: "<<endl;
      cin>>remedioparaapagar;
      apagarremedio(remedioparaapagar);
    }
    if(opcao == 6){
      break;
    }
  }
  }else{
      cout<<"Senha errada"<<endl;
  }
  }else{
    cout<< "Perfil não encontrado!"<<endl;
  }


  
return 0;
}