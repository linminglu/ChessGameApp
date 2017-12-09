/************************************************************************************
 * file: 		HallLayer.cpp
 * copyright:	Cavan.Liu 2017
 * Author: 		Cavan.Liu
 * Create: 		2017/07/23 23:08:24
 * Description: 
 * Version	Author		Time			Description
 * V1.0    	Cavan.Liu	2017/07/23			
 *
 ************************************************************************************/

#include "HallLayer.h"

USING_NS_CC;

//************************************************************************
// 	Function:	createScene
//	Privilege:	public
//	Create:		2017/07/14
//	Author:		Cavan.Liu
//	Parameter:	
//	Return:		bool
//************************************************************************
Scene* HallLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HallLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

//************************************************************************
// 	Function:	init
//	Privilege:	public
//	Create:		2017/07/12
//	Author:		Cavan.Liu
//	Parameter:	
//	Return:		bool
//************************************************************************
bool HallLayer::init()
{
	if (!Layer::init())
		return false;

	// 1.set scene information
	if (!ESLayer::initLayerBg(this, PNG_HALL_BG))
		return false;

	// 2.set menu item
	if (!initMenuItem())
		return false;

	/*CCSpriteFrame* pSpriteFrameSettingUp = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_SETTING_UP);

	CCSprite* pSpriteSettingUp = Sprite::create(PNG_SETTING_UP);
	CCSprite* pSpriteSettingDown = Sprite::create(PNG_SETTING_DOWN);

	auto sizePngSettingUp = pSpriteSettingUp->getTextureRect().size;

	pSpriteSettingUp->setScaleX(RESOLUTION_WIDTH/sizePngSettingUp.width);
	pSpriteSettingUp->setScaleY(RESOLUTION_HEIGHT/sizePngSettingUp.height);

	int nPngSettingX = SIZE_SCREEN.width - sizePngSettingUp.width - SCREEN_DISTANCE_X;
	int nPngSettingY = SCREEN_DISTANCE_Y;

	MenuItemSprite* pMenuItemSprite = MenuItemSprite::create(pSpriteSettingUp, pSpriteSettingDown, CC_CALLBACK_1(HallLayer::menuItemSettingCallback, this));

	// 2.1 scale png to adapter to screen size and position
	// todo 2017/07/22 to be continue 
	pMenuItemSprite->setPosition(Director::getInstance()->convertToGL(Vec2(nPngSettingX, nPngSettingY)));

	// 3.create menu item
	Menu* pMenu = Menu::create(pMenuItemSprite, NULL);

	// 4.set menu position
	pMenu->setPosition(Vec2::ZERO);

	// 5.add menu
	this->addChild(pMenu);*/

	return true;
}

//************************************************************************
// 	Function:	initialize menu item
//	Privilege:	
//	Create:		2017/07/24
//	Author:		Cavan.Liu
//	Parameter:	
//	Return:		void
//************************************************************************
bool HallLayer::initMenuItem()
{
	ST_MENU_ITEM_INFO stMenuItemInfo = {0};

	sprintf_s(stMenuItemInfo.szPNGMenuItem, sizeof(stMenuItemInfo.szPNGMenuItem), PNG_SETTING_UP.c_str());
	sprintf_s(stMenuItemInfo.szPNGNormal, sizeof(stMenuItemInfo.szPNGNormal), PNG_SETTING_UP.c_str());
	sprintf_s(stMenuItemInfo.szPNGSelect, sizeof(stMenuItemInfo.szPNGSelect), PNG_SETTING_DOWN.c_str());

	stMenuItemInfo.nX = 200;
	stMenuItemInfo.nY = 200;

	//typedef void (*pMenuItemSettingCallback)(cocos2d::Ref *);

	//stMenuItemInfo.ccMenuCallbackFunc = pMenuItemSettingCallback;

	return ESLayer::initMenuItem(this, &stMenuItemInfo);
}

//************************************************************************
// 	Function:	menuItemSettingCallback
//	Privilege:	
//	Create:		2017/07/24
//	Author:		Cavan.Liu
//	Parameter:	
//	Return:		void
//************************************************************************
void HallLayer::menuItemSettingCallback(cocos2d::Ref * pSender)
{
	log("��������ҳ�� HallLayer::menuItemSettingCallback(cocos2d::Ref * pSender)");

	auto createSceneSettingLayer = SettingLayer::createScene();

	Director::getInstance()->pushScene(createSceneSettingLayer);
}
