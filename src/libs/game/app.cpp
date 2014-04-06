#include "app.h"

#include "SystemDisplay.h"
#include "SystemMove.h"
#include "InputSystem.h"
#include "SystemAnimation.h"
#include "SystemMoveAnimation.h"
#include "SystemScaling.h"
#include "SystemCollision.h"
#include "SystemConversation.h"

using namespace aunteater;

void HardCore::init()
{
	Polycode::CoreServices::getInstance()->getRenderer()->setTextureFilteringMode(Polycode::Renderer::TEX_FILTERING_NEAREST);

	std::vector<Entity> bgs = createBackground(mScreen);
	for (Entity bg : bgs)
	{
		mEngine.addEntity(bg);
	}

	std::vector<Entity> pngs = createPng(mScreen);
	for (Entity png : pngs)
	{
		mEngine.addEntity(png);
	}

	Entity player = createPlayer(mScreen);
	mEngine.addEntity("player", player);

	std::vector<Entity> barriers = createBarriers();
	for (Entity barrier : barriers)
	{
		mEngine.addEntity(barrier);
	}
	
	new SystemDisplay(mEngine);
	new SystemMove(mEngine);
	new InputSystem(mEngine);
	new SystemAnimation(mEngine);
	new SystemMoveAnimation(mEngine);
	new SystemScaling(mEngine);
	new SystemCollision(mEngine);
    new SystemConversation(mEngine,
                           BASE_PATH "scenarios/accroche.txt",
                           BASE_PATH "scenarios/conversation.txt");
}