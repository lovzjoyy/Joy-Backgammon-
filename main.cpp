#include "mainwidget.h"
#include <QApplication>
#include "chessdemo.h"
#include "mainwidget.h"

#include <QApplication>
#include <QCoreApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QDir>

#pragma execution_character_set("utf-8")
// 创建json文件
void CreateMyJson()
{
    QFile file(QDir::currentPath() + "/chess.json");

    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "File open error";
    }

    // 清空文件中的原有内容
    file.resize(0);

    // 添加学校信息
    QJsonObject jsonObject;
    jsonObject.insert("x","1");
    jsonObject.insert("y", "2");
    jsonObject.insert("type", "white");

    //构建了一个对象
//    {
//        "School"："北京一中"
//    }

    // 使用QJsonArray添加学生信息
//    QJsonArray personArray;
//    for(int i = 0; i < 3; i++)
//    {
//        QJsonObject personObject;
//        personObject.insert("Id", QString::number(i+1));
//        personObject.insert("age", "18");
//        personObject.insert("ontime", true);
//        personObject.insert("time", QDateTime::currentDateTime().toString());
//        personArray.append(personObject);
//    }


//    QJsonArray colorAry;
//    colorAry.append(0.8);
//    colorAry.append(1.0);
//    colorAry.append(0.0);

//    // 使用QJsonObject对象插入键值对。
//    QJsonObject jsonObject;
//    jsonObject.insert("Address", "北京");
//    jsonObject.insert("Type", "学校");
//    jsonObject.insert("Data", 1998);
//    jsonObject.insert("Info", QJsonValue(schoolObject));
//    jsonObject.insert("Color", QJsonValue(colorAry));
//    jsonObject.insert("Students", QJsonValue(personArray));

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObject);
    qDebug()<<jsonDoc.toJson();  //转json串口
    file.write(jsonDoc.toJson());//写文件
    file.close();
}

// 解析json文件
void ParseMyJson()
{
    QFile jsonFile(QDir::currentPath() + "/chess.json");

    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "could't open projects json";
        return;
    }

    QByteArray byteArray = jsonFile.readAll();
    jsonFile.close();

    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(byteArray, &jsonError);  // 转化为 JSON 文档
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
    {
        // 解析未发生错误
        if (doucment.isObject())
        {
            // JSON 文档为对象
            QJsonObject object = doucment.object();  // 转化为对象
            if (object.contains("x"))
            {
                QJsonValue value = object.value("x");
                if (value.isString())
                {
                    QString strAddress = value.toString();
                    qDebug() << "x : " << strAddress;
                }
            }
            if (object.contains("type"))
            {
                QJsonValue value = object.value("type");
                if (value.isString())
                {
                    QString strAddress = value.toString();
                    qDebug() << "type : " << strAddress;
                }
            }
            if (object.contains("y"))
            {
                QJsonValue value = object.value("y");
                if (value.isString())
                {
                    QString strAddress = value.toString();
                    qDebug() << "y : " << strAddress;
                }
            }

            if (object.contains("Type"))
            {
                QJsonValue value = object.value("Type");
                if (value.isString())
                {
                    QString strType = value.toString();
                    qDebug() << "Type : " << strType;
                }
            }

            if (object.contains("Data"))
            {
                QJsonValue value = object.value("Data");
                if (value.isDouble())
                {
                    int nData = value.toVariant().toInt();
                    qDebug() << "Data : " << nData;
                }
            }

            if (object.contains("Color"))
            {
                QJsonValue value = object.value("Color");
                if (value.isArray())
                {
                    QJsonArray array = value.toArray();
                    int nSize = array.size();
                    for (int i = 0; i < nSize; ++i)
                    {
                        QJsonValue value = array.at(i);
                        if (value.isDouble())
                        {
                            double dColor = value.toDouble();
                            qDebug() << "Color" << i << ": " << dColor;
                        }
                    }
                }
            }

            if (object.contains("Info"))
            {
                QJsonValue value = object.value("Info");
                if (value.isObject())
                {
                    QJsonObject obj = value.toObject();
                    if (obj.contains("Class"))
                    {
                        QJsonValue value = obj.value("Class");
                        if (value.isString())
                        {
                            QString strClass = value.toString();
                            qDebug() << "Info:Class : " << strClass;
                        }
                    }

                    if (obj.contains("School"))
                    {
                        QJsonValue value = obj.value("School");
                        if (value.isString())
                        {
                            QString strSchool = value.toString();
                            qDebug() << "Info:School : " << strSchool;
                        }
                    }
                }
            }

            if (object.contains("Students"))
            {
                QJsonValue value = object.value("Students");
                if (value.isArray())
                {
                    QJsonArray array = value.toArray();
                    int nSize = array.size();
                    for (int i = 0; i < nSize; ++i)
                    {
                        QJsonValue childValue = array.at(i);
                        QJsonObject childobj = childValue.toObject();
                        if (childobj.contains("Id"))
                        {
                            QJsonValue value = childobj.value("Id");
                            if (value.isString())
                            {
                                QString strId = value.toString();
                                qDebug() << "Students:" << i << ": Id : " << strId;
                            }
                        }

                        if (childobj.contains("age"))
                        {
                            QJsonValue value = childobj.value("age");
                            if (value.isString())
                            {
                                QString strage = value.toString();
                                qDebug() << "Students:" << i << ": age : " << strage;
                            }
                        }

                    }
                }
            }
        }
    }
}

//修改数据
void ModifyMyJson()
{
    QFile jsonFile(QDir::currentPath() + "/myjson.json");
    if(jsonFile.exists())
    {
        jsonFile.open(QIODevice::ReadWrite|QIODevice::Text);
        QByteArray byteArray = jsonFile.readAll();
        QJsonParseError jsonError;
        QJsonDocument doucment = QJsonDocument::fromJson(byteArray, &jsonError);
        if (doucment.isObject())
        {
            // JSON 文档为对象
            QJsonObject object = doucment.object();  // 转化为对象
            if (object.contains("Address"))
            {
                object["Address"] = "北京海淀区";
            }

            doucment.setObject(object);
        }

        jsonFile.seek(0);
        jsonFile.write(doucment.toJson());
        jsonFile.flush();
        jsonFile.close();
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CreateMyJson();

      ParseMyJson();

      ModifyMyJson();
    mainWidget w;
//    ChessDemo w;
    w.show();

    return a.exec();
}
