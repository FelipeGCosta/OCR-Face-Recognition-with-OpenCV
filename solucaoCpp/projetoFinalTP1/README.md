# projetoTP1_2

## Introdu��o
Projeto final disciplina T�cnicas de Programa��o 1 

Este projeto consiste em um sistema de controle de acesso para ser utilizado na entrada dos Laborat�rios de Inform�tica (Linf). 

Sendo que no momento do cadastramento de usu�rio s�o passados suas informa��es e logo ap�s o sistema capta algumas fotos do rosto dessa pessoa com diferentes express�es faciais para que seja feita a valida��o de acesso.

O reconhecimento facial � uma das t�cnicas mais utilizadas na biometria tanto para a seguran�a da informa��o como para seguran�a de nossa sociedade. 

Este trabalho implementa um software que reconhece uma imagem retirada atrav�s de um webcam ou c�mera para reconhecer suas caracter�sticas e compar�-las com as de um banco de dados. 

Foi utilizada a biblioteca OpenCV, biblioteca para a utiliza��o de processamento de imagens de grande efic�cia e por obter excelentes resultados no reconhecimento de caracter�sticas utilizando os HaarCascade. O software foi
desenvolvido em c++.

## Requisitos Linux:

Vers�o testada Ubuntu 16.04 LTS

> Compilador :

g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609

Copyright (C) 2015 Free Software Foundation, Inc.

> Opencv 3.2.0-dev:

Fonte: https://github.com/opencv/opencv

Modulos extra: https://github.com/opencv/opencv_contrib

<h2>Requisitos Windows</h2>

> Compilador G++

Baixe o MinGW acessando <a href="https://sourceforge.net/projects/mingw-w64/">SourceForge</a>, clique depois em Download e espere o download finalizar, execute o aplicativo. Prossiga com Next e escolha a configura��o adequada, como uma vers�o mais recente e a arquitetura compat�vel. Clique em Next at� finalizar a instala��o. Ser� mostrado uma tela inicial mostrando informa��es do Projeto. Prossiga at� chegar em uma tela para escolher os recursos que ser�o instalados, selecione mingw32-base e o mingw32-gcc-g++. Depois disso, clique em Instalattion > Apply Changes.

Agora ser� necess�rio adicionar o diret�rio de bin�rios do MinGW na Path do Windows, para isso, clique no Iniciar, e depois clique com o bot�o direito em Computador, e em seguida em Propriedades. No lado esquerdo clique em Configura��es avan�adas do sistema. Clique agora em vari�veis de ambiente. Ache a vari�vel PATH, e clique em editar, no fim dela, adicione um �;� (ponto e v�rgula), e coloque o diret�rio dos bin�rios que foram instalados com o MinGW (geralmente em C:\Program Files (x86)\mingw-w64). Para testar se deu certo, abra o Prompt de Comando e digite �g++�.

> .NET Framework

Ser� utilizado nas pr�ximas instala��es o .NET Framework. Baixe acessando <a href="https://www.microsoft.com/net/download/framework">Microsoft</a>, escolha uma vers�o 4.3 ou superior e clique em Download. Execute e aceite os termos de contrato e em seguida clique em instalar, espere o download e a instala��o finalizar.

> OpenCV

Baixe o <a href="http://opencv.org/releases.html">OpenCV</a> vers�o 2.4.* de prefer�ncia ou acesse diretamente pela p�gina do <a href="https://sourceforge.net/projects/opencvlibrary/files/opencv-win/2.4.11/opencv-2.4.11.exe/download">SourceForge</a> que ir� fazer o Download automaticamente. Depois abra e clique em extrair.

Agora ser� necess�rio adicionar o diret�rio de bin�rios do OpenCV na Path do Windows, para isso, clique no Iniciar, e depois clique com o bot�o direito em Computador, e em seguida em Propriedades. No lado esquerdo clique em Configura��es avan�adas do sistema. Clique agora em vari�veis de ambiente. Em vari�veis do sistema clique em Novo, defina o nome da vari�vel como "OPENCV_DIR" sem aspas e o valor da vari�vel como o diret�rio da build do OpenCV (ex. C:\opencv\build;). Ache a vari�vel PATH, e clique em editar, no fim dela, adicione um �;� (ponto e v�rgula), e coloque "%OPENCV_DIR%" ligado a continua��o do diret�rio dos bin�rios que foram instalados com o OpenCV (ex. %OPENCV_DIR%\x64\vc11\bin;).

> Visual Studio IDE

Para quem gosta do aux�lio que uma IDE proporciona, sugiro baixar o <a href="https://www.visualstudio.com/pt-br/vs/cplusplus/?rr=https%3A%2F%2Fwww.google.com.br%2F">VisualStudio</a>.

Veja aqui um <a href="http://www2.ic.uff.br/~crisnv/disciplinas/procImg/Tutorial_de_Instal_do_OpenCV.pdf">tutorial</a> instrutivo que ir� deixar a IDE configurada para reconhecer a biblioteca OpenCV.

<h2>Build e Compilation</h2>

Baixe o <a href="https://cmake.org/download/">CMake</a> para a portabilidade do seu projeto ap�s verificar o tipo de sistema de sua m�quina e extraia os arquivos. Ap�s a extra��o encontre o diret�rio bin�rio do CMake e execute o programa cmake-gui. Ap�s isso insira o caminho dos arquivos de c�digo na primeira entrada e na segunda insira o caminho que ir� ser armazenados os arquivos build do CMake. Clique em Configure e depois que nenhum erro for relatado, voc� pode clicar no bot�o Generate. E seu trabalho estar� pronto.

CMakeLists:

<pre>cmake_minimum_required (VERSION 2.6)<br>project (tp1.2)<br>add_executable(tp1.2 tp1.cpp)</pre>

Linha de comando utilizada:

<pre>cmake .</pre>


## Diagrama Casos de uso

Esse diagrama foi feito pensando nos principais atores presentes no laborat�rio.
� tamb�m uma ideia inicial de modelagem do banco de dados.

<img src="imagens/diagrama_casos_de_uso.png" alt="Diagrama de casos de uso">

Fonte:

https://yuml.me/diagram/scruffy/usecase/samples

```
[Professor]-(Reservar laborat�rio)
[Professor]-(Acessar laborat�rio)
[Professor]-(Criar cadastro de acesso)
[Aluno]-(Criar cadastro de acesso)
[Aluno]-(Acessar laborat�rio)
[Funcion�rio]-(Criar cadastro de acesso)
[Funcion�rio]-(Acessar laborat�rio)
[Funcion�rio]-(Modificar cadastro de acesso)
[Funcion�rio]-(Excluir cadastro de acesso)
```

## Diagrama de Atividades

Descreve o parte do sistema de reconhecimento de faces para permitir a entrada ou cadastrar uma pessoa no linf.

<img src="imagens/diagrama_atividade.png" alt="Diagrama de atividade">

Fonte:

https://yuml.me/diagram/nofunky/activity/samples

```
(start)->(Reconhecer_Face)-><a>[Ok]->(Permite_Acesso_Linf),
<a>[Nao_identificado]->(Digita_login_senha)->(Atualiza_Cadastro)->(Permite_Acesso_Linf)->(end)
```

##  Diagram de Sequ�ncia

Primeiro diagrama de sequ�ncia 

<img src="imagens/diagrama_sequencia.png" alt="Diagrama de sequencia">

Fonte:

https://www.websequencediagrams.com/

```
title Sistema Trabalho 2
User->SGBD: informar n�mero de matr�cula
alt Matr�cula encontrada
    SGBD->SYSTEM: retorna fotos do User
    User->SYSTEM: captura uma foto
    SYSTEM->User: reconhece foto
    alt foto N�o reconhecida
        User->SYSTEM: captura foto
        SYSTEM->SGBD: armazena nova foto
    end
else Matr�cula n�o encontrada
    SGBD->User: cadastrar_User()
    User->SGBD: informa dados()
    User->SYSTEM: captura fotos()
    SYSTEM->SGBD: armazena fotos()
end
SYSTEM->User: Validar User
```

##  Diagrama de Classes

Primeiro diagrama de classes

<img src="imagens/diagrama_simplificado_de_classes.png" alt="diagrama simplificado de classes">

<h2>Diagrama de Sequ�ncia</h2>

<img src="imagens/diagram.png" alt="diagrama sequencia">

<h2>Screenshots</h2>

<img src="imagens/ss.png" alt="ss">
<img src="imagens/ss2.png" alt="ss2">
<img src="imagens/ss3.png" alt="ss3">
<img src="imagens/ss4.png" alt="ss4">

