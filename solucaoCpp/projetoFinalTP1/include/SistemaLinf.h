#pragma once
#ifndef __SistemaLinf__
#define __SistemaLinf__

#include <iostream>

#include "GerenteLogin.h"
#include "GerenteBD.h"
#include "Usuario.h"
#include "Reserva.h"

using std::cout;
using std::endl;
using std::cin;

/*!	\brief Gera ambiente onde classes se comunicam
*
*	As classes do sistema se comunicam no m�todo Run() de SistemaLinf.
*/
class SistemaLinf {
private:
	GerenteLogin GLog;
	GerenteBD GBD;
	Usuario usuarioLogado;

	void _EfetuaLogin();
	void _OpcaoInvalida();
	void _NavegaConta();
	void _LimpaTela();
	void _Cabecalho();
	void _EditaDadosPessoais();
	void _ReservaLaboratorio();
	void _VerificaReserva();
	void _ReservarLab();
	void _CancelarReserva();
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


#endif // SistemaLinf
