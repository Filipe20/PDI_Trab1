// Jogo PacMan 
// Objects.hpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2018


#ifndef __OBJETOS_HPP__
#define __OBJETOS_HPP__

#include <iostream>
#include <GL/glut.h>

//#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>



/////////////////////////////////////////////////////////////
class Objetos
{
public:	
	virtual void desenha() = 0;
	virtual void atualiza(int value) = 0;
	virtual int colisao(float x, float z, float t) = 0;

};


#endif
