#ifndef APPLICATION_H
#define APPLICATION_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <string>

#include "parser.h"

class Application : public QGuiApplication
{
    Q_OBJECT

protected:

    QQmlApplicationEngine m_engine;
    
    Parser m_parser;

protected:

    void updateExpression(QString expression);

public:

    Application(int argc, char *argv[]);

public slots:

    void onOperationClicked(QString operation);
};

#endif // APPLICATION_H
