#include "apkthumb.h"
#include <QImage>
#include <QString>

int main(int argc, char *argv[])
{
    ApkThumb *apk = new ApkThumb();
    QImage image;
    QString file = argv[1];
    bool a = apk->create(file, 128, 128, image);
    if(a)
        image.save("out.png");
    delete apk;
    return 0;
}
