#ifndef ELAPSEDTIMER_H
#define ELAPSEDTIMER_H

#ifndef WINVER
#define WINVER 0x0601
#endif

#include <QtWidgets>
#include <QLabel>
#include <QTime>
#include <QString>

class ElapsedTimer : public QLabel
{
    Q_OBJECT

public:
    ElapsedTimer(QWidget *parent = 0);
    ~ElapsedTimer();
    int ms();
    void update(unsigned long long progress, unsigned long long total);
    void start();
    void stop();

private:
    struct timeStruct_t
    {
        unsigned short hour = 0;
        unsigned short min  = 0;
        unsigned short sec  = 0;
    };

    QTime *timer;
    void secsToHMS(unsigned int secs, timeStruct_t *ts);
    static const unsigned short MS_PER_SEC = 1000;
    static const unsigned short SECS_PER_MIN = 60;
    static const unsigned short MINS_PER_HOUR = 60;
    static const unsigned short SECS_PER_HOUR = (SECS_PER_MIN * MINS_PER_HOUR);
};

#endif // ELAPSEDTIMER_H
