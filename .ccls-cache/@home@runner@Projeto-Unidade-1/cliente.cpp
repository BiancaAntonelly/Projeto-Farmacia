#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std; 

map<string, float> mapremedios; 

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

//buscar remédio procurando o nome no map
void buscarRemedioMap(string nomeRemedio){
  for(auto i : mapremedios){
    if(i.first == nomeRemedio){
      cout << "Remedio encontrado!" << endl;
      break; //para não ficar se repetindo
    }else{
      cout << "Remedio não encontrado!" << endl;
      break;
    }
  }
}

//adicionar um novo medicamento no map
void cadastrarremedios(string nomemedicamentonovo, int valordomedicamentonovo){
  fstream arquivo;
  arquivo.open("Aremedios.txt", ios::out | ios::app); //Abre um arquivo (escrita)
  arquivo << nomemedicamentonovo <<endl;
  arquivo << valordomedicamentonovo <<endl;
  mapremedios[nomemedicamentonovo]=valordomedicamentonovo;
  arquivo.close();
  cout << "Remédio Cadastrado\n";
}

//Atualiza o arquivo para excluir a linha apagada
void atualizararquivoremedio(){
  fstream arquivo;
  arquivo.open("Aremedios.txt", ios::out); //Apaga o arquivo original
  
  //Reescreve todo o arquivo do zero com os dados do map
  for (auto it = mapremedios.begin(); it != mapremedios.end(); ++it) {
    std::cout<< it->first<<std::endl;
    std::cout<< it->second << std::endl;
}
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
      atualizararquivoremedio(); // Chama a função para atualizar o arquivo
      cout << "Remédio excluido com sucesso" << endl;
      return;
    }   
  }
  cout << "Remédio não encontrado!!!" << endl;
}






































































/*struct Gerente{ //não ta usando essa struct em nenhum lugar...
  string remedio; // coloquei como base, mas depois não usei
  string valor;
};*/

//buscar um remédio por seu nome
//no buscar remedios basta passar o nome do remedio... mas pode ficar assim
//vamos deixar assim então
//o nome do arquivo era aquele que estava o Aremedios , então vou collocar po nomme de volta tá bom? ta certo

//Agora que você tem um map pode buscar nele o remedio.. assim vocÊ busca no arquivo... vou deixar essa função mas vou criar outra em baixo.
//buscar no map é mt mais simplles né?
/*
void clientebuscaroremedio(string Aremedios, string buscarremedio){
  ifstream arquivo("Aremedios.txt");
  if(arquivo.is_open()){
    string linha;
    vector<string> vetor;
    while(getline(arquivo, linha)){
      vetor.push_back(linha);
  }
    arquivo.close();
  for (int i = 0; i < vetor.size(); i++){
    string nome = vetor[i];
    if(vetor[i]==buscarremedio){
      cout<<"Tem esse remédio!"<<endl;
      return;
    }
  }
 cout << "Não tem esse remédio." << endl;
  }
}
*/

//Muito mais simpless



//ler o arquivo

// Acho que essa função ja existe la em cima...
//sim sim
/*
vector<string> lerArquivo(string Aremedios){
    ifstream arquivo(Aremedios);
    vector<string> vetor;

    if(arquivo.is_open()){
        string linha;
        while(getline(arquivo, linha)){
            vetor.push_back(linha);
        }
        arquivo.close();
    }
    return vetor;
}

*/
//mas essa função eu já tenho, tenho ela no arquivo gerente, eu fiz 
/*

//selecionar remédio para comprar




void selecionarremedioparacomprar(const vector<string>& vetor, map<string, double>& mapremedio, string remediocomprar, map<string, int>&mapcarrinho, int valordoremedio){
  for(int i = 0; i < vetor.size(); i++){
    if(remediocomprar == vetor[i]){
      ofstream arquivo;
      arquivo.open("Carrinho.txt", ios::out);
      arquivo<<vetor[i]<<endl;
      arquivo<<vetor[i+1]<<endl;
      vetor[i+1]=valordoremedio;
      mapcarrinho[vetor[i]]=valordoremedio;
    }
    }
  cout<<"Não temos disponível esse remédio."<<endl;
}

//calcular o valor da compra
void calcularovalordocarrinho(const vector<string>& vetor, map<string, int>& mapcarrinho){
    ofstream arquivo;  
    arquivo.open("Carrinho.txt");
    int quantidadederemedios = 0;
    for(int i = 0; i < vetor.size(); i += 2{
    quantidadederemedio++;
    }

  
    for(int i = 0; i < vetor.size(); i += 2{

        double valorcarrinho = stod(vetor[i]);
        notas[nome] = mediaaluno; 
    }
}
//atualizar arquivo carrinho
void atualizararquivocarrinho(map<string,  int>mapcarrinho){
  fstream arquivo;
  arquivo.open("Carrinho.txt", ios::out); //Apaga o arquivo original
  
  //Reescreve todo o arquivo do zero com os dados do map
  for(auto i : mapcarrinho){
    arquivo << i.first << endl;
  }
}

//excluir um remédio do carrinho
void apagarremediocarrinho(string remedioparaapagar, map<string, int>mapcarrinho){
  for(auto i : mapcarrinho){
    if(i.first == remedioparaapagar){
      mapcarrinho.erase(remedioparaapagar);
      atualizararquivocarrinho(mapcarrinho); // Chama a função para atualizar o arquivo
      cout << "Remédio excluido com sucesso" << endl;
      return;
    }   
  }
  cout << "Remédio não encontrado!!!" << endl;
}

*/