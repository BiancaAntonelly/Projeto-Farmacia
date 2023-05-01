#ifndef _GERENTE_HPP
#define _GERENTE_HPP

void escreverArquivo();
void gerentecarregarDados(std::map<std::string, float> mapremedios);
void gerentelistarremedios(std::map<std::string, float> mapremedios);

void gerentebuscarRemedioMap(std::string nomeRemedio, std::map<std::string, float>mapremedios);




void cadastrarremedios(std::string Aremedios, std::string nomemedicamentonovo, int valordomedicamentonovo, std::map<std::string, float>mapremedios);
void buscaroremedio(std::string Hgerente, std::string buscarremedio, std::map<std::string, float>mapremedios);
void atualizarprecodoremedio(std::string nomedoremedioprocurado, int novovalor, std::map<std::string, float>mapremedios);
void atualizararquivoremedio(std::map<std::string, float>mapremedios);
void apagarremedio(std::string remedioparaapagar,  std::map<std::string, float>mapremedios);

#endif