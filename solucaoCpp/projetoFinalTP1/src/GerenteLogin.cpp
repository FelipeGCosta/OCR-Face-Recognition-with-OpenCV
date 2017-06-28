#include "GerenteLogin.h"

//#define DEBUG
#ifdef DEBUG
	#define DEBUG_PRINT(x) do{cout << x << endl;}while(0)
#else
	#define DEBUG_PRINT(x)  
#endif

GerenteLogin::GerenteLogin()
{
}


GerenteLogin::~GerenteLogin()
{
}

void GerenteLogin::Iniciar() {
	DEBUG_PRINT("GerenteLogin::Iniciar - inicio");
	//tenta fazer login via _entradaWebcam().
	//se n�o conseguir, faz via teclado
	_entradaTeclado();
	DEBUG_PRINT("GerenteLogin::Iniciar - fim");
}

void GerenteLogin::_entradaTeclado() {
	DEBUG_PRINT("GerenteLogin::_entradaTeclado - inicio");
	//pega as informa��es MATRICULA e SENHA via teclado
	//envia a interface de persist�ncia para tentar efetuar login
	
	string mat;
	cout << "Matricula:";
	cin >> mat;
	cout << "Matricula inserida: " << mat << endl;
	cin >> mat;

	DEBUG_PRINT("GerenteLogin::_entradaTeclado - fim");
}

Usuario GerenteLogin::Credencia(string matricula) {
	DEBUG_PRINT("GerenteLogin::Credencia - inicio");
	Usuario usuario;
	if ( GerenteBD::ExisteUsuario(matricula) ) { //usuario cadastrado
		DEBUG_PRINT("	Usuario cadastrado na base de dados");
		if (ReconheceFace(matricula)) {//reconhece o rosto
			//reconheceu pelo rosto
			//modifica a inst�ncia de usuario
			usuario = GerenteBD::BuscaUsuario(matricula);
			DEBUG_PRINT("		Matricula: " << usuario.GetMatricula());
			DEBUG_PRINT("		Nome: " << usuario.GetNome());
			return usuario;
		}
		else {//caso nao reconhecido
			string senha;
			cout << "Usuario nao reconhecido" << endl;
			cout << "Digite sua senha: ";
			cin >> senha;
			if (GerenteBD::ChecaUsuario(matricula, senha)) {
				usuario = GerenteBD::BuscaUsuario(matricula);
				DEBUG_PRINT("		Matricula: " << usuario.GetMatricula());
				DEBUG_PRINT("		Nome: " << usuario.GetNome());
			}
			return usuario;
		}
	}
	DEBUG_PRINT("GerenteLogin::Credencia - fim");
	return usuario;
}

bool GerenteLogin::ReconheceFace(string matricula) {

	if (false) {//caso reconhe�a pelo rosto
		cout << "Usuario reconhecido" << endl;
		return true;
	}
	else {//caso contrario
		cout << "Rosto nao reconhecido" << endl;
		return false;
	}

}

/*

void GerenteLogin::detectaTiraFoto(Mat frame)
{

	std::vector<Rect> faces;
	Mat frame_gray;
	Mat original = frame.clone();
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);
	//-- Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(150, 0, 255), 4, 8, 0);
		Mat faceROI = frame_gray(faces[i]);
		std::vector<Rect> eyes;
		//-- In each face, detect eyes
		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
		for (size_t j = 0; j < eyes.size(); j++)
		{
			Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
			int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
			circle(frame, eye_center, radius, Scalar(255, 0, 0), 4, 8, 0);
		}
		if (eyes.size() == 2 && num < 10) {

			char nome[20];
			sprintf(nome, "%d-alpha.png", num);
			imwrite(nome, frame_gray);
			num++;
			cout << "Sorria! " << num << endl;
			if (num == 10) {
				cout << "10 fotos... pronto!" << endl;
			}
		}
		else if (eyes.size() > 0) {
			cout << "achei " << eyes.size() << " olhos no total" << endl;
		}
	}
	//-- Show what you got
	imshow(window_name, frame);
}

void GerenteLogin::_mySleep(int sleepMs)
{
#ifdef __linux__ 
	usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
#else
	Sleep(sleepMs);
#endif
}
*/
Usuario GerenteLogin::NovoUsuario(string matricula) {
	string nome;
	cout << "Nome: ";
	cin >> nome;
	Usuario usuario(nome, matricula);
	GerenteBD::InsereUsuario(usuario);
	return usuario;
}

#ifdef DEBUG
#undef DEBUG
#endif // DEBUG
