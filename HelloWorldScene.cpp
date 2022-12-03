/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "Box2D/Box2D.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

using namespace ui;
using namespace CocosDenshion;

String narasi = __String::create("Permission is hereby granted, free of charge, to any person obtaining")->getCString();
String narasi2 = __String::create("Permission is hereby granted, free of charge, to any person obtaining")->getCString();
int y = 0;
void HelloWorld::listener_text()
{
    if (y != 10 && y != 13 && y != 20 && y != 29 && y != 34 && y != 37 && y != 45 && y != 48 && y != 52 && y != 59)
    {
        text->getLetter(y)->setOpacity(255);
    }

    y++;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto text2 = Label::createWithTTF(__String::create(narasi2.getCString())->getCString(),
        "fonts/arial.ttf", 20);
    text2->setTextColor(Color4B::RED);
    text2->setAnchorPoint(Point(0, 0.5));
    text2->setPosition(Vec2(visibleSize.width / 2 + origin.x - 400, visibleSize.height / 2 + origin.y));
    this->addChild(text2);

    text = Label::createWithTTF(__String::create(narasi.getCString())->getCString(),
        "fonts/arial.ttf", 20);
    text->setTextColor(Color4B::WHITE);
    text->setAnchorPoint(Point(0, 0.5));
    text->setPosition(Vec2(visibleSize.width / 2 + origin.x- 400, visibleSize.height / 2 + origin.y));
    this->addChild(text);
    text->setAlignment(TextHAlignment::RIGHT);
    text->setOpacity(0);
    runAction(Repeat::create(Sequence::create(CallFunc::create(CC_CALLBACK_0(HelloWorld::listener_text, this)),
        DelayTime::create(0.10), NULL), narasi.length()));



    

    return true;
}
