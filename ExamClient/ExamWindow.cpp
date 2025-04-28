#include "ExamWindow.h"
#include "ui_ExamWindow.h"
#include <QRadioButton>
#include <QMessageBox>

ExamWindow::ExamWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExamWindow)
    , m_currentIndex(0)
    , m_score(0)
{
    ui->setupUi(this);
}

ExamWindow::~ExamWindow()
{
    delete ui;
}

void ExamWindow::setExamQuestions(int examId, const QVector<ExamQuestion> &questions)
{
    qDebug() << "Received" << questions.size() << "questions.";

    m_examId = examId;
    const int maxReasonableQuestions = 1000;
    if (questions.size() > maxReasonableQuestions) {
        ui->TextLabel->setText("Ошибка: получено слишком много вопросов.");
        ui->pushButton->setEnabled(false);
        return;
    }

    m_questions = questions;
    m_currentIndex = 0;
    m_score = 0;
    m_userAnswers.clear();
    m_userAnswers.resize(m_questions.size());

    if (!m_questions.isEmpty()) {
        displayCurrentQuestion();
        ui->pushButton->setEnabled(true);
    } else {
        ui->TextLabel->setText("Нет вопросов для этого экзамена.");
        ui->pushButton->setEnabled(false);
    }
}


void ExamWindow::displayCurrentQuestion()
{
    if (m_currentIndex < 0 || m_currentIndex >= m_questions.size()) {
        return;
    }

    const ExamQuestion &q = m_questions[m_currentIndex];

    ui->TextLabel->setText(q.questionText);

    QList<QRadioButton*> radios = {
        ui->radioButton,
        ui->radioButton_2,
        ui->radioButton_3,
        ui->radioButton_4
    };

    for (QRadioButton *rb : radios) {
        rb->setAutoExclusive(false);
        rb->setChecked(false);
        rb->setAutoExclusive(true);
        rb->show();
    }

    for (int i = 0; i < radios.size(); ++i) {
        if (i < q.options.size()) {
            radios[i]->setText(q.options[i]);
            radios[i]->show();
        } else {
            radios[i]->hide();
        }
    }
}

void ExamWindow::on_pushButton_clicked()
{
    if (m_currentIndex < 0 || m_currentIndex >= m_questions.size()) {
        return;
    }

    QList<QRadioButton*> radios = {
        ui->radioButton,
        ui->radioButton_2,
        ui->radioButton_3,
        ui->radioButton_4
    };

    int selectedIndex = -1;
    for (int i = 0; i < radios.size(); ++i) {
        if (radios[i]->isChecked()) {
            selectedIndex = i;
            break;
        }
    }

    if (selectedIndex == -1) {
        QMessageBox::warning(this, "Внимание", "Выберите ответ, прежде чем продолжить.");
        return;
    }

    m_userAnswers[m_currentIndex] = selectedIndex;

    const ExamQuestion &currentQuestion = m_questions[m_currentIndex];
    QString selectedAnswer = currentQuestion.options.at(selectedIndex);
    if (selectedAnswer == currentQuestion.correctAnswerText) {
        m_score++;
    }

    m_currentIndex++;
    if (m_currentIndex < m_questions.size()) {
        displayCurrentQuestion();
    } else {
        ui->pushButton->setEnabled(false);

        QVector<QString> userAnswersText;
        for (int i = 0; i < m_questions.size(); ++i) {
            int idx = m_userAnswers[i];
            if (idx >= 0 && idx < m_questions[i].options.size()) {
                userAnswersText.append(m_questions[i].options[idx]);
            } else {
                userAnswersText.append("Не выбран");
            }
        }
        emit examFinished(m_examId, m_score, m_questions, userAnswersText);
    }
}

