#pragma once

#include <QFile>
#include <QException>
#include <QMessageBox>

namespace jbrush
{
// Inherits from QException and allows the client to specify a unique string message that
// is displayed in Qt's debugging console when raised
class GeneralException : public QException
{
protected:
    QString message;
public:
    GeneralException();
    GeneralException(QString);
    void raise() const override;
    GeneralException* clone() const override;

    // Return the error message assigned to this exception
    QString errorMessage () const;

    // Causes a message box to appear describing the error that occurred
    // Good for informing the user of errors they need to be aware of
    void errorWindow () const;
};

// Throw this exception if a file was not opened properly
class BadFile : public GeneralException
{
public:
    BadFile(QString message);
    BadFile(const QFile& badFile);
};
// Throw this exception if the file attempted to open did not have the correct format
class BadFileFormat : public GeneralException
{
public:
    BadFileFormat(QString message);
    BadFileFormat(const QFile& badFile);
    BadFileFormat(QString expected, QString got);
    BadFileFormat(const QFile& badFile, QString expected, QString got);
};
}

