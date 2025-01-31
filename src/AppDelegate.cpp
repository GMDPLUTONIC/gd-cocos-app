#include "AppDelegate.hpp"
#include "HelloWorldScene.hpp"
#include "log.hpp"

void AppDelegate::setupGLView() {
	auto* director = CCDirector::sharedDirector();

	auto* glView = CCEGLView::createWithRect("Singularity!", CCRect(0, 0, 1280, 720), 1.0f);
	director->setOpenGLView(glView);

	director->setupScreenScale({480, 320}, {1280, 720}, TextureQuality::kTextureQualityHigh);
}

bool AppDelegate::applicationDidFinishLaunching() {
	auto* director = CCDirector::sharedDirector();
	director->setAlphaBlending(true);
	// doesnt work
	// director->setDisplayStats(true);

	// use gd resources
	CCFileUtils::sharedFileUtils()->addSearchPath("Resources");

	auto* scene = HelloWorld::scene();
	director->runWithScene(scene);

	return true;
}

void AppDelegate::applicationDidEnterBackground() {}

void AppDelegate::applicationWillEnterForeground() {}
