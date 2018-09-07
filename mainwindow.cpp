#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <curl/curl.h>
#include <string>
#include "metarretriever.h"
#include "metardecoder.h"
#include "metar.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBuscar_clicked()
{
    QString icao = ui->icao->text();

    if(validate_icao(icao)) {
        MetarRetriever * metarRetriever = new MetarRetriever();
        std::string metar = metarRetriever->get_metar(icao.toStdString());

        MetarDecoder *decoder = new MetarDecoder();
        decoder->decode(metar);

        ui->textMetar->setText(QString::fromStdString(metar));
    } else {
        QMessageBox message;
        message.setText("Invalid ICAO code");
        message.exec();
    }
}

bool MainWindow::validate_icao(QString icao) {
    return icao.length() == 4;
}
