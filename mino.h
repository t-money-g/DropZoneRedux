//Future dropzone class designed for generating
//appropriate tetramino and handling their graphics

#ifndef _MINO_H
#define _MINO_H
#define WIN32_LEAN_AND_MEAN

#include "image.h"
#include "constants.h"
#include "entity.h"

namespace minoNS {
	const float SPEED = 200;
	const float MIN_VY = 1;                 // minumum Y velocity
	const float MASS = 1.0f;
	enum MINO_TYPE{ LBLOCK, TBLOCK, OBLOCK };
}

class Mino : public Entity {

private:
	Image minoData[4]; 
	int type;
	
public: 

	//default constructor
	Mino();
	
	//Destructor 
	virtual ~Mino();


	bool initialize();


	void makeMino(Graphics *graphics, TextureManager *minoTexture);

	void draw();
	void setMinoData();
	void update(float frametime);
};
#endif