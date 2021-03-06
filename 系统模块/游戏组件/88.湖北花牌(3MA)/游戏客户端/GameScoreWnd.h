#include "Stdafx.h"
#include "Resource.h"

#pragma once

#include "Stdafx.h"
#include "Resource.h"

//////////////////////////////////////////////////////////////////////////
//结构定义

//积分信息
struct tagGameScoreInfo
{
	BYTE				cbChiHuCard;			            //吃胡扑克
	BYTE				cbGoldCard;				            //主精牌

	WORD				wBankerUser;						//庄家用户
	WORD				wProvideUser;						//点炮用户
	BYTE				wWinner;	  						//赢家

	LONG				lScore[GAME_PLAYER];				//用户积分
	TCHAR				szUserName[GAME_PLAYER][NAME_LEN];	//用户帐号
	tagHuCardWeave		HuCardWeave;						//胡牌组合



	LONG				lHuPoint; 						//基础分
};

//////////////////////////////////////////////////////////////////////////

//积分报告
class CGameScoreWnd : public CWnd
{
	//变量定义
protected:
	CSkinImage				m_ImageBack;				//背景资源
	tagGameScoreInfo		m_GameScoreInfo;			//积分信息
	LONG					m_lTax;						//游戏税收

	//函数定义
public:
	//构造函数
	CGameScoreWnd();
	//析构函数
	virtual ~CGameScoreWnd();

	//功能函数
public:
	//设置积分
	void SetScoreInfo(tagGameScoreInfo &GameScoreInfo);
	//设置税收
	void SetTax(LONG lTax);

	//消息映射
protected:
	//重画函数
	afx_msg void OnPaint();
	//绘画背景
	afx_msg BOOL OnEraseBkgnd(CDC * pDC);
	//建立函数
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//鼠标消息
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////
