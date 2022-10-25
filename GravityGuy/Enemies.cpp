/**********************************************************************************
// Platform (C�digo Fonte)
//
// Cria��o:     21 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#include "Enemies.h"
#include "Level1.h"
#include "BossLVL1.h"
#include "Level4.h"
#include "Level3.h"
#include "Level2.h"

// ---------------------------------------------------------------------------------

Enemies::Enemies(float posX, float posY, uint enem, Color tint) : color(tint)
{

	type = ENEMYS;

	uint idle[5] = { 0, 1, 2, 3, 4 };
	uint idleInv[5] = { 9, 10, 11, 12, 13 };
	
	hp = 2;
	touched = false;
	touchedBullet = false;

	
	switch (enem)
	{

	case ENEMY:
		tileSet = new TileSet("Resources/enemy.png", 70, 80, 5, 5);
		anim = new Animation(tileSet, 0.120f, true);

		anim->Add(IDLE_I, idle, 5);
		anim->Add(IDLE_INV_I, idleInv, 5);

		break;

	case ENEMY_FLY:
		tileSet = new TileSet("Resources/Fly Enemy.png", 80, 40, 6, 6);
		anim = new Animation(tileSet, 0.120f, true);

		break;
	}

	BBox(new Rect(
		//esq
		-1.0f * (this->Width() - 30) / 2.0f,
		//top
		-1.0f * (this->Height() - 30) / 2.0f,
		//di
		(this->Width()-30) / 2.0f,
		//down
		(this->Height()-30) / 2.0f
	));

	state = IDLE_I;
	xOrigin = posX * GravityGuy::totalScale;
	yOrigin = posY * GravityGuy::totalScale;
	velocity = 80.0f * altVel(mt);

	MoveTo(posX * GravityGuy::totalScale, posY * GravityGuy::totalScale, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

Enemies::~Enemies()
{
	delete anim;
	delete tileSet;
}


// -------------------------------------------------------------------------------

void Enemies::Update()
{
	
	if (touched) {

		if (time.Elapsed(1.5))
		{
			touched = false;
			time.Reset();
			time.Stop();
		}

	}

	if (touchedBullet)
	{
		time.Start();
		if (time.Elapsed(1.5))
		{
			touchedBullet = false;
			time.Reset();
			time.Stop();
		}
	}

	if (enemyType == ENEMY) {

		//al�m inv�s de transladar, a plataforma tem sua origem alterada 
		if (!GravityGuy::playerRgt)
			xOrigin += GravityGuy::platform_velocity * gameTime;
		if (!GravityGuy::playerLft)
			xOrigin += GravityGuy::platform_velocity * gameTime;
	}

	if (!GravityGuy::playerRgt)
		Translate(GravityGuy::platform_velocity * gameTime, 0);
	if (!GravityGuy::playerLft)
		Translate(GravityGuy::platform_velocity * gameTime, 0);




	if (enemyType == ENEMY_FLY) {    //plataforma horizontal 

		float distance = GravityGuy::player->X() - x;
		if (-distance <= 30.0f)
		{
			Translate(0, 100.0f * gameTime - 2.0f);

		}

		float diff = x - xOrigin;

		if (diff < 0)
			diff = -diff;

		if (diff >= (150.0f * GravityGuy::totalScale))
			direcao = -direcao;

		Translate(100.0f * direcao * gameTime, 0);

	}

	else if (enemyType == ENEMY) {    //plataforma horizontal 

		float diff = x - xOrigin;

		if (diff < 0)
			diff = -diff;

		if (diff >= (150.0f * GravityGuy::totalScale))
			direcao = -direcao;

		Translate(100.0f * direcao * gameTime, 0);
	}

	anim->Select(state);
	anim->NextFrame();
}



// -------------------------------------------------------------------------------
