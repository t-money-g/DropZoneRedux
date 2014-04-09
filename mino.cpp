#include "mino.h"


Mino::Mino() : Entity()
{
	frameDelay = 1;
	startFrame = 0;                             // first frame of animation
	endFrame = 0;                           // last frame of animation
	currentFrame = startFrame;
	velocity.x = minoNS::SPEED;
	velocity.y = minoNS::SPEED;
	collisionType = entityNS::BOX;
	type = minoNS::MINO_TYPE::TBLOCK;
}


Mino::~Mino()
{

}

void Mino::makeMino(Graphics *graphics, TextureManager *minoTexture)
{
	for (int i = 0; i < 4; i++) {
		if (!minoData[i].initialize(graphics, MINO_WIDTH, MINO_HEIGHT, 1, minoTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing mino"));
	}
	
	
}


void Mino::draw()
{
	for (int i = 0; i < 4; i++) {
		minoData[i].draw();
	}
	setMinoData();
}

void Mino::setMinoData() {

	if (type == minoNS::MINO_TYPE::TBLOCK) {
		minoData[0].setX(GAME_WIDTH / 2);
		minoData[0].setY(GAME_HEIGHT / 2);


		minoData[1].setX(GAME_WIDTH / 2 + MINO_WIDTH);
		minoData[1].setY(GAME_HEIGHT / 2);


		minoData[2].setX(GAME_WIDTH / 2 + MINO_WIDTH * 2);
		minoData[2].setY(GAME_HEIGHT / 2);


		minoData[3].setX(GAME_WIDTH / 2 + MINO_WIDTH);
		minoData[3].setY(GAME_HEIGHT / 2 + MINO_WIDTH);
	}

}
//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Mino::update(float frameTime) {

	Entity::update(frameTime);
	//minoData[0].spriteData.y += frameTime * velocity.y;

}