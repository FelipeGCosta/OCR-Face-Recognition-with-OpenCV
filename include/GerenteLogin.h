//#ifndef GERENTE_LOGIN
//#define GERENTE_LOGIN


#include <iostream>
#include <ctime>
#include <sstream>      // std::stringstream
#include <string>       // std::string
#include <sys/stat.h>   // mkdir
#include <fstream>  // ler arquivo csv

#include "opencv2/core.hpp"
#include "opencv2/face.hpp"


#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/videoio/videoio.hpp"

//#include <vector>

//#include "Usuario.h"
#include "GerenteBD.h"

#ifdef __linux__ 
	#include <unistd.h>
	#include <termios.h>
#elif _WIN32
	#include <windows.h>
#endif

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

using namespace cv;

using namespace cv::face;

/*!
*	\brief Credencia o usu�rio.
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

	/*!
	*	\brief Gera a inst�ncia do usu�rio que navega no sistema.
	*
	*	O m�todo credencia o usu�rio tentando de duas formas:
	*	Primeiro, tenta identificar o usu�rio pela face, utilizando algor�tmos de
	*	vis�o computacional providos pela biblioteca OpenCV.
	*	Caso o reconhecimento falhe, � pedido ao usu�rio que entre com uma senha.
	*	Nesse caso, o sistema realimenta a base de dados com novas fotos e cria a sess�o
	*	daquele usu�rio.
	*
	*	\param matricula Matr�cula do usu�rio que pretende fazer acesso.
	*	\return Inst�ncia com informa��es do usu�rio
	*/
	Usuario Credencia(string matricula);

	/*!
	*	\brief Gera uma inst�ncia de usu�rio.
	*
	*	\param matricula Matr�cula do usu�rio.
	*	\return Usu�rio.
	*/
	Usuario NovoUsuario(string matricula);
	
private:
	/*!
	*	\brief Faz a verifica��o de usu�rio via webcam.
	*/
	bool _ReconheceFace(string matricula);
	
	/*!
	*	\brief Faz a captura de novas fotos do usu�rio via webcam.
	*/
	void _AtualizaBancoDeFotos();

	bool _CriaBancoDeFotos(string matricula);

	void _mySleep(int);

	void _read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';');

	string _digiteSenha();
};

//#endif