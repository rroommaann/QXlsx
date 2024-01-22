// xlsxzipwriter.cpp

#include "xlsxzipwriter_p.h"


//#include <QtGui/private/qzipwriter_p.h>
#include "private/qzipwriter_p.h"

#include <QDebug>
#include <QtGlobal>

QT_BEGIN_NAMESPACE_XLSX

ZipWriter::ZipWriter(const QString &filePath)
{
    m_writer = new MyZipWriter(filePath, QIODevice::WriteOnly);
    m_writer->setCompressionPolicy(MyZipWriter::AutoCompress);
}

ZipWriter::ZipWriter(QIODevice *device)
{
    m_writer = new MyZipWriter(device);
    m_writer->setCompressionPolicy(MyZipWriter::AutoCompress);
}

ZipWriter::~ZipWriter()
{
    delete m_writer;
}

bool ZipWriter::error() const
{
    return m_writer->status() != MyZipWriter::NoError;
}

void ZipWriter::addFile(const QString &filePath, QIODevice *device)
{
    m_writer->addFile(filePath, device);
}

void ZipWriter::addFile(const QString &filePath, const QByteArray &data)
{
    m_writer->addFile(filePath, data);
}

void ZipWriter::close()
{
    m_writer->close();
}

QT_END_NAMESPACE_XLSX
