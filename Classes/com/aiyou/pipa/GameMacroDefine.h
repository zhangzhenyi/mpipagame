//
//  GameMacroDefine.h
//  mpipagame
//
//  Created by 卢珺 on 14-5-20.
//
//

#ifndef mpipagame_GameMacroDefine_h
#define mpipagame_GameMacroDefine_h
//把位宏定义

#define BAWEI_0 0
#define BAWEI_1 1
#define BAWEI_2 2
#define BAWEI_3 3
#define BAWEI_4 4

enum Bawei {
    XiangBawei,
    FirstBawei,
    SecondBawei,
    ThirdBawei,
    FouthBawei
    
};
//弦位定义
#define XIAN_1 1
#define XIAN_2 2
#define XIAN_3 3
#define XIAN_4 4

enum XianIndex{
    FirstXian = 1,
    SecondXIian,
    ThirdXian,
    FouthXian
};

//指法表
#define SKILL_TAN "TAN"
#define SKILL_TIAO "TIAO"


//D调弦音位表 TODO, 弦，音调，品位，可以根据乐谱定义出弦位置
//#define

//定义声音文件名字，do、re、mi、fa、sol、la、si，音域29，基本音，泛音，轮指
#define ppSOL ""

#endif
