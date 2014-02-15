#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QGridLayout>
#include <QWebView>
#include <QLineEdit>
#include <QToolButton>
#include <QWidget>
#include <QTextStream>
#include <QSettings>
#include <QMenu>
class WebBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit WebBrowser(QWidget *parent = 0);
    void set_home_page(QString home){ homepage_=home;}

private:
    QWebView *web_;
    QLineEdit *address_;
    QToolButton *refresh_;
    QToolButton *back_;
    QToolButton *forward_;
    QToolButton *home_;
    QToolButton *marcador_;
    QGridLayout *layout_;
    QString homepage_;
private:
    void setupConnections();
signals:
    void s_marcador(QString);
public slots:
    void onLoad();
    void onHome();
    void onUrlChange(QUrl url);
    void guardar_marcador();
    void onLoadFinished(bool ok);
};

#endif // WEBBROWSER_H
