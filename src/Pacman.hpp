#include "Objeto.hpp"


/////////////////////////////////////////////////////////////
class Pacman
{
public:	
	Pacman(float x,float y,float z,float r);
	~Pacman();

    void vertex(double th2, double ph2, double raio,float xi,float yi,float zi);
    void vertex2(double th2, double ph2, double raio,float xi,float yi,float zi);
	void move();
	void direcao(int key);
	void desenha();
	void atualiza(int value);
	void stop(int bateu);
	void colisao(int x, int y);
	float* hitbox();

private:

	float x , y, z;
	float r;//raio
	int direc;
	int direcimag;

	glm::vec3 points_base[3];
	glm::vec3 points[3];


private:

	void transform(void);
};