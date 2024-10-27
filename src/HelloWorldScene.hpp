#pragma once

#include <cocos2d.h>

using namespace cocos2d;

class HelloWorld : public CCLayer {
	CCLabelBMFont* m_fpsLabel;
public:
	bool init() override;

	static CCScene* scene();

	void update(float) override;

	CREATE_FUNC(HelloWorld);
};
