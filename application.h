#ifndef APPLICATION_H
#define APPLICATION_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <string>

class Application : public QGuiApplication
{
    Q_OBJECT

protected:

    QQmlApplicationEngine m_engine;
    
    QString m_expression;
    QString m_last;

protected:

    void expressionChanged();

public:

    Application(int argc, char *argv[]);

public slots:

    void onOperationClicked(QString operation);
};

#endif // APPLICATION_H
