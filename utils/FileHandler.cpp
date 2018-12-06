#include "FileHandler.hpp"

namespace jbrush {

Vector<Shape*> FileHandler::loadShapesFromFile(const QString& directory)
{
    Vector<Shape*> shapesToReturn;  // Vector of shapes to be returned by the function

    // Throws: file didn't open
    try
    {
        // Get the file at the current directory
        // and make a text stream to operate on it
        QFile file(directory);
        QTextStream qin(&file);
        Shape *shapeExtracted;  // Shape extracted from the file

        if(!file.open(QIODevice::ReadOnly))
        {
           // If the file didn't open, throw an exception
           throw BadFile(file);
        }

        // Push each shape extracted back into the vector until we get to the end of the file
        while(!qin.atEnd())
        {
            // Extract shape throws if the shape could not be identified
            shapeExtracted = extractShape(qin);
            if(shapeExtracted != nullptr)
            {
                shapesToReturn.push_back(shapeExtracted);
            }
        }

        // Close the file when loading is finised
        file.close();
    }// end try
    catch (GeneralException& exception) {
        exception.errorWindow();

        // De allocate shapes and clear the vector
        for(auto shape : shapesToReturn)
        {
            delete shape;
        }
        shapesToReturn.clear();
    }

    return shapesToReturn;
}

Shape *FileHandler::extractShape(QTextStream& qin)
{
    QString shapeType;  // Name of the shape being extracted currently
    QList<int> dimensionsList;   // List of dimensions of the shape
    Shape *shape;    // Pointer to the shape that is returned by the function

    // Ignore the shape's ID data
    getTo(qin, jconstants::TITLE_INTERRUPTOR);

    // Get the name of the shape to add
    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    qin >> shapeType;

    // If we got to the end of the file, return a null pointer
    if(qin.atEnd())
    {
        return nullptr;
    }

    // Throw an exception if the shape type extracted is not in the list of valid shape types
    if(jconstants::TYPE_LIST.indexOf(shapeType) == -1)
    {
        QFile* file = dynamic_cast<QFile*>(qin.device());

        if(file != nullptr)
        {
            throw BadFileFormat(*file, "a valid shape type name", shapeType);
        }
        else
        {
            throw BadFileFormat("a valid shape type name", shapeType);
        }
    }

    // Extract the dimensions from the file
    dimensionsList = extractDimensions(qin, shapeType);

    // If the shape being read in isn't text...
    if(shapeType != jconstants::TEXT)
    {
        //...call corresponding extraction function
        shape = extractNonText(qin, shapeType, dimensionsList);
    }
    // Otherwise, if the shape is a text...
    else
    {
        //...call the corresponding extraction function
        shape = extractText(qin, dimensionsList);
    }

    return shape;
}

Shape *FileHandler::extractNonText(QTextStream& qin, QString& shapeType, QList<int>& dimensionsList)
{
    Shape* shape;    // Shape pointer to be returned by the function

    // Extract data for the pen that draws this shape' edges
    extractPen(qin);

    // If the shape being read in isn't a line, we know it needs a brush
    if(shapeType != jconstants::LINE && shapeType != jconstants::POLYLINE)
    {
        // Extract data for the brush used to fill the insides of this shape
        extractBrush(qin);
        shape = constructShape(shapeType, dimensionsList);
    }
    else
    {
        shape = constructLine(shapeType, dimensionsList);
    }

    return shape;
}

Shape *FileHandler::extractText(QTextStream& qin, QList<int>& dimensionsList)
{
    QString body;   // Body of the text
    QFont font; // Font of the text

    // Get to the next whitspace, then read in the line as the text's body
    jbrush::getTo(qin, jconstants::TITLE_INTERRUPTOR);
    body = qin.readLine().trimmed();

    // For now, ignore the shape color and shape alignment
    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    getTo(qin, jconstants::TITLE_INTERRUPTOR);

    // Extract the text's font
    font = extractFont(qin);

    return new Text(QPoint(dimensionsList[0], dimensionsList[1]), dimensionsList[2], dimensionsList[3], body);
}

QList<int> FileHandler::extractDimensions(QTextStream& qin, const QString& shapeType)
{
    QList<int> dimensionsList;
    QChar buffer;   // Used to track where the text stream is in the file
    int dimension;  // Used to store the current dimension being read in

    // Get to next whitespace after leading title
    getTo(qin, jconstants::TITLE_INTERRUPTOR);

    // Continue reading in integers until one is found that is not followed by the designated dimension interruptor
    do
    {
        qin >> dimension;
        dimensionsList.append(dimension);
        qin >> buffer;
    }while(buffer == jconstants::DIMENSION_INTERRUPTOR && !qin.atEnd());

    // Check the dimensions list and throw an exception if there is an error
    checkDimensions(qin, shapeType, dimensionsList.size());

    return dimensionsList;
}

// MODIFICATION PENDING IN FUTURE PRODUCT UPGRADES
QPen FileHandler::extractPen(QTextStream& qin)
{
    QPen pen;
    QString buffer;

    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    getTo(qin, jconstants::TITLE_INTERRUPTOR);

    return pen;
}
// MODIFICATION PENDING IN FUTURE PRODUCT UPGRADES
QBrush FileHandler::extractBrush(QTextStream& qin)
{
    QBrush brush;
    QString buffer;

    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    getTo(qin, jconstants::TITLE_INTERRUPTOR);

    return brush;
}

QFont FileHandler::extractFont(QTextStream& qin)
{
    QFont font;
    int pointSize; // Temporary storage for an integer
    QString stringExtracted; // Temporary storage for a string

    // Get text size
    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    qin >> pointSize;
    font.setPointSize(pointSize);

    // Get font family
    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    stringExtracted = qin.readLine().trimmed();
    font.setFamily(stringExtracted);

    // Get font style
    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    qin >> stringExtracted;
    font.setStyle(jconstants::TEXT_STYLE_MAP[stringExtracted]);

    // Get font weight
    getTo(qin, jconstants::TITLE_INTERRUPTOR);
    qin >> stringExtracted;
    font.setWeight(jconstants::TEXT_WEIGHT_MAP[stringExtracted]);

    return font;
}

Shape *FileHandler::constructLine(QString& type, QList<int>& dimensions)
{
    if(type == jconstants::LINE)
    {
       return new Line(QPoint(dimensions[0], dimensions[1]), QPoint(dimensions[2], dimensions[3]));
    }
    else
    {
        return new Polyline(getPoints(dimensions), uint32_t(dimensions.size() / 2));
    }
}

Shape *FileHandler::constructShape(QString& type, QList<int>& dimensions)
{
    if(type == jconstants::POLYGON)
    {
        return new Polygon(getPoints(dimensions), uint32_t(dimensions.size() / 2));
    }
    else if(type == jconstants::RECTANGLE)
    {
        return new Rectangle(QPoint(dimensions[0], dimensions[1]), dimensions[2], dimensions[3]);
    }
    else if(type == jconstants::SQUARE)
    {
        return new Rectangle(QPoint(dimensions[0], dimensions[1]), dimensions[2], dimensions[2]);
    }
    else if(type == jconstants::ELLIPSE)
    {
        return new Ellipse(QPoint(dimensions[0], dimensions[1]), dimensions[2], dimensions[3]);
    }
    else
    {
        return new Circle(QPoint(dimensions[0], dimensions[1]), dimensions[2]);
    }
}

QPoint *FileHandler::getPoints(QList<int>& dimensions)
{
    // Create a block of qpoints that is half the size of the dimensions integers
    int totalPoints = dimensions.size() / 2;
    QPoint* pArray = new QPoint[totalPoints];

    // Loop through each point and initialize it using the two integers in the list
    for(int point = 0; point < totalPoints; ++point)
    {
        pArray[point] = QPoint(dimensions[point * 2], dimensions[(point * 2) + 1]);
    }

    return pArray;
}

void FileHandler::checkDimensions(const QTextStream& qin, const QString& shapeType, uint32_t numDimensions)
{
    QFile* file;
    uint32_t expectedDimensionsSize;

    // Try to get the file back from the text stream device
    file = dynamic_cast<QFile*>(qin.device());

    // Check to make sure the expected number of dimensions were extracted
    if(shapeType != jconstants::POLYLINE && shapeType != jconstants::POLYGON)
    {
        expectedDimensionsSize = jconstants::DIMENSION_COUNT_MAP[shapeType];

        if(numDimensions != expectedDimensionsSize)
        {
            if(file != nullptr)
            {
                throw BadFileFormat(*file, QString::number(expectedDimensionsSize) + " dimensions", QString::number(numDimensions) + " dimensions");
            }
            else
            {
                throw BadFileFormat(QString::number(expectedDimensionsSize) + " dimensions", QString::number(numDimensions) + " dimensions");
            }
        }
    }
    else if(numDimensions < 4)
    {
        if(file != nullptr)
        {
            throw BadFileFormat(*file, "at least " + QString::number(4) + " dimensions", QString::number(numDimensions) + " dimensions");
        }
        else
        {
            throw BadFileFormat("at least " + QString::number(4) + " dimensions", QString::number(numDimensions) + " dimensions");
        }
    }
}
}

