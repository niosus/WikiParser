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
    static MainWindow* getInstance()
    {
     if(!instance)
     {
       instance = new MainWindow();
     }
     return instance;
    }
    ~MainWindow();

public slots:
    void progressUpdated(const qreal &percent);
    void showError(const QString &errorMessage);

protected:
   MainWindow(QWidget* = nullptr);

private:
    static MainWindow* instance;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
