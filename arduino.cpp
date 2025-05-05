#include "arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QSqlQuery>
#include <QSqlError>


Arduino::Arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
    return serial;
}
int Arduino::connect_arduino()

{
    const quint16 arduino_uno_vendor_id = 0x2341;
    const quint16 arduino_uno_product_id = 0x0043;

    const quint16 ch340_vendor_id = 0x1A86;
    const quint16 ch340_product_id = 0x7523;
    // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            qDebug() << "Détection port :" << serial_port_info.portName()
                     << "- VID:" << QString::number(serial_port_info.vendorIdentifier(), 16)
                     << "- PID:" << QString::number(serial_port_info.productIdentifier(), 16);

            if ((serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_product_id) ||
                (serial_port_info.vendorIdentifier() == ch340_vendor_id && serial_port_info.productIdentifier() == ch340_product_id)) {

                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
                break;
            }
        }
    }

    qDebug() << "arduino_port_name is :" << arduino_port_name;
    if(arduino_is_available){ // configuration de la communication ( débit...)
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)){
            serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
            serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
            serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
            serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

int Arduino::close_arduino()

{

    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;


}

void Arduino::readFromArduino() {
    QByteArray receivedData = serial->readAll();  // Lire les données envoyées par Qt
    QString uid = QString(receivedData).trimmed();

    // Débogage : afficher l'UID reçu
    qDebug() << "UID reçu : " << uid;

    // Vérification de l'UID dans la base de données
    QString reponse = verifierUID(uid);  // Appel de la méthode de vérification
    qDebug() << "Réponse envoyée : " << reponse;

    // Envoi de la réponse à Arduino
    write_to_arduino(reponse.toUtf8() + "\n");
}

/*QString Arduino::verifierUID(QString uid) {
    // Comparaison de l'UID reçu avec celui dans la base de données
    if (uid == "76 7B D1 CF") {  // Exemple d'UID correct
        return "WELCOME sabrine";
    } else {
        return "wrong card";  // Retourne "wrong card" si l'UID est incorrect
    }
}*/
QString Arduino::verifierUID(QString uid) {

    // Vérification de l'UID dans la table "projet"
    QSqlQuery query;
    query.prepare("SELECT nom , prenom FROM employe WHERE rfid = :rfid");
    query.bindValue(":rfid", uid);

    if (query.exec() && query.next()) {
        QString nom_employe = query.value(0).toString();
        QString prenom_employe = query.value(1).toString();
        qDebug() << "Nom du employé trouvé : " << nom_employe;
        return "WELCOME:" + nom_employe +" "+ prenom_employe;
    } else {
        qDebug() << "Erreur lors de la vérification UID:" << query.lastError().text();
        return "DENIED";
    }
}




void Arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
