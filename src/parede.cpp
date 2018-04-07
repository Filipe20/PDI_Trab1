// Jogo PacMan
// Parede.cpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2018

#include <stdlib.h>
#include <stdio.h>
#include "parede.hpp"

Parede::Parede(float x, float y, float z, float c, float l, float h)
{
	this->x=x;
	this->y=y;
	this->z=z;
	this->c=c;
	this->l=l;
	this->h=h;
		//	std::cout << "inicio: " << glm::to_string(points[0]);
	//points = *point_;
}

//---------------------------------------------------------------------
Parede::~Parede()
{

}

//---------------------------------------------------------------------
void Parede::atualiza(int value)
{
	x += value;
	y += value;

	transform();
}

//---------------------------------------------------------------------
int Parede::colisao(float xc, float zc, float tc)
{


	if ( (xc+tc<=(x+c/2))&&(xc+tc>=(x-c/2))&&(zc<=(z+l/2))&&(zc>=(z-l/2)))
	{
		return 1;
	}
	else if((xc-tc<=(x+c/2))&&(xc-tc>=(x-c/2))&&(zc<=(z+l/2))&&(zc>=(z-l/2)))
	{
		return 2;
	}
	else if((xc<=(x+c/2))&&(xc>=(x-c/2))&&(zc+tc<=(z+l/2))&&(zc+tc>=(z-l/2)))
	{
		return 3;
	}
	else if((xc<=(x+c/2))&&(xc>=(x-c/2))&&(zc-tc<=(z+l/2))&&(zc-tc>=(z-l/2)))
	{
		return 4;
	}
	return 0;

}

//---------------------------------------------------------------------
void Parede::transform(void)
{

	//glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
	glm::mat3 Model = glm::mat3(1.0);
	Model[2] = glm::vec3(x, y, 1.0);

	//std::cout << "tes: " << glm::to_string(Model[0]) << std::endl;
	//std::cout << "tes: " << glm::to_string(Model[1])<< std::endl;
	//std::cout << "tes: " << glm::to_string(Model[2])<< "\n" << std::endl;

	//glm::vec4 Transformed = Model * Position;

	for (int i = 0; i < 3; i++)
	{
		points[i] = Model * points_base[i];
	}
}

//---------------------------------------------------------------------
void Parede::desenha()
{
	glLineWidth(3.0f);
	glColor3f(1.0f, 0.0f, 0.0f); // rosa
	glBegin(GL_QUADS);
	glNormal3f(0.0, -1, 0); // baixo
	glVertex3f( x +  c / 2, 0,  z -  l / 2);
	glVertex3f( x +  c / 2, 0,  z +  l / 2);
	glVertex3f( x -  c / 2, 0,  z +  l / 2);
	glVertex3f( x -  c / 2, 0,  z -  l / 2);

	// glEnd();

	glColor3f(1.0f, 1.0f, 1.0f); // azul
	glBegin(GL_QUADS);	   // cima
	glNormal3f(0.0, 1.0, 0);
	glVertex3f( x +  c / 2, h,  z -  l / 2);
	glVertex3f( x +  c / 2, h,  z +  l / 2);
	glVertex3f( x -  c / 2, h,  z +  l / 2);
	glVertex3f( x -  c / 2, h,  z -  l / 2);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f); //Verde
	glBegin(GL_QUADS);
	glNormal3f(1.0, 0.0, 0.0); // frente
	glVertex3f( x +  c / 2, 0,  z -  l / 2);
	glVertex3f( x +  c / 2, 0,  z +  l / 2);
	glVertex3f( x +  c / 2, h,  z +  l / 2);
	glVertex3f( x +  c / 2, h,  z -  l / 2);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f); //Vermelha
	glBegin(GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0); // fundo
	glVertex3f( x -  c / 2, 0,  z -  l / 2);
	glVertex3f( x -  c / 2, 0,  z +  l / 2);
	glVertex3f( x -  c / 2, h,  z +  l / 2);
	glVertex3f( x -  c / 2, h,  z -  l / 2);

	glColor3f(1.0f, 0.0f, 0.0f); // amarelo
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1); // lado
	glVertex3f( x +  c / 2, 0,  z -  l / 2);
	glVertex3f( x +  c / 2, h,  z -  l / 2);
	glVertex3f( x -  c / 2, h,  z -  l / 2);
	glVertex3f( x -  c / 2, 0,  z -  l / 2);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f); //branco
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1); // lado
	glVertex3f( x +  c / 2, 0,  z +  l / 2);
	glVertex3f( x +  c / 2, h,  z +  l / 2);
	glVertex3f( x -  c / 2, h,  z +  l / 2);
	glVertex3f( x -  c / 2, 0,  z +  l / 2);
	glEnd();
}
