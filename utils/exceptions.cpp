#include "utils/exceptions.hpp"
#include <QTextStream>
#include <QIcon>

namespace jbrush {

// GENERAL EXCEPTION DEFS
GeneralException::GeneralException() {}
GeneralException::GeneralException(QString m) : message(m) {}
void GeneralException::raise() const
{
    throw *this;
}
GeneralException* GeneralException::clone() const
{
    return new GeneralException(*this);
}
QString GeneralException::errorMessage() const
{
    return message;
}
void GeneralException::errorWindow() const
{
    QMessageBox error(QMessageBox::Critical, "Error", message);
    error.setWindowIcon(QIcon(":/resources/icon.png"));
    error.exec();
}

// BAD FILE DEFS
BadFile::BadFile(QString m) : GeneralException(m) {}
BadFile::BadFile(const QFile& badFile)
{
    message = badFile.fileName() + " does not exist or is corrupted and cannot be used";
}

// BAD FILE FORMAT DEFS
BadFileFormat::BadFileFormat(QString m) : GeneralException(m) {}
BadFileFormat::BadFileFormat(const QFile& badFile)
{
    message = "File named " + badFile.fileName() + " has an invalid format and cannot be properly loaded";
}
BadFileFormat::BadFileFormat(QString expectedData, QString dataDiscovered)
{
    message = "File expected " + expectedData + "; got " + dataDiscovered;
}
BadFileFormat::BadFileFormat(const QFile& badFile, QString expectedData, QString dataDiscovered)
{
    message = "Error reading file named " + badFile.fileName() + ": expected " + expectedData + "; got " + dataDiscovered;
}

}
