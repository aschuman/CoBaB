#include "greeting.h"

Greeting::Greeting(QString subject) : mSubject(subject)
{

}


QString Greeting::get() const
{
    return "Hello " + mSubject + "!";
}
