#ifndef GERENTE_BD 
#define GERENTE_BD

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "Usuario.h"

/*!
*	\brief \c GerenteBD controla requisi��es ao banco de dados
*	
*	GerenteBD � respons�vel por promover a interface entre a camada de neg�cio
*	e a camada de persist�ncia de dados.
*/
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::map;


class GerenteBD
{
public:
	GerenteBD();
	virtual ~GerenteBD();
	
	//CRUD Pessoa
	/*!
	*	\brief Insere um novo usu�rio no banco de dados.
	*	\param usuario Instancia de usuario a ser salvo no banco.
	*/
	static void InsereUsuario(Usuario &usuario);

	/*!
	*	\brief Busca um usu�rio no banco de dados.
	*
	*	\param matricula Matricula do usuario
	*	\return Objeto usuario com os campos preenchidos
	*/
	static Usuario BuscaUsuario(string matricula);
	
	/*!
	*	\brief Atualiza um usu�rio no banco de dados.
	*/
	void AtualizaUsuario();

	/*!
	*	\brief Remove um usu�rio do banco de dados.
	*/
	void RemoveUsuario();

	/*!
	*	\brief Verifica a existencia de usuario.
	*	\param matricula Matricula de usuario.
	*	\return true caso a matricula exista no banco.
	*/
	static bool ExisteUsuario(string matricula);
	
	/*!
	*	\brief Verifica se a matricula confere com a senha.
	*	\param matricula Matricula do usuario.
	*	\param senha Senha a ser testada.
	*	\return Sretorna true apenas se a matricula existe e est� associada � senha.
	*/
	static bool ChecaUsuario(string matricula, string senha);
private:
	static string dbName;
	static map<string, string> dadosUsuarios;
};

#endif