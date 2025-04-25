#ifndef EXAMQUESTION_H
#define EXAMQUESTION_H

#include <QString>
#include <QStringList>

struct ExamQuestion {
    QString questionText;
    QStringList options;
    // Храним правильный ответ как текст
    QString correctAnswerText;
};

#endif // EXAMQUESTION_H
