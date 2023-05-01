#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std; 

map<string, float> mapremedios;
map<string, float> mapcarrinho;

//escrever no arquivo e armazenar no map
void escreverArquivo(){
  ofstream arquivo;

  arquivo.open("Aremedios.txt", ios::out);
  
  arquivo<<"Neosaldina"<<endl;
  arquivo<<"10"<<endl;
  mapremedios["Neosaldina"]=10;
  arquivo<<"Engov"<<endl;
  arquivo<<"15"<<endl;
  mapremedios["Engov"]=15;
  arquivo<<"Novalgina"<<endl;
  arquivo<<"20"<<endl;
  mapremedios["Novalgina"]=20;
  arquivo<<"Doril"<<endl;
  arquivo<<"25"<<endl;
  mapremedios["Doril"]=25;
  arquivo<<"Dipirona"<<endl;
  arquivo<<"30"<<endl;
  mapremedios["Dipirona"]=30;
  arquivo<<"Lisador"<<endl;
  arquivo<<"35"<<endl;
  mapremedios["Lisador"]=35;

  
arquivo.close();
}

//carregar dados do map
void carregarDados(){
   fstream arquivo("Aremedios.txt");
    if(arquivo.is_open()){
      string linha;
      vector<string> vetor;
      while(getline(arquivo, linha)){
        vetor.push_back(linha);
      }

    arquivo.close();
    for (int i = 0; i < vetor.size(); i+= 2){
      string nome = vetor[i];
      mapremedios[nome] = stof(vetor[i+1]);

      //O problema era que tava lendo os textos e não os numeros
      //porque o for tava para as linhas erradas para o map

    }
  }
}

//listar remédios pegando do map
void listarremedios(){
  for(auto i : mapremedios){
    cout << "Nome: " << i.first << endl;
    cout << "Preço: " << i.second << endl;
  }
}

//Atualiza o arquivo para excluir a linha apagada
void atualizararquivoremedio(){
  fstream arquivo;
  arquivo.open("Aremedios.txt", ios::out | ios::in); //Apaga o arquivo original
  
  //Reescreve todo o arquivo do zero com os dados do map
  cout<<"Remédio que ainda estão no seu arquivo"<<endl;
  for (auto it = mapremedios.begin(); it != mapremedios.end(); ++it) {
    std::cout<< it->first<<std::endl;
    std::cout<< it->second << std::endl;
}
}

//buscar remédio procurando o nome no map
void buscarRemedioMap(string nomeRemedio){
  bool encontrado = false;
  for(auto i : mapremedios){
    if(i.first == nomeRemedio){
      encontrado  = true;
      cout << "Remedio encontrado!" << endl;
      break; //para não ficar se repetindo
    }
  }
  if(!encontrado){
    cout<<"Remédio não encontrado"<<endl;
  }
}
//usei booleano pois antes ele estava verificando só o primeiro e sempre falava que não tinha encontrado o  remédio

//adicionar um novo medicamento no map
void cadastrarremedios(string nomemedicamentonovo, int valordomedicamentonovo){
  fstream arquivo;
  arquivo.open("Aremedios.txt", ios::out | ios::app); //Abre um arquivo (escrita)
  arquivo << nomemedicamentonovo <<endl;
  arquivo << valordomedicamentonovo <<endl;
  mapremedios[nomemedicamentonovo]=valordomedicamentonovo;
  atualizararquivoremedio();
  arquivo.close();
  cout << "Remédio Cadastrado\n";
}


//atualizar o preço do remédio1
void atualizarprecodoremedio(string nomedoremedioprocurado, int novovalor){
  for(auto i : mapremedios){
    if(i.first == nomedoremedioprocurado){
      mapremedios[nomedoremedioprocurado] = novovalor;
      atualizararquivoremedio();
      cout<<"Valor do remédio "<<nomedoremedioprocurado<<" foi atualizado com sucesso."<<endl;
    }   
  }
}

//excluir um remédio
void apagarremedio(string remedioparaapagar){
  for(auto i : mapremedios){
    if(i.first == remedioparaapagar){
      mapremedios.erase(remedioparaapagar);
      cout << "Remédio excluido com sucesso" << endl;
      atualizararquivoremedio(); // Chama a função para atualizar o arquivo
      return;
    }   
  }
  cout << "Remédio não encontrado!!!" << endl;
}

//selecionar remédio para comprar
void selecionarremedioparacomprar(string remediocomprar){
  auto it = mapremedios.find(remediocomprar);
  if(it != mapremedios.end()){ // verifica se o remédio existe no map
    ofstream arquivo;
    arquivo.open("Carrinho.txt", ios::out | ios::app);
    arquivo << it->first << endl;
    arquivo << it->second << endl;
    mapcarrinho[it->first] = it->second;
    cout <<"O remédio "<<remediocomprar<<" foi adicionado ao seu carrinho."<<endl;
  } else {
    cout << "Não temos disponível esse remédio." << endl;
  }
}

//calcular o valor da compra
void calcularovalordocarrinho(){
    ofstream arquivo;  
    arquivo.open("Carrinho.txt");
    int somarcarrinho = 0;
    for (auto it = mapcarrinho.begin(); it != mapcarrinho.end(); it++) {
        somarcarrinho += it->second;
    }

    std::cout << "Soma do seu carrinho deu: " << somarcarrinho << std::endl;
}

//atualizar arquivo carrinho
void atualizararquivocarrinho(){
  fstream arquivo;
  arquivo.open("Carrinho.txt", ios::out); //Apaga o arquivo original
  
  //Reescreve todo o arquivo do zero com os dados do map
  cout<<"Remédio que ainda estão no seu carrinho"<<endl;
  for (auto it = mapcarrinho.begin(); it != mapcarrinho.end(); ++it) {
    std::cout<<it->first<<std::endl;
    std::cout<< it->second << std::endl;
}
}

//excluir um remédio do carrinho
void apagarremediocarrinho(string remedioparaapagardocarrinho){
  for(auto i : mapcarrinho){
    if(i.first == remedioparaapagardocarrinho){
      mapcarrinho.erase(remedioparaapagardocarrinho);
      cout << "Remédio excluido com sucesso" << endl;
      atualizararquivocarrinho(); // Chama a função para atualizar o arquivo
      return;
    }   
  }
  cout << "Remédio não encontrado!!!" << endl;
}
