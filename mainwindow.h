#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool validate_icao(QString icao);
    QString get_metar(QString icao);
    static size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data);

private slots:
    void on_btnBuscar_clicked();
};

#endif // MAINWINDOW_H
