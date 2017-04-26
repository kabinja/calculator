#include "application.h"

Application::Application(int argc, char *argv[])
    : QGuiApplication(argc, argv)
{
   m_engine.load(QUrl(QLatin1String("qrc:/OperationButton.qml")));
   m_engine.load(QUrl(QLatin1String("qrc:/main.qml")));

   QObject *object = m_engine.rootObjects().value(1);

   connect(object, SIGNAL(operatorClicked(QString)), this, SLOT(onOperationClicked(QString)));
}

void Application::onOperationClicked(QString operation)
{
    if(operation == "C")
        m_parser.removeToken();
    else if(operation == "AC")
        m_parser.clearExpression();
    else if(operation == "=")
        m_parser.evaluate();
    else
    {
       m_parser.addToken(operation.toUtf8().constData());

       if(operation == "root" || operation == "power")
         m_parser.addToken("(");
    }

    updateExpression();
    updateAnswer();
}

void Application::updateExpression()
{
    QString expression = QString::fromStdString(m_parser.expression());

    QObject *object = m_engine.rootObjects().value(1);
    QQmlProperty::write(object, "equation", expression);
}

void Application::updateAnswer()
{
    QString answer = QString::fromStdString(m_parser.answer());

    QObject *object = m_engine.rootObjects().value(1);
    QQmlProperty::write(object, "answer", answer);
}
