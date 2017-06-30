#ifndef GERENTE_BD 
#define GERENTE_BD

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include "Usuario.h"
#include "Reserva.h"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::map;
using std::vector;

/*!
*	\brief Controla requisi��es ao banco de dados
*
*	GerenteBD � respons�vel por promover a interface entre a camada de neg�cio
*	e a camada de persist�ncia de dados.
*/
class GerenteBD
{
public:
	/*!
	*	\brief Construtor padr�o
	*
	*	Na constru��o da inst�ncia de \c GerenteBD � feita a leitura
	*	dos arquivos com registros de usu�rios e registros das reservas.
	*/
	GerenteBD();

	/*!
	*	\brief Destrutor.
	*/
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

	/*!
	*	\brief Executa as modifica��es sobre usu�rio na base de dados.
	*/
	static void CommitUsuario();

	//CRUD Reserva
	/*!
	*	\brief Salva um novo registro de reserva.
	*
	*	\param matricula Matr�cula do usu�rio que efetuou reserva.
	*	\param reserva Objeto que cont�m as informa��es da reserva.
	*/
	static void InsereReserva(string matricula, Reserva reserva);

	/*!
	*	\brief Busca registros de reserva de acordo com o campo utilizado como crit�rio de busca.
	*
	*	\param entrada Valor a ser comparado na busca.
	*	\param campo Informa��o da reserva a ser levada em considera��o (data ou matricula).
		\return Vetor de registros que respondem � pesquisa.
	*/
	static vector<Reserva> BuscaReserva(string entrada, string campo);

	/*!
	*	\brief Cancela uma reserva.
	*
	*	\param numReserva C�digo da reserva a ser cancelada.
	*/
	static void CancelaReserva(string numReserva);

	/*!
	*	\brief Executa as modifica��es sobre reserva na base de dados.
	*/
	static void CommitReserva();

	/*!
	*	\brief Verifica se a data informada possui reservas.
	*
	*	\param data Data a ser verificada.
	*	\return \c true caso hajam reservas na data informada. \c false caso contr�rio. 
	*/
	static bool DataComReserva(string data);


private:
	/*!
	*	\brief Contador para gerar c�digos de novas reservas.
	*/
	static int codigoReserva;

	/*!
	*	\brief Nome do arquivo detentor dos registros de usuario.
	*/
	static string dbName;

	/*!
	*	\brief Nome do arquivo detentor dos registros de reservas.
	*/
	static string dbReserva;

	/*!
	*	\brief Mapeamento de usuarios.
	*
	*	O mapeamento utiliza a matr�cula do usu�rio para obter suas informa��es cadastrais.
	*/
	static map<string, string> dadosUsuarios;

	/*!
	*	\brief Mapeamento de registros de reservas.
	*
	*	O mapeamento � feito priorizando a busca por data (chave), 
	*	permitindo acesso aos registros de reservas daquele dia.
	*/
	static map<string, vector<Reserva>> dadosReservas;
};

#endif