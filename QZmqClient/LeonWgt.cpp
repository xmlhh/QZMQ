#include "LeonWgt.h"
#include "ui_LeonWgt.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

LeonWgt::LeonWgt(QWidget *parent) :
    LDrawWgt(parent),
    ui(new Ui::LeonWgt)
{
    InitUI();
}

LeonWgt::~LeonWgt()
{
    delete ui;
}


/**
* @author by LHH
* @brief 初始化界面
* @param 无
* @return void
*/
void LeonWgt::InitUI()
{
    //ui->setupUi(this);
    ui->setupUi(m_pCenterWidget);

    setWindowTitle("QZMQ客户端");
    resize(WIN_WIDTH, WIN_HEIGHT);

    // 可拖拽
    setDragable(true);
    // 不可最大化
    setMaxable(false);
    // 不可缩放
    setResizable(false);

    // 不显示选项按钮
    setShowMoreOptions(false);
    // 显示最小化按钮
    setShowMinBtn(true);
    // 不显示最大化按钮
    setShowMaxBtn(false);
}
