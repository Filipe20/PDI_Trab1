#include "Objeto.hpp"


/////////////////////////////////////////////////////////////
class Fruta
{
public:	
	Fruta(float x,float y,float z,float r);
	~Fruta();

    void vertex(double th2, double ph2, double raio,float xi,float yi,float zi);
    void vertex2(double th2, double ph2, double raio,float xi,float yi,float zi);
	void desenha();
	void atualiza(int value);
	void colisao();
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