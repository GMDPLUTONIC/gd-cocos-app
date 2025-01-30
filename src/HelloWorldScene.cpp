#include "HelloWorldScene.hpp"
#include "log.hpp"

CCScene* HelloWorld::scene() {
	auto* scene = CCScene::create();
	auto* layer = HelloWorld::create();
	scene->addChild(layer);

	return scene;
}

bool HelloWorld::init() {
	if (!CCLayer::init()) {
		return false;
	}
	auto winSize = CCDirector::sharedDirector()->getWinSize();
	println("Window size is {}x{}", winSize.width, winSize.height);

	auto* label = CCLabelBMFont::create("Singularity", "bigFont.fnt");
	label->setPosition(winSize / 2);
	this->addChild(label);

	auto* sprite = CCSprite::create("game_bg_07_001.png");
	sprite->setZOrder(-100);
	sprite->setColor({122, 179, 239});
	sprite->setPosition(winSize / 2);
	sprite->setScale(1.9f);
	this->addChild(sprite);

	m_fpsLabel = CCLabelBMFont::create("FPS: 0", "chatFont.fnt");
	m_fpsLabel->setPosition(0, winSize.height);
	m_fpsLabel->setAnchorPoint({0, 1});
	this->addChild(m_fpsLabel);

	this->scheduleUpdate();

	return true;
}

void HelloWorld::update(float dt) {
	CCLayer::update(dt);
	m_fpsLabel->setString(std::format("FPS: {:.2f}", 1 / dt).c_str());
}
