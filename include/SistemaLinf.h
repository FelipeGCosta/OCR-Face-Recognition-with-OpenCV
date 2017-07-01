//#pragma once
//#ifndef __SistemaLinf__
//#define __SistemaLinf__

#include <iostream>

#include "GerenteLogin.h"
//#include "GerenteBD.h"
//#include "Usuario.h"
//#include "Reserva.h"

using std::cout;
using std::endl;
using std::cin;

/*!	\brief Gera ambiente onde classes se comunicam
*
*	As classes do sistema se comunicam no m�todo Run() de SistemaLinf.
*/
class SistemaLinf {
private:
	/*!
	*	\brief Inst�ncia de \c GerenteLogin.
	*/
	GerenteLogin GLog;

	/*!
	*	\brief Inst�ncia de \c GerenteBD.
	*/
	GerenteBD GBD;

	/*!
	*	\brief Inst�ncia de usu�rio que efetuou login no sistema.
	*/
	Usuario usuarioLogado;

	/*!
	*	\brief Responsavel por resolver o login do usu�rio.
	*
	*	O login pode ser feito via reconhecimento facial, possibilitado
	*	pela biblioteca OpenCV. Caso o reconhecimento falhe, � exigida
	*	senha do usu�rio.
	*/
	void _EfetuaLogin();

	/*!
	*	\brief Mensagem padr�o para entrada inv�lida.
	*/
	void _OpcaoInvalida();

	/*!
	*	\brief Fornece os principais conjuntos de opera��es possiveis no sistema.
	*/
	void _NavegaConta();
	
	/*!
	*	\brief Limpa os caracteres da tela.
	*/
	void _LimpaTela();

	/*!
	*	\brief Gera o cabe�alho principal do sistema.
	*/
	void _Cabecalho();

	/*!
	*	\brief Acessa �rea de modifica��o de dados pessoais.
	*/
	void _EditaDadosPessoais();

	/*!
	*	\brief Acessa a �rea de reserva de salas do laborat�rio.
	*/
	void _ReservaLaboratorio();

	/*!
	*	\brief Faz requisi��o das reservas existentes pelo usu�rio logado.
	*/
	void _VerificaReserva();

	/*!
	*	\brief Faz requisi��o para reserva de laborat�rio.
	*/
	void _ReservarLab();

	/*!
	*	\brief Faz requisi��o para cancelamento de reserva.
	*/
	void _CancelarReserva();

	/*!
	*	\brief Imprime na tela resultado da consulta de reservas.
	*/
	void _ImprimeReservas(vector<Reserva> reservas);
public:
	/*!
	*	\brief Construtor padr�o.
	*/
	SistemaLinf();
	
	/*!
	*	\brief Ambiente de execu��o dos sistema.
	*/
	void Run();
};


//#endif // SistemaLinf
