#ifndef _FARMACIA_HPP
#define _FARMACIA_HPP

void escreverArquivo();
void carregarDados();
void listarremedios();
void buscarRemedioMap(std::string nomeRemedio);
void cadastrarremedios(std::string nomemedicamentonovo, int valordomedicamentonovo);
void atualizararquivoremedio();
void atualizarprecodoremedio(std::string nomedoremedioprocurado, int novovalor);
void apagarremedio(std::string remedioparaapagar);

void selecionarremedioparacomprar(std::string remediocomprar);
void calcularovalordocarrinho();
void atualizararquivocarrinho();
void apagarremediocarrinho(std::string remedioparaapagardocarrinho);
#endif
