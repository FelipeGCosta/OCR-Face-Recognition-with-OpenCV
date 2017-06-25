#ifndef GERENTE_BD 
#define GERENTE_BD

#include <iostream>
#include <fstream>
#include <string>
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
	*/
	void BuscaUsuario();
	
	/*!
	*	\brief Atualiza um usu�rio no banco de dados.
	*/
	void AtualizaUsuario();

	/*!
	*	\brief Remove um usu�rio do banco de dados.
	*/
	void RemoveUsuario();
private:
	static string dbName;

};

#endif