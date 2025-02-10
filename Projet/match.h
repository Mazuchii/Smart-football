#ifndef MATCH_H
#define MATCH_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Match;
}
QT_END_NAMESPACE

class Match : public QMainWindow
{
    Q_OBJECT

public:
    Match(QWidget *parent = nullptr);
    ~Match();

private:
    Ui::Match *ui;
};
#endif // MATCH_H
