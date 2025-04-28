#ifndef EXAMQUESTION_H
#define EXAMQUESTION_H

#include <QString>
#include <QStringList>

struct ExamQuestion {
    QString questionText;
    QStringList options;
    QString correctAnswerText;
};

#endif
