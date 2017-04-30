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
	if (operation == "C")
	{
		m_tokens.pop();
	}
	else if (operation == "AC")
	{
		m_tokens.clear();
		m_parser.clear();
	}		
	else if (operation == "=")
	{
		m_parser.evaluate(m_tokens);
	}
       
  else
  {
		m_tokens.append(operation.toUtf8().constData());

      if(operation == "root" || operation == "power")
				m_tokens.append("(");
  }

  updateExpression();
  updateAnswer();
}

void Application::updateExpression()
{
    QString expression = QString::fromStdString(m_tokens.expression());

    QObject *object = m_engine.rootObjects().value(1);
    QQmlProperty::write(object, "equation", expression);
}

void Application::updateAnswer()
{
    QString answer = QString::fromStdString(m_parser.answer());

    QObject *object = m_engine.rootObjects().value(1);
    QQmlProperty::write(object, "answer", answer);
}
