#ifndef APPLICATION_H
#define APPLICATION_H

#include "parser.h"

class Application : public QGuiApplication
{
    Q_OBJECT

protected:

    QQmlApplicationEngine m_engine;
    
    Parser m_parser;

protected:

    void updateExpression();
    void updateAnswer();

public:

    Application(int argc, char *argv[]);

public slots:

    void onOperationClicked(QString operation);
};

#endif // APPLICATION_H
