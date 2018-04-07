// Jogo PacMan 
// application.hpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2018

#include <iostream>
#include <vector>
#include <list>

#include <GL/glut.h>


#include "Objeto.hpp"
#include "parede.hpp"
#include "Pacman.hpp"
#include "Fantasma.hpp"
#include "Fruta.hpp"


using namespace std;

/////////////////////////////////////////////////////////////
class Jogo
{
public:
	Jogo(int argc, char** argv);
	~Jogo(void);

	void desenha();
	void atualizatamanho(GLsizei w, GLsizei h);
	void KeyboardHandle(unsigned char key, int x, int y);
	void MouseHandle(int button, int state, int x, int y);
	void SpecialKeyHandle(int key, int x, int y);
	void atualiza(int value, void (*func_ptr)(int));

private:

	int time;
	
    float parede = 1.2, b = 0;
	int a = 1, h = 2;
	GLfloat xf;
	GLfloat yf;
	GLfloat win;
	GLint view_w;
	GLint view_h;
	GLfloat angle = 45, fAspect;

	Fantasma *fantasma;
	Pacman *pacman;
	Fruta *fruta;
	list<Objetos*> mapa_;

private:
	void Inicializa (void);
	bool insere_objetos(void);
	
};

