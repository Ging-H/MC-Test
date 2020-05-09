#include "curve.h"
#include "ui_curve.h"
#include "qcustomplot.h"


Curve::Curve(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Curve)
{
    ui->setupUi(this);
    this->setWindowTitle("硬石电子-FOC5.4.3测试工具-参数曲线");

    this->initCurve();
    this->addSpeedGraph();
    this->addPosGraph();
}

Curve::~Curve()
{
    delete ui;
}

/*-------------------------------------*/
// ui相关配置

/**
 * @brief Curve::initCurve 初始化绘图配置
 */
void Curve::initCurve()
{
    // set some pens, brushes and backgrounds:
    /* 坐标轴 */
    ui->plot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->plot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->plot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->plot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->plot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->plot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->plot->xAxis->setTickLabelColor(Qt::white);
    ui->plot->yAxis->setTickLabelColor(Qt::white);
    ui->plot->yAxis->setLabel( "速度值(RPM)" );
    ui->plot->yAxis->setLabelColor( Qt::white );

    /* 第二Y轴 */
    ui->plot->yAxis2->setBasePen(QPen(Qt::white, 1));
    ui->plot->yAxis2->setTickPen(QPen(Qt::white, 1));
    ui->plot->yAxis2->setSubTickPen(QPen(Qt::white, 1));
    ui->plot->yAxis2->setTickLabelColor(Qt::white);
    ui->plot->yAxis2->setVisible(true);
    ui->plot->yAxis2->setTickLabels(true);
    ui->plot->yAxis2->setLabel( "位置值(r)" );
    ui->plot->yAxis2->setLabelColor( Qt::white );

    /* 栅格 */
    ui->plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->plot->xAxis->grid()->setSubGridVisible(true);
    ui->plot->yAxis->grid()->setSubGridVisible(true);
    ui->plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->plot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->plot->axisRect()->setBackground(axisRectGradient);

    /* 坐标轴范围，原点位于中心 */
    ui->plot->xAxis->setRange(0, 10, Qt::AlignCenter);
    ui->plot->yAxis->setRange(0, 10, Qt::AlignCenter);

    ui->plot->xAxis2->setRange(0, 10, Qt::AlignCenter);
    ui->plot->yAxis2->setRange(0, 10, Qt::AlignCenter);

    //设定右上角图形标注和字体
    ui->plot->legend->setBorderPen(QPen(QColor(140, 140, 140,0)));// legend 边框颜色透明
    ui->plot->legend->setTextColor(QColor(255,255,255,150)); // legend 字体颜色,白色
    ui->plot->legend->setBrush(QColor(74,74,74,0));   //legend背景色设为灰色但背景透明，允许图像在legend区域可见
    ui->plot->legend->setWrap(20); // 超过20行就换一列
    ui->plot->legend->setVisible(true);

    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    QList<QCPAxis*> axes;
    axes << ui->plot->xAxis << ui->plot->yAxis << ui->plot->xAxis2 << ui->plot->yAxis2;

    ui->plot->axisRect()->setRangeDragAxes( axes );
    ui->plot->axisRect()->setRangeZoomAxes( axes );
}

/**
 * @brief Curve::addNewGraph 添加一条新的速度曲线
 */
void Curve::addSpeedGraph()
{
    ui->plot->addGraph(ui->plot->xAxis, ui->plot->yAxis);
    indexOfSpd = ui->plot->graphCount()-1;// 当前曲线的索引号
    QCPGraph *speedGraph = ui->plot->graph(indexOfSpd);

    QPen pen;           // 画笔,绘制曲线颜色,形状等
    pen.setWidth(1);    //线宽
    pen.setStyle(Qt::SolidLine);// 线型
    pen.setColor(QColor("#FB0803"));      // 曲线颜色
    speedGraph->setPen(pen);  // line color blue for first graph
    speedGraph->setName(tr("速度"));  // 速度值
    speedGraph->setSelectable(QCP::stSingleData);
    speedGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 5));
}

/**
 * @brief Curve::addPosGraph 添加一条新的位置曲线
 */
void Curve::addPosGraph()
{
    ui->plot->addGraph(ui->plot->xAxis, ui->plot->yAxis2 );
    indexOfPos = ui->plot->graphCount()-1;// 当前曲线的索引号
    QCPGraph *posGraph = ui->plot->graph(indexOfPos);

    QPen pen;           // 画笔,绘制曲线颜色,形状等
    pen.setWidth(1);    //线宽
    pen.setStyle( Qt::SolidLine );          // 线型
    pen.setColor( QColor("#08FB73") );      // 曲线颜色
    posGraph->setPen(pen);                  // line color blue for first graph
    posGraph->setName( tr("位置") );         // 位置值
    posGraph->setSelectable(QCP::stSingleData);
    posGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::yellow), 5));
}

/**
 * @brief Curve::resetAxisRange 调整速度坐标轴范围
 * @param x       当前x 值
 * @param y       当前y 值
 */
void Curve::resetSpdAxisRange(quint32 xValue, qint32 yValue)
{
    QCPRange xRange = ui->plot->xAxis->range();
    QCPRange yRange = ui->plot->yAxis->range();
    if( xValue > xRange.upper ){
        ui->plot->xAxis->setRange(xValue-10, 50, Qt::AlignLeft );
    }
    if( yValue > yRange.upper ){
        ui->plot->yAxis->setRange(yValue-10, 290, Qt::AlignLeft );
    }else if( yValue < yRange.lower){
        ui->plot->yAxis->setRange(yValue+10, 290, Qt::AlignRight );
    }
}

/**
 * @brief Curve::resetPosAxisRange 调整位置曲线的坐标轴范围
 * @param x
 * @param y
 */
void Curve::resetPosAxisRange(float yValue)
{
    QCPRange yRange = ui->plot->yAxis2->range();
    if( yValue > yRange.upper ){
        ui->plot->yAxis2->setRange(yValue-10, 90, Qt::AlignLeft );
    }else if( yValue < yRange.lower){
        ui->plot->yAxis2->setRange(yValue+10, 90, Qt::AlignRight );
    }
}

/**
 * @brief Curve::slots_updateSpeedGraph 更新速度曲线
 * @param spd  速度值 RPM
 */
void Curve::slots_updateSpeedGraph(qint32 spd)
{
    if( ui->actionPause->isChecked() )
        return ;
    QCPGraph *speedGraph = ui->plot->graph( indexOfSpd );
    speedGraph->addData(spdCoorX++, spd);
    this->resetSpdAxisRange( spdCoorX, spd ); // 调整坐标轴
    ui->plot->replot(QCustomPlot::rpQueuedReplot);// 重绘曲线图像
}

/**
 * @brief Curve::slots_updatePositionGraph 更新位置值
 * @param pos 位置值 r
 */
void Curve::slots_updatePositionGraph(float pos)
{
    if( ui->actionPause->isChecked() )
        return ;
    QCPGraph *posGraph = ui->plot->graph(indexOfPos);
    posGraph->addData(posCoorX++, pos);
    this->resetPosAxisRange( pos );      // 调整坐标轴
    ui->plot->replot(QCustomPlot::rpQueuedReplot);// 重绘曲线图像
}

/**
 * @brief Curve::on_actionClear_triggered 工具栏 清空数据
 */
void Curve::on_actionClear_triggered()
{
    ui->plot->graph(indexOfSpd)->data().data()->clear();
    ui->plot->graph(indexOfPos)->data().data()->clear();\
    spdCoorX = 0;
    posCoorX = 0;
    /* 坐标轴范围，原点位于中心 */
    ui->plot->xAxis->setRange(0, 10, Qt::AlignCenter);
    ui->plot->yAxis->setRange(0, 10, Qt::AlignCenter);

    ui->plot->xAxis2->setRange(0, 10, Qt::AlignCenter);
    ui->plot->yAxis2->setRange(0, 10, Qt::AlignCenter);
    ui->plot->replot(QCustomPlot::rpQueuedReplot);// 重绘曲线图像
}

/**
 * @brief Curve::on_actionZoom_triggered  工具栏 选择放大
 * @param checked
 */
void Curve::on_actionZoom_triggered(bool checked)
{
    if(checked){
        ui->plot->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);
    }else{
        ui->plot->setSelectionRectMode(QCP::SelectionRectMode::srmNone);
    }
}

/**
 * @brief Curve::on_actionSaveImg_triggered 工具栏 保存图像
 */
void Curve::on_actionSaveImg_triggered()
{
    QFileDialog *fileDialog = this->initSaveFileDialog();

    QString fileName = nullptr;
    QString fileType = nullptr;

    if(fileDialog->exec() == QDialog::Accepted) {
        fileName = fileDialog->selectedFiles()[0]; // fileName不包含文件类型 (.xxx)
        fileType = fileDialog->selectedNameFilter();

        QRegExp reg("(\\.).*(\\))", Qt::CaseInsensitive);// 匹配 .xxx)
        reg.indexIn(fileType);// 搜索文件类型
        fileType = reg.cap(0);
        fileType.chop(1);
        fileName += fileType; // 拼接文件名和文件类型
    }
    QFileInfo file(fileName);
    if(file.path() != "/")
    {
        qint32 count = fileDialog->layout()->count();
        QWidget *pWidget = fileDialog->layout()->itemAt(count-1)->widget();// 获取layout最后一个Widget的指针
        count = pWidget->children().count();
        QDoubleSpinBox *pScale = (QDoubleSpinBox *)pWidget->children().at(count-1);// 获取pWidget的子widget
        QSpinBox *pHeight = (QSpinBox *)pWidget->children().at(count-3);
        QSpinBox *pWidth  = (QSpinBox *)pWidget->children().at(count-5);
        qint32 width      = pWidth->value();
        qint32 height     = pHeight->value();
        double scale      = pScale->value();

        bool success = false;

        if(fileName.endsWith(".png")){
            success = ui->plot->savePng(fileName, width, height, scale, 100, 100);
        }else if(fileName.endsWith(".jpg")){
            success = ui->plot->saveJpg(fileName,width, height, scale,100,100);
        }else if(fileName.endsWith(".bmp")){
            success = ui->plot->saveBmp(fileName,width, height, scale,100);
        }else if(fileName.endsWith(".pdf")){
            success = ui->plot->savePdf(fileName,width, height, QCP::epAllowCosmetic,"ing10 SerialData","Curve");
        }

        if(success){
            QDesktopServices::openUrl(QUrl::fromLocalFile(file.path()));
        }else{
            QMessageBox::information(NULL, tr("SaveFiles"), tr("保存失败"));
        }

    }else{
        QMessageBox::information(NULL, tr("SaveFiles"), tr("请选择正确的路径"));
    }
    delete fileDialog;
}
/**
 * @brief Curve::initSaveFileDialog 自定义文件保存对话框
 * @return
 */
QFileDialog *Curve::initSaveFileDialog()
{
    QFileDialog *fileDialog = new QFileDialog();
    fileDialog->setOption(QFileDialog::DontUseNativeDialog, true); // 不使用本地的文件对话框

    QLabel *lblWidth = new QLabel("Width",fileDialog);  // 宽度
    QSpinBox *spbWidth = new QSpinBox(fileDialog);
    spbWidth->setMinimum(10);
    spbWidth->setMaximum(16777215);
    spbWidth->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spbWidth->setValue(ui->plot->width());

    QLabel *lblHeight = new QLabel("Height",fileDialog);// 高度
    QSpinBox *spbHeight  = new QSpinBox(fileDialog);
    spbHeight->setMinimum(10);
    spbHeight->setMaximum(16777215);
    spbHeight->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spbHeight->setValue(ui->plot->height());

    QLabel *lblScale = new QLabel("Scale",fileDialog);  // 缩放比例
    QDoubleSpinBox *spbScale  = new QDoubleSpinBox(fileDialog);
    spbScale->setMinimum(0);
    spbScale->setMaximum(16777215);
    spbScale->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spbScale->setValue(1);

    QHBoxLayout *hlayout = new QHBoxLayout(); // 新建布局图层
    hlayout->addWidget(lblWidth);             // 添加Widget
    hlayout->addWidget(spbWidth);
    hlayout->addWidget(lblHeight);
    hlayout->addWidget(spbHeight);
    hlayout->addWidget(lblScale);
    hlayout->addWidget(spbScale);
    hlayout->setSpacing(3);// 间隔为0

    QWidget *pWidget = new QWidget(fileDialog);
    QLabel *lblImagesSize = new QLabel("ImagesSize:",fileDialog); // 图像大小
    fileDialog->layout()->addWidget(lblImagesSize);// 添加Widget,整体添加两个Widget, pWidget另外包含4个Widget
    fileDialog->layout()->addWidget(pWidget);      //
    pWidget->setLayout(hlayout);

    fileDialog->setWindowTitle(tr("保存图像"));           // 对话框标题
    fileDialog->setAcceptMode(QFileDialog::AcceptSave); // 保存模式
    fileDialog->setViewMode(QFileDialog::List);         // 列表显示
    fileDialog->setLabelText(QFileDialog::Accept,"保存");// 按钮文本
    fileDialog->setLabelText(QFileDialog::Reject,"取消");

    fileDialog->setDirectory(".");
    QString filters="png(*.png);;jpg(*.jpg);;bmp(*.bmp);;pdf(*.pdf)";// 过滤类型
    fileDialog->setNameFilter(filters);
    fileDialog->setDirectory(qApp->applicationDirPath());// 默认路径
    return fileDialog;
}
