/**********************************************************************************
// Player (C�digo Fonte)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Boss.h"
#include "Platform.h"
#include "Timer.h"
#include "GravityGuy.h"
#include "Bullet.h"
#include "BossLVL1.h"

// ---------------------------------------------------------------------------------

Boss::Boss(uint boss)
{
	type = BOSS;
	this->boss = boss;

	switch (boss) {
	case BANSHEE:
		
		tileSet = new TileSet("Resources/boss_level1.png", 150, 300, 1, 1);
		anim = new Animation(tileSet, 0.120f, true);

		uint idle[1] = { 0 };

		anim->Add(0, idle, 1);

		// cria bounding box
		BBox(new Rect(
			-1.0f * this->Width() / 2.0f,
			-1.0f * this->Height() / 2.0f,
			this->Width() / 2.0f,
			this->Height() / 2.0f
		));
		hp = 200;

		// posi��o inicial da banshee
		MoveTo(window->Width() - (this->Width() / 2.0f), ( 470.0f * GravityGuy::totalScale ), 0.55f);
		
		break;
	}
	
}

// ---------------------------------------------------------------------------------

Boss::~Boss()
{
	delete anim;
	delete tileSet;
}

// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------

void Boss::Update()
{
	// atualiza anima��o
	anim->Select(0);
	anim->NextFrame();
}

// ---------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------