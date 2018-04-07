// Jogo PacMan
// Parede.hpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2018


#include "Objeto.hpp"


/////////////////////////////////////////////////////////////
class Parede: public Objetos
{
public:	
	Parede(float x, float y, float z, float c, float l, float h);
	~Parede();

	void desenha();
	void atualiza(int value);
	int colisao(float x, float z, float t);

private:

	float x,y,z,c,l,h;
	float theta;

	glm::vec3 points_base[3];
	glm::vec3 points[3];


private:

	void transform(void);
};


