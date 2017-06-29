#pragma once
#ifndef __RESERVA__
#define __RESERVA__

#include <iostream>
#include <string>
#include <ostream>

using std::string;
using std::ostream;
using std::cout;
using std::endl;
using std::stoi;

/*!
*	\brief Classe \c Reserva abstrai o conceito da reserva de uma sala no laborat�rio.
*/
class Reserva {
public:
	/*!
	*	\brief Construtor padr�o.
	*/
	Reserva();

	/*!
	*	Destrutor.
	*/
	~Reserva();

	/*!
	*	\brief Sa�da formatada das informa��es da inst�ncia da \c Reserva.
	*/
	void ImprimeReserva();

	/*!
	*	\brief Data para o qual foi feita a reserva.
	*/
	string data;

	/*!
	*	\brief Hor�rio reservado.
	*/
	string hora;

	/*!
	*	\brief Numero do laborat�rio reservado.
	*/
	string laboratorio;

	/*!
	*	\brief C�digo da reserva.
	*/
	string numeroReserva;

	/*!
	*	\brief Matr�cula do usu�rio que efetuou a reserva.
	*/
	string matricula;
};
#endif // __RESERVA__
