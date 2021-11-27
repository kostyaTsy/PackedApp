#include "packunpackwindow.h"
#include "ui_packunpackwindow.h"
#include "Modules/convertFiles.h"
#include "Modules/RLE.h"
#include "Modules/LZ77.h"
#include "Modules/huffman.h"
#include <QFileDialog>
#include <QMessageBox>
#include <string>


PackUnpackWindow::PackUnpackWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PackUnpackWindow)
{
    ui->setupUi(this);
}

PackUnpackWindow::~PackUnpackWindow()
{
    delete ui;
}

// finding file type from initial file path
std::string findingFileType(std::string filePath) {
    std::string fileType = filePath;
    auto pos = fileType.find_last_of('.');
    if (pos != std::string::npos) {
        fileType.erase(0, pos + 1);
        return fileType;
    }
    return "";
}

// cutting the file type of the initial file
std::string cuttingFileType(std::string filePath) {
    std::string tmpStr = filePath;
    auto pos = tmpStr.find_last_of('/');
    if (pos != std::string::npos) {
        std::string fileWithoudType = tmpStr;
        fileWithoudType.erase(pos+1, fileWithoudType.size());

        tmpStr.erase(0, pos + 1);
        pos = tmpStr.find_last_of('.');
        if (pos != std::string::npos) {
            tmpStr.erase(pos, tmpStr.size());
            return fileWithoudType+tmpStr;
        }
    }
    return filePath;
}

// Changing window depends on title name
void PackUnpackWindow::on_PackUnpackWindow_windowTitleChanged(const QString &title)
{
    if (title == "Pack file") {
        ui->btnAction->setText("Pack");
        ui->cbPackAlgo->setVisible(true);
    }
    else if (title == "Unpack file") {
        ui->btnAction->setText("Unpack");
        ui->cbPackAlgo->setVisible(false);
    }

}

// Action on button (pack file or unpack)
void PackUnpackWindow::on_btnAction_clicked()
{

    QMessageBox msgBox;
    std::string fileType = findingFileType(this->filePath);
    this->savePath = cuttingFileType(this->savePath);

    if (ui->lePath->text() == "") {
        msgBox.setText("No path chosen,\nPlease choose the path");
        msgBox.exec();
        return;
    }

    // Packing files
    if (ui->btnAction->text() == "Pack") {
        QString packAlorithm = ui->cbPackAlgo->currentText();
        // using RLE alorithm
        if (packAlorithm == "RLE") {
            int *arr = nullptr;
            long long sizeArr = 0;

            arr = ConvertFileToCode(this->filePath, sizeArr);

            RLE_pack(arr, sizeArr, this->savePath+".RLE", fileType);
            delete [] arr;

        }
        // using LZ77 algorithm
        else if (packAlorithm == "LZ77") {
            LZ77_pack(this->filePath, this->savePath+".LZ77", fileType);
        }
        // using Huffman algorithm
        else if (packAlorithm == "Huffman") {
            Huffman_pack(this->filePath, this->savePath+".Huff", fileType);
        }
        msgBox.setText("File packed!");

        if (msgBox.exec() == QMessageBox::Ok) {
            this->close();
        }
    }
    // Unpacking files
    else if (ui->btnAction->text() == "Unpack") {
        // unpacking RLE file
        if (fileType == "RLE") {
            long long arrSize = 0;
            std::string newFileType = "";
            int *arr = ConvertPackedFile(this->filePath, arrSize, newFileType);

            RLE_unpack(arr, arrSize, this->savePath+newFileType);
            delete [] arr;
        }
        // unpacking LZ77 file
        else if (fileType == "LZ77") {
            LZ77_unpack(this->filePath, this->savePath);
        }
        else if (fileType == "Huff") {
            Huffman_unpack(this->filePath, this->savePath);
        }
        else {
            msgBox.setText("Inccorect file");
            if (msgBox.exec() == QMessageBox::Ok) {
                this->close();
            }
            return;
        }

        msgBox.setText("File unpacked!");
        if (msgBox.exec() == QMessageBox::Ok) {
            this->close();
        }
    }
}

// Getting path to save pacled/unpacked file
void PackUnpackWindow::on_btnChoosePath_clicked()
{
    QString titleOfSaveDialog;
    if (ui->btnAction->text() == "Pack") {
        titleOfSaveDialog = "Save packed file as";
    }
    else if (ui->btnAction->text() == "Unpack") {
        titleOfSaveDialog = "Save unpacked file as";
    }

    QString savePath = QFileDialog::getSaveFileName(0, titleOfSaveDialog, QString::fromStdString(this->filePath));
    this->savePath = savePath.toStdString();
    ui->lePath->setText(savePath);
}

