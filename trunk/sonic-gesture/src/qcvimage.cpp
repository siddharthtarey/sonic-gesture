
#include <QtGui/qwidget.h>

#include "qcvimage.h"
#include "source.h"
#include "tools.h"

QCVImage::QCVImage(QWidget *parent) : QWidget(parent) {
};

QCVImage::~QCVImage() {};

void QCVImage::setImage(Mat* bgr) {
    this->bgr = bgr;
    //this->resize(bgr->cols, bgr->rows);
    //this->setMinimumSize(bgr->cols, bgr->rows);
    //this->setMaximumSize(bgr->cols, bgr->rows);
    update();
}

void QCVImage::paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    qframe = mat2qimage(*bgr);
    //qframe = qframe.scaled(this->size(), Qt::KeepAspectRatio);
    int wskip = (this->width() - qframe.width())/2;
    int hskip = (this->height() - qframe.height())/2;
    painter.drawImage(QPoint(wskip, hskip),qframe);
};

