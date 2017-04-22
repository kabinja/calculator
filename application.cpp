#include "application.h"

#include <QQuickView>
#include <QQuickItem>
#include <QQmlComponent>
#include <QQmlProperty>

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
    m_last = operation;
    
    m_expression += operation;
    expressionChanged();
}

void Application::expressionChanged()
{
    QObject *object = m_engine.rootObjects().value(1);
    QQmlProperty::write(object, "equation", m_expression);
}
