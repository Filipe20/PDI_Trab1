#include "Objeto.hpp"

/////////////////////////////////////////////////////////////
class Fantasma
{
public:	
	Fantasma(float x1,float y2,float z3,float raio,float alt);
	~Fantasma();

    void vertex(double th2, double ph2, double raio,float xi,float yi,float zi);
    void vertex2(double th2, double ph2, double raio,float xi,float yi,float zi);
	//void move();
	//void direcao(int key);
	void desenha();
	void animacao();
	//void atualiza(int value);
	//void stop(int bateu);
	//void colisao(int x, int y);
	//float* hitbox();

private:

	float x , y, z,altura;
	float r;//raio
	int direc;
	int direcimag;
	int animabase=0,animaolhos=1;

	glm::vec3 points_base[3];
	glm::vec3 points[3];


private:

	void transform(void);
};