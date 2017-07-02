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
	/*!
	*	\brief Nome do usu�rio.
	*/
	string nome;

	/*!
	*	Matr�cula do usu�rio.
	*/
	string matricula;
	/*!
	*	\brief Senha do usu�rio.
	*/
	string senha;

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
	Usuario(string matricula, string nome);

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
	*	\brief Getter do atributo senha.
	*/
	string GetSenha();

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

	/*!
	*	\brief Setter do atributo senha.
	*	\param senha Senha designada para inst�ncia.
	*/
	void SetSenha(string senha);

};

#endif // !__USUARIO__
