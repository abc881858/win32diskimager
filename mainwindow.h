#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef WINVER
#define WINVER 0x0601
#endif

#include <QtWidgets>
#include <windows.h>
//#include <memory>
#include "ui_mainwindow.h"

class QClipboard;
class ElapsedTimer;

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT
public:
    static MainWindow* getInstance() {
        // !NOT thread safe  - first call from main only
        if (!instance)
            instance = new MainWindow();
        return instance;
    }

    ~MainWindow();
    void closeEvent(QCloseEvent *event);
    enum Status {STATUS_IDLE=0, STATUS_READING, STATUS_WRITING, STATUS_VERIFYING, STATUS_EXIT, STATUS_CANCELED};
    bool nativeEvent(const QByteArray &type, void *vMsg, long *result);
protected:
    MainWindow(QWidget* = NULL);
private:
    static MainWindow* instance;
    void getLogicalDrives();
    void setReadWriteButtonState();
    void saveSettings();
    void loadSettings();
    void initializeHomeDir();
    HANDLE hVolume;
    HANDLE hFile;
    HANDLE hRawDisk;
    static const unsigned short ONE_SEC_IN_MS = 1000;
    unsigned long long sectorsize;
    int status;
    char *sectorData;
    char *sectorData2; //for verify
    QTime update_timer;
    ElapsedTimer *elapsed_timer = NULL;
    QClipboard *clipboard;
    void generateHash(char *filename, int hashish);
    QString myHomeDir;
protected slots:
    void on_tbBrowse_clicked();
    void on_bCancel_clicked();
    void on_bWrite_clicked();
    void on_bRead_clicked();
    void on_bVerify_clicked();
    void on_leFile_editingFinished();
    void on_bHashCopy_clicked();
private slots:
    void on_bHashGen_clicked();
    void on_cboxHashType_currentIndexChanged(int);
    void updateHashControls();
    void on_bExit_clicked();
};

#endif // MAINWINDOW_H
