#pragma once
#ifndef __USUARIO__
#define __USUARIO__

#include <iostream>
#include <string>

using std::string;

/*!
*	\brief Representa a inst�ncia do usuario que utiliza o sistema.
*	
*	Cont�m as informa��es do usu�rio.
*/
class Usuario {
private:
	string nome;
	string matricula;

public:
	/*!
	*	\brief Construtor padr�o
	*/
	Usuario();
	
	/*!
	*	\brief Construtor alternativo.
	*	\param nome Nome do usuario.
	*	\param matricula Matricula do usuario
	*/
	Usuario(string nome, string matricula);

	/*!
	*	\brief Construtor de c�pia.
	*	\param user Usuario a ser copiado.
	*/
	Usuario(Usuario &user);

	/*!
	*	\brief Getter do atributo nome.
	*/
	string GetNome();
	
	/*!
	*	\brief Getter do atributo matricula.
	*/
	string GetMatricula();

	/*!
	*	\brief Setter do atributo nome.
	*	\param nome Nome designado para instancia.
	*/
	void SetNome(string nome);

	/*!
	*	\brief Setter do atributo matricula.
	*	\param matricula Matricula designada para inst�ncia.
	*/
	void SetMatricula(string matricula);

};

#endif // !__USUARIO__
