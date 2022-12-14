/**********************************************************************************
// Player (C?digo Fonte)
//
// Cria??o:     20 Abr 2012
// Atualiza??o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri??o:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Bullet.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "BossLVL1.h"
#include "Enemies.h"

// ---------------------------------------------------------------------------------

Bullet::Bullet(bool direction, float scale)
{
    type = BULLET;
    this->scale = scale;
    this->direction = direction;

    tileset = new TileSet("Resources/bullet.png", 18, 5, 5, 10);
    anim = new Animation(tileset, 0.06f, true);

    uint right[5] = { 0, 1, 2, 3, 4 };
    uint left[5] = { 9, 8, 7, 6, 5 };

    anim->Add(0, left, 5);
    anim->Add(1, right, 5);

    BBox(new Rect(
        -1.0f * this->Width() / 2.0f,
        -1.0f * this->Height() / 2.0f,
        this->Width() / 2.0f,
        this->Height() / 2.0f
    ));
    
    if(direction)
        MoveTo(GravityGuy::player->Right(), GravityGuy::player->Y(), Layer::FRONT);
    else
        MoveTo(GravityGuy::player->Left(), GravityGuy::player->Y(), Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Bullet::~Bullet()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Bullet::OnCollision(Object* obj) {
	
	if (obj->type == BOSS) {
		float xDiff = x - obj->X();

		if (xDiff < 0)
			xDiff = -xDiff;

		if (xDiff <= 50 * GravityGuy::totalScale) {
			Boss* boss = (Boss*)obj;
			boss->hp -= 1;
			if (GravityGuy::currentLvl == BOSS_LEVEL)
				BossLVL1::scene->Delete(this, MOVING);
		}
	}

    if (obj->type == ENEMYS) {
        
        float xDiff = x - obj->X();

        if (xDiff < 0)
            xDiff = -xDiff;

        if (xDiff <= 10 * GravityGuy::totalScale) {
            Enemies* enemies = (Enemies*)obj;
           
            if (GravityGuy::currentLvl == LEVEL_1) {
                Level1::scene->Delete(enemies, MOVING);

                Level1::scene->Delete(this, MOVING);

            }
            else if (GravityGuy::currentLvl == LEVEL_2) {
                Level2::scene->Delete(enemies, MOVING);
                Level2::scene->Delete(this, MOVING);

            }
            else if (GravityGuy::currentLvl == LEVEL_3) {
                Level3::scene->Delete(this, MOVING);

                Level3::scene->Delete(enemies, MOVING);


            }
            else if (GravityGuy::currentLvl == LEVEL_4) {
                Level4::scene->Delete(enemies, MOVING);

                Level4::scene->Delete(this, MOVING);



            }
            else if (GravityGuy::currentLvl == BOSS_LEVEL) {
                BossLVL1::scene->Delete(enemies, MOVING);

                BossLVL1::scene->Delete(this, MOVING);



            }
        }

    }
}

// ---------------------------------------------------------------------------------

void Bullet::Update()
{
    if (!GravityGuy::playerLft && !GravityGuy::playerRgt) {
        if (direction) {
            Translate(( 700.0f + GravityGuy::platform_velocity ) * gameTime, 0);
        }
        else
            Translate(( -700.0f + GravityGuy::platform_velocity ) * gameTime, 0);
    }
    else {
        if (direction) {
            Translate(700.0f * gameTime, 0);
        }
        else
            Translate(-700.0f * gameTime, 0);
    }
    
    //deleta quando sair da tela
	if (x < 0 || x > window->Width()) {
		if (GravityGuy::currentLvl == LEVEL_1)
			Level1::scene->Delete(this, MOVING);
		else if (GravityGuy::currentLvl == LEVEL_2)
			Level2::scene->Delete(this, MOVING);
		else if (GravityGuy::currentLvl == LEVEL_3)
			Level3::scene->Delete(this, MOVING);
		else if (GravityGuy::currentLvl == LEVEL_4)
			Level4::scene->Delete(this, MOVING);
		else if (GravityGuy::currentLvl == BOSS_LEVEL)
			BossLVL1::scene->Delete(this, MOVING);
	}

    anim->Select((uint)direction);
    anim->NextFrame();
}