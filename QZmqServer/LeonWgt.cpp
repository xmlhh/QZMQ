#include "LeonWgt.h"
#include "ui_LeonWgt.h"
#include <QDebug>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

LeonWgt::LeonWgt(QWidget *parent) :
    LDrawWgt(parent),
    m_bStartFlag(false),
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

    setWindowTitle("QZMQ服务端");
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

    // 信号的连接
    SignalConnects();
}


/**
* @author by LHH
* @brief 控件信号的连接
* @param 无
* @return void
*/
void LeonWgt::SignalConnects()
{
    QObject::connect(ui->m_pStartBtn, SIGNAL(clicked()), this, SLOT(OnStartBtn()));
}


/**
* @author by LHH
* @brief 启动
* @param 无
* @return void
*/
void LeonWgt::OnStartBtn()
{
    if (!m_bStartFlag)
    {
        ui->m_pStartBtn->setText("停止");
    }
    else
    {
        ui->m_pStartBtn->setText("启动");
    }

    m_bStartFlag = !m_bStartFlag;
}
