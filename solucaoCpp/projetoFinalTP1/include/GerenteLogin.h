#ifndef GERENTE_LOGIN
#define GERENTE_LOGIN


#include <iostream>
#include <string>

#include "Usuario.h"
#include "GerenteBD.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

/*!
*	\brief \c GerenteLogin � aquela que credencia o usu�rio.
*
*	A primeira classe com quem o usu�rio ir� lidar no sistema � o GerenteLogin.
*	Essa ser� respons�vel por validar a entrada do usu�rio no sistema. A primeira
*	tentativa ser� requisitando a matr�cula do usuario e tentando reconhecimento facial. 
*	Caso falhe, o Gerente ir� possibilitar que o usu�rio insira sua matr�cula e senha para fazer login.
*
*	Uma vez credenciado, GerenteLogin gera uma inst�ncia de Usuario que ir� existir durante a sess�o no sistema,
*	encerrando-se a responsabilidade de GerenteLogin.
*/

class GerenteLogin
{
public:
	/*!
	*	\brief Construtor padr�o da classe.
	*/
	GerenteLogin();
	virtual ~GerenteLogin();
	
	/*!
	*	\brief Passa o controle para a classe GerenteLogin.
	*	
	*	A tela default de in�cio do sistema � a tela de login. Essa tela aguarda at� que
	*	seja feita verifica��o de um usu�rio v�lido.
	*
	*/
	void Iniciar();
	Usuario Credencia(string matricula);
	bool ReconheceFace(string matricula);
	Usuario NovoUsuario(string matricula);
	
private:

	/*!
	*	\brief Faz a verifica��o de usu�rio via webcam.
	*/
	void _entradaCamera();
	
	/*!
	*	\brief Faz a verifica��o de usu�rio via teclado.
	*/
	void _entradaTeclado();

	/*!
	*	\brief Valida a opera��o de entrada.
	*/
	int _verificaEntrada();//
};

#endif