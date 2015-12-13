#include "apkthumb.h"

#include <QImage>
#include <QString>
#include <QProcess>
#include <KZip>
#include <KZipFileEntry>

extern "C"
{
  Q_DECL_EXPORT ThumbCreator *new_creator()
  {
      return new ApkThumb;
  }
}

ApkThumb::ApkThumb(){}

ApkThumb::~ApkThumb(){}

bool ApkThumb::create(const QString & path, int width, int height, QImage & img)
{
    KZip zip(path);
    if ( !zip.open( QIODevice::ReadOnly ) ){
        return false;
    }
    QProcess process;
    QStringList sl;
    sl << "d" << "badging" << path;
    process.start("aapt", sl);
    process.waitForFinished();
    QString out;
    QStringList icons;
    while(!process.atEnd()){
        out = QString::fromLatin1(process.readLine());
        if(out.contains("application-icon"))
            icons << out.split(':')[1].trimmed().remove('\'');
    }
    foreach (const QString& icon, icons) {
        const KArchiveEntry* iconEntry = zip.directory()->entry( icon );
        const KZipFileEntry* iconFile = static_cast<const KZipFileEntry*>(iconEntry);
        if ( !iconFile ){
            return false;
        }
        QImage iconImg;
        iconImg.loadFromData( iconFile->data() );
        img = iconImg;
        return true;
    }
    if(img.isNull())
        return 0;
    return 0;
}
