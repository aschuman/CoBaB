#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H
#include <QWidget>
#include <QVariant>

/**
 * @brief An abstract base class for widgets that can be handled by the Navigator.
 * @author Vincent Winkler
 */
class PageWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Resets this widget to its initial state.
     */
    virtual void reset() = 0;
    /**
     * @brief Retranslates the user interface after the user switched the language.
     */
    virtual void retranslateUi() = 0;
    /**
     * @brief Returns the name of the PageWidget
     * @return The name of the PageWidget
     */
    virtual QString getName() = 0;

signals:
    /**
     * @brief Emitted when this widget wants to push to the stack.
     * @param item Item to be pushed to the stack.
     */
    void pushToStack(QVariant item);

    /**
     * @brief Emitted when this widget wants to read from the stack.
     * @param index Position at which will be read (0 is referes to the top of the stack, -1 to the bottom).
     * @param value Valid QVariant which will be equipped with the appripriate stack item after return.
     */
    void readFromStack(int index, QVariant& value);

    /**
     * @brief Emtted when this widget wants to exit.
     * @param exitCode Code noting the type of exit.
     */
    void exit(int exitCode);

};

#endif // PAGEWIDGET_H
