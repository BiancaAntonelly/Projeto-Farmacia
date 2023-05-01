
#ifndef _CLIENTE_HPP
#define _CLIENTE_HPP

void escreverArquivo();
void carregarDados();
void listarremedios();
void buscarRemedioMap(std::string nomeRemedio);
void cadastrarremedios(std::string nomemedicamentonovo, int valordomedicamentonovo);
void atualizararquivoremedio();
void atualizarprecodoremedio(std::string nomedoremedioprocurado, int novovalor);
void apagarremedio(std::string remedioparaapagar);

//void escreverArquivo(std:: string Aremedios);

//void clientelistarremedios(std::string Aremedios);
//void clientebuscaroremedio(std::string Hgerente, std::string buscarremedio);
/*
vector<string> lerArquivo(std::string Aremedios);

void selecionarremedioparacomprar(const vector<std::string>& vetor, map<std::string, double>& mapremedio, std::string remediocomprar);
void calcularovalordocarrinho(const vector<string>& vetor, map<string, int>& mapcarrinho);
void atualizararquivocarrinho(map<string,  int>mapcarrinho);
void apagarremediocarrinho(string remedioparaapagar, map<string, int>mapcarrinho)
*/
#endif
