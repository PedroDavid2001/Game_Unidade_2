/**********************************************************************************
// Background (C?digo Fonte)
// 
// Cria??o:     21 Abr 2012
// Atualiza??o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri??o:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"
#include "GravityGuy.h"

// ---------------------------------------------------------------------------------

Background::Background(Color tint) : color(tint)
{
	
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
	
	// carrega nuvens
	clouds1 = new Sprite("Resources/clouds.png");
	clouds2 = new Sprite("Resources/clouds.png");

	if (GravityGuy::currentLvl != BOSS_LEVEL) {
		// cria sprites do plano de fundo
		sky = new Sprite("Resources/background.png");

		//inicializa a posi??o inicial
		posC1 = posC2 = x;
		posB11 = posB12 = x;
		posB21 = posB22 = x;
		posB31 = posB32 = x;
		
		if (GravityGuy::currentLvl == LEVEL_1) {
			build_11 = new Sprite("Resources/city.png");
			build_12 = new Sprite("Resources/city.png");
			build_21 = new Sprite("Resources/city2.png");
			build_22 = new Sprite("Resources/city2.png");
			build_31 = new Sprite("Resources/city3.png");
			build_32 = new Sprite("Resources/city3.png");
		}
		else if(GravityGuy::currentLvl == LEVEL_2) {

			build_11 = new Sprite("Resources/city_fase2.png");
			build_12 = new Sprite("Resources/city_fase2.png");
			build_21 = new Sprite("Resources/city2_fase2.png");
			build_22 = new Sprite("Resources/city2_fase2.png");
			build_31 = new Sprite("Resources/city3_fase2.png"); 
			build_32 = new Sprite("Resources/city3_fase2.png");
		}
		else if (GravityGuy::currentLvl == LEVEL_3) {

			build_11 = new Sprite("Resources/city_fase3.png");
			build_12 = new Sprite("Resources/city_fase3.png");
			build_21 = new Sprite("Resources/city2_fase3.png");
			build_22 = new Sprite("Resources/city2_fase3.png");
			build_31 = new Sprite("Resources/city3_fase3.png");
			build_32 = new Sprite("Resources/city3_fase3.png");
		}
		else if (GravityGuy::currentLvl == LEVEL_4) {

			build_11 = new Sprite("Resources/city_fase4.png");
			build_12 = new Sprite("Resources/city_fase4.png");
			build_21 = new Sprite("Resources/city2_fase4.png");
			build_22 = new Sprite("Resources/city2_fase4.png");
			build_31 = new Sprite("Resources/city3_fase4.png");
			build_32 = new Sprite("Resources/city3_fase4.png");
		}

	}
	else {	
		bossBg = new Sprite("Resources/background_boss.png");
	}
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    delete clouds1;
    delete clouds2;
    delete sky;
	delete bossBg;
	delete build_11;
	delete build_12;
	delete build_21;
	delete build_22;
	delete build_31;
	delete build_32;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
	if (GravityGuy::currentLvl != BOSS_LEVEL) {
		if (!GravityGuy::playerLft && !GravityGuy::playerRgt) {
			//mesmo se o player estiver parado, as nuvens ir?o se mover
			posC1 += ((GravityGuy::platform_velocity / 4.0f) * gameTime) - (50.0f * gameTime);
			posC2 += ((GravityGuy::platform_velocity / 4.0f) * gameTime) - (50.0f * gameTime);

			posB11 += GravityGuy::platform_velocity * gameTime;
			posB12 += GravityGuy::platform_velocity * gameTime;

			posB21 += (GravityGuy::platform_velocity / 2.0f) * gameTime;
			posB22 += (GravityGuy::platform_velocity / 2.0f) * gameTime;

			posB31 += (GravityGuy::platform_velocity / 4.0f) * gameTime;
			posB32 += (GravityGuy::platform_velocity / 4.0f) * gameTime;
		}
		else {
			posC1 -= (50.0f * gameTime);
			posC2 -= (50.0f * gameTime);
		}
	}
	else {
		posC1 -= (20.0f * gameTime);
		posC2 -= (20.0f * gameTime);
	}
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
	float cloudWidth = GravityGuy::totalScale * clouds1->Width();

	clouds1->Draw(posC1, y, Layer::LOWER, GravityGuy::totalScale, 0.0f, color); //primeira leva de nuvens
	clouds2->Draw(posC2 + cloudWidth, y, Layer::LOWER, GravityGuy::totalScale, 0.0f, color); //segunda leva de nuvens

	// traz pano de fundo de volta para dentro da tela
	if (posC1 + cloudWidth / 2.0f < 0)
		posC1 += cloudWidth;

	if (posC2 + cloudWidth / 2.0f < 0)
		posC2 += cloudWidth;
	//se a primeira parte estiver ap?s zero, a segunda permance atr?s dela para tapar o espa?o
	else if (posC1 - cloudWidth / 2.0f > 0)
		posC2 -= cloudWidth;

	if (GravityGuy::currentLvl != BOSS_LEVEL) {

		// desenha pano de fundo
		sky->Draw(window->CenterX(), window->CenterY(), Layer::BACK, GravityGuy::totalScale, 0.0f, color);

		float buildWidth = GravityGuy::totalScale * build_11->Width();

		//primeira camada de predios
		build_11->Draw(posB11, y, 0.6f, GravityGuy::totalScale, 0.0f, color);
		build_12->Draw(posB12 + buildWidth, y, 0.6f, GravityGuy::totalScale, 0.0f, color);

		//segunda camada de predios
		build_21->Draw(posB21, y, 0.65f, GravityGuy::totalScale, 0.0f, color);
		build_22->Draw(posB22 + buildWidth, y, 0.65f, GravityGuy::totalScale, 0.0f, color);

		//terceira camada de predios
		build_31->Draw(posB31, y, 0.7f, GravityGuy::totalScale, 0.0f, color);
		build_32->Draw(posB32 + buildWidth, y, 0.7f, GravityGuy::totalScale, 0.0f, color);

		if (posB11 + buildWidth / 2.0f < 0)
			posB11 += buildWidth;

		if (posB12 + buildWidth / 2.0f < 0)
			posB12 += buildWidth;
		else if (posB11 - buildWidth / 2.0f > 0)
			posB12 -= buildWidth;

		if (posB21 + buildWidth / 2.0f < 0)
			posB21 += buildWidth;

		if (posB22 + buildWidth / 2.0f < 0)
			posB22 += buildWidth;
		else if (posB21 - buildWidth / 2.0f > 0)
			posB22 -= buildWidth;

		if (posB31 + buildWidth / 2.0f < 0)
			posB31 += buildWidth;

		if (posB32 + buildWidth / 2.0f < 0)
			posB32 += buildWidth;
		else if (posB31 - buildWidth / 2.0f > 0)
			posB32 -= buildWidth;
	}
	else {
		bossBg->Draw(window->CenterX(), window->CenterY(), 0.8f, GravityGuy::totalScale, 0.0f, color);
	}
    
}

// -------------------------------------------------------------------------------
